#include <iostream>
#include "string.h"
#include "SException.h"

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

String::String(int size_, const char* str_)
{
	if ((size_ == 0) || (str_ == nullptr))
	{
		m_size = size_;
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

String& String::operator=(const String& str_)
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

	return *this;
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
		throw(SException("Error! Out of range!", *this));

	return m_string[index_];
}

char& String::Front()
{
	if (m_size == 0)
		throw(SException("Error! Out of range!", *this));

	return m_string[0];
}

char& String::Back()
{
	if (m_size == 0)
		throw(SException("Error! Out of range!", *this));

	return m_string[m_size - 1];
}

char& String::operator[](int index_)
{
	if ((index_ < 0) || (index_ >= m_size))
		throw(SException("Error! Out of range!", *this));

	return m_string[index_];
}

String& String::Insert(char sym_, int pos_)
{
	if ((pos_ < 0) || (pos_ > m_size))
		throw(SException("Error! Out of range!", *this));

	int n = 0;
	char* tempStr = new char[m_size + 2];
	while (n < pos_)
	{
		tempStr[n] = m_string[n];
		++n;
	}
	tempStr[pos_] = sym_;
	while (m_string[n] != '\0')
	{
		tempStr[n + 1] = m_string[n];
		n++;
	}
	tempStr[n + 1] = '\0';

	++m_size;
	delete[] m_string;
	m_string = new char[m_size + 1];

	for (int i = 0; i < m_size; i++)
		m_string[i] = tempStr[i];
	m_string[m_size] = '\0';

	delete[] tempStr;

	return *this;
}

String& String::Erase(int firstPos_, int lastPos_)
{
	if ((firstPos_ < 0) || (lastPos_ > m_size))
		throw(SException("Error! Out of range!", *this));


	if (firstPos_ > lastPos_)
		throw(SException("Error! You enter wrong range to delete", *this));

	char buffStr[1024];

	int n = 0;
	for (; n < firstPos_; n++)
		buffStr[n] = m_string[n];
	for (int i = lastPos_ + 1; i < m_size; i++, n++)
		buffStr[n] = m_string[i];

	buffStr[n] = '\0';

	m_size -= lastPos_ - firstPos_ + 1;
	delete[] m_string;

	if (m_size == 0)
	{
		m_string = nullptr;
		return *this;
	}

	for (int i = 0; i < m_size; i++)
		m_string[i] = buffStr[i];

	m_string[m_size] = '\0';
	return *this;
}

String& String::Push_back(char sym_)
{
	char buffstr[1024];
	int sizeStr = 0;

	while (m_string[sizeStr] != '\0')
	{
		buffstr[sizeStr] = m_string[sizeStr];
		sizeStr++;
	}
	sizeStr++;
	buffstr[sizeStr] = sym_;
	buffstr[sizeStr + 1] = '\0';

	delete[]m_string;
	m_size++;
	m_string = new char[m_size + 1];

	for (int i = 0; buffstr[i] != '\0'; i++)
		m_string[i] = buffstr[i];
	m_string[m_size] = '\0';

	return *this;
}

void String::Resize(int size_)
{
	if (size_ == m_size)
		return;
	char buffstr[1024];
	int sizeStr = 0;

	if (size_ > m_size)
	{
		while (m_string[sizeStr] != '\0')
		{
			buffstr[sizeStr] = m_string[sizeStr];
			sizeStr++;
		}
		while (sizeStr < size_)
		{
			buffstr[sizeStr] = '0';
			sizeStr++;
		}
		buffstr[size_] = '\0';

		delete[] m_string;
		m_size = size_;
		m_string = new char[m_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			m_string[i] = buffstr[i];
		}
		m_string[size_] = '\0';
	}
	else
	{
		while (sizeStr < size_)
		{
			buffstr[sizeStr] = m_string[sizeStr];
			sizeStr++;
		}
		buffstr[size_] = '\0';

		delete[] m_string;
		m_size = size_;
		m_string = new char[m_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			m_string[i] = buffstr[i];
		}
		m_string[size_] = '\0';
	}
}

void String::Swap(String str_)
{
	String tempStr = *this;
	*this = str_;
	str_ = tempStr;
	tempStr.Clear();
}

String& String::Append(const String& str_)
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

const char* String::C_str()
{
	char* resStr_ = new char[m_size + 1];
	for (int i = 0; i < m_size; i++)
		resStr_[i] = m_string[i];
	resStr_[m_size] = '\0';
	return resStr_;
}

int String::find(const String& str_, int pos_)
{
	int i = pos_;
	int j = 0;
	int res_pos = -1;

	for (i; i < m_size; i++)
	{
		if (m_string[i] == str_.m_string[i])
		{
			res_pos = i;
			for (i, j; j < str_.m_size; i++, j++)
			{
				if (m_string[i] != str_.m_string[i])
				{
					res_pos = -1;
					break;
				}
			}
		}
	}

	return res_pos;
}

String String::substr(int len_, int pos_)
{
	String res;
	if (pos_ == m_size)
		return res;
	if (pos_ > m_size)
		throw(SException("Error! Out of range!", *this));

	res.m_string = new char[len_ + 1];
	int j = pos_;
	int i = 0;
	for (i, j; i < len_ && j < m_size; i++, j++)
		res.m_string[i] = m_string[j];
	res.m_string[len_] = '\0';
	res.m_size = i;
	return res;
}

int String::compare(const String& str_)
{
	if (m_size < str_.m_size)
		return -1;
	if (m_size > str_.m_size)
		return 1;
	for (int i = 0; i < m_size; i++)
	{
		if (m_string[i] < str_.m_string[i])
			return -1;
		if (m_string[i] > str_.m_string[i])
			return 1;
	}
	return 0;
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
