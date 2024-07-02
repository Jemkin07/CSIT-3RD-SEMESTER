#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

void bezier(int x[], int y[]) {
    int gd = DETECT, gm;
    int i;
    double t;

    initgraph(&gd, &gm, NULL);

    for (t = 0; t <= 1; t += 0.0001) {
        double u = 1 - t;
        double x_pixel = pow(u, 3) * x[0] + 3 * t * pow(u, 2) * x[1] + 3 * pow(t, 2) * u * x[2] + pow(t, 3) * x[3];
        double y_pixel = pow(u, 3) * y[0] + 3 * t * pow(u, 2) * y[1] + 3 * pow(t, 2) * u * y[2] + pow(t, 3) * y[3];
        putpixel((int)x_pixel, (int)y_pixel, WHITE);
    }

   getch();
    closegraph();
}

int main() {
    printf("Sasank Lama \n");
    int x[4], y[4]; // Control points

    printf("Enter the x-coordinates of 4 control points:\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter the y-coordinates of 4 control points:\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &y[i]);
    }

    bezier(x, y);

    return 0;
}
