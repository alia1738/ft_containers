/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:58:06 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/10/28 10:35:39 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>

namespace ft {

	template < class T1, class T2 > struct pair {

		typedef T1		first_type;
		typedef T2		second_type;

		first_type	first;
		second_type	second;

		pair(){}

		template < class TT1, class TT2 > pair(const pair<TT1, TT2>& p){
			this->first = p.first;
			this->second = p.second;
		}

		pair(const first_type& f, const second_type& s){
			this->first = f;
			this->second = s;
		}

		pair&	operator=(const pair& p){
			if (this != &p) {
				this->first = p.first;
				this->second = p.second;
			}
			return (*this);
		}

		bool operator==(const pair& p){
			return ((this->first == p.first) && (this->second == p.second));
		}

		~pair(){}
	};

	template < class T1, class T2 > pair<T1, T2>	make_pair(T1 first, T2 second) {
		return (pair<T1, T2>(first, second));
	}

	// template < class T1, class T2 > bool	operator==(const pair<T1, T2> right, const pair<T1, T2> left);
	// template < class T1, class T2 > bool	operator!=(const pair<T1, T2> right, const pair<T1, T2> left);
	// template < class T1, class T2 > bool	operator<(const pair<T1, T2> right, const pair<T1, T2> left);
	// template < class T1, class T2 > bool	operator<=(const pair<T1, T2> right, const pair<T1, T2> left);
	// template < class T1, class T2 > bool	operator>(const pair<T1, T2> right, const pair<T1, T2> left);
	// template < class T1, class T2 > bool	operator>=(const pair<T1, T2> right, const pair<T1, T2> left);

}

#endif