/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:35:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/20 14:34:49 by aalsuwai         ###   ########.fr       */
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
		explicit vector();
		explicit vector(int n, const T& val = T());
		// vector& operator=(const vector& v);

		void	push_back(const T& val);
		int		size() const;

		void	getC() const{
			for (int i = 0; i < _size; i++){
				std::cout << this->c[i] << " .. ";}
			std::cout << std::endl;
			}

		~vector();

	};

}

#include "vector.tpp" 

#endif
