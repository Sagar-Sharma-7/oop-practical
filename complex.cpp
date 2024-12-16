#include <iostream>
using namespace std;

class complex{
    int real;
    int img;

    public:
        complex(){
            real = 0;
            img = 0;
        }

        complex(int real, int img){
            this -> real = real;
            this -> img = img;
        }

        complex operator + (const complex &other){
            complex result;
            result.real = real + other.real;
            result.img = img + other.img;
            return result;
        }

        complex operator * (const complex &other){
            complex result;
            result.real = real * other.real - img * other.img;
            result.img = real * other.img - img * other.real;
            return result;
        }

        friend istream& operator >> (istream& in, complex& c){
            cout << "Enter real part: ";
            in >> c.real;
            cout << "Enter img part: ";
            in >> c.img;
            return in;
        }

        friend ostream& operator << (ostream& out, const complex& c){
            out << c.real << " + i" << c.img << endl;
            return out;
        }
};

int main(){
    complex C1, C2, C3, C4;
    int flag = 1;
    char b;

    while(flag == 1){
        cout << "Enter Real and Imaginary part of the Complex Number 1:\n";
        cin >> C1;

        cout << "Enter Real and Imaginary part of the Complex Number 2:\n";
        cin >> C2;

        int operation;

        cout << "complex number 1: " << C1 << endl;
        cout << "complex number 2: " << C2 << endl;

        cout << "********** MENU **********" << endl;
        cout << "1. Addition of Complex Numbers" << endl;
        cout << "2. Multiplication of Complex Numbers" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice from the MENU (1 to 3): ";
        cin >> operation;

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
            flag = 0;
        } else {
            // Invalid choice
            cout << "Invalid choice! Please enter again.\n";
        }

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