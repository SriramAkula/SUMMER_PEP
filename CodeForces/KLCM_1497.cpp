#include <iostream>
#include <vector>
using namespace std;

void findK3LCM(int n){
    if(n%2==1){
        cout<<1<<" "<<n/2<<" "<<n/2;
    }else if(n%4==0){
        cout<<n/2<<" "<<n/4<<" "<<n/4;  
    }else{
        cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2;  
    }
}
// Function to compute k positive integers with the desired properties
void findKLCM(int n, int k) {
    // Your code goes here
    for(int i=0;i<k-3;i++){
        cout<<1<<" ";
        n--;
    }
    findK3LCM(n);
    cout<<endl;
}

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        findKLCM(n, k);
    }
    return 0;
}
