/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:40:16 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/11 15:49:00 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "avlTree.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<key>, class Allocate = std::allocator< pair<const key, val> > > 
	class map {

	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair <const key_type, mapped_type>			value_type;
		typedef typename Compare							key_compare;
		typedef typename Allocate							allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::size_type			size_type;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		
	private:
		// typedef avlTree <>
		
	public:
	};
}

#endif