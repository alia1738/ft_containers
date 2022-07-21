/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:35:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/21 17:14:20 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector> // remove
#include <memory>
#include <iostream>

namespace ft
{

	template <typename T, class alloc_type> class vector
	{

	private:
		std::allocator<T> myalloc;
		T		*c;
		int		_size;

	public:
		explicit vector(const alloc_type& alloc = alloc_type()): _size(1){
			this->c = myalloc.allocate(1);
		}
	
		explicit vector(int n, const T& val = T()): _size(n){
			this->c = myalloc.allocate(n);
			if (val)
			{
				std::cout << "hi" << std::endl;
				for (int i = 0; i < n; i++)
					this->myalloc.construct(c + i, val);
			}
		}

		// vector& operator=(const vector& v);

		void	push_back(const T& val){
			static int i = 0;
			
			this->myalloc.construct(this->c + i, val);
			i++;
			if (i == this->_size)
				i = 0;
		}

		int		size() const{
			return(this->_size);
		}

		/* !!!!!!!! remove !!!!!!!! */
		void	getC() const{
			for (int i = 0; i < _size; i++){
				std::cout << this->c[i] << " .. ";}
			std::cout << std::endl;
		}
		/* !!!!!!!!!!!!!!!!!!!!!!!! */

		~vector(){
			;
		}

	};

}

#endif
