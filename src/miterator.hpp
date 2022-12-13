/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:07:48 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/13 13:14:01 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MITERATOR_HPP
# define MITERATOR_HPP

#include "map.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Allocate = std::allocator< pair<const Key, T> > > class map;
	
	/* ---------------------- -- - Iterator - -- --------------------- */
	template < class myPair, class Compare, class Node > class miterator {
	
	public:
		typedef Node*								node_pointer;
		typedef std::ptrdiff_t						difference_type;
		typedef myPair								value_type;
		typedef value_type*							pointer;
		typedef value_type&							reference;
		typedef Compare								key_compare;

	private:
		node_pointer		_it;
		node_pointer		_start;
		node_pointer		_end;
		key_compare			comp;

	public:
	
		miterator(){
			this->_it = NULL;
			this->_start = NULL;
			this->_end = NULL;
		}
		
		miterator(const node_pointer s, const node_pointer e){
			this->_it = NULL;
			this->_start = s;
			this->_end = e;
		}

		miterator(const miterator& it){
			this->_it = it._it;
			this->_start = it._start;
			this->_end = it._end;
		}

		miterator(const node_pointer n, const node_pointer s, const node_pointer e){
			this->_it = n;
			this->_start = s;
			this->_end = e;
		}

		miterator& operator=(const miterator& it){
			if (this != &it) {
				this->_it = it._it;
				this->_start = it._start;
				this->_end = it._end;
				this->comp = it.comp;
			}
			return (*this);
		}

		operator miterator<const myPair, Compare, Node>() const {
			return(miterator<const myPair, Compare, Node>(_it, _start, _end));
		}

		node_pointer base() const {
			return (this->_it);
		}
		
		pointer get_pair() const {
			pointer v = &this->_it->_info;
			return (v);
		}

		reference operator*() const{
			return (this->_it->_info);}

		pointer	operator->() const {
			if (!_it){
				return (NULL);
			}
			return (get_pair());
		}

		bool	current(){
			return ((this->_it)? true:false);
		}

		bool	operator==(const miterator<const myPair, Compare, Node>& it) const {
			return (this->base() == it.base());}

		bool	operator!=(const miterator<const myPair, Compare, Node>& it) const {
			return (this->base() != it.base());}

		bool	operator<(const miterator<const myPair, Compare, Node>& it) const {
			return (this->get_pair() < it.get_pair());}

		bool	operator<=(const miterator<const myPair, Compare, Node>& it) const {
			return (this->get_pair() <= it.get_pair());}

		bool	operator>(const miterator<const myPair, Compare, Node>& it) const {
			return (this->get_pair() > it.get_pair());}

		bool	operator>=(const miterator<const myPair, Compare, Node>& it) const {
			return (this->get_pair() >= it.get_pair());}

		miterator& operator++(){
			if (_it->right) {
				getSuccessor();}
			else {
				findChosenParentPlus();}
			return (*this);
		}

		miterator operator++(int){
			miterator temp = *this;
			++(*this);
			return (temp);
		}

		miterator& operator--(){
			if (!this->_it) {
				this->_it = this->_end;}
			else if (_it->left){
				getPredecessor();}
			else {
				findChosenParentMinus();}
			return (*this);
		}

		miterator operator--(int){

			miterator temp = *this;
			--(*this);
			return (temp);
		}

		bool	is_null() const {
			return (!(_it)? true:false);
		}

	private:
		void	findChosenParentPlus() {
			for (node_pointer temp = this->_it; temp->parent; temp = temp->parent) {
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
			for (node_pointer temp = this->_it; temp->parent; temp = temp->parent) {
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
			getPredecessor(false);
		}

		void	getSuccessor(bool first_time = true) {
			if (first_time)
				this->_it = this->_it->right;
			if (!this->_it->left)
				return ;
			this->_it = this->_it->left;
			getSuccessor(false);
		}
		
	};
}

#endif