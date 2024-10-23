#include<stdio.h>
#include<graphics.h>
#include<math.h>

int initialize(int c1, int c2);

int main()
{
	   int x1, y1, x2, y2, dx, dy, s1, s2, p, i, flag = 0, temp;
    int gd = DETECT, gm;
    int dotpattern;
    initgraph(&gd, &gm, "..\\BGI");



    printf("\n Enter The Co-ordinates of first point (x1, y1): ");
    scanf("%d%d", &x1, &y1);

    printf("\n Enter The Co-ordinates of second point (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    dx = abs(x2 - x1);  // Absolute difference in x
    dy = abs(y2 - y1);  // Absolute difference in y

    // Check if the line is steep (dy > dx)
    if (dy > dx) {
	temp = dx;  // Swap dx and dy
	dx = dy;
	dy = temp;
	flag = 1;  // Mark that the slope is steep
    }

    s1 = initialize(x1, x2);  // Determine direction of x increment
    s2 = initialize(y1, y2);  // Determine direction of y increment

    p = 2 * dy - dx;  // Initial decision parameter

    // Main loop for plotting the line

    //tanmay

    for (i = 0; i <= dx; i++) {
    //	putpixel(x1, y1, 15);  // Plot the pixel at (x1, y1)

    putpixel(x1,y1,15);

	if (p < 0) {
	    if (flag == 1) {  // For steep slope
		y1 = y1 + s2;  // Move along y-axis
	    } else {  // For shallow slope
		x1 = x1 + s1;  // Move along x-axis
	    }
	    p = p + 2 * dy;  // Update decision parameter
	} else {
	    x1 = x1 + s1;  // Move in both x and y directions
	    y1 = y1 + s2;
	    p = p + 2 * dy - 2 * dx;  // Update decision parameter


	}delay(1000);
    }

    getch();
    closegraph();
    return 0;
}

// Function to determine the direction (sign) of movement
int initialize(int c1, int c2)
{
    if ((c2 - c1) < 0)
	return -1;  // Negative direction
    else if ((c2 - c1) > 0)
	return 1;  // Positive direction
    else
	return 0;  // No movement along this axis
}