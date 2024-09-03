#pragma once
#include <vector>
#include <raylib.h>

class Grid {
public:
    Grid();
    void Principal_Screen();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int grid[20][10];
    int ClearFullRows();

private:
    //std::vector<Color> GetCellColors();
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowsDown(int row, int numRows);
};