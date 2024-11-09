#include <iostream>
#include<stack>
// Insert at bottom for first step
using namespace std;

void print(stack <int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}


void insert_at_bottom(stack <int> &s,int target){
    // Top ko bottom mai daalne ke liye
    // Recursive program bnayenge
    if(s.empty()){
        s.push(target);
        return;
    }
    // Stack top jab bhi access krein to hume pehle check krna hai empty na ho stack

   int topEl = s.top();
// Movinfg to next step and the recursive call
    s.pop();
    insert_at_bottom(s,target);

    s.push(topEl);

}


void reverse(stack <int> &s){

    // base case
    if(s.empty()){
        return;
    }

    int target = s.top();
    s.pop();


    // Reverse stack
    reverse(s);

    // Insert at Bottom
    insert_at_bottom(s,target);
}

int main(){
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    print(s);

    reverse(s);
    cout<<"Printing after reverse"<<endl;
    print(s);
    // reverse(s);
    return 0;

}

/* Algorithm
Step -1 Pehle top element nikalo
Step -2 pop kro
Step -3 Recursve call maaro
Step-4 Insert atb ottom kro top ko*/