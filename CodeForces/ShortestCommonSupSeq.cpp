#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the dp table in reverse
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(str1[i] == str2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        string scs = "";
        int i = 0, j = 0;
        
        // Construct the SCS string
        while(i < m && j < n) {
            if(str1[i] == str2[j]) {
                scs += str1[i];
                i++;
                j++;
            } else if(dp[i + 1][j] > dp[i][j + 1]) {
                scs += str1[i];
                i++;
            } else {
                scs += str2[j];
                j++;
            }
        }

        // Add remaining characters from str1 or str2
        while(i < m) {
            scs += str1[i];
            i++;
        }
        while(j < n) {
            scs += str2[j];
            j++;
        }
        
        return scs;
    }
};

int main() {
    Solution solution;
    
    // Sample input
    string str1 = "abac";
    string str2 = "cab";
    
    string result = solution.shortestCommonSupersequence(str1, str2);
    
    cout << "Shortest Common Supersequence: " << result << endl;

    return 0;
}
