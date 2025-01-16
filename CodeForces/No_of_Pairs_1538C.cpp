#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

// Function to count pairs with sum in range [l, r]
long long countPairsInRange(const vector<int>& a, int l, int r) {
    // Your implementation goes here
    long long ans=0;
    for(int i=0;i<a.size();i++){
        int itr1=lower_bound(a.begin()+i+1,a.end(),l-a[i])-a.begin();
        int itr2=upper_bound(a.begin()+i+1,a.end(),r-a[i])-a.begin();
        ans+=(itr2-itr1);
    }
    return ans; // Placeholder
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sort the array for two-pointer/binary search
        sort(a.begin(), a.end());

        // Find the number of valid pairs
        cout << countPairsInRange(a, l, r) << endl;
    }

    return 0;
}
