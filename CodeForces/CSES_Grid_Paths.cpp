#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int paths(int i,int j,vector<vector<char>>& arr,vector<vector<int>>& dp){
    int n=arr.size();
    if(i>=n||j>=n||arr[i][j]=='*'){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 1;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int right=paths(i,j+1,arr,dp);
    int down=paths(i+1,j,arr,dp);
    dp[i][j]=(right+down)%MOD;
    return dp[i][j];

    
}

int main() {
    int n;
    cin>>n;
    vector<vector<char>> arr(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<paths(0, 0, arr, dp)<<endl;
    return 0;
}