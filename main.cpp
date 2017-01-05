/* Running file */

// *****************************************************************************
// main.cpp
//
// Summary: Main file.
//
// Author: Nancy Gomez
// Created: 3 Jan 2017
//
// *****************************************************************************

#include "tictactoe.h" // tictactoe game
#include <cstdlib>     // exit_success
using namespace n_tictactoe;

int main() {
    TicTacToe game_on;
    game_on.run();

    return EXIT_SUCCESS;
}
