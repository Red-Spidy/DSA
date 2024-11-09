#include <iostream>
using namespace std;
char stack[100];
int tos = -1;
void push(char a){
    tos++;
    stack[tos] = a;
}
void pop(){
    cout<<stack[tos];
    tos--;
}
void top(){
    cout<<stack[tos];
}
void print(){
    for(int i = tos;i >=0; i--){
        cout<<stack[i];
    }
}
void search(char a){
    for(int i = 0 ;i<=tos;i++){
        if(stack[i]==a){
            cout<<"Found"<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }
    }
}
int main(){
    return 0;
}