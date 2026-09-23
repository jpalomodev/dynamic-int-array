#include "DynamicIntArray.hpp"
#include <cassert>
#include <iostream>

int main() {
    DynamicIntArray a;

    assert(a.size() == 0);
    assert(a.capacity() == 0);
    assert(a.empty() == 1);

    a.push_back(10);
    assert(a.size() == 1);
    assert(a.capacity() == 1);

    a.push_back(20);
    assert(a.size() == 2);
    assert(a.capacity() == 2);

    a.push_back(30);
    assert(a.size() == 3);
    assert(a.capacity() == 4);

    a.push_back(40);
    assert(a.size() == 4);
    assert(a.capacity() == 4);

    a.push_back(50);
    assert(a.size() == 5);
    assert(a.capacity() == 8);

    a.at(2) = 100;
    assert(a.at(0) == 10);
    assert(a.at(1) == 20);
    assert(a.at(2) == 100);
    assert(a.at(3) == 40);
    assert(a.at(4) == 50);

    bool exception_thrown = false;
    try {
        a.at(a.size());
    } catch (const std::out_of_range&) {
        exception_thrown = true;
    }

    assert(exception_thrown);

    exception_thrown = false;
    const DynamicIntArray& const_a = a;
    try {
        const_a.at(const_a.size());
    } catch (const std::out_of_range&) {
        exception_thrown = true;
    }

    assert(exception_thrown);

    DynamicIntArray b = a;
    assert(a.size() == b.size());
    assert(a.capacity() == b.capacity());
    for (size_t i = 0; i < a.size(); i++) {
        assert(a.at(i) == b.at(i));
    }
    assert(&a.at(0) != &b.at(0));

    b.at(2) = 200;
    assert(a.at(0) == 10);
    assert(a.at(1) == 20);
    assert(a.at(2) == 100);
    assert(a.at(3) == 40);
    assert(a.at(4) == 50);

    DynamicIntArray c;
    c.push_back(25);

    c = b;
    assert(c.at(0) == 10);
    assert(c.at(1) == 20);
    assert(c.at(2) == 200);
    assert(c.at(3) == 40);
    assert(c.at(4) == 50);
    assert(&c.at(0) != &b.at(0));

    a = a;
    assert(a.size() == 5);
    assert(a.capacity() == 8);
    assert(a.empty() == 0);
    assert(a.at(0) == 10);
    assert(a.at(1) == 20);
    assert(a.at(2) == 100);
    assert(a.at(3) == 40);
    assert(a.at(4) == 50);

    c = b = a;
    for (size_t i = 0; i < a.size(); i++) {
        assert(a.at(i) == b.at(i) && b.at(i) == c.at(i));
    }

    const DynamicIntArray& view = a;
    assert(view.at(0) == 10);

    std::cout << "Program finished execution. Passed all test cases.\n";

    return 0;
}
