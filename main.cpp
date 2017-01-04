/*

*/

#include "tictactoe.h"
using namespace n_tictactoe;

int main() {
    TicTacToe game_on;
    game_on.printBoard();
    game_on.run();
    game_on.reset();
    game_on.printBoard();

    return EXIT_SUCCESS;
}
