/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingTree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:08:49 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/23 11:18:39 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
// #include "avlTree.hpp"
// #include <string>
// // #include "fstream"
// #ifndef FT
#include <map>
// 	namespace ft = std;
// 	std::string	type = "std_";

// #else
// 	#include "map.hpp"
// 	std::string	type = "ft_";

// #endif

int main() {
	try {
		{
			std::cout << "/---------------------------\\ " << std::endl;
			std::cout << "|         STD Map           | " << std::endl;
			std::cout << "\\---------------------------/ " << std::endl;
			
			std::map<int, int>	m;

			m.insert(std::pair<int, int>(1, 10));
			m.insert(std::pair<int, int>(2, 20));
			m.insert(std::pair<int, int>(3, 30));
			m.insert(std::pair<int, int>(4, 40));
			m.insert(std::pair<int, int>(5, 50));
			m.insert(std::pair<int, int>(6, 60));
			m.insert(std::pair<int, int>(7, 70));
			m.insert(std::pair<int, int>(8, 80));
			m.insert(std::pair<int, int>(9, 90));

			std::map<int, int>::iterator	b = m.begin();
			// for (int i = 0; i < 8; i++)
			// 	b++;
			std::cout << "b->first " << b->first << " .. b->second " << b->second << std::endl;
			m.insert(b, std::pair<int, int>(10, 100));
			
			std::cout << " ---------- ERASE ---------- " << std::endl;
			std::cout << " m.size() " << m.size() << std::endl;
			std::map<int, int>::size_type	i = m.erase(7);
			std::cout << "return from m.erase(7) => " << i << std::endl;
			std::cout << " m.size() " << m.size() << std::endl;

			std::map<int, int>::iterator	it = m.begin();
			std::map<int, int>::iterator	it_end = m.end();

			
			std::cout << " --------- TESTING --------- " << std::endl;
			for (; it != it_end; it++) {
				std::cout << "it->first " << it->first << " .. it->second " << it->second << std::endl;
			}
			
			std::map<int, int>	m_copy(m.begin(), m.end());

			std::cout << " m.size() " << m.size() << std::endl;
			std::cout << " m_copy.size() " << m_copy.size() << std::endl;
			// std::cout << " m_copy[0] " << m_copy[0] << std::endl;
			// std::cout << " m_copy[1] " << m_copy[1] << std::endl;
			// std::cout << " m_copy[90] " << m_copy[90] << std::endl;
			
			std::map<int, int>	otherMap;
			std::map<int, int>::iterator	otherIt = m.begin();
			
			otherIt++;
			otherIt++;
			otherIt++;
			
			otherMap.insert(m.begin(), otherIt);
			otherIt = otherMap.begin();
			otherMap.at(1) = 999;
			for (; otherIt != otherMap.end(); otherIt++) {
				std::cout << "otherIt->first " << otherIt->first << " .. otherIt->second " << otherIt->second << std::endl;
			}
			std::cout << " otherMap.size() " << otherMap.size() << std::endl;

			std::cout << " ---------- ERASE ---------- " << std::endl;
			// ft::map<int, int>::size_type	ii = 
			otherMap.erase(otherMap.begin(), otherMap.end());
			// std::cout << "return from myMap.erase(7) => " << ii << std::endl;
			
			std::cout << " otherMap.size() " << otherMap.size() << std::endl;
			
			std::cout << " --------------------------- " << std::endl;
			std::cout << " --------------------------- " << std::endl << std::endl;
		}

		{
			std::cout << "/----------------------------\\ " << std::endl;
			std::cout << "|          my Map            | " << std::endl;
			std::cout << "\\----------------------------/ " << std::endl;
			
			ft::map<int, int>	myMap;

			myMap.insert(ft::make_pair(1, 10));
			myMap.insert(ft::make_pair(2, 20));
			myMap.insert(ft::make_pair(3, 30));
			myMap.insert(ft::make_pair(4, 40));
			myMap.insert(ft::make_pair(5, 50));
			myMap.insert(ft::make_pair(6, 60));
			myMap.insert(ft::make_pair(7, 70));
			myMap.insert(ft::make_pair(8, 80));
			myMap.insert(ft::make_pair(9, 90));

			ft::map<int, int>::iterator	b = myMap.begin();
			// for (int i = 0; i < 8; i++)
			// 	b++;
			std::cout << "b->first " << b->first << " .. b->second " << b->second << std::endl;
			myMap.insert(b, ft::make_pair(10, 100));

			std::cout << " ---------- ERASE ---------- " << std::endl;
			std::cout << " myMap.size() " << myMap.size() << std::endl;
			ft::map<int, int>::size_type	i = myMap.erase(7);
			std::cout << "return from myMap.erase(7) => " << i << std::endl;
			std::cout << " myMap.size() " << myMap.size() << std::endl;
			
			ft::map<int, int>::iterator	it = myMap.begin();
			ft::map<int, int>::iterator	it_end = myMap.end();

			std::cout << " --------- TESTING --------- " << std::endl;
			for (; it != it_end; it++) {
				std::cout << "it->first " << it->first << " .. it->second " << it->second << std::endl;
			}

			ft::map<int, int>	myMap_copy(myMap.begin(), myMap.end());

			std::cout << " myMap.size() " << myMap.size() << std::endl;
			std::cout << " myMap_copy.size() " << myMap_copy.size() << std::endl;
			// std::cout << " myMap_copy[1] " << myMap_copy[1] << std::endl;
			

			ft::map<int, int>	otherMap;
			ft::map<int, int>::iterator	otherIt = myMap.begin();
			
			otherIt++;
			otherIt++;
			otherIt++;
			
			// otherMap[1] = 999;
			otherMap.insert(myMap.begin(), otherIt);
			otherIt = otherMap.begin();
			otherMap.at(1) = 999;
			for (; otherIt != otherMap.end(); otherIt++) {
				std::cout << "otherIt->first " << otherIt->first << " .. otherIt->second " << otherIt->second << std::endl;
			}
			std::cout << " otherMap.size() " << otherMap.size() << std::endl;

			std::cout << " ---------- ERASE ---------- " << std::endl;
			// ft::map<int, int>::size_type	ii = 
			otherMap.erase(otherMap.begin(), otherMap.end());
			// std::cout << "return from myMap.erase(7) => " << ii << std::endl;

			std::cout << " otherMap.size() " << otherMap.size() << std::endl;
			// otherMap.insert(myMap.begin(), otherIt);
			
			std::cout << " --------------------------- " << std::endl;
			std::cout << " --------------------------- " << std::endl << std::endl;
			
		}

		// it--;
		// *it = 999;
		// std::cout << "it " << *it << std::endl;
		// std::cout << "*it-- " << *it-- << std::endl;
		// std::cout << "it " << *it << std::endl;
		// std::cout << "*it++ " << *it++ << std::endl;
		// // std::cout << "*it++ " << *it++ << std::endl;
		// std::cout << "it " << *it << std::endl;
		// std::cout << "it " << *it << std::endl;

		// for (ft::map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
			// std::cout << "The issue here is " << it->first << " and " << it->second <<  std::endl;

		// it--;
		// it--;
		// it++;
		// std::cout << "it have " << *it << std::endl;
		// it++;
		// std::cout << "it_end have " << *it_end << std::endl;

		// std::cout << "I have " << myMap.at(3) << " in myMap[3]" << std::endl;
		// std::cout << "I have " << myMap.at(1) << " in myMap[1]" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

// int  main(){
// 	ft::avlTree<int, int> t;

// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "     ADD 0 - 20     " << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	for (int i = 0; i <= 20; i++) {
// 		// std::cout << i << std::endl;
// 		t.add_new_node(ft::make_pair<int, int>(i, (i + 1)));
// 		// t.printTree(t.get_root());
// 	}
// 	// std::cout << "hi" << std::endl;
// 	t.deleteNode(11);

// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "      PRINTING      " << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	t.printTree(t.get_root());
// 	std::cout << "--------------------" << std::endl << std::endl;

// 	// std::cout << "--------------------" << std::endl;
// 	// std::cout << "       ADD 1        " << std::endl;
// 	// std::cout << "--------------------" << std::endl;
// 	// t.add_new_node(ft::make_pair<int, int>(1,2));
// 	// t.printTree(t.get_root());
// 	// std::cout << "--------------------" << std::endl << std::endl;

// 	// std::cout << "--------------------" << std::endl;
// 	// std::cout << "       ADD 2        " << std::endl;
// 	// std::cout << "--------------------" << std::endl;
// 	// t.add_new_node(ft::make_pair<int, int>(2,1));
// 	// t.printTree(t.get_root());
// 	// std::cout << "--------------------" << std::endl << std::endl;

// 	// std::cout << "--------------------" << std::endl;
// 	// std::cout << "       ADD 3        " << std::endl;
// 	// std::cout << "--------------------" << std::endl;
// 	// t.add_new_node(ft::pair<int, int>(3,4));
// 	// t.printTree(t.get_root());
// 	// // std::cout << "--------------------" << std::endl << std::endl;

// 	// std::cout << "--------------------" << std::endl;
// 	// std::cout << "       ADD 0        " << std::endl;
// 	// std::cout << "--------------------" << std::endl;
// 	// t.add_new_node(ft::pair<int, int>(0,3));
// 	// t.printTree(t.get_root());
// 	// // std::cout << "--------------------" << std::endl << std::endl;

// 	// std::cout << "--------------------" << std::endl;
// 	// std::cout << "      DELETE 1      " << std::endl;
// 	// std::cout << "--------------------" << std::endl;
// 	// t.deleteNode(1);
// 	// t.printTree(t.get_root());
// 	// std::cout << "--------------------" << std::endl << std::endl;

// }