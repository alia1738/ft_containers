#include <string>
#include "fstream"

#ifndef FT
	#include <stack>
	namespace ft = std;
	std::string	type = "std_";

#else
	#include "../src/stack.hpp"
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
		ft::stack<int> s;
		file << s.size() << std::endl;
		file << "-------------------------\n";
	}
	file.close();
}

/* -------------------- Element Access -------------------- */
void	element_access_test() {
	std::string		fileName = type + "element_access.txt";
	std::ofstream	file(fileName);

	file << "/* -------------------- Element Access -------------------- */\n";
	{ // top
		file << "Top:\n";
		ft::stack<std::string> s;
		s.push("Hello!");
			file << s.top() << std::endl;
		s.push("I am testing stack");
			file << s.top() << std::endl;
		s.push("hmmm.. seems like it's working so far");
			file << s.top() << std::endl;
		s.push("");
			file << s.top() << std::endl;

		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------------- Capacity ----------------------- */
void	capacity_test() {
	std::string		fileName = type + "capacity.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------------- Capacity ----------------------- */\n";
	
	{ // empty
		file << "Empty:\n";
		ft::stack<std::string> s;
		s.push("Hello!");
		s.push("I am testing stack");
		s.push("hmmm.. seems like it's working so far");
		s.push("");
		while (!s.empty()) {
			file << s.top() << std::endl;
			s.pop();
		}
		file << "\n-------------------------\n";
	}
	{ // size
		file << "Size:\n";
		ft::stack<int> s;
		file << "size = " << s.size() << std::endl;
		for (int i = 0; i < 10; i++) {
			s.push(i+1);
			file << "size = " << s.size() << std::endl;
		}

		while (!s.empty()) {
			file << "size = " << s.size() << std::endl;
			s.pop();
		}
			
		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------------- Modifiers ---------------------- */
void	modifiers_test() {
	std::string		fileName = type + "modifiers.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------------- Modifiers ---------------------- */\n";
	
	{ // push
		file << "Push:\n";
		ft::stack<int> s;
		file << "size = " << s.size() << std::endl;
		for (int i = 1; i <= 5; i++)
			s.push(i);
		file << "size = " << s.size() << std::endl;
		for (int i = 1; i <= 5; i++){
			file << s.top() << std::endl;
			s.pop();
		}
		file << "\n-------------------------\n";
	}
	{ // pop
		file << "Pop:\n";
		ft::stack<char> s;
		file << "size = " << s.size() << std::endl;
		for (char i = 'a'; i <= 'z'; i++)
			s.push(i);
		file << "size = " << s.size() << std::endl;
		for (char i = 'a'; i <= 'z'; i++){
			file << s.top() << std::endl;
			s.pop();
		}
		file << "size = " << s.size() << std::endl;
		file << "\n-------------------------\n";
	}
	file.close();
}

/* ----------------- Non-member Functions ----------------- */
void	non_member_functions_test() {
	std::string		fileName = type + "non_member_functions.txt";

	std::ofstream	file(fileName);
	file << "/* ----------------- Non-member Functions ----------------- */\n";
	
	{ // relational operators
		file << "Relational Operators:\n";
		ft::stack<int> s1;
		ft::stack<int> s2;
		ft::stack<int> s3;
		ft::stack<int> s4;
		
		for (int i = 1; i <= 5; i++) {
			s2.push(i);
			s4.push(i);
		}
		for (int i = 1; i <= 15; i++)
			s3.push(i);

		file << (s1 == s4) << " ";
		file << (s2 == s4) << " ";
		file << (s2 == s3) << " ";
		file << (s2 != s3) << " ";
		file << (s1 > s3) << " ";
		file << (s3 >= s2) << " ";
		file << (s2 < s4) << " ";
		file << (s4 <= s3);
		file << "\n-------------------------\n";
	}
	
	file.close();
}

int main() {
	constructors_test();
	element_access_test();
	capacity_test();
	modifiers_test();
	non_member_functions_test();
}