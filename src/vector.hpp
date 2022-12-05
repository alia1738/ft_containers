/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:35:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/05 15:03:59 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector> // remove
#include <memory>
#include <iostream>
#include "viterator.hpp"

/* ----------------------- > >> Colors << < ----------------------- */

# define RED			"\033[0;31m"
# define BLUE			"\033[0;34m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define PURPLE			"\033[0;35m"
# define LIGHT_BLUE		"\033[0;36m"
# define RESET			"\x1B[0m"

# define RED1			"\033[1;31m"
# define BLUE1			"\033[1;34m"
# define GREEN1			"\033[1;32m"
# define YELLOW1		"\033[1;33m"
# define PURPLE1		"\033[1;35m"
# define LIGHT_BLUE1	"\033[1;36m"

# define RED2			"\033[2;31m"
# define BLUE2			"\033[2;34m"
# define GREEN2			"\033[2;32m"
# define YELLOW2		"\033[2;33m"
# define PURPLE2		"\033[2;35m"
# define LIGHT_BLUE2	"\033[2;36m"

# define RED3			"\033[3;31m"
# define BLUE3			"\033[3;34m"
# define GREEN3			"\033[3;32m"
# define YELLOW3		"\033[3;33m"
# define PURPLE3		"\033[3;35m"
# define LIGHT_BLUE3	"\033[3;36m"

namespace ft
{
	
	template < class InputIterator1, class InputIterator2 > 
	bool equal (InputIterator1 f1, InputIterator1 l1, 
									InputIterator2 f2){
		for (; f1 != l1; f1++, f2++){
			if (!(*f1 == *f2))
				return (false);
		}
		return (true);
	}

	template < class InputIterator1, class InputIterator2, class BinaryPredicate > 
	bool equal (InputIterator1 f1, InputIterator1 l1, 
									InputIterator2 f2, BinaryPredicate pred){
		for (; f1 != l1; f1++, f2++){
			if (!pred(*f1, *f2))
				return (false);
		}
		return (true);
	}

	template < class InputIterator1, class InputIterator2 > 
	bool lexicographical_compare (InputIterator1 f1, InputIterator1 l1, 
									InputIterator2 f2, InputIterator2 l2){
		for (; f1 != l1; f1++, f2++){
			if ((f2 == l2) || (*f1 > *f2))
				return (false);
			else if (*f1 < *f2)
				return (true);
		}
		return (f2 != l2);
	}

	template < class InputIterator1, class InputIterator2, class Compare > 
	bool lexicographical_compare (InputIterator1 f1, InputIterator1 l1, 
									InputIterator2 f2, InputIterator2 l2, Compare comp){
		for (; (f1 != l1) && (f2 != l2); f1++, f2++){
			if (!comp(*f1, *f2))
				return (false);
			else if (comp(*f1, *f2))
				return (true);
		}
		return (false);
	}

	template<typename T, T val> struct is_integral_base {
		static const T	value = val;
	};

	typedef is_integral_base<bool, true> true_type;
	typedef is_integral_base<bool, false> false_type;

	template<typename T> struct is_integral: false_type{};
	template<> struct is_integral<bool>: true_type{};
	template<> struct is_integral<int>: true_type{};
	template<> struct is_integral<short>: true_type{};
	template<> struct is_integral<long>: true_type{};
	template<> struct is_integral<long long>: true_type{};
	template<> struct is_integral<unsigned int>: true_type{};
	template<> struct is_integral<unsigned long>: true_type{};
	template<> struct is_integral<unsigned long long>: true_type{};
	template<> struct is_integral<char>: true_type{};
	template<> struct is_integral<signed char>: true_type{};
	template<> struct is_integral<unsigned char>: true_type{};
	template<> struct is_integral<wchar_t>: true_type{};

	template <bool, typename T = void> struct enable_if {};
	template <typename T> struct enable_if<false, T> {
		typedef T type;
	};

	template < typename T, class Alloc > 
	class vector
	{

	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef  v_iterator<value_type>						iterator;
		typedef v_iterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type			size_type;

	private:
		allocator_type	alloc;
		pointer			_start;
		pointer			_end;
		size_type		cap;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()): _start(0), _end(0), cap(0){
			this->alloc = alloc;
		}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _start(0), _end(0), cap(0){
			if (n){
				this->alloc = alloc;
				this->_start = this->alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					this->alloc.construct(this->_start + i, val);
				this->_end = this->_start + n;
				this->cap = this->size();
			}
		}

		template < class InputIterator > vector(InputIterator first, InputIterator end, const allocator_type& alloc = allocator_type(), typename enable_if<is_integral<InputIterator>::value, InputIterator>::type=0){
			this->alloc = alloc;
			int count = 0;
			for (; (first + count) != end; count++)
				;
			this->_start = this->alloc.allocate(count);
			for (int i = 0; i < count; i++) {
				this->alloc.construct((this->_start + i), first[i]);
			}
			this->_end = this->_start + count;
			this->cap = this->size();
		}

		vector(const vector& v): _start(0), _end(0), cap(0){
			this->alloc = v.alloc;
			this->cap = v.size();
			this->_start = this->alloc.allocate(v.size());

			size_type	i = 0;
			for (i = 0; i < v.size(); i++)
				this->alloc.construct((this->_start + i), *(v._start + i));
			this->_end = this->_start + i;
		}

		vector& operator=(const vector& v){
			if (this != &v){
				this->alloc = v.alloc;
				if (this->cap < v.cap)
					this->cap = v.cap;
				this->_start = this->alloc.allocate(v.size());

				size_type	i = 0;
				for (i = 0; i < v.size(); i++)
					this->alloc.construct((this->_start + i), *(v._start + i));
				this->_end = this->_start + i;
			}
			return(*this);
		}

		reference operator[](size_type n){
			return(*(this->_start + n));
		}

		const_reference operator[] (size_type n) const{
			return(*(this->_start + n));
		}

		iterator begin(){
			iterator	it(this->_start);
			return (it);
		}

		const_iterator begin() const{
			const_iterator	cit(static_cast<const_pointer>(this->_start));
			return (cit);
		}

		reverse_iterator rbegin(){
			reverse_iterator	it(this->_end);
			return (it);
		}

		const_reverse_iterator rbegin() const{
			const_reverse_iterator	cit(static_cast<const_pointer>(this->_end));
			return (cit);
		}

		iterator end(){
			iterator	it(this->_end);
			return (it);
		}

		const_iterator end() const{
			const_iterator	cit(this->_end);
			return (cit);
		}

		reverse_iterator rend(){
			reverse_iterator	it(this->_start);
			return (it);
		}

		const_reverse_iterator rend() const{
			const_reverse_iterator	cit(static_cast<const_pointer>(this->_start));
			return (cit);
		}

		reference at (size_type n){
			if (n >= this->size())
				throw std::out_of_range("\nft::vector: out of range");
			return(*(this->_start + n));
		}

		const_reference at (size_type n) const{
			if (n >= this->size())
				throw std::out_of_range("\nft::vector: out of range");
			return(*(this->_start + n));
		}

		template < class InputIterator > void assign(InputIterator first, InputIterator last, typename enable_if<is_integral<InputIterator>::value, InputIterator>::type=0){
			size_type	new_size = static_cast<size_type>(last - first);

			if (new_size >= this->cap){
				pointer	temp = alloc.allocate(new_size);
				
				size_type i = 0, max = this->size();
				for (; i < new_size; i++){
					this->alloc.construct((temp + i), *first++);
					
					if (i < max)
						this->alloc.destroy(this->_start + i);
				}

				this->alloc.deallocate(this->_start, max);
				this->_start = temp;
				this->_end = this->_start + i;
				this->cap = new_size;
			}
			else {
				for (size_type i = 0; i < new_size; i++){
					alloc.destroy(this->_start + i);
					alloc.construct(this->_start + i, *first++);
				}
				this->_end = this->_start + new_size;
			}
		}
		
		void	assign (size_type n, const value_type& val){
			if (n >= this->cap){
				pointer	temp = alloc.allocate(n);
				
				size_type i = 0, max = this->size();
				for (; i < n; i++){
					this->alloc.construct((temp + i), val);
					if (n < max)
						this->alloc.destroy(this->_start + i);
				}

				this->alloc.deallocate(this->_start, i);
				this->_start = temp;
				this->_end = this->_start + i;
				this->cap = n;
			}
			else {
				for (size_type i; i < n; i++){
					alloc.destroy(this->_start + i);
					alloc.construct(this->_start + i, val);
				}
			}
		}

		reference back(){
			return (*(this->_end - 1));
		}

		const_reference back() const{
			return (*(this->_end - 1));
		}
		
		iterator	erase(iterator position){
			difference_type location = position - this->begin();

			for (size_type i = location, next_i = location + 1; next_i < this->size(); next_i++, i++) {
				value_type	v = this->_start[i];
				alloc.destroy(this->_start + i);
				alloc.construct((this->_start + i), *(this->_start + next_i));
				alloc.destroy(this->_start + next_i);
				alloc.construct((this->_start + next_i), v);
			}

			--this->_end;
			alloc.destroy(this->_end + 1);
			return (this->begin() + location);
		}

		iterator	erase(iterator first, iterator last) {
			size_type		off_set = &(*last) - &(*first);
			difference_type location = first - this->begin();

			for (size_type i = location, next_i = location + off_set; next_i < this->size(); next_i++, i++) {
				value_type	v = this->_start[i];
				alloc.destroy(this->_start + i);
				alloc.construct((this->_start + i), *(this->_start + next_i));
				alloc.destroy(this->_start + next_i);
				alloc.construct((this->_start + next_i), v);
			}

			for (size_type i = 0; i < off_set; i++) {
				--this->_end;
				alloc.destroy(this->_end + 1);
			}

			return (this->begin() + location);
		}

		void clear(){
			size_type i = 0, max = this->size();

			for (; i < max; i++)
				this->alloc.destroy(this->_start + i);
			this->_end = this->_start;
		}

		bool empty() const{
			return (this->_start == this->_end);
		}

		reference front(){
			return (*(this->_start));
		}

		const_reference front() const{
			return (*(this->_start));
		}

		allocator_type getallocator_type() const{
			return (this->alloc);
		}

		iterator	insert(iterator position, const value_type& val) {
			size_type	new_size = this->size() + 1, start_i = 0, temp_i = 0;
			if (new_size > this->cap)
				this->cap *= 2;
			pointer	temp = alloc.allocate(new_size);
			for (bool added = false; temp_i < new_size; temp_i++){
				if (!added && &(*position) == &this->_start[start_i]) {
					added = true;
					this->alloc.construct((temp + temp_i), val);
				}
				else {
					this->alloc.construct((temp + temp_i), *(this->_start + start_i));
					this->alloc.destroy(this->_start + start_i++);
				}
			}
			this->alloc.deallocate(this->_start, start_i);
			this->_start = temp;
			this->_end = temp + temp_i;
			return (this->begin());
		}
	
		void	insert(iterator position, size_type n, const value_type& val) {
			size_type	new_size = this->size() + n, start_i = 0, temp_i = 0;
			while (new_size > this->cap)
				this->cap *= 2;
			pointer	temp = alloc.allocate(new_size);
			for (bool added = false; temp_i < new_size;){
				if (!added && &(*position) == &this->_start[start_i]) {
					added = true;
					for (size_type i = 0; i < n; i++)
						this->alloc.construct((temp + temp_i++), val);
				}
				else {
					this->alloc.construct((temp + temp_i++), *(this->_start + start_i));
					this->alloc.destroy(this->_start + start_i++);
				}
			}
			this->alloc.deallocate(this->_start, start_i);
			this->_start = temp;
			this->_end = temp + temp_i;
		}

		template <class InputIterator> void	insert(iterator position, InputIterator first, InputIterator last, typename enable_if<is_integral<InputIterator>::value, InputIterator>::type=0) {
			size_type	to_add = static_cast<size_type>(last - first);
			size_type	new_size = this->size() + to_add, start_i = 0, temp_i = 0;
			while (new_size > this->cap)
				this->cap *= 2;
			pointer	temp = alloc.allocate(new_size);
			for (bool added = false; temp_i < new_size;){
				if (!added && &(*position) == &this->_start[start_i]) {
					added = true;
					for (; first != last; first++)
						this->alloc.construct((temp + temp_i++), *first);
				}
				else {
					this->alloc.construct((temp + temp_i++), *(this->_start + start_i));
					this->alloc.destroy(this->_start + start_i++);
				}
			}
			this->alloc.deallocate(this->_start, start_i);
			this->_start = temp;
			this->_end = temp + temp_i;
		}

		size_type max_size() const{
			return(this->alloc.max_size());
		}

		void pop_back(){
			this->_end -= 1;
			this->alloc.destroy(this->_end + 1);
		}

		void	push_back(const value_type& val){
			if (this->cap == this->size())
			{
				size_type i = 0;

				this->cap = (!this->cap) ? 1 : (this->cap * 2);

				pointer temp = this->alloc.allocate(this->cap);

				for (i = 0; i < this->size(); i++){
					this->alloc.construct((temp + i), *(this->_start + i));
					this->alloc.destroy(this->_start + i);
				}
				this->alloc.construct((temp + i), val);

				this->alloc.deallocate(this->_start, i);
				this->_start = temp;
				this->_end = (!i) ? (this->_start + 1) : (this->_start + ++i);
			}

			else if (this->cap > this->size())
			{
				this->_start[this->size()] = val;
				this->_end++;
			}
		}

		void reserve (size_type n){
			if (n > this->cap){
				pointer	temp = this->alloc.allocate(n);
				
				size_type i = 0, max = this->size();
				for (; i < max; i++){
					this->alloc.construct(temp + i, *(this->_start + i));
					this->alloc.destroy(this->_start + i);
				}
				this->alloc.deallocate(this->_start, max);
				this->_start = temp;
				this->_end = temp + max;
				this->cap = n;
			}
		}
		
		void resize (size_type n, value_type val = value_type()){
			if (n < this->size()){
				this->_end -= (this->size() - n);
				for (size_type i = this->size(); i > n; i--)
					this->alloc.destroy(this->_start + i);
			}
			else if (n > this->capacity()){
				size_type max = this->size();
				pointer temp = this->alloc.allocate(n);

				for (size_type i = 0; i < n; i++){
					if (i < max){
						this->alloc.construct((temp + i), *(this->_start + i));
						this->alloc.destroy(this->_start + i);
					}
					else
						this->alloc.construct((temp + i), val);
				}
				this->alloc.deallocate(this->_start, max);
				this->_start = temp;
				this->_end = temp + n;
				this->cap = n;
			}
			else {
				for (size_type i = this->size(); i < n; i++)
					this->alloc.construct(this->_start + i, val);
				this->_end += (n - this->size());
			}
		}

		size_type		size() const{
			return(static_cast<size_type>(this->_end - this->_start));
		}

		size_type capacity() const{
			return(this->cap);
		}

		void swap (vector& v){			
			allocator_type	temp_alloc = v.alloc;
			pointer 	temp_start = v._start;
			pointer		temp_end = v._end;
			size_type	temp_cap = v.cap;

			v.alloc = this->alloc;
			v._start = this->_start;
			v._end = this->_end;
			v.cap = this->cap;

			this->alloc = temp_alloc;
			this->_start = temp_start;
			this->_end = temp_end;
			this->cap = temp_cap;
		}

		~vector(){
			size_type	i = 0, max = this->size();
			
			for (i = 0; i < max; i++)
				this->alloc.destroy(this->_start + i);
			this->alloc.deallocate(this->_start, i);
		}

	};

	template < typename T, class _alloc > void swap(ft::vector<T, _alloc>& l, ft::vector<T, _alloc>& r){
		l.swap(r);
	}

	template < typename T, class _alloc > bool operator==(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (l.size() == r.size() && ft::equal(l.begin(), l.end(), r.begin()));
	}

	template < typename T, class _alloc > bool operator!=(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (!(l == r));
	}

	template < typename T, class _alloc > bool operator<(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (ft::lexicographical_compare(l.begin(), l.end(), r.begin(), r.end()));
	}

	template < typename T, class _alloc > bool operator>(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (r < l);
	}

	template < typename T, class _alloc > bool operator>=(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (!(l < r));
	}

	template < typename T, class _alloc > bool operator<=(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (!(r < l));
	}

}

#endif
