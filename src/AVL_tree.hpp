/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:48:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/10/24 14:21:32 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

#include "Node.hpp"
// #include "Compare.hpp"
#include <functional>

namespace ft {
	template < class key, class val, class Compare = std::less<key>, class Alloc = std::allocator< pair<const key, val> > >
	class AVL_tree {

	public:
		typedef	Node<key, val>								_node;
		typedef pair<key, val>								value_type;
		typedef typename std::allocator<_node>	_allocator;

	private:
		_node *_root;
		_allocator	alloc;

	public:

		AVL_tree(){
			// this->_root = this->alloc.allocate(1);
			this->_root = NULL;
		}

		void	add_new_node(const val v){
			if (!this->_root){
				this->_root = alloc.allocate(1);
				alloc.construct(_root, _node(v));
			}
				//  = _node(v);
			else{
				placeNewNode(v);
			}
		}

		void	rotateLeft(_node *n) {
			_node *x = n->left;
			_node *y = x->right;

			x->right = n;
			n->left = y;

			x->height = 1 + maxHight(x->right, x->left);
			n->height = 1 + maxHight(n->right, n->left);
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
			return (n->right->height - n->left->height);
		}

		void	adjustTreeBalance(_node *n, const value_type& newNodeInfo) {
			n->height = 1 + maxHight(n->right, n->left);

			// balance factor
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

			adjustTreeBalance(n->parent);
		}

		void	AllocConstruct(_node *parent, _node *child, const value_type& newNodeInfo) {
			child = alloc.allocate(1);
			child->construct(child, _node(parent, newNodeInfo));
		}

		void	placeNewNode(const value_type& newNode) {
			static	_node *temp = this->root;

			if (compare(newNode->first, temp->_info->first)){
				if (!temp->right) {
					AllocConstruct(temp, temp->right, newNode);
					adjustTreeBalance(temp, newNode);
					return ;
				}
				else {
					temp = temp->right;
					placeNewNode(newNode);
				}
			}

			else if (!compare(newNode->first, temp->_info->first)) {
				if (!temp->left) {
					AllocConstruct(temp, temp->left, newNode);
					adjustTreeBalance(temp, newNode);
					return ;
				}
				else {
					temp = temp->left;
					placeNewNode(newNode);
				}
			}
		}

		_node *get_root(){
			return (this->_root);
		}

		void printTree(_node *r, std::string indent = "", bool last = "") {
			if (r) {
				std::cout << indent;
				if (last) {
				std::cout << "R----";
				indent += "   ";
				} else {
				std::cout << "L----";
				indent += "|  ";
				}
				std::cout << r->_info->first << std::endl;
				printTree(r->left, indent, false);
				printTree(r->right, indent, true);
			}
		}

		// void	deleteNode(){
		// 	;
		// }

	};
}

#endif