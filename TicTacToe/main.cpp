#include <iostream>

#include "TicTacToeGame.cpp"

using namespace std;

int main() {

    char player, player1 = '1',  player2 = '2';
    string move;
    bool p1Turn = true;
    int choice;
    TicTacToeGame game(3, player1, player2);

    start:
    cout << "Who will start first (0 : Player 1, 1 : Player 2): ";
    cin >> choice;

    if (!choice)
        p1Turn = true;
    else if (choice == 1)
        p1Turn = false;
    else
        goto start;

    while (true) {

        game.displayInstance();

        if (p1Turn) {
            player = player1;
            cout << "Player 1, ";
        } else {
            player = player2;
            cout << "Player 2, ";
        }

        cout << "make your move: ";
        cin >> move;

        try {
            game.makeAMove(player, move);
        } catch (char const* exception) {
            cout << exception << "\nTry again\n";
            continue;
        }

        if (game.hasFinished())
            break;

        p1Turn = !p1Turn;                  //To change turn
    }

    game.displayInstance();

    if (game.getWinner() == "") {
        cout << "Game ended up in a draw!\n";
        return 0;
    }

    cout << "Game has been won by: " << game.getWinner() << "\n";

    return 0;
}