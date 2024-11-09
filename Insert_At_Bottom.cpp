// Top ko bottokm mai shift krna hai and then print krna hai
#include <iostream>
#include <stack>
using namespace std;

void print(stack <int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void solve(stack <int> &s , int target){
    // Base Case
    if(s.empty()){
        s.push(target);
        return;
    }
    int topEl = s.top();
// Movinfg to next step and the recursive call
    s.pop();
    solve(s,target);

// Backtrack
    s.push(topEl);

    
}

void insert_at_bottom(stack <int> &s){
    // Top ko bottom mai daalne ke liye
    // Recursive program bnayenge

    // Stack top jab bhi access krein to hume pehle check krna hai empty na ho stack

    if(s.empty()){
        cout<<"Stack IS empty"<<endl;
        return;
    }
    int target = s.top();
    s.pop();
    solve(s, target);

}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);



    print(s);
    cout<<"After shifting the elements"<<endl;

    insert_at_bottom(s);
    print(s);
}