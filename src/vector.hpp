/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:35:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/09 17:05:10 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "viterator.hpp"
#include "rev_iterator.hpp"
#include "extra.hpp"

/* ----------------------- > >> Colors << < ----------------------- */

# define RED			"\033[0;31m"
# define RED1			"\033[1;31m"
# define RED2			"\033[2;31m"
# define RED3			"\033[3;31m"
# define RESET			"\x1B[0m"

namespace ft
{

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
		typedef v_iterator<value_type>						iterator;
		typedef v_iterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
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

		template < class InputIterator > 
		vector(InputIterator first, InputIterator end, 
			typename enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* = 0, const allocator_type& alloc = allocator_type()){
			this->alloc = alloc;
			int count = 0;
			for (InputIterator f = first; f != end; f++, count++)
				;
			this->_start = this->alloc.allocate(count);
			for (int i = 0; i < count; first++, i++) {
				this->alloc.construct((this->_start + i), *first);
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

		template < class InputIterator > void assign(InputIterator first, InputIterator last, typename enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* =0){
			size_type	new_size = 0;
			for (InputIterator f = first; f != last; f++, new_size++)
				;

			if (new_size >= this->cap){
				pointer	temp = alloc.allocate(new_size);
				
				size_type i = 0, max = this->size();
				for (; i < new_size; i++, first++){
					this->alloc.construct((temp + i), *first);
					if (i < max)
						this->alloc.destroy(this->_start + i);
				}

				this->alloc.deallocate(this->_start, max);
				this->_start = temp;
				this->_end = this->_start + i;
				this->cap = new_size;
			}
			else {
				for (size_type i = 0; i < new_size; i++, first++){
					alloc.destroy(this->_start + i);
					alloc.construct(this->_start + i, *first);
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
				size_type i = 0;
				for (; i < n; i++){
					alloc.destroy(this->_start + i);
					alloc.construct(this->_start + i, val);
				}
				this->_end = this->_start + i;
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
			size_type	new_size = this->size() + 1, start_i = 0, temp_i = 0, save_i = 0;
			this->cap = (!this->cap)? 1: this->cap;
			if (new_size > this->cap)
				this->cap *= 2;
			pointer	temp = alloc.allocate(new_size);
			for (bool added = false; temp_i < new_size;){
				if (!added && &(*position) == &this->_start[start_i]) {
					added = true;
					save_i = temp_i;
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
			return (this->begin() + save_i);
		}
	
		void	insert(iterator position, size_type n, const value_type& val) {
			size_type	new_size = this->size() + n, start_i = 0, temp_i = 0;
			this->cap = (!this->cap)? 1: this->cap;
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

		template <class InputIterator> 
		void	insert(iterator position, InputIterator first, InputIterator last, typename enable_if< !ft::is_integral<InputIterator>::value, InputIterator>::type* =0) {
			size_type	to_add = 0;
			for (InputIterator f = first; f != last; to_add++, f++)
				;
			size_type	new_size = this->size() + to_add, start_i = 0, temp_i = 0;
			this->cap = (!this->cap)? 1: this->cap;
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

	template < typename T, class _alloc > bool operator<=(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (!(r < l));
	}

	template < typename T, class _alloc > bool operator>(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (r < l);
	}

	template < typename T, class _alloc > bool operator>=(const ft::vector<T, _alloc>& l, const ft::vector<T, _alloc>& r){
		return (!(l < r));
	}


}

#endif
