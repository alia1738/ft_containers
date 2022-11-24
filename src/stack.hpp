/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:34:58 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/24 17:15:02 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {
	
	template <class T, class Container = ft::vector<T> > 
	class stack{

	public:
		typedef Container						container_type;
		typedef container_type::value_type		value_type;
		typedef container_type::const_reference	const_reference;
		typedef container_type::size_type		size_type;

	protected:
		container_type	_container;

	public:
		explicit stack (const container_type& c = container_type()): _container(c){	
		}

		bool empty() const{
			return (this->_container.empty());
		}

		size_type size() const{
			return (this->_container.size());
		}

		value_type& top();const value_type& top() const {
			return (this->_container.back());
		}

		void push (const value_type& val){
			return (this->_container.push_back());
		}

		void pop(){
			return (this->_container.pop_back());
		}

	};

}

#endif
