#include <iostream>
#include <complex>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;

typedef complex<double> point;
#define x real()
#define y imag()

void displaymenu()
{
    cout << "Press 1 for translation." << endl;
    cout << "Press 2 for rotation." << endl;
    cout << "Press 3 for scaling." << endl;
    cout << "Press 4 for reflection." << endl;
}

void reflectionmenu()
{
    cout << "Press 1 for reflection through x-axis." << endl;
    cout << "Press 2 for reflection through y-axis." << endl;
}

point translation(point A, int a, int b)
{
    point B(A.real() + a, A.imag() + b);
    return B;
}

point rotation(point A, int a, int b, float angl)
{
    point C = translation(A, -a, -b);
    point B(((C.real() * cos(angl)) - (C.imag() * sin(angl))), ((C.real() * sin(angl)) + (C.imag()) * cos(angl)));
    point D = translation(B, +a, +b);
    return D;
}

point scaling(point A, int a, int b)
{
    point B(A.real() * a, A.imag() * b);
    return B;
}

point reflectionthx(point A)
{
    point C(A.real(), -A.imag());
    point B = translation(C, 0, 600);
    return B;
}

point reflectionthy(point A)
{
    point C(-A.real(), A.imag());
    point B = translation(C, 600, 0);
    return B;
}

int drawpolygon(point W, point X, point Y, point Z)
{
    line(W.real(), W.imag(), Z.real(), Z.imag());
    delay(200);
    line(Z.real(), Z.imag(), Y.real(), Y.imag());
    delay(200);
    line(Y.real(), Y.imag(), X.real(), X.imag());
    delay(200);
    line(X.real(), X.imag(), W.real(), W.imag());
    delay(200);
    return 0;
}

int main()
{
    printf("Sasank Lama \n");
    int gd = DETECT, gm;
    point E, F, G, H;
    int x1, y1, x2, y2, x3, y3, x4, y4, choice, subchoice;

    cout << "Enter four coordinates of polygon (one in a single line): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    initgraph(&gd, &gm,"");
    point A(x1, y1);
    point B(x2, y2);
    point C(x3, y3);
    point D(x4, y4);
    drawpolygon(A, B, C, D);
    displaymenu();

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        int a, b;
        cout << "Enter translation distances: ";
        cin >> a >> b;
        E = translation(A, a, b);
        F = translation(B, a, b);
        G = translation(C, a, b);
        H = translation(D, a, b);
        setcolor(WHITE);
        drawpolygon(E, F, G, H);
        getch();
        break;

    case 2:
        float angle, ang;
        int c, d; // pivot
        cout << "Enter pivot point for rotation: ";
        cin >> c >> d;
        cout << "Enter angle through which you want to rotate: ";
        cin >> ang;
        angle = (ang * 3.14) / 180;
        E = rotation(A, c, d, angle);
        F = rotation(B, c, d, angle);
        G = rotation(C, c, d, angle);
        H = rotation(D, c, d, angle);
        setcolor(WHITE);
        drawpolygon(E, F, G, H);
        break;

    case 3:
        int sx, sy;
        cout << "Enter scaling factors (Sx, Sy): ";
        cin >> sx >> sy;
        E = scaling(A, sx, sy);
        F = scaling(B, sx, sy);
        G = scaling(C, sx, sy);
        H = scaling(D, sx, sy);
        setcolor(WHITE);
        drawpolygon(E, F, G, H);
        break;

    case 4:
        reflectionmenu();
        cout << "Choose type of reflection: ";
        cin >> subchoice;
        switch (subchoice)
        {
        case 1:
            E = reflectionthx(A);
            F = reflectionthx(B);
            G = reflectionthx(C);
            H = reflectionthx(D);
            setcolor(WHITE);
            drawpolygon(E, F, G, H);
            break;

        case 2:
            E = reflectionthy(A);
            F = reflectionthy(B);
            G = reflectionthy(C);
            H = reflectionthy(D);
            setcolor(WHITE);
            drawpolygon(E, F, G, H);
            break;
        }
        break;

    default:
        cout << "Invalid Choice.." << endl;
        break;
    }

    getch();
    closegraph();

    return 0;
}
