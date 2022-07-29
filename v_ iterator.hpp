/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_ iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:54:46 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/29 17:03:47 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_ITERATOR_HPP
# define V_ITERATOR_HPP

#include <iostream>

template <class T> class v_iterator {
	
public:
	v_iterator();
	v_iterator(const v_iterator& it);
	v_iterator& operator=(const v_iterator& it);

	bool	operator==(const v_iterator& it1, const v_iterator& it2);
	bool	operator!=(const v_iterator& it1, const v_iterator& it2);

	~v_iterator();
	
};

#endif