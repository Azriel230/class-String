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

void String::Copy(const String & str_)
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

String String::operator+(const String& str_)
{
	String resSrt;
	resSrt.m_size = m_size + str_.m_size;
	resSrt.m_string = new char[resSrt.m_size + 1];

	int resCount = 0;
	for(int i = 0; i < m_size; i++)
	{
		resSrt.m_string[resCount] = m_string[i];
		resCount++;
	}
	for (int i = 0; i < str_.m_size; i++)
	{
		resSrt.m_string[resCount] = str_.m_string[i];
		resCount++;
	}

	resSrt.m_string[resSrt.m_size] = '\0';

	return resSrt;
}

String& String::operator+=(const String& str_)
{
	String resSrt;
	resSrt.m_size = m_size + str_.m_size;
	resSrt.m_string = new char[resSrt.m_size + 1];

	int resCount = 0;
	for (int i = 0; i < m_size; i++)
	{
		resSrt.m_string[resCount] = m_string[i];
		resCount++;
	}
	for (int i = 0; i < str_.m_size; i++)
	{
		resSrt.m_string[resCount] = str_.m_string[i];
		resCount++;
	}

	resSrt.m_string[resSrt.m_size] = '\0';

	return resSrt;
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