#include <raylib.h>
#include "simulation.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Color GREY = {29, 29, 29, 255};
    const int ScreenWidth = 1800;
    const int ScreenHeight = 1000;
    int CellSize = 14;
    int FPS = 16;

    InitWindow(ScreenWidth, ScreenHeight, "Conway's game of life");
    SetTargetFPS(FPS);

    Simulation Simulation(ScreenWidth, ScreenHeight, CellSize);

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            int PosX = GetTouchX() / CellSize;
            int PosY = GetTouchY() / CellSize;
            Simulation.ToggleCell(PosY, PosX);
        }
        if (IsKeyPressed(KEY_ENTER))
        {
            Simulation.Start();
            SetWindowTitle("Simulation Started.");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            Simulation.Stop();
            SetWindowTitle("Simulation Stopped.");
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
        else if (IsKeyPressed(KEY_ONE))
        {
            //Glider
            Simulation.FillPlainText(
                ".O.\n"
                "..O\n"
                "OOO\n",
                20,
                20
            );
            SetWindowTitle("Glider is running.");
        }
        else if (IsKeyPressed(KEY_TWO))
        {
            //Glider Period 30
            Simulation.FillPlainText(
                "........................O...........\n"
                "......................O.O...........\n"
                "............OO......OO............OO\n"
                "...........O...O....OO............OO\n"
                "OO........O.....O...OO..............\n"
                "OO........O...O.OO....O.O...........\n"
                "..........O.....O.......O...........\n"
                "...........O...O....................\n"
                "............OO......................\n",
                20,
                20
            );
            SetWindowTitle("Gospel glider gun period 30 is running.");
        }
        else if (IsKeyPressed(KEY_THREE))
        {
            //Glider Period 60
            Simulation.FillPlainText(
                "............................O..........\n"
                "............................O.O........\n"
                "...........OO..................OO......\n"
                ".........O...O.................OO....OO\n"
                "...OO...O.....O................OO....OO\n"
                "...OO..OO.O...O.............O.O........\n"
                "........O.....O.............O..........\n"
                ".........O...O.........................\n"
                "...........OO..........................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                ".......................................\n"
                "..........O.O..........................\n"
                ".........O..O...OO.....................\n"
                "OO......OO.....OOO.OO..OO..............\n"
                "OO....OO...O...O...O...O.O.............\n"
                "........OO.....O.O........O............\n"
                ".........O..O..OO......O..O............\n"
                "..........O.O.............O............\n"
                ".......................O.O.......OO....\n"
                ".......................OO........O.O...\n"
                "...................................O...\n"
                "...................................OO..\n",
                20,
                20
            );
            SetWindowTitle("Gospel glider gun period 60 is running.");
        }
        else if (IsKeyPressed(KEY_FOUR))
        {
            //Glider Gun with eater
            Simulation.FillPlainText(
               "........................O..........................\n"
               "......................O.O..........................\n"
               "............OO......OO............OO...............\n"
               "...........O...O....OO............OO...............\n"
               "OO........O.....O...OO.............................\n"
               "OO........O...O.OO....O.O..........................\n"
               "..........O.....O.......O..........................\n"
               "...........O...O...................................\n"
               "............OO.....................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "..........................................OO.......\n"
               "..........................................O.O......\n"
               "............................................O......\n"
               "............................................OO.....\n"
               "...................................................\n"
               "...................................................\n",
                20,
                20
            );
            SetWindowTitle("Gospel glider gun eater is running.");
        }
        else if (IsKeyPressed(KEY_FIVE))
        {
            //Glider Gun and Glider Gun with Eater
            Simulation.FillPlainText(
               "........................O..........................\n"
               "......................O.O..........................\n"
               "............OO......OO............OO...............\n"
               "...........O...O....OO............OO...............\n"
               "OO........O.....O...OO.............................\n"
               "OO........O...O.OO....O.O..........................\n"
               "..........O.....O.......O..........................\n"
               "...........O...O...................................\n"
               "............OO.....................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "..........................................OO.......\n"
               "..........................................O.O......\n"
               "............................................O......\n"
               "............................................OO.....\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n"
               "........................O..........................\n"
               "......................O.O..........................\n"
               "............OO......OO............OO...............\n"
               "...........O...O....OO............OO...............\n"
               "OO........O.....O...OO.............................\n"
               "OO........O...O.OO....O.O..........................\n"
               "..........O.....O.......O..........................\n"
               "...........O...O...................................\n"
               "............OO.....................................\n"
               "...................................................\n"
               "...................................................\n"
               "...................................................\n",
                6,
                20
            );
        }
        Simulation.Update();
        BeginDrawing();
        ClearBackground(GREY);
        Simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}
