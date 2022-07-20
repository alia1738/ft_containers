/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:39:19 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/07/20 15:53:58 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

using namespace ft;

int main()
{
	vector<int, int> i(5);
	i.push_back(1);
	i.push_back(2);
	i.push_back(3);
	i.push_back(4);
	i.push_back(5);
	i.getC();
	std::cout << i.size() << std::endl;
	
	std::vector<int> v(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	for (int c = 0; c < 5; c++)
		std::cout << c << ": " << v[c] << " - ";
	std::cout << std::endl;
}
