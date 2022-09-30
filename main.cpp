/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42abudhabmy_vector.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:39:19 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/08/02 16:05:08 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#if STD
	#include <vector>
	#include <map>
	#include <stack>
	namespace ft = std;

#else
	#include "./src/vector.hpp"
	// #include "map.hpp"
	// #include "stack.hpp"

#endif

int main()
{

	try{
		std::vector<int> i;
		ft::vector<int> vector;
		// random tests
	}

	catch (std::exception& e){
		std::cerr << RED1 << e.what()<< RESET << std::endl;
	}

}
