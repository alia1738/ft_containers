/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:58:06 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/08 17:56:36 by aalsuwai         ###   ########.fr       */
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

		template < class TT1, class TT2 > pair(const pair<TT1, TT2>& p): 
		first(p.first), second(p.second){
		}

		pair(const first_type& f, const second_type& s): first(f), second(s){
		}

		pair&	operator=(const pair& p){
			if (this != &p) {
				this->first = p.first;
				this->second = p.second;
			}
			return (*this);
		}

		// bool operator==(const pair& p){
		// 	return ((this->first == p.first) && (this->second == p.second));
		// }

		// bool operator<(const pair& p){
		// 	return ((this->first < p.first) && (this->second < p.second));
		// }

		// bool operator<(const pair& p){
		// 	return ((this->first < p.first));
		// }

		// bool operator>=(const pair& p){
		// 	return ((this->first >= p.first));
		// }

		// bool operator<=(const pair& p){
		// 	return ((this->first <= p.first));
		// }

		~pair(){}
	};

	template < class T1, class T2 > pair<T1, T2>	make_pair(T1 first, T2 second) {
		return (pair<T1, T2>(first, second));
	}

	template < class T1, class T2 > bool	operator==(const pair<T1, T2> l, const pair<T1, T2> r){
		return ((l.first == r.first) && (l.second == r.second));
	}
	template < class T1, class T2 > bool	operator!=(const pair<T1, T2> l, const pair<T1, T2> r){
		return (!(l == r));
	}
	template < class T1, class T2 > bool	operator<(const pair<T1, T2> l, const pair<T1, T2> r){
		return ((l.first < r.first) && (l.second < r.second));
	}
	template < class T1, class T2 > bool	operator<=(const pair<T1, T2> l, const pair<T1, T2> r){
		return (!(r < l));
	}
	template < class T1, class T2 > bool	operator>(const pair<T1, T2> l, const pair<T1, T2> r){
		return (r < l);
	}
	template < class T1, class T2 > bool	operator>=(const pair<T1, T2> l, const pair<T1, T2> r){
		return ((l.first >= r.first) && (l.second >= r.second));
	}

}

#endif