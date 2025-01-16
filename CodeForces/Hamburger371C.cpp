#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string recipe;
    cin >> recipe;

    ll nb, ns, nc;
    cin >> nb >> ns >> nc;

    ll pb, ps, pc;
    cin >> pb >> ps >> pc;

    ll r;
    cin >> r;

    ll rb = count(recipe.begin(), recipe.end(), 'B');
    ll rs = count(recipe.begin(), recipe.end(), 'S');
    ll rc = count(recipe.begin(), recipe.end(), 'C');

    ll low = 0, high = 1e13, maxHamburgers = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        ll needB = max(0LL, mid * rb - nb);
        ll needS = max(0LL, mid * rs - ns);
        ll needC = max(0LL, mid * rc - nc);

        ll cost = needB * pb + needS * ps + needC * pc;

        if (cost <= r) {
            maxHamburgers = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << maxHamburgers << endl;
    return 0;
}
