/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingTree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:08:49 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/09 15:47:11 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL_tree.hpp"


int  main(){
	ft::AVL_tree<int, int> t;

	std::cout << "--------------------" << std::endl;
	std::cout << "     ADD 0 - 20     " << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i <= 20; i++) {
		// std::cout << i << std::endl;
		t.add_new_node(ft::make_pair<int, int>(i, (i + 1)));
		// t.printTree(t.get_root());
	}
	// std::cout << "hi" << std::endl;
	t.deleteNode(3);

	std::cout << "--------------------" << std::endl;
	std::cout << "      PRINTING      " << std::endl;
	std::cout << "--------------------" << std::endl;
	t.printTree(t.get_root());
	std::cout << "--------------------" << std::endl << std::endl;

	// std::cout << "--------------------" << std::endl;
	// std::cout << "       ADD 1        " << std::endl;
	// std::cout << "--------------------" << std::endl;
	// t.add_new_node(ft::make_pair<int, int>(1,2));
	// t.printTree(t.get_root());
	// // std::cout << "--------------------" << std::endl << std::endl;

	// std::cout << "--------------------" << std::endl;
	// std::cout << "       ADD 2        " << std::endl;
	// std::cout << "--------------------" << std::endl;
	// t.add_new_node(ft::make_pair<int, int>(2,1));
	// t.printTree(t.get_root());
	// // std::cout << "--------------------" << std::endl << std::endl;

	// std::cout << "--------------------" << std::endl;
	// std::cout << "       ADD 3        " << std::endl;
	// std::cout << "--------------------" << std::endl;
	// t.add_new_node(ft::pair<int, int>(3,4));
	// t.printTree(t.get_root());
	// // std::cout << "--------------------" << std::endl << std::endl;

	// std::cout << "--------------------" << std::endl;
	// std::cout << "       ADD 0        " << std::endl;
	// std::cout << "--------------------" << std::endl;
	// t.add_new_node(ft::pair<int, int>(0,3));
	// t.printTree(t.get_root());
	// // std::cout << "--------------------" << std::endl << std::endl;

	// std::cout << "--------------------" << std::endl;
	// std::cout << "      DELETE 3      " << std::endl;
	// std::cout << "--------------------" << std::endl;
	// t.deleteNode(3);
	// t.printTree(t.get_root());
	// std::cout << "--------------------" << std::endl << std::endl;

}