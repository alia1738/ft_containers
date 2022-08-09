/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:54:46 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/08/04 14:21:14 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VITERATOR_HPP
# define VITERATOR_HPP

#include <iostream>
// #include "vector.hpp"

namespace ft {
	
	template < typename T, class _alloc = std::allocator<T> > class vector;

	template <class it> class iterator_trailts {
	public:
		typedef typename it::difference_type   difference_type;
		typedef typename it::value_type        value_type;
		typedef typename it::pointer           pointer;
		typedef typename it::reference         reference;
		typedef typename it::iterator_category iterator_category;
	};

	template < typename T> class v_iterator {
	public:
		typedef typename vector<T>::pointer			pointer;
		typedef typename vector<T>::value_type		value_type;
		typedef typename vector<T>::reference		reference;
		typedef typename vector<T>::difference_type	difference_type;
	
	private:
		pointer _content;

	public:
		v_iterator(){}

		v_iterator(const v_iterator& it){
			this->_content = it._content;
		}

		v_iterator(pointer con){
			this->_content = con;
		}

		v_iterator& operator=(const v_iterator& it){
			if (this != &it)
				this->_content = it._content;
			return (*this);
		}

		bool	operator==(const v_iterator& it1){
			return (this->_content == it1._content);
		}

		bool	operator!=(const v_iterator& it1){
			return (this->_content != it1._content);
		}

		bool	operator>(const v_iterator& it1){
			return (this->_content > it1._content);
		}

		bool	operator<(const v_iterator& it1){
			return (this->_content < it1._content);
		}

		bool	operator>=(const v_iterator& it1){
			return (this->_content >= it1._content);
		}

		bool	operator<=(const v_iterator& it1){
			return (this->_content <= it1._content);
		}

		v_iterator& operator++(){
			++this->_content;
			return (*this);
		}

		v_iterator operator++(int){
			v_iterator temp = *this;
			this->_content++;
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

		value_type& operator*(){
			return (this->_content[0]);
		}

		value_type& operator[](int n){
			return (this->_content[n]);
		}

		v_iterator& operator+=(int n){
			this->_content += n;
			return (*this);
		}

		v_iterator& operator-=(int n){
			this->_content -= n;
			return (*this);
		}

		v_iterator operator+(int n){
			v_iterator temp = *this;
			temp += n;
			return (temp);
		}

		v_iterator operator-(int n){
			v_iterator temp = *this;
			temp -= n;
			return (temp);
		}

		difference_type operator-(const v_iterator& it){
			return (this->_content - it._content);
		}

		~v_iterator(){}

	};
	
}
template < class itr > ft::v_iterator<itr> operator+(typename ft::v_iterator<itr>::difference_type n, ft::v_iterator<itr> &vec){
	ft::v_iterator<itr> temp = vec;
	temp += n;
	return (temp);
}


#endif