#include <iostream>
using namespace std;

class Person {
public:
    int* agePtr;  // Pointer to dynamically allocated age

    // Constructor
    Person(int age) {
        agePtr = new int(age); 
    }

    // Copy constructor (prevents shallow copy problem)
    Person(const Person& p) {
        agePtr = new int(*p.agePtr); 
    }

    // Overloaded assignment operator
    Person& operator=(const Person& p) {
        if (this == &p) return *this;  // Avoid self-assignment

        delete agePtr;  // Free existing memory
        agePtr = new int(*p.agePtr);  

        return *this;  
    }

    // Destructor
    ~Person() {
        delete agePtr; 
    }
};

int main() {
    Person p1(18);
    Person p2(20);

    // Assignment operation (calls overloaded operator=)
    p2 = p1;

    cout << "The age of P1 is: " << *p1.agePtr << endl;
    cout << "The age of P2 is: " << *p2.agePtr << endl;

    // Test copy constructor (calls deep copy constructor)
    Person p3 = p1;

    cout << "The age of P3 is: " << *p3.agePtr << endl;

    return 0;
}

