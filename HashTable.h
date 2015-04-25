#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

struct Spot{
    bool x;
    Spot *next;
    int id;
    Spot(){};

    Spot(bool in_x, int in_id)
    {
        x = in_x;
        id = in_id;
    }

};

class HashTable
{
    public:
        HashTable();
        ~HashTable();
        void BuildTable();
        void printGrid();
        void changeSpot(int row, int column);
        void changeRow(int row);
        void changeColumn(int column);
        void checkUp(int row, int column);
        void checkUnder(int row, int column);
        void checkLeft(int row, int column);
        void checkRight(int row, int column);
        bool checkForVictory();


    protected:
    private:
        Spot *hashTable[5];
};

#endif // HASHTABLE_H
