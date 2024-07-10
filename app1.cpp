/*
Implement a class Complex which represents the Complex Number data type. Implement the
following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers.
*/
#include <iostream>
using namespace std;

// Class definition for Complex numbers
class Complex {
    double real; // Real part of the complex number
    double img;  // Imaginary part of the complex number

public:
    // Constructors
    Complex(); // Default constructor
    Complex(double r, double i); // Parameterized constructor

    // Operator overloading for addition and multiplication
    Complex operator + (const Complex&); // Addition operator overload
    Complex operator * (const Complex&); // Multiplication operator overload

    // Friend functions for input and output
    friend istream& operator >> (istream&, Complex&);
    friend ostream& operator << (ostream&, const Complex&);
};

// Default constructor initializes complex number to 0 + 0i
Complex::Complex() {
    real = 0;
    img = 0;
}

// Parameterized constructor initializes complex number to specified real and imaginary parts
Complex::Complex(double r, double i) {
    real = r;
    img = i;
}

// Overloading >> operator for reading Complex numbers from input
istream& operator >> (istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.img;
    return in;
}

// Overloading << operator for printing Complex numbers to output
ostream& operator << (ostream& out, const Complex& c) {
    out << c.real << " + i" << c.img << "\n";
    return out;
}

// Overloading + operator for adding two Complex numbers
Complex Complex::operator + (const Complex& c) {
    Complex temp;
    temp.real = real + c.real; // Adding real parts
    temp.img = img + c.img;    // Adding imaginary parts
    return temp;               // Returning the result as a new Complex object
}

// Overloading * operator for multiplying two Complex numbers
Complex Complex::operator * (const Complex& c) {
    Complex tmp;
    tmp.real = real * c.real - img * c.img; // Multiplying using complex number multiplication formula
    tmp.img = real * c.img + img * c.real;
    return tmp; // Returning the result as a new Complex object
}

// Main function
int main() {
    Complex C1, C2, C3, C4; // Declaring four Complex objects to store complex numbers
    int flag = 1; // Flag to control program execution
    char b;

    // Outer loop to continue running the program until flag is set to 0
    while (flag == 1) {
        // Prompting user to enter real and imaginary parts for Complex Number 1
        cout << "Enter Real and Imaginary part of the Complex Number 1:\n";
        cin >> C1;

        // Prompting user to enter real and imaginary parts for Complex Number 2
        cout << "Enter Real and Imaginary part of the Complex Number 2:\n";
        cin >> C2;

        int operation; // Variable to store user's operation choice

        // Displaying Complex numbers entered by user
        cout << "Complex Number 1: " << C1 << endl;
        cout << "Complex Number 2: " << C2 << endl;

        // Displaying menu options
        cout << "********** MENU **********" << endl;
        cout << "1. Addition of Complex Numbers" << endl;
        cout << "2. Multiplication of Complex Numbers" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice from the MENU (1 to 3): ";
        cin >> operation;

        // Performing operation based on user's choice
        if (operation == 1) {
            // Addition operation
            C3 = C1 + C2;
            cout << "Addition Result: " << C3 << endl;
        } else if (operation == 2) {
            // Multiplication operation
            C4 = C1 * C2;
            cout << "Multiplication Result: " << C4 << endl;
        } else if (operation == 3) {
            // Exiting the program
            cout << "Exiting program. Thank you!\n";
            flag = 0; // Setting flag to 0 to exit outer loop
        } else {
            // Invalid choice
            cout << "Invalid choice! Please enter again.\n";
        }

        // Asking user if they want to perform another operation
        if (flag != 0) {
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> b;
            if (b != 'y' && b != 'Y') {
                flag = 0; // Setting flag to 0 to exit outer loop
            }
        }
    }

    return 0;
}
