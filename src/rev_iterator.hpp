/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:10:33 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/14 09:04:24 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ITERATOR_HPP
# define REV_ITERATOR_HPP

namespace ft {

	template <class it> class iterator_traits {
	public:
		typedef typename it::difference_type   difference_type;
		typedef typename it::value_type        value_type;
		typedef typename it::pointer           pointer;
		typedef typename it::reference         reference;
		typedef typename it::iterator_category iterator_category;
	};

	struct	input_iterator_tag{};
	struct	output_iterator_tag{};
	struct	forward_iterator_tag: public input_iterator_tag{};
	struct	bidirectional_iterator_tag: public forward_iterator_tag{};
	struct	random_access_iterator_tag: public bidirectional_iterator_tag{};

	/* ------------------ -- - Reverse Iterator - -- ------------------ */

	template < class It> class reverse_iterator {
	public:
		typedef It												iterator_type;
		typedef typename iterator_traits<It>::difference_type	difference_type;
		typedef typename iterator_traits<It>::reference			reference;
		typedef typename iterator_traits<It>::pointer			pointer;
		typedef typename iterator_traits<It>::iterator_category	iterator_category;

	private:
		It _content;

	public:
		reverse_iterator(): _content(){}

		explicit reverse_iterator(const It con): _content(con){}

		template<class r_it> 
		reverse_iterator(const ft::reverse_iterator<r_it>& rit): _content(rit.base()){
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
			return (reverse_iterator<const It>(this->_content));}

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
}

#endif