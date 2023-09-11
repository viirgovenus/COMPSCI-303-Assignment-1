
#ifndef arrayFunctions
#define arrayFunctions

// A function to check if a certain integer exists in the array
bool checkInt(int arr[], int size, int num);

// A function that can modify the value of an integer when called with the
// index of the integer in the array and return the new value and old value
// back to the user
void modifyVal(int arr[], int index, int &newInt, int &oldInt);

// A function that adds a new integer to the end of the array
void addInt(int arr[], int &size, int num);

// A function which intakes an index of an array and replaces the value
// with either zero or removes the integer altogether
void removeInt(int arr[], int &size, int index);

#endif