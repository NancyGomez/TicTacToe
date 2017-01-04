
#include "tictactoe.h"
namespace n_tictactoe {
    // ************************ CONSTRUCTORS *******************************
    TicTacToe::TicTacToe() {
        emptyBoard();
        user_mark = ' ';
        cpu_mark = ' ';
        winner_mark = ' ';
        available = TOTAL;
        taken = 0;

    }
    // ************************** ACCESSORS ********************************
    void TicTacToe::printBoard() {
        for (unsigned r = 0; r < R; r++){
            for (unsigned c = 0; c < C; c++)
                std::cout << board[r][c];
            std::cout << std::endl;
        }
    }

    // *************************** METHODS *********************************
    void TicTacToe::run() {
        std::cout << "Enter the character of your choice: (X / O): ";
        std::cin >> user_mark;

        while (user_mark != 'X' && user_mark != 'O') {
            std::cout << "Error! Enter only enter (X / O): ";
            std::cin >> user_mark;
        }
        if (user_mark == 'X')
            cpu_mark = 'O';
        else
            cpu_mark = 'X';

        while (!isGameOver()) {

        }
    }

    void TicTacToe::reset() {
        TicTacToe();
    }
    bool TicTacToe::isGameOver() {
        // Checking when the user wins:
        if (lines(user_mark) || diagonal(user_mark))
            return true; // TODO: make a special function to print the win

        // Checking when the cpu wins:
        else if (lines(cpu_mark) || diagonal(cpu_mark))
            return true; // TODO: make a special function to print the loss

        // otherwise check for a tie (all spots are marked)
        else (taken == TOTAL);  // TODO: make a special function to print the tie
    }
    bool TicTacToe::diagonal(char mark) {
        // diagonal from top left to bot right
        if (mark == board[top][right]
            && board[top][left] == board[mid][mid]
            && board[mid][mid] == board[bot][right])
            winner_mark = mark;
        // diagonal from top right to bot left
        else if (mark == board[top][right]
            && board[top][right] == board[mid][mid]
            && board[mid][mid] == board[bot][left])
            winner_mark = mark;
        return (winner_mark == mark);
    }

    bool TicTacToe::lines(char mark) {
        // check for three in a row
        for (unsigned r = 0; r < R; r+=2)
            if (mark == board[r][left]
                && board[r][left] == board[r][mid]
                && board[r][mid] == board[r][right])
                winner_mark = mark;

        // check for three in a column
        for (unsigned c = 0; c < C; c++)
            if (mark == board[top][c]
                && board[top][c] == board[mid][c]
                && board[mid][c] == board[bot][c])
                winner_mark = mark;

        return (winner_mark == mark);
    }
    void TicTacToe::emptyBoard() {
        for (unsigned r = 0; r < R; r++) {
            for (unsigned c = 0; c < C; c++) {
                if (r % 2 == 0 && c % 2 == 0){
                    board[r][c] = ' ';
                    is_taken[r][c] = False;
                } else if (r % 2){
                    board[r][c] = '-';
                    is_taken[r][c] = N_A;
                } else{
                    board[r][c] = '|';
                    is_taken[r][c] = N_A;
                }
            }
        }
        return;
    }

} // end namespace!
