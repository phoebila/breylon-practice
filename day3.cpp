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
