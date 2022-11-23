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

	private:
		compare		comp;
		
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

		void	adjustTreeBalance(pointer n, const key nodeKey) {
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

		void	LinkParentNodeForDelete(pointer parent, pointer child, bool r) {
			if (parent) {
				parent->introduceChildToParent(child, r);
				if (!parent->right && !parent->left)
					parent->height--;
			}
		}

		void	updateRoot(const key nodeKey, pointer potentialRoot) {
			if (nodeKey == this->_root->_info.first)
				this->_root = potentialRoot;
		}

		void	destroyDeallocate(pointer n) {
			this->alloc.destroy(n);
			this->alloc.deallocate(n, 1);
		}

		void	swap_l_r_pointers(pointer place_tacker, pointer to_be_deleted, pointer to_be_deleted_right, pointer to_be_deleted_left) {
			if (to_be_deleted_right->_info.first == place_tacker->_info.first)
				place_tacker->right = NULL;
			else
				place_tacker->right = to_be_deleted_right;

			if (to_be_deleted_left->_info.first == place_tacker->_info.first)
				place_tacker->left = NULL;
			else
				place_tacker->left = to_be_deleted_left;

			if (to_be_deleted_right && to_be_deleted_right->_info.first != place_tacker->_info.first)
				to_be_deleted_right->parent = place_tacker;
			if (to_be_deleted_left && to_be_deleted_left->_info.first != place_tacker->_info.first)
				to_be_deleted_left->parent = place_tacker;
			isolate_to_be_deleted(to_be_deleted);
		}

		void	isolate_to_be_deleted(pointer to_be_deleted) {
			to_be_deleted->parent = NULL;
			to_be_deleted->right = NULL;
			to_be_deleted->left = NULL;
		}

		void replaceNodes(pointer to_be_deleted, pointer place_tacker) {
			pointer place_tacker_parent = place_tacker->parent;
			pointer to_be_deleted_parent = to_be_deleted->parent;
			pointer to_be_deleted_right = to_be_deleted->right;
			pointer to_be_deleted_left = to_be_deleted->left;

			place_tacker->height = to_be_deleted->height;
			LinkParentNodeForDelete(to_be_deleted_parent, place_tacker, \
			((to_be_deleted_parent && (!comp(to_be_deleted->_info.first, to_be_deleted_parent->_info.first)))? true: false));
			LinkParentNodeForDelete(place_tacker_parent, NULL, \
			((place_tacker_parent && (!comp(place_tacker->_info.first, place_tacker_parent->_info.first)))? true: false));

			place_tacker->parent = to_be_deleted->parent;
			swap_l_r_pointers(place_tacker, to_be_deleted, to_be_deleted_right, to_be_deleted_left);

			updateRoot(place_tacker->_info.first, place_tacker);
			destroyDeallocate(to_be_deleted);
			adjustTreeBalance(place_tacker, place_tacker->_info.first);
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
			adjustTreeBalance(to_be_deleted, to_be_deleted->_info.first);
		}

		pointer	placeNewNode(const pointer starting_point, const value_type& newNode, bool first_time = true) {
			static	pointer temp = starting_point;

			temp = (first_time)? starting_point: temp;

			if (comp(newNode.first, temp->_info.first)){
				if (nodeAdded(newNode, temp, temp->left, false)) 
					return (temp->left);
				else {
					temp = temp->left;
					placeNewNode(this->_root, newNode, false);}
			}

			else if (!comp(newNode.first, temp->_info.first)) {
				if (nodeAdded(newNode, temp, temp->right, true))
					return (temp->right);
				else {
					temp = temp->right;
					placeNewNode(this->_root, newNode, false);}
			}
			return (temp);
		}

		void	deleteNodeOneChild(pointer to_be_deleted) {
			bool r = (to_be_deleted->right)? true:false;
			pointer child = (r)? to_be_deleted->right: to_be_deleted->left;
			pointer parent = to_be_deleted->parent;
			
			LinkParentNodeForDelete(parent, child, r);
			child->parent = parent;
			adjustNodeHight(child);
			updateRoot(to_be_deleted->_info.first, child);
			destroyDeallocate(to_be_deleted);
			adjustTreeBalance(child, child->_info.first);
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
			return (placeNewNode(this->_root, v));
		}

		pointer	insert(value_type *position, const value_type& v){
			(void)position;
			return(insert(v));
		}

		pointer findNode(const key& nodeKey, bool first_time = false){
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
				adjustTreeBalance(temp, newNode.first);
				return (true);}
			return (false);
		}
		
		bool	deleteNode(const key nodeKey){
			pointer temp = findNode(nodeKey, true);
			pointer temp_parent = (!temp)? NULL: temp->parent;

			if (!temp)
				return (false);
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
			return (true);
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

	};
}

#endif