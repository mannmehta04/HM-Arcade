#include <graphics.h>
#include <time.h>

#define MAX_OBSTACLES 3
#define GAP_SIZE 150
#define OBSTACLE_SPEED 4
#define BIRD_GRAVITY 1.2
#define BIRD_JUMP_VELOCITY -15

int main()
{
    initwindow(400, 600, "Flappy Bird");

    int score = 0;

    // Bird
    int birdX = 100, birdY = 300, birdSize = 30;
    int birdVelocity = 0;

    // Obstacles
    int obstacles[MAX_OBSTACLES][2] = {
        {500, rand() % 200},
        {700, rand() % 200},
        {900, rand() % 200},
    };
    int obstacleWidth = 60, obstacleHeight = 400;

    while (!kbhit()) {
        cleardevice();

        // Draw bird
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(birdX, birdY, birdSize, birdSize);

        // Draw obstacles
        setfillstyle(SOLID_FILL, GREEN);
        for (int i = 0; i < MAX_OBSTACLES; i++) {
            bar(
                obstacles[i][0], obstacles[i][1],
                obstacles[i][0] + obstacleWidth, obstacles[i][1] + obstacleHeight
            );
            obstacles[i][0] -= OBSTACLE_SPEED;
            if (obstacles[i][0] < -obstacleWidth) {
                obstacles[i][0] = 600;
                obstacles[i][1] = rand() % 200;
            }
            // Check for collision
            if (
                birdX - birdSize < obstacles[i][0] + obstacleWidth &&
                birdX + birdSize > obstacles[i][0] &&
                (birdY - birdSize < obstacles[i][1] ||
                 birdY + birdSize > obstacles[i][1] + GAP_SIZE)
            ) {
                // Collision occurred
                cleardevice();
                outtextxy(150, 200, "Game Over!");
                //outtextxy(150, 250, ("Score: " + std::to_string(score)).c_str());
                delay(2000);
                return 0;
            }
            if (obstacles[i][0] == birdX) {
                score++;
            }
        }

        // Apply gravity to bird
        birdVelocity += BIRD_GRAVITY;
        birdY += birdVelocity;

        // Check for space key
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            birdVelocity = BIRD_JUMP_VELOCITY;
        }

        // Delay and update screen
        delay(30);
        //updategraph();
    }

    return 0;
}

