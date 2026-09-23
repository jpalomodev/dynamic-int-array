# DynamicIntArray

A from-scratch implementation/demo of a dynamically allocated array of integers in C++. 

## To Build and Run 

In project directory:

To build, run 'make all'

To run, run './DynamicIntArray'

## Reflection

1. A DynamicIntArray object needs to maintain a unique state. No two DynamicIntArray
objects are allowed to share the same heap memory allocation.

2. The DynamicIntArray class owns a unique int* that points to a dynamically allocated array
stored in heap memory.

3. DynamicIntArray.size() represents the number of logical int objects currently stored in the array.
DynamicIntArray.capacity() represents the total live int objects that the array can store.

4. When push_back() causes growth, a new dynamically allocated array is created. A copy operation
is performed from the previous/full array to the new array, preserving item sequence. Once
complete, the previous/full array is deallocated from memory and DynamicIntArray.array_ is 
set to point to the new array.

5. Copying the raw address alone would be incorrect because it would lead to double delete
/ dangling pointer operations and modifying one object would result in modifying the other as well.

6. The custom copy constructor establishes independent ownership because it ensures no two
instances of DynamicIntArray share the same memory allocation leading to undefined behavior.

7. Copy assignment copies the values of an already existing source object to an already
existing destination object. Copy constructing copies the values of an already existing source
object to a newly declared object.

8. Self-assignment could be dangerous depending on implementation because it could cause deletion
of an object's own data before it is copied to itself.

9. Const and non-const at() overloads return different reference types to ensure that objects 
can only be modified through a non-const reference.

10. A pointer/ reference to an element may become invalid after growth because a new array
is created everytime growth occurs. Any references to data in the previous array become invalid
since they no longer point to a live object.

11. When a DynamicIntArray is destroyed, delete[] deallocates the heap memory used to store the
int array.

12. The class invariant is int* array_, which must remain unique for each object of type
DynamicIntArray no matter the operation performed on the object. 
