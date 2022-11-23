/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:40:16 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/23 11:18:53 by aalsuwai         ###   ########.fr       */
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
		typedef avlTree<Key, T, Compare, Allocate>				_base;
		// typedef avlTree<Key, T, Compare>::allocator_type	tree_alloc;
		typedef	Node<Key, T>									_node;
		typedef	Node<Key, T>*									_node_pointer;
	
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
		size_type		_size;

	public:
	
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(){
			this->_comp = comp;
			this->_alloc = alloc;
			_size = 0;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _size(0), _tree(){
			map_init(first, last, comp, alloc);
		}

		map(const map& m): _size(0), _tree(){
			map_init(m.begin(), m.end(), m._comp, m._alloc);
		}
		
		map& operator=(const map& m){
			if (this != &m) {
				// delete before
				map_init(m.begin(), m.end(), m._comp, m._alloc);
			}
			return (*this);
		}
		
		template <class InputIterator>
		void map_init(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) {
			this->_comp = comp;
			this->_alloc = alloc;
			size_type	i = 0;
			for (i = 0; first != last; first++, i++)
				this->insert(ft::make_pair(first->first, first->second));
			this->_size = i;
		}

		size_type size() const{
			return (this->_size);
		}

		size_type max_size() const {
			return (this->_tree->alloc.max_size());
		}

		bool empty() const{
			return ((this->_size)? false: true);
		}

		iterator	begin() const{
			return (iterator(getFurthestLeft(), getFurthestLeft(), getFurthestRight()));
		}

		iterator	end() const{
			return (iterator(getFurthestLeft(), getFurthestRight()));
		}

		_node_pointer	getFurthestLeft() const{
			_node_pointer n = this->_tree._root;
			
			while (n && n->left) 
				n = n->left;
			return (n);
		}

		_node_pointer	getFurthestRight() const{
			_node_pointer n = this->_tree._root;
			
			while (n && n->right)
				n = n->right;
			return (n);
		}

		iterator find (const key_type& k){
			return (iterator((this->_tree.findNode(k, true)), this->getFurthestLeft(), this->getFurthestRight()));
		}

		pair<iterator, bool> insert(const value_type& val){
			_node_pointer	n = this->_tree.findNode(val.first, true);
			if (n)
				return (ft::make_pair(iterator(n, this->getFurthestLeft(), this->getFurthestRight()), false));
			n = this->_tree.insert(val);
			this->_size++;
			return (ft::make_pair(iterator(n, this->getFurthestLeft(), this->getFurthestRight()), true));
		}

		iterator insert (iterator position, const value_type& val) {
			_node_pointer	n = this->_tree.findNode(val.first, true);
			if (n)
				return (iterator(n, this->getFurthestLeft(), this->getFurthestRight()));
			n = this->_tree.insert(*position, val);
			this->_size++;
			return (iterator(n, this->getFurthestLeft(), this->getFurthestRight()));
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last){
			for (; first != last; first++)
				insert(ft::make_pair(first->first, first->second));
		}

		void erase (iterator position) {
			if (this->_tree.deleteNode(position->first))
				this->_size--;
		}

		size_type erase (const key_type& k) {
			if (this->_tree.deleteNode(k) && this->_size--)
				return (1);
			return (0);
		}

		void erase (iterator first, iterator last){
			for (bool r = true; r && first != last; first++, this->_size--)
				r = this->_tree.deleteNode(first->first);
		}

		mapped_type& at (const key_type& k) {
			_node_pointer	temp = this->_tree.findNode(k, true);

			if (!temp)
				throw std::out_of_range("\nft::map::at: key not found");
			return (temp->_info.second);
		}

		mapped_type& operator[](const key_type& k) {
			ft::pair<iterator, bool> ret = insert(ft::make_pair(k, NULL));
			return (ret.first->second);
		}

	};
}

#endif