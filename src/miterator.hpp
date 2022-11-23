/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:07:48 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/22 13:45:14 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MITERATOR_HPP
# define MITERATOR_HPP

#include "map.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Allocate = std::allocator< pair<const Key, T> > > class map;
	
	/* ---------------------- -- - Iterator - -- --------------------- */
	template < class Key, class T, class N, class Compare = std::less<Key> > class miterator {
	
	public:
		typedef N											_node;
		typedef N*											pointer;
		// typedef N&											reference;
		typedef typename map< Key, T >::difference_type		difference_type;
		typedef typename map< Key, T >::value_type			value_type;
		// typedef typename value_type*						value_type_pointer;
		typedef Compare										key_compare;
		typedef Key											key_type;
		typedef T											mapped_type;



	private:
		pointer		_it;
		pointer		_start;
		pointer		_end;
		key_compare	comp;

	public:
		miterator(pointer s, pointer e){
			this->_it = NULL;
			this->_start = s;
			this->_end = e;
		}

		miterator(const miterator& it){
			this->_it = it._it;
			this->_start = it._start;
			this->_end = it._end;
		}

		miterator(pointer n, pointer s, pointer e){
			this->_it = n;
			this->_start = s;
			this->_end = e;
		}

		miterator& operator=(const miterator& it){
			if (this != &it)
				this->_it = it._it;
			return (*this);
		}
		
		value_type* get_pair() const {
			value_type *v = &this->_it->_info;
			return (v);
		}

		value_type* operator*() const{
			return (get_pair());}

		value_type*	operator->() const {
			return (get_pair());}

		bool	operator==(const miterator& it) const {
			return (this->_it == it._it);}

		bool	operator!=(const miterator& it) const {
			return (this->_it != it._it);}

		bool	operator>(const miterator& it) const {
			return (this->_it > it._it);}

		bool	operator<(const miterator& it) const {
			return (this->_it < it._it);}

		bool	operator>=(const miterator& it) const {
			return (this->_it >= it._it);}

		bool	operator<=(const miterator& it) const {
			return (this->_it <= it._it);}

		miterator& operator++(){
			if (_it->right)
				getSuccessor();
			else
				findChosenParentPlus();
			return (*this);
		}

		miterator operator++(int){
			miterator temp = *this;
			++(*this);
			return (temp);
		}

		/* account for cases when you go to null after the smallest iterator */
		/* you shouldn't go back yo the last one you just sig fault */
		miterator& operator--(){
			// std::cout << "this->_it->_info.second" << this->_it->_info.second << std::endl;
			// static bool first_time = true;
			if (!this->_it)
				this->_it = this->_end;
			// first_time = false;
			else if (_it->left)
				getPredecessor();
			else
				findChosenParentMinus();
			return (*this);
		}

		miterator operator--(int){
			// std::cout << "this->_it->_info.second" << this->_it->_info.second << std::endl;

			miterator temp = *this;
			--(*this);
			return (temp);
		}

		void	findChosenParentPlus() {
			for (pointer temp = this->_it; temp->parent; temp = temp->parent) {
				if (!comp(temp->parent->_info.first, temp->_info.first)) {
					this->_it = temp->parent;
					return ;
				}
				else if (comp(temp->parent->_info.first, temp->_info.first))
					;
			}
			this->_it = NULL;
		}

		void	findChosenParentMinus() {
			for (pointer temp = this->_it; temp->parent; temp = temp->parent) {
				if (comp(temp->parent->_info.first, temp->_info.first)) {
					this->_it = temp->parent;
					return ;
				}
				else if (!comp(temp->parent->_info.first, temp->_info.first))
					;
			}
			this->_it = NULL;
		}

		void getPredecessor(bool first_time = true) {
			if (first_time)
				this->_it = this->_it->left;
			if (!this->_it->right)
				return ;
			this->_it = this->_it->right;
			if (!this->_it)
				return ;
			getSuccessor(false);
		}

		void	getSuccessor(bool first_time = true) {
			if (first_time)
				this->_it = this->_it->right;
			if (!this->_it->left)
				return ;
			this->_it = this->_it->left;
			if (!this->_it)
				return ;
			getSuccessor(false);
		}
		
	};
}

#endif