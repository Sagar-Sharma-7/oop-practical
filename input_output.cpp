#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee{
    string name;
    int id;
    float salary;

    public:
        void add(){
            cout << "\nname: ";
            cin.ignore();
            getline(cin, name);
            cout << "\nid: ";
            cin >> id;
            cout << "\nsalary: ";
            cin >> salary;
        }

        void display() const{
            cout << "\nName: " << name;
            cout << "\nID: " << id;
            cout << "\nSalary: " << salary << endl;
        }

        void writeToFile(fstream &f){
            f.write((char*)this, sizeof(Employee));
        }

        void readFromFile(fstream &f){
            f.read((char*)this, sizeof(Employee));
        }
};

int main(){
    Employee emp[5];
    fstream file;
    int n;

    file.open("employees.dat", ios::out | ios::binary);
    if(!file){
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "\nNEnter the number of employees you want to store: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "\nEnter information for employee " << i + 1 << "\n";
        emp[i].add();
        emp[i].writeToFile(file);
    }

    file.close();

    file.open("employees.dat", ios::in | ios::binary);
    if(!file){
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    cout << "\nInformation of Employees is as follows:\n";
    for (int i = 0; i < n; i++){
        cout << "\nEmployee " << i + 1 << endl;
        emp[i].readFromFile(file);
        emp[i].display();
    }

    file.close();

    return 0;
}