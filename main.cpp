/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:39:19 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/25 15:21:09 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

using namespace ft;

int main()
{
	vector<int> i(5);
	std::vector<int> ii(5);

	i[0] = 0;
	i[1] = 1;
	i[2] = 2;
	ii[0] = 0;
	ii[1] = 1;
	ii[2] = 2;
	// ii.push_back(9);
	std::cout << YELLOW << "ii = " << YELLOW1 << ii.size() << RESET << std::endl;
	std::cout << YELLOW << "capacity ii = " << YELLOW1 << ii.capacity() << RESET << std::endl;
	std::cout << YELLOW << "ii[0] = " << YELLOW1 << ii[0] << RESET << std::endl;
	std::cout << YELLOW << "ii[1] = " << YELLOW1 << ii[1] << RESET << std::endl;
	std::cout << YELLOW << "ii[2] = " << YELLOW1 << ii[2] << RESET << std::endl;
	std::cout << YELLOW << "ii[5] = " << YELLOW1 << ii[5] << RESET << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << BLUE << "i = " << BLUE1 << i.size() << RESET << std::endl;
	std::cout << BLUE << "i[0] = " << BLUE1 << i[0] << RESET << std::endl;
	std::cout << BLUE << "i[1] = " << BLUE1 << i[1] << RESET << std::endl;
	std::cout << BLUE << "i[2] = " << BLUE1 << i[2] << RESET << std::endl;
	std::cout << BLUE << "i[5] = " << BLUE1 << i[5] << RESET << std::endl;


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
