#include <iostream>
#include "string.h"
#include "SException.h"

int main()
{
	try
	{
		String str1(5, "Hello");
		//std::cin >> str1;
		std::cout << std::endl << "str1 = " << str1 << std::endl;

		String str2(6, "World!");
		//std::cin >> str2;
		std::cout << std::endl << "str2 = " << str2 << std::endl;

		String str;
		str = str1 + str2;
		std::cout << std::endl << "str = " << str << std::endl;

		std::cout << std::endl << str[10];
		std::cout << std::endl << str[100];
	}
	catch (SException obj)
	{
		std::cout << obj;
	}

	return 0;
}
