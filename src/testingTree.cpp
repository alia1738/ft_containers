/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingTree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:08:49 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/03 15:02:58 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL_tree.hpp"

int  main(){
	ft::AVL_tree<int, int> t;

	t.add_new_node(ft::make_pair<int, int>(1,2));
	std::cout << "--------------------" << std::endl;
	t.printTree(t.get_root());
	std::cout << "--------------------" << std::endl << std::endl;

	t.add_new_node(ft::make_pair<int, int>(2,1));
	std::cout << "--------------------" << std::endl;
	t.printTree(t.get_root());
	std::cout << "--------------------" << std::endl << std::endl;

	t.add_new_node(ft::pair<int, int>(3,4));
	std::cout << "--------------------" << std::endl;
	t.printTree(t.get_root());
	std::cout << "--------------------" << std::endl << std::endl;

	t.add_new_node(ft::pair<int, int>(0,3));
	std::cout << "--------------------" << std::endl;
	t.printTree(t.get_root());
	std::cout << "--------------------" << std::endl << std::endl;

	t.deleteNode(1);
	std::cout << "--------------------" << std::endl;
	t.printTree(t.get_root());
	std::cout << "--------------------" << std::endl << std::endl;
}