/*
Implement a class Complex which represents the Complex Number data type. Implement the
following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers.
*/

#include <bits/stdc++.h>
using namespace std;

class Complex{
    private:
        int real;
        int imginary;
    public:
        Complex(int r = 0.0, int i = 0.0){
            real = r;
            imginary = i;
        }

        void print(){
            cout << real << " +i" << imginary << endl;
        }

        friend Complex operator+(Complex const& c1, Complex const& c2){
            return Complex(c1.real + c2.real, c1.imginary + c2.imginary);
        }

        friend Complex operator*(Complex const& c1, Complex const& c2){
            // (a+ib)(c+id) = (ac-bd) + i(ad + bc)
            // return Complex((c1.real * c2.real) - (c1.real * c2.imginary), (c1.real * c2.imginary) - (c1.imginary * c2.real));
            int realPart = c1.real * c2.real - c1.imginary * c2.imginary;
            int imgPart = c1.real * c2.imginary + c1.imginary * c2.real;
            return Complex(realPart, imgPart);
        }
};

int main(){
    Complex c1(5,6);
    Complex c2(2,5);
    Complex c3 = c1 + c2;
    Complex c4 = c1 * c2;
    c3.print();
    c4.print();
    return 0;
}