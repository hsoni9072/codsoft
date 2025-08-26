#include <iostream>
#include <vector>

using namespace std;


void displayBoard(const vector<vector<char>>& board);
bool placeMove(vector<vector<char>>& board, int row, int col, char player);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    bool gameRunning = true;

    cout << "TIC-TAC-TOE GAME\n";

    while (gameRunning) {
        
        vector<vector<char>> board(3, vector<char>(3, ' '));
        currentPlayer = 'X';

        bool gameOver = false;

        while (!gameOver) {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << "'s turn.\n";
            cout << "Enter row (1-3) and column (1-3): ";
            cin >> row >> col;

            
            row--; col--;

            if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                if (placeMove(board, row, col, currentPlayer)) {
                    if (checkWin(board, currentPlayer)) {
                        displayBoard(board);
                        cout << "Player " << currentPlayer << " wins!\n";
                        gameOver = true;
                    } else if (checkDraw(board)) {
                        displayBoard(board);
                        cout << "It's a draw!\n";
                        gameOver = true;
                    } else {
                        switchPlayer(currentPlayer);
                    }
                } else {
                    cout << "Cell already occupied. Try again.\n";
                }
            } else {
                cout << "Invalid input. Try again.\n";
            }
        }

        gameRunning = playAgain();
    }

    cout << "Thanks for playing!\n";
    return 0;
}


void displayBoard(const vector<vector<char>>& board) {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << endl;
}


bool placeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}


bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}


void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
