#include <string>
#include "fstream"

#ifndef FT
	#include <map>
	namespace ft = std;
	std::string	type = "std_";

#else
	#include "../src/map.hpp"
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
		ft::map<int, std::string> m;
		file << "size: " << m.size() << std::endl;
		file << "-------------------------\n";
	}
	{ // range
		file << "Range:\n";
		ft::map<int, std::string> m;
		m.insert(ft::pair<int, std::string>(1, "hi"));
		m.insert(ft::pair<int, std::string>(2, "hii"));
		m.insert(ft::pair<int, std::string>(3, "hiii"));
		ft::map<int, std::string> r(m.begin(), m.end());
		file << "size: " << m.size() << " .. " << r.size() << std::endl;
		file << "m[1]= " << m[1] << " .. ";
		file << "m[2]= " << m[2] << " .. ";
		file << "m[3]= " << m[3] << std::endl;
		file << "r[1]= " << r[1] << " .. ";
		file << "r[2]= " << r[2] << " .. ";
		file << "r[3]= " << r[3] << std::endl;
		file << std::endl;
		file << "-------------------------\n";
	}
	{ // copy
		file << "Copy:\n";
		ft::map<std::string, int> m;
		m.insert(ft::pair<std::string, int>("hi", 11));
		file << "m size: " << m.size() << std::endl;
		m.insert(ft::pair<std::string, int>("hii", 22));
		file << "m size: " << m.size() << std::endl;
		m.insert(ft::pair<std::string, int>("hiii", 33));
		file << "m size: " << m.size() << std::endl;
		m.insert(ft::pair<std::string, int>("hiiii", 44));
		file << "m size: " << m.size() << std::endl;
	
		ft::map<std::string, int> c(m);
		file << "m size: " << m.size() << " .. c size: " << c.size() << std::endl;
		file << "m[hi]" << m["hi"] << " .. " << "c[hi]" << c["hi"] << std::endl;
		file << "m[hii]" << m["hii"] << " .. " << "c[hii]" << c["hii"] << std::endl;
		file << "m[hiii]" << m["hiii"] << " .. " << "c[hiii]" << c["hiii"] << std::endl;
		file << "m[hiiii]" << m["hiiii"] << " .. " << "c[hiiii]" << c["hiiii"] << std::endl;
		
		file << "-------------------------\n";
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
		ft::map<int, int> m;
		for (ft::map<int, int>::size_type i = 0; i < 10; i++) {
			m.insert(ft::pair<int, int>(i, (i * 11)));
			file << "m.at(i)= " << m.at(i) << std::endl;
		}
		file << "\n-------------------------\n";
	}
	{ // operator[]
		file << "Operator[]:\n";
		ft::map<int, int> m;
		for (ft::map<int, int>::size_type i = 0; i < 10; i++) {
			m.insert(ft::pair<int, int>(i, (i * 11)));
			file << "m[" << i << "]= " << m[i] << std::endl;
		}
		m[20] = 2002;
		file << "m[20]= " << m[20] << std::endl;
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
		ft::map<int, std::string>	m;
		m.insert(ft::pair<int, std::string>(1, "10"));
		m.insert(ft::pair<int, std::string>(2, "20"));
		m.insert(ft::pair<int, std::string>(3, "30"));
		m.insert(ft::pair<int, std::string>(4, "40"));
		m.insert(ft::pair<int, std::string>(5, "50"));
		m.insert(ft::pair<int, std::string>(6, "60"));
		m.insert(ft::pair<int, std::string>(7, "70"));
		m.insert(ft::pair<int, std::string>(8, "80"));
		m.insert(ft::pair<int, std::string>(9, "90"));
		ft::map<int, std::string>::iterator	it = m.begin();
		for (; it != m.end(); it++) {
			file << "it->first " << it->first << " .. it->second " << it->second << std::endl;}
		file << "\n-------------------------\n";
	}

	// { // reverse
	// 	file << "Reverse:\n";
	// 	//
	// 	file << "\n-------------------------\n";
	// }
	file.close();
}

/* ----------------------- Capacity ----------------------- */
void	capacity_test() {
	std::string		fileName = type + "capacity.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------------- Capacity ----------------------- */\n";
	
	{ // empty
		file << "Empty:\n";
		ft::map<int, int>	m;

		file << "m.empty()= " << m.empty() << std::endl;
		m.insert(ft::pair<int, int>(11, 111000));
		file << "m.empty()= " << m.empty() << std::endl;

		file << "\n-------------------------\n";
	}
	{ // size
		file << "Size:\n";
		ft::map<int, int>	m;

		file << "m.size()= " << m.size() << std::endl;
		m.insert(ft::pair<int, int>(11, 22));
		file << "m.size()= " << m.size() << std::endl;
		for (ft::map<int, int>::size_type i = 0; i < 11; i++)
			m.insert(ft::pair<int, int>(i, (i + i)));
		file << "m.size()= " << m.size() << std::endl;

		file << "\n-------------------------\n";
	}
	{ // max_size
		file << "Max_size:\n";
		
		ft::map<int, int>	m;
		file << "m.size()= " << m.max_size() << std::endl;

		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------------- Modifiers ---------------------- */
void	modifiers_test() {
	std::string		fileName = type + "modifiers.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------------- Modifiers ---------------------- */\n";
	
	{ // clear
		file << "Clear:\n";
		
		ft::map<int, int>	m;
		for (ft::map<int, int>::size_type i  = 0; i < 20; i++) {
			m.insert(ft::pair<int, int>(i, (i * 2)));
			file << "m[" << i << "]= " << m[i] << std::endl;
		}
		file << "m.size()= " << m.size() << std::endl;

		m.clear();
		file << "After using clear():" << std::endl;
		file << "m.size()= " << m.size() << std::endl;

		file << "\n-------------------------\n";
	}
	{ // insert
		file << "Insert:\n";
		ft::map<int, int>	m;

		file << " insert single elements:" << std::endl;
		m.insert(ft::pair<int, int>(1, 10));
		m.insert(ft::pair<int, int>(2, 20));
		m.insert(ft::pair<int, int>(3, 30));
		m.insert(ft::pair<int, int>(4, 40));
		m.insert(ft::pair<int, int>(5, 50));
		m.insert(ft::pair<int, int>(6, 60));
		m.insert(ft::pair<int, int>(7, 70));
		m.insert(ft::pair<int, int>(8, 80));
		m.insert(ft::pair<int, int>(9, 90));

		for (ft::map<int, int>::size_type i = 1; i < 10; i++) {
			file << "m[" << i << "]= " << m[i] << std::endl;}
		
		file << " insert single element with hint:" << std::endl;
		ft::map<int, int>::iterator it = m.end();
		it--;
		m.insert(it, ft::make_pair(10, 100));
		
		for (ft::map<int, int>::size_type i = 1; i <= 10; i++) {
			file << "m[" << i << "]= " << m[i] << std::endl;}
		
		file << " insert range:" << std::endl;
		ft::map<int, int>	mm;
		mm.insert(ft::pair<int, int>(22, 220));
		mm.insert(ft::pair<int, int>(33, 330));
		mm.insert(ft::pair<int, int>(44, 440));
		mm.insert(ft::pair<int, int>(55, 550));

		m.insert(mm.begin(), mm.end());

		for (ft::map<int, int>::size_type i = 1; i <= 10; i++) {
			file << "m[" << i << "]= " << m[i] << std::endl;}
		file << "m[22]= " << m[22] << std::endl;
		file << "m[33]= " << m[33] << std::endl;
		file << "m[44]= " << m[44] << std::endl;
		file << "m[55]= " << m[55] << std::endl;

		file << "\n-------------------------\n";
	}
	{ // erase
		file << "Erase:\n";
		ft::map<int, int>	m;

		m.insert(ft::pair<int, int>(1, 10));
		m.insert(ft::pair<int, int>(2, 20));
		m.insert(ft::pair<int, int>(3, 30));
		m.insert(ft::pair<int, int>(4, 40));
		m.insert(ft::pair<int, int>(5, 50));
		m.insert(ft::pair<int, int>(6, 60));
		m.insert(ft::pair<int, int>(7, 70));
		m.insert(ft::pair<int, int>(8, 80));
		m.insert(ft::pair<int, int>(9, 90));

		for (ft::map<int, int>::size_type i = 1; i < 10; i++) {
			file << "m[" << i << "]= " << m[i] << std::endl;}
		
		ft::map<int, int>::size_type	i = m.erase(7);
		file << " After erasing key 7:" << std::endl;
		file << " Erase return: " << i << std::endl;
		ft::map<int, int>::iterator	it = m.begin();
		for (; it != m.end(); it++)
			file << "it->first " << it->first << " .. it->second " << it->second << std::endl;
		
		it--;
		m.erase(it);
		file << " After erasing key 9:" << std::endl;
		// file << " Erase return: " << i << std::endl;
		it = m.begin();
		for (; it != m.end(); it++)
			file << "it->first " << it->first << " .. it->second " << it->second << std::endl;
		
		it = m.begin();
		it++;
		it++;
		it++;
		// it++;
		ft::map<int, int>::iterator end = m.end();
		end--;
		// end--;
		m.erase(it, end);
		file << "After erasing key 4 to key 8:" << std::endl;
		it = m.begin();
		for (; it != m.end(); it++)
			file << "it->first " << it->first << " .. it->second " << it->second << std::endl;
		file << "-------------------------\n";
	}
	{ // swap
		file << "Swap(member):\n";
		ft::map<int, int>	m;

		for (int i = 1; i < 10; i++)
			m.insert(ft::pair<int, int>(i, (i * 10)));

		ft::map<int, int>	mm;
		for (int i = 1; i < 6; i++)
			mm.insert(ft::pair<int, int>((i * 11), (i * 11 * 10)));

		file << " Before swapping:" << std::endl;
		file << " --- m ---" << std::endl;
		ft::map<int, int>::iterator	it = m.begin();
		for (; it != m.end(); it++)
			file << "it->first " << it->first << " .. it->second " << it->second << std::endl;

		file << " --- mm ---" << std::endl;
		it = mm.begin();
		for (; it != mm.end(); it++)
			file << "it->first " << it->first << " .. it->second " << it->second << std::endl;

		m.swap(mm);

		file << " After swapping:" << std::endl;
		file << " --- m ---" << std::endl;
		it = m.begin();
		for (; it != m.end(); it++)
			file << "it->first " << it->first << " .. it->second " << it->second << std::endl;

		file << " --- mm ---" << std::endl;
		it = mm.begin();
		for (; it != mm.end(); it++)
			file << "it->first " << it->first << " .. it->second " << it->second << std::endl;

		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------------- Observers ---------------------- */
void	observers_test() {
	std::string		fileName = type + "observers.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------------- Observers ---------------------- */\n";
	
	{ // key_comp
		file << "Key_comp:\n";
		ft::map<int, int>	m;
		m[0] = 123;
		m[1] = 456;
		m[2] = 789;

		ft::map<int, int>::key_compare c = m.key_comp();
		ft::map<int, int>::iterator it = m.begin();

		do {
			file << it->first << " => " << it->second << '\n';
		} while ( c((it++)->first, 2) );

		file << "\n-------------------------\n";
	}
	{ // value_comp
		file << "Value_comp:\n";
		ft::map<int, std::string>	m;
		m.insert(ft::pair<int, std::string>(1, "HI!"));
		m.insert(ft::pair<int, std::string>(2, "I am testing"));
		m.insert(ft::pair<int, std::string>(3, "123"));
		// m[1] = "HI!";
		// m[2] = "I am testing";
		// m[3] = "123";

		ft::map<int, std::string>::iterator it = m.begin();
		ft::pair<int, std::string> p(3, "123");

		do {
			file << it->first << " => " << it->second << '\n';
		} while ( m.value_comp()((*it++), p) );

		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------------- Operations ---------------------- */
// void	observers_test() {
// 	std::string		fileName = type + "operations.txt";

// 	std::ofstream	file(fileName);
// 	file << "/* ----------------------- Operations ---------------------- */\n";
	
// 	{ // count
// 		file << "Count:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // find
// 		file << "Find:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // equal_range
// 		file << "Equal_range:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // lower_bound
// 		file << "Lower_bound:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // upper_bound
// 		file << "Upper_bound:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	file.close();
// }

/* ----------------- Non-member Functions ----------------- */
// void	non_member_functions_test() {
// 	std::string		fileName = type + "non_member_functions.txt";

// 	std::ofstream	file(fileName);
// 	file << "/* ----------------- Non-member Functions ----------------- */\n";
	
// 	{ // swap
// 		file << "Swap(non-member):\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // relational operators
// 		file << "Relational Operators:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
	
// 	file.close();
// }

int main() {
	constructors_test();
	element_access_test();
	iterator_test();
	capacity_test();
	modifiers_test();
	observers_test();
}