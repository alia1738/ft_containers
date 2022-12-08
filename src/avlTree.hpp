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
		typedef	_node*										pointer;
		typedef pair< const key, val>						value_type;
		typedef typename std::allocator<_node>				_allocator;
		pointer		_root;
		_allocator	alloc;
		compare		comp;

	private:
		
		void	adjustNodeHight(pointer n) {
			n->height = 1 + maxHight(n->right, n->left);
		}

		int	maxHight(pointer right, pointer left){
			int r = (right)? right->height : 0;
			int l = (left)? left->height : 0;
			return ((r > l) ? r : l);
		}

		int	getBalanceFactor(pointer n){
			if (!n)
				return (0);
			int r = !(n->right)? 0: n->right->height;
			int l = !(n->left)? 0: n->left->height;
			return (l - r);
		}

		pointer	AllocConstruct(pointer parent, pointer child, const value_type& newNodeInfo, bool r) {
			child = alloc.allocate(1);
				
			alloc.construct(child, _node(parent, newNodeInfo));
			parent->introduceChildToParent(child, r);
			parent->height++;
			return (child);
		}

		void	linkParentNodesForRotation(pointer n, pointer x, pointer y){
			pointer n_new_parent = x;
			pointer x_new_parent = n->parent;
			pointer y_new_parent = n;
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

		void	rotateRight(pointer n) {
			pointer x = n->left;
			pointer y = x->right;

			linkParentNodesForRotation(n, x, y);
			x->right = n;
			n->left = y;
			adjustNodeHight(n);
			adjustNodeHight(x);
			if (n->_info == _root->_info)
				this->_root = x;
		}

		void	rotateLeft(pointer n) {
			pointer x = n->right;
			pointer y = x->left;

			linkParentNodesForRotation(n, x, y);
			x->left = n;
			n->right = y;
			adjustNodeHight(n);
			adjustNodeHight(x);
			if (n->_info == _root->_info)
				this->_root = x;
		}

		void	adjustTreeBalance(pointer n) {
			if (!n)
				return ;

			adjustNodeHight(n);
			int balance = getBalanceFactor(n);

			if (balance > 1) {
				if (getBalanceFactor(n->right) <= 0)  {
					return (rotateRight(n));
				}
				else {
					rotateLeft(n->left);
					return (rotateRight(n));}
			}
			else if (balance < -1) {
				if (getBalanceFactor(n->left) >= 0) {
					return (rotateLeft(n));}
				else {
					rotateRight(n->right);
					return (rotateLeft(n));}
			}

			adjustTreeBalance(n->parent);
			return ;
		}

		void	adjustTreeBalance_delete(pointer n) {
			if (!n)
				return ;

			adjustNodeHight(n);
			int balance = getBalanceFactor(n);

			if (balance > 1) {
				if (getBalanceFactor(n->left) >= 0)  {
					return (rotateRight(n));
				}
				else {
					rotateLeft(n->left);
					return (rotateRight(n));}
			}
			else if (balance < -1) {
				if (getBalanceFactor(n->right) <= 0) {
					return (rotateLeft(n));}
				else {
					rotateRight(n->right);
					return (rotateLeft(n));}
			}

			adjustTreeBalance_delete(n->parent);
			return ;
		}

		void	LinkParentNodeForDelete(pointer parent, pointer child, bool r) {
			if (parent) {
				parent->introduceChildToParent(child, r);
				if (!parent->right && !parent->left)
					parent->height--;
			}
		}

		void	updateRoot(pointer swappedNode, pointer potentialRoot) {
			if (swappedNode && swappedNode->_info == this->_root->_info) {
				this->_root = potentialRoot;}
		}

		void	destroyDeallocate(pointer n) {
			this->alloc.destroy(n);
			this->alloc.deallocate(n, 1);
		}

		void	changeNodeLinks(pointer parent, pointer child, bool r) {
			if (parent){
				if (r) {
					parent->right = child;}
				else if (!r) {
					parent->left = child;}
			}
			if (child){
				child->parent = parent;}
		}

		bool is_right(pointer parent, pointer child){
			if (parent)
				return ((this->comp(child->_info.first, parent->_info.first))? false:true);
			return (false);
		}

		void replaceNodes(pointer to_be_deleted, pointer place_tacker) {
			
			pointer	place_tacker_parent = place_tacker->parent;
			pointer	to_be_deleted_parent = to_be_deleted->parent;
			bool	direct_child = (place_tacker_parent->_info.first == to_be_deleted->_info.first)? true:false;
			bool	r = is_right(to_be_deleted_parent, to_be_deleted);

			changeNodeLinks(to_be_deleted_parent, place_tacker, r);
			// to_be delete_parent is connected with place_tacker
			// place tacker is connected with to be delete parent

			changeNodeLinks(place_tacker, to_be_deleted->left, false);
			// connect to_be_delete->left->parent with place_tacker
			// connect place_tacker->left with to be_delete->left->parent

			if (!direct_child){
				changeNodeLinks(place_tacker_parent, place_tacker->right, false);
				changeNodeLinks(place_tacker, to_be_deleted->right, true);
			}
			// if it not a direct child
				// connect place_tacker->right to place_tacker->parent->left
				// connect place_tacker->parent->left to place_tacker->right
				// connect to_be_delete->right->parent to place_tacker
				// connect place_tacker with to_be_deleted->right->parent;

			updateRoot(to_be_deleted, place_tacker);
			destroyDeallocate(to_be_deleted);
			if (direct_child)
				adjustTreeBalance_delete(place_tacker);
			else
				adjustTreeBalance_delete(place_tacker_parent);
		}

		_node*	getInOrderSuccessor(pointer to_be_deleted, bool first_time = true) {
			static pointer nextNode = to_be_deleted->right;

			nextNode = (first_time)? to_be_deleted->right: nextNode;
			
			if (!nextNode->left)
				return (nextNode);
			nextNode = nextNode->left;
			getInOrderSuccessor(to_be_deleted, false);

			return (nextNode);
		}

		void	findAndReplace(pointer to_be_deleted) {
			pointer place_tacker = getInOrderSuccessor(to_be_deleted);

			replaceNodes(to_be_deleted, place_tacker);
		}

		pointer	placeNewNode(const value_type& newNode, bool first_time = true) {
			static	pointer temp = this->_root;

			temp = (first_time)? this->_root: temp;

			if (comp(newNode.first, temp->_info.first)){
				if (nodeAdded(newNode, temp, temp->left, false)){
					temp = temp->left;
					return (temp);}
				else {
					temp = temp->left;
					placeNewNode(newNode, false);}
			}

			else if (!comp(newNode.first, temp->_info.first)) {
				if (nodeAdded(newNode, temp, temp->right, true)) {
					temp = temp->right;
					return (temp);}
				else {
					temp = temp->right;
					placeNewNode(newNode, false);}
			}
			return (temp);
		}

		void	deleteNodeOneChild(pointer to_be_deleted) {
			pointer child = (to_be_deleted->right)? to_be_deleted->right: to_be_deleted->left;
			pointer parent = (to_be_deleted->parent)? to_be_deleted->parent:NULL;
			bool r = (parent && this->comp(to_be_deleted->_info.first, parent->_info.first))? false:true;

			LinkParentNodeForDelete(parent, child, r);
			child->parent = parent;
			adjustNodeHight(child);
			updateRoot(to_be_deleted, child);
			destroyDeallocate(to_be_deleted);
			adjustTreeBalance_delete(child);
		}

	public:

		avlTree(){
			this->_root = NULL;
		}

		pointer	insert(const value_type &v){
			if (!this->_root){
				this->_root = alloc.allocate(1);
				_node temp(v);
				alloc.construct(_root, temp);
				return (this->_root);
			}
			return (placeNewNode(v));
		}

		pointer	insert(value_type position, const value_type& v){
			(void)position;
			return(insert(v));
		}

		pointer findNode(const key& nodeKey, bool first_time = false) const{
			static pointer temp = this->_root;

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

		bool	nodeAdded(const value_type& newNode, pointer temp, pointer temp_l_r, bool t){
			if (!temp_l_r) {
				AllocConstruct(temp, temp_l_r, newNode, t);
				adjustTreeBalance(temp);
				return (true);}
			return (false);
		}
		
		bool	deleteNode(const key nodeKey){
			pointer temp = findNode(nodeKey, true);

			if (!temp)
				return (false);
			pointer temp_parent = (!temp->parent)? NULL: temp->parent;
			if (!temp->right && !temp->left) {
				bool r = (temp_parent && nodeKey > temp_parent->_info.first)? true: false;
				LinkParentNodeForDelete(temp_parent, NULL, r);
				updateRoot(temp, temp_parent);
				destroyDeallocate(temp);
				adjustTreeBalance_delete(temp_parent);
				return (true);
			}
			else if (!temp->right || !temp->left){
				deleteNodeOneChild(temp);
				return (true);}

			else {
				findAndReplace(temp);
				return (true);}
			return (false);
		}

		void	clear_tree(){
			while (	this->_root)
				deleteNode(this->_root->_info.first);
		}


		/* *************************************** */
		/* ************ To be deleted ************ */
		pointer get_root(){
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

		~avlTree(){
			this->clear_tree();
		}

	};
}

#endif