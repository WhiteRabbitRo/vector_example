#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() //конструктор
{
    size_ = 0;
    capacity_ = 0;
    elements_ = nullptr;
}

vector_t::vector_t(vector_t const& other) //конструктор копирования
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    elements_ = new int[capacity_];
    for (unsigned int i = 0; i < size_; i++)
        elements_[i] = other.elements_[i];
}

vector_t& vector_t::operator=(vector_t const& other) //оператор присваивания с копированием
{
    if (this->elements_ == other.elements_)
        return *this;
    if (elements_ != nullptr)
        delete[] elements_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    elements_ = new int[capacity_];
    for (unsigned int i = 0; i < size_; i++)
        elements_[i] = other.elements_[i];

    return *this;
}

bool vector_t::operator==(vector_t const& other) const //оператор сравнения
{
    if (other.size_ != size_)
        return false;
    for (unsigned int i = 0; i < size_; i++) {
        if (elements_[i] != other.elements_[i])
            return false;
    }
    return true;
}

vector_t::~vector_t() //деструктор
{
    if (elements_ != nullptr)
        delete[] elements_;
    size_ = capacity_ = 0;
}

std::size_t vector_t::size() const //размер
{
    return size_;
}

std::size_t vector_t::capacity() const //память
{
    return capacity_;
}

void vector_t::push_back(int value) //добавление элемента
{
    if (size_ == 0) {
        size_++;
        capacity_ = 1;
        elements_ = new int[1];
        elements_[0] = value;
        return;
    }
    if (size_ == capacity_) {
        capacity_ *= 2;
        int* elements_2 = new int[capacity_];
        for (unsigned int i = 0; i < size_; i++)
            elements_2[i] = elements_[i];
        delete[] elements_;
        size_++;
        elements_ = new int[capacity_];
        for (unsigned int i = 0; i < size_; i++)
            elements_[i] = elements_2[i];
        elements_[size_ - 1] = value;
        delete[] elements_2;
        return;
    }
    size_++;
    elements_[size_ - 1] = value;
}

void vector_t::pop_back() //удаление элемента
{
    if (size_ == 0)
        return;
    if (size_ == 1) {
        size_ = 0;
        capacity_ = 1;
        return;
    };
    size_--;
    if (capacity_ == (4 * size_)) {
        int* elements_2 = new int[capacity_ / 2];
        capacity_ = capacity_ / 2;
        for (unsigned int i = 0; i < size_; i++)
            elements_2[i] = elements_[i];
        delete[] elements_;
        elements_ = new int[capacity_];
        for (unsigned int i = 0; i < size_; i++)
            elements_[i] = elements_2[i];
        delete[] elements_2;
        return;
    }
}

int& vector_t::operator[](std::size_t index) //позволяет изменять значение элемента
{
    return elements_[index];
}

int vector_t::operator[](std::size_t index) const
{
    return elements_[index];
}

bool operator!=(vector_t const& lhs, vector_t const& rhs) //оператор "не равно"
{
    if (lhs.size() != rhs.size())
        return true;
    for (unsigned int i = 0; i < rhs.size(); i++)
        if (lhs[i] != rhs[i])
            return true;
    return false;
}
