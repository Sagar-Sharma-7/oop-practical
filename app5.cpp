/*
Write a function template for selection sort that inputs, sorts, and outputs an integer array and a float array.
*/

#include <iostream>
using namespace std;

// Template function for selection sort
template <class T>
void selectionSort(T A[], int n) {
    int i, j, minIndex;
    T temp;
    
    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        // Swap the found minimum element with the first element
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
    
    // Output sorted array
    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, choice;
    
    do {
        cout << "\n* * * * * SELECTION SORT SYSTEM * * * * *";
        cout << "\n--------------------MENU-----------------------";
        cout << "\n1. Integer Values";
        cout << "\n2. Float Values";
        cout << "\n3. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "\nEnter total number of integer elements: ";
                cin >> n;
                int* A = new int[n];  // Dynamic memory allocation for integer array
                cout << "\nEnter integer elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> A[i];
                }
                selectionSort(A, n);  // Call template function for int array
                delete[] A;  // Free dynamically allocated memory
                break;
            }
            
            case 2: {
                cout << "\nEnter total number of float elements: ";
                cin >> n;
                float* B = new float[n];  // Dynamic memory allocation for float array
                cout << "\nEnter float elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> B[i];
                }
                selectionSort(B, n);  // Call template function for float array
                delete[] B;  // Free dynamically allocated memory
                break;
            }
            
            case 3:
                exit(0);  // Exit the program
                break;
            
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
