#include <iostream>
#include <string> // For string class
using namespace std;

// Base class for all publications
class Publication {
private:
    string title; // Title of the publication
    float price;  // Price of the publication

public:
    // Function to add publication details
    void add() {
        cout << "\nEnter the Publication Information:" << endl;
        cout << "Title: ";
        cin.ignore(); // Ignore leftover newline character
        getline(cin, title); // Read full line including spaces
        cout << "Price: ";
        cin >> price; // Read price
    }

    // Function to display publication details
    void display() const {
        cout << "\nTitle: " << title;
        cout << "\nPrice: $" << price;
    }
};

// Derived class for books
class Book : public Publication {
private:
    int pageCount; // Number of pages in the book

public:
    // Function to add book details
    void addBook() {
        try {
            add(); // Get title and price from base class
            cout << "Page Count: ";
            cin >> pageCount;
            if (pageCount <= 0) {
                throw pageCount; // Throw exception if page count is invalid
            }
        } catch (...) {
            cout << "\nInvalid Page Count! Setting to 0.";
            pageCount = 0; // Default to 0 if exception occurs
        }
    }

    // Function to display book details
    void displayBook() const {
        display(); // Get title and price from base class
        cout << "\nPage Count: " << pageCount;
    }
};

// Derived class for tapes
class Tape : public Publication {
private:
    float playTime; // Playtime of the tape in minutes

public:
    // Function to add tape details
    void addTape() {
        try {
            add(); // Get title and price from base class
            cout << "Play Time (minutes): ";
            cin >> playTime;
            if (playTime <= 0) {
                throw playTime; // Throw exception if play time is invalid
            }
        } catch (...) {
            cout << "\nInvalid Play Time! Setting to 0.";
            playTime = 0; // Default to 0 if exception occurs
        }
    }

    // Function to display tape details
    void displayTape() const {
        display(); // Get title and price from base class
        cout << "\nPlay Time: " << playTime << " minutes";
    }
};

// Main function to interact with the user
int main() {
    const int MAX_SIZE = 10; // Maximum number of books and tapes
    Book books[MAX_SIZE]; // Array of book objects
    Tape tapes[MAX_SIZE]; // Array of tape objects
    int bookCount = 0; // Number of books added
    int tapeCount = 0; // Number of tapes added
    int choice; // User choice for menu

    do {
        // Display menu
        cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
        cout << "\n1. Add Book";
        cout << "\n2. Add Tape";
        cout << "\n3. Display Books";
        cout << "\n4. Display Tapes";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (bookCount < MAX_SIZE) {
                    books[bookCount].addBook(); // Add book details
                    bookCount++; // Increment book count
                } else {
                    cout << "\nBook list is full!";
                }
                break;

            case 2:
                if (tapeCount < MAX_SIZE) {
                    tapes[tapeCount].addTape(); // Add tape details
                    tapeCount++; // Increment tape count
                } else {
                    cout << "\nTape list is full!";
                }
                break;

            case 3:
                cout << "\n* * * * * BOOK INFORMATION * * * * *";
                for (int i = 0; i < bookCount; ++i) {
                    books[i].displayBook(); // Display all books
                    cout << "\n-------------------------";
                }
                break;

            case 4:
                cout << "\n* * * * * TAPE INFORMATION * * * * *";
                for (int i = 0; i < tapeCount; ++i) {
                    tapes[i].displayTape(); // Display all tapes
                    cout << "\n-------------------------";
                }
                break;

            case 5:
                cout << "Exiting program.";
                break;

            default:
                cout << "Invalid choice. Please try again.";
        }
    } while (choice != 5); // Continue until the user chooses to exit

    return 0; // End of the program
}
