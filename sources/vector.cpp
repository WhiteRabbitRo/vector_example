#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() //конструктор
{
	size_ = 0;
	capacity_ = 0;
	elemetns_ = nullptr;
}

vector_t::vector_t(vector_t const & other) //конструктор копирования
{
	size_ = other.size_;
	elements_ = new int[size_];
	for (int i = 0; i < size_; i++) 
		elements_[i] = other.elements_[i];
}

vector_t & vector_t::operator =(vector_t const & other) //оператор присваивания с копированием
{
	if (elements_ != nullptr) delete[] elemets_;
	size_ = other.size_;
	elements_ = new int[size_];
	for (int i = 0; i < size_; i++) elements_[i] = other.elements_[i];
	
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	return false;
}

vector_t::~vector_t() //деструктор
{
	if (elements_ != nullptr) delete[] elements_;
}

std::size_t vector_t::size() const
{
    return 0;
}

std::size_t vector_t::capacity() const
{
    return 0;
}

void vector_t::push_back(int value)
{
}

void vector_t::pop_back()
{
}

int & vector_t::operator [](std::size_t index) //позволяет изменять значение элемента
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return 0;
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	return true;
}
