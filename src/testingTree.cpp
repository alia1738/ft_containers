/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingTree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:08:49 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/18 17:07:41 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
// #include "avlTree.hpp"

int main() {
	try {
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

		ft::map<int, int>::iterator	it = myMap.begin();
		ft::map<int, int>::iterator	it_end = myMap.end();

		for (int i = 0; it != it_end; it++) {
			std::cout << "it have " << *it << std::endl;
		}

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