/*
Experiment Number 2: 
Question: 
Develop a program in C++ to create a database of student’s information system containing the following information:
- Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no.
The database should have suitable member functions and must use:
- Constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code, dynamic memory allocation operators (`new` and `delete`), and exception handling.
*/

#include <iostream>
#include <memory>  // For smart pointers
#include <string>

using namespace std;

class StudData;

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
    Student()
        : name(""), roll_no(0), cls(""), division("Unknown"), dob("dd/mm/yyyy"), bloodgroup("Unknown") {}

    // Copy Constructor
    Student(const Student& other)
        : name(other.name), roll_no(other.roll_no), cls(other.cls), division(other.division), dob(other.dob), bloodgroup(other.bloodgroup) {
        count++;
    }

    // Destructor
    ~Student() {
        // No need for explicit memory management as we're not using raw pointers here
    }

    // Static member function
    static int getCount() {
        return count;
    }

    // Member functions
    void getData(shared_ptr<StudData> st);
    void dispData(shared_ptr<StudData> st) const;
};

class StudData {
    string caddress;
    long telno;
    long dlno;

    friend class Student;  // Friend class to allow Student access private members

public:
    // Default Constructor
    StudData() : caddress(""), telno(0), dlno(0) {}

    // Destructor
    ~StudData() = default;

    // Member functions
    void getStudData() {
        cout << "Enter Contact Address: ";
        cin.ignore();  // To ignore leftover newline character
        getline(cin, caddress);
        cout << "Enter Telephone Number: ";
        cin >> telno;
        cout << "Enter Driving License Number: ";
        cin >> dlno;
    }

    void dispStudData() const {
        cout << "Contact Address: " << caddress << endl;
        cout << "Telephone Number: " << telno << endl;
        cout << "Driving License Number: " << dlno << endl;
    }
};

int Student::count = 0;

// Inline function to get student data
inline void Student::getData(shared_ptr<StudData> st) {
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cin.ignore();  // To ignore newline character
    cout << "Enter Class: ";
    getline(cin, cls);
    cout << "Enter Division: ";
    getline(cin, division);
    cout << "Enter Date of Birth (dd/mm/yyyy): ";
    getline(cin, dob);
    cout << "Enter Blood Group: ";
    getline(cin, bloodgroup);
    st->getStudData();
    count++;
}

// Inline function to display student data
inline void Student::dispData(shared_ptr<StudData> st) const {
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Class: " << cls << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodgroup << endl;
    st->dispStudData();
}

int main() {
    // Using smart pointers for automatic memory management
    vector<shared_ptr<Student>> students;
    vector<shared_ptr<StudData>> studData;
    
    char ch;
    do {
        auto student = make_shared<Student>();
        auto studdata = make_shared<StudData>();
        student->getData(studdata);
        students.push_back(student);
        studData.push_back(studdata);

        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
        cin.ignore();  // To ignore newline character

    } while (ch == 'y' || ch == 'Y');

    // Display all student data
    for (size_t i = 0; i < students.size(); i++) {
        cout << "---------------------------------------------------------------" << endl;
        students[i]->dispData(studData[i]);
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students: " << Student::getCount() << endl;
    cout << "---------------------------------------------------------------" << endl;

    return 0;
}
