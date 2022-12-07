/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:54:46 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/07 09:58:16 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VITERATOR_HPP
# define VITERATOR_HPP

#include <iostream>
// #include "vector.hpp"

namespace ft {

	template < typename T, class _alloc = std::allocator<T> > class vector;

	template <class it> class iterator_traits {
	public:
		typedef typename it::difference_type   difference_type;
		typedef typename it::value_type        value_type;
		typedef typename it::pointer           pointer;
		typedef typename it::reference         reference;
		// typedef typename it::iterator_category iterator_category;
	};

	/* ------------------ -- - Reverse Iterator - -- ------------------ */

	template < class It> class reverse_iterator {
	public:
		typedef It												iterator_type;
		typedef typename iterator_traits<It>::difference_type	difference_type;
		typedef typename iterator_traits<It>::reference			reference;
		typedef typename iterator_traits<It>::pointer			pointer;

	private:
		It _content;

	public:
		reverse_iterator(): _content(){}

		explicit reverse_iterator(const It con): _content(con){}

		template<class r_it> reverse_iterator(const ft::reverse_iterator<r_it>& rit): _content(rit.base()){
			// this->_content = rit.base();
		}

		reverse_iterator& operator=(const ft::reverse_iterator<It>& rev) {
			if (this != &rev)
				this->_content = rev.base();
			return (*this);
		}

		It base() const {
			return (this->_content);}

		reference operator*() const {
			It temp = this->_content;
			temp--;
			return (*temp);
		}

		pointer operator->() const{
			It temp = this->_content;
			temp--;
			return (temp.operator->());
		}

		reverse_iterator& operator++(){
			--this->_content;
			return (*this);
		}

		reverse_iterator operator++(int){
			reverse_iterator temp(*this);
			this->_content--;
			return (temp);
		}

		reverse_iterator& operator--(){
			++this->_content;
			return (*this);
		}

		reverse_iterator operator--(int){
			reverse_iterator temp(*this);
			this->_content++;
			return (temp);
		}

		reverse_iterator operator+(difference_type n) const{
			return (reverse_iterator(this->_content - n));}
		
		reverse_iterator& operator+=(difference_type n){
			this->_content -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const{
			return (reverse_iterator(this->_content + n));}

		reverse_iterator& operator-=(difference_type n){
			this->_content += n;
			return (*this);
		}

		operator reverse_iterator<const It>() const {
			return (reverse_iterator<const It>());}

		reference operator[](difference_type n) const{
			return (*(*this + n));}
	
	};

	template < class It > ft::reverse_iterator<It> operator+(typename ft::reverse_iterator<It>::difference_type n, const ft::reverse_iterator<It>& rit){
		return (ft::reverse_iterator<It>(rit.base() - n));}

	template < class It, class It2 > 
	typename ft::reverse_iterator<It>::difference_type operator-(const ft::reverse_iterator<It>& l, const ft::reverse_iterator<It2>& r){
		return ((r.base() - l.base()));
	}

	template < class It, class It2 >
	bool operator==(const ft::reverse_iterator<It>& l, const ft::reverse_iterator<It2>& r){
		return (r.base() == l.base());}

	template < class It, class It2 >
	bool operator!=(const ft::reverse_iterator<It>& l, const ft::reverse_iterator<It2>& r){
		return (r.base() != l.base());}

	template < class It, class It2 >
	bool operator<(const ft::reverse_iterator<It>& l, const ft::reverse_iterator<It2>& r){
		return (r.base() < l.base());}

	template < class It, class It2 >
	bool operator<=(const ft::reverse_iterator<It>& l, const ft::reverse_iterator<It2>& r){
		return (r.base() <= l.base());}

	template < class It, class It2 >
	bool operator>(const ft::reverse_iterator<It>& l, const ft::reverse_iterator<It2>& r){
		return (r.base() > l.base());}

	template < class It, class It2 >
	bool operator>=(const ft::reverse_iterator<It>& l, const ft::reverse_iterator<It2>& r){
		return (r.base() >= l.base());}

	/* ---------------------- -- - Iterator - -- --------------------- */
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