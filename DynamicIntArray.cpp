#include "DynamicIntArray.hpp"
#include <format>
#include <iostream>
#include <stdexcept>

// public member functions
DynamicIntArray::DynamicIntArray() : array_(nullptr), size_(0), capacity_(0) {}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
    : size_(other.size_), capacity_(other.capacity_) {
    array_ = new int[capacity_];
    for (size_t i = 0; i < size_; i++) {
        array_[i] = other.array_[i];
    }
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    if (this == &other) {
        return *this;
    }

    delete[] array_;

    size_ = other.size_;
    capacity_ = other.capacity_;

    array_ = new int[capacity_];
    for (size_t i = 0; i < size_; i++) {
        array_[i] = other.array_[i];
    }

    return *this;
}

DynamicIntArray::~DynamicIntArray() { delete[] array_; }

void DynamicIntArray::push_back(int value) {
    if (size_ == capacity_) {
        increase_capacity();
    }

    array_[size_] = value;
    size_++;
}

int& DynamicIntArray::at(std::size_t index) {
    if (size_ == 0 || index > size_ - 1) {
        throw std::out_of_range(
            std::format("Index out of range for array of size {}", size_));
    }

    return array_[index];
}

const int& DynamicIntArray::at(std::size_t index) const {
    if (size_ == 0 || index > size_ - 1) {
        throw std::out_of_range(
            std::format("Index out of range for array of size {}", size_));
    }

    return array_[index];
}

std::size_t DynamicIntArray::size() const { return size_; }

std::size_t DynamicIntArray::capacity() const { return capacity_; }

bool DynamicIntArray::empty() const { return this->size_ == 0; }

void DynamicIntArray::print_all() const {
    for (size_t i = 0; i < size_; i++) {
        std::cout << array_[i] << " ";
    }
}

// private member functions
void DynamicIntArray::increase_capacity() {
    if (capacity_ == 0) {
        capacity_++;
        array_ = new int[capacity_];
        return;
    }

    capacity_ *= 2;
    int* increased = new int[capacity_];
    for (size_t i = 0; i < size_; i++) {
        increased[i] = array_[i];
    }

    delete[] array_;
    array_ = increased;
}
