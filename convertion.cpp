#include <iostream>

using namespace std;

class Convert{
    protected:
        double val1;
        double val2;
    public:
        Convert(double initialValue){
            val1 = initialValue;
            val2 = 0;
        }
        double getInit(){
            return val1;
        }
        double getConv(){
            return val2;
        }

        virtual void compute() = 0;

        virtual ~Convert() {}
};

class KmhToMs: public Convert{
    public:
        KmhToMs(double kmph): Convert(kmph){}

        void compute() override{
            val2 = val1 * (1000.0/3600.0);
        }
};

class InchesToCm : public Convert{
    public:
        InchesToCm(double inches) : Convert(inches) {}

        void compute() override{
            val2 = val1 * 2.54;
        }
};

int main(){
    int value;
    cout << "\nEnter speed in Km/hr: ";
    cin >> value;
    KmhToMs kmphToMs(value);
    kmphToMs.compute();
    cout << "Speed in m/s: " << kmphToMs.getConv() << endl;

    // Inches to Centimeters Conversion
    cout << "\nEnter length in Inches: ";
    cin >> value;
    InchesToCm inToCm(value);
    inToCm.compute();
    cout << "Length in Centimeters: " << inToCm.getConv() << endl;

    return 0;
}