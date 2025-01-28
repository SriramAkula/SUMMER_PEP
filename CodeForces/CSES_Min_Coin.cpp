#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int t;
    cin>>t;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(t+1,t+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(coins[i-1]<=j){
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    // vector<int> dp(t + 1, t + 1);
    // dp[0] = 0; 
    // for (int i = 0; i < n; i++) {
    //     for (int j = coins[i]; j <= t; j++) {
    //         dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
    //     }
    // }
    //Space Optimal



    if (dp[n][t] == t+1) {
        cout << -1 << endl; 
    } else {
        cout << dp[n][t] << endl; 
    }
    return 0;
}