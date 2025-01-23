#include <iostream>
using namespace std;
#define MOD 1000000007
//v2
long long FCS(int n,int mod){
    if(n==0){
        return 0;
    }
    long long c=0;
    long long temp=2;
    for(int i=0;i<n;i++){
        c+=(temp)%MOD;
        temp=((long long)temp*3)%MOD;
    }
    return (c)%mod;
}
int main() {
    int n,mod;
    cin>>n>>mod;
    long long res=FCS(n,mod);
    cout<<res<<endl;
    return 0;
}