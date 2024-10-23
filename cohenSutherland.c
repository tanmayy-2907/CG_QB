#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#define TOP    8 // 1000
#define BOTTOM 4 // 0100
#define RIGHT  2 // 0010
#define LEFT   1 // 0001

// Function to compute the region code for a point (x, y)
int computeCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = 0;
    
    if (x < xmin)      // to the left of rectangle
        code |= LEFT;
    else if (x > xmax) // to the right of rectangle
        code |= RIGHT;
    if (y < ymin)      // below the rectangle
        code |= BOTTOM;
    else if (y > ymax) // above the rectangle
        code |= TOP;

    return code;
}

// Cohen-Sutherland line clipping algorithm
void cohenSutherlandClip(int x0, int y0, int x1, int y1, int xmin, int ymin, int xmax, int ymax) {
    int code0 = computeCode(x0, y0, xmin, ymin, xmax, ymax);
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int accept = 0;

    while (1) {
        if ((code0 == 0) && (code1 == 0)) {
            // Both points inside the rectangle
            accept = 1;
            break;
        } else if (code0 & code1) {
            // Both points outside the rectangle, and not within the same region
            break;
        } else {
            // Some portion of the line segment is within the rectangle
            int codeOut;
            float x, y;

            // Choose one of the points outside the rectangle
            if (code0 != 0)
                codeOut = code0; // code0 is outside
            else
                codeOut = code1; // code1 is outside

            // Now find the intersection point;
            // Note: using the left edge of the rectangle as an example
            if (codeOut & TOP) { // point is above the clip rectangle
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            } else if (codeOut & BOTTOM) { // point is below the clip rectangle
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            } else if (codeOut & RIGHT) { // point is to the right of clip rectangle
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            } else if (codeOut & LEFT) { // point is to the left of clip rectangle
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            // Now intersection point x, y is found
            // Replace point outside rectangle with intersection point
            if (codeOut == code0) {
                x0 = x;
                y0 = y;
                code0 = computeCode(x0, y0, xmin, ymin, xmax, ymax);
            } else {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        // Draw the accepted line
        setcolor(GREEN);
        line(x0, y0, x1, y1);
    }
}

// Main function
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xmin = 100, ymin = 100, xmax = 400, ymax = 400;
    // Draw the clipping rectangle
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Sample line coordinates
    int x0 = 50, y0 = 50, x1 = 450, y1 = 450;

    // Draw the original line
    setcolor(RED);
    line(x0, y0, x1, y1);

    // Perform Cohen-Sutherland clipping
    cohenSutherlandClip(x0, y0, x1, y1, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}
