/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:48:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/10/05 10:55:27 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

#include "Node.hpp"
#include "Compare.hpp"
#include <functional>

namespace ft {
	template < class key, class val, class Compare = std::less<key>, class Alloc = std::allocator< pair<const key, val> > >
	class AVL_tree {

	public:
		typedef typename std::allocator<Node>	_allocator;
		typedef typename pair<key, val>			value_type;

	private:
		Node _root;
		_allocator	alloc;

	public:

		AVL_tree(): _root(NULL){}

		void	add_new_node(const Node::value_type& val){
			if (!this->_root)
				this->root = Node(val);
			else{
				placeNewNode(val);
			}
		}

		void	rotateLeft(Node *n) {
			Node *x = n->left;
			Node *y = x->right;

			x->right = n;
			n->left = y;

			x->height = 1 + maxHight(x->right, x->left);
			n->height = 1 + maxHight(n->right, n->left);
		}

		void	rotateRight(Node *n) {
			Node *x = n->right;
			Node *y = x->left;

			x->left = n;
			n->right = y;

			x->height = 1 + maxHight(x->right, x->left);
			n->height = 1 + maxHight(n->right, n->left);
		}

		int	maxHight(Node *right, Node *left){
			int r = (right)? right->height : 0;
			int l = (left)? left->height : 0;
			return ((r > l) ? r : l);
		}

		int	getBalanceFactor(Node *n){
			if (!n)
				return (0);
			return (n->right->height - n->left->height);
		}

		void	adjustTreeBalance(Node *n, const value_type& newNodeInfo) {
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

		void	AllocConstruct(Node *parent, Node *child, const value_type& newNodeInfo) {
			child = alloc.allocate(1);
			child.construct(child, Node(parent, newNodeInfo));
		}

		void	placeNewNode(const value_type& newNode) {
			static	Node *temp = this->root;

			if (compare(newNode.first, temp->_info.first)){
				if (!temp->right) {
					AllocConstruct(temp, temp->right, newNode);
					adjustTreeBalance(temp, newNodeInfo);
					return ;
				}
				else {
					temp = temp->right;
					placeNewNode(newNode);
				}
			}

			else if (!compare(newNode.first, temp._info.first)) {
				if (!temp->left) {
					AllocConstruct(temp, temp->left, newNode);
					adjustTreeBalance(temp, newNodeInfo);
					return ;
				}
				else {
					temp = temp->left;
					placeNewNode(newNode);
				}
			}
		}

	};
}

#endif