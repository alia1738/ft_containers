/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:40:16 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/13 15:04:26 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "avlTree.hpp"
#include "miterator.hpp"
#include "rev_iterator.hpp"
#include "extra.hpp"

namespace ft {
	
	
	template < class Key, class T, class Compare, class Allocate > 
	class map {

	private:
		typedef avlTree<Key, T, Compare, Allocate>			_base;
		typedef	Node<Key, T>								_node;
		typedef	Node<Key, T>*								_node_pointer;
	
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

		typedef miterator< value_type, Compare, _node >			iterator;
		typedef miterator< const value_type,  Compare, _node >	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

	private:
		
		_base			_tree;
		allocator_type	_alloc;
		key_compare		_comp;
		size_type		_size;

	public:

		class value_compare : public std::binary_function<value_type, value_type, bool>{
			friend class map;
		
		protected:
			key_compare comp;
			value_compare (key_compare c) : comp(c) {}
		
		public:
			typedef bool		result_type;

			bool operator() (const value_type& val, const value_type& val2) const{
				return comp(val.first, val2.first);
			}
		};
	
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(){
			this->_comp = comp;
			this->_alloc = alloc;
			_size = 0;
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(), _size(0){
			this->_tree.clear_tree();
			this->_comp = comp;
			this->_alloc = alloc;
			size_type	i = 0;
			for (i = 0; first != last; first++, i++) 
				this->insert(ft::pair<key_type, mapped_type>(first->first, first->second));
			this->_alloc = this->_tree.alloc;
		}

		map(const map& m): _tree(), _size(0){
			this->_tree.clear_tree();
			this->_comp = m._comp;
			this->_alloc = m._alloc;
			size_type	i = 0;
			for (const_iterator f = m.begin(); f != m.end(); f++, i++) 
				this->insert(ft::pair<const key_type, const mapped_type>(f->first, f->second));
			this->_alloc = this->_tree.alloc;
		}
		
		map& operator=(const map& m){
			if (this != &m) {
				this->_tree.clear_tree();
				this->_comp = m._comp;
				this->_alloc = m._alloc;
				size_type	i = 0;
				for (const_iterator f = m.begin(); f != m.end(); f++, i++) 
					this->insert(ft::pair<key_type, mapped_type>(f->first, f->second));
				this->_alloc = this->_tree.alloc;
				this->_size = m._size;
			}
			return (*this);
		}

		size_type size() const{
			return (this->_size);
		}

		size_type max_size() const {
			return (this->_tree.alloc.max_size());
		}

		bool empty() const{
			return ((this->_size)? false: true);
		}

		iterator	begin(){
			return (iterator(getFurthestLeft(), getFurthestLeft(), getFurthestRight()));
		}

		iterator	end(){
			return (iterator(getFurthestLeft(), getFurthestRight()));
		}

		const_iterator begin() const{
			return (const_iterator(getFurthestLeft(), getFurthestLeft(), getFurthestRight()));
		}

		const_iterator end() const{
			return (const_iterator(getFurthestLeft(), getFurthestRight()));
		}

		reverse_iterator rbegin(){
			return (reverse_iterator(this->end()));
		}

		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator(this->end()));
		}

		reverse_iterator rend(){
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rend() const{
			return (const_reverse_iterator(this->begin()));
		}

		iterator find (const key_type& k){
			return (iterator((this->_tree.findNode(k, true)), this->getFurthestLeft(), this->getFurthestRight()));
		}

		const_iterator find (const key_type& k) const{
			return (const_iterator((this->_tree.findNode(k, true)), this->getFurthestLeft(), this->getFurthestRight()));
		}

		pair<iterator, bool> insert(const value_type& val){
			_node_pointer	n = this->_tree.findNode(val.first, true);
			if (n)
				return (ft::pair<iterator, bool>(iterator(n, this->getFurthestLeft(), this->getFurthestRight()), false));
			n = this->_tree.insert(val);
			this->_size++;
			iterator it(n, this->getFurthestLeft(), this->getFurthestRight());
			return (ft::pair<iterator, bool>(it, true));
		}

		iterator insert (iterator position, const value_type& val) {
			_node_pointer	n = this->_tree.findNode(val.first, true);
			if (n)
				return (iterator(n, this->getFurthestLeft(), this->getFurthestRight()));
			if (position.is_null())
				position--;
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
			if (position.current() && this->_tree.deleteNode(position->first))
				this->_size--;
		}

		size_type erase (const key_type& k) {
			if (this->_tree.deleteNode(k) && this->_size--)
				return (1);
			return (0);
		}

		void erase (iterator first, iterator last){
			if (!first.current())
				return ;
			for (iterator temp; first.current() && first != last; ) {
				temp = first++;
				if (!first.current() && last == this->end()) {
					first--;
					if (this->_tree.deleteNode(first->first))
						this->_size--;
					return ;
				}
				if (this->_tree.deleteNode(temp->first))
					this->_size--;
			}
		}

		void swap (map& m) {
			this->_tree.swap(m._tree);
			
			allocator_type a = this->_alloc;
			this->_alloc = m._alloc;
			m._alloc = a;
			
			key_compare c = this->_comp;
			this->_comp = m._comp;
			m._comp = c;
			
			size_type s = this->_size;
			this->_size = m._size;
			m._size = s;
		}

		void clear(){
			this->_tree.clear_tree();
			this->_size = 0;
		}

		value_compare value_comp() const{
			return (value_compare(this->_comp));
		}

		key_compare key_comp() const {
			return (this->_comp);
		}
		
		allocator_type get_allocator() const {
			return (this->_alloc);
		}

		size_type count (const key_type& k) const {
			return ((this->_tree.findNode(k, true))? 1: 0);
		}

		iterator lower_bound (const key_type& k) {
			for (iterator it = this->begin(); it != this->end(); it++) {
				if (!_comp(it->first, k))
					return (it);
			}
			return (this->end());
		}

		const_iterator lower_bound (const key_type& k) const{
			for (const_iterator it = this->begin(); it != this->end(); it++) {
				if (!_comp(it->first, k))
					return (it);
			}
			return (this->end());
		}

		iterator upper_bound (const key_type& k) {
			for (iterator it = this->begin(); it != this->end(); it++) {
				if (it->first != k && !_comp(it->first, k))
					return (it);
			}
			return (this->end());
		}

		const_iterator upper_bound (const key_type& k) const{
			for (const_iterator it = this->begin(); it != this->end(); it++) {
				if (it->first != k && !_comp(it->first, k))
					return (it);
			}
			return (this->end());
		}

		pair<iterator,iterator>	equal_range (const key_type& k){
			return (pair<iterator,iterator>(this->lower_bound(k), this->upper_bound(k)));
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return (pair<const_iterator,const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		}

		mapped_type& at (const key_type& k) {
			_node_pointer	temp = this->_tree.findNode(k, true);

			if (!temp)
				throw std::out_of_range("\nft::map::at: key not found");
			return (temp->_info.second);
		}

		mapped_type& operator[](const key_type& k) {
			this->insert(value_type(k, mapped_type()));
			_node_pointer temp = this->_tree.findNode(k, true);
			return (temp->_info.second);
		}

	private:
		_node_pointer	getFurthestLeft() const{
			_node_pointer n = this->_tree._root;

			while (n && n->left) {
				n = n->left;}
			return (n);
		}

		_node_pointer	getFurthestRight() const{
			_node_pointer n = this->_tree._root;
			
			while (n && n->right) {
				n = n->right;}
			return (n);
		}

	};

	template < class Key, class T, class Compare, class Allocate >
	void swap(ft::map<Key, T, Compare, Allocate>& l, ft::map<Key, T, Compare, Allocate>& r){
		l.swap(r);
	}

	template < class Key, class T, class Compare, class Allocate >
	bool operator==(const ft::map<Key, T, Compare, Allocate>& l, const ft::map<Key, T, Compare, Allocate>& r) {
		return (l.size() == r.size() && ft::equal(l.begin(), l.end(), r.begin()));
	}

	template < class Key, class T, class Compare, class Allocate >
	bool operator!=(const ft::map<Key, T, Compare, Allocate>& l, const ft::map<Key, T, Compare, Allocate>& r) {
		return (!(l == r));
	}

	template < class Key, class T, class Compare, class Allocate >
	bool operator<(const ft::map<Key, T, Compare, Allocate>& l, const ft::map<Key, T, Compare, Allocate>& r) {
		return (ft::lexicographical_compare(l.begin(), l.end(), r.begin(), r.end()));
	}

	template < class Key, class T, class Compare, class Allocate >
	bool operator<=(const ft::map<Key, T, Compare, Allocate>& l, const ft::map<Key, T, Compare, Allocate>& r) {
		return (!(r < l));
	}

	template < class Key, class T, class Compare, class Allocate >
	bool operator>(const ft::map<Key, T, Compare, Allocate>& l, const ft::map<Key, T, Compare, Allocate>& r) {
		return (r < l);
	}

	template < class Key, class T, class Compare, class Allocate >
	bool operator>=(const ft::map<Key, T, Compare, Allocate>& l, const ft::map<Key, T, Compare, Allocate>& r) {
		return (!(l < r));
	}
}

#endif