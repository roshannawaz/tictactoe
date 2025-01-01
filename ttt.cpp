#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(char board[]);
bool checkWin(char board[], char player);
bool checkDraw(char board[]);
void makeMove(char board[], char player);

int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player = 'X';
    bool gameOn = true;

    while (gameOn) {
        displayBoard(board);
        makeMove(board, player);
        
        if (checkWin(board, player)) {
            displayBoard(board);
            cout << "Player " << player << " wins!\n";
            gameOn = false;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            gameOn = false;
        } else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }
    return 0;
}

void displayBoard(char board[]) {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

bool checkWin(char board[], char player) {
    // Check rows, columns, and diagonals
    return (
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
    );
}

bool checkDraw(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

void makeMove(char board[], char player) {
    int move;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        if (move >= 1 && move <= 9 && board[move - 1] != 'X' && board[move - 1] != 'O') {
            board[move - 1] = player;
            validMove = true;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}
