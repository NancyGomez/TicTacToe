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
//                 - Added the functions fillAcross and fillDiagonal which can be
//                   used so that the cpu can connect any diagonals or row/columns and
//                   stops the user from completing 3 consecutive marks. Also added this
//                   order of priority: win, block, take middle, take corner, next available.
//                   Now the computer is challenging to play against :)
//                   Important TODO: Ties may result in the cpu taking the last turn anyway
//
//
// *****************************************************************************

#include <iostream> // cin, cout
#include <cstdlib>  // size_t
#include <cassert>  // assert
#include <iomanip>  // setw
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
        // Postcondition: Calls the emptyBoard func and the assignMarks func. All other
        //                values are set to a space or 0.
        TicTacToe();

    // *************************** METHODS *********************************

        // Precondition: Takes in no paramaters.
        // Postcondition: Calls the main while loop that runs until the game is over
        //                (defined by the isGameOver func)
        void run();
        //****************************************************************************
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
        // Postcondition: Clears the terminal screen.
        void clearScreen();
        //****************************************************************************
        // Precondition: Takes in no paramaters.
        // Postcondition: Prompts the user for which mark they'd like to choose from.
        //                The cpu takes the left over mark.
        void assignMarks();
        //****************************************************************************
        // Precondition: Takes in no paramaters.
        // Postcondition: Assigns all of the valid indeces to position from the enum
        //                and all odd rows are assigned to dashes whereas all odd
        //                columns are assigned to pipes (to create a board)
        void emptyBoard();

    // *************************** METHODS *********************************

        // Precondition: Takes in no paramaters.
        // Postcondition: Calls the diagonal and across functions on both the user's
        //                mark as well as the cpu's mark to end the game when either
        //                wins or if there's a tie.
        bool isGameOver();
        //****************************************************************************

        // Precondition: Takes in no paramaters.
        // Postcondition: Prompts the user to answer whether they'd like to play again,
        //                if the answer is yes, then it calls the reset function.
        void playAgain();
        //****************************************************************************
        // Precondition: Takes in a mark to look for diagonals with.
        // Postcondition: Since there are only two possible diagonals, checks those
        //                specific cases and if a diagonal is made up of all the same
        //                mark that was passed in, returns true.
        bool checkDiagonal(char mark);
        //****************************************************************************
        // Precondition: Takes in a mark to check for diagonal wins / blocks.
        // Postcondition: It finds where there are two of the mark in a diagonal and if
        //                the missing spot is available, it is filled and returns true.
        //                Otherwise returns false.
        bool fillDiagonal(char mark);
        //****************************************************************************
        // Precondition: Takes in a mark to look for 3 across with.
        // Postcondition: Since there are 3 possible rows and 3 possible columns,
        //                has two seperate loops (one iterates through the row and
        //                the other iterates through the columns). If one is made up
        //                of all the same mark, returns true.
        bool checkAcross(char mark);
        //****************************************************************************
        // Precondition: Takes in a mark to check for cross wins / blocks.
        // Postcondition: If it finds where there are two marks in a row or column and
        //                the missing spot is available, it is filled. (Rows being pri-
        //                oritized). Otherwise returns false.
        bool fillAcross(char mark);
        //****************************************************************************
        // Precondition: Takes in a row, column, and mark.
        // Postcondition: Checks to see whether the spot in is_taken is 'False'
        //                and if it is, then it is marked. is_taken is set to 'True'
        //                and the taken variable is incremented by one.
        void markSpot(unsigned row, unsigned col, char mark);
        //****************************************************************************
        // Precondition: Takes in no paramaters.
        // Postcondition: Checks if any corner values are available (these are key for
        //                easy wins) and claims one then returns true. If no corners
        //                are available, returns false.
        bool availableCorner();
        //****************************************************************************
        // Precondition: Takes in no paramaters.
        // Postcondition: Prints the board and then checks what next move would be best.
        //                The current order is: win, block, middle, corner, next.
        void cpuTurn();
        //****************************************************************************

    };
    #endif
}
