#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(const string &inputFile, const string &outputFile){
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cout << "Error: Unable to open input file." << endl;
        return;
    }
    if (!outFile) {
        cout << "Error: Unable to open output file." << endl;
        return;
    }

    char ch;
    while(inFile.get(ch)){
        outFile.put(ch + 5);
    }

    cout << "File successfully encrypted and saved as " << outputFile << endl;
    inFile.close();
    outFile.close();
}

void decryptFile(const string &inputFile, const string &outputFile){
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cout << "Error: Unable to open input file." << endl;
        return;
    }
    if (!outFile) {
        cout << "Error: Unable to open output file." << endl;
        return;
    }

    char ch;
    while(inFile.get(ch)){
        outFile.put(ch - 5);
    }
    cout << "File successfully decrypted and saved as " << outputFile << endl;

    inFile.close();
    outFile.close();
}

int main() {
    int choice;
    string inputFile, outputFile;

    do {
        cout << "\n* * * FILE ENCRYPTION & DECRYPTION MENU * * *\n";
        cout << "1. Encrypt a file\n";
        cout << "2. Decrypt a file\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the name of the file to encrypt: ";
                cin >> inputFile;
                cout << "Enter the name of the output file: ";
                cin >> outputFile;
                encryptFile(inputFile, outputFile);
                break;

            case 2:
                cout << "Enter the name of the file to decrypt: ";
                cin >> inputFile;
                cout << "Enter the name of the output file: ";
                cin >> outputFile;
                decryptFile(inputFile, outputFile);
                break;

            case 3:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
