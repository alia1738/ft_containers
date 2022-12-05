/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:34:58 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/05 15:29:01 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {
	
	template <class T, class Container = ft::vector<T> > 
	class stack{

	public:
		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::const_reference	const_reference;
		typedef typename container_type::size_type			size_type;

	protected:
		container_type	_container;

	public:
		explicit stack (const container_type& c = container_type()): _container(c){	
		}

		bool empty() const{
			return (this->_container.empty());
		}

		void pop(){
			return (this->_container.pop_back());
		}

		void push (const value_type& val){
			return (this->_container.push_back(val));
		}

		size_type size() const{
			return (this->_container.size());
		}

		value_type& top() {
			return (this->_container.back());
		}
		
		const value_type& top() const{
			return (this->_container.back());
		}

		template < typename T1, class Container1 > 
		friend bool operator==(const ft::stack<T1, Container1>& l, const ft::stack<T1, Container1>& r);

		template < typename T1, class Container1 >
		friend bool operator<(const ft::stack<T1, Container1>& l, const ft::stack<T1, Container1>& r);
	};

	template < typename T, class Container > bool operator==(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r){
		return (l._container == r._container);
	}

	template < typename T, class Container > bool operator!=(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r){
		return (!(l == r));
	}

	template < typename T, class Container > bool operator<(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r){
		return (l._container < r._container);
	}

	template < typename T, class Container > bool operator>(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r){
		return (r < l);
	}

	template < typename T, class Container > bool operator>=(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r){
		return (!(l < r));
	}

	template < typename T, class Container > bool operator<=(const ft::stack<T, Container>& l, const ft::stack<T, Container>& r){
		return (!(r < l));
	}

}

#endif
