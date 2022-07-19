/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:35:25 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/19 14:55:33 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector> // remove

namespace ft
{

	template <typename T, class alloc_type> class vector
	{

	private:
		void	*c;

	public:
		explicit vector(const alloc_type& t = alloc_type());
		// vector& operator=(const vector& v);

		void	push_back(const T& val);

		~vector();

	};

}

#include "vector.tpp" 

#endif
