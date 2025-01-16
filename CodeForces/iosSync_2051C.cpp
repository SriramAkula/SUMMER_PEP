#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        
        unordered_set<int> known_questions;
        for (int i = 0; i < k; ++i) {
            int q;
            cin >> q;
            known_questions.insert(q);
        }

        string res = "";
        for (int i = 0; i < m; ++i) {
            int missing_question = a[i];
            bool can_pass = true;

            // Check if Monocarp knows all questions except the missing one
            for (int question = 1; question <= n; ++question) {
                if (question != missing_question && known_questions.find(question) == known_questions.end()) {
                    can_pass = false;
                    break;
                }
            }
            res += (can_pass ? '1' : '0');
        }

        cout << res << endl;
    }
    return 0;
}
