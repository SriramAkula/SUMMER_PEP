#include <iostream>
using namespace std;
#define ll long long
#define MOD 1000000007

ll f(int i){
    if(i<=1){
        return 1;
    }
    ll ans=0;
    for(int j=1;j<=6;j++){
        if((i-j)>=0){
            ans+=f(i-j);
        }
    }
    return ans%MOD;
}

int main() {
        int n;
        cin>>n;
        ll res=f(n);
        cout<<res<<endl;

        return 0;
}