#include "../include/grid.h"
#include <iostream>
#include "../include/color.h"

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Principal_Screen()
{
}

// Define the Initialize method to set all the grid values to 0
void Grid::Initialize() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            grid[row][column] = 0;
        }
    }
}


// Define the Print method to print the grid to the console
void Grid::Print() {
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numCols; column++) {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

// Define the GetCellColor method
/*
std::vector<Color> Grid::GetCellColors(){

    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    // It is important to return the colors in the same order as the grid values
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};

}*/


void Grid::Draw(){
    for(int row = 0; row < numRows; row++){
        for(int column = 0; column < numCols; column++){
            int cellValue = grid[row][column];
            DrawRectangle(column*cellSize+11, row*cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }



}

bool Grid::IsCellOutside(int row, int column)
{
   if(row >= 0 && row < numRows && column >= 0 && column < numCols)
   {
       return false;
   }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int row = numRows-1; row >= 0; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        }
        else if( completed > 0){
            MoveRowsDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for(int column = 0; column < numCols; column++){
        if(grid[row][column] == 0){
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int column = 0; column < numCols; column++){
        grid[row][column] = 0;
    }
}

void Grid::MoveRowsDown(int row, int numRows)
{
    for(int column = 0; column < numCols; column++){
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}
