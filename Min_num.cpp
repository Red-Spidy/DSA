#include <iostream>
#include <climits>
using namespace std;
int main(){
    int min = INT_MAX;
    int arr[5]= {1,3,5,7,9};
    for(int i=0;i<5;i++){
        if(arr[i]< min){
            min = arr[i];
        }
    }
    cout<<min;
    return 0;
}