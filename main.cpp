#include <iostream>

using namespace std;

class TicTacToe {
private:
    char board[3][3];

public:
    TicTacToe();
    void printBoard();
    bool makeMove(int row, int col, char player);
    char checkWinner();
};


int main() {
    TicTacToe game;
    int row, col;
    char player = 'X';

    for (int turn = 0; turn < 9; turn++) {
        game.printBoard();
        // get valid row and column input
        cout << "player " << player << ", enter your move (enter row (space) enter column): ";
        cin >> row >> col;
        // invalid size
        while (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "invalid input. rows and columns should be between 1 and 3. Try again: ";
            cin >> row >> col;
        }
        // attempt to make the move
        while (!game.makeMove(row - 1, col - 1, player)) {
            cout << "invalid move. try again: ";
            cin >> row >> col;//retry
        }

        char winner = game.checkWinner();
        if (winner != '-') {
            game.printBoard();
            cout << "player " << winner << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X'; // switches player
    }

    game.printBoard();
    cout << "it's a draw!\n";
    return 0;
}
//our baord 3x3
TicTacToe::TicTacToe() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}
// actually print it out 3x3
void TicTacToe::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}
bool TicTacToe::makeMove(int row, int col, char player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') return false;

    board[row][col] = player;
    return true;
}
char TicTacToe::checkWinner() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') return board[i][0];
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-') return board[0][j];
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') return board[0][2];

    return '-'; // no winner yet
}
