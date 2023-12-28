#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed at a given position
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the current row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Function to solve N Queens problem using backtracking
bool solveNQueens(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed, return true
    if (col >= N)
        return true;

    // Try placing the queen in all rows of the current column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1, N))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, remove it
            board[i][col] = 0;
        }
    }

    // If the queen can't be placed in any row of this column, return false
    return false;
}

// Function to print the N-Queens solution
void printSolution(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Main function to solve N-Queens problem
void solveNQueensProblem(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueens(board, 0, N))
        cout << "Solution does not exist";
    else
        printSolution(board, N);
}

int main() {
    int N = 4; // Change N for different board sizes
    solveNQueensProblem(N);
    return 0;
}
