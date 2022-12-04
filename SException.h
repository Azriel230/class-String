#pragma once
#include <iostream>
#include "string.h"

class SException
{
	char m_message[128];
	String m_err_obj;
public:
	SException()
	{
		m_message[0] = '\0';
		m_err_obj = String();
	}
	SException(const char* error_message, String& str_)
	{
		int i = 0;
		for (i; error_message[i] != '\0'; i++)
			m_message[i] = error_message[i];
		m_message[i] = '\0';

		m_err_obj = str_;
	}
	~SException() {};

	friend std::ostream& operator<<(std::ostream& stream, const SException& obj);
};