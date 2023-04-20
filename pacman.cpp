#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <windows.h>

using namespace std;

void drawPacman(int x, int y) {
    setcolor(YELLOW);
    setfillstyle(1, YELLOW);
    pieslice(x, y, 45, 315, 15);
}

void drawGhost(int x, int y) {

    setcolor(RED);
    setfillstyle(1, RED);
    rectangle(x - 15, y - 15, x + 15, y + 15);
    floodfill(x, y, RED);

    setcolor(WHITE);
    setfillstyle(1, WHITE);
    circle(x - 10, y - 10, 5);
    circle(x + 10, y - 10, 5);
    floodfill(x - 10, y - 10, WHITE);
    floodfill(x + 10, y - 10, WHITE);

    setcolor(BLACK);
    setfillstyle(1, BLACK);
    circle(x - 10, y - 10, 2);
    circle(x + 10, y - 10, 2);
    floodfill(x - 10, y - 10, BLACK);
    floodfill(x + 10, y - 10, BLACK);

    setcolor(BLACK);
    arc(x, y, 45, 135, 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = getmaxx() / 2; // Pac-Man starting x position
    int y = getmaxy() / 2; // Pac-Man starting y position

    int ghostX = 50; // Ghost starting x position
    int ghostY = 50; // Ghost starting y position

    char ch;
    bool gameover = false;

    while (!gameover) {
        cleardevice();
        
        drawPacman(x, y);
        drawGhost(ghostX, ghostY);

        if (kbhit()) {
            ch = getch();
            switch (ch) {
                case 'w':
                    y -= 10;
                    break;
                case 'a':
                    x -= 10;
                    break;
                case 's':
                    y += 10;
                    break;
                case 'd':
                    x += 10;
                    break;
            }
        }

        if (ghostX < x) {
            ghostX += 2;
        } else {
            ghostX -= 2;
        }
        if (ghostY < y) {
            ghostY += 2;
        } else {
            ghostY -= 2;
        }

        if (abs(ghostX - x) <= 15 && abs(ghostY - y) <= 15) {
        	setcolor(YELLOW);
			outtextxy(300, 90, "Game Over");
            gameover = true;
        }


        delay(20);
    }

    closegraph();
    return 0;
}

