// Theory
// 1. Default constructor is a constructor which can be called with no arguments. EX: ClassName obj; or ClassName obj();
// 2. Parameterized constructor is a constructor which can be called with arguments. EX: ClassName obj(arg1, arg2);
// 3. Copy constructor is a constructor which creates a new object as a copy of an existing object. EX: ClassName obj2 = obj1; or ClassName obj2(obj1);
// 4. A destructor is a special member function that is executed when an object of its class goes out of scope or is explicitly deleted. It has the same name as the class, preceded by a tilde (~), and it cannot take any arguments nor return any value. EX: ~ClassName() { // cleanup code }
// 5. A copy assignment operator is a special operator that is used to copy the contents of one object to another existing object of the same class. It is defined using the operator= syntax. EX: obj2 = obj1; where both obj1 and obj2 are objects of the same class.
// 6. Rule of Three states that if a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely requires all three. This is because these three functions are responsible for managing the resources of the class, and if one of them is not properly defined, it can lead to resource leaks or undefined behavior.
//7. Rule of Five extends the Rule of Three to include move semantics. It states that if a class requires a user-defined destructor, copy constructor, copy assignment operator, move constructor, or move assignment operator, it likely requires all five. This is because move semantics can help optimize resource management by allowing resources to be transferred from one object to another without unnecessary copying.

#include <iostream>

struct Vector {
  // Manage dynamic array to illustrate Rule of Three/Five
  int *data;
  int size;
  int capacity;

  public:
    //default constructor
    Vector() {
        data = new int[1];
        size = 0;
        capacity = 1;
    }

    // Parameterized constructor
    Vector(int n){
        data = new int[n];
        size = 0;
        capacity = n;
    }

    // copy constructor
    Vector(const Vector &other) {
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // copy assignment operator
    Vector& operator=(const Vector &other) {
        if (this != &other) { // self-assignment check
            delete[] data; // free existing resource
            size = other.size;
            capacity = other.capacity;
            data = new int[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // push back function
    void push_back(int value) {
        if (size == capacity) {
            // resize
            capacity *= 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    // pop back function
    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    // print elements
    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

};

// Quiz
//1. Whats the difference betweeen a constructor and a copy constructor?
// A constructor initializes a new object, while a copy constructor creates a new object as a copy of an existing object.
// ex: ClassName obj1; // constructor
//     ClassName obj2 = obj1; // copy constructor

//2. Why do we need a destructor in a class?
// A destructor is needed to free up resources that were allocated to an object when it goes out of scope or is deleted, preventing memory leaks.

//3. Explain the rule of 3
// If a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely requires all three to manage resources properly.
// ex: class MyClass {
//      MyClass(const MyClass& other); // copy constructor
//      MyClass& operator=(const MyClass& other); // copy assignment operator
//      ~MyClass(); // destructor
// };

//4. List 5 special member functions included in the rule of 5:
// 1. Destructor
// 2. Copy constructor 
// 3. Copy assignment operator
// 4. Move constructor
// 5. Move assignment operator

//5. Whats wrong with this class?
class Broken {
    int* data;
public:
    Broken(int val) { data = new int(val); }
    ~Broken() {}
};
// The class is missing a copy constructor and copy assignment operator. If an object of this class is copied, both objects will point to the same memory location, leading to double deletion when both destructors are called. This can be fixed by implementing the Rule of Three/Five.

//6. How would you fix the code above?
class Fixed {
    int* data;
public:
    Fixed(int val) { data = new int(val); }
    ~Fixed() { delete data; } // destructor
    Fixed(const Fixed &other) { // copy constructor
        data = new int(*(other.data));
    }
    Fixed& operator=(const Fixed &other) { // copy assignment operator
        if (this != &other) {
            delete data;
            data = new int(*(other.data));
        }
        return *this;
    }  
};

//7. Whats the difference between a deep and a shallow copy?
// Deep copy creates a new copy of all objects and their resources, while shallow copy copies only the references to the objects, leading to shared resources.
// ex: Deep copy - class MyClass { int* data; MyClass(const MyClass& other) { data = new int(*(other.data)); } }
//     Shallow copy - class MyClass { int* data; MyClass(const MyClass& other) { data = other.data; } }

//8. given this: whats printed?

class Example {
public:
    Example() { cout << "Default "; }
    Example(const Example&) { cout << "Copy "; }
};
int main() {
    Example a;
    Example b = a;
}
// Output: Default Copy, this is a shallow copy.

//9. Why is it bad to call delete[] on a pointer that was allocated with new?
// It is bad because it leads to undefined behavior, as the memory was not allocated as an array. This can cause memory corruption or crashes.
// ex: int* p = new int; delete[] p; // undefined behavior

//10. What is a move constructor and how does it differ from a copy constructor?
// A move constructor transfers ownership of resources from a temporary object to a new object, leaving the temporary object in a valid but unspecified state. It is more efficient than a copy constructor, which creates a new copy of the resources.
// ex: class MyClass {
//      MyClass(MyClass&& other) noexcept {
//          data = other.data;
//          other.data = nullptr;
//      }
// };