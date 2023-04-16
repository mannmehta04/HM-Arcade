#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <graphics.h>
#include <conio.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initwindow(1200, 700, "Hangman");

    if (graphresult() != 0) {
        cout << "Error initializing graphics." << endl;
        exit(1);
    }

    char words[][50] = {"class", "object", "inheritance", "abstraction", "polymorphism", "encapsulation", "template", "exception", "constructor", "destructor", "virtualfunction", "operatoroverloading", "friendfunction"};
    int numWords = 6;
    srand(time(NULL));  // seed
    int randomIndex = rand() % numWords;
    char word[20];
    strcpy(word, words[randomIndex]);
    
    char display[40];
	for(int i = 0; i < strlen(word)*2-1; i+=2) {
	    display[i] = '_';
	    display[i+1] = ' ';
	}
	display[strlen(word)*2-1] = '\0';



    char guess;
    bool fail=0;
    int i, wrongGuesses = 0, len = strlen(word), hintsLeft = 3;

    settextstyle(10, HORIZ_DIR, 2);
    outtextxy(50, 50, "Welcome to Hangman! Stickman is trying to remain hidden from it's enemies.");
    outtextxy(50, 75, "Guess the words related to Concepts of C++ correctly to keep the stickman hidden.");
    outtextxy(50, 100, "Press any key to guess a letter. You have 6 chances to guess incorrectly.");
    outtextxy(50, 125, "On Incorrect guess, Stickman will be slowly visible. Guess the word before so!");
    outtextxy(50, 150, "Good luck!");

    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(300, 500, display);
    
    settextstyle(10, HORIZ_DIR, 2);
    outtextxy(50, 200, "Press '.' for a hint.");

    while (1) {
        guess = getch();

		if (guess == '.' && hintsLeft > 0) {
            int randIndex;
            do {
                randIndex = rand() % len;
            } while (display[randIndex * 2] != '_');
            
            display[randIndex * 2] = word[randIndex];
            settextstyle(10, HORIZ_DIR, 2);
            hintsLeft--;
            outtextxy(50, 230 + (3 - hintsLeft) * 25, "Hint used!");
            delay(200);
        }
		else if (guess != '.') {
	        bool found = false;
	        for (i = 0; i < len; i++) {
	            if (word[i] == guess) {
	                display[i*2] = guess;
	                found = true;
	            }
	        }
	
	        if (!found) {
	            wrongGuesses++;
	        }
		}

        switch (wrongGuesses) {
		    case 1:
		        circle(750, 250, 50);
		        break;
		    case 2:
		        line(750, 300, 750, 500);
		        break;
		    case 3:
		        line(750, 350, 700, 400);
		        break;
		    case 4:
		        line(750, 350, 800, 400);
		        break;
		    case 5:
		        line(750, 500, 700, 600);
		        break;
		    case 6:
		        line(750, 500, 800, 600);
		        fail = 1;
		        settextstyle(10, HORIZ_DIR, 4);
		        outtextxy(80, 620, "You Failed to Save the Stickman :(");
		        delay(2000);
		        exit(0);
		        break;
		}

        int asterisks = 0;
        for (i = 0; i < len; i++) {
            if (display[i*2] == '_') {
                asterisks++;
            }
        }
        settextstyle(10, HORIZ_DIR, 3);
        outtextxy(300, 500, display);
        
        if (asterisks == 0) {
            break;
        }
    }
    
    if(fail==0){
    	settextstyle(10, HORIZ_DIR, 4);
    	outtextxy(80, 580, "Congratulations, you guessed the word safely!");
		delay(2000);
		exit(0);
	}
    getch();
    closegraph();
    return 0;
}
