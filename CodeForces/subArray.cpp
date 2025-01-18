#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        arr1[i]=(n-i)*(i+1);
    }
    for(int i=0;i<n;i++){
        arr1[i]*=arr[i];
    }
    int sum=0;
    for(int i: arr1){
        sum+=i;
    }
    cout<<sum;
    return 0;
}