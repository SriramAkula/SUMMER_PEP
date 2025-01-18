#include <iostream>
using namespace std;

int fact(int n,int val=1){
    if(n==0 || n==1){
        return val;
    }
    return fact(n-1,n*val);
}

int main() {
    int n;
    cin>>n;
    int res=fact(n);
    cout<<res;
    return 0;
}