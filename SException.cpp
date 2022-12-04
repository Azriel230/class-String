#include <iostream>
#include "SException.h"
#include "string.h"

std::ostream& operator<<(std::ostream& stream, const SException& obj)
{
	for (int i = 0; obj.m_message[i] != '\0'; i++)
		stream << obj.m_message[i];
	stream << std::endl;
	stream << "The object that caused the exception: " << obj.m_err_obj;

	return stream;
}
