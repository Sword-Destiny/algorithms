//
// Created by sworddestiny on 18-5-16.
//

#include <iostream>
#include "base/parentheses_balance.h"

using std::cout;
using std::endl;

int main() {
	char *s;
	s = const_cast<char *>("");
	cout << "str: " << s << " , answer: " << parentheses_balance(s, 0) << endl;

	s = const_cast<char *>("[]");
	cout << "str: " << s << " , answer: " << parentheses_balance(s, 2) << endl;

	s = const_cast<char *>("[");
	cout << "str: " << s << " , answer: " << parentheses_balance(s, 1) << endl;

	s = const_cast<char *>("[][");
	cout << "str: " << s << " , answer: " << parentheses_balance(s, 3) << endl;

	s = const_cast<char *>("[[asd]]");
	cout << "str: " << s << " , answer: " << parentheses_balance(s, 7) << endl;

	s = const_cast<char *>("[]dd[]");
	cout << "str: " << s << " , answer: " << parentheses_balance(s, 6) << endl;

	s = const_cast<char *>("][[[]]]");
	cout << "str: " << s << " , answer: " << parentheses_balance(s, 7) << endl;

	return 0;

	// 1100110
}
