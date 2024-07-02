#include <stdio.h>
#include <graphics.h>

void draw_ellipse(int xc, int yc, int rx, int ry) {
    int x, y, p1, p2;
    x = 0;
    y = ry;
    p1 = ry * ry - rx * rx * ry + 0.25 * rx * rx;

    while (2 * ry * ry * x < 2 * rx * rx * y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0) {
            x++;
            p1 += 2 * ry * ry * x + ry * ry;
        } else {
            x++;
            y--;
            p1 += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
        }
    }

    p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0) {
            y--;
            p2 += -2 * rx * rx * y + rx * rx;
        } else {
            x++;
            y--;
            p2 += 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
    }
}

int main() {
    printf("Sasank Lama \n");
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int xc, yc, rx, ry;
    printf("Enter center coordinates (xc,yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter major radius (rx): ");
    scanf("%d", &rx);
    printf("Enter minor radius (ry): ");
    scanf("%d", &ry);

    draw_ellipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}
