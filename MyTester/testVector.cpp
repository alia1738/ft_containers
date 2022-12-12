/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:37:57 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/12/12 11:00:49 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <string>
#include "fstream"

#ifndef FT
	#include <vector>
	namespace ft = std;
	std::string	type = "std_";
	std::string	for_time = "STD";


#else
	#include "../src/vector.hpp"
	std::string	type = "ft_";
	std::string	for_time = "FT";

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
		ft::swap(vec, vec2);
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

#include <sys/time.h>

int main() {
	timeval exec_time;
	gettimeofday(&exec_time, NULL);
	double start = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;

	constructors_test();
	element_access_test();
	iterator_test();
	capasity_test();
	modifiers_test();
	non_member_functions_test();

	std::string fileName = type + "time.txt";
	std::ofstream	file(fileName);

	gettimeofday(&exec_time, NULL);
	double end = 1.0e6 * exec_time.tv_sec + exec_time.tv_usec;
	file << for_time << ": ";
	file << std::fixed << std::setprecision(3) << (end - start) / 1000 << " ms" << std::endl;
}