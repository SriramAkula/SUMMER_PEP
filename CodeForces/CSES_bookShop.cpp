#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,price;
    cin>>n>>price;
    int cost[n];
    int pages[n];
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(price+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=price;j++){
            dp[i][j]=dp[i-1][j];
            if(cost[i-1]<=j){
                dp[i][j]=max(dp[i][j],pages[i-1]+dp[i-1][j-cost[i-1]]);
            }
            
        }
    }
    cout<<dp[n][price]<<endl;
    return 0;
}