#include <raylib.h>
#include "simulation.hpp"
#include <iostream>

using namespace std;

int main()
{
    /*int PatternNumber;
    cout << "Pick a pattern" << endl;
    int num;
    cout << "1. Glider pattern\n2. Gospel Glider Gun\n3. Glider Gun with eater\n4. Custom" << endl;
    cin >> num;
    PatternNumber = num;*/
    Color GREY = {29, 29, 29, 255};
    const int ScreenWidth = 1700;
    const int ScreenHeight = 1000;
    int CellSize = 15;
    /*if(num == 3){
        CellSize = 12;
    }else if(num == 2){
        CellSize = 15;
    }else{
        CellSize = 21;
    }*/
    int FPS = 20;

    InitWindow(ScreenWidth, ScreenHeight, "Conway's game of life");
    SetTargetFPS(FPS);

    Simulation Simulation(ScreenWidth, ScreenHeight, CellSize);

    /*switch (PatternNumber)
    {
    case 1:
        Simulation.FillPattern({{1, 0, 1}, {2, 1, 1}, {0, 2, 1}, {1, 2, 1}, {2, 2, 1}});
        break;

    case 2:
        Simulation.FillPattern({
            {0, 24, 1},
            {1, 22, 1}, {1, 24, 1},
            {2, 12, 1}, {2, 13, 1}, {2, 20, 1}, {2, 21, 1}, {2, 34, 1}, {2, 35, 1},
            {3, 11, 1}, {3, 15, 1}, {3, 20, 1}, {3, 21, 1}, {3, 34, 1}, {3, 35, 1},
            {4, 0, 1}, {4, 1, 1}, {4, 10, 1}, {4, 16, 1}, {4, 20, 1}, {4, 21, 1},
            {5, 0, 1}, {5, 1, 1}, {5, 10, 1}, {5, 14, 1}, {5, 16, 1}, {5, 17, 1}, {5, 22, 1}, {5, 24, 1},
            {6, 10, 1}, {6, 16, 1}, {6, 24, 1},
            {7, 11, 1}, {7, 15, 1},
            {8, 12, 1}, {8, 13, 1},
        });
        break;

    case 3:
       Simulation.FillPattern({
            {0, 24, 1},
            {1, 22, 1}, {1, 24, 1},
            {2, 12, 1}, {2, 13, 1}, {2, 20, 1}, {2, 21, 1}, {2, 34, 1}, {2, 35, 1},
            {3, 11, 1}, {3, 15, 1}, {3, 20, 1}, {3, 21, 1}, {3, 34, 1}, {3, 35, 1},
            {4, 0, 1}, {4, 1, 1}, {4, 10, 1}, {4, 16, 1}, {4, 20, 1}, {4, 21, 1},
            {5, 0, 1}, {5, 1, 1}, {5, 10, 1}, {5, 14, 1}, {5, 16, 1}, {5, 17, 1}, {5, 22, 1}, {5, 24, 1},
            {6, 10, 1}, {6, 16, 1}, {6, 24, 1},
            {7, 11, 1}, {7, 15, 1},
            {8, 12, 1}, {8, 13, 1},
        });
        break;

    case 4:
        break;

    default:
        break;
    }*/

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            /*Vector2 MousePosition = GetMousePosition();
            int MousePositionX = MousePosition.y/CellSize;
            int MousePositionY = MousePosition.x/CellSize;*/
            int PosX = GetTouchX() / CellSize;
            int PosY = GetTouchY() / CellSize;
            // cout<<PosY/CellSize<<","<<PosX/CellSize<<endl;
            Simulation.ToggleCell(PosY, PosX);
        }
        if (IsKeyPressed(KEY_ENTER))
        {
            Simulation.Start();
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            Simulation.Stop();
        }
        else if (IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_S))
        {
            if (FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }
        else if (IsKeyPressed(KEY_R))
        {
            Simulation.FillRandom();
        }
        else if (IsKeyPressed(KEY_C))
        {
            Simulation.ClearGrid();
        }
        Simulation.Update();
        BeginDrawing();
        ClearBackground(GREY);
        Simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}
