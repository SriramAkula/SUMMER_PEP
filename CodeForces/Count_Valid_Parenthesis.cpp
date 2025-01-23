#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int catalan(int n){
    vector<int> c(n+1);
    c[0]=1;
    c[1]=1;
    for(int i=2;i<=n;i++){
        c[i]=0;
        for(int j=0;j<i;j++){
            c[i] = (c[i]+1LL*c[j]*c[i-j-1]%MOD)%MOD;
        }
    }
    
    return c[n]%MOD;
}

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if (n%2 == 1) {
            cout<<-1<<endl;
        } else {
            int res=catalan(n / 2);
            cout<<res<<endl;
        }
    }
    return 0;
}