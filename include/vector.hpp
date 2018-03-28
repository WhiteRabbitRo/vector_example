#include <iostream>

class vector_t
{
private:
	int * elements_;
	std::size_t size_; //количество элементов
	std::size_t capacity_; //выделенная память
public:
	vector_t(); //конструктор
	vector_t(vector_t const & other); //конструктор копирования
	vector_t & operator =(vector_t const & other);
	~vector_t(); //деструктор

	std::size_t size() const; //возвращение закрытого поля size
	std::size_t capacity() const;

	void push_back(int value); //1 - проверка заполненности, 2 -увеличивает размер
	void pop_back(); //

	int & operator [](std::size_t index);
	int operator [](std::size_t index) const;

	bool operator ==(vector_t const & other) const; //оператор сравнения
};

bool operator !=(vector_t const & lhs, vector_t const & rhs);
