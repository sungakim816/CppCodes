#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
char BOARD[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
const int WAY_TO_WIN[8][3] = {
    {0, 1, 2},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6},
    {3, 4, 5},
    {6, 7, 8},
};
const char X_CHAR = 'x';
const char O_CHAR = 'o';
string PLAYER1 = "";
string PLAYER2 = "";
bool FINISH_OR_NOT = false;
void print_board()
{ // for printing the board
    cout << endl;
    cout << endl
         << "                                   |-----|-----|-----|";
    cout << endl
         << "                                   |  " << BOARD[0] << "  |  " << BOARD[1] << "  |  " << BOARD[2] << "  |";
    cout << endl
         << "                                   |-----|-----|-----|";
    cout << endl
         << "                                   |  " << BOARD[3] << "  |  " << BOARD[4] << "  |  " << BOARD[5] << "  |";
    cout << endl
         << "                                   |-----|-----|-----|";
    cout << endl
         << "                                   |  " << BOARD[6] << "  |  " << BOARD[7] << "  |  " << BOARD[8] << "  |";
    cout << endl
         << "                                   |-----|-----|-----|";
    cout << endl
         << endl;
}
void instructions()
{
    cout << "                                       TIC_TAC_TOE " << endl;
    cout << "              Make Your Move Known By Entering a Number from 0 - 8. The Number" << endl;
    cout << "                 Corresponds to the Desired Board Position as illustrated.. " << endl;
    print_board();
    cin.get();
    if (system("cls"))
        system("clear");
}
void check_winner()
{ // for checking if there's a winner
    for (int i = 0; i < 8; ++i)
    {
        if (BOARD[WAY_TO_WIN[i][0]] == BOARD[WAY_TO_WIN[i][1]] && BOARD[WAY_TO_WIN[i][2]] == BOARD[WAY_TO_WIN[i][1]])
        {
            FINISH_OR_NOT = true;
            break;
        }
    }
}
void ask_player_names()
{ // ask for players' names
    cout << "Who Would Be Player No.1, Pls. Enter Your Name: ";
    getline(cin, PLAYER1);
    cout << "Who Would Be Player No.2, Pls. Enter Your Name: ";
    getline(cin, PLAYER2);
    cout << endl
         << "Good Luck to Both Players.";
    cout << endl
         << PLAYER1 << " Will Be Using 'x' while " << PLAYER2 << " Will Be Using 'o'";
}

bool _whose_turn(bool whose_turn)
{
    whose_turn = !whose_turn;
    return whose_turn;
}

int main()
{ //main program
    int MOVE = 0;
    int move_count = 0;
    bool whose_turn = false; // true for player 1 false for player 2
    instructions();
    print_board();
    ask_player_names();
    cout << endl
         << endl;
    for (;;)
    {
        whose_turn = _whose_turn(whose_turn);
        for (;;)
        { //for players move
            if (whose_turn)
            {
                cout << endl
                     << PLAYER1 << "'s"
                     << " Move: ";
                cin >> MOVE;
                if (MOVE < 9 && MOVE > -1 && BOARD[MOVE] != X_CHAR && BOARD[MOVE] != O_CHAR)
                {
                    BOARD[MOVE] = X_CHAR;
                    break;
                }
                else
                    cout << endl
                         << "Invalid Input, Pls Try Again";
            }
            else if (!whose_turn)
            {
                cout << endl
                     << PLAYER2 << "'s"
                     << " Move: ";
                cin >> MOVE;
                if (MOVE < 9 && MOVE > -1 && BOARD[MOVE] != X_CHAR && BOARD[MOVE] != O_CHAR)
                {
                    BOARD[MOVE] = O_CHAR;
                    break;
                }
                else
                    cout << endl
                         << "Invalid Input, Pls Try Again";
            }
        }
        ++move_count;
        print_board();
        check_winner();
        if (FINISH_OR_NOT)
        {
            if (whose_turn == true)
                cout << endl
                     << PLAYER1 << " Wins" << endl;
            else
                cout << endl
                     << PLAYER2 << " Wins" << endl;
            break;
        }
        else if (!FINISH_OR_NOT && move_count == 9)
        {
            cout << endl
                 << "It's a Tie";
            break;
        }
    }
    cout << endl
         << "THANKS FOR PLAYING " << endl;
    return 0;
}
