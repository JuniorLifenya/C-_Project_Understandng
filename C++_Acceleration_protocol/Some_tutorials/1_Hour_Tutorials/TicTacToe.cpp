#include <iostream>
#include <string>
using namespace std;

struct BoardSquare
{
    enum E // Enoms values are not constraint to scopes
    {
        x,o,Empty
    };
};  

class Board
{
public:
    int GetWidth(){}
    int GetTotalSquares(){}

    BoardSquare::E GetSquare (int index){}
    void SetSquare(int index, BoardSquare::E square){}
};

class IRuleEngine
{
public:
    virtual BoardSquare::E HasWon(Board& board) == 0;
};

class Game
{
public:
    BoardSquare:: E Run(){}
};

int main()
{
    return 0;
}