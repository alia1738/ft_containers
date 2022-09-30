/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:21:02 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/09/30 13:08:41 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_HPP
# define COMPARE_HPP

template <typename T> struct isNodeSmaller: binary_function <T, T, bool> {
	return (node1 < node2);
}

template <typename T> struct isNodeBigger: binary_function <T, T, bool> {
	return (node1 > node2);
}

#endif