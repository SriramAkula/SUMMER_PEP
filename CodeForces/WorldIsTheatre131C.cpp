#include <iostream>
using namespace std;
long long nCr(int n,int r){
    if(r>n) return 0;
    if(r==n) return 1;
    if(r==0) return 1;
    long long ans=1;
    for(int i=1;i<=r;i++){
        ans=((long long)ans*(n-i+1)/i);
    }
    return ans;
}

int main() {
    int nb,ng,n;
    cin>>nb>>ng>>n;
    long long tot=nCr(nb+ng,n);
    long long sum=0;
    for(int i=0;i<4;i++) { 
        int j=n-i;
        if(i<=nb && j<=ng){
            sum+=nCr(nb,i)*nCr(ng,j);
        } 
        
    }
    int g=0;
    int b=n-g;
    if(b<=nb && g<=ng){
        sum+=nCr(nb,b)*nCr(ng,g);
    }
    cout<<(tot-sum)<<endl;
    return 0;
}