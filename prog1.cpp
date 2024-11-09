#include <iostream>
using namespace std;

int main() {
    int arr[53]; // Declare an array of 30 integers
    char arr2[106];
    bool arr[23];

    cout << &arr << endl;    // Print the address of the entire array
    cout << &arr[1] << endl; // Print the address of the second element of the array

    return 0;
}
