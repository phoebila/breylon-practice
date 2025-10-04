#include <iostream>
using namespace std;

// 4 pillars of OOP: Encapsulation, Abstraction, Inheritance, Polymorphism
// 1. Encapsulation: Bundling data and methods that operate on that data within a single unit or class, restricting direct access to some of the object's components.
// 2. Abstraction: Hiding complex implementation details and showing only the essential features of an object, making it easier to interact with.
// 3. Inheritance: Mechanism by which one class can inherit properties and behaviors (methods) from another class, promoting code reusability.
// 4. Polymorphism: Ability of different classes to be treated as instances of thesame class through a common interface, typically achieved through method overriding and interfaces.

//1a. Classes are blueprints for creating objects, defining their properties and behaviors, while objects are instances of classes that hold specific data and can perform actions defined by the class.
//1b. Private/public/protected are access specifiers in C++ that control the visibility and accessibility of class members. Private members are accessible only within the class itself, public members can be accessed from outside the class, and protected members can be accessed within the class and by derived classes.
//1c. Getters/Setters are methods used to access and modify private class members. Getters retrieve the value of a private member, while setters allow you to set or update the value of a private member, providing controlled access to the class's internal data.

//2a. Abstract classes are classes that cannot be instantiated on their own and are designed to be inherited by other classes. They often contain pure virtual functions that must be implemented by derived classes.
//2b. Pure virtual functions are virtual functions that have no implementation in the base class and are declared by assigning 0 in their declaration. They enforce that derived classes must provide an implementation for these functions, making the base class abstract.
//2c. Interfaces in C++ are typically implemented using abstract classes with only pure virtual functions. They define a contract that derived classes must adhere to, specifying methods that must be implemented without providing any implementation details.

//3a. Base/Derived classes: A base class is a general class that provides common attributes and methods, while a derived class inherits from the base class and can add or override functionality to create a more specialized version of the base class.
//3b. Virtual functions are member functions in a base class that can be overridden in derived classes. They enable polymorphism by allowing the program to determine at runtime which function to call based on the object's actual type, rather than the type of the pointer or reference.

//4a. Function overloading is the ability to define multiple functions with the same name but different parameter lists within the same scope, allowing for different implementations based on the arguments passed.
//4b. Overriding is a feature that allows a derived class to provide a specific implementation of a method that is already defined in its base class, enabling polymorphism and dynamic method resolution at runtime.
//4c. Dynamic binding (or late binding) is the process of resolving method calls at runtime rather than compile-time, typically achieved through virtual functions, allowing for more flexible and dynamic behavior in object-oriented programming.

// The difference between overloading and overriding is that overloading allows multiple functions with the same name but different parameters within the same scope, while overriding allows a derived class to provide a specific implementation of a method already defined in its base class, enabling polymorphism.
// Constructors and Destructors are special member functions in a class. A constructor is called when an object of the class is created and is used to initialize the object's attributes. A destructor is called when an object goes out of scope or is deleted and is used to clean up resources that the object may have acquired during its lifetime.

struct Shape {
    virtual void draw() = 0; //pure virtual function
    virtual double area() const = 0; //pure virtual function
    virtual ~Shape() {} //virtual destructor, needed only for base classes with virtual functions
};

struct Circle : public Shape {
    private: double radius;
    public: Circle(double r) : radius(r) {}
    double area() override {
        return 3.14159 * radius * radius;
    }
    void draw() override {
        cout << "Drawing Circle with radius: " << radius << endl;
    }
};

struct Rectangle : public Shape {
    private: double width, height;
    public: Rectangle(double w, double h) : width(w), height(h) {}
    double area() override {
        return width * height;
    }
    void draw() override {
        cout << "Drawing Rectangle with width: " << width << " and height: " << height << endl;
    }
};

