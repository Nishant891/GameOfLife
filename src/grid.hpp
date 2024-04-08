#pragma once
#include <vector>
#include <string>
using namespace std;

class Grid{
    public:
    Grid(int height, int width, int cellSize)
    : rows(width/cellSize), columns(height/cellSize), cellSize(cellSize), cells(rows,vector<int>(columns,0)) {};
    void Draw();
    void SetVal(int row, int column, int value);
    void RandomInitialization();
    void PatternInitialization(vector<vector<int>> vec);
    void PlainTextInitialization(string str);
    void Clear();
    void ToggleCell(int row, int column);
    int GetVal(int row, int column);
    int GetRows(){return rows;};
    int GetColumns(){return columns;};
    bool IsValidCell(int row, int column);
    private:
    int rows;
    int columns;
    int cellSize;
    vector<vector<int>>cells;
};