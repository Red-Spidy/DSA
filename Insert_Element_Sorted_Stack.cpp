#include <iostream>
#include<stack>

using namespace std;

void print(stack <int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void sorted_insert(stack <int> &s, int target){

    if(s.empty()){
        s.push(target);
        return;
    }
    // base caes
    if(s.top()>=target){
        s.push(target);
        return;
    }

    // Calling top poping it storing in another variaable
    int topel = s.top();
    s.pop();

    // Recursion calling function

    sorted_insert(s, target);

    s.push(topel);
    
}

void sort_stack(stack <int> &s){
    
    // Base Case
    if(s.empty()){
        return;
    }

    int topel2 = s.top();
    s.pop();
    sort_stack(s);

    sorted_insert(s, topel2);
}
int main()
{

    stack <int> s;
    
    s.push(80);
    s.push(70);
    s.push(60);
    s.push(90);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);
    print(s);
    sort_stack(s);
    cout<<"Aftyer Sorting"<<endl;
    print(s);
    return 0;

}
