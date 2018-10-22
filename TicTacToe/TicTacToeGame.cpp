//
// Created by devansh on 21/10/18.
//

#include "TicTacToeBoard.cpp"

class TicTacToeGame {

private:

    TicTacToeBoard board;
    int size;
    char p1Symbol, p2Symbol;
    string winner;
    bool finished = false;

public:

    TicTacToeGame(int size, char p1Symbol = '1', char p2Symbol = '2')
                    : board(size, p1Symbol, p2Symbol) {

        this->size = board.getSize();
        this->p1Symbol = board.getP1Symbol();
        this->p2Symbol = board.getP2Symbol();
    }

    string getWinner() {
        return winner;
    }

    void displayInstance() {
        board.displayBoard();
    }

    void makeAMove(char player, string pos) {

        int pos1 = pos.at(0) - 97;
        int pos2 = pos.at(1) - 49;

        //Check for valid player
        if (player != p1Symbol && player != p2Symbol)
            throw "Invalid player\n";

        //Check for correct position
        if (pos1 >= size || pos1 < 0 || pos2 >= size || pos2 < 0 )
            throw "Invalid position\n";
        else
            board.setBoardPosition(player, pos1, pos2);
    }

    bool hasFinished() {

        char** boardMatrix = board.getBoardMatrix();
        int p1Count = 0;
        int p2Count = 0;

        //Check combination in rows
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (boardMatrix[i][j] == p1Symbol)
                    p1Count++;
                else if (boardMatrix[i][j] == p2Symbol)
                    p2Count++;
            }
            checkWinner(p1Count, p2Count);
            p1Count = p2Count = 0;
            if (finished)
                return true;
        }

        //Check combination in columns
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (boardMatrix[j][i] == p1Symbol)
                    p1Count++;
                else if (boardMatrix[j][i] == p2Symbol)
                    p2Count++;
            }
            checkWinner(p1Count, p2Count);
            p1Count = p2Count = 0;
            if (finished)
                return true;
        }

        //Check left diagonal
        for (int i = 0; i < size; ++i) {
            if (boardMatrix[i][i] == p1Symbol)
                p1Count++;
            else if (boardMatrix[i][i] == p2Symbol)
                p2Count++;
        }
        checkWinner(p1Count, p2Count);
        if (finished)
            return true;

        //Check right diagonal
        for (int i = (size - 1); i >= 0; --i) {
            if (boardMatrix[i][i] == p1Symbol)
                p1Count++;
            else if (boardMatrix[i][i] == p2Symbol)
                p2Count++;
        }
        checkWinner(p1Count, p2Count);
        return finished;
    }

private:

    void checkWinner(int p1Count, int p2Count) {
        if (p1Count == size) {
            winner = "Player 1";
            finished = true;
            return;
        } else if (p2Count == size){
            winner = "Player 2";
            finished = true;
            return;
        }
    }
};
