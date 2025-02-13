#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

int max_score(int n, int m, vector<tuple<int, int, int>> &tunnels) {
    vector<ll> dist(n + 1, -INF);
    dist[1] = 0;
    
    for (int i = 1; i <= n - 1; i++) {
        for (auto &tunnel : tunnels) {
            int a, b, x;
            tie(a, b, x) = tunnel;
            if (dist[a] != -INF && dist[a] + x > dist[b]) {
                dist[b] = dist[a] + x;
            }
        }
    }
    
    // Check for positive cycle
    for (int i = 1; i <= n - 1; i++) {
        for (auto &tunnel : tunnels) {
            int a, b, x;
            tie(a, b, x) = tunnel;
            if (dist[a] != -INF && dist[a] + x > dist[b]) {
                return -1;
            }
        }
    }
    
    return dist[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> tunnels(m);
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        tunnels[i] = make_tuple(a, b, x);
    }
    cout << max_score(n, m, tunnels) << endl;
    return 0;
}
