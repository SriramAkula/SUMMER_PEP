#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long nCr(int n,int r){
    if(r>n) return 0;
    if(r==n) return 1;
    if(r==0) return 1;
    long long ans=1;
    for(int i=1;i<=r;i++){
        ans=((long long)ans*(n-i+1)/i)%MOD;
    }
    return ans%MOD;

}
long long KAC(vector<int>&v,int n){
    int sum=v[0];
    long long ways=1;
    for(int i=1;i<v.size();i++){
        int k=v[i]-1;
        if(i>=2){
            sum++;
        }
        sum+=k;
        ways*=nCr(sum,k)%MOD;
    }
    return ways;
}

int main() {
    int t;
    cin>>t;
    vector<int> v(t);
    int sum=0;
    for(int i=0;i<t;i++){
        cin>>v[i];
        sum+=v[i];
    }
    long long res=KAC(v,sum);
    cout<<res<<endl;
    return 0;
}