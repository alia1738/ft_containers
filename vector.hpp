/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:35:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/26 14:50:23 by aalsuwai         ###   ########.fr       */
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
		typedef typename _allocator::pointer		pointer;
		typedef pointer								iterator;

		pointer		_start;
		pointer		_end;
		size_type	cap;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()): _start(nullptr), _end(nullptr){
			this->_start = static_cast<allocator_type>(alloc).allocate(0);
			this->_end = this->_start;
			this->cap = this->size();
		}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _start(nullptr), _end(nullptr){
			if (n){
				(void)alloc;
				_allocator a;
				this->_start = a.allocate(n);
				for (size_type i = 0; i < n; i++)
					a.construct(this->_start + i, val);
				this->_end = this->_start + n;
				this->cap = this->size();
			}
		}

		reference operator[](size_type n){
			// if (n < this->size())
				return(*(this->_start + n));
			// else
			// 	return(...);
		}

		// vector& operator=(const vector& v);

		void	push_back(const value_type& val){
			if (this->cap == this->size())
			{
				size_type i;
				_allocator alloc;
		
				if (!this->cap)
					this->cap = 1;
				else
					this->cap *= 2;

				pointer temp = alloc.allocate(this->cap);
				for (i = 0; i < this->size(); i++)
					temp[i] = this->_start[i];
				temp[i++] = val;
				alloc.deallocate(this->_start, this->size());
				this->_start = temp;
				this->_end = temp + i;
			}

			else if (this->cap > this->size())
			{
				this->_start[this->size()] = val;
				this->_end = this->_start + (this->size() + 1);
			}
		}

		size_type		size() const{
			return(static_cast<size_type>(this->_end - this->_start));
		}

		size_type capacity() const{
			return(this->cap);
		}

		~vector(){
			;
		}

	};

}

#endif
