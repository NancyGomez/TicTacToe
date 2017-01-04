
#include "tictactoe.h"
namespace n_tictactoe {
    // ************************ CONSTRUCTORS *******************************
    TicTacToe::TicTacToe() {
        emptyBoard();
        user_mark = ' ';
        cpu_mark = ' ';
        winner_mark = ' ';
        taken = 0;

    }
    // ************************** ACCESSORS ********************************
    void TicTacToe::printBoard() {
        for (unsigned r = 0; r < R; r++){
            for (unsigned c = 0; c < C; c++)
                std::cout << board[r][c];
            std::cout << std::endl;
        }
        return;
    }

    // *************************** METHODS *********************************
    void TicTacToe::run() {
        int user_choice;

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
            printBoard();
            std::cout << "\nMark where? ";
            std::cin >> user_choice;

            switch (user_choice) {
                case tl:
                    markSpot(top, left, user_mark);
                    cpuTurn();
                    break;
                case tm:
                    markSpot(top, mid, user_mark);
                    cpuTurn();
                    break;
                case tr:
                    markSpot(top, right, user_mark);
                    cpuTurn();
                    break;
                case ml:
                    markSpot(mid, left, user_mark);
                    cpuTurn();
                    break;
                case mm:
                    markSpot(mid, mid, user_mark);
                    cpuTurn();
                    break;
                case mr:
                    markSpot(mid, right, user_mark);
                    cpuTurn();
                    break;
                case bl:
                    markSpot(bot, left, user_mark);
                    cpuTurn();
                    break;
                case bm:
                    markSpot(bot, mid, user_mark);
                    cpuTurn();
                    break;
                case br:
                    markSpot(bot, right, user_mark);
                    cpuTurn();
                    break;
                default: std::cout << "Enter again!\n";
                    break;
            }
        }
    }
    void TicTacToe::reset() {
        TicTacToe();
        return;
    }
    bool TicTacToe::isGameOver() {
        // Checking when the user wins:
        if (across(user_mark) || diagonal(user_mark)){
            printBoard(); std::cout << "Congratulations you won!\n";
            return true;
        // Checking when the cpu wins:
        } else if (across(cpu_mark) || diagonal(cpu_mark)){
            printBoard(); std::cout << "Try again?\n";
            return true;
        // otherwise check for a tie (all spots are marked)
        } else if (taken == TOTAL) {
            std::cout << "Tie!\n";
            return true;
        }
        return false;
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

    bool TicTacToe::across(char mark) {
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
    void TicTacToe::markSpot(int row, int col, char mark) {
        if (is_taken[row][col] == False){
            board[row][col] = mark;
            is_taken[row][col] = True;
            taken++;
        } else
            std::cout << "Spot is taken!\n";
        return;
    }
    void TicTacToe::cpuTurn() {
        printBoard();
        std::cout << "\nMy turn...\n\n";
        cpuCalc();
    }
    void TicTacToe::cpuCalc() {
        // Temporarily just letting the cpu enter a value in the next available Spot
        for (unsigned r = 0; r < R; r++) {
            for (unsigned c = 0; c < C; c++) {
                if (is_taken[r][c] == False){
                    board[r][c] = cpu_mark;
                    is_taken[r][c] = True;
                    taken++;
                    return;
                }
            }
        }
        // must check for potential user wins in order to block

        // otherwise check own positions to try and wins
    }
    void TicTacToe::emptyBoard() {
        for (unsigned r = 0, pos = tl; r < R; r++) {
            for (unsigned c = 0; c < C; c++) {
                // even rows and columns = Valid index
                if (!(r % 2) && !(c % 2)){
                    board[r][c] = pos + '0';
                    pos++;
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
