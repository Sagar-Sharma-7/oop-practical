#include <iostream>
#include <string>
using namespace std;

// Forward declaration of StudData class
class StudData;

// Student class declaration
class Student {
    string name;
    int roll_no;
    string cls;
    string division;  // Changed to std::string
    string dob;
    string bloodgroup;  // Changed to std::string
    static int count;  // Static member variable to count number of students

public:
    // Default Constructor
    Student() {
        name = "";
        roll_no = 0;
        cls = "";
        division = "";  // No dynamic allocation needed
        dob = "dd/mm/yyyy";
        bloodgroup = "";  // No dynamic allocation needed
    }

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
};

// Definition of static member variable count
int Student::count = 0;

// StudData class declaration
class StudData {
    string caddress;
    long telno;  // Changed to long
    long dlno;   // Changed to long
    friend class Student;  // Student class is a friend of StudData

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
        cout << "Contact Address: " << caddress << endl;
        cout << "Telephone Number: " << telno << endl;
        cout << "Driving License Number: " << dlno << endl;
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

// Inline function to display student data
inline void Student::dispData(StudData* st) const {
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Class: " << cls << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodgroup << endl;
    st->dispStudData();  // Displaying additional data using StudData object
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

    // Loop to display student data
    for (int i = 0; i < n; i++) {
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);  // Displaying data for each Student object
    }

    // Displaying total number of students
    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students: " << Student::getCount() << endl;
    cout << "---------------------------------------------------------------" << endl;

    // Deleting allocated memory for objects
    for (int i = 0; i < n; i++) {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}
