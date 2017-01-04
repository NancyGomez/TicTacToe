/*






*/
#include <iostream> // cin, cout
#include <string>
#include <cstdlib>  // size_t
namespace n_tictactoe {
    const static size_t R = 5;
    const static size_t C = 5;

    #ifndef TICTACTOE_H
    #define TICTACTOE_H

    class TicTacToe {

    public:
    // ************************ CONSTRUCTORS *******************************
        // Precondition:
        // Postcondition:
        TicTacToe();
    // ************************** ACCESSORS ********************************
        //
        //
        void printBoard();

    // *************************** METHODS *********************************
        // Precondition:
        // Postcondition:
        void run();

        // Precondition:
        // Postcondition:
        void reset();

        // Precondition:
        // Postcondition:
        void emptyBoard();

    private:
        char board[R][C];
        char user_mark,
             cpu_mark;
        size_t available;
        size_t taken;

    };
    #endif
}
