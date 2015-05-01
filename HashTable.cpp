#include "HashTable.h"
#include <iostream>

using namespace std;

//constructor
HashTable::HashTable()
{
    //initializing the contents of the array hashTable to be Null
    cout<<"Let the game begin!"<<endl;
    for ( int i = 0; i < 5; i++)
    {
        hashTable[i] = NULL;
    }
    BuildTable();
}

/*
Function Prototype:
void HashTable::BuildTable();

Function description:
This function builds the hash table and initializes all spots on the hash table to have x = false

Example:
HashTable ht;
ht.buildTable();

Precondition:
No preconditions besides a having created a HashTable object

PostCondition:
A 5x5 hash table created with all spots have x = false
*/
void HashTable::BuildTable()
{
    //looping through elements in array and setting x to false
    for (int i = 0; i < 5; i++)
    {
        Spot *newSpot = new Spot(false,0);
        newSpot->next = NULL;
        hashTable[i] = newSpot;

        //creating the linked list for each element in array
        for (int j = 1; j < 5; j++)
        {
            Spot *newSpot2 = new Spot(false,j);
            newSpot2->next = NULL;
            newSpot->next = newSpot2;
            newSpot = newSpot2;
        }
    }
    //printing the grid when finished
    printGrid();
}

/*
Function Prototype:
void HashTable::printGrid();

Function description:
loops through the hash table and prints out o's or x's in a grid which correspond to a spot in the hash table

Example:
HashTable ht;
ht.printGrid();

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
A 5x5 grid of x's and o's displayed in terminal
*/
void HashTable::printGrid()
{
    cout<<"\n";

    //looping through array and doing the corresponding print outs
    for (int i = 0; i < 5; i++)
    {
        cout<<"\t";
        if(hashTable[i]->x == false)
        {
            cout<<"O    ";
        }
        else
        {
            cout<<"X    ";
        }

        //looping through each linked list and doing the corresponding print outs
        Spot *spotTemp = new Spot();
        spotTemp = hashTable[i];
        while(spotTemp->next != NULL)
        {
            spotTemp = spotTemp->next;
            if(spotTemp->x == false)
            {
                cout<<"O    ";
            }
            else
            {
                cout<<"X    ";
            }
        }
        cout<<"\n"<<endl;
        delete spotTemp;
    }
}

/*
Function Prototype:
void HashTable::changeSpot(int, int);

Function description:
changes the spot at the given index in the hash table to the opposite of what it was 'o' or 'x'

Example:
HashTable ht;
ht.changeSpot(3,2);

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
The spot given change and all spots adjacent change if they exist
*/
void HashTable::changeSpot(int row, int column)
{
    //checking for if the entered numbers exist
    if (row < 0 || row > 4 || column < 0 || column > 4)
    {
        cout<<"Spot does not exist"<<endl;
        printGrid();
        return;
    }

    //checking if the changed spot is in the first column
    if (column == 0)
    {
        if (hashTable[row]->x == true)
        {
            hashTable[row]->x = false;
        }
        else
        {
            hashTable[row]->x = true;
        }
    }
    else
    {
        //looping through the linked list if spot was not at the head
        Spot *spotTemp = new Spot();
        spotTemp = hashTable[row];
        while( column != spotTemp->id)
        {
            spotTemp = spotTemp->next;
        }
        if (spotTemp->x == true)
        {
            spotTemp->x = false;
        }
        else
        {
            spotTemp->x = true;
        }
        delete spotTemp;
    }

    //changing adjacent spots and printing the grid
    checkUp( row, column);
    checkLeft( row, column);
    checkRight( row, column);
    checkUnder( row, column);
    printGrid();
}

/*
Function Prototype:
void HashTable::changeRow(int);

Function description:
changes the row at the given index in the hash table to the opposite of what it was 'o' or 'x'
and the spot adjacent to the middle of the row

Example:
HashTable ht;
ht.changeRow(3);

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
The row given change and the two spots adjacent to the middle of the row change if they exist
*/
void HashTable::changeRow(int row)
{
    //checking to see if spot exist
    if (row < 0 || row > 4)
    {
        cout<<"Spot does not exist"<<endl;
        printGrid();
        return;
    }

    //changing first spot in row
    Spot *spotTemp = new Spot();
    spotTemp = hashTable[row];
    if (spotTemp->x == true)
    {
        spotTemp->x = false;
    }
    else
    {
        spotTemp->x = true;
    }

    //looping through and changing the rest of the spots
    while(spotTemp->next != NULL)
    {
        spotTemp = spotTemp->next;
        if (spotTemp->x == true)
        {
            spotTemp->x = false;
        }
        else
        {
            spotTemp->x = true;
        }
    }
    delete spotTemp;
    //changing the spots adjacent to the middle of the row and printing the grid
    checkUp(row, 2);
    checkUnder(row, 2);
    printGrid();
}

/*
Function Prototype:
void HashTable::changeColumn(int);

Function description:
changes the column at the given index in the hash table to the opposite of what it was 'o' or 'x'
and the spot adjacent to the middle of the column

Example:
HashTable ht;
ht.changeColumn(4);

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
The Column given change and the two spots adjacent to the middle of the column change if they exist
*/
void HashTable::changeColumn(int column)
{
    //checking to see if spot exist
    if (column < 0 || column > 4)
    {
        cout<<"Spot does not exist"<<endl;
        printGrid();
        return;
    }

    //looping through and changing the column
    for (int i = 0; i < 5;i++)
    {
        //checking to see if changing column is the first column
        if (column == 0)
        {
            if (hashTable[i]->x == true)
            {
                hashTable[i]->x = false;
            }
            else
            {
                hashTable[i]->x = true;
            }
        }
        else
        {
            //looping though each linked list and finding the column to be changed
            Spot *spotTemp = new Spot();
            spotTemp = hashTable[i];
            while(spotTemp->id != column)
            {
                spotTemp = spotTemp->next;
            }
            if (spotTemp->x == true)
            {
                spotTemp->x = false;
            }
            else
            {
                spotTemp->x = true;
            }
            delete spotTemp;
        }
    }

    //changing spots adjacent to middle of column and printing the grid
    checkLeft( 2, column);
    checkRight( 2, column);
    printGrid();
}

/*
Function Prototype:
void HashTable::checkUp(int,int);

Function description:
check if the spot above the given spot exist and changes its 'x' or 'o' if it does

Example:
HashTable ht;
ht.checkUp(3,1);

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
the spot above the given spot change if it exits
*/
void HashTable::checkUp(int row, int column)
{
    //checking to see if spot exist
    row--;
    if (row == -1)
    {
        return;
    }

    //checking to see if it is the first column
    if (column == 0)
    {
        if (hashTable[row]->x == true)
        {
            hashTable[row]->x = false;
        }
        else
        {
            hashTable[row]->x = true;
        }
    }
    else
    {
        //looping through the linked list and finding the correct spot to change
        Spot *spotTemp = new Spot();
        spotTemp = hashTable[row];
        while( column != spotTemp->id)
        {
            spotTemp = spotTemp->next;
        }
        if (spotTemp->x == true)
        {
            spotTemp->x = false;
        }
        else
        {
            spotTemp->x = true;
        }
        delete spotTemp;
    }
}

/*
Function Prototype:
void HashTable::checkUnder(int,int)

Function description:
check if the spot below the given spot exist and changes its 'x' or 'o' if it does

Example:
HashTable ht;
ht.checkUnder(1,1);

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
the spot below the given spot change if it exits
*/
void HashTable::checkUnder(int row, int column)
{
    //checking to see if spot exist
    row++;
    if (row == 5)
    {
        return;
    }

    //checking to see if spot is in the first column
    if (column == 0)
    {
        if (hashTable[row]->x == true)
        {
            hashTable[row]->x = false;
        }
        else
        {
            hashTable[row]->x = true;
        }
    }
    else
    {
        //looping through the linked list and finding the spot to change
        Spot *spotTemp = new Spot();
        spotTemp = hashTable[row];
        while( column != spotTemp->id)
        {
            spotTemp = spotTemp->next;
        }
        if (spotTemp->x == true)
        {
            spotTemp->x = false;
        }
        else
        {
            spotTemp->x = true;
        }
        delete spotTemp;
    }
}

/*
Function Prototype:
void HashTable::checkLeft(int,int)

Function description:
check if the spot to the left of the given spot exist and changes its 'x' or 'o' if it does

Example:
HashTable ht;
ht.checkLeft(3,4);

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
the spot to the left of the given spot change if it exits
*/
void HashTable::checkLeft(int row, int column)
{
    //checking to see if spot exist
    column--;
    if (column == -1)
    {
        return;
    }

    //checking to see if spot is in the first column
    if (column == 0)
    {
        if (hashTable[row]->x == true)
        {
            hashTable[row]->x = false;
        }
        else
        {
            hashTable[row]->x = true;
        }
    }
    else
    {
        //looping through the linked list and finding the spot to change
        Spot *spotTemp = new Spot();
        spotTemp = hashTable[row];
        while( column != spotTemp->id)
        {
            spotTemp = spotTemp->next;
        }
        if (spotTemp->x == true)
        {
            spotTemp->x = false;
        }
        else
        {
            spotTemp->x = true;
        }
        delete spotTemp;
    }
}

/*
Function Prototype:
void HashTable::checkRight(int,int)

Function description:
check if the spot above the given spot exit and changes its 'x' or 'o' if it does

Example:
HashTable ht;
ht.checkRight(4,2);

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
the spot to the right of the given spot change if it exits
*/
void HashTable::checkRight(int row, int column)
{
    //checking to see if spot exist
    column++;
    if (column == 5)
    {
        return;
    }

    //checking to see if spot is in the first column
    if (column == 0)
    {
        if (hashTable[row]->x == true)
        {
            hashTable[row]->x = false;
        }
        else
        {
            hashTable[row]->x = true;
        }
    }
    else
    {
        //looping through the linked list and finding the spot to change
        Spot *spotTemp = new Spot();
        spotTemp = hashTable[row];
        while( column != spotTemp->id)
        {
            spotTemp = spotTemp->next;
        }
        if (spotTemp->x == true)
        {
            spotTemp->x = false;
        }
        else
        {
            spotTemp->x = true;
        }
        delete spotTemp;
    }
}

/*
Function Prototype:
void HashTable::checkForVictory()

Function description:
checks all spots in the hash table and checks how many x's there are, and if there are 25 then it return true
for the game being complete

Example:
HashTable ht;
ht.checkForVictory();

Precondition:
each spot in the hash table must not be null and have x = either true or false

PostCondition:
true returned if the board is all x's and false if there is any o's in the board
*/
bool HashTable::checkForVictory()
{
    int xCount = 0;
    bool victory = false;
    //looping through the hash table array and counting x's
    for (int i = 0; i < 5; i++)
    {
        if(hashTable[i]->x == false)
        {
            break;
        }
        else
        {
            xCount++;
        }

        //looping through the linked list and counting x's
        Spot *spotTemp = new Spot();
        spotTemp = hashTable[i];
        while(spotTemp->next != NULL)
        {
            spotTemp = spotTemp->next;
            if(spotTemp->x == false)
            {
                break;
            }
            else
            {
                xCount++;
            }
        }
        delete spotTemp;
    }

    //if there are 25 x's, then the board is full and the game is complete
    if (xCount == 25)
    {
        victory = true;
    }
    return victory;
}

//deconstructor
HashTable::~HashTable()
{
    //dtor
}
