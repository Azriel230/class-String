#include <iostream>
#include "string.h"

int StrLen(char* str_)
{
	int counter = 0;
	while (str_[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

void String::Copy(const String& str_)
{
	if (str_.m_size == 0 || str_.m_string == nullptr)
	{
		m_size = 0;
		m_string = nullptr;
		return;
	}

	m_size = str_.m_size;
	m_string = new char[m_size + 1];

	for (int i = 0; i < m_size; i++)
		m_string[i] = str_.m_string[i];

	m_string[m_size] = '\0';
}

void String::Clear()
{
	m_size = 0;
	delete[] m_string;
	m_string = nullptr;
}

String::String()
{
	m_size = 0;
	m_string = nullptr;
}

String::String(int size_, char* str_)
{
	if (size_ == 0)
	{
		m_size = 0;
		m_string = nullptr;
		return;
	}

	m_size = size_;
	m_string = new char[m_size + 1];

	for (int i = 0; i < m_size; i++)
		m_string[i] = str_[i];

	m_string[m_size] = '\0';
}

String::String(const String& str_)
{
	Copy(str_);
}

String::~String()
{
	Clear();
}

String& String::operator=(const String & str_)
{
	if (this == &str_)
		return *this;
	Clear();
	Copy(str_);
	return *this;
}

bool String::operator==(const String& str_)
{
	if (m_size != str_.m_size)
		return false;
	if ((m_string == nullptr) && (str_.m_string == nullptr))
		return true;
	if ((m_string == nullptr) || (str_.m_string == nullptr))
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (m_string[i] != str_.m_string[i])
			return false;
	}

	return true;
}

bool String::operator!=(const String& str_)
{
	return !(*this == str_);
}

bool String::operator<(const String& str_)
{
	if (m_size < str_.m_size)
		return true;
	if (m_size > str_.m_size)
		return false;
	if ((m_string == nullptr) && (str_.m_string == nullptr))
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (m_string[i] < str_.m_string[i])
			return true;
	}

	return false;
}

bool String::operator>(const String& str_)
{
	if (m_size > str_.m_size)
		return true;
	if (m_size < str_.m_size)
		return false;
	if ((m_string == nullptr) && (str_.m_string == nullptr))
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (m_string[i] > str_.m_string[i])
			return true;
	}

	return false;
}

bool String::operator<=(const String& str_)
{
	if (m_size < str_.m_size)
		return true;
	if (m_size > str_.m_size)
		return false;
	if ((m_string == nullptr) && (str_.m_string == nullptr))
		return true;

	for (int i = 0; i < m_size; i++)
	{
		if (m_string[i] <= str_.m_string[i])
			return true;
	}

	return false;
}

bool String::operator>=(const String& str_)
{
	if (m_size > str_.m_size)
		return true;
	if (m_size < str_.m_size)
		return false;
	if ((m_string == nullptr) && (str_.m_string == nullptr))
		return true;

	for (int i = 0; i < m_size; i++)
	{
		if (m_string[i] >= str_.m_string[i])
			return true;
	}

	return false;
}

String String::operator+(const String& str_)
{
	String resStr;
	resStr.m_size = m_size + str_.m_size;
	resStr.m_string = new char[resStr.m_size + 1];

	int resCount = 0;
	for (int i = 0; i < m_size; i++)
	{
		resStr.m_string[resCount] = m_string[i];
		resCount++;
	}
	for (int i = 0; i < str_.m_size; i++)
	{
		resStr.m_string[resCount] = str_.m_string[i];
		resCount++;
	}

	resStr.m_string[resStr.m_size] = '\0';

	return resStr;
}

String& String::operator+=(const String& str_)
{
	String resStr;
	resStr.m_size = m_size + str_.m_size;
	resStr.m_string = new char[resStr.m_size + 1];

	int resCount = 0;
	for (int i = 0; i < m_size; i++)
	{
		resStr.m_string[resCount] = m_string[i];
		resCount++;
	}
	for (int i = 0; i < str_.m_size; i++)
	{
		resStr.m_string[resCount] = str_.m_string[i];
		resCount++;
	}

	resStr.m_string[resStr.m_size] = '\0';

	*this = resStr;

	return resStr;
}

bool String::IsEmpty()
{
	return (m_string == nullptr);
}

int String::Length()
{
	return m_size;
}

char& String::At(int index_)
{
	if ((index_ < 0) || (index_ >= m_size))
	{
		std::cout << "Error! Out of range!";
		exit(EXIT_FAILURE);
	}

	return m_string[index_];
}

char& String::Front()
{
	if (m_size == 0)
	{
		std::cout << "Error! Out of range!";
		exit(EXIT_FAILURE);
	}

	return m_string[0];
}

char& String::Back()
{
	if (m_size == 0)
	{
		std::cout << "Error! Out of range!";
		exit(EXIT_FAILURE);
	}

	return m_string[m_size - 1];
}

char& String::operator[](int index_)
{
	if ((index_ < 0) || (index_ >= m_size))
	{
		std::cout << "Error! Out of range!";
		exit(EXIT_FAILURE);
	}

	return m_string[index_];
}

String& String::Insert(char sym_, int pos_)
{

}


std::ostream& operator<<(std::ostream& stream, const String& str_)
{
	stream << '"';
	for (int i = 0; i < str_.m_size; i++)
		stream << str_.m_string[i];
	stream << '"';
	return stream;
}

std::istream& operator>>(std::istream& stream, String& str_)
{
	str_.Clear();

	char buffStr[1024];
	int countSize = 0;

	while (stream.peek() == '\n')
		stream.ignore();

	while (stream.peek() != EOF && stream.peek() != '\n')
	{
		if (stream.peek() == ' ')
		{
			stream.ignore();
			buffStr[countSize] = ' ';
			countSize++;
		}

		stream >> buffStr[countSize];
		countSize++;
	}

	buffStr[countSize] = '\0';

	str_.m_size = countSize;
	str_.m_string = new char[str_.m_size + 1];

	for (int i = 0; buffStr[i] != '\0'; i++)
		str_.m_string[i] = buffStr[i];

	str_.m_string[str_.m_size] = '\0';

	return stream;
}
