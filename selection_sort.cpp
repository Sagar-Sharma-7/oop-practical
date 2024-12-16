#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int size){
    for(int i = 0; i < size-1; i++){
        int min_index = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        T temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

template <typename T>
void displayArr(T arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main(){
    int intArr[] = {34,7,23,32,5,62};
    int intsize = sizeof(intArr)/sizeof(intArr[0]);

    float floatArr[] = {3.4, 7.2, 2.3, 3.2, 0.5, 6.2};
    int floatsize = sizeof(floatArr) / sizeof(floatArr[0]);

    cout << "Original integer array: ";
    displayArr(intArr, intsize);

    selectionSort(intArr, intsize);  // Sorting integer array

    cout << "Sorted integer array: ";
    displayArr(intArr, intsize);

    cout << "\nOriginal float array: ";
    displayArr(floatArr, floatsize);

    selectionSort(floatArr, floatsize);  // Sorting float array

    cout << "Sorted float array: ";
    displayArr(floatArr, floatsize);
    return 0;
}