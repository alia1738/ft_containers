/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:40:16 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/17 11:23:32 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "avlTree.hpp"
#include "miterator.hpp"

namespace ft {
	template < class Key, class T, class Compare, class Allocate > 
	class map {

	private:
		typedef avlTree<Key, T, Compare>					_base;
		// typedef avlTree<Key, T, Compare>::allocator_type	tree_alloc;
		typedef	Node<Key, T>										_node;
		typedef	Node<Key, T>*										_node_pointer;
	
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair <const key_type, mapped_type>			value_type;
		typedef Compare										key_compare;
		typedef Allocate									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type			size_type;
		typedef miterator< Key, T, _node,  Compare >		iterator;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator

	private:
		// typedef avlTree<Key, T, Compare, Allocate>			_base;
		// typedef	Node<Key, T>								_node;
		// typedef	Node<Key, T>*								_node_pointer;
		// typedef	
		// typedef avlTree <>
		
		_base			_tree;
		allocator_type	_alloc;
		key_compare		_comp;
		size_type		size;

	public:
	
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
			this->_comp = comp;
			this->_alloc = alloc;
			size = 0;
		}

		// map(const map& m){
		// 	if (this != m) {
		// 		this->_comp = m->_comp;
		// 		this->_alloc = m->_alloc;
		// 		for (size_type i = 0; i < size; i++){
		// 			// insert
		// 		}
		// 	}
		// }

		iterator	begin() {
			if (!this->_tree._root)
				return (NULL);
			return (iterator(getFurthestLeft()));
		}

		iterator	end() {
			if (!this->_tree._root)
				return (NULL);
			return (iterator(getFurthestRight()));
		}

		_node_pointer	getFurthestLeft(){
			_node_pointer n = this->_tree._root;
			
			while (n && n->left)
				n = n->left;
			return (n);
		}

		_node_pointer	getFurthestRight(){
			_node_pointer n = this->_tree._root;
			
			while (n && n->right)
				n = n->right;
			return (n);
		}

		pair</*iterator*/_node*, bool> insert(const value_type& val){
			_node_pointer	temp = this->_tree.findNode(val.first, true);
			if (temp){
				return (make_pair(temp, false));
			}
			this->_tree.add_new_node(val);
			temp = this->_tree.findNode(val.first);
			this->size++;
			// std::cout << "temp found " << temp->_info.first << std::endl;
			// std::cout << "I AM HERE!" << std::endl;
			return (make_pair(temp, true));
		}

		mapped_type& at (const key_type& k) {
			_node_pointer	temp = this->_tree.findNode(k, true);

			if (!temp)
				throw std::out_of_range("\nft::map: out of range");
			return (temp->_info.second);
		}

		mapped_type& operator[](const key_type& k){
			return (this->at(k));
		}

	};
}

#endif