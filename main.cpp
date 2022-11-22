#include <iostream>
#include "string.h"

int main()
{
	String str1;
	std::cin >> str1;
	std::cout << std::endl << "str1 = " << str1 << std::endl;

	String str2;
	std::cin >> str2;
	std::cout << std::endl << "str2 = " << str2 << std::endl;

	String str;
	str = str1 + str2;
	std::cout << std::endl << "str = " << str << std::endl;

	return 0;
}