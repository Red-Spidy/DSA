#include <iostream>
#include <climits>
using namespace std;
int main(){
    int start=0;
    int size =9;
    int arr[9]= {10,20,30,40,50,60,70,80,90};
    int end = size -1;
    while(true){
        if(start>end){
            break;
        }
        if(start==end)
        {
            cout<<arr[start]<<" ";
        }
        else{
            cout<<arr[start]<<" ";
            cout<<arr[end]<<" ";
        }

        
        start++;
        end--;
    }
    return 0;
}