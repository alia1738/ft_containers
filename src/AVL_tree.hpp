/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:48:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/03 15:06:12 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

#include "Node.hpp"
// #include "Compare.hpp"
#include <functional>

namespace ft {
	template < class key, class val, class compare = std::less<key>, class Alloc = std::allocator< pair<const key, val> > >
	class AVL_tree {

	public:
		typedef	Node<key, val>								_node;
		typedef pair<key, val>								value_type;
		typedef typename std::allocator<_node>				_allocator;

	private:
		_node *_root;
		_allocator	alloc;
		compare		comp;

		void	rotateLeft(_node *n) {
			_node *x = n->left;
			_node *y = x->right;

			x->right = n;
			n->left = y;

			x->height = 1 + maxHight(x->right, x->left);
			n->height = 1 + maxHight(n->right, n->left);
			if (n->_info == _root->_info)
				this->_root = x;
		}

		void	rotateRight(_node *n) {
			_node *x = n->right;
			_node *y = x->left;

			x->left = n;
			n->right = y;

			x->height = 1 + maxHight(x->right, x->left);
			n->height = 1 + maxHight(n->right, n->left);
		}

		int	maxHight(_node *right, _node *left){
			int r = (right)? right->height : 0;
			int l = (left)? left->height : 0;
			return ((r > l) ? r : l);
		}

		int	getBalanceFactor(_node *n){
			if (!n)
				return (0);
			int r = !(n->right)? 0: n->right->height;
			int l = !(n->left)? 0: n->left->height;
			return (r - l);
		}

		void	AllocConstruct(_node *parent, _node *child, const value_type& newNodeInfo, bool r) {
			child = alloc.allocate(1);
			alloc.construct(child, _node(parent, newNodeInfo));
			parent->introduceChildToParent(child, r);
		}

	public:

		AVL_tree(){
			this->_root = NULL;
		}

		void	add_new_node(const value_type v){
			if (!this->_root){
				this->_root = alloc.allocate(1);
				_node temp(v);				
				alloc.construct(_root, temp);
			}
			else {
				placeNewNode(v);
			}
		}

		_node& findNode(const key& nodeKey){
			static _node* temp = this->_root;
	
			if (comp(nodeKey, temp->_info.first)){
				temp = temp->right;
				findNode(nodeKey);
			}
			else if (!comp(nodeKey, temp->_info.first)){
				temp = temp->left;
				findNode(nodeKey);
			}
			else if (nodeKey == temp->_info.first)
				return (temp);
		}

		void replaceNodes(_node *toBeDeleted, _node *placeTaker) {
			_node *parent = toBeDeleted->parent;
			
			placeTaker->right = toBeDeleted->right;
			placeTaker->left = toBeDeleted->left;
			toBeDeleted->right = NULL;
			toBeDeleted->left = NULL;

			parent->introduceChildToParent(placeTaker, (placeTaker->_info.first < parent->_info.first)? true: false);
			placeTaker->parent = parent;

			this->alloc.destroy(toBeDeleted);
			this->alloc.deallocate(toBeDeleted, 1);
		}

		void	deleteNodeOneChild(_node *toBeDeleted) {
			_node *child = (toBeDeleted->right)? toBeDeleted->right: toBeDeleted->left;
			_node *parent = toBeDeleted->parent;
			
			parent->introduceChildToParent(child, (child->_info.first < parent->_info.first)? true: false);
			child->parent = parent;

			this->alloc.destroy(toBeDeleted);
			this->alloc.deallocate(toBeDeleted, 1);
		}

		_node&	inorderSuccessorFinder(_node *toBeDeleted) {
			static _node *nextNode = toBeDeleted->left;
			
			if (!nextNode->right)
				return (nextNode);
			
			nextNode->right;
			inorderSuccessorFinder(toBeDeleted);
		}

		void	findAndReplace(_node *toBeDeleted) {
			_node *replacer = inorderSuccessorFinder(toBeDeleted);

			replaceNodes(toBeDeleted, replacer);			
		}
		
		void	deleteNode(const key nodeKey){
			_node *temp = findNode(nodeKey);

			if (!temp->right && !temp->left) {
				this->alloc.destroy(temp);
				this->alloc.deallocate(temp, 1);
			}
			
			else if (!temp->right || !temp->left)
				deleteNodeOneChild(temp);

			else
				findAndReplace(temp);
		}

		void	placeNewNode(const value_type& newNode) {
			static	_node *temp = this->_root;

			if (comp(newNode.first, temp->_info.first)){
				if (!temp->right) {
					AllocConstruct(temp, temp->right, newNode, true);
					adjustTreeBalance(temp, newNode);
					return ;
				}
				else {
					temp = temp->right;
					placeNewNode(newNode);
				}
			}

			else if (!comp(newNode.first, temp->_info.first)) {
				if (!temp->left) {
					AllocConstruct(temp, temp->left, newNode, false);
					adjustTreeBalance(temp, newNode);
					return ;
				}
				else {
					temp = temp->left;
					placeNewNode(newNode);
				}
			}
		}

		void	adjustTreeBalance(_node *n, const value_type& newNodeInfo) {
			n->height = 1 + maxHight(n->right, n->left);

			int balance = getBalanceFactor(n);
			
			if (balance > 1) {
				if (newNodeInfo.first < n->right->_info.first) 
					return (rotateRight(n));
				else {
					rotateLeft(n->right);
					return (rotateRight(n));}
			}
			else if (balance < -1) {
				if (newNodeInfo.first > n->left->_info.first) 
					return (rotateLeft(n));
				else {
					rotateRight(n->left);
					return (rotateLeft(n));}
			}
			if (n->parent)
				adjustTreeBalance(n->parent, newNodeInfo);
			else
				return ;
		}


		_node *get_root(){
			return (this->_root);
		}

		void printTree(_node* r, int location = 0) {
			if (r) {
				if (!location)
					std::cout << "Root: " << r->_info.first << std::endl;
				
				else if (location == 1)
					std::cout << "right: " << r->_info.first << std::endl;

				else if (location == -1)
					std::cout << "left: " << r->_info.first << std::endl;
				
				printTree(r->right, 1);
				printTree(r->left, -1);
				
			}
		}

	};
}

#endif