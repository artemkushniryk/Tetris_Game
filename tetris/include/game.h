#pragma once
#include "../include/grid.h"
#include "../src/blocks.cpp"
#include <vector>

class Game {
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    Grid grid;
    bool gameOver;

private:
    void RotateBlock();
    void LockBlock();
    void Reset();
    bool IsBlockOutside();
    bool BlockFits();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};