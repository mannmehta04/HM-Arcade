#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<cstring>

using namespace std;

int main()
{
    initwindow(800, 800, "Hangman Game");
    char word[20] = "programming";  // change to char array
    char display[20] = {'*','*','*','*','*','*','*','*','*','*','\0'};
    char guess;
    int i, wrongGuesses = 0;

    // draw initial blank spaces
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(300, 500, display);

    while (1) {
        guess = getch();

        // check if guessed letter is in word
        for (i = 0; i < strlen(word); i++) {
            if (word[i] == guess) {
                display[i] = guess;
            }
        }

        // increment wrongGuesses if guess is wrong
        if (strstr(display, "*")) {
            wrongGuesses++;
        }

        // display hangman image based on number of wrong guesses
        switch (wrongGuesses) {
            case 1:
                circle(550, 250, 50);
                break;
            case 2:
                line(550, 300, 550, 500);
                break;
            case 3:
                line(550, 350, 500, 400);
                break;
            case 4:
                line(550, 350, 600, 400);
                break;
            case 5:
                line(550, 500, 500, 600);
                break;
            case 6:
                line(550, 500, 600, 600);
                break;
        }

        // display current guess status
        settextstyle(10, HORIZ_DIR, 3);
        outtextxy(300, 500, display);

        // if all letters guessed, exit loop
        if (!strstr(display, "*")) {
            break;
        }
    }

    // display message
    settextstyle(10, HORIZ_DIR, 4);
    outtextxy(250, 100, "Congratulations, you guessed the word!");
    getch();
    closegraph();
    return 0;
}

