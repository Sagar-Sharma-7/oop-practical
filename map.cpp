#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    map<string, int> covidData;
    covidData["Maharashtra"] = 1500000;
    covidData["Kerala"] = 750000;
    covidData["Delhi"] = 450000;
    covidData["Tamil Nadu"] = 650000;
    covidData["Karnataka"] = 700000;

    cout << "Covid19 Patient Data by State\n";
    cout << "--------------------------------\n";
    cout << "States and their Covid19 Patient Counts:\n";
    for(const auto& entry: covidData){
        cout << entry.first << ": " << entry.second << " patients" << endl;
    }

    string state;
    cout << "\nEnter the name of the state to look up its Covid19 patient count: ";
    cin >> state;

    auto it = covidData.find(state);
    if(it != covidData.end()){
         cout << "The Covid19 patient count in " << state << " is: " << it->second << " patients." << endl;
    }else{
         cout << "The state " << state << " is not in the database." << endl;
    }

    return 0;

}