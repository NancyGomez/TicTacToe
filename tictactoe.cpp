/*


*/

#include "tictactoe.h"
namespace n_tictactoe {
    // ************************ CONSTRUCTORS *******************************
    TicTacToe::TicTacToe() {
        emptyBoard();
        user_mark = ' ';
        cpu_mark = ' ';

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
    }

    void TicTacToe::reset() {
        TicTacToe();
    }

    void TicTacToe::emptyBoard() {
        for (unsigned r = 0; r < R; r++) {
            for (unsigned c = 0; c < C; c++) {
                if (r % 2 == 0 && c % 2 == 0)
                    board[r][c] = ' ';
                else if (r % 2)
                    board[r][c] = '-';
                else
                    board[r][c] = '|';
            }
        }
    }
}
