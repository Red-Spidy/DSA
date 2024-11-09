#include <iostream>
#include <climits>
using namespace std;
int main(){
    int max = INT_MIN;
    int arr[5]= {1,3,5,7,9};
    for(int i=0;i<5;i++){
        if(arr[i]> max){
            max = arr[i];
        }
    }
    cout<<max;
    return 0;
}