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
# define Y	"\033[0;33m"	// Yellow
# define B	"\033[0;34m"	// Blue
# define P	"\033[0;35m"	// Purple
# define W	"\033[0;37m"	// White
# define R	"\033[0;31m"	// Red
# define G	"\033[0;32m"	// Green
# define B	"\033[0;34m"	// Blue
# define C	"\033[0;36m"	// Cyan

#ifndef FT
	#include <vector>
	#include <map>
	#include <stack>
	namespace ft = std;

#else
	#include "./src/vector.hpp"
	#include "./src/map.hpp"
	#include "./src/stack.hpp"

#endif

int main()
{

	{
		std::cout << Y << "-------------- " << W << C << "VECTOR" << W << Y <<" --------------" << W << std::endl;
		ft::vector<int> vec(5, 55);
		std::cout << "size = " << vec.size() << std::endl;
		std::cout << "capasity = " << vec.capacity() << std::endl;
		for (int i = 0; i < 8; i++)
			vec.push_back(i * 2);
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
		std::cout << Y << "------------------------------------" << W << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << Y << "--------------- " << W << C << "STACK" << W << Y <<" --------------" << W << std::endl;
		ft::stack<char> s;
		for (char i = 'a'; i <= 'r'; i++)
			s.push(i);
		std::cout << "size = " << s.size() << std::endl;
		while (!s.empty()) {
			std::cout << s.top() << " ";
			s.pop();
		}
		std::cout << std::endl;
		std::cout << Y << "------------------------------------" << W << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << Y << "---------------- " << W << C << "MAP" << W << Y <<" ---------------" << W << std::endl;
		ft::map<int, std::string> m;
		m.insert(ft::pair<int, std::string>(1, "hi"));
		m.insert(ft::pair<int, std::string>(2, "hii"));
		m.insert(ft::pair<int, std::string>(3, "hiii"));
		ft::map<int, std::string> r(m.begin(), m.end());
		std::cout << "size: " << m.size() << " .. " << r.size() << std::endl;
		std::cout << "m[1]= " << m[1] << " .. ";
		std::cout << "m[2]= " << m[2] << " .. ";
		std::cout << "m[3]= " << m[3] << std::endl;
		std::cout << "r[1]= " << r[1] << " .. ";
		std::cout << "r[2]= " << r[2] << " .. ";
		std::cout << "r[3]= " << r[3];
		std::cout << std::endl;
		std::cout << Y << "------------------------------------" << W << std::endl;
	}

}
