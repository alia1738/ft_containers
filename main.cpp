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
	
		// vector<int> my_vector(3);
		std::vector<int> og_vector(3);

		// my_vector[0] = 9;
		// my_vector[1] = 1;
		// my_vector[2] = 2;
		// my_vector.push_back(5);
		// my_vector.push_back(8);
		// my_vector.push_back(10);
		// my_vector.push_back(11);
		og_vector[0] = 9;
		og_vector[1] = 1;
		og_vector[2] = 2;
		// og_vector.push_back(5);
		// og_vector.push_back(8);
		// og_vector.push_back(10);
		// og_vector.push_back(11);


		// vector<int>::iterator my_it = my_vector.begin();
		// vector<int>::iterator my_it_end = my_vector.end();
		std::vector<int>::iterator og_it = og_vector.begin();
		std::vector<int>::iterator og_it_end = og_vector.end();

		// vector<int> my_vec_range(og_it, og_it_end);
		std::vector<int> og_vec_range(og_it, og_it_end);

		// std::cout << YELLOW1 << "size: " << my_vector.size() << " .. cap: " << my_vector.capacity() << RESET << std::endl;
		// std::cout << YELLOW1 << "size: " <<  my_vec_range.size() << " .. cap: " << my_vec_range.capacity() << RESET << std::endl;

		std::cout << BLUE1 << "size: " << og_vector.size() << " .. cap: " << og_vector.capacity() << RESET << std::endl;
		std::cout << BLUE1 << "size: " <<  og_vec_range.size() << " .. cap: " << og_vec_range.capacity() << RESET << std::endl;

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

		// std::cout << PURPLE1 << "my_vector before pushing: " << my_vector.size() << " .. " << my_vector.capacity() << GREEN1 << " og_vector before pushing: " << og_vector.size() << " .. " << og_vector.capacity() << RESET << std::endl;
		// my_vector.push_back(9);
		// vector<int> copy(my_vector);
		// og_vector.push_back(9);
		// std::cout << "my vector: " << my_vector.at(0) << " .. OG vector: " << og_vector.at(0) << std::endl;
		// my_vector.pop_back();
		// og_vector.pop_back();
		// std::cout << "my vector: " << my_vector.at(0) << " .. OG vector: " << og_vector.at(0) << std::endl;
		// std::cout << "testing out of range for my vector: " << my_vector.at(1) << std::endl;
		// std::cout << "testing out of range for my vector: " << my_vector.at(2) << std::endl;
		
		// std::cout << PURPLE1 << "i afetr pushing 9: " << my_vector.size() << " .. " << my_vector.capacity() << GREEN1 << " og_vector after pushing 9: " << og_vector.size() << " .. " << og_vector.capacity() << RESET << std::endl;
		// my_vector.push_back(8);
		// og_vector.push_back(8);
		// std::cout << PURPLE1 << "i afetr pushing 8: " << my_vector.size() << " .. " << my_vector.capacity() << GREEN1 << " og_vector after pushing 8: " << og_vector.size() << " .. " << og_vector.capacity() << RESET << std::endl;
		// my_vector.push_back(7);
		// og_vector.push_back(7);
		// std::cout << PURPLE1 << "i afetr pushing 7: " << my_vector.size() << " .. " << my_vector.capacity() << GREEN1 << " og_vector after pushing 7: " << og_vector.size() << " .. " << og_vector.capacity() << RESET << std::endl;
		// my_vector.push_back(6);
		// og_vector.push_back(6);
		// std::cout << PURPLE1 << "i afetr pushing 6: " << my_vector.size() << " .. " << my_vector.capacity() << GREEN1 << " og_vector after pushing 6: " << og_vector.size() << " .. " << og_vector.capacity() << RESET << std::endl;
		// my_vector.push_back(5);
		// og_vector.push_back(5);
		// std::cout << PURPLE1 << "i afetr pushing 5: " << my_vector.size() << " .. " << my_vector.capacity() << GREEN1 << " og_vector after pushing 5: " << og_vector.size() << " .. " << og_vector.capacity() << RESET << std::endl;
		// my_vector.push_back(4);
		// og_vector.push_back(4);
		// std::cout << PURPLE1 << "i afetr pushing 4: " << my_vector.size() << " .. " << my_vector.capacity() << GREEN1 << " og_vector after pushing 4: " << og_vector.size() << " .. " << og_vector.capacity() << RESET << std::endl;
		// my_vector.push_back(3);
		// og_vector.push_back(3);
		// std::cout << PURPLE1 << "i afetr pushing 3: " << my_vector.size() << " .. " << my_vector.capacity() << GREEN1 << " og_vector after pushing 3: " << og_vector.size() << " .. " << og_vector.capacity() << RESET << std::endl;
		// std::cout << YELLOW << "og_vector = " << YELLOW1 << og_vector.size() << RESET << std::endl;
		// std::cout << YELLOW << "capacity og_vector = " << YELLOW1 << og_vector.capacity() << RESET << std::endl;
		// std::cout << YELLOW << "og_vector[0] = " << YELLOW1 << og_vector[0] << RESET << std::endl;
		// std::cout << YELLOW << "og_vector[1] = " << YELLOW1 << og_vector[1] << RESET << std::endl;
		// std::cout << YELLOW << "og_vector[2] = " << YELLOW1 << og_vector[2] << RESET << std::endl;
		// std::cout << YELLOW << "og_vector[3] = " << YELLOW1 << og_vector[3] << RESET << std::endl;
		// std::cout << YELLOW << "og_vector[4] = " << YELLOW1 << og_vector[4] << RESET << std::endl;
		// std::cout << YELLOW << "og_vector[5] = " << YELLOW1 << og_vector[5] << RESET << std::endl;
		// std::cout << YELLOW << "og_vector[6] = " << YELLOW1 << og_vector[6] << RESET << std::endl;
		// std::cout << "----------------------" << std::endl;
		// std::cout << BLUE << "i = " << BLUE1 << my_vector.size() << RESET << std::endl;
		// std::cout << BLUE << "capacity i = " << BLUE1 << my_vector.capacity() << RESET << std::endl;
		// std::cout << BLUE << "my_vector[0] = " << BLUE1 << my_vector[0] << RESET << std::endl;
		// std::cout << BLUE << "my_vector[1] = " << BLUE1 << my_vector[1] << RESET << std::endl;
		// std::cout << BLUE << "my_vector[2] = " << BLUE1 << my_vector[2] << RESET << std::endl;
		// std::cout << BLUE << "my_vector[3] = " << BLUE1 << my_vector[3] << RESET << std::endl;
		// std::cout << BLUE << "my_vector[4] = " << BLUE1 << my_vector[4] << RESET << std::endl;
		// std::cout << BLUE << "my_vector[5] = " << BLUE1 << my_vector[5] << RESET << std::endl;
		// std::cout << BLUE << "my_vector[6] = " << BLUE1 << my_vector[6] << RESET << std::endl;
		// std::cout << RED1 << "why the fuck are you seg faulting" << RESET << std::endl;
	}

	catch (std::exception& e){
		std::cerr << RED1 << e.what()<< RESET << std::endl;
	}

	/* -------------------------------------------------------------------------- */

	// { // range constructor test
	// 	vector<int> my_vector(3);
	// 	std::vector<int> og_vector(3);

	// 	my_vector[0] = 9;
	// 	my_vector[1] = 1;
	// 	my_vector[2] = 2;
	// 	my_vector.push_back(5);
	// 	my_vector.push_back(8);
	// 	my_vector.push_back(10);
	// 	my_vector.push_back(11);
	// 	og_vector[0] = 9;
	// 	og_vector[1] = 1;
	// 	og_vector[2] = 2;
	// 	og_vector.push_back(5);
	// 	og_vector.push_back(8);
	// 	og_vector.push_back(10);
	// 	og_vector.push_back(11);


	// 	vector<int>::iterator my_it = my_vector.begin();
	// 	vector<int>::iterator my_it_end = my_vector.end();
	// 	std::vector<int>::iterator og_it = og_vector.begin();
	// 	std::vector<int>::iterator og_it_end = og_vector.end();

	// 	vector<int> my_vec_range(og_it, og_it_end);
	// 	std::vector<int> og_vec_range(og_it, og_it_end);

	// 	std::cout << YELLOW1 << "size: " << my_vector.size() << " .. cap: " << my_vector.capacity() << RESET << std::endl;
	// 	std::cout << YELLOW1 << "size: " <<  my_vec_range.size() << " .. cap: " << my_vec_range.capacity() << RESET << std::endl;

	// 	std::cout << BLUE1 << "size: " << og_vector.size() << " .. cap: " << og_vector.capacity() << RESET << std::endl;
	// 	std::cout << BLUE1 << "size: " <<  og_vec_range.size() << " .. cap: " << og_vec_range.capacity() << RESET << std::endl;
	// }

	/* -------------------------------------------------------------------------- */

	// { // simple const iterator test
	// 	const vector<int> my_vector(5, 8);
	// 	const std::vector<int> og_vector(5, 8);
	// 	vector<int>::const_iterator my_it = my_vector.begin();
	// 	vector<int>::const_iterator my_it_end = my_vector.end();
	// 	std::vector<int>::const_iterator og_it = og_vector.begin();
	// 	std::vector<int>::const_iterator og_it_end = og_vector.end();
	// 	for (; *my_it != *my_it_end; *my_it++)
	// 		std::cout << YELLOW1 << *my_it << RESET << std::endl;
	// 	for (; *og_it != *og_it_end; *og_it++)
	// 		std::cout << BLUE1 << *og_it << RESET << std::endl;
	// }

	/* -------------------------------------------------------------------------- */

	// { // iterator test
	// 	vector<int> my_vector(3);
	// 	std::vector<int> og_vector(3);

	// 	my_vector[0] = 9;
	// 	my_vector[1] = 1;
	// 	my_vector[2] = 2;
	// 	og_vector[0] = 9;
	// 	og_vector[1] = 1;
	// 	og_vector[2] = 2;


	// 	vector<int>::iterator my_it = my_vector.begin();
	// 	vector<int>::iterator my_it_end = my_vector.end();
	// 	std::vector<int>::iterator og_it = og_vector.begin();
	// 	std::vector<int>::iterator og_it_end = og_vector.end();

	// 	*my_it++ = 5;
	// 	*og_it++ = 5;
	// 	my_it -= 1;
	// 	og_it -= 1;

	// 	my_it++;
	// 	og_it++;
	// 	my_it -= 1;
	// 	og_it -= 1;

	// 	for (; *my_it != *my_it_end; *my_it++)
	// 		std::cout << YELLOW1 << *my_it << RESET << std::endl;
	// 	for (; *og_it != *og_it_end; *og_it++)
	// 		std::cout << BLUE1 << *og_it << RESET << std::endl;
	// }

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
