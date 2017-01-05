
#include "tictactoe.h"
namespace n_tictactoe {
    // ************************ CONSTRUCTORS *******************************
    TicTacToe::TicTacToe() {
        emptyBoard();
        assignMarks();
        winner_mark = ' ';
        taken = 0;
    }
    // ************************** ACCESSORS ********************************
    void TicTacToe::printBoard() {
        for (unsigned r = 0; r < R; r++){
            for (unsigned c = 0; c < C; c++)
                std::cout << std::setw(2) << board[r][c];
            std::cout << std::endl;
        }
        return;
    }
    // ************************ PUBLIC METHODS ******************************
    void TicTacToe::run() {
        int user_choice;
        while (!isGameOver()) {
            printBoard();
            std::cout << "\nMark where? ";
            std::cin >> user_choice;

            switch (user_choice) {
                case tl:
                    if (is_taken[top][left]) run();
                    markSpot(top, left, user_mark);
                    cpuTurn();
                    break;
                case tm:
                    if (is_taken[top][mid]) run();
                    markSpot(top, mid, user_mark);
                    cpuTurn();
                    break;
                case tr:
                    if (is_taken[top][right]) run();
                    markSpot(top, right, user_mark);
                    cpuTurn();
                    break;
                case ml:
                    if (is_taken[mid][left]) run();
                    markSpot(mid, left, user_mark);
                    cpuTurn();
                    break;
                case mm:
                    if (is_taken[mid][mid]) run();
                    markSpot(mid, mid, user_mark);
                    cpuTurn();
                    break;
                case mr:
                    if (is_taken[mid][right]) run();
                    markSpot(mid, right, user_mark);
                    cpuTurn();
                    break;
                case bl:
                    if (is_taken[bot][left]) run();
                    markSpot(bot, left, user_mark);
                    cpuTurn();
                    break;
                case bm:
                    if (is_taken[bot][mid]) run();
                    markSpot(bot, mid, user_mark);
                    cpuTurn();
                    break;
                case br:
                    if (is_taken[bot][right]) run();
                    markSpot(bot, right, user_mark);
                    cpuTurn();
                    break;
                default: std::cout << "Enter again correctly!\n";
                    break;
            }
        }
    }
    void TicTacToe::reset() {
        *this = TicTacToe();
        this->run();
        return;
    }
    // *************************** HELPERS *********************************
    void TicTacToe::clearScreen() {
        printf( "\033[2J");
        return;
    }
    void TicTacToe::assignMarks() {
        std::cout << "Enter the character of your choice: (X / O): ";
        std::cin >> user_mark;
        user_mark = toupper(user_mark);

        while (user_mark != 'X' && user_mark != 'O') {
            std::cout << "Error! Enter only enter (X / O): ";
            std::cin >> user_mark;
            user_mark = toupper(user_mark);
        }

        if (user_mark == 'X')
            cpu_mark = 'O';
        else
            cpu_mark = 'X';
    }
    void TicTacToe::emptyBoard() {
        for (unsigned r = 0, pos = tl; r < R; r++) {
            for (unsigned c = 0; c < C; c++) {
                // even rows and columns = Valid index
                if (!(r % 2) && !(c % 2)) {
                    board[r][c] = pos + '0';
                    pos++;
                    is_taken[r][c] = False;
                } else if (r % 2) {
                    board[r][c] = '-';
                    is_taken[r][c] = N_A;
                } else {
                    board[r][c] = '|';
                    is_taken[r][c] = N_A;
                }
            }
        }
        return;
    }
    // ************************ PRIVATE METHODS *****************************
    bool TicTacToe::isGameOver() {
        // Checking when the user wins:
        if (checkAcross(user_mark) || checkDiagonal(user_mark)){
            printBoard();
            std::cout << "Congratulations! "; playAgain();
            return true;
        // Checking when the user wins:
    } else if (checkAcross(cpu_mark) || checkDiagonal(cpu_mark)){
            printBoard();
            std::cout << "You lost! "; playAgain();
            return true;
            // otherwise check for a tie (all spots are marked)
        } else if (taken == TOTAL) {
            printBoard();
            std::cout << "Tie! "; playAgain();
            return true;
        }
        return false;
    }
    void TicTacToe::playAgain() {
        char user_choice;
        std::cout << "Play again? (Y/N): ";
        std::cin >> user_choice;
        user_choice = toupper(user_choice);

        while (user_choice != 'Y' && user_choice != 'N') {
            std::cout << "Invalid! Enter (Y/N): ";
            std::cin >> user_choice;
            user_choice = toupper(user_choice);
        }

        if (user_choice == 'Y')
            reset();
        return;
    }
    bool TicTacToe::checkDiagonal(char mark) {
        // diagonal from top left to bot right
        if (mark == board[top][left]
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
    bool TicTacToe::fillDiagonal(char mark) {
        // Checking diagonal
        size_t mark_t_b, mark_r, mark_c,
               top_bot = 0, bot_top = 0;
        bool isTopBot = false, isBotTop = false;
        for (unsigned i = 0, j = R-1; i < R; i+=2, j-=2) {
            // from top left to bot right
            if (board[i][i] == mark)
                top_bot++;
            else if (is_taken[i][i] == False){
                mark_t_b = i;
                isTopBot = true;
            }

            // from bot left to top right
            if (board[j][i] == mark)
                bot_top++;
            else if (is_taken[j][i] == False) {
                mark_r = j; mark_c = i;
                isBotTop = true;
            }
        }
        // if the spot is available and there's 2, complete the diagonal!
        if (top_bot == 2 && isTopBot){
            markSpot(mark_t_b, mark_t_b, cpu_mark);
            return true;
        } else if (bot_top == 2 && isBotTop) {
            markSpot(mark_r, mark_c, cpu_mark);
            return true;
        }
        return false;
    }
    bool TicTacToe::checkAcross(char mark) {
        // check for three in a row
        for (unsigned r = 0; r < R; r+=2)
            if (mark == board[r][left]
                && board[r][left] == board[r][mid]
                && board[r][mid] == board[r][right])
                winner_mark = mark;

        // check for three in a column
        for (unsigned c = 0; c < C; c+=2)
            if (mark == board[top][c]
                && board[top][c] == board[mid][c]
                && board[mid][c] == board[bot][c])
                winner_mark = mark;

        return (winner_mark == mark);
    }
    bool TicTacToe::fillAcross(char mark) {
        // Checking across
        size_t row_r, row_c,
               col_r, col_c;
        for (unsigned r = 0, count_r = 0, count_c = 0; r < R; r+=2){
            bool r_available = false, c_available = false;
            count_r = 0; count_c = 0;
            for (unsigned c = 0; c < C; c+=2){
                // Checking rows
                if (board[r][c] == mark)
                    count_r++;
                else if (is_taken[r][c] == False){
                    row_r = r; row_c = c;
                    r_available = true;
                }
                // Checking columns
                if (board[c][r] == mark)
                    count_c++;
                else if (is_taken[c][r] == False) {
                    col_r = c; col_c = r;
                    c_available = true;
                }
            } // end inner for
            if (count_r == 2 && r_available){
                markSpot(row_r, row_c, cpu_mark);
                return true;
            } else if (count_c == 2 && c_available) {
                markSpot(col_r, col_c, cpu_mark);
                return true;
            }
        }
        return false;
    }
    void TicTacToe::markSpot(unsigned row, unsigned col, char mark) {
        if (!is_taken[row][col]){
            board[row][col] = mark;
            is_taken[row][col] = True;
            taken++;
        } else {
            std::cout << "Spot is taken!\n";
        }
        return;
    }
    bool TicTacToe::availableCorner() {
        if (!is_taken[top][left]) {
            markSpot(top, left, cpu_mark);
            return true;
        } else if (!is_taken[top][right]) {
            markSpot(top, right, cpu_mark);
            return true;
        } else if (!is_taken[bot][left]) {
            markSpot(bot, left, cpu_mark);
            return true;
        } else if (!is_taken[bot][right]) {
            markSpot(bot, right, cpu_mark);
            return true;
        }
        return false;
    }
    void TicTacToe::cpuTurn() {
        printBoard();
        std::cout << "\nMy turn...\n\n";
        // first check if the cpu can win!
        if (fillAcross(cpu_mark) || fillDiagonal(cpu_mark)){
            return;
        // next check if we can stop the user from winning!
        } else if (fillAcross(user_mark) || fillDiagonal(user_mark)){
            return;
        // then, check if the middle is claimable!
        } else if (is_taken[mid][mid] == False) {
            markSpot(mid, mid, cpu_mark);
        // if not, take any corners!
        } else if (availableCorner()) {
            return;
        // otherwise, take what's left :(
        } else {
            for (unsigned r = 0; r < R; r++) {
                for (unsigned c = 0; c < C; c++) {
                    if (!is_taken[r][c]){
                        markSpot(r, c, cpu_mark);
                        return;
                    }
                }
            } // end outter for
        }
        return;
    }

} // end namespace!
