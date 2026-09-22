#pragma once
#include <cstddef>

class DynamicIntArray {
public:
    DynamicIntArray();

    DynamicIntArray(const DynamicIntArray& other);

    DynamicIntArray(DynamicIntArray&&) = delete;

    ~DynamicIntArray();

    DynamicIntArray& operator=(const DynamicIntArray& other);

    DynamicIntArray& operator=(const DynamicIntArray&& other) = delete;

    void push_back(int value);

    int& at(std::size_t index);

    const int& at(std::size_t index) const;

    std::size_t size() const;

    std::size_t capacity() const;

    bool empty() const;

    void print_all() const;

private:
    int* array_;
    size_t size_;
    size_t capacity_;

    void increase_capacity();
};
