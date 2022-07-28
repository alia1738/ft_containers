/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:39:19 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/28 16:48:26 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

using namespace ft;

int main()
{
	try{
		vector<int> i;
		std::vector<int> ii;

		// // i[0] = 0;
		// // i[1] = 1;
		// // i[2] = 2;
		// // ii[0] = 0;
		// // ii[1] = 1;
		// // ii[2] = 2;
		// std::cout << PURPLE1 << "i before pushing: " << i.size() << " .. " << i.capacity() << GREEN1 << " ii before pushing: " << ii.size() << " .. " << ii.capacity() << RESET << std::endl;
		i.push_back(9);
		// vector<int> copy(i);
		ii.push_back(9);
		std::cout << "my vector: " << i.at(0) << " .. OG vector: " << ii.at(0) << std::endl;
		std::cout << "testing out of range for my vector: " << i.at(1) << std::endl;
		std::cout << "testing out of range for my vector: " << i.at(2) << std::endl;
		
		// std::cout << PURPLE1 << "i afetr pushing 9: " << i.size() << " .. " << i.capacity() << GREEN1 << " ii after pushing 9: " << ii.size() << " .. " << ii.capacity() << RESET << std::endl;
		// i.push_back(8);
		// ii.push_back(8);
		// std::cout << PURPLE1 << "i afetr pushing 8: " << i.size() << " .. " << i.capacity() << GREEN1 << " ii after pushing 8: " << ii.size() << " .. " << ii.capacity() << RESET << std::endl;
		// i.push_back(7);
		// ii.push_back(7);
		// std::cout << PURPLE1 << "i afetr pushing 7: " << i.size() << " .. " << i.capacity() << GREEN1 << " ii after pushing 7: " << ii.size() << " .. " << ii.capacity() << RESET << std::endl;
		// i.push_back(6);
		// ii.push_back(6);
		// std::cout << PURPLE1 << "i afetr pushing 6: " << i.size() << " .. " << i.capacity() << GREEN1 << " ii after pushing 6: " << ii.size() << " .. " << ii.capacity() << RESET << std::endl;
		// i.push_back(5);
		// ii.push_back(5);
		// std::cout << PURPLE1 << "i afetr pushing 5: " << i.size() << " .. " << i.capacity() << GREEN1 << " ii after pushing 5: " << ii.size() << " .. " << ii.capacity() << RESET << std::endl;
		// i.push_back(4);
		// ii.push_back(4);
		// std::cout << PURPLE1 << "i afetr pushing 4: " << i.size() << " .. " << i.capacity() << GREEN1 << " ii after pushing 4: " << ii.size() << " .. " << ii.capacity() << RESET << std::endl;
		// i.push_back(3);
		// ii.push_back(3);
		// std::cout << PURPLE1 << "i afetr pushing 3: " << i.size() << " .. " << i.capacity() << GREEN1 << " ii after pushing 3: " << ii.size() << " .. " << ii.capacity() << RESET << std::endl;
		// std::cout << YELLOW << "ii = " << YELLOW1 << ii.size() << RESET << std::endl;
		// std::cout << YELLOW << "capacity ii = " << YELLOW1 << ii.capacity() << RESET << std::endl;
		// std::cout << YELLOW << "ii[0] = " << YELLOW1 << ii[0] << RESET << std::endl;
		// std::cout << YELLOW << "ii[1] = " << YELLOW1 << ii[1] << RESET << std::endl;
		// std::cout << YELLOW << "ii[2] = " << YELLOW1 << ii[2] << RESET << std::endl;
		// std::cout << YELLOW << "ii[3] = " << YELLOW1 << ii[3] << RESET << std::endl;
		// std::cout << YELLOW << "ii[4] = " << YELLOW1 << ii[4] << RESET << std::endl;
		// std::cout << YELLOW << "ii[5] = " << YELLOW1 << ii[5] << RESET << std::endl;
		// std::cout << YELLOW << "ii[6] = " << YELLOW1 << ii[6] << RESET << std::endl;
		// std::cout << "----------------------" << std::endl;
		// std::cout << BLUE << "i = " << BLUE1 << i.size() << RESET << std::endl;
		// std::cout << BLUE << "capacity i = " << BLUE1 << i.capacity() << RESET << std::endl;
		// std::cout << BLUE << "i[0] = " << BLUE1 << i[0] << RESET << std::endl;
		// std::cout << BLUE << "i[1] = " << BLUE1 << i[1] << RESET << std::endl;
		// std::cout << BLUE << "i[2] = " << BLUE1 << i[2] << RESET << std::endl;
		// std::cout << BLUE << "i[3] = " << BLUE1 << i[3] << RESET << std::endl;
		// std::cout << BLUE << "i[4] = " << BLUE1 << i[4] << RESET << std::endl;
		// std::cout << BLUE << "i[5] = " << BLUE1 << i[5] << RESET << std::endl;
		// std::cout << BLUE << "i[6] = " << BLUE1 << i[6] << RESET << std::endl;
		// std::cout << RED1 << "why the fuck are you seg faulting" << RESET << std::endl;
	}

	catch (std::exception& e){
		std::cerr << RED1 << e.what()<< RESET << std::endl;
	}


	// vector<int> i;
	// i.push_back(1);
	// i.push_back(2);
	// i.push_back(3);
	// i.push_back(4);
	// i.push_back(5);
	// i.getC();
	// std::cout << i.size() << std::endl;
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
