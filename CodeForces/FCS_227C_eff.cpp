#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//v2

int main() {
    long long n,mod;
    cin>>n>>mod;
    long long res=pow(3,n)-1;
    cout<<(res+mod)%mod<<endl;
    return 0;
}