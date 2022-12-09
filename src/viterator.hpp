/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:54:46 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/09 16:52:19 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VITERATOR_HPP
# define VITERATOR_HPP

#include <iostream>
#include "vector.hpp"

namespace ft {

	template < typename T, class Alloc = std::allocator<T> > class vector;

	/* ---------------------- -- - Iterator - -- --------------------- */
	template < typename T> class v_iterator {
	public:
		typedef typename ft::vector<T>::pointer			pointer;
		typedef typename ft::vector<T>::value_type		value_type;
		typedef typename ft::vector<T>::reference		reference;
		typedef typename ft::vector<T>::difference_type	difference_type;

	private:
		pointer _content;

	public:
		v_iterator(){}

		v_iterator(const v_iterator& it){
			this->_content = it._content;}

		v_iterator(pointer con){
			this->_content = con;}

		v_iterator& operator=(const ft::v_iterator<T>& it){
			if (this != &it)
				this->_content = it._content;
			return (*this);
		}
		
		pointer base() const {
			return (this->_content);
		}

		bool	operator==(const v_iterator<const T>& it1) const {
			return (this->base() == it1.base());}

		bool	operator!=(const v_iterator<const T>& it1) const {
			return (this->base() != it1.base());}

		bool	operator>(const v_iterator<const T>& it1) const {
			return (this->base() > it1.base());}

		bool	operator<(const v_iterator<const T>& it1) const {
			return (this->base() < it1.base());}

		bool	operator>=(const v_iterator<const T>& it1) const {
			return (this->base() >= it1.base());}

		bool	operator<=(const v_iterator<const T>& it1) const {
			return (this->base() <= it1.base());}

		operator v_iterator<const T>() const {
			return (v_iterator<const T>(_content));}

		v_iterator& operator++(){
			++this->_content;
			return (*this);
		}

		v_iterator operator++(int){
			v_iterator temp = *this;
			// this->_content++;
			++(*this);
			return (temp);
		}

		v_iterator& operator--(){
			--this->_content;
			return (*this);
		}

		v_iterator operator--(int){
			v_iterator temp = *this;
			this->_content--;
			return (temp);
		}

		value_type& operator*() const{
			return (*this->_content);}

		pointer operator->() {
			return (this->_content);
		}

		value_type& operator[](int n) const{
			return (this->_content[n]);}

		v_iterator& operator+=(int n){
			this->_content += n;
			return (*this);
		}

		v_iterator& operator-=(int n){
			this->_content -= n;
			return (*this);
		}

		v_iterator operator+(difference_type n) const{
			v_iterator temp = *this;
			temp += n;
			return (temp);
		}

		v_iterator operator-(difference_type n) const{
			v_iterator temp = *this;
			temp -= n;
			return (temp);
		}

		template <class T1 > difference_type operator-(const ft::v_iterator<T1>& it) const{
			return (this->base() - it.base());}

		~v_iterator(){}

	};

	template < class itr > ft::v_iterator<itr> operator+(typename ft::v_iterator<itr>::difference_type n, ft::v_iterator<itr> &vec){
		ft::v_iterator<itr> temp = vec;
		temp += n;
		return (temp);
	}
}



#endif