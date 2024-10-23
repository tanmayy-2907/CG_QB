#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

void drawFlag(int yOffset) {
    // Flag dimensions
    int left = 200, top = 100 + yOffset, right = 400, bottom = 200 + yOffset;
    int i,angle,x,y;
    // Saffron part (top stripe)
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(left, top, right, top + 33);
    floodfill(left + 1, top + 1, RED);

    // White part (middle stripe)
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(left, top + 33, right, top + 66);
    floodfill(left + 1, top + 34, WHITE);

    // Green part (bottom stripe)
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(left, top + 66, right, bottom);
    floodfill(left + 1, top + 67, GREEN);

    // Ashoka Chakra in the middle
    setcolor(BLUE);
    circle(300, top + 50, 15); // Position and radius of the chakra
    for (i = 0; i < 24; i++) {
	 angle = i * 15; // 360 degrees divided by 24 spokes
	 x = 300 + 15 * cos(angle * 3.14 / 180);
	 y = top + 50 + 15 * sin(angle * 3.14 / 180);
        line(300, top + 50, x, y); // Drawing spokes
    }
}

int main() {
    int gd = DETECT, gm;
    int yOffset = 250; // Start flag below the screen
    
    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    // Flagpole
    setcolor(WHITE);
    line(200, 100, 200, 350);

    // Flag hoisting animation
    while (yOffset > 0) {
        cleardevice(); // Clear previous frame

        // Draw flagpole
        setcolor(WHITE);
        line(200, 100, 200, 350);

        // Draw flag at current position
        drawFlag(yOffset);

        delay(50); // Slow down the movement
        yOffset -= 2; // Move the flag up step by step
    }

    // Draw the final position of the flag (fully hoisted)
    drawFlag(0);

    getch();
    closegraph();

    return 0;
}
