//Hunter Haskins TA: Brett Israelson
//includes
#include <iostream>
#include <HashTable.h>

using namespace std;

//prototyping functions
void printMenu();
bool victory();

//main function for the program
int main()
{
    //the intro game text
    cout<<"Welcome to this grid game!"<<endl;
    cout<<"The object of this game is to make every spot on the grid an 'X'"<<endl;
    cout<<"Every spot on the board will start as an 'O'"<<endl;
    cout<<"Spots are made an x by selecting a spots on the grid, selecting a spot"<<endl;
    cout<<"will change that spot to an x, as well as the spots adjacent to it"<<endl;
    cout<<"Additionally you can change an entire row or column at a time"<<endl;
    cout<<"doing this also changes the spot adjacent to the middle of the row or column"<<endl;
    cout<<"The coordinates of all points on the grid are 0-4. Good luck!"<<endl;

    //initializing the hash table object and other variables
    HashTable game;
    bool playing = true;
    bool startOver;
    bool win;
    int actionChoice;
    int rowChoice;
    int columnChoice;

    //the game loop
    while(playing == true)
    {
        //printing the game menu and getting the player choice of action
        printMenu();
        cin>>actionChoice;
        cin.ignore();
        if(actionChoice == 1)
        {
            //getting the row and column of choice and calling change spot function
            cout<<"Row of spot?"<<endl;
            cin>>rowChoice;
            cout<<"Column of spot?"<<endl;
            cin>>columnChoice;
            game.changeSpot(rowChoice,columnChoice);

            //checking for victory and for if the player wants to play again
            win = game.checkForVictory();
            if (win == true)
            {
                startOver = victory();
                if (startOver == true)
                {
                    game.BuildTable();
                }
                else
                {
                    playing = false;
                }
            }

        }
        else if(actionChoice == 2)
        {
            //getting player's choice of row
            cout<<"Row of spot?"<<endl;
            cin>>rowChoice;
            game.changeRow(rowChoice);

            //checking for victory and for playing again
            win = game.checkForVictory();
            if (win == true)
            {
                startOver = victory();
                if (startOver == true)
                {
                    game.BuildTable();
                }
                else
                {
                    playing = false;
                }
            }
        }
        else if(actionChoice == 3)
        {
            //getting players choice of column
            cout<<"Column of spot?"<<endl;
            cin>>columnChoice;
            game.changeColumn(columnChoice);

            //checking for victory and for playing again
            win = game.checkForVictory();
            if (win == true)
            {
                startOver = victory();
                if (startOver == true)
                {
                    game.BuildTable();
                }
                else
                {
                    playing = false;
                }
            }
        }
        else if(actionChoice == 4)
        {
            //quitting out of the game loop
            cout<<"Goodbye!"<<endl;
            playing = false;
        }
    }

    return 0;
}

//function that prints the menu
void printMenu()
{
    cout<<"~~~~~~~Menu~~~~~~~"<<endl;
    cout<<"1: Change a spot"<<endl;
    cout<<"2: Change a row"<<endl;
    cout<<"3: Change a column"<<endl;
    cout<<"4: Quit"<<endl;
}

//function that prints the victory screen and gets player input for playing again
bool victory()
{
    int check;
    bool playAgain;
    cout<<"CONGRATULATIONS!"<<endl;
    cout<<"You have completed the game!"<<endl;
    cout<<"Play again? Enter 0 for no, and 1 for yes."<<endl;
    cin>>check;
    if (check == 0)
    {
        playAgain = false;
    }
    else
    {
        playAgain = true;
    }
    return playAgain;
}

