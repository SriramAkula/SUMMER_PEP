#include <iostream>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        cout <<max(n, m) + 1 << endl;
    }
}

int main() {
    solve();
    return 0;
}
