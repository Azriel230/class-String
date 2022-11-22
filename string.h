#include <iostream>

class String {
	int m_size;
	char* m_string;
	void Copy(const String& str_);
public:
	void Clear();
	String();
	String(int size_, char* str_);
	String(const String& str_);
	~String();

	String& operator=(const String& str_)
	{
		if (this == &str_)
			return *this;
		Clear();
		Copy(str_);
		return *this;
	}

	String operator+(const String& str_);
	String& operator+=(const String& str_);

	friend std::ostream& operator<<(std::ostream& stream, const String& str_);
	friend std::istream& operator>>(std::istream& stream, String& str_);
};