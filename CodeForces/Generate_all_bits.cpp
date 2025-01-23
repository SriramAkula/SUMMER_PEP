#include <bits/stdc++.h>
using namespace std;

void generate(int n, string current, vector<string>& sequences) {
    if (current.length() == n) {
        sequences.push_back(current);
        return;
    }
    generate(n, current + "0", sequences);
    generate(n, current + "1", sequences);
}

int main() {
    int n;
    cin >> n;
    int t;
    while(t--){
        string seq;
        getline(cin,seq);
        int correct;
        cin>>correct;
        
        vector<string> sequences;
        generate(n, "", sequences);
    }

    return 0;
}
