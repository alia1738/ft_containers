/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:54:46 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/08/03 15:37:55 by aalsuwai         ###   ########.fr       */
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
		typedef T									type_name;
		typedef typename vector<T>::pointer			pointer;
		typedef typename vector<T>::value_type		value_type;
		typedef typename vector<T>::reference		reference;
		// typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
		// typedef typename iterator_traits<iterator_type>::value_type        value_type;
		// typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
		// typedef typename iterator_traits<iterator_type>::pointer           pointer;
		// typedef typename iterator_traits<iterator_type>::reference         reference;
	
	private:
		pointer _content;

	public:
		v_iterator(){}

		v_iterator(const v_iterator& it){
			this->_content = it._content;
		}

		v_iterator(pointer con){
			std::cout << con[0] << std::endl;
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

		// bool	operator>(const v_iterator& it1){ // compare based on size or content or adfress
		// 	return (this->_content > it1._content);
		// }

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

		// iterator_type& operator[](unsigned int n){
		// 	return (this->_content[n]);
		// }

		value_type operator*() const{
			return (this->_content[0]);
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

		// v_iterator operator+(v_iterator& it){
		// 	v_iterator temp = it;
		// 	temp += this;
		// 	return (temp);
		// }

		// v_iterator operator+(int n, const v_iterator) const{
		// 	// (void)it;
		// 	v_iterator temp = *this;
		// 	temp += n;
		// 	return (temp);
		// }

		v_iterator operator-(int n){
			v_iterator temp = *this;
			temp -= n;
			return (temp);
		}

		~v_iterator(){}

	};
}


#endif