#include <iostream>
#include <string>

using namespace std;

class Student{
    private:
        string name;
        int rollNumber;
        string studentClass;
        char division;
        string dob;
        string bloodGroup;
        string contactAddress;
        long long phoneNumber;
        string license;

        static int studentCount;

    public:
        // Default Constructor
         Student() {
            name = "Unknown";
            rollNumber = 0;
            studentClass = "Unknown";
            division = 'A';
            dob = "01/01/2000";
            bloodGroup = "Unknown";
            contactAddress = "Unknown";
            phoneNumber = 0;
            license = "Unknown";
            studentCount++;
        }

        ~Student(){
            studentCount--;
        }

        void input(){
            cout << "\nEnter Student Details:" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Roll Number: ";
            cin >> rollNumber;
            cout << "Class: ";
            cin >> studentClass;
            cout << "Division: ";
            cin >> division;
            cout << "Date of Birth (DD/MM/YYYY): ";
            cin >> dob;
            cout << "Blood Group: ";
            cin >> bloodGroup;
            cout << "Contact Address: ";
            cin.ignore();
            getline(cin, contactAddress);
            cout << "Telephone Number: ";
            cin >> phoneNumber;
            cout << "Driving License Number: ";
            cin >> license; 
        }

        void display() const{
            cout << "\nName: " << name;
            cout << "\nRoll Number: " << rollNumber;
            cout << "\nClass: " << studentClass;
            cout << "\nDivision: " << division;
            cout << "\nDate of Birth: " << dob;
            cout << "\nBlood Group: " << bloodGroup;
            cout << "\nContact Address: " << contactAddress;
            cout << "\nTelephone Number: " << phoneNumber;
            cout << "\nDriving License Number: " << license << endl;  
        }

        static int getStudentCount(){
            return studentCount;
        }

        friend class Admin;
};

int Student::studentCount = 0;

class Admin{
    public:
        void printStudentDetails(const Student &student){
            cout << "\n[Admin Access] Student Details:";
            student.display();
        }
};

int main(){
    const int Max_students = 5;
    Student students[Max_students];
    int studentCount = 0;
    int choice;

    do{
        cout << "\n* * * STUDENT DATABASE SYSTEM * * *";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Display Total Students";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: {
                if(studentCount < Max_students){
                    students[studentCount].input();
                    studentCount++;
                }else{
                    cout << "\nStudent Database is full!";
                }
                break;
            }
            case 2: {
                if (studentCount == 0) {
                    cout << "\nNo students to display.";
                } else {
                    for (int i = 0; i < studentCount; ++i) {
                        cout << "\nStudent " << (i + 1) << ":";
                        students[i].display();
                    }
                }
                break;
            }
            case 3:{
                cout << "\nTotal Students: " << Student::getStudentCount() << endl;
                break;
            }
            case 4: {
                break;
            }
            default:{
                cout << "\nInvalid Choice.";
            }

        }

    }while(choice != 4);

    return 0;
}
