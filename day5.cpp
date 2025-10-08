//Theory

//1. Virtual destructors:
//    - When a base class has virtual functions, it should also have a virtual destructor.
//    - This ensures that the destructor of the derived class is called when an object is deleted through a base class pointer.
//    - Prevents resource leaks and undefined behavior.

//2. Operator overloading (+, <<, >>, etc.):
//    - Allows you to define custom behavior for operators when applied to user-defined types (classes).
//    - Syntax: Define a member function or a friend function with the operator keyword followed by the operator symbol.

//3. Friend Functions:
//    - A friend function is a function that is not a member of a class but has access to its private and protected members.
//    - Declared using the friend keyword inside the class definition.  

//4. Static members:
//    - Static members (data members and member functions) belong to the class rather than any specific object.
//    - Shared among all instances of the class.
//    - Syntax: Use the static keyword in the class definition. Static members must be defined outside the class. ex: int ClassName::staticMember = initialValue;
//    - Can be accessed using the class name or through an object of the class.

#include <iostream>
using namespace std;

class Complex {
  private:
      float real;
      float imag;
      static int objectCount; // Static member to count objects
  public:
      Complex(float r = 0, float i = 0) : real(r), imag(i) {
          objectCount++;
      }

      // Static member function to get the object count
      static int getObjectCount() {
          return objectCount;
      }

      //overload operator +
      Complex operator + (const Complex& obj) {
          return Complex(real + obj.real, imag + obj.imag);
      }
};

class Library {
  private:
      string name;
      string address;
  public:
      Library(string n, string a) : name(n), address(a) {}

      void display() {
          cout << "Library Name: " << name << ", Address: " << address << endl;
      }
};

// Library system:
class Book {
  private:
      string title;
      string author;
      int id;
      static int bookCount; // Static member to count books
  public:
      Book(string t, string a) : title(t), author(a) {
          id = ++bookCount; // Increment book count and assign ID
      }

      void display() {
          cout << "Book ID: " << id << ", Title: " << title << ", Author: " << author << endl;
      }

      // Static member function to get the book count
      static int getBookCount() {
          return bookCount;
      }
};

class Magazine : public Book {
  private:
      int issueNumber;
  public:
      friend class Library; // If Library needs access to private members
      Magazine(string t, string a, int issue) : Book(t, a), issueNumber(issue) {}

      void display() {
          Book::display();
          cout << "Issue Number: " << issueNumber << endl;
      }
};

// Definition of static member
int Complex::objectCount = 0;
int Book::bookCount = 0;

// Quiz;

//1. What is a template and why is it used?
// A template is a feature in C++ that allows you to write generic and reusable code. It enables functions and classes to operate with any data type without being rewritten for each type. Templates are used to create functions or classes that can work with different data types while maintaining type safety.

// 2. Differentiate between class templates and function templates.
// Class templates define a blueprint for creating classes that can operate with any data type. Function templates define a blueprint for creating functions that can operate with any data type. Class templates are used to create objects, while function templates are used to create functions.

//3. What does this code output?
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(3, 4) << " ";
    cout << add(2.5, 1.5);
}
// The output will be "7 4" because the add function is called with integer arguments (3 and 4) and floating-point arguments (2.5 and 1.5).

//4. What is operator overloading and why is it used?
// Operator overloading is a feature in C++ that allows you to define custom behavior for operators when applied to user-defined types (classes). It is used to make objects of user-defined types behave like built-in types, allowing for more intuitive and readable code.

//5. Which operators cannot be overloaded in C++?
// The following operators cannot be overloaded in C++:
// 1. Scope resolution operator (::)
// 2. Member access operator (.)
// 3. Member pointer access operator (.*)
// 4. Ternary conditional operator (?:)
// 5. sizeof operator
// 6. Typeid operator
// 7. Cast operators (static_cast, dynamic_cast, const_cast, reinterpret_cast)

//6. Given this: 
class Point {
    int x, y;
public:
    Point(int x, int y): x(x), y(y) {}
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
};
// What does p1 + p2 do? 
// - It adds the corresponding x and y coordinates of two Point objects p1 and p2, returning a new Point object with the summed coordinates.

//7. Whats the difference between a prefix and postfix increment operator overload?
// The prefix increment operator (++obj) increments the value of the object before it is used in an expression, while the postfix increment operator (obj++) increments the value of the object after it is used in an expression. In operator overloading, the postfix version typically takes an int parameter to differentiate it from the prefix version.

//8. What is a static member variable and how is it shared among objects?
// - A static member variable is a variable that is shared among all instances of a class. It belongs to the class itself rather than any specific object. All objects of the class share the same copy of the static member variable, and it can be accessed using the class name or through an object of the class.

//9. Whats the difference between a static method and a non-static method?
// A static method belongs to the class itself and can be called without creating an instance of the class. It can only access static member variables and other static methods. A non-static method belongs to an instance of the class and can access both static and non-static member variables and methods. Non-static methods require an object of the class to be called.

//10. Write psuedocode for a generic Stack<t> class with push, pop, and top methods.
template <typename T>
class Stack {
  private:
      vector<T> elements; // Use a vector to store stack elements
  public:
      void push(const T& element) {
          elements.push_back(element); // Add element to the top of the stack
      }

      void pop() {
          if (!elements.empty()) {
              elements.pop_back(); // Remove the top element of the stack
          } else {
              throw runtime_error("Stack is empty");
          }
      }

      void top() const {
          if (!elements.empty()) {
              return elements.back(); // Return the top element of the stack
          } else {
              throw runtime_error("Stack is empty");
          }
      }
};