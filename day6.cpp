#include <iostream>
using namespace std;

//Theory 
//1. Smart pointers:
//    - Smart pointers are template classes provided by the C++ Standard Library to manage dynamic memory automatically.
//    - They help prevent memory leaks and dangling pointers by ensuring proper deallocation of memory when the pointer goes out of scope.
//    - Common smart pointers include std::unique_ptr, std::shared_ptr, and std::weak_ptr.
//    - std::unique_ptr: Represents exclusive ownership of a dynamically allocated object. Cannot be copied, only moved.
//    - std::shared_ptr: Represents shared ownership of a dynamically allocated object. Multiple shared_ptr instances can point to the same object, and the object is deleted when the last shared_ptr pointing to it is destroyed or reset.
//    - std::weak_ptr: A non-owning smart pointer that references an object managed by std::shared_ptr. It is used to break circular references that can lead to memory leaks.

//2. Templates:
//    - Templates allow you to write generic and reusable code.
//    - Function templates enable you to create functions that can operate with any data type.
//    - Class templates enable you to create classes that can operate with any data type.
//    - Syntax for function template:
template <typename T>
T add(T a, T b) {
    return a + b;
}

//3. Exceptions and Exception Handling:
//    - Exceptions are runtime anomalies or errors that occur during program execution.
//    - C++ provides a robust exception handling mechanism using try, catch, and throw keywords.
//    - The try block contains code that may throw an exception.
//    - The throw statement is used to signal that an exception has occurred.
//    - The catch block is used to handle the exception and define how the program should respond.
void riskyFunction(int x) {
    if (x == 0) {
        throw runtime_error("Division by zero error");
    }
    cout << "Result: " << (10 / x) << endl;
}
int main() {
    // Testing function template
    cout << "Sum of 3 and 4: " << add(3, 4) << endl; // Works with integers
    cout << "Sum of 2.5 and 1.5: " << add(2.5, 1.5) << endl; // Works with doubles

    // Testing exception handling
    try {
        riskyFunction(0); // This will throw an exception
    } catch (const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    try {
        riskyFunction(2); // This will not throw an exception
    } catch (const runtime_error& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}


// Coding: template Box<T> that stores a value of any type.
template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() const { return value; }
};


// Now replacing raw pointers with unique_ptr
#include <memory> // for std::unique_ptr
void useSmartPointer() {
    std::unique_ptr<Box<int>> intBox = std::make_unique<Box<int>>(123);
    std::cout << "Box contains: " << intBox->getValue() << std::endl;

    std::unique_ptr<Box<string>> strBox = std::make_unique<Box<string>>("Hello, Templates!");
    std::cout << "Box contains: " << strBox->getValue() << std::endl;
}
// Quiz:
//1. What is the purpose of exception handling in C++?
// Exception handling in C++ is used to manage and respond to runtime errors or exceptional conditions that occur during program execution. It allows developers to separate error-handling code from regular code, making programs more robust and easier to maintain.

//2. What are the keywords used in C++ for exception handling?
// The keywords used in C++ for exception handling are try, catch, and throw.

//3. What happens if you throw an exception but never catch it?
// If an exception is thrown but never caught, the program will terminate and call the std::terminate function, which usually results in abnormal program termination. This can lead to resource leaks and other issues since the normal cleanup code may not be executed.

//4. What is the output?
try {
    throw runtime_error("Error occurred");
} catch (exception &e) {
    cout << e.what();
}
// The output will be "Error occurred" because the runtime_error exception is caught by the catch block, and the what() method returns the error message.

//5. Whats the difference between:
int* p = new int(5);
delete p;
// and
unique_ptr<int> p = make_unique<int>(5);
// The first code snippet uses a raw pointer to allocate memory for an integer and requires manual deallocation using delete to prevent memory leaks. The second code snippet uses a std::unique_ptr, which is a smart pointer that automatically manages the memory and deallocates it when the unique_ptr goes out of scope, reducing the risk of memory leaks.

//6. What are unique_ptr, and shared_ptr?
// std::unique_ptr is a smart pointer that represents exclusive ownership of a dynamically allocated object.
// std::shared_ptr is a smart pointer that represents shared ownership of a dynamically allocated object, allowing multiple shared_ptr instances to point to the same object.

//7. When do you use a weak_ptr?
// std::weak_ptr is used to reference an object managed by std::shared_ptr without affecting its reference count. It is typically used to break circular references that can lead to memory leaks in shared ownership scenarios.

//8. What's wrong with this code?
int* p = new int[10];
delete p;
// The code incorrectly uses delete to deallocate memory allocated for an array. It should use delete[] instead of delete to properly deallocate the array memory.
// Corrected code:
int* p = new int[10];
delete[] p;

//9. Explain RAII:
// - RAII (Resource Acquisition Is Initialization) is a programming idiom used in C++ where resource allocation is tied to the lifetime of objects. Resources such as memory, file handles, or network connections are acquired during object creation (initialization) and released during object destruction. This ensures that resources are properly managed and released when they are no longer needed, reducing the risk of resource leaks and improving code safety.

// 10. Write psuedocode using smart pointers to create and safely delete a Dog object.
class Dog {
public:
    Dog() { cout << "Dog created" << endl; }
    ~Dog() { cout << "Dog destroyed" << endl; }
    void bark() { cout << "Woof!" << endl; }
};

int main() {
    unique_ptr<Dog> dog = make_unique<Dog>(); //smart pointer to manage Dog object
    dog->bark();
    return 0;
}