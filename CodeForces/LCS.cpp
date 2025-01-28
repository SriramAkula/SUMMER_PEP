
#include<bits/stdc++.h>
using namespace std;

    string lcse(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        string lcs = "";
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (text1[i] == text2[j]) {
                lcs += text1[i];
                i++;
                j++;
            } else if (dp[i + 1][j] > dp[i][j + 1]) {
                i++;
            } else {
                j++;
            }
        }

        return lcs;
    }


int main(){
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    string res=lcse(s1,s2);
    cout<<res<<endl;
    return 0;
}