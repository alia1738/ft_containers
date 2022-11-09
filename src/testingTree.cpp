/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingTree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:08:49 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/09 09:43:38 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL_tree.hpp"

int  main(){
	ft::AVL_tree<int, int> t;

	std::cout << "--------------------" << std::endl;
	std::cout << "       ADD 1        " << std::endl;
	std::cout << "--------------------" << std::endl;
	t.add_new_node(ft::make_pair<int, int>(1,2));
	t.printTree(t.get_root());
	// std::cout << "--------------------" << std::endl << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "       ADD 2        " << std::endl;
	std::cout << "--------------------" << std::endl;
	t.add_new_node(ft::make_pair<int, int>(2,1));
	t.printTree(t.get_root());
	// std::cout << "--------------------" << std::endl << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "       ADD 3        " << std::endl;
	std::cout << "--------------------" << std::endl;
	t.add_new_node(ft::pair<int, int>(3,4));
	t.printTree(t.get_root());
	// std::cout << "--------------------" << std::endl << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "       ADD 0        " << std::endl;
	std::cout << "--------------------" << std::endl;
	t.add_new_node(ft::pair<int, int>(0,3));
	t.printTree(t.get_root());
	// std::cout << "--------------------" << std::endl << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "      DELETE 3      " << std::endl;
	std::cout << "--------------------" << std::endl;
	t.deleteNode(3);
	t.printTree(t.get_root());
	std::cout << "--------------------" << std::endl << std::endl;
}