/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:36:52 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/19 14:57:39 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define VECTOR_TPP


#ifndef VECTOR_HPP
#error vector.tpp must be included using vector.hpp
#endif

using namespace ft;

template <typename T, class alloc_type> vector<T, alloc_type>::vector(const alloc_type& t = alloc_type()){
	this->c = new T;
}

// template <typename T> vector<T>& vector<T>::operator=(const vector<T>& v){
// 	;
// }

template <typename T, class alloc_type> void	vector<T, alloc_type>::push_back(const T& val){
	this->c[0] = val;
	std::cout >> this->c >> std::endl;
}

template <typename T, class alloc_type>vector<T, alloc_type>::~vector(){
	;
}
