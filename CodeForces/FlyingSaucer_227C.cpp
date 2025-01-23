#include <iostream>
using namespace std;
int TOH(int n,int S,int A,int D){
    if(n==0){
        return 0;
    }
    int m=0;
    m+=TOH(n-1,S,A,D);
    m++;
    m+=TOH(n-1,D,A,S);
    m++;
    m+=TOH(n-1,S,A,D);
    return m;
}

int FCS(int m,int mod){
    return (m)%mod;
}
int main() {
    int n,mod;
    cin>>n>>mod;
    int m=TOH(n,1,2,3);
    int res=FCS(m,mod);
    cout<<res<<endl;
    return 0;
}