#include <iostream>
#include<stack>

using namespace std;

void print(stack <int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main()
{

    stack <int> s;
    s.push(10);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(80);
    s.push(60);
    s.push(70);
    s.push(50);
    print(s);

    return 0;

}
