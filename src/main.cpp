#include <raylib.h>
#include "simulation.hpp"
#include <iostream>

using namespace std;

int main()
{
    int PatternNumber;
    cout << "Pick a pattern" << endl;
    int num;
    cout << "1. Demo\n2. Glider pattern\n3. Gospel Glider Gun\n4. Glider Gun with eater\n5. AND Gate\n6. Custom" << endl;
    cin >> num;
    PatternNumber = num;
    Color GREY = {29, 29, 29, 255};
    const int ScreenWidth = 1800;
    const int ScreenHeight = 1000;
    int CellSize = 10;
    if(num == 3 || num == 5){
        CellSize = 12;
    }else if(num == 2){
        CellSize = 15;
    }else{
        CellSize = 21;
    }
    int FPS = 4;

    InitWindow(ScreenWidth, ScreenHeight, "Conway's game of life");
    SetTargetFPS(FPS);

    Simulation Simulation(ScreenWidth, ScreenHeight, CellSize);

    switch (PatternNumber)
    {
    case 1:
        Simulation.FillPattern({{13, 5, 1},
            {13, 13, 1}, {12, 13, 1}, {13, 14, 1}, 
            {12, 22, 1}, {12, 24, 1}, {14, 23, 1}, 
            {13, 32, 1}, {12, 31, 1}, {12, 33, 1}, {14, 31, 1}, {14, 33, 1},
        });
        break;

    case 2:
        Simulation.FillPattern({{1, 0, 1}, {2, 1, 1}, {0, 2, 1}, {1, 2, 1}, {2, 2, 1}});
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
            {28,42,1}, {28,43,1}, {29,42,1}, {29,44,1}, {30,44,1}, {31,44,1}, {31,45,1},
        });
        break;

    case 5:
        Simulation.FillPattern({
        // Glider gun 1
            {0, 24, 1},
            {1, 22, 1}, {1, 24, 1},
            {2, 12, 1}, {2, 13, 1}, {2, 20, 1}, {2, 21, 1}, {2, 34, 1}, {2, 35, 1},
            {3, 11, 1}, {3, 15, 1}, {3, 20, 1}, {3, 21, 1}, {3, 34, 1}, {3, 35, 1},
            {4, 0, 1}, {4, 1, 1}, {4, 10, 1}, {4, 16, 1}, {4, 20, 1}, {4, 21, 1},
            {5, 0, 1}, {5, 1, 1}, {5, 10, 1}, {5, 14, 1}, {5, 16, 1}, {5, 17, 1}, {5, 22, 1}, {5, 24, 1},
            {6, 10, 1}, {6, 16, 1}, {6, 24, 1},
            {7, 11, 1}, {7, 15, 1},
            {8, 12, 1}, {8, 13, 1},

            // Glider gun 2
            {28, 42, 1}, {28, 43, 1}, {29, 42, 1}, {29, 44, 1}, {30, 44, 1}, {31, 44, 1}, {31, 45, 1},

            // Glider gun 3
            {56, 54, 1}, {56, 55, 1}, {57, 53, 1}, {57, 55, 1}, {58, 52, 1}, {58, 53, 1}, {58, 54, 1}, {58, 55, 1},
            {58, 65, 1}, {58, 66, 1}, {59, 52, 1}, {59, 53, 1}, {59, 54, 1}, {59, 55, 1}, {60, 53, 1}, {60, 55, 1},
            {61, 54, 1}, {61, 55, 1},
        });
        break;

    case 6:
        break;

    default:
        break;
    }

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
            SetWindowTitle("Game of life is running.");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            Simulation.Stop();
            SetWindowTitle("Game of life has stopped.");
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
            SetWindowTitle("Random values filled.");
        }
        else if (IsKeyPressed(KEY_C))
        {
            Simulation.ClearGrid();
            SetWindowTitle("Grid is cleared.");
        }
        Simulation.Update();
        BeginDrawing();
        ClearBackground(GREY);
        Simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}
