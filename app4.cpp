/*
Write a C++ program that creates an output file, writes information to it,
closes the file, opens it again as an input file, and reads the information from the file.
*/

#include<iostream>
#include<fstream>
using namespace std;

class Employee {  // Declaring class Employee
    string Name;
    int ID;
    double salary;

public:
    // Function to accept employee details
    void accept() {
        cout << "\nName: ";
        cin.ignore();  // To ignore leftover newline character
        getline(cin, Name);
        cout << "ID: ";
        cin >> ID;
        cout << "Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void display() const {
        cout << "\nName: " << Name;
        cout << "\nID: " << ID;
        cout << "\nSalary: " << salary << endl;
    }

    // Function to write the object to a file
    void writeToFile(fstream &f) {
        f << Name << "\n" << ID << "\n" << salary << "\n";
    }

    // Function to read the object from a file
    void readFromFile(fstream &f) {
        f.ignore();  // To ignore leftover newline character
        getline(f, Name);
        f >> ID;
        f >> salary;
    }
};

int main() {
    Employee employees[5];  // Array to hold up to 5 employees
    fstream file;
    int n;

    // Opening file in output mode to write employee data
    file.open("employees.txt", ios::out);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    cout << "\nEnter the number of employees you want to store (up to 5): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter information of Employee " << i + 1 << "\n";
        employees[i].accept();
        employees[i].writeToFile(file);  // Writing each employee's data to file
    }

    file.close();  // Closing the file after writing

    // Opening the file in input mode to read employee data
    file.open("employees.txt", ios::in);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nInformation of Employees is as follows:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << "\n";
        employees[i].readFromFile(file);  // Reading each employee's data from file
        employees[i].display();  // Displaying employee data
    }

    file.close();  // Closing the file after reading

    return 0;
}
