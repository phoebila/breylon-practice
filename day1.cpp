#include <iostream>
using namespace std;


void swapReferences(int &a, int &b) { //swaps by pass by reference
    // uses references, without needing to make a copy
    int temp = a;
    a = b;
    b = temp;
}

void swapPointer(int *x, int *y) { //swaps by pass by pointer
    // uses pointers, manipulating the original variables, just requires syntax of dereferencing
    int temp = *x;
    *x = *y;
    *y = temp;
}

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int findMaxInArray(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

struct Point {
    int x;
    int y;
};

int distance(Point a, Point b){
    return ( (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) );
}

// EOD Quiz 1
// 1. pointer is a variable that stores the memory address of another variable
// 1. reference is an alias for another variable.
// 1. pointer can be reassigned to point to different variables, reference cannot be changed after initialization

//2. delete[] is used
// 3. The declaration of: 
    //    const int* p;
    //    int* const q = &x;
    //    const int* const r = &y;
    // p is a pointer, q is a const pointer to x and cannot change the address it holds but can change the value, r is a const pointer to const int y and cannot change either the address or the value it points to.

// 4. The difference between passing by reference and passing by pointer is that passing by reference uses references (aliases) to manipulate the original variables directly, while passing by pointer uses memory addresses and requires dereferencing to access or modify the values. Passing by reference is often more convenient and safer, as it avoids issues with null pointers and pointer arithmetic.
// 5. The difference between stack memory and heap memory is that stack memory is used for static memory allocation, where variables are automatically managed and deallocated when they go out of scope, while heap memory is used for dynamic memory allocation, where memory is manually allocated and deallocated using new and delete. Stack memory is generally faster and has a limited size, while heap memory can be larger but may lead to fragmentation and requires careful management to avoid memory leaks.

// 6. This program will output: 
    // int main() {
    //     int x = 5;
    //     int& ref = x;
    //     int* ptr = &x;

    //     *ptr = 10; x becomes 10
    //     ref = 20; x becomes 20

    //     cout << x << " " << ref << " " << *ptr << endl;
    //     return 0;
    // }
    // Output: 20 20 20

//  7. Dynamic array allocation:
    // void allocate5Array(int arr[]) {
    //     arr = new int[5]; //allocates memory for an array of integers
    //     for (int i = 0; i < 5; i++) {
    //         arr[i] = i + 1; //initializes the array with values 1 to 5
    //     }
    //     // prints numbers in array
    //     for (int i = 0; i < 5; i++) {
    //         cout << arr[i] << " ";
    //     }
    //     delete[] arr; //frees the allocated memory
    // }

// 8. double distance for Point struct:
    // int doubleDistance(Point a, Point b) {
    //     int dx = b.x - a.x;
    //     int dy = b.y - a.y;
    //     return sqrt(dx * dx + dy * dy);
    // }

int main() {
    int x = 5;
    int y = 10;

    int* pointer = &x; //pointer to x
    int& reference = x; //reference to x

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swapReferences(x, y);
    cout << "After swapReferences: x = " << x << ", y = " << y << endl;

    swapPointer(&x, &y);
    cout << "After swapPointer: x = " << x << ", y = " << y << endl;

    swapXY(&x, &y);
    cout << "After swapXY: x = " << x << ", y = " << y << endl;

    // dynamic memory allocation
    int* p = new int;
    int* myArray = new int[10]; //allocates memory for an array of 10 integers

    // deletes the memory allocated for the integer
    delete p;
    // deletes the memory allocated for the array
    delete[] myArray;

    // const pointer and pointer to const
    const int a = 5; //cannot change value of a
    const int* ptrToConst = &a; // pointer to const, (value cant change through ptrToConst)
    int b = 10;
    int* const constPtr = &b; // const pointer, cannot change the address, but value can change
    const int* const r = &a; //both fixed

    return 0;

}