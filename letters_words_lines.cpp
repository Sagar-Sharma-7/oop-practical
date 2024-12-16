#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countFileContents(const string& filename){
    ifstream file(filename);

    if(!file){
        cerr << "Error opening the file" << endl;
        return;
    }

    int letters = 0, words = 0, lines = 0;
    string line;
    while(getline(file, line)){
        lines++;
        bool inWord = false;
        for(char ch: line){
            if(isalpha(ch)){
                letters++;
            }
            if(isspace(ch)){
                if(inWord){
                    words++;
                    inWord = false;
                }
            }else{
                inWord = true;
            }
        }
        if(inWord){
            words++;
        }

    }

    file.close();
    cout << "Letters: " << letters << endl;
    cout << "Words: " << words << endl;
    cout << "Lines: " << lines << endl;
}

void calculateFileSize(const string& filename){
    ifstream file(filename, ios::binary | ios::in);
    if(!file){
        //
        return;
    }

    file.seekg(0 , ios::end);
    int size = file.tellg();
    file.close();
    cout << "File size: " << size << " bytes" << endl;
}

int main(){
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    countFileContents(filename);
    calculateFileSize(filename);

    return 0;
}