#include <windows.h>
#ifndef __APPLE__
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0); glVertex3f(-0.6, -0.75, 0.5);
        glColor3f(1.0, 1.0, 1.0); glVertex3f(0.6, -0.75, 0.0);
        glColor3f(1.0, 1.0, 1.0); glVertex3f(0.0, 0.45, 0.0);
    glEnd();
    glFlush();
}
int main(int argc, char **argv) {
    printf("Sasank Lama \n");
    glutInit(&argc, argv);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(400, 300);
    glutCreateWindow("bijay Triangle output");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
