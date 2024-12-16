#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Item{
    public:
        int code;
        string name;
        int cost;
        int quantity;

        Item(int c, const string& n, int co, int q):code(c), name(n), cost(co), quantity(q){};

        void display() const{
            cout << "Item code: " << code << ", Name: " << name << ", Cost: " << cost << ", Quantity: " << quantity << endl;
        }

        bool operator == (const Item& other) const{
            return code == other.code;
        }

        bool operator < (const Item& other) const {
            return cost < other.cost;
        }

};

class ItemManager{
    private:
        vector<Item> items;
    public:
        void insertItem(){
            int code, cost, quantity;
            string name;

            cout << "Enter Item Code: ";
            cin >> code;
            cout << "Enter Item Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Item Cost: ";
            cin >> cost;
            cout << "Enter Item Quantity: ";
            cin >> quantity;

            items.push_back(Item(code, name, cost, quantity));
        }

        void displayItems() const{
            for(const auto& item: items){
                item.display();
            }
        }

        void searchItem(){
            int code;
            cout << "Enter Item Code to search: ";
            cin >> code;

            auto it = find(items.begin(), items.end(), Item(code, "", 0, 0));
            if(it != items.end()){
                cout << "Item found: ";
                it->display();
            }else{
                cout << "Item not Found!" << endl;
            }
        }

        void sortItemsByCost(){
            sort(items.begin(), items.end());
            cout << "Items sorted by cost: " << endl;
            displayItems();
        }

};

int main(){
    ItemManager manager;
    int choice;

    do{
        cout << "\n* * * * Menu * * * *";
        cout << "\n1. Insert Item";
        cout << "\n2. Display Items";
        cout << "\n3. Search Item by Code";
        cout << "\n4. Sort Items by Cost";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1: {
                manager.insertItem();
                break;
            }
            case 2: {
                manager.displayItems();
                break;
            }
            case 3: {
                manager.searchItem();
                break;
            }
            case 4: {
                manager.sortItemsByCost();
                break;
            }
            case 5: {
                cout << "Exiting Program..." << endl;
                break;
            }
            default:
                cout << "Invalid Choice!" << endl;
        }

    }while(choice != 5);

    return 0;
}