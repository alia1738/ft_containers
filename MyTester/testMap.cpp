#include <string>
#include "fstream"

// #ifndef FT
	#include <map>
	namespace ft = std;
	std::string	type = "std_";

// #else
// 	// #include "../src/map.hpp"
// 	std::string	type = "ft_";

// #endif

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
		for (ft::map<int, std::string>::size_type i = 0; i < m.size(); ++i) {
			file << m[i] << " ";
		}
		file << std::endl;
		for (ft::map<int, std::string>::size_type i = 0; i < r.size(); ++i) {
			file << r[i] << " ";
		}
		file << std::endl;
		file << "-------------------------\n";
	}
	{ // copy
		file << "Copy:\n";
		ft::map<std::string, int> m;
		m["hi"] = 11;
		file << "size: " << m.size() << std::endl;
		m["hii"] = 22;
		file << "size: " << m.size() << std::endl;
		m["hiii"] = 33;
		file << "size: " << m.size() << std::endl;
		m["hiiii"] = 44;
		file << "size: " << m.size() << std::endl;
	
		ft::map<std::string, int> c(m);
		file << "size: " << m.size() << " .. " << c.size() << std::endl;
		file << m["hi"] << " .. " << c["hi"] << std::endl;
		file << m["hii"] << " .. " << c["hii"] << std::endl;
		file << m["hiii"] << " .. " << c["hiii"] << std::endl;
		file << m["hiiii"] << " .. " << c["hiiii"] << std::endl;
		
		file << "-------------------------\n";
	}
	{ // assign
		file << "Assign:\n";
		ft::map<std::string, char> m;
		ft::map<std::string, char> a;
		m["hi"] = 'a';
		m["hii"] = 'b';
		m["hiii"] = 'c';
		a["a"] = 'y';
		a["b"] = 'z';
		file << "size: " << m.size() << " .. " << a.size() << std::endl;
		a = m;
		file << "size: " << m.size() << " .. " << a.size() << std::endl;
		file << m["hi"] << " .. " << a["hi"] << std::endl;
		file << m["hii"] << " .. " << a["hii"] << std::endl;
		file << m["hiii"] << " .. " << a["hiii"] << std::endl;
		file << "-------------------------\n";
	}
	file.close();
}

/* -------------------- Element Access -------------------- */
// void	element_access_test() {
// 	std::string		fileName = type + "element_access.txt";

// 	std::ofstream	file(fileName);
// 	file << "/* -------------------- Element Access -------------------- */\n";
// 	{ // at
// 		file << "At:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // operator[]
// 		file << "Operator[]:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	file.close();
// }

/* ---------------------- Iterators ----------------------- */
// void	iterator_test() {
// 	std::string		fileName = type + "iterator.txt";

// 	std::ofstream	file(fileName);
// 	file << "/* ---------------------- Iterators ----------------------- */\n";
	
// 	{ // regular
// 		file << "Regular:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}

// 	{ // reverse
// 		file << "Reverse:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	file.close();
// }

/* ----------------------- Capacity ----------------------- */
// void	capasity_test() {
// 	std::string		fileName = type + "capasity.txt";

// 	std::ofstream	file(fileName);
// 	file << "/* ----------------------- Capacity ----------------------- */\n";
	
// 	{ // empty
// 		file << "Empty:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // size
// 		file << "Size:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // max_size
// 		file << "Max_size:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	file.close();
// }

/* ----------------------- Modifiers ---------------------- */
// void	modifiers_test() {
// 	std::string		fileName = type + "modifiers.txt";

// 	std::ofstream	file(fileName);
// 	file << "/* ----------------------- Modifiers ---------------------- */\n";
	
// 	{ // clear
// 		file << "Clear:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // insert
// 		file << "Insert:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // erase
// 		file << "Erase:\n";
// 		//
// 		file << "-------------------------\n";
// 	}
// 	{ // swap
// 		file << "Swap(member):\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	file.close();
// }

/* ----------------------- Observers ---------------------- */
// void	observers_test() {
// 	std::string		fileName = type + "observers.txt";

// 	std::ofstream	file(fileName);
// 	file << "/* ----------------------- Observers ---------------------- */\n";
	
// 	{ // key_comp
// 		file << "Key_comp:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	{ // value_comp
// 		file << "Value_comp:\n";
// 		//
// 		file << "\n-------------------------\n";
// 	}
// 	file.close();
// }

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
}