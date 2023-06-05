#include "glew.h"
#include "freeglut.h"
#include "glut.h"
#include<iostream>
#include<math.h>
#include <stdlib.h>

void Tebrikler();

float kare_x = -0.95f;
float kare_y = 0.95f;
float kare_size = 0.05f;
float heli_x = 0.0f;
float heli_y = 0.0f;
int a = 0;
int b = 0;
int menusec = 0;
double rotate_x = 0;
double rotate_y = 0;
double rotate_y_pervane = 0;
int ani = 0;



int lab[20][20] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 2},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1}
};


void kare_ciz(float x, float y, float size, float r, float g, float m) {
    glColor3f(r, g, m);
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(-size, -size);
    glVertex2f(size, -size);
    glVertex2f(size, size);
    glVertex2f(-size, size);
    glEnd();
    if (lab[a][b] == 2) {
        Tebrikler();
    }

    glPopMatrix();
}

void kalani_ciz() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (lab[i][j] == 1 || lab[i][j] == 2) {
                float x = -0.95f + j * 0.1f;
                float y = 0.95f - i * 0.1f;

                kare_ciz(x, y, kare_size, 1.0f, 0.0f, 0.0f);
                if (lab[i][j] == 2) {
                    kare_ciz(x, y, kare_size, 0.0f, 1.0f, 0.0f);

                }
            }
        }
    }
    kare_ciz(kare_x, kare_y, kare_size, 0.0f, 0.0f, 1.0f);
    glutSwapBuffers();
}

void menu() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -0.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-0.55f, 0.75f);
    std::string tt = "1, 2 ve 3 tuslari ile secenekleri secebilirisniz";
    for (int i = 0; i < tt.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, tt[i]);

    glRasterPos2f(-0.55f, 0.35f);
    std::string aa = "1. Project Labirent oyununa Basla";
    for (int i = 0; i < aa.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, aa[i]);

    glRasterPos2f(-0.55f, 0.0f);
    std::string bb = "2. Helicopter prototip";
    for (int i = 0; i < bb.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, bb[i]);

    glRasterPos2f(-0.55f, -0.55f);
    std::string cc = "3. Program bilgileri";
    for (int i = 0; i < cc.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, cc[i]);


    glutSwapBuffers();

}

void bilgi() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -0.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-0.95f, 0.55f);
    std::string dd = "Labirent oyunu WASD tuslari ile oynanir. ";
    for (int i = 0; i < dd.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, dd[i]);

    glRasterPos2f(-0.95f, 0.0f);
    std::string ee = "Yon tuslari ile helikoptere bakabilirsiniz";
    for (int i = 0; i < ee.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ee[i]);

    glRasterPos2f(-0.95f, -0.1f);
    std::string rr = "P ile motoru baslatabilir ve hizlandirabilirisniz. L tusu ile motor durur.";
    for (int i = 0; i < rr.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, rr[i]);
    glRasterPos2f(-0.95f, -0.2f);
    std::string zz = "D-A tuslari ile helikoter ileri ve geri gider. W-S ile yukselir ve alcalir";
    for (int i = 0; i < zz.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, zz[i]);

    glRasterPos2f(-0.95f, -0.55f);
    std::string ff = "0 ile ana menuye dönebilirsiniz.";
    for (int i = 0; i < ff.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ff[i]);

    glutSwapBuffers();

}

void helikopter() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //glTranslated(rotate_x / 100, 0.0, 0.0); 

    glPushMatrix();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glTranslatef(heli_x, heli_y, 0.0f);

    ///////////////////////// kabin
    glTranslatef(0.2f, -0.25f, 0.0f);
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_POLYGON); //ön yüzü
    glVertex3f(0.5, -0.25, -0.5);
    glVertex3f(0.5, 0.25, -0.5);
    glVertex3f(-0.5, 0.25, -0.5);
    glVertex3f(-0.5, -0.25, -0.5);
    glEnd();

    // arka
    glBegin(GL_POLYGON);
    glVertex3f(0.5, -0.25, 0.5);
    glVertex3f(0.5, 0.25, 0.5);
    glVertex3f(-0.5, 0.25, 0.5);
    glVertex3f(-0.5, -0.25, 0.5);
    glEnd();

    // sað
    glBegin(GL_POLYGON);
    glVertex3f(0.5, -0.25, -0.5);
    glVertex3f(0.5, 0.25, -0.5);
    glVertex3f(0.5, 0.25, 0.5);
    glVertex3f(0.5, -0.25, 0.5);
    glEnd();

    // sol
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.25, 0.5);
    glVertex3f(-0.5, 0.25, 0.5);
    glVertex3f(-0.5, 0.25, -0.5);
    glVertex3f(-0.5, -0.25, -0.5);
    glEnd();

    //  üst
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.25, 0.5);
    glVertex3f(0.5, 0.25, -0.5);
    glVertex3f(-0.5, 0.25, -0.5);
    glVertex3f(-0.5, 0.25, 0.5);
    glEnd();

    // alt
    glBegin(GL_POLYGON);
    glVertex3f(0.5, -0.25, -0.5);
    glVertex3f(0.5, -0.25, 0.5);
    glVertex3f(-0.5, -0.25, 0.5);
    glVertex3f(-0.5, -0.25, -0.5);
    glEnd();



    /////////////////////////// kuyruk
    glTranslatef(-0.5f, -0.0f, 0.0f);
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_POLYGON); //ön yüzü
    glVertex3f(0.5, -0.125, -0.25);
    glVertex3f(0.5, 0.125, -0.25);
    glVertex3f(-0.5, 0.125, -0.25);
    glVertex3f(-0.5, -0.125, -0.25);
    glEnd();

    // arka
    glBegin(GL_POLYGON);
    glVertex3f(0.5, -0.125, 0.25);
    glVertex3f(0.5, 0.125, 0.25);
    glVertex3f(-0.5, 0.125, 0.25);
    glVertex3f(-0.5, -0.125, 0.25);
    glEnd();

    // sað
    glBegin(GL_POLYGON);
    glVertex3f(0.5, -0.125, -0.25);
    glVertex3f(0.5, 0.125, -0.25);
    glVertex3f(0.5, 0.125, 0.25);
    glVertex3f(0.5, -0.125, 0.25);
    glEnd();

    // sol
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.125, 0.25);
    glVertex3f(-0.5, 0.125, 0.25);
    glVertex3f(-0.5, 0.125, -0.25);
    glVertex3f(-0.5, -0.125, -0.25);
    glEnd();

    //  üst
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.125, 0.25);
    glVertex3f(0.5, 0.125, -0.25);
    glVertex3f(-0.5, 0.125, -0.25);
    glVertex3f(-0.5, 0.125, 0.25);
    glEnd();

    // alt
    glBegin(GL_POLYGON);
    glVertex3f(0.5, -0.125, -0.25);
    glVertex3f(0.5, -0.125, 0.25);
    glVertex3f(-0.5, -0.125, 0.25);
    glVertex3f(-0.5, -0.125, -0.25);
    glEnd();

    ////////////////////// kuyruk kanat

    glTranslatef(-0.4f, 0.2f, 0.0f);
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_POLYGON); //ön yüzü
    glVertex3f(0.0625, -0.25, -0.25);
    glVertex3f(0.0625, 0.25, -0.25);
    glVertex3f(-0.0625, 0.25, -0.25);
    glVertex3f(-0.0625, -0.25, -0.25);
    glEnd();

    // arka
    glBegin(GL_POLYGON);
    glVertex3f(0.0625, -0.25, 0.25);
    glVertex3f(0.0625, 0.25, 0.25);
    glVertex3f(-0.0625, 0.25, 0.25);
    glVertex3f(-0.0625, -0.25, 0.25);
    glEnd();

    // sað
    glBegin(GL_POLYGON);
    glVertex3f(0.0625, -0.25, -0.25);
    glVertex3f(0.0625, 0.25, -0.25);
    glVertex3f(0.0625, 0.25, 0.25);
    glVertex3f(0.0625, -0.25, 0.25);
    glEnd();

    // sol
    glBegin(GL_POLYGON);
    glVertex3f(-0.0625, -0.25, 0.25);
    glVertex3f(-0.0625, 0.25, 0.25);
    glVertex3f(-0.0625, 0.25, -0.25);
    glVertex3f(-0.0625, -0.25, -0.25);
    glEnd();

    //  üst
    glBegin(GL_POLYGON);
    glVertex3f(0.0625, 0.25, 0.25);
    glVertex3f(0.0625, 0.25, -0.25);
    glVertex3f(-0.0625, 0.25, -0.25);
    glVertex3f(-0.0625, 0.25, 0.25);
    glEnd();

    // alt
    glBegin(GL_POLYGON);
    glVertex3f(0.0625, -0.25, -0.25);
    glVertex3f(0.0625, -0.25, 0.25);
    glVertex3f(-0.0625, -0.25, 0.25);
    glVertex3f(-0.0625, -0.25, -0.25);
    glEnd();

    ///////////////////////////// pervane yukseltmesi şeysi \ silindir yapmayı beceremedim

    glTranslatef(1.0f, 0.3f, 0.0f);
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_POLYGON); //ön yüzü
    glVertex3f(0.0625, -0.25, -0.0625);
    glVertex3f(0.0625, 0.25, -0.0625);
    glVertex3f(-0.0625, 0.25, -0.0625);
    glVertex3f(-0.0625, -0.25, -0.0625);
    glEnd();

    // arka
    glBegin(GL_POLYGON);
    glVertex3f(0.0625, -0.25, 0.0625);
    glVertex3f(0.0625, 0.25, 0.0625);
    glVertex3f(-0.0625, 0.25, 0.0625);
    glVertex3f(-0.0625, -0.25, 0.0625);
    glEnd();

    // sað
    glBegin(GL_POLYGON);
    glVertex3f(0.0625, -0.25, -0.0625);
    glVertex3f(0.0625, 0.25, -0.0625);
    glVertex3f(0.0625, 0.25, 0.0625);
    glVertex3f(0.0625, -0.25, 0.0625);
    glEnd();

    // sol
    glBegin(GL_POLYGON);
    glVertex3f(-0.0625, -0.25, 0.0625);
    glVertex3f(-0.0625, 0.25, 0.0625);
    glVertex3f(-0.0625, 0.25, -0.0625);
    glVertex3f(-0.0625, -0.25, -0.0625);
    glEnd();

    //  üst
    glBegin(GL_POLYGON);
    glVertex3f(0.0625, 0.25, 0.0625);
    glVertex3f(0.0625, 0.25, -0.0625);
    glVertex3f(-0.0625, 0.25, -0.0625);
    glVertex3f(-0.0625, 0.25, 0.0625);
    glEnd();

    // alt
    glBegin(GL_POLYGON);
    glVertex3f(0.0625, -0.25, -0.0625);
    glVertex3f(0.0625, -0.25, 0.0625);
    glVertex3f(-0.0625, -0.25, 0.0625);
    glVertex3f(-0.0625, -0.25, -0.0625);
    glEnd();


    ///////////////////////// pervane 1 / koni şekilnde
    glTranslatef(0.0f, 0.2f, 0.0f);
    glRotatef(rotate_y_pervane * 1000, 0.0, 1.0, 0.0);

    //glTranslatef(0.0f, 0.2f, 0.0f);
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_POLYGON); //ön yüzü
    glVertex3f(0.0, -0.0625, -0.0625);
    glVertex3f(0.8, 0.0, 0);
    glVertex3f(-0.0, 0.0625, -0.0625);

    glEnd();

    // arka
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.0625, 0.0625);
    glVertex3f(0.8, 0.0, 0);
    glVertex3f(-0.0, 0.0625, 0.0625);

    glEnd();


    //  üst
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0625, 0.0625);
    glVertex3f(0.8, 0.0, 0);
    glVertex3f(-0.0, 0.0625, -0.0625);

    glEnd();

    // alt
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.0625, -0.0625);
    glVertex3f(0.8, 0.0, 0);
    glVertex3f(-0.0, -0.0625, 0.0625);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.0625, -0.0625);
    glVertex3f(0.0, 0.0625, 0.0625);
    glVertex3f(0.0, 0.0625, -0.0625);
    glVertex3f(0.0, -0.0625, 0.0625);

    glEnd();

    ////////////////// pervane 2

    glTranslatef(0.0f, 0.0f, 0.0f);
    glColor3f(0.5, 0.5, 0.5);

    glBegin(GL_POLYGON); //ön yüzü
    glVertex3f(0.0, -0.0625, -0.0625);
    glVertex3f(-0.8, 0.0, 0);
    glVertex3f(-0.0, 0.0625, -0.0625);

    glEnd();

    // arka
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.0625, 0.0625);
    glVertex3f(-0.8, 0.0, 0);
    glVertex3f(-0.0, 0.0625, 0.0625);

    glEnd();


    //  üst
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0625, 0.0625);
    glVertex3f(-0.8, 0.0, 0);
    glVertex3f(-0.0, 0.0625, -0.0625);

    glEnd();

    // alt
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.0625, -0.0625);
    glVertex3f(-0.8, 0.0, 0);
    glVertex3f(-0.0, -0.0625, 0.0625);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.0625, -0.0625);
    glVertex3f(0.0, 0.0625, 0.0625);
    glVertex3f(0.0, 0.0625, -0.0625);
    glVertex3f(0.0, -0.0625, 0.0625);

    glEnd();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();


}


void display() {
    if (menusec == 0)
        menu();
    if (menusec == 1)
        kalani_ciz();
    if (menusec == 2)
        helikopter();
    if (menusec == 3)
        bilgi();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void SpecialKey(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    glutPostRedisplay();
}

void Ani(int t)
{
    rotate_y_pervane += 0.5;
    rotate_x += 0.01;
    glutPostRedisplay();
    if (ani == 1) glutTimerFunc(10, Ani, 2);
}

void Tebrikler() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(-0.7f, 0.0f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(-0.95f, 0.55f);
    std::string uu = "Tebrikler, oyunu kazandiniz. Menuye donmek icin sifir tusuna basiniz  ";
    for (int i = 0; i < uu.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, uu[i]);



}

void keyboard(unsigned char key, int x, int y) {

    switch (key) {
    case 'w':
    case 'W':
        if (kare_y == 0.95f) {
            if (menusec == 2)
                heli_y += 0.1f;
            break;
        }
        if (lab[a - 1][b] == 0) {
            if (menusec == 2)
                heli_y += 0.1f;
            break;
        }
        if (menusec == 1) {
            kare_y += 0.1f;
            a -= 1;

        }

        if (menusec == 2)
            heli_y += 0.1f;

        break;

    case 's':
    case 'S':
        if (kare_y <= -0.95f) {
            if (menusec == 2)
                heli_y -= 0.1f;
            break;
        }
        if (lab[a + 1][b] == 0) {
            if (menusec == 2)
                heli_y -= 0.1f;
            break;
        }
        if (menusec == 1) {
            a += 1;
            kare_y -= 0.1f;

        }

        if (menusec == 2)
            heli_y -= 0.1f;
        break;
    case 'a':
    case 'A':
        if (kare_x == -0.95f) {
            if (menusec == 2)
                heli_x -= 0.1f;
            break;
        }
        if (lab[a][b - 1] == 0) {
            if (menusec == 2)
                heli_x -= 0.1f;
            break;
        }
        if (menusec == 1) {
            b -= 1;
            kare_x -= 0.1f;
        }
        if (menusec == 2)
            heli_x -= 0.1f;
        break;
    case 'd':
    case 'D':
        if (kare_x >= 0.95f) {
            if (menusec == 2)
                heli_x += 0.1f;

            break;
        }
        if (lab[a][b + 1] == 0) {
            if (menusec == 2)
                heli_x += 0.1f;

            break;
        }
        if (menusec == 1) {

            b += 1;
            kare_x += 0.1f;
        }
        if (menusec == 2)
            heli_x += 0.1f;
        break;
    case '0':
        menusec = 0;
        menu();
        break;
    case '1':
        if (menusec == 2 || menusec == 3)
            break;
        menusec = 1;
        break;
    case '2':
        if (menusec == 1 || menusec == 3)
            break;
        menusec = 2;
        break;
    case '3':
        if (menusec == 1 || menusec == 2)
            break;
        menusec = 3;
        break;
    case 'p':
    case 'P':
        ani = 1;
        glutTimerFunc(100, Ani, 0);
        break;
    case 'l':
    case 'L':
        ani = 0;

        break;
    }




    glutPostRedisplay();
}



static void idle(void)
{
    rotate_y += 0.0004;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Project \"Labirent\", cikisi bul!");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    //glutIdleFunc(idle);
    glutSpecialFunc(SpecialKey);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);



    glutMainLoop();

    return 0;
}
