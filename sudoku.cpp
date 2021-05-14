#include <iostream>
#include <string>

class SudokuSquare
{
    public: 
        int val = 0;
        //array containing a true or false value for all of the sudoku vals 1-9
        bool notes[9];

        SudokuSquare();
};

SudokuSquare::SudokuSquare()
{
    for (bool note : notes)
    {
        note = true; 
    }
}

class Sudoku
{
    public:
        SudokuSquare grid [9][9];
        
        Sudoku();
        Sudoku(int sudoku[9][9]);

        bool is_valid();

        Sudoku solve();

        void draw();
};

Sudoku::Sudoku()
{
    for (int rows = 0; rows < 9; rows++)
    {
        for (int cols = 0; cols < 9; cols++)
        {
            grid[rows][cols].val = 0;
        }
    }
}

Sudoku::Sudoku(int sudoku[9][9])
{
    for (int rows = 0; rows < 9; rows++)
    {
        for (int cols = 0; cols < 9; cols++)
        {
            grid[rows][cols].val = sudoku[rows][cols];
        }
    }
}

bool Sudoku::is_valid()
{
    for (int rows = 0; rows < 9; rows++)
    {
        for (int cols = 0; cols < 9; cols++)
        {
            if (grid[rows][cols].val > 9 || grid[rows][cols].val < 1)
            {
                std::cout << "Invalid sudoku: squares contain values outside 1-9" << std::endl;
                return false;
            }
        }
    }
    return true;
}

void Sudoku::draw()
{
    for (int rows = 0; rows < 9; rows++)
    {
        if (rows == 3 || rows == 6)
        {
            std::cout << "------+-------+------" << std::endl;
        }

        for (int cols = 0; cols < 9; cols++) 
        {
            if (cols == 3 || cols == 6)
            {
                std::cout << "| ";
            } 

            if (grid[rows][cols].val == 0) //if square is empty, leave blank
            {
                std::cout << "  ";
            } else { //if square not empty, write its value
                std::cout << grid[rows][cols].val << " ";
            }
            }
        std::cout << std::endl;
    }
}

int main()
{
    Sudoku demo(
        new int[9][9]{
            {4, 7, 9,    6, 0, 0,    1, 3, 0},
            {5, 0, 8,    0, 1, 9,    7, 6, 0},
            {1, 0, 0,    7, 3, 0,    5, 0, 8},

            {0, 0, 3,    5, 6, 0,    4, 0, 7},
            {2, 5, 0,    0, 9, 0,    0, 0, 3},
            {0, 0, 0,    0, 4, 2,    9, 1, 5},

            {0, 2, 6,    0, 0, 1,    0, 0, 9},
            {0, 0, 0,    0, 0, 6,    0, 0, 0},
            {0, 0, 0,    4, 0, 0,    0, 0, 6}}
    );

    demo.draw();

    return 0;
}