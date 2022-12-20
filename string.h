#pragma once
#include <iostream>

class String {
	int m_size;
	char* m_string;
	void Copy(const String& str_);
public:
	
	/*
	* @brief Конструктор по умолчанию
	*/
	String();

	/*
	* @brief Конструктор с параметрами
	* @param size_ - размер строки
	* @param str_ - массив символов
	*/
	String(int size_, const char* str_);

	/*
	* @brief Конструктор копирования
	* @param str_ - строка, из которой будет производиться копия
	*/
	String(const String& str_);

	/*
	* @brief Деструктор
	*/
	~String();

	/*
	* @brief Оператор присваивания
	* @param str_ - строка, от которой будет производиться присваивание
	*/
	String& operator=(const String& str_);

	/*
	* @brief Оператор сравнения == - проверка на равенство строк
	* @param str_ - строка, с которой будет производиться сравнение
	* @return true, если строки равны, false иначе
	*/
	bool operator==(const String& str_);

	/*
	* @brief Оператор сравнения != - проверка на неравенство строк
	* @param str_ - строка, с которой будет производиться сравнение
	* @return true, если строки неравны, false иначе
	*/
	bool operator!=(const String& str_);

	/*
	* @brief Оператор сравнения < - проверка, первая строка меньше второй или нет
	* @param str_ - строка, с которой будет производиться сравнение
	* @return true, если первая строка меньше второй, false иначе
	*/
	bool operator<(const String& str_);

	/*
	* @brief Оператор сравнения > - проверка, первая строка больше второй или нет
	* @param str_ - строка, с которой будет производиться сравнение
	* @return true, если первая строка больше второй, false иначе
	*/
	bool operator>(const String& str_);

	/*
	* @brief Оператор сравнения <= - проверка, первая строка меньше или равна второй или нет
	* @param str_ - строка, с которой будет производиться сравнение
	* @return true, если первая строка меньше или равна второй, false иначе
	*/
	bool operator<=(const String& str_);

	/*
	* @brief Оператор сравнения >= - проверка, первая строка больше или равна второй или нет
	* @param str_ - строка, с которой будет производиться сравнение
	* @return true, если первая строка больше или равна второй, false иначе
	*/
	bool operator>=(const String& str_);

	/*
	* @brief Конкатенация строк, создает копию
	* @str_ строка, с которой будет производиться конкатенация
	* @return Копия строки результата конкатенации
	*/
	String operator+(const String& str_);

	/*
	* @brief Конкатенация строк, результат в первой строке
	* @str_ строка, с которой будет производиться конкатенация
	* @return Строка, к которой конкатенировалась вторая строка
	*/
	String& operator+=(const String& str_);

	//Capacity:

	/*
	* @brief Проверяет, пустая ли строка
	* @return true, если строка пустая, false иначе
	*/
	bool IsEmpty();

	/*
	* Возвращает длину строки
	* @return Длина строки
	*/
	int Length();

	//Access
	
	/*
	* @brief Доступ к элементу по индексу
	* @param index_ - номер элемента
	* @return Символ по номеру
	*/
	char& At(int index_);

	/*
	* @brief Доступ к первому элементу
	* @return Символ по номеру
	*/
	char& Front();

	/*
	* @brief Доступ к последнему элементу
	* @return Символ по номеру
	*/
	char& Back();

	/*
	* @brief Доступ к элементу по индексу
	* @param index_ - номер элемента
	* @return Символ по номеру
	*/
	char& operator[](int index_);

	//Modifiers

	/*
	* @brief Очищает контейнер
	*/
	void Clear();

	/*
	* @brief Вставляет символ в строку на выбронную позицию
	* @param sym_ - символ для вставки
	* @param pos_ - номер в строке
	* @return Строку с вставленным символом на нужной позиции
	*/
	String& Insert(char sym_, int pos_);

	/*
	* @brief Удаление символа или диапазона из строки
	* @param firstPos_ - начало диапазона
	* @param lastPos_ - конец диапазона
	* @return Строка с удаленным диапазоном
	*/
	String& Erase(int firstPos_, int lastPos_);

	/*
	* @brief Вставка символа в конец строки
	* @param sym_ - символ для вставки
	* @return Строка с вставленным в конец символом
	*/
	String& Push_back(char sym_);

	/*
	* @brief Изменяет размер строки: если увеличивается, то новые ячейки заполняются нулями, иначе удаляются
	* @param size_ - новый размер
	*/
	void Resize(int size_);

	/*
	* @brief Меняет местами две строки
	* @param str_ вторая строка для обмена
	*/
	void Swap(String& str_);

	/*
	* @brief Конкатенирует две строки и возвращает копию
	* @param str_ - второя строка конкатенации
	* @return Копия строки результата конкатенации
	*/
	String Append(const String& str_);

	//Operations

	/*
	* @brief Возвращает си-строку
	* @return Си-строка
	*/
	const char* C_str();
	//Copy

	/*
	* @brief Поиск строки с выбранной позиции
	* @param str_ - строка, которую нужно найти
	* @param pos_ - позиция, с которой ведется поиск
	* @return Позиция найденной строки (если -1, то не нашли)
	*/
	int Find(const String& str_, int pos_);

	/*
	* @brief Генерирует подстроку длины len с позиции pos
	* @param len_ - количество символов в подстроке
	* @param pos_ - позиция, с которой нужно генерировать подстроку
	* @return Созданная подстрока
	*/
	String SubStr(int len_, int pos_);

	/*
	* @brief Сравнивает две строки
	* @param str_ - второя строка сравнения
	* @return -1 если первая меньше второй, 0, если равны и 1 если первая больше второй
	*/
	int Compare(const String& str_);

	/*
	* @brief Вывод строки в формате "строка"
	* @param stream - ссылка на поток вывода
	* @param str_ - строка, которую нужно вывести
	* @return Ссылка на поток вывода
	*/
	friend std::ostream& operator<<(std::ostream& stream, const String& str_);

	/*
	* @brief Ввод строки
	* @param stream - ссылка на поток ввода
	* @param str_ - строка, в которую будет введена строка
	* @return Ссылка на поток ввода
	*/
	friend std::istream& operator>>(std::istream& stream, String& str_);
};
