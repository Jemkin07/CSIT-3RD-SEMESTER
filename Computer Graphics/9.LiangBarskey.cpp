#include <stdio.h>
#include <graphics.h>
// Liang-Barsky line clipping algorithm
void liangBarsky(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int p[4], q[4];
    float u1 = 0, u2 = 1;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int xdelta = xmin - x1;
    int ydelta = ymin - y1;
    p[0] = -dx;  p[1] = dx;  p[2] = -dy;  p[3] = dy;
    q[0] = xdelta;  q[1] = xmax - x1;  q[2] = ydelta;  q[3] = ymax - y1;
    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0)
                return; // Line is parallel to clipping boundary and outside
        } else {
            float u = (float)q[i] / p[i];
            if (p[i] < 0 && u > u1)
                u1 = u;
            else if (p[i] > 0 && u < u2)
                u2 = u;
        }
    }

    if (u1 < u2) {
        int x1_clip = x1 + u1 * dx;
        int y1_clip = y1 + u1 * dy;
        int x2_clip = x1 + u2 * dx;
        int y2_clip = y1 + u2 * dy;

        setcolor(WHITE);
        line(x1_clip, y1_clip, x2_clip, y2_clip);
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
    // Apply Liang-Barsky algorithm
    liangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
    getch();
    closegraph();

    return 0;
}
