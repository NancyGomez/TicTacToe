/* header file */

// *****************************************************************************
// tictactoe.h
//
// Summary: Defines a class that allows the user to launch a Tic Tac Toe game and play
//          against the computer. The user can choose which mark they want to claim and
//          then the user gets to choose whether he/she wants to go first. The game is
//          played until the user wins/loses/ties and they are prompted to answer whether
//          they'd like to play again.
//
// Author: Nancy Gomez
// Created: 3 Jan 2017
// Summary of Modifications:
//      3 Jan 2017 - Added the bare bones as well as the logic for ending the
//                   game. Much is left!
//      4 Jan 2017 - Added some functionality to the skeleton which allows the user to
//                   play. The cpu doesn't make intelligent decisions as of now.
//
//
// *****************************************************************************

#include <iostream> // cin, cout
#include <string>
#include <cstdlib>  // size_t
namespace n_tictactoe {
    // universal and non-changable dimensions
    const static size_t R = 5;
    const static size_t C = 5;
    // total number of mark spots
    const static size_t TOTAL = (C-2) * (R-2);

    #ifndef TICTACTOE_H
    #define TICTACTOE_H

    class TicTacToe {

    public:
    // ************************ CONSTRUCTORS *******************************

        // Precondition: Default constructor, takes in no paramaters.
        // Postcondition: Calls the emptyBoard func and assigns all member variables
        //                to empty spaces.
        TicTacToe();

    // *************************** METHODS *********************************

        // Precondition: Takes in no paramaters.
        // Postcondition: Prompts the user for their choice of the mark, then Calls
        //                the main while loop that runs until the game is over (defined
        //                by the isGameOver func)
        void run();
        // Precondition: Takes in no paramaters.
        // Postcondition: Calls the default constructor to reinstate itself and then Calls
        //                the run function.
        void reset();

    private:
        // To label the is_taken parallel 2D array I need 3 values:
        enum taken_labels {False = 0, True = 1, N_A = 2};
        // To label the indeces more appropriately
        enum spot_labels {top = 0, mid = 2, bot = 4, left = 0, right = 4};
        // to label the positions on the visual
        enum positions {tl = 1, tm = 2, tr = 3,
                        ml = 4, mm = 5, mr = 6,
                        bl = 7, bm = 8, br = 9};

        char board[R][C];
        int is_taken[R][C];

        char user_mark,
             cpu_mark,
             winner_mark;
        size_t taken;


        // ************************** ACCESSORS ********************************

            // Precondition: Takes in no paramaters.
            // Postcondition: Through two nested for loops, prints all the values stored
            //                in the board 2D array which visualizes the board.
            void printBoard();

        // *************************** HELPERS *********************************

            // Precondition: Takes in no paramaters.
            // Postcondition: Calls the diagonal and across functions on both the user's
            //                mark as well as the cpu's mark to end the game when either
            //                wins or if there's a tie.
            bool isGameOver();
            // Precondition: Takes in a mark to look for diagonals with.
            // Postcondition: Since there are only two possible diagonals, checks those
            //                specific cases and if a diagonal is made up of all the same
            //                mark that was passed in, returns true.
            bool diagonal(char mark);
            // Precondition: Takes in a mark to look for 3 across with.
            // Postcondition: Since there are 3 possible rows and 3 possible columns,
            //                has two seperate loops (one iterates through the row and
            //                the other iterates through the columns). If one is made up
            //                of all the same mark, returns true.
            bool across(char mark);
            // Precondition: Takes in a row, column, and mark.
            // Postcondition: Checks to see whether the spot in is_taken is 'False'
            //                and if it is, then it is marked. is_taken is set to 'True'
            //                and the taken variable is incremented by one.
            void markSpot(int row, int col, char mark);
            // Precondition: Takes in no paramaters.
            // Postcondition: For the sake of organization, all the steps necessary for
            //                cpu's Turn are kept here.
            void cpuTurn();
            // Precondition: Takes in no paramaters.
            // Postcondition: Calculates the best spot for the cpu to choose, whether
            //                that means blocking the user's win or winning.
            void cpuCalc();
            // Precondition: Takes in no paramaters.
            // Postcondition: Assigns all of the valid indeces to position from the enum
            //                and all odd rows are assigned to dashes whereas all odd
            //                columns are assigned to pipes (to create a board)
            void emptyBoard();

    };
    #endif
}
