// C program for DDA line generation
#include <iostream>
#include <graphics.h>
#include <math.h>
#include <conio.h>

// DDA Function for line generation
void DDA(int X0, int Y0, int X1, int Y1)
{
    int gd = DETECT, gm;
    // Initialize graphics function
    initgraph(&gd, &gm, "");

    int dx = X1 - X0;
    int dy = Y1 - Y0;


    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);


    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;


    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(X), round(Y), WHITE);
        X += Xinc;
        Y += Yinc;
    }
    getch();
    closegraph();

    printf("\n\nDDA Completed.");
}


int main()
{   printf("Sasank Lama \n");
    int X0, Y0, X1, Y1;

    // scanning the points for drawing
    printf("Enter the initial cordinates (x,y): ");
    scanf("%d %d", &X0, &Y0);
    printf("Enter the final coordinates (x,y): ");
    scanf("%d %d", &X1, &Y1);

    // implement the DDA algorithm code
    DDA(X0, Y0, X1, Y1);

    getch();
    return 0;
}
