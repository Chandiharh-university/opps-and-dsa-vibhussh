#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) return false;
    }
    return true;
}

void solve(int n, int row, vector<int> &board, int &count) {
    if (row == n) {
        count++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col)) {
            board[row] = col;
            solve(n, row + 1, board, count);
        }
    }
}

int totalNQueens(int n) {
    vector<int> board(n, -1);
    int count = 0;
    solve(n, 0, board, count);
    return count;
}
