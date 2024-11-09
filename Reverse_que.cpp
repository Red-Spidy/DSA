#include<iostream>
#include <queue>
#include <stack>
using namespace std;

// First Approach using stack
// Seciond Approach Using recursion

// recursion mai pehla case mai sambhalunga then baaki ka recursion ko nolunga sambhal ne le lioye
//  Letrs Suppose Is code4 mai 3 6 9 2 8 given queue hai
// Pehle 3 ko nikal lo

// Recursion ne merko 8 2 9 6 tk de dia bss merko ab ye sochna haoi mai 3 jko end mai kaise daalu'
// 3 end mai daal dia
// bss khtm



// STack waale case mai time compklexity O(n) and spacer complexity bhi O(n)
void reverseQueue(queue <int> &q){
    stack<int> s;
    while(!q.empty()){
        int element = q.front();
        s.push(element);
        q.pop();
    }

    // Put all elements to q
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
}

void reverseQueueRecursion(queue <int> &q){
    // Trying Using recursive Calls
    if(q.empty()){

        return;
    }

    // Baad mai
    int ele = q.front();
    q.pop();
    reverseQueue(q);

    q.push(ele);

}
int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueue(q);

    cout<<"Printing Queue"<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}