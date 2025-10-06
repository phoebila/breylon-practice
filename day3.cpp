// Theory
// 1. Default constructor is a constructor which can be called with no arguments. EX: ClassName obj; or ClassName obj();
// 2. Parameterized constructor is a constructor which can be called with arguments. EX: ClassName obj(arg1, arg2);
// 3. Copy constructor is a constructor which creates a new object as a copy of an existing object. EX: ClassName obj2 = obj1; or ClassName obj2(obj1);
// 4. A destructor is a special member function that is executed when an object of its class goes out of scope or is explicitly deleted. It has the same name as the class, preceded by a tilde (~), and it cannot take any arguments nor return any value. EX: ~ClassName() { // cleanup code }
// 5. A copy assignment operator is a special operator that is used to copy the contents of one object to another existing object of the same class. It is defined using the operator= syntax. EX: obj2 = obj1; where both obj1 and obj2 are objects of the same class.
// 6. Rule of Three states that if a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely requires all three. This is because these three functions are responsible for managing the resources of the class, and if one of them is not properly defined, it can lead to resource leaks or undefined behavior.
//7. Rule of Five extends the Rule of Three to include move semantics. It states that if a class requires a user-defined destructor, copy constructor, copy assignment operator, move constructor, or move assignment operator, it likely requires all five. This is because move semantics can help optimize resource management by allowing resources to be transferred from one object to another without unnecessary copying.

struct Vector {
  // Manage dynamic array to illustrate Rule of Three/Five
  int *arr;
  int size;
  int x;
  int y;

  // Parameterized constructor for dynamic array
  Vector(int s) : size(s) {
      arr = new int[size];
  }

  // Copy constructor for dynamic array
  Vector(const Vector &v) : x(v.x), y(v.y), size(v.size) {
      arr = new int[size];
      for (int i = 0; i < size; ++i) {
          arr[i] = v.arr[i];
      }
  }

  // Destructor
  ~Vector() {
      delete[] arr;
  }

};
