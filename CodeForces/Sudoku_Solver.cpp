#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col,char num) {
        for(int i=0;i<9;i++){
            if(board[row][i]==num) return false;
            if(board[i][col]==num) return false;
            int subGridRow=3*(row/3)+i/3;
            int subGridCol=3*(col/3)+i%3;
            if(board[subGridRow][subGridCol]==num) return false;
        }
        return true;
    }
    bool f(vector<vector<char>>& board, int row, int col) {
        if (row == 9) { 
            return true;
        }

        int nextRow = (col == 8) ? row + 1 : row;
        int nextCol = (col == 8) ? 0 : col + 1;

        if (board[row][col] != '.') {
            return f(board, nextRow, nextCol);
        } else {
            for (char ch = '1'; ch <= '9'; ch++) {
                if (check(board, row, col, ch)) {
                    board[row][col] = ch;
                    if (f(board, nextRow, nextCol)) return true;
                    board[row][col] = '.'; 
                }
            }
        }
        return false; 
    }
    bool solve(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char num='1';num<='9';num++){
                        if(check(board,row,col,num)){
                            board[row][col]=num;
                            if(solve(board)) return true;
                            board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // solve(board);
        f(board,0,0);
    }
};

int main() {
    // Sample Sudoku board
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solution;
    cout << "Original Sudoku Board:" << endl;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << (cell == '.' ? '.' : cell) << " ";
        }
        cout << endl;
    }

    solution.solveSudoku(board);

    cout << "\nSolved Sudoku Board:" << endl;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
