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

#include "vector.hpp"

using namespace ft;


int main()
{

	try{

		// reverse_it_test();

		// std::cout << YELLOW1 << "size: " << my_vector.size() << " .. cap: " << my_vector.capacity() << RESET << std::endl;
		// std::cout << YELLOW1 << "size: " <<  my_vec_range.size() << " .. cap: " << my_vec_range.capacity() << RESET << std::endl;

		// std::cout << BLUE1 << "size: " << og_vector.size() << " .. cap: " << og_vector.capacity() << RESET << std::endl;
		// std::cout << BLUE1 << "size: " <<  og_vec_range.size() << " .. cap: " << og_vec_range.capacity() << RESET << std::endl;

		// vector<int>::iterator		my_itcopy = my_it;
		// std::vector<int>::iterator	*og_itcopy;

		// *my_itcopy = 0;
		// *og_itcopy = 0;

		// if (my_it <= my_itcopy)
		// 	std::cout << YELLOW1 << "mine works!" << RESET << std::endl;
		// else 
		// 	std::cout << YELLOW1 << "YEEEE!" << RESET << std::endl;
		// if (og_it <= og_itcopy)
		// 	std::cout << BLUE1 << "og works..." << RESET << std::endl;
		// else
		// 	std::cout << BLUE1 << "YOOO!" << RESET << std::endl;

		// std::cout << YELLOW1 << (my_it - my_itcopy) << RESET << std::endl;
		// std::cout << BLUE1 << (og_it - og_itcopy) << RESET << std::endl;

		// std::cout << YELLOW1 << "my it: " << *my_it << RESET << std::endl;
		// std::cout << BLUE1 << "og it: " << *og_it << std::endl;

		// for (; my_it != my_it_end; my_it++)
		// std::cout << YELLOW1 << "my it: " << *my_it << RESET << std::endl;
		// for (; og_it != og_it_end; og_it++)
		// std::cout << BLUE1 << "og it++: " << *og_it << std::endl;

		
	}

	catch (std::exception& e){
		std::cerr << RED1 << e.what()<< RESET << std::endl;
	}

	/* -------------------------------------------------------------------------- */

	// vector<int> i;
	// my_vector.push_back(1);
	// my_vector.push_back(2);
	// my_vector.push_back(3);
	// my_vector.push_back(4);
	// my_vector.push_back(5);
	// my_vector.getC();
	// std::cout << my_vector.size() << std::endl;
	// std::cout << "---------------------------" << std::endl;

	// std::vector<int> v;
	// std::cout << "size before push_back: " << v.size() << std::endl;
	// v.push_back(1);
	// std::cout << "size after one push_back: " << v.size() << std::endl;
	// v.push_back(2);
	// std::cout << "size after two push_back: " << v.size() << std::endl;
	// v.push_back(3);
	// v.push_back(4);
	// v.push_back(5);
	// v.push_back(6);
	// std::cout << "size after six push_back: " << v.size() << std::endl;

	// std::vector<int>::iterator it = v.begin();
	// std::cout << *it++ << " - ";
	// std::cout << *it++ << " - ";
	// std::cout << *it++ << " - ";
	// std::cout << *it++ << " - ";
	// std::cout << *it++ << " - ";
	// std::cout << *it++ << std::endl;;
	// for (int c = 0; c < 5; c++)
	// 	std::cout << c << ": " << v[c] << " - ";
	// std::cout << std::endl;
}

