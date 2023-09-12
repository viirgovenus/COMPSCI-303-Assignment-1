
#include "arrayFunctions.h"
#include <iostream>
#include <fstream>

using namespace std;

// A function to check if a certain integer exists in the array

bool checkInt(int arr[], int size, int num){
    for (int i = 0; i < size; i++){
        if (arr[i] == num){
            return true;
        }
    }
    return false;
}

// A function that can mddify the value of an integer when called with the
// index of the integer in the array and return the new value and old value
// back to the user; also added in try/catch block to ensure user can't ask
// for an index that is out of bounds

void modifyVal(int arr[], int index, int &newInt, int &oldInt){
 try {
    if (index >= 0 && index < arr[index]) {
        oldInt = arr[index];
        arr[index] = newInt;
    } else {
        throw std::out_of_range("The index is out of bounds.");
    }
 } catch (const std::out_of_range &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
 }
}

// A function that adds a new integer to the end of the array

void addInt(int arr[], int &size, int num){
    arr[size++] = num;
}

// A function  which intakes an index of an array anda replaces the value
// with either zero or removes the integer altogether

void removeInt(int arr[], int &size, int index){
    for (int i = index; i < size; i++){
        arr[i] = arr[ i + 1];
    }
    size--;
}

// MAIN PROGRAM //

int main(){

    // Get file input from user and set array size
    // Create exception for if file doesn't exist
    // Close file

    string file = "array.txt";
    int arr[1000];
    int size = 0;

    ifstream inputFile;
    inputFile.open(file.c_str());
    if (!inputFile)
    {
        cout << "File cannot be opened." << endl;
        exit(1);
    }

    int num;
    while (inputFile >> num)
    {
        arr[size++] = num;
    }
    inputFile.close();

    // A function to return the index of an integer if it is present in
    // the array, aka a continuation of checkInt()

    cout << "Enter an integer to see if it exists within the array: ";
    cin >> num;
    if (checkInt(arr, size, num)){
        cout << "The integer exists in the array" << endl;
    } else {
            cout << "The integer does not exist in the array" << endl;
    }
  
    // Implementation of the modifyInt() function

    int index, newInt, oldInt;
    cout << "Enter the index of the integer you'd like to modify: ";
    cin >> index;
    cout << "Enter the new integer to replace the old: ";
    cin >> newInt;
    modifyVal(arr, index, newInt, oldInt);
    cout << "The old integer was "<<oldInt<<" and the new integer is "<<newInt<<" " << endl;

    // Implementation of the addInt() function

    cout<<"Enter a number to add to the array: ";
    cin >> num;
    addInt(arr, size, num);
    cout<<"The new array is: ";
    for(int i = 0; i < size; i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;


    // Implementation of removeInt() function

    cout << "Enter the index of the integer to remove: ";
    cin >> index;
    removeInt(arr, size, index);
    cout << "The new array is: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}






