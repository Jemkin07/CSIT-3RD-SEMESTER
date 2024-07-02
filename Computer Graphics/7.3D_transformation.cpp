#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
int translation(int n, int tn) {
    return (n + tn);}
int scalar(int k, int n) {
    return (k * n);}
int main() {
    int gd = DETECT, gm, left, right, bottom, top, depth, k;
    initgraph(&gd, &gm, "");
    printf("Sasank Lama\n");
    printf("Enter the coordinates of cube (left, top, right, bottom): ");
    scanf("%d %d %d %d", &left, &top, &right, &bottom);
    depth = fabs(right - left) / 2;
    bar3d(left, top, right, bottom, depth, 1);
    printf("1. Translation\n2. Scaling\n");
    printf("Enter one of the options: ");
    scanf("%d", &k);
    switch (k) {
        case 1:
            printf("Enter the x-translating factor: ");
            scanf("%d", &k);
            left = translation(left, k);
            right = translation(right, k);
            printf("Enter the y-translating factor: ");
            scanf("%d", &k);
            top = translation(top, k);
            bottom = translation(bottom, k);
            depth = fabs(right - left) / 2;
            bar3d(left, top, right, bottom, depth, 1);
            getch();
            break;
        case 2:
            printf("Assuming even scaling on all axis, enter the scalar factor: ");
            scanf("%d", &k);
            left = scalar(left, k);
            right = scalar(right, k);
            top = scalar(top, k);
            bottom = scalar(bottom, k);
            depth = fabs(right - left) / 2;
            bar3d(left, top, right, bottom, depth, 1);
            getch();
            break;
        default:
            printf("Invalid selection!");
            break;
    }    closegraph();
    return 0;
}
