#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void drawCircle(int xctr, int yctr, int r, int thickness);
void plotCircle(int xctr, int yctr, int r);
void plotCirclePoints(int xctr, int yctr, int x, int y);
int main() {
    int gd = DETECT, gm;
    int x1, y1, r, thickness;

    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    printf("\nEnter Centre Coordinates: ");
    scanf("%d %d", &x1, &y1);

    printf("\nEnter Radius of Circle: ");
    scanf("%d", &r);

    printf("\nEnter Thickness of Circle: ");
    scanf("%d", &thickness);

    drawCircle(x1, y1, r, thickness);

    getch();
    closegraph();
    return 0;
}

void drawCircle(int xctr, int yctr, int r, int thickness) {
    // Draw multiple circles to create a thick appearance
    int t;
    for (t = 0; t < thickness; t++) {
	plotCircle(xctr, yctr, r + t);
	 // Draw outer circles based on thickness
    }
}

void plotCircle(int xctr, int yctr, int r) {
    int x, y, p;

    x = 0;
    y = r;
    p = 1 - r;

    // Plot initial points
    plotCirclePoints(xctr, yctr, x, y);

    while (x < y) {
	x++;
	if (p < 0) {
	    p = p + 2 * x + 1;
	} else {
	    y--;
	    p = p + 2 * (x - y) + 1;
	}
	// Plot circle points
	plotCirclePoints(xctr, yctr, x, y);
    }
}

void plotCirclePoints(int xctr, int yctr, int x, int y) {
    // Plot points around the circumference of the circle
    putpixel(xctr + x, yctr + y, WHITE);
    putpixel(xctr - x, yctr + y, WHITE);
    putpixel(xctr + x, yctr - y, WHITE);
    putpixel(xctr - x, yctr - y, WHITE);
    putpixel(xctr + y, yctr + x, WHITE);
    putpixel(xctr - y, yctr + x, WHITE);
    putpixel(xctr + y, yctr - x, WHITE);
    putpixel(xctr - y, yctr - x, WHITE);

    delay(0);

}
