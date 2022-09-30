/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:48:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/09/30 13:40:14 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

#include "Node.hpp"
#include "Compare.hpp"

namespace ft {
	template < class key, class val, class Compare = isNodeSmaller<Key> >
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

		void	adjustTreeHight(Node *temp) {
			int	addToRight = temp->right? 1: 0;
			int	addToLeft = temp->left? 1: 0;
			temp->hight = (temp->right->hight + addToRight) - (temp->left->higth + addToLeft);

			if (temp->hight > 1) {
				// rotate to right
				adjustTreeHight(temp);
			}
			else if (temp->hight < -1) {
				//rotate to left
				adjustTreeHight(temp);
			}
			else
				adjustTreeHight(temp->parent);
		}

		void	AllocConstruct(Node *parent, Node *child, const value_type& newNodeInfo) {
			child = alloc.allocate(1);
			child.construct(child, Node(parent, newNodeInfo));
		}

		void	placeNewNode(const value_type& newNode) {
			static	Node *temp = this->root;

			if (compare(newNode.first, temp._info.first)){
				if (!temp->right) {
					AllocConstruct(temp, temp->right, newNode);
					adjustTreeHight(temp);
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
					adjustTreeHight(temp);
					return ;
				}
				else {
					temp = temp->left;
					placeNewNode(newNode);
				}
			}
		}

	}
}

#endif