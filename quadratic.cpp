#include <iostream>
#include <cmath>

using namespace std;

class Quadratic{
    private:
        double a, b, c;
    public:
        Quadratic(){
            a = 0;
            b = 0;
            c = 0;
        }

        Quadratic(double a, double b, double c){
            this-> a = a;
            this-> b = b;
            this->c = c;
        }

        Quadratic operator +(const Quadratic& q) const{
            return Quadratic(a + q.a, b + q.b, c + q.c);
        }

        friend istream& operator >> (istream& in, Quadratic& q){
            cout << "Enter coefficients (a, b, c): ";
            in >> q.a >> q.b >> q.c;
            return in;
        }  

        friend ostream& operator <<(ostream& out, const Quadratic& q){
            out << q.a << "x^2 + " << q.b << "x + " << q.c;
            return out;
        }

        double eval(double x){
            return (a * x * x) + (b * x) + c;
        }

        void solve(){
            if(a == 0){
                if(b==0){
                    if(c==0){
                         cout << "The equation has infinitely many solutions." << endl;
                    } else {
                    cout << "No solution exists." << endl;
                    }
                }else{
                    cout << "The solution is: " << -c / b << endl;
                }
            }else{
                double discriminant = b*b - 4*a*c;
                if(discriminant > 0){
                    double root1 = (-b + sqrt(discriminant)) / (2*a);
                    double root2 = (-b - sqrt(discriminant)) / (2*a);
                    cout << "The solutions are: " << root1 << " and " << root2 << endl;
                }else if(discriminant == 0){
                    double root = -b/(2*a);
                    cout << "The solution is: " << root << endl;
                }else{
                    cout << "No real solutions exist." << endl;
                }
            }
        }
};

int main(){
    Quadratic q1, q2;

    cout << "Enter the first polynomial:\n";
    cin >> q1;

    cout << "Enter the second polynomial:\n";
    cin >> q2;

    Quadratic sum = q1 + q2;
    cout << "\nFirst Polynomial: " << q1 << endl;
    cout << "Second Polynomial: " << q2 << endl;
    cout << "Sum of Polynomials: " << sum << endl;

    double x;
    cout << "\nEnter a value for x to evaluate the first polynomial: ";
    cin >> x;
    cout << "Value of the first polynomial at x = " << x << ": " << q1.eval(x) << endl;
    cout << "Value of the first polynomial at x = " << x << ": " << q2.eval(x) << endl;
    
     cout << "\nSolutions for the first polynomial equation:\n";
    q1.solve();

    return 0;

}