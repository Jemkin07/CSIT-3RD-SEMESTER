#include <stdio.h>
#include <graphics.h>

// Define region codes for Cohen-Sutherland algorithm
#define INSIDE 0 // 0000
#define LEFT 1   // 0001
#define RIGHT 2  // 0010
#define BOTTOM 4 // 0100
#define TOP 8    // 1000

// Function to compute region code for a point (x, y)
int computeCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

// Cohen-Sutherland line clipping algorithm
void cohenSutherland(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int code1, code2;
    int accept = 0, done = 0;

    code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);

    do {
        // If both endpoints lie inside the window
        if (code1 == 0 && code2 == 0) {
            accept = 1;
            done = 1;
        }
        // If both endpoints lie outside the window
        else if (code1 & code2) {
            done = 1;
        }
        // If one of the endpoints is inside the window
        else {
            int x, y;
            int code = code1 ? code1 : code2;

            // Calculate intersection point
            if (code & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            // Update the endpoint
            if (code == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    } while (!done);

    // If line is accepted, draw it
    if (accept) {
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main() {
    printf("Sasank Lama \n");
    int gd = DETECT, gm;
    int xmin, ymin, xmax, ymax;
    int x1, y1, x2, y2;

    printf("Enter the window boundaries (xmin ymin xmax ymax): ");
    scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

    printf("Enter the endpoints of the line (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    initgraph(&gd, &gm, "");

    // Draw the window
    rectangle(xmin, ymin, xmax, ymax);

    // Draw the original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    // Apply Cohen-Sutherland algorithm
    cohenSutherland(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
    getch();
    closegraph();
    return 0;
}
