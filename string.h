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

	String& operator=(const String& str_);

	bool operator==(const String& str_);
	bool operator!=(const String& str_);
	bool operator<(const String & str_);
	bool operator>(const String& str_);
	bool operator<=(const String& str_);
	bool operator>=(const String& str_);

	String operator+(const String& str_);
	String& operator+=(const String& str_);

	//Capacity:
	bool IsEmpty();
	int Length();

	//Access
	char& At(int index_);
	char& Front();
	char& Back();
	char& operator[](int index_);

	//Modifiers
	//void Clear();
	String& Insert(char sym_, int pos_);
	String& Erase(int firstPos_, int lastPos_);
	String& Push_back(char sym_);
	void Resize(int size_);
	void Swap(String str_);
	String& Append(const String& str_);

	friend std::ostream& operator<<(std::ostream& stream, const String& str_);
	friend std::istream& operator>>(std::istream& stream, String& str_);
};
