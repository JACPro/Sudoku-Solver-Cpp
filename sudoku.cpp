#include <iostream>
#include <string>

enum Line { row, col };

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
    for (bool note : notes) { note = true; }
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
    
    private:
        bool check_squares_valid();
        bool check_line_valid(int rowNo, Line lineType);
        bool check_box_valid(int row, int col);
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

bool Sudoku::check_squares_valid()
{
    for (int rows = 0; rows < 9; rows++)
    {
        for (int cols = 0; cols < 9; cols++)
        {
            if (grid[rows][cols].val > 9 || grid[rows][cols].val < 0)
            {
                std::cout << "Invalid sudoku: squares contain values outside 1-9" << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::check_line_valid(int lineNo, Line lineType)
{
    bool squares[9];
    for (int i = 0; i < 9; i++) { squares[i] = false; }

    for (int count = 0; count < 9; count++)
    {
        int currSquare = (lineType == Line::row ? grid[lineNo][count].val : grid[count][lineNo].val);
        if (currSquare == 0) { continue; } //skip this number if square is empty
        //
        if (squares[currSquare - 1] == true) { 
            std::cout << "Error: " << (lineType == Line::row ? "Row " : "Column ") << lineNo + 1 << " contains duplicate numbers." << std::endl;
            return false; 
        } else { 
            squares[currSquare - 1] = true;
        }
    }

    return true;
}

bool Sudoku::check_box_valid(int r, int c)
{
    bool squares[9];
    for (int i = 0; i < 9; i++) { squares[i] = false; }

    for (int row = r * 3; row < ((r * 3) + 3); row++)
    {
        for (int col = c * 3; col < ((c * 3) + 3); col++)
        {
            int currSquare = grid[row][col].val;
            if (currSquare == 0) { continue; } //skip this number if square is empty

            if (squares[currSquare - 1] == true) {
                return false;
            } else {
                squares[currSquare - 1] = true;
            }
        }
    }
    return true;
}

bool Sudoku::is_valid()
{
    //check each square only contains values 1-9 (0 for empty)
    if (!check_squares_valid()) { return false; }
    
    //check there are no duplicate numbers on each row and each column
    for (int i = 0; i < 9; i++)
    {
        if(!check_line_valid(i, Line::row) || !check_line_valid(i, Line::col))
        {
            return false;
        }
    }
    
    //check there are no duplicate numbers in each of the 3x3 boxes
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (!check_box_valid(row, col))
            {
                std::cout << "Error: Box (Col " << col + 1 << ", Row " << row + 1 << ") contains duplicate numbers." << std::endl;
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
    std::cout << std::endl;
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

    std::cout << (demo.is_valid() ? "True" : "False") << std::endl;

    return 0;
}