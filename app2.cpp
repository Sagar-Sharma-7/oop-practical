#include <iostream>
#include <string>
#include <iomanip> // For setw and left
using namespace std;

// ANSI escape codes for terminal colors
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"

// Forward declaration of StudData class
class StudData;

// Student class declaration
class Student {
    string name;
    int roll_no;
    string cls;
    string division;
    string dob;
    string bloodgroup;
    static int count;

public:
    // Default Constructor
    Student() : name(""), roll_no(0), cls(""), division(""), dob("dd/mm/yyyy"), bloodgroup("") {}

    // Destructor
    ~Student() {}

    // Static member function to get count of students
    static int getCount() {
        return count;
    }

    // Member function to get data of a student
    void getData(StudData*);

    // Member function to display data of a student
    void dispData(StudData*) const;

    // Accessor methods
    string getName() const { return name; }
    int getRollNo() const { return roll_no; }
    string getClass() const { return cls; }
    string getDivision() const { return division; }
    string getDob() const { return dob; }
    string getBloodGroup() const { return bloodgroup; }
};

// Definition of static member variable count
int Student::count = 0;

// StudData class declaration
class StudData {
    string caddress;
    long telno;
    long dlno;
    friend class Student;  // Allow Student to access private members

public:
    // Constructor
    StudData() : caddress(""), telno(0), dlno(0) {}

    // Destructor
    ~StudData() {}

    // Function to get student data related to address, telephone, and driving license
    void getStudData() {
        cout << "Enter Contact Address: ";
        cin.ignore();  // Clear newline left in the buffer
        getline(cin, caddress);
        cout << "Enter Telephone Number: ";
        cin >> telno;
        cout << "Enter Driving License Number: ";
        cin >> dlno;
    }

    // Function to display student data related to address, telephone, and driving license
    void dispStudData() const {
        // This function is not used in the main function but could be implemented for completeness
    }
};

// Inline function to get student data
inline void Student::getData(StudData* st) {
    cout << "Enter Student Name: ";
    cin.ignore();  // Clear newline left in the buffer
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cin.ignore();  // Clear newline left in the buffer
    cout << "Enter Class: ";
    getline(cin, cls);
    cout << "Enter Division: ";
    getline(cin, division);
    cout << "Enter Date of Birth: ";
    getline(cin, dob);
    cout << "Enter Blood Group: ";
    getline(cin, bloodgroup);
    st->getStudData();  // Getting additional data using StudData object
    count++;  // Incrementing count of students
}

// Function to display student data
void Student::dispData(StudData* st) const {
    cout << "| " << setw(17) << left << name
         << "| " << setw(7)  << left << roll_no
         << "| " << setw(5)  << left << cls
         << "| " << setw(9)  << left << division
         << "| " << setw(10) << left << dob
         << "| " << setw(11) << left << bloodgroup
         << "| " << setw(17) << left << st->caddress
         << "| " << setw(12) << left << st->telno
         << "| " << setw(11) << left << st->dlno
         << "|" << endl;
}

// Main function
int main() {
    Student* stud1[100];  // Array of pointers to Student objects
    StudData* stud2[100]; // Array of pointers to StudData objects
    int n = 0;
    char ch;

    // Loop to add students
    do {
        stud1[n] = new Student;   // Creating new Student object
        stud2[n] = new StudData;  // Creating new StudData object
        stud1[n]->getData(stud2[n]);  // Getting data for Student object
        n++;
        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
        cin.ignore();  // Clear newline left in the buffer
    } while (ch == 'y' || ch == 'Y');

    // Print table header
    cout << GREEN << "---------------------------------------------------------------" << RESET << endl;
    cout << GREEN << "| " << CYAN << setw(17) << left << "Name" << RESET
         << "| " << CYAN << setw(7)  << left << "Roll No" << RESET
         << "| " << CYAN << setw(5)  << left << "Class" << RESET
         << "| " << CYAN << setw(9)  << left << "Division" << RESET
         << "| " << CYAN << setw(10) << left << "DOB" << RESET
         << "| " << CYAN << setw(11) << left << "Blood Group" << RESET
         << "| " << CYAN << setw(17) << left << "Address" << RESET
         << "| " << CYAN << setw(12) << left << "Tel No" << RESET
         << "| " << CYAN << setw(11) << left << "DL No" << RESET
         << "|" << endl;
    cout << GREEN << "---------------------------------------------------------------" << RESET << endl;

    // Loop to display student data in tabular form
    for (int i = 0; i < n; i++) {
        stud1[i]->dispData(stud2[i]);  // Displaying data for each Student object
    }

    // Print table footer
    cout << GREEN << "---------------------------------------------------------------" << RESET << endl;

    // Display total number of students
    cout << MAGENTA << "Total Students: " << RESET << Student::getCount() << endl;

    // Deleting allocated memory for objects
    for (int i = 0; i < n; i++) {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}
