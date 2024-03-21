
#include <GL/glut.h>

// Variabile pentru poziția și viteza mașinilor
float X1 = 0.0, X2 = -10.0, Y2 = 0.0;  // Obs. Nu avem nevoie de pozitia Y a primei masini deoarece se misca pe o singura axa
float viteza1 = 0.05, viteza2 = 0.07;   // Vitezele pot fi modificate in functie de distantele intre masini
bool depasire = false; // Dacă mașina a doua se afla in depasire


// Funcția pentru actualizarea scenei
void actualizare(int value) {
    X1 += viteza1; // Deplasează prima mașină
    X2 += viteza2; // Deplasează a doua mașină

    // Logică pentru accelerare înainte de depășire
    if (X2 > X1 - 3 && X2 < X1 + 3)
    {
        X2 += 0.1;
    }
    else if (X2 > X1 - 6 && X2 < X1 + 6)
    {
        X2 += 0.05;
    }
    else if (X2 > X1 - 8 && X2 < X1 + 8)
    {
        X2 += 0.03;
    }



    // Logică pentru depășire
    if (X2 > X1 - 3 && !depasire) {
        depasire = true;
    }
    if (Y2 < 1.5 && depasire && X2 < X1)
        Y2 += 0.1; // Mașina iese pe sensul opus în timpul depășirii

    if (depasire && X2 > X1 + 3) {
        depasire = false;
    }
    if (Y2 > 0 && depasire && X2 > X1 + 1)
        Y2 -= 0.1;  // Mașina revine pe banda sa după depășire

    glutPostRedisplay(); // Redesenează scena
    glutTimerFunc(25, actualizare, 0); // Reapelează funcția actualizare după 25 ms
}

void roadDisplay() {
    glColor3f(0.6, 0.6, 0.6);

    // Desenează linia de mijloc punctată
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(2.0);
    glLineStipple(2, 0x00FF); // Setează stilul liniei punctate
    glBegin(GL_LINES);
    glVertex2f(0.0, 20.0);
    glVertex2f(40.0, 20.0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);

    // Desenează liniile paralele pentru marginile străzii
    glBegin(GL_LINES);
    glLineWidth(2.0);
    glVertex2f(0.0, 18.5);
    glVertex2f(40.0, 18.5);
    glVertex2f(0.0, 21.5);
    glVertex2f(40.0, 21.5);
    glEnd();
}

// Funcția de desenare
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    roadDisplay();

    // Desenează prima mașină
    glPushMatrix();
    glTranslated(X1, 18.8, 0.0);


    glColor3f(0.0, 0.0, 1.0); // Prima mașină este de culoare albastră
    glRectf(0.0, 0.0, 1.5, 1.0); // Desenarea unui dreptunghi pentru mașină

    glColor3f(1.0, 1.0, 0.0); // Culoare semnalizatoare: galben
    glRectf(1.3, 0.7, 1.5, 1.0); // Semnalizator dreapta sus
    glColor3f(1.0, 1.0, 0.0); // Culoare semnalizatoare: galben
    glRectf(1.3, 0.0, 1.5, 0.3); // Semnalizator dreapta jos

    glPopMatrix();

    // Desenează a doua mașină

    glPushMatrix();
    glTranslated(X2, Y2 + 18.8, 0.0);

    glColor3f(1.0, 0.0, 0.0);

    // Logică pentru semnalizare
    glColor3f(1.0, 0.0, 0.0);    // A doua mașină este de culoare roșie
    glRectf(0.0, 0.0, 1.5, 1.0); // Desenarea unui dreptunghi pentru mașină
    glColor3f(1.0, 1.0, 0.0);
    if (X2 > X1 - 6 && X2 < X1)
    {

        if (abs((int)X2) % 2 == 0)
            glColor3f(1.0, 1.0, 0.0); // Culoare semnalizatoare: galben
        else
            glColor3f(0.968, 0.694, 0.145);   // Înaintea, în timpul și după depășire, semnalizatorul își schimbă culoarea alternativ pentru a simula semnalizarea.
    }
    glRectf(1.3, 0.7, 1.5, 1.0); // Semnalizator dreapta sus
    glColor3f(1.0, 1.0, 0.0); // Culoare semnalizatoare: galben
    if (X2 > X1 && X2 < X1 + 6)
    {
        if (abs((int)X2) % 2 == 0)
            glColor3f(1.0, 1.0, 0.0); // Culoare semnalizatoare: galben
        else
            glColor3f(0.968, 0.694, 0.145);
    }
    glRectf(1.3, 0.0, 1.5, 0.3); // Semnalizator dreapta jos
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1600, 1200);
    glutCreateWindow("Simularea Procesului de Depășire a unei Mașini");
    glClearColor(0.7, 0.7, 0.7, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 30.0, 0.0, 30.0);
    glutDisplayFunc(display);
    glutTimerFunc(25, actualizare, 0);
    glutMainLoop();
    return 0;
}
