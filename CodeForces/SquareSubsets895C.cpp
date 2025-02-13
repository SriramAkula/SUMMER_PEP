#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
#define ll long long

bool perfectSquare(ll num){
    ll root=sqrt(num);
    return (root*root)==num;
}

unordered_map<ll, unordered_map<int, int>> dp;

int cntWay(vector<int>& arr,ll product,int ind){
    if(ind==arr.size()){
        if(perfectSquare(product)){
            return 1;
        }
        return 0;
    }
    if(dp[product].count(ind)){
        return dp[product][ind];
    }
    ll exclude=cntWay(arr,product,ind+1);
    ll include=cntWay(arr,product*arr[ind],ind+1);
    return dp[product][ind]=((exclude+include)%MOD);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll product=1;
    int res=cntWay(arr,product,0);
    cout<<res-1<<endl;
    return 0;
}