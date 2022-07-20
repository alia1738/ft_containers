/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:36:52 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/20 15:50:42 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define VECTOR_TPP


#ifndef VECTOR_HPP
#error vector.tpp must be included using vector.hpp;
#endif

using namespace ft;

template <typename T, class alloc_type> vector<T, alloc_type>::vector(): _size(1){
	this->c = myalloc.allocate(1);
}

template <typename T, class alloc_type> vector<T, alloc_type>::vector(int n, const T& val): _size(n){
	this->c = myalloc.allocate(n);
	if (val)
	{
		std::cout << "hi" << std::endl;
		for (int i = 0; i < n; i++)
			this->myalloc.construct(c + i, val);		
	}
}

// template <typename T> vector<T>& vector<T>::operator=(const vector<T>& v){
// 	;
// }

template <typename T, class alloc_type> void	vector<T, alloc_type>::push_back(const T& val){
	static int i = 0;
	
	this->myalloc.construct(this->c + i, val);
	i++;
	if (i == this->_size)
		i = 0;
}

template <typename T, class alloc_type> int		vector<T, alloc_type>::size() const{
	return(this->_size);
}

template <typename T, class alloc_type>vector<T, alloc_type>::~vector(){
	;
}
