/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:37:57 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/09/14 15:00:03 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "fstream"

#ifndef FT
	#include <vector>
	namespace ft = std;
	std::string	type = "std_";

#else
	#include "vector.hpp"
	std::string	type = "ft_";

#endif

/* **************************** Member Functions **************************** */
/* --------------------- Constructors --------------------- */
void	constructors_test() {
	std::string		fileName = type + "constructors.txt";

	std::ofstream	file(fileName);
	file << "/* --------------------- Constructors --------------------- */\n";
	{ // defult
		file << "Defult:\n";
		ft::vector<int> vec;
		file << "size = " << vec.size() << "\n";
		file << "capasity = " << vec.capacity() << "\n";
		file << "-------------------------\n";
	}
	{ // fill
		file << "fill:\n";
		ft::vector<int> vec(10, 11);
		file << "size = " << vec.size() << "\n";
		file << "capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n-------------------------\n";

	}
	{ // range
		file << "Range:\n";
		ft::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		file << "size = " << vec.size() << "\n";
		file << "capasity = " << vec.capacity() << "\n";
		ft::vector<int>::iterator	it = vec.begin();
		ft::vector<int>::iterator	it_end = vec.end();
		ft::vector<int> vec2(it, it_end);
		file << "size = " << vec2.size() << "\n";
		file << "capasity = " << vec2.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec2.size(); i++)
			file << vec2[i] << " ";
		file << "\n-------------------------\n";
	}
	{ // copy
		file << "Copy:\n";
		ft::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		ft::vector<int> vec2(vec);
		file << "size = " << vec.size() << "\n";
		file << "capasity = " << vec.capacity() << "\n";
		file << "size = " << vec2.size() << "\n";
		file << "capasity = " << vec2.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec2.size(); i++)
			file << vec2[i] << " ";
		file << "\n-------------------------\n";
	}
	{ // assign
		file << "Assign:\n";
		ft::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		file << "size = " << vec.size() << "\n";
		file << "capasity = " << vec.capacity() << "\n";
		ft::vector<int> vec2(10, 11);
		file << "size = " << vec2.size() << "\n";
		file << "capasity = " << vec2.capacity() << "\n";
		vec2 = vec;
		file << "size = " << vec2.size() << "\n";
		file << "capasity = " << vec2.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec2.size(); i++)
			file << vec2[i] << " ";
		file << "\n-------------------------\n";
	}
	file.close();
}



/* -------------------- Element Access -------------------- */
void	element_access_test() {
	std::string		fileName = type + "element_access.txt";

	std::ofstream	file(fileName);
	file << "/* -------------------- Element Access -------------------- */\n";
	{ // at
		file << "At:\n";
		ft::vector<int> vec;
		for (int i = 0; i < 20; i++)
			vec.push_back(i);
		for (int i = 0; i < 20; i++)
			file << vec.at(i) << " ";
		file << "\n-------------------------\n";
	}
	{ // operator[]
		file << "Operator[]:\n";
			ft::vector<int> vec(10);
		for (int i = 0; i < 10; i++)
			vec[i] = i;
		for (int i = 0; i < 10; i++)
			file << vec[i] << " ";
		file << "\n-------------------------\n";
	}
	{ // front n back
		file << "Front n Back:\n";
		ft::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		file << "Front = " << vec.front() << "\n";
		file << "Back = " << vec.back();
		file << "\n-------------------------\n";
	}
	file.close();
}

/* ---------------------- Iterators ----------------------- */
void	iterator_test() {
	std::string		fileName = type + "iterator.txt";

	std::ofstream	file(fileName);
	file << "/* ---------------------- Iterators ----------------------- */\n";
	
	{ // regular
		file << "Regular:\n";
		ft::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		ft::vector<int>::iterator it = vec.begin();
		ft::vector<int>::iterator it_end = vec.end();
		for (; it != it_end; it++)
			file << *it << " ";
		file << "\n-------------------------\n";
	}

	{ // reverse
		file << "Reverse:\n";
		ft::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		ft::vector<int>::reverse_iterator it = vec.rbegin();
		ft::vector<int>::reverse_iterator it_end = vec.rend();
		for (; it != it_end; it++)
			file << *it << " ";
		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------------- Capacity ----------------------- */
void	capasity_test() {
	std::string		fileName = type + "capasity.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------------- Capacity ----------------------- */\n";
	
	{ // empty
		file << "Empty:\n";
		ft::vector<int> vec;
		file << vec.empty() << " ";
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		file << vec.empty();
		file << "\n-------------------------\n";
	}
	{ // max_size
		file << "Max_size:\n";
		ft::vector<int> vec;
		file << vec.max_size() << " ";
		ft::vector<int> vec2(10, 50);
		file << vec2.max_size() << " ";
		ft::vector<int> vec3(vec2);	
		file << vec3.max_size() << " ";
		file << "\n-------------------------\n";
	}
	{ // reserve
		file << "Reserve:\n";
		ft::vector<int> vec;
		vec.reserve(2);
		vec.reserve(2);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.reserve(100);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------------- Modifiers ---------------------- */
void	modifiers_test() {
	std::string		fileName = type + "modifiers.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------------- Modifiers ---------------------- */\n";
	
	{ // assign
		file << "Assign:\n";
		ft::vector<int> vec;
		ft::vector<int> vec1(10, 55);
		ft::vector<int> vec2;
		for (int i = 0; i < 10; i++)
			vec2.push_back(i * 10);

		file << "vec size = " << vec.size() << " ";
		file << "vec capasity = " << vec.capacity() << "\n";
		file << "vec1 size = " << vec.size() << " ";
		file << "vec1 capasity = " << vec.capacity() << "\n";
		file << "vec2 size = " << vec.size() << " ";
		file << "vec2 capasity = " << vec.capacity() << "\n";
		
		vec1.assign(vec.begin(), vec.end());
		vec.assign(5, 11);
		vec2.assign(vec2.begin(), vec2.end());
		
		file << "vec size = " << vec.size() << " ";
		file << "vec capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n";
		
		file << "vec1 size = " << vec.size() << " ";
		file << "vec1 capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec1.size(); i++)
			file << vec1[i] << " ";
		file << "\n";
		
		file << "vec2 size = " << vec.size() << " ";
		file << "vec2 capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec2.size(); i++)
			file << vec2[i] << " ";
		file << "\n-------------------------\n";
	}
	{ // clear
		file << "Clear:\n";
		ft::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.clear();
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		file << "\n-------------------------\n";
	}
	{ // insert
		file << "Insert:\n";
		ft::vector<int>	vec;
		vec.push_back(22);
		vec.push_back(44);
		vec.push_back(66);
		vec.push_back(88);
		vec.push_back(1010);

		vec.insert(vec.begin(), 11);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n";

		vec.insert(vec.begin(), 5, 33);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n";

		vec.insert(vec.begin(), vec.begin(), vec.end());
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		
		file << "\n-------------------------\n";

	}
	{ // erase
		file << "Erase:\n";
		ft::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		// vec.erase(vec.begin() + 1);
		ft::vector<int>::iterator it = vec.erase(vec.begin() + 1);
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n";
		for (ft::vector<int>::iterator it_end = vec.end(); it != it_end; it++)
			file << *it << " ";
		file << "\n";
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		ft::vector<int>::iterator it2 = vec.erase(vec.begin() + 2, vec.end() - 5);
		for (ft::vector<int>::iterator it_end = vec.end(); it2 != it_end; it2++)
			file << *it2 << " ";
		file << "\n";
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		file << "-------------------------\n";
	}
	{ // push_back
		file << "Push_back:\n";
		ft::vector<int> vec;
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.push_back(1);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.push_back(2);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.push_back(3);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.push_back(4);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.push_back(5);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n-------------------------\n";
	}
	{ // pop_back
		file << "Pop_back:\n";
		ft::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i * 10);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.pop_back();
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.pop_back();
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.pop_back();
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.pop_back();
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		vec.pop_back();
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (int i = 0; i < 10; i++)
			file << vec[i] << " ";
		file << "\n-------------------------\n";
	}
	{ // resize
		file << "Resize:\n";
		ft::vector<int> vec;
		vec.resize(5);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n";
		vec.resize(2, 22);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n";
		vec.resize(44, 4);
		file << "size = " << vec.size() << " ";
		file << "capasity = " << vec.capacity() << "\n";
		for (ft::vector<int>::size_type i = 0; i < vec.size(); i++)
			file << vec[i] << " ";
		file << "\n-------------------------\n";
	}
	{ // swap
		file << "Swap(member):\n";
		ft::vector<int> vec;
		ft::vector<int> vec2;
		for (int i = 0; i < 10; i++) {
			vec.push_back(i * 10);
			vec2.push_back(i);
		}
		for (int i = 0; i < 10; i++) {
			file << vec[i] << " ";
		}
		file << "\n";
		for (int i = 0; i < 10; i++) {
			file << vec2[i] << " ";
		}
		vec.swap(vec2);
		for (int i = 0; i < 10; i++) {
			file << vec[i] << " ";
		}
		file << "\n";
		for (int i = 0; i < 10; i++) {
			file << vec2[i] << " ";
		}
		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------- Non-member Functions ----------------- */
void	non_member_functions_test() {
	std::string		fileName = type + "non_member_functions.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------- Non-member Functions ----------------- */\n";
	
	{ // swap
		file << "Swap(non-member):\n";
		ft::vector<int> vec;
		ft::vector<int> vec2;
		for (int i = 0; i < 6; i++) {
			vec.push_back(i * 6);
			vec2.push_back(i);
		}
		for (int i = 0; i < 6; i++) {
			file << vec[i] << " ";
		}
		file << "\n";
		for (int i = 0; i < 6; i++) {
			file << vec2[i] << " ";
		}
		swap(vec, vec2);
		for (int i = 0; i < 6; i++) {
			file << vec[i] << " ";
		}
		file << "\n";
		for (int i = 0; i < 6; i++) {
			file << vec2[i] << " ";
		}
		file << "\n-------------------------\n";
	}
	{ // relational operators
		file << "Relational Operators:\n";
		ft::vector<int> vec;
		ft::vector<int> vec1(5, 55);
		ft::vector<int> vec2;
		ft::vector<int> vec3(vec);
		for (int i = 0; i < 10; i++)
			vec2.push_back(i * 10);
		file << (vec == vec3) << " ";
		file << (vec1 != vec2) << " ";
		file << (vec > vec2) << " ";
		file << (vec2 >= vec1) << " ";
		file << (vec1 < vec3) << " ";
		file << (vec3 <= vec2);
		file << "\n-------------------------\n";
	}
	
	file.close();
}

int main() {
	constructors_test();
	element_access_test();
	iterator_test();
	capasity_test();
	modifiers_test();
	non_member_functions_test();
}

// void	range_assign_test() { // range assign  
// 	vector<int> my_vector(3);
// 	std::vector<int> og_vector(3);

// 	my_vector[0] = 9;
// 	my_vector[1] = 1;
// 	my_vector[2] = 2;
// 	my_vector.push_back(5);
// 	my_vector.push_back(8);
// 	my_vector.push_back(10);
// 	my_vector.push_back(11);
// 	og_vector[0] = 9;
// 	og_vector[1] = 1;
// 	og_vector[2] = 2;
// 	og_vector.push_back(5);
// 	og_vector.push_back(8);
// 	og_vector.push_back(10);
// 	og_vector.push_back(11);

// 	vector<int>::iterator my_it = my_vector.begin();
// 	vector<int>::iterator my_it_end = my_vector.end();
// 	std::vector<int>::iterator og_it = og_vector.begin();
// 	std::vector<int>::iterator og_it_end = og_vector.end();

// 	vector<int> my_vec_ass;
// 	std::vector<int> og_vec_ass;

// 	// my_vec_ass.push_back(12);
// 	// my_vec_ass.push_back(12);
// 	// my_vec_ass.push_back(12);
// 	// my_vec_ass.push_back(12);

// 	// og_vec_ass.push_back(12);
// 	// og_vec_ass.push_back(12);
// 	// og_vec_ass.push_back(12);
// 	// og_vec_ass.push_back(12);
// 	std::cout << GREEN1 << "------ My vec ------" << RESET << std::endl;
// 	for (int i = 0; i < static_cast<int>(my_vec_ass.size()); i++)
// 		std::cout << PURPLE1 << my_vec_ass[i] << RESET << std::endl;
// 	std::cout << PURPLE1 << "size = " << my_vec_ass.size() << RESET << std::endl;

// 	std::cout << GREEN1 << "------ Og vec ------" << RESET << std::endl;
// 	for (int i = 0; i < static_cast<int>(og_vec_ass.size()); i++)
// 		std::cout << PURPLE1 << og_vec_ass[i] << RESET << std::endl;
// 	std::cout << PURPLE1 << "size = " << og_vec_ass.size() << RESET << std::endl;

// 	std::cout << GREEN1 << "------ My vec ------" << RESET << std::endl;
// 	my_vec_ass.assign(my_it, my_it_end);
// 	for (int i = 0; i < static_cast<int>(my_vec_ass.size()); i++)
// 		std::cout << YELLOW1 << my_vec_ass[i] << RESET << std::endl;
// 	std::cout << YELLOW1 << "size = " << my_vec_ass.size() << RESET << std::endl;

// 	std::cout << GREEN1 << "------ Og vec ------" << RESET << std::endl;
// 	og_vec_ass.assign(og_it, og_it_end);
// 	for (int i = 0; i < static_cast<int>(og_vec_ass.size()); i++)
// 		std::cout << YELLOW1 << og_vec_ass[i] << RESET << std::endl;
// 	std::cout << YELLOW1 << "size = " << og_vec_ass.size() << RESET << std::endl;
// }

// void	basic_const_it_test(){
// 	const vector<int> my_vector(5, 8);
// 	const std::vector<int> og_vector(5, 8);

// 	vector<int>::const_iterator my_it = my_vector.begin();
// 	vector<int>::const_iterator my_it_end = my_vector.end();
// 	std::vector<int>::const_iterator og_it = og_vector.begin();
// 	std::vector<int>::const_iterator og_it_end = og_vector.end();

// 	for (; *my_it != *my_it_end; *my_it++)
// 		std::cout << YELLOW1 << *my_it << RESET << std::endl;
// 	for (; *og_it != *og_it_end; *og_it++)
// 		std::cout << BLUE1 << *og_it << RESET << std::endl;
// }

// void	basic_it_test(){
// 	vector<int> my_vector(3);
// 	std::vector<int> og_vector(3);

// 	my_vector[0] = 9;
// 	my_vector[1] = 1;
// 	my_vector[2] = 2;
// 	og_vector[0] = 9;
// 	og_vector[1] = 1;
// 	og_vector[2] = 2;

// 	vector<int>::iterator my_it = my_vector.begin();
// 	vector<int>::iterator my_it_end = my_vector.end();
// 	std::vector<int>::iterator og_it = og_vector.begin();
// 	std::vector<int>::iterator og_it_end = og_vector.end();

// 	*my_it++ = 5;
// 	*og_it++ = 5;
// 	my_it -= 1;
// 	og_it -= 1;

// 	my_it++;
// 	og_it++;
// 	my_it -= 1;
// 	og_it -= 1;

// 	for (; *my_it != *my_it_end; *my_it++)
// 		std::cout << YELLOW1 << *my_it << RESET << std::endl;
// 	for (; *og_it != *og_it_end; *og_it++)
// 		std::cout << BLUE1 << *og_it << RESET << std::endl;
// }

// void	reverse_it_test(){
// 	std::vector<int> og_vec;

// 	og_vec.push_back(5);
// 	og_vec.push_back(6);
// 	og_vec.push_back(7);
// 	og_vec.push_back(8);
// 	og_vec.push_back(9);

// 	std::reverse_iterator<std::vector<int>::iterator> og_rev_it = og_vec.rbegin();
// 	std::reverse_iterator<std::vector<int>::iterator> og_rev_it_end = og_vec.rend();

// 	// og_rev_it_end--;
// 	std::cout << BLUE1 << *og_rev_it_end << RESET << std::endl;
// 	for (; og_rev_it != og_rev_it_end; og_rev_it++)
// 		std::cout << PURPLE1 << *og_rev_it << RESET << " .. ";
// 	std::cout << std::endl;
// }

// vector<int> i;
	// my_vector.push_back(1);
	// my_vector.push_back(2);
	// my_vector.push_back(3);
	// my_vector.push_back(4);
	// my_vector.push_back(5);
	// my_vector.getC();
	// std::cout << my_vector.size() << std::endl;
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