#include "DynamicIntArray.hpp"
#include <iostream>

int main() {
    try {
        DynamicIntArray a;

        std::cout << "Created new DynamicIntArray...\n";
        std::cout << "The size of a: " << a.size() << "\n";
        std::cout << "The capacity of a: " << a.capacity() << "\n";
        std::cout << "Is a empty? " << a.empty() << "\n";
        a.print_all();

        std::cout << "\n\n";

        a.push_back(10);
        a.push_back(20);
        a.push_back(30);
        a.push_back(40);
        a.push_back(50);

        std::cout << "Pushed values 10, 20, 30, 40, 50...\n";
        std::cout << "The size of a: " << a.size() << "\n";
        std::cout << "The capacity of a: " << a.capacity() << "\n";
        std::cout << "Is a empty? " << a.empty() << "\n";
        a.print_all();

        std::cout << "\n\n";

        a.at(2) = 100;

        std::cout << "Changed the value at a[2] from 30 to 100...\n";
        std::cout << "The size of a: " << a.size() << "\n";
        std::cout << "The capacity of a: " << a.capacity() << "\n";
        std::cout << "Is a empty? " << a.empty() << "\n";
        a.print_all();

        std::cout << "\n\n";

        // This will throw a std::out_of_range exception...
        // a.at(a.size());

        DynamicIntArray b = a;
        std::cout
            << "Copy-constructed a new DynamicIntArray called b from a...\n";
        std::cout << "The size of b: " << b.size() << "\n";
        std::cout << "The capacity of b: " << b.capacity() << "\n";
        std::cout << "Is b empty? " << b.empty() << "\n";
        std::cout << "Address of a[0]: " << &a.at(0) << "\n";
        std::cout << "Address of b[0]: " << &b.at(0) << "\n";
        b.print_all();

        std::cout << "\n\n";

        DynamicIntArray c;
        c.push_back(67);
        c = b;

        std::cout
            << "Copy-assigned an existing DynamicIntArray called c from b...\n";
        std::cout << "The size of c: " << c.size() << "\n";
        std::cout << "The capacity of c: " << c.capacity() << "\n";
        std::cout << "Is c empty? " << c.empty() << "\n";
        std::cout << "Address of b[0]: " << &b.at(0) << "\n";
        std::cout << "Address of c[0]: " << &c.at(0) << "\n";
        c.print_all();

        std::cout << "\n\n";

        c = c;

        std::cout
            << "Assigned an existing DynamicIntArray called c to itself...\n";
        std::cout << "The size of c: " << c.size() << "\n";
        std::cout << "The capacity of c: " << c.capacity() << "\n";
        std::cout << "Is c empty? " << c.empty() << "\n";
        c.print_all();

        std::cout << "\n\n";

        DynamicIntArray d;
        d = c = b = a;

        std::cout << "Created a new DynamicIntArray called d and performed a "
                     "chained assignment | d = c = b = a...\n";
        std::cout << "The size of d: " << d.size() << "\n";
        std::cout << "The capacity of d: " << d.capacity() << "\n";
        std::cout << "Is d empty? " << d.empty() << "\n";
        d.print_all();

        std::cout << "\n\n";

        const DynamicIntArray& view = a;
        std::cout << "Reading a[0] through a const reference to a...\n";
        std::cout << view.at(0) << "\n\n";

        // This will fail for attempting to perform mutation through view...
        // view.at(0) = 1000;

    } catch (const std::exception& e) {
        std::cerr << "\n\nFATAL ERROR: " << e.what() << "\n";
        std::cout << "Exiting program with return value 1\n";
        return 1;
    }

    return 0;
}
