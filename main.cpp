#include <GL/glut.h>

// Variabile pentru poziția și viteza mașinilor
float car1X = 0.0, car2X = -10.0;
float speedCar1 = 0.05, speedCar2 = 0.08;

// Funcția pentru desenarea unei mașini
void drawCar(float x) {
   glRectf(x, 0.0, x + 2.0, 1.0); // Desenarea unui dreptunghi pentru mașină
}

// Funcția pentru actualizarea scenei
void update(int value) {
    car1X += speedCar1; // Deplasează prima mașină
    car2X += speedCar2; // Deplasează a doua mașină

    // Dacă a doua mașină depășește prima, încetinește-o
    if (car2X > car1X) speedCar2 = speedCar1;

    glutPostRedisplay(); // Redesenează scena
    glutTimerFunc(25, update, 0); // Reapelează funcția update după 25 ms
}

// Funcția de desenare
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Culoarea mașinii
    drawCar(car1X);
    glColor3f(1.0, 0.0, 1.0); // Culoarea mașinii
    drawCar(car2X);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Car Animation");
    glClearColor(0.5, 0.5, 0.5, 1.0); // Culoarea de fundal: gri
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 30.0, 0.0, 30.0);
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
