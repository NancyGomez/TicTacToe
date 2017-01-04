/* header file */

// *****************************************************************************
// tictactoe.h
//
// Summary:
//
// Author: Nancy Gomez
// Created: 3 Jan 2017
// Summary of Modifications:
//      3 Jan 2017 - Added the bare bones as well as the logic for ending the
//                   game. Much is left!
//
//
// *****************************************************************************

#include <iostream> // cin, cout
#include <string>
#include <cstdlib>  // size_t
namespace n_tictactoe {
    const static size_t R = 5;
    const static size_t C = 5;

    const static size_t TOTAL = (C-2) * (R-2);

    #ifndef TICTACTOE_H
    #define TICTACTOE_H

    class TicTacToe {

    public:
    // ************************ CONSTRUCTORS *******************************

        // Precondition:
        // Postcondition:
        TicTacToe();

    // ************************** ACCESSORS ********************************

        // Precondition:
        // Postcondition:
        void printBoard();

    // *************************** METHODS *********************************

        // Precondition:
        // Postcondition:
        void run();
        // Precondition:
        // Postcondition:
        void reset();

    // *************************** HELPERS *********************************

        // Precondition:
        // Postcondition:
        bool isGameOver();
        // Precondition:
        // Postcondition:
        bool diagonal(char mark);
        // Precondition:
        // Postcondition:
        bool lines(char mark);
        // Precondition:
        // Postcondition:
        void emptyBoard();

    private:
        // To label the is_taken parallel 2D array I need 3 values:
        enum taken_labels {False = 0, True = 1, N_A = 2};
        // To label the spots on the actual on the visual:
        enum spot_labels {top = 0, mid = 2, bot = 4, left = 0, right = 4};

        char board[R][C];
        int is_taken[R][C];

        char user_mark,
             cpu_mark,
             winner_mark;
        size_t available;
        size_t taken;

    };
    #endif
}
