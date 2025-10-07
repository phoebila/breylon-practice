#include <iostream>

// Theory
//1. Inheritance basics:
//    - Inheritance allows a class (derived class) to inherit properties and behaviors (data members and member functions) from another class (base class).
// Syntax:
class Animal {
  public:
  void eat() {
        std::cout << "Animal eats" << std::endl;
    }
};

class Dog: public Animal { // Dog inherits from Animal
  public:
    void bark() {
        std::cout << "Dog barks" << std::endl;
    }
};

// Dog will have eat() and bark() methods

//2. Function Overriding:
//    - Function overriding allows a derived class to provide a specific implementation of a function that is already defined in its base class.
//    - marking the base class function as virtual allows dynamic binding.

class Animal {
  public:
    virtual void speak() { // virtual function
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog: public Animal {
  public:
    void speak() override { // overriding the base class function
        std::cout << "Dog barks" << std::endl;
    }
};

// 3. Virtual Functions and vtables:
//    - Virtual functions enable dynamic (runtime) polymorphism.
//    - When a class has virtual functions, the compiler creates a vtable (virtual table) for that class.
//    - The vtable is essentially a lookup table of function pointers.
Animal* a = new Dog();
a->speak(); // Calls Dog's speak() due to dynamic binding

//4. Pure virtual functions and Abstract Classes:
//    - A pure virtual function is a virtual function that is declared by assigning 0 in its declaration.
//    - A class containing at least one pure virtual function is called an abstract class and cannot be instantiated.
class Animal {
  public:
    virtual void speak() = 0; // pure virtual function
};
// Can't instantiate an abstract class directly.

//5. Multiple Inheritance + Diamond Problem:
//    - C++ supports multiple inheritance, where a class can inherit from more than one base class.
//    - The diamond problem occurs when two base classes inherit from the same superclass, and a derived class inherits from both base classes.
//    - This can lead to ambiguity about which base class's properties or methods the derived class should inherit.
class A { public: int x; };
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { }; // Diamond problem

// Practice:
class Animal {
  public:
    virtual void speak() {
        std::cout << "Animal makes a sound" << std::endl;
    }
    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

class Dog: public Animal {
  public:
    void speak() override {
        std::cout << "Dog barks" << std::endl;
    }
};

class Cat: public Animal {
  public:
    void speak() override {
        std::cout << "Cat meows" << std::endl;
    }
};

int main() {
    Animal* a1 = new Dog(); //polymorphic behavior with base class pointer
    Animal* a2 = new Cat();

    a1->speak(); // Outputs: Dog barks
    a2->speak(); // Outputs: Cat meows

    delete a1; // Clean up
    delete a2; // Clean up

    return 0;
}

// Shape polymorphism example:
class Shape {
  public:
    virtual double area() = 0; // abstract
    virtual ~Shape() {}
};

class Circle: public Shape {
  double r;
  public:
    Circle(double radius) : r(radius) {}
    double area() override {
        return 3.14159 * r * r;
    }
};

class Rectangle: public Shape {
  double w, h;
  public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double area() override {
        return w * h;
    }
};

int main() {
    Shape* s1 = new Circle(5.0);
    Shape* s2 = new Rectangle(4.0, 6.0);

    std::cout << "Circle area: " << s1->area() << std::endl; // Outputs area of circle
    std::cout << "Rectangle area: " << s2->area() << std::endl; // Outputs area of rectangle

    delete s1; // Clean up
    delete s2; // Clean up

    return 0;
}

//Quiz:
//1. The difference between compile time and runtime polymorphism?
// Compile time polymorphism is achieved through function overloading and operator overloading, where the method to be invoked is determined at compile time. Runtime polymorphism is achieved through inheritance and virtual functions, where the method to be invoked is determined at runtime based on the object type.
//2. What happens if a derived class does not override a base class's virtual function?
// If a derived class does not override a base class's virtual function, the base class's version of the function will be called when invoked through a base class pointer or reference.
//3. Consider this code: 
class Base {
public:
    virtual void show() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    void show() { cout << "Derived\n"; }
};

int main() {
    Base b;
    Derived d;
    Base* ptr = &d;
    ptr->show();
}
// the output will be "Derived" because the show() function is virtual, and the call is resolved at runtime to the derived class's implementation.

//4. What happens if you remove the virtual keyword from the base class function?
// If the virtual keyword is removed, the function will not support runtime polymorphism. The function call will be resolved at compile time based on the type of the pointer/reference, not the actual object type, leading to potentially unexpected behavior.

//5. Explain what a pure virtual function is and when would you use one?
// A pure virtual function is a virtual function that is declared by assigning 0 in its declaration. It makes the class abstract, meaning it cannot be instantiated directly. Pure virtual functions are used when you want to define an interface that derived classes must implement.

//6. What does the following code print?
class A {
public:
    A() { cout << "A "; }
    virtual ~A() { cout << "~A "; }
};

class B : public A {
public:
    B() { cout << "B "; }
    ~B() { cout << "~B "; }
};

int main() {
    A* obj = new B();
    delete obj;
}
// The output will be "A B ~B ~A " because the constructor of A is called first, then B's constructor. Upon deletion, B's destructor is called first (due to virtual destructor), followed by A's destructor.

//7. Why should destructors be declared as virtual when using inheritance?
// Destructors should be declared as virtual in base classes to ensure that the derived class's destructor is called when an object is deleted through a base class pointer. This prevents resource leaks and undefined behavior by ensuring proper cleanup of derived class resources.

//8. What is the diamond problem in C++ and how can it be resolved?
// The diamond problem occurs in multiple inheritance when two base classes inherit from the same superclass, and a derived class inherits from both base classes. This can lead to ambiguity about which base class's properties or methods the derived class should inherit. It can be resolved using virtual inheritance, which ensures that only one instance of the common base class is shared among the derived classes.
// Virtual inheritance solves the diamond problem by ensuring that only one instance of the common base class is created, even when multiple derived classes inherit from it. This is done by declaring the inheritance as virtual in the derived classes.

//9. T/F: you can instantiate a class that contains at least one pure virtual function.
// False. A class with at least one pure virtual function is considered an abstract class and cannot be instantiated directly.

//10. Write pseudocode for an abstract class "Shape" with a pure virtual function "area" and two derived classes "Circle" and "Square" that implement the "area" function.

class Shape {
  public:
    virtual double area() = 0; // pure virtual function
    virtual ~Shape() {}
};

class Circle : public Shape {
  public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14 * radius * radius; }
  private:
    double radius;
};

class Square : public Shape {
  public:
    Square(double s) : side(s) {}
    double area() override { return side * side; }
  private:
    double side;
};