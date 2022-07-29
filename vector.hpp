/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:35:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/29 16:14:42 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector> // remove
#include <memory>
#include <iostream>

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

	template < typename T, class _alloc = std::allocator<T> > class vector
	{

	public:
		typedef _alloc								allocator_type;
		typedef std::allocator<T>					_allocator;
		typedef typename _allocator::size_type		size_type;
	
	private:
		typedef T									value_type;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef typename _allocator::pointer		pointer;
		typedef pointer								iterator;

		_allocator	alloc;
		pointer		_start;
		pointer		_end;
		size_type	cap;

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

		vector (const vector& v): _start(0), _end(0), cap(0){
			this->alloc = v.alloc;
			this->cap = v.cap;
			this->_start = this->alloc.allocate(v.size());

			size_type	i = 0;
			for (i = 0; i < v.size(); i++)
				this->alloc.construct((this->_start + i), *(v._start + i));
			this->_end = this->_start + i;
		}

		vector& operator=(const vector& v){
			this->_start = 0; this->_end = 0; this->cap = 0;
			if (this != &v){
				this(v);
			}
			return(*this);
		}

		reference operator[](size_type n){
			return(*(this->_start + n));
		}

		const_reference operator[] (size_type n) const{
			return(*(this->_start + n));
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
				this->_end = this->_start + ++i;
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

		allocator_type get_allocator() const{
			return (this->alloc);
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
			if (n < this->size){
				this->_end -= (this->size() - n);
				for (size_type i = this->size(); i > n; i--)
					this->alloc.destroy(this->_start + i);
			}
			else if (n > this->capasity){
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
					this->alloc.construct(this->start + i, val);
				this->_end += (n - this->size());
			}
		}

		size_type		size() const{
			return(static_cast<size_type>(this->_end - this->_start));
		}

		size_type capacity() const{
			return(this->cap);
		}

		~vector(){
			size_type	i = 0, max = this->size();
			
			for (i = 0; i < max; i++)
				this->alloc.destroy(this->_start + i);
			this->alloc.deallocate(this->_start, i);
		}

	};

}

#endif
