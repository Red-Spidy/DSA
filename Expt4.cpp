#include <iostream>
#include <string>
using namespace std;

void array_creation(string a[], bool b[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "Enter the item you want to store:" << endl;
        cin.ignore();
        getline(cin, a[i]);
        cout << "If you have already packed the item, press 1. Else, press 0:" << endl;
        cin >> b[i];
    }
}

void Print_Already_Bought(string a[], bool b[], int size) {
    for(int i = 0; i < size; i++) {
        if(b[i] == 1) {
            cout << "You have already packed " << a[i] << endl;
        }
    }
}
void  Print_Yet_To_Buy(string a[], bool b[], int size) {
    for(int i = 0; i < size; i++) {
        if(b[i] == 0) {
            cout << "You have not packed " << a[i] << endl;
        }
    }
}

int main() {
    int size;
    cout<<"Enter The size Of elements"<<endl;
    cin>>size;
    string a[size];
    bool b[size];
    array_creation(a, b, size);
    Print_Yet_To_Buy(a,b,size);
    Print_Already_Bought(a, b, size);
    return 0;
}