#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool check(int n, vector<string>& nQueens, int row, int col) {
        for (int i = 0; i < n; i++) {
            if (nQueens[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(int n, vector<vector<string>>& output, vector<string>& nQueens, int row) {
        if (row == n) {
            output.push_back(nQueens);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (check(n, nQueens, row, col)) {
                nQueens[row][col] = 'Q';
                solve(n, output, nQueens, row + 1);
                nQueens[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> nQueens(n, string(n, '.'));
        solve(n, output, nQueens, 0);
        return output;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Number of solutions: " << solutions.size() << endl;

    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
