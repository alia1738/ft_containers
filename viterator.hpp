/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:54:46 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/08/03 07:41:36 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VITERATOR_HPP
# define VITERATOR_HPP

#include <iostream>

namespace ft {
	
	template <class it> class iterator_trailts {
	public:
		typedef typename it::difference_type   difference_type;
		typedef typename it::value_type        value_type;
		typedef typename it::pointer           pointer;
		typedef typename it::reference         reference;
		typedef typename it::iterator_category iterator_category;
	};

	template <typename T, class vec> class v_iterator { // <--- I am here 
	public:
		typedef T		iterator_type;
		typedef T&		reference;
		// typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
		// typedef typename iterator_traits<iterator_type>::value_type        value_type;
		// typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
		// typedef typename iterator_traits<iterator_type>::pointer           pointer;
		// typedef typename iterator_traits<iterator_type>::reference         reference;
	
	private:
		iterator_type _it;

	public:
		v_iterator(){}

		v_iterator(const v_iterator& it){
			this->_it = it._it;
		}

		v_iterator(const iterator_type& it){
			this->_it = it;
		}

		v_iterator& operator=(const v_iterator& it){
			if (this != &it)
				this->_it = it;
			return (*this);
		}

		bool	operator==(const v_iterator& it1){
			return (this->_it == it1->_it);
		}

		bool	operator!=(const v_iterator& it1){
			return (this->_it != it1->_it);
		}

		v_iterator& operator++(){
			++this->_it;
			return (*this);
		}

		v_iterator operator++(int){
			v_iterator temp = *this;
			this->_it++;
			return (temp);
		}

		v_iterator& operator--(){
			--this->_it;
			return (*this);
		}

		v_iterator operator--(int){
			v_iterator temp = *this;
			this->_it--;
			return (temp);
		}

		// iterator_type& operator[](unsigned int n){
		// 	return (this->_it[n]);
		// }

		iterator_type operator*() const{
			return (_it);
		}


		~v_iterator(){}


	};
}


#endif