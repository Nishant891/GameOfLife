#include <iostream>
#include <vector>
#include <utility>
#include "simulation.hpp"
#include <string>

using namespace std;

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellVal(int row, int column, int value)
{
    grid.SetVal(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int liveNeighbors = 0;
    vector<pair<int, int>> NeighborsOffset = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (auto &i : NeighborsOffset)
    {
        //int neighborRow = (row + i.first + grid.GetRows()) % grid.GetRows();
        //int neighborColumn = (column + i.second + grid.GetColumns()) % grid.GetColumns();

        int neighborRow = (row + i.first);
        int neighborColumn = (column + i.second);

        liveNeighbors += grid.GetVal(neighborRow, neighborColumn);
    }

    return liveNeighbors;
}

void Simulation::Update()
{
    if (IsRunning())
    {
        int rows = grid.GetRows();
        int columns = grid.GetColumns();

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                int liveNeighbors = CountLiveNeighbors(row, column);
                int CellValue = grid.GetVal(row,column);
                if(CellValue == 1){
                    if (liveNeighbors < 2 || liveNeighbors > 3)
                    {
                        tempGrid.SetVal(row,column,0);
                    }else
                    {
                        tempGrid.SetVal(row,column,1);
                    }
                }
                else
                {
                    if (liveNeighbors == 3)
                    {
                        tempGrid.SetVal(row,column,1);
                    }else
                    {
                        tempGrid.SetVal(row,column,0);
                    }
                }
            }
        }
        grid = tempGrid;
    }
}

/*void Simulation::CheckCells()
{
    if (IsRunning())
    {
        int rows = Grid.GetRows();
        int columns = Grid.GetColumns();

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                int liveNeighbors = CountLiveNeighbors(row, column);
                if (liveNeighbors < 2 || liveNeighbors > 3)
                {
                    vector<int> newVec = {row, column, 0};
                    vec.push_back(newVec);
                }
                else if (liveNeighbors == 3)
                {
                    vector<int> newVec = {row, column, 1};
                    vec.push_back(newVec);
                }
            }
        }
        ResetGraph();
    }
}

void Simulation::ResetGraph()
{
    for (auto &i : vec)
    {
        //cout<<"("<<i[0]<<","<<i[1]<<","<<i[2]<<")"<<endl;
        SetCellVal(i[0], i[1], i[2]);
    }
    vec.empty();
}*/

void Simulation::FillRandom()
{
    if(!IsRunning()){
        grid.RandomInitialization();
    }
}

void Simulation::FillPattern(vector<vector<int>> vec)
{
    if(!IsRunning()){
        grid.PatternInitialization(vec);
    }
}

void Simulation::FillPlainText(string str)
{
    if(!IsRunning()){
        grid.PlainTextInitialization(str);
    }
}

void Simulation::ClearGrid()
{
    if(!IsRunning()){
        grid.Clear();
    }

}

void Simulation::ToggleCell(int row, int column)
{
    if(!IsRunning()){
        grid.ToggleCell(row, column);
    }

}