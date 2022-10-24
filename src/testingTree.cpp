/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingTree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:08:49 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/10/24 14:21:50 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AVL_tree.hpp"

int  main(){
	ft::AVL_tree<int, int> t;

	t.add_new_node(5);	
	t.add_new_node(3);	
	t.add_new_node(7);	
	t.add_new_node(1);	
	t.add_new_node(4);	
	t.add_new_node(0);

	t.printTree(t.get_root());
}