/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:14:39 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/08 17:23:20 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_HPP
# define EXTRA_HPP

namespace ft {
	template < class InputIterator1, class InputIterator2 > 
	bool equal (InputIterator1 f1, InputIterator1 l1, 
									InputIterator2 f2){
		for (; f1 != l1; f1++, f2++){
			if (*f1 != *f2)
				return (false);
		}
		return (true);
	}

	template < class InputIterator1, class InputIterator2, class BinaryPredicate > 
	bool equal (InputIterator1 f1, InputIterator1 l1, 
									InputIterator2 f2, BinaryPredicate pred){
		for (; f1 != l1; f1++, f2++){
			if (!pred(*f1, *f2))
				return (false);
		}
		return (true);
	}

	template < class InputIterator1, class InputIterator2 > 
	bool lexicographical_compare (InputIterator1 f1, InputIterator1 l1, 
									InputIterator2 f2, InputIterator2 l2){
		// for (; (f1 != l1); f1++, f2++){
		// 	if ((f2 == l2) || (*f1 > *f2))
		// 		return (false);
		// 	else if (*f1 < *f2)
		// 		return (true);
		// }
		// return (f2 != l2);
		for (; (f1 != l1) && (f2 != l2); ++f1, (void) ++f2)
    {
        if (*f1 < *f2)
            return true;
        if (*f2 < *f1)
            return false;
    }
 
    return (f1 == l1) && (f2 != l2);
	}

	template < class InputIterator1, class InputIterator2, class Compare > 
	bool lexicographical_compare (InputIterator1 f1, InputIterator1 l1, 
									InputIterator2 f2, InputIterator2 l2, Compare comp){
		for (; (f1 != l1) && (f2 != l2); f1++, f2++){
			if (!comp(*f1, *f2))
				return (false);
			else if (comp(*f1, *f2))
				return (true);
		}
		return (false);
	}

	template<typename T, T val> struct is_integral_base {
		static const T	value = val;
	};

	typedef is_integral_base<bool, true> true_type;
	typedef is_integral_base<bool, false> false_type;

	template<typename T> struct is_integral: false_type{};
	template<> struct is_integral<bool>: true_type{};
	template<> struct is_integral<int>: true_type{};
	template<> struct is_integral<short>: true_type{};
	template<> struct is_integral<long>: true_type{};
	template<> struct is_integral<long long>: true_type{};
	template<> struct is_integral<unsigned int>: true_type{};
	template<> struct is_integral<unsigned long>: true_type{};
	template<> struct is_integral<unsigned long long>: true_type{};
	template<> struct is_integral<char>: true_type{};
	template<> struct is_integral<signed char>: true_type{};
	template<> struct is_integral<unsigned char>: true_type{};
	template<> struct is_integral<wchar_t>: true_type{};

	template <bool, typename T = void> struct enable_if {};
	template <typename T> struct enable_if<true, T> {
		typedef T type;
	};
}

#endif
