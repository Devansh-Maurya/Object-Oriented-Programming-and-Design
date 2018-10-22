#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//
// Created by devansh on 21/10/18.
//

class TicTacToeBoard {

private:

    int size;
    int rSize;                  //Size reduced by 1
    char p1Symbol, p2Symbol;
    char** boardMatrix;         //Dynamically allocated matrix for board

public:

    TicTacToeBoard(int size, char p1Symbol, char p2Symbol) {
        this->size = size;
        this->p1Symbol = p1Symbol;
        this->p2Symbol = p2Symbol;

        rSize = size-1;

        //Initializing the matrix that is a representation of the board
        boardMatrix = new char*[size];
        for (int i = 0; i < size; ++i)
            boardMatrix[i] = new char[size];

        //Initialize all the positions to ' '(space character)
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                boardMatrix[i][j] = ' ';
    }


    char getP1Symbol() const {
        return p1Symbol;
    }

    char getP2Symbol() const {
        return p2Symbol;
    }

    int getSize() const {
        return size;
    }

    char **getBoardMatrix() const {
        return boardMatrix;
    }

    void displayBoard() {

        displayRepeatedCharacter('\n');
        displayHorizontalPositions();

        displaySpacesWithSeparator();
        displayVerticalPosition(0);
        displayMatrix(0);
        displaySpacesWithSeparator();

        for (int i = 1; i < size; ++i) {
            displaySeparator();
            displaySpacesWithSeparator();
            displayVerticalPosition(i);
            displayMatrix(i);
            displaySpacesWithSeparator();
        }

        displayRepeatedCharacter('\n');
    }

    void setBoardPosition(char player, int pos1, int pos2) {
        boardMatrix[pos1][pos2] = player;
    }


private:

    void displayHorizontalPositions() {

        displayRepeatedCharacter('\t');

        for (int i = 0; i < size; ++i) {
            cout << "   " << (i+1) << "    ";
        }
        cout << "\n\n";
    }

    void displayVerticalPosition(int rowNum) {
        cout << (char) (rowNum + 97) << "\t";
    }

    void displaySpacesWithSeparator() {

        displayRepeatedCharacter('\t');

        for (int i = 0; i < rSize; ++i) {
            cout << "       |";
        }
        cout << "       \n";
    }

    void displaySeparator() {

        displayRepeatedCharacter('\t');

        for (int i = 0; i < rSize; ++i) {
            cout << "-------+";
        }
        cout << "-------\n";
    }

    void displayMatrix(int row) {

        displayRepeatedCharacter('\t', 1);

        int j;
        for (j = 0; j < rSize; ++j) {
            cout << "   " << boardMatrix[row][j] << "   |";
        }
        cout << "   " << boardMatrix[row][j] << "   \n";
    }

    void displayRepeatedCharacter(char character, int num = 2) {
        for (int i = 0; i < num; ++i) {
            cout << character;
        }
    }

};

