/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:48:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/09 15:40:31 by aalsuwai         ###   ########.fr       */
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

		void	rotateRight(_node *n) {
			_node *x = n->left;
			_node *y = x->right;
			_node *n_new_parent = x;
			_node *x_new_parent = n->parent;
			_node *y_new_parent = n;
			bool r = false;
			
			if (x_new_parent && x_new_parent->right->_info == n->_info)
				r = true;

			x->right = n;
			n->left = y;

			n->height = 1 + maxHight(n->right, n->left);
			x->height = 1 + maxHight(x->right, x->left);

			x->parent = x_new_parent;
			if (x_new_parent && r)
				x_new_parent->right = x;
			else if (x_new_parent && !r)
				x_new_parent->left = x;

			n->parent = n_new_parent;
			if (y) {
				y->parent = y_new_parent;
			}

			if (n->_info == _root->_info)
				this->_root = x;
		}

		void	rotateLeft(_node *n) {
			_node *x = n->right;
			_node *y = x->left;
			_node *n_new_parent = x;
			_node *x_new_parent = n->parent;
			_node *y_new_parent = n;
			bool r = false;
			
			if (x_new_parent && x_new_parent->right->_info == n->_info)
				r = true;

			x->left = n;
			n->right = y;

			x->parent = x_new_parent;
			if (x_new_parent && r)
				x_new_parent->right = x;
			else if (x_new_parent && !r)
				x_new_parent->left = x;

			n->parent = n_new_parent;
			if (y)
				y->parent = y_new_parent;

			n->height = 1 + maxHight(n->right, n->left);
			x->height = 1 + maxHight(x->right, x->left);

			if (n->_info == _root->_info)
				this->_root = x;
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
			return (l - r);
		}

		void	AllocConstruct(_node *parent, _node *child, const value_type& newNodeInfo, bool r) {
			child = alloc.allocate(1);
				
			alloc.construct(child, _node(parent, newNodeInfo));
			parent->introduceChildToParent(child, r);
			parent->height++;
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

		_node* findNode(const key& nodeKey){
			static _node* temp = this->_root;

			if (temp->_info.first == nodeKey)
				return (temp);
			else if (comp(nodeKey, temp->_info.first)){
				temp = temp->left;
				findNode(nodeKey);
			}
			else if (!comp(nodeKey, temp->_info.first)){
				temp = temp->right;
				findNode(nodeKey);
			}
			return (temp);
		}

		void replaceNodes(_node *toBeDeleted, _node *placeTaker) {
			_node *parent = toBeDeleted->parent;
			_node *placeTakerParent = placeTaker->parent;

			if (placeTakerParent && (placeTaker->_info.first > placeTakerParent->_info.first))
				placeTakerParent->right = NULL;
			if (placeTakerParent && (placeTaker->_info.first < placeTakerParent->_info.first))
				placeTakerParent->left = NULL;
			parent->height--;

			value_type temp = toBeDeleted->_info;
			toBeDeleted->_info = placeTaker->_info;
			placeTaker->_info = temp;

			this->alloc.destroy(placeTaker);
			this->alloc.deallocate(placeTaker, 1);
	
			adjustTreeBalance(toBeDeleted, toBeDeleted->_info.first);
		}

		void	deleteNodeOneChild(_node *toBeDeleted) {
			bool r = (toBeDeleted->right)? true:false;
			_node *child = (r)? toBeDeleted->right: toBeDeleted->left;
			_node *parent = toBeDeleted->parent;
			
			if (parent) {
				parent->introduceChildToParent(child, r);
				parent->height--;
			}
			child->parent = parent;
			child->height = 1 + maxHight(child->right, child->left);

			this->alloc.destroy(toBeDeleted);
			this->alloc.deallocate(toBeDeleted, 1);

			adjustTreeBalance(child, child->_info.first);
		}

		_node*	inorderSuccessorFinder(_node *toBeDeleted) {
			static _node *nextNode = toBeDeleted->right;
			
			std::cout << "next node " << nextNode->_info.first << std::endl;
			if (!nextNode->left)
				return (nextNode);

			nextNode = nextNode->left;
			inorderSuccessorFinder(toBeDeleted);

			return (nextNode);
		}

		void	findAndReplace(_node *toBeDeleted) {
			_node *replacer = inorderSuccessorFinder(toBeDeleted);

			std::cout << "replacer " << replacer->_info.first << std::endl;
			replaceNodes(toBeDeleted, replacer);
			adjustTreeBalance(replacer, replacer->_info.first);
		}
		
		void	deleteNode(const key nodeKey){
			_node *temp = findNode(nodeKey);
			_node *temp_parent = temp->parent;

			if (!temp->right && !temp->left) {
				bool r = (nodeKey > temp_parent->_info.first)? true: false;
				
				if (temp_parent){
					temp_parent->introduceChildToParent(NULL, r);
					temp_parent->height--;
					adjustTreeBalance(temp_parent, nodeKey);}
				
				if (nodeKey == this->_root->_info.first) {
					this->_root = temp_parent;}

				this->alloc.destroy(temp);
				this->alloc.deallocate(temp, 1);
			}
			
			else if (!temp->right || !temp->left){
				deleteNodeOneChild(temp);}

			else {
				findAndReplace(temp);}
		}

		void	placeNewNode(const value_type& newNode) {
			static	_node *temp = this->_root;

			if (comp(newNode.first, temp->_info.first)){
				if (!temp->left) {
					AllocConstruct(temp, temp->left, newNode, false);
					adjustTreeBalance(temp, newNode.first);
					return ;
				}
				else {
					temp = temp->left;
					placeNewNode(newNode);
				}
			}

			else if (!comp(newNode.first, temp->_info.first)) {
				if (!temp->right) {
					AllocConstruct(temp, temp->right, newNode, true);
					adjustTreeBalance(temp, newNode.first);
					return ;
				}
				else {
					temp = temp->right;
					placeNewNode(newNode);
				}
			}
		}

		void	adjustTreeBalance(_node *n, const key nodeKey) {
			n->height = 1 + maxHight(n->right, n->left);
			int balance = getBalanceFactor(n);

			
			if (balance > 1) {
				if (!n->right || nodeKey < n->left->_info.first)  {
					return (rotateRight(n));
				}
				else {
					rotateLeft(n->left);
					return (rotateRight(n));}
			}
			else if (balance < -1) {
				if (!n->left || nodeKey > n->right->_info.first) {
					return (rotateLeft(n));}
				else {
					rotateRight(n->right);
					return (rotateLeft(n));}
			}

			if (n->parent)
				adjustTreeBalance(n->parent, nodeKey);

			else
				return ;
		}

		_node *get_root(){
			return (this->_root);
		}

		void printTree(_node* r, int location = 0) {
			if (r) {
				if (!location) {
					std::cout << "Root: " << r->_info.first << " .. ";
					std::cout << "height: " << r->height << " .. ";
					if (r->parent)
						std::cout << "Parent: " << r->parent->_info.first << std::endl << std::endl;
					else
						std::cout << "NO PARENT" << std::endl << std::endl;
				}
				
				else if (location == 1) {
					std::cout << "right: " << r->_info.first << " .. ";
					std::cout << "height: " << r->height << " .. ";
					if (r->parent)
						std::cout << "Parent: " << r->parent->_info.first << std::endl << std::endl;
					else
						std::cout << "NO PARENT" << std::endl << std::endl;
				}

				else if (location == -1) {
					std::cout << "left: " << r->_info.first << " .. ";
					std::cout << "height: " << r->height << " .. ";
					if (r->parent)
						std::cout << "Parent: " << r->parent->_info.first << std::endl << std::endl;
					else
						std::cout << "NO PARENT" << std::endl << std::endl;
				}
				
				printTree(r->right, 1);
				printTree(r->left, -1);
			}
		}

	};
}

#endif