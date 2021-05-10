#include <iostream>
#include <string>

class Sudoku
{
    public:
        int grid [3][3];
        
        Sudoku();
        Sudoku(int sudoku[3][3]){};

        static bool is_valid(Sudoku sudoku);
};

Sudoku::Sudoku()
{
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
        {
            grid[rows][cols] = 0;
        }
    }
}

Sudoku::Sudoku(int sudoku[3][3])
{

}

bool Sudoku::is_valid(Sudoku sudoku)
{
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
        {
            if (sudoku.grid[rows][cols] > 9 || sudoku.grid[rows][cols] < 1)
            {
                std::cout << "Invalid sudoku: squares contain values outside 1-9" << endl;
                return false;
            }
        }
    }
}

int main()
{
    return 0;
}