#include "../include/block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(){
    std::vector<Position> titles = GetCellPositions();
    for(Position item: titles)
    {
        DrawRectangle(item.column * cellSize + 11, item.row * cellSize+11, cellSize-1, cellSize-1, colors[id]);
    };
}

void Block::Move(int rows, int columns){
    rowOffset += rows;
    columnOffset += columns;
};

std::vector<Position> Block::GetCellPositions(){
    std::vector<Position> titles = cells[rotationState];
    std::vector<Position> movedTitles;
    for(Position item: titles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTitles.push_back(newPos);
    };
    return movedTitles;

};
void Block::Rotate() {
    rotationState ++;
    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }
}
void Block::UndoRotation() {
    rotationState --;
    if(rotationState == - 1){
        rotationState = (int)cells.size() - 1;
    }
};