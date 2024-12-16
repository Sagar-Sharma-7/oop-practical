#include <iostream>
#include <string>
using namespace std;

class Publication{
    protected:
        string title;
        float price;
    public:

        void add(){
            cout << "\nEnter the publication info: " << endl;
            cout << "Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Price: ";
            cin >> price;
        }

        virtual void display() const{
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
        }
};


class Book : public Publication{
    private:
        int pageCount;
    public:
        void addBook(){
            try{
                add();
                cout << "Page count: ";
                cin >> pageCount;
                if(pageCount < 0){
                    throw pageCount;
                }
            }catch(...){
                cout << "\nInvalid page count! setting to 0.";
                pageCount = 0;
            }
        }

        void display() const override{
            Publication::display();
            cout << "Page Count: " << pageCount;
        }
};

class Tape: public Publication{
    private:
        float playtime;
    public:
        void addTape(){
            try{
                add();
                cout <<"Play Time: ";
                cin >> playtime;
                if(playtime < 0){
                    throw playtime;
                }
            }catch(...){
                cout << "\nInvalid Play Time! Setting to 0.";
                playtime = 0;
            }
        }

        void display() const override{
            Publication::display();
            cout << "Play Time: " << playtime << " min";
        }
};

int main(){
    const int Max_size = 10;
    Book books[Max_size];
    Tape tapes[Max_size];
    int bookcount = 0;
    int tapecount = 0;
    int choice;

    do{
        // Display menu
        cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
        cout << "\n1. Add Book";
        cout << "\n2. Add Tape";
        cout << "\n3. Display Books";
        cout << "\n4. Display Tapes";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: {
                if(bookcount < Max_size){
                    books[bookcount].addBook();
                    bookcount++;
                }else{
                    cout << "\nBook List is full!";
                }
                break;
            }
            case 2: {
                 if (tapecount < Max_size) {
                    tapes[tapecount].addTape(); // Add tape details
                    tapecount++; // Increment tape count
                } else {
                    cout << "\nTape list is full!";
                }
                break;
            }
            case 3: {
                cout << "\n* * * * * BOOK INFORMATION * * * * *\n";
                for (int i = 0; i < bookcount; ++i) {
                    books[i].display(); // Display all books
                    cout << "\n-------------------------";
                }
                break;
            }
            case 4: {
                cout << "\n* * * * * TAPE INFORMATION * * * * *\n";
                for (int i = 0; i < tapecount; ++i) {
                    tapes[i].display(); // Display all tapes
                    cout << "\n-------------------------";
                }
                break;
            }
            case 5: {
                cout << "Exiting program.";
                break;
            }
            default : {
                cout << "Invalid choice. Please try again.";
            }
        }
    }while(choice != 5);
    return 0;
}

