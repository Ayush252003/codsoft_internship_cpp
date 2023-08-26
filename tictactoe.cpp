#include <iostream>
#include <vector>

using namespace std;


void displayBoard(const vector<vector<char>>& board) {
    cout << "TIC-TAC-TOE" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}


bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;  
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;  
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;      
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;      
    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;  
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameover = false;

    while (!gameover) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        int row, col;
        cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameover = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameover = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameover = false;
    }

    return 0;
}
