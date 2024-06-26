#include "grid.hpp"
#include <string>

class Simulation{
    public:
        Simulation(int height, int width, int cellSize) : grid(height, width, cellSize), tempGrid(height, width, cellSize){};
        void Draw();
        void SetCellVal(int row, int column, int value);
        void Update();
        void Start(){run = true;};
        void Stop(){run = false;};
        void FillRandom();
        void FillPlainText(string str, int offsetX, int offsetY);
        void ClearGrid();
        void ToggleCell(int row, int column);
        int CountLiveNeighbors(int row, int column);
        bool IsRunning(){return run;};
        //void CheckCells();
        //void ResetGraph();
    private:
    Grid grid;
    Grid tempGrid;
    bool run = false;
    //vector<vector<int>> vec;
};