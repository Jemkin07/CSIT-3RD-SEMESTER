#include <stdio.h>
#include <graphics.h>

void draw_circle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main() {
    printf("Sasank Lama \n");
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, radius;
    printf("Enter center coordinates (xc yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter radius: ");
    scanf("%d", &radius);

    draw_circle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
