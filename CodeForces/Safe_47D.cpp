#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int mod = 1e9 + 7;

// #ifndef ONLINE_JUDGE
// #include "C:/algo/debug.h"
// #else
// #define debug(x)
// #endif

int n,m;
vector<string> posswr;
vector<pair<string,int>> mp;

void f(int ind, string &s, int n) {
    if(ind>=s.size()) {
        if(n==0) posswr.push_back(s);
        return;
    }
    f(ind+1,s,n);
    if(n>0) {
        char org = s[ind];
        s[ind] = org=='0'?'1':'0';
        f(ind+1,s,n-1);
        s[ind] = org;
    }
}

bool check(string wrong, string guess, int n) {
    int cnt = 0;
    for(int i=0;i<wrong.size();i++) {
        if(wrong[i]!=guess[i]) cnt++;
    }
    return cnt==n;
}

void solve() {
    int ans = 0;
    cin>>n>>m;
    posswr.clear();
    mp.clear();
    mp.resize(m);
    for(int i=0;i<m;i++) {
        string s;
        int val;
        cin>>s>>val;
        mp[i] = {s,val};
    }

    f(0, mp[0].first, mp[0].second);

    for(auto &it: posswr) {
        bool flag = true;
        for(auto &i: mp) {
            if(!check(it,i.first,i.second)) {
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    
    cout<<ans<<endl;
}

signed main(){
    fastIO();
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// Codeforces 47 D Solution