#include <iostream>
using namespace std;
char stack[100];
int tos = -1;
void push(char a){
    tos++;
    stack[tos] = a;
}
void print(){
    for(int i = tos;i >=0; i--){
        cout<<stack[i];
    }
}
int main(){
    string n;
    cout<<"Enter The String ";
    cin>> n;
    for(int i = 0; i<n.length(); i++){
        push(n[i]);
    }
    cout<<"Entered String is "<<n<<endl;

    cout<<"Reverse Of the String is ";
    print();
    return 0;
}