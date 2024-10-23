/*
Write a C++ program using STL for sorting and searching user-defined records
such as item records using vector container.
*/

#include <iostream>
#include <algorithm>  // For STL algorithms like sort, find, for_each
#include <vector>     // For STL vector container
using namespace std;

// Class to represent an Item
class Item {
public:
    char name[10];  // Item name
    int quantity;   // Item quantity
    int cost;       // Item cost
    int code;       // Unique item code

    // Operator overload to check equality based on item code
    bool operator==(const Item& i1) {
        return code == i1.code;
    }

    // Operator overload to compare items based on item code (for sorting)
    bool operator<(const Item& i1) {
        return code < i1.code;
    }
};

vector<Item> o1;  // Vector to store Item objects

// Function declarations
void print(Item& i1);
void display();
void insert();
void search();
void dlt();
bool compare(const Item& i1, const Item& i2);

int main() {
    int ch;
    do {
        cout << "\n* * * * * Menu * * * * *";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            sort(o1.begin(), o1.end(), compare);  // Sorting the items based on cost
            cout << "\n\nSorted on Cost: ";
            display();
            break;

        case 5:
            dlt();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\nInvalid choice! Please try again.";
        }

    } while (ch != 6);

    return 0;
}

// Function to insert a new item into the vector
void insert() {
    Item i1;
    cout << "\nEnter Item Name: ";
    cin >> i1.name;
    cout << "\nEnter Item Quantity: ";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost: ";
    cin >> i1.cost;
    cout << "\nEnter Item Code: ";
    cin >> i1.code;
    o1.push_back(i1);  // Add the item to the vector
}

// Function to display all items in the vector
void display() {
    for_each(o1.begin(), o1.end(), print);  // Use for_each to display all items
}

// Function to print details of a single item
void print(Item& i1) {
    cout << "\nItem Name: " << i1.name;
    cout << "\nItem Quantity: " << i1.quantity;
    cout << "\nItem Cost: " << i1.cost;
    cout << "\nItem Code: " << i1.code;
    cout << "\n";
}

// Function to search for an item based on its code
void search() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);  // Use find algorithm to search for the item
    if (p == o1.end()) {
        cout << "\nNot found!!!";
    } else {
        cout << "\nFound!!!";
    }
}

// Function to delete an item based on its code
void dlt() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);  // Use find algorithm to search for the item to delete
    if (p == o1.end()) {
        cout << "\nNot found!!!";
    } else {
        o1.erase(p);  // Use erase to delete the item from the vector
        cout << "\nDeleted!!!";
    }
}

// Function to compare two items based on their cost (used for sorting)
bool compare(const Item& i1, const Item& i2) {
    return i1.cost < i2.cost;
}
