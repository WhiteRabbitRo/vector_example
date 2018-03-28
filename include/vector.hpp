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
	vector_t & operator =(vector_t const & other); //оператор присваивания с копированием
	~vector_t(); //деструктор

	std::size_t size() const; //возвращение закрытого поля size
	std::size_t capacity() const; //возвращение закрытого поля capacity

	void push_back(int value); //1 - проверка заполненности, 2 -увеличивает размер
	void pop_back(); //1 - удаление элементов, 2 - проверка capacity (уменьшаем в 2 раза размер, если элементов в 4 раза больше)

	int & operator [](std::size_t index); //индексикация
	int operator [](std::size_t index) const; //позволяет изменять значения

	bool operator ==(vector_t const & other) const; //оператор сравнения
};

bool operator !=(vector_t const & lhs, vector_t const & rhs); //нахождение неравных массивов
