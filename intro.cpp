#include <graphics.h>
#include <iostream>
#include <cstdlib>

using namespace std;

void drawLogo();
void drawGameMenu();

int main()
{
//    initwindow(1280, 720, "H&M Arcade");
	initwindow(1362, 800, "H&M Arcade");
	
    drawLogo();
    drawGameMenu();
    
	while(1) {
	    if(kbhit()) {
	            char ch = getch();
	            if(ch == 'h' || ch == 'H') {
	                cleardevice();
	                settextstyle(3, HORIZ_DIR, 4);
	                outtextxy(300, 100, "Hangman");
	                const char* path="C:\\Users\\LENOVO\\Downloads\\hangman.exe";
	                system(path);
	                //displayLoadingScreen(2);
	                // code
	                break;
	            } else if(ch == 'p' || ch == 'P') {
	                cleardevice();
	                settextstyle(3, HORIZ_DIR, 4);
	                outtextxy(300, 100, "Pacman");
	                const char* path="C:\\Users\\LENOVO\\Downloads\\pacman.exe";
	                system(path);
	                //displayLoadingScreen(2);
	                // code
	                break;
	            } else if(ch == 'e' || ch == 'E') {
	                break;
	            }
	        }
	    }
    closegraph();
    return 0;
}

void drawLogo() {

//HM Text
    settextstyle(3, 0, 10);
    setcolor(RED);

    int x = getmaxx();
    int y = getmaxy();

    int text_width = textwidth("H&M");
    int text_height = textheight("H&M");

    outtextxy((x - text_width) / 2, (y - text_height) / 2, "H&M");	
//Arcade Text
    settextstyle(2, 0, 10);
    setcolor(YELLOW);

    int subtext_width = textwidth("Arcade");
    int subtext_height = textheight("Arcade");

    outtextxy((x - subtext_width) / 2, (y - text_height) / 2 + text_height, "Arcade");

//Corners
    setcolor(RED);
    rectangle(0, y-50, 50, y);
    circle(25, y-25, 10);
    line(25, y-15, 25, y-5);
    line(25, y-5, 30, y-10);
    line(30, y-10, 35, y-5);
    line(35, y-5, 35, y-15);
    line(35, y-15, 30, y-20);
    line(30, y-20, 25, y-15);
    setcolor(YELLOW);
    rectangle(x-50, y-50, x, y);
    circle(x-25, y-25, 10);
    line(x-25, y-15, x-25, y-5);
    line(x-25, y-5, x-30, y-10);
    line(x-30, y-10, x-35, y-5);
    line(x-35, y-5, x-35, y-15);
    line(x-35, y-15, x-30, y-20);
    line(x-30, y-20, x-25, y-15);

// Set font style and color for the loading text
settextstyle(3, 0, 3);
setcolor(WHITE);

// Draw the loading text centered below the subheading
int loading_width = textwidth("Loading...");
int loading_height = textheight("Loading...");
outtextxy((x - loading_width) / 2, (y - text_height) / text_height, "Loading...");

// Draw the circle loader beside the loading text
int loader_radius = 20;
int loader_x = (x - loading_width) / 2 - loader_radius - 10;
int loader_y = (y - text_height) / text_height + subtext_height + (loading_height - 2 * loader_radius) / 2;
for (int i = 0; i <= 360; i += 10) {
    setcolor(WHITE);
    circle(loader_x, loader_y, loader_radius);
    setcolor(BLACK);
    pieslice(loader_x, loader_y, i, i + 7, loader_radius);
    delay(60);
}


    delay(500);
    settextstyle(5, 0, 4);
    setcolor(WHITE);
    outtextxy((x - textwidth("Developed by Harsh & Mann :)")) / 2, y - 100, "Developed by Harsh & Mann :)");
    delay(2000);
}
void drawGameMenu()
{
cleardevice();

// Menu
setcolor(CYAN);
settextstyle(2, 0, 10);
outtextxy(50, 100, "[H] HangMan");
setcolor(GREEN);
outtextxy(50, 250, "[P] Pacman");
//setcolor(YELLOW);
//outtextxy(50, 400, "[P] 2Pac Man");
//setcolor(MAGENTA);
//outtextxy(600, 100, "[T] Tetrizz");
//setcolor(LIGHTGREEN);
//outtextxy(600, 250, "[S] Space Invaders");
setcolor(LIGHTRED);
outtextxy(600, 400, "[E] Exit");

// H&M and Arcade text
settextstyle(3, 0, 10);
setcolor(RED);
int x = getmaxx();
int y = getmaxy();
int text_width = textwidth("H&M");
int text_height = textheight("H&M");
outtextxy(x - text_width - 50, (y - text_height) / 2, "H&M");
settextstyle(2, 0, 10);
setcolor(YELLOW);
int subtext_width = textwidth("Arcade");
int subtext_height = textheight("Arcade");
outtextxy(x - subtext_width - 50, (y - text_height) / 2 + text_height, "Arcade");

}

