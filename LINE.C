#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main() {
    int i, gd = DETECT, gm;
    int x0, y0, x1, y1;
    float x, y, dx, dy, steps;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Take user input for the coordinates
    printf("\nEnter X Values (x0 and x1): ");
    scanf("%d %d", &x0, &x1);
    printf("\nEnter Y Values (y0 and y1): ");
    scanf("%d %d", &y0, &y1);

    // Calculate dx, dy, and steps
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);

    if (fabs(dx) >= fabs(dy)) {
        steps = fabs(dx);
    } else {
        steps = fabs(dy);
    }

    // Calculate increments for each step
    dx = dx / steps;
    dy = dy / steps;

    // Initialize starting points
    x = x0;
    y = y0;

    // Draw the dotted line
    for (i = 0; i <= steps; i++) {
        // Check for even/odd condition
        if (i % 2 == 0) {
            putpixel(x, y, RED);  // Plot pixel only if i is even
        }
        x = x + dx;
        y = y + dy;
    }

    // Wait for user input and close the graphics mode
    getch();
    closegraph();

    return 0;
}