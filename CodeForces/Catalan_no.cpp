#include <bits/stdc++.h>
using namespace std;

int catalan(int n){
    vector<int> c(n+1);
    c[0]=1;
    c[1]=1;
    for(int i=2;i<=n;i++){
        c[i]=0;
        for(int j=0;j<i;j++){
            c[i]+=c[j]*c[i-j-1];
        }
    }
    
    return c[n];
}

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int res=catalan(n);
        cout<<res<<endl;
    }
    return 0;
}