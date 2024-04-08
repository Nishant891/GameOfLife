#include <raylib.h>
#include "grid.hpp"
#include <string>

// Color Gray = {29, 29, 29, 255};

void Grid::Draw()
{

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }

}

void Grid::SetVal(int row, int column, int value)
{
    if (IsValidCell(row, column))
    {
        cells[row][column] = value;
    }
}

void Grid::RandomInitialization(){
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int RandomNumber = GetRandomValue(0,4);
            cells[row][column] = (RandomNumber == 1) ? 1 : 0;
        }
    }
}

void Grid::PatternInitialization(vector<vector<int>> vec){
    for(auto &i: vec){
            SetVal(i[0],i[1],i[2]);
    }
}

void Grid::PlainTextInitialization(string str){
    int row = 20;
    int col = 20;
    for(char c : str){
        if(row < rows && col < columns){
            if(c == 'O'){
                SetVal(row, col, 1);
            }
            if(c == '\n'){
                row++;
                col = 20;
            }else{
                col++;
            }
        }
    }
}

int Grid::GetVal(int row, int column)
{
    if (IsValidCell(row, column))
    {
        return cells[row][column];
    }
    return 0;

}

bool Grid::IsValidCell(int row, int column){

    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        return true;
    }
    return false;

}

void Grid::Clear()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cells[row][column] = 0;
        }
    }
}

void Grid::ToggleCell(int row, int column){

    if (IsValidCell(row, column))
    {
        cells[row][column] = !cells[row][column];
    }

}

/*void Grid::CheckCells()
{

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int count = 0;
            if (row - 1 >= 0)
            {
                if (column - 1 >= 0 && cells[row - 1][column - 1] == 1)
                {
                    count++;
                }
                if (column + 1 < columns && cells[row - 1][column + 1] == 1)
                {
                    count++;
                }
                if (cells[row - 1][column] == 1)
                {
                    count++;
                }
            }
            if (row + 1 < rows)
            {
                if (column - 1 >= 0 && cells[row + 1][column - 1] == 1)
                {
                    count++;
                }
                if (column + 1 < columns && cells[row + 1][column + 1] == 1)
                {
                    count++;
                }
                if (cells[row + 1][column] == 1)
                {
                    count++;
                }
            }
            if (column - 1 >= 0 && cells[row][column - 1] == 1)
            {
                count++;
            }
            if (column + 1 < columns && cells[row][column - 1] == 1)
            {
                count++;
            }


            if(cells[row][column] == 1){
                if(count < 2 || count > 3){
                    nextGen.push_back(make_tuple(row,column,0));
                }else{
                    nextGen.push_back(make_tuple(row,column,1));
                }
            }else{
                if(count == 3){
                    nextGen.push_back(make_tuple(row,column,1));
                }else{
                    nextGen.push_back(make_tuple(row,column,0));
                }
            }
            
        }
    }
}

void Grid::SetCells(){
    for(auto &tuple : nextGen){
        int row, column, value;
        tie(row, column, value) = tuple;
        SetVal(row, column, value);
    }
}*/
