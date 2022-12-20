#include <iostream>
#include "string.h"
#include "SException.h"

int main()
{
	try
	{
		String str1(5, "Hello");
		std::cout << std::endl << "str1 = " << str1 << std::endl;
		String str2(6, "World!");
		std::cout << std::endl << "str2 = " << str2 << std::endl;
		std::cout << std::endl;
		std::cout << (str1 < str2) << (str1 <= str2) << (str1 > str2) << (str1 >= str2) << (str1 == str2) << (str1 != str2);
		std::cout << std::endl;
		String str;
		str = str1 + str2;
		std::cout << std::endl << "str = " << str << std::endl;
		str += str2;
		std::cout << std::endl << "str = " << str << std::endl;
		std::cout << std::endl;
		std::cout << str1.IsEmpty() << std::endl;
		std::cout << str1.Length() << std::endl;
		std::cout << std::endl;
		std::cout << str1.At(2) << std::endl;
		std::cout << str1.Front() << std::endl;
		std::cout << str1.Back() << std::endl;
		std::cout << str1[3] << std::endl;
		std::cout << std::endl;
		str1.Insert('n', 4);
		std::cout << str1 << std::endl;
		str1.Erase(4, 4);
		std::cout << str1 << std::endl;
		str1.Push_back('!');
		std::cout << str1 << std::endl;
		str1.Resize(10);
		std::cout << str1 << std::endl;
		str1.Resize(3);
		std::cout << str1 << std::endl;
		str1.Swap(str2);
		std::cout << str1 << std::endl;
		std::cout << str2 << std::endl;
		str = str1.Append(str2);
		std::cout << str << std::endl;
		std::cout << std::endl;
		std::cout << str1.C_str() << std::endl;
		std::cout << str.Find(str1, 1) << std::endl;
		String subStr;
		subStr = str.SubStr(4, 3);
		std::cout << subStr << std::endl;
		std::cout << subStr.Compare(str) << std::endl;


		std::cout << std::endl << str[10];
		std::cout << std::endl << str[100];
	}
	catch (SException obj)
	{
		std::cout << obj;
	}

	return 0;
}
