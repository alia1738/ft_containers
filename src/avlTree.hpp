/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:48:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/11 09:42:13 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

#include "Node.hpp"
// #include "Compare.hpp"
#include <functional>

namespace ft {
	template < class key, class val, class compare = std::less<key>, class Alloc = std::allocator< pair<const key, val> > >
	class avlTree {

	public:
		typedef	Node<key, val>								_node;
		typedef pair<key, val>								value_type;
		typedef typename std::allocator<_node>				_allocator;
		_node *_root;

	private:
		_allocator	alloc;
		compare		comp;
		
		void	adjustNodeHight(_node *n) {
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
			return (l - r);
		}

		void	AllocConstruct(_node *parent, _node *child, const value_type& newNodeInfo, bool r) {
			child = alloc.allocate(1);
				
			alloc.construct(child, _node(parent, newNodeInfo));
			parent->introduceChildToParent(child, r);
			parent->height++;
		}

		void	linkParentNodesForRotation(_node *n, _node *x, _node *y){
			_node *n_new_parent = x;
			_node *x_new_parent = n->parent;
			_node *y_new_parent = n;
			bool r = false;
			
			if (x_new_parent && x_new_parent->right->_info == n->_info)
				r = true;
			x->parent = x_new_parent;
			if (x_new_parent && r)
				x_new_parent->right = x;
			else if (x_new_parent && !r)
				x_new_parent->left = x;
			n->parent = n_new_parent;
			if (y) {
				y->parent = y_new_parent;
			}
		}

		void	rotateRight(_node *n) {
			_node *x = n->left;
			_node *y = x->right;

			linkParentNodesForRotation(n, x, y);
			x->right = n;
			n->left = y;
			adjustNodeHight(n);
			adjustNodeHight(x);
			if (n->_info == _root->_info)
				this->_root = x;
		}

		void	rotateLeft(_node *n) {
			_node *x = n->right;
			_node *y = x->left;

			linkParentNodesForRotation(n, x, y);
			x->left = n;
			n->right = y;
			adjustNodeHight(n);
			adjustNodeHight(x);
			if (n->_info == _root->_info)
				this->_root = x;
		}

		void	adjustTreeBalance(_node *n, const key nodeKey) {
			if (!n)
				return ;
			adjustNodeHight(n);
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

		bool	nodeAdded(const value_type& newNode, _node *temp, _node *temp_l_r, bool t){
			if (!temp_l_r) {
				AllocConstruct(temp, temp_l_r, newNode, t);
				adjustTreeBalance(temp, newNode.first);
				return (true);}
			return (false);
		}

		void	placeNewNode(const value_type& newNode) {
			static	_node *temp = this->_root;

			if (comp(newNode.first, temp->_info.first)){
				if (nodeAdded(newNode, temp, temp->left, false)) 
					return ;
				else {
					temp = temp->left;
					placeNewNode(newNode);}
			}

			else if (!comp(newNode.first, temp->_info.first)) {
				// std::cout << "temp = " << temp->_info.first << std::endl;
				if (nodeAdded(newNode, temp, temp->right, true))
					return ;
				else {
					temp = temp->right;
					placeNewNode(newNode);}
			}
		}

		void	LinkParentNodeForDelete(_node *parent, _node *child, bool r) {
			if (parent) {
				parent->introduceChildToParent(child, r);
				parent->height--;
			}
		}

		void	updateRoot(const key nodeKey, _node *potentialRoot) {
			if (nodeKey == this->_root->_info.first)
				this->_root = potentialRoot;
		}

		void	destroyDeallocate(_node *n) {
			this->alloc.destroy(n);
			this->alloc.deallocate(n, 1);
		}

		_node*	getInOrderSuccessor(_node *toBeDeleted) {
			static _node *nextNode = toBeDeleted->right;
			
			if (!nextNode->left)
				return (nextNode);
			nextNode = nextNode->left;
			getInOrderSuccessor(toBeDeleted);

			return (nextNode);
		}

		void replaceNodes(_node *infoTaker, _node *toBeDeleted) {
			_node *toBeDeletedParent = toBeDeleted->parent;
			bool r = (toBeDeletedParent && (toBeDeleted->_info.first > toBeDeletedParent->_info.first))? true: false;

			LinkParentNodeForDelete(toBeDeletedParent, NULL, r);
			
			value_type temp = infoTaker->_info;
			infoTaker->_info = toBeDeleted->_info;
			toBeDeleted->_info = temp;
			
			updateRoot(infoTaker->_info.first, infoTaker);
			destroyDeallocate(toBeDeleted);
			// adjustTreeBalance(infoTaker, infoTaker->_info.first);
		}

		void	findAndReplace(_node *infoTaker) {
			_node *toBeDeleted = getInOrderSuccessor(infoTaker);

			replaceNodes(infoTaker, toBeDeleted);
			adjustTreeBalance(infoTaker, infoTaker->_info.first);
		}

		void	deleteNodeOneChild(_node *toBeDeleted) {
			bool r = (toBeDeleted->right)? true:false;
			_node *child = (r)? toBeDeleted->right: toBeDeleted->left;
			_node *parent = toBeDeleted->parent;
			
			LinkParentNodeForDelete(parent, child, r);
			child->parent = parent;
			adjustNodeHight(child);
			updateRoot(toBeDeleted->_info.first, child);
			destroyDeallocate(toBeDeleted);
			adjustTreeBalance(child, child->_info.first);
		}

	public:

		avlTree(){
			this->_root = NULL;
		}

		void	add_new_node(const value_type &v){
			if (!this->_root){
				this->_root = alloc.allocate(1);
				_node temp(v);				
				alloc.construct(_root, temp);
			}
			else {
				placeNewNode(v);
			}
		}

		_node* findNode(const key& nodeKey, bool first_time = false){
			static _node* temp = this->_root;

			temp = (first_time)? this->_root: temp;

			if (!temp)
				return (NULL);
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
		
		void	deleteNode(const key nodeKey){
			_node *temp = findNode(nodeKey, true);
			_node *temp_parent = temp->parent;

			if (!temp->right && !temp->left) {
				bool r = (temp_parent && nodeKey > temp_parent->_info.first)? true: false;
				LinkParentNodeForDelete(temp_parent, NULL, r);
				updateRoot(nodeKey, temp_parent);
				destroyDeallocate(temp);
				adjustTreeBalance(temp_parent, nodeKey);
			}

			else if (!temp->right || !temp->left){
				deleteNodeOneChild(temp);}

			else {
				findAndReplace(temp);}
		}


		/* *************************************** */
		/* ************ To be deleted ************ */
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