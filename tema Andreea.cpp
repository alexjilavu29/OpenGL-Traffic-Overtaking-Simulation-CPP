/*#include <GL/glut.h>

struct Car {
    float x, y;
    float speed;

    Car(float x, float y, float speed) : x(x), y(y), speed(speed) {}
};

Car car1(-0.05, 0.0, 0.001);  // Mașina lentă
Car car2(-0.4, -0.1, 0.004);  // Mașina care depășește

void drawCar(const Car& car) {
    glPushMatrix();
    glTranslatef(car.x, car.y, 0.0);
    glScalef(0.05, 0.03, 1.0);  // Ajustăm dimensiunile mașinii
    glColor3f(1.0, 0.0, 0.0);   // Roșu
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();
    glPopMatrix();
}

void drawRoad() {
    glColor3f(0.5, 0.5, 0.5); // Gri pentru drum
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.15);
    glVertex2f(1.0, -0.15);
    glVertex2f(1.0, 0.15);
    glVertex2f(-1.0, 0.15);
    glEnd();
}

void drawGrass() {
    glColor3f(0.0, 1.0, 0.0); // Verde pentru iarbă
    glBegin(GL_QUADS);
    // Iarbă în stânga drumului
    glVertex2f(-1.0, -1.0);
    glVertex2f(-1.0, -0.15);
    glVertex2f(1.0, -0.15);
    glVertex2f(1.0, -1.0);
    // Iarbă în dreapta drumului
    glVertex2f(-1.0, 1.0);
    glVertex2f(-1.0, 0.15);
    glVertex2f(1.0, 0.15);
    glVertex2f(1.0, 1.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrass();
    drawRoad();
    drawCar(car1);
    drawCar(car2);
    glutSwapBuffers();
}

void update(int value) {
    car1.x += car1.speed;
    car2.x += car2.speed;

    // Logica de depășire
    if (car2.x > car1.x - 0.25 && car2.x < car1.x + 0.15 && car2.y<=0.12) {
        car2.y += 0.005;
    }
    else if (car2.x >= car1.x + 0.25) {
        car2.y -= 0.005;
        if (car2.y < -0.1) car2.y = -0.1; // Asigură-te că mașina rămâne pe drum
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 1000);
    glutCreateWindow("Simulare Depasire");

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}*/


#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "SOIL.h"


void drawAxes() {
    glColor3f(1.0, 1.0, 1.0); // Culoare albă pentru axe
    glBegin(GL_LINES);
    // Axă X
    glVertex2f(-100.0, 0.0);
    glVertex2f(100.0, 0.0);
    // Axă Y
    glVertex2f(0.0, -100.0);
    glVertex2f(0.0, 100.0);
    glEnd();
}

void drawSquare(bool textured) {

    glBegin(GL_QUADS);

    if (!textured) {
        // Aplică un mix de culori
        glColor3f(1.0, 0.0, 0.0); // Rosu
        glVertex2f(-15.0, -15.0); // Stânga jos
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(15.0, -15.0);  // Dreapta jos
        glColor3f(0.0, 0.0, 1.0); // Albastru
        glVertex2f(15.0, 15.0);   // Dreapta sus
        glColor3f(1.0, 1.0, 0.0); // Galben
        glVertex2f(-15.0, 15.0);  // Stânga sus
    }
    else {
        // Aplică coordonate de textură
        glColor3f(1.0, 1.0, 1.0); // Reset la culoarea albă pentru textură
        glTexCoord2f(0.0, 0.0); glVertex2f(-15.0, -15.0);
        glTexCoord2f(1.0, 0.0); glVertex2f(15.0, -15.0);
        glTexCoord2f(1.0, 1.0); glVertex2f(15.0, 15.0);
        glTexCoord2f(0.0, 1.0); glVertex2f(-15.0, 15.0);
    }

    glEnd();

}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    // Pătrat cu mix de culori
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(2.0, 0.5, 1.0);
    drawSquare(false); // Fără textură
    glPopMatrix();
    // Pătrat cu textură
    glPushMatrix();
    glEnable(GL_TEXTURE_2D); // Activează texturarea
    glTranslatef(100.0, 100.0, 0.0);
    glScalef(2.0, 0.5, 1.0);
    drawSquare(true); // Cu textură
    glDisable(GL_TEXTURE_2D); // Dezactivează texturarea
    glPopMatrix();
    glFlush();
}


void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Fundal negru
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0); // Setează coordonatele sistemului de vizualizare
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 900);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformări OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}