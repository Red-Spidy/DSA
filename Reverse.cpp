#include <iostream>
#include <stack>
using namespace std;
int main(){
    string a = "Mallaylam";
    stack<char> s;
    for(int i =0; i<a.length();i++){
        s.push(a[i]);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}