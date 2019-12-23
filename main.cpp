#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>
#define PI 3.14159265358979323846

using namespace std;

bool isRaining = false;

float _run3 = 0.0;

float _planeMoving = 0.0;
float _planeMovingUpdate = 7.5;

float _teslaCyberTruckMoving = 0.0;
float _teslaCyberTruckUpdateValue = 3.7;

float _shipMoving = 0.0;
float _ship1Moving = 0.0;
float _ship1UpdateValue = 1.7;

float _busMoving = 1000.0;
float _busMovingUpdate = -3.7;

int buildingWindowColor[] = {240, 200, 100};
int sunOrMoonColor[] = {200, 200, 200};

float _rainValueY = 0.0;
float _rainUpdateValueY = 2.7;

float _rainValueX = 0.0;
float _rainUpdateValueX = 2.7;

int cloudColor[] = {255, 255, 255};

void init()
{

    glClearColor(0.0, 0.5, 0.8, 1.0);
    glColor3f(0.0, 0.0, 0.5);
    glPointSize(4.0);
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}
void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides)
{
    int numberOfVertices = numberOfSides + 2;

    GLfloat twicePi = 2.0f * M_PI;

    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];

    circleVerticesX[0] = x;
    circleVerticesY[0] = y;
    circleVerticesZ[0] = z;

    for (int i = 1; i < numberOfVertices; i++)
    {
        circleVerticesX[i] = x + (radius * cos(i * twicePi / numberOfSides));
        circleVerticesY[i] = y + (radius * sin(i * twicePi / numberOfSides));
        circleVerticesZ[i] = z;
    }

    GLfloat allCircleVertices[(numberOfVertices)*3];

    for (int i = 0; i < numberOfVertices; i++)
    {
        allCircleVertices[i * 3] = circleVerticesX[i];
        allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
        allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void separaratorTopBuildingLine(int y)
{
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2i(0, y);
    glVertex2i(1000, y);
    glEnd();
}

void buildWindow(int xw, int yw)
{
    glPushMatrix();
    glColor3ub(buildingWindowColor[0], buildingWindowColor[1], buildingWindowColor[2]);
    glBegin(GL_QUADS);
    glVertex2i((xw + 20), yw + 20);
    glVertex2i(xw + 20, yw + 50);
    glVertex2i(xw + 80, yw + 50);
    glVertex2i(xw + 80, yw + 20);
    glEnd();
    glPopMatrix();
}

void rain()
{
    glPushMatrix();

    glColor3ub(230, 230, 230);
    glTranslatef(-(_rainValueY / 4), -_rainValueY, 0.0);
    for (int i = 0; i < 1500; i += 10)
    {
        for (int j = 0; j < 10000; j += 10)
        {

            glBegin(GL_LINES);

            glVertex2i(i, j);
            glVertex2i(i + 10, j + 10);

            glEnd();
            j += 10;
        }

        i += 10;
    }
    glPopMatrix();
}

void smallBuilding(int locationX, int locationY)
{
    glPushMatrix();
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
    glVertex2i(locationX, locationY);
    glVertex2i(locationX, locationY + 150);
    glVertex2i(locationX + 100, locationY + 150);
    glVertex2i(locationX + 100, locationY);
    //buildWindow(locationX,locationY);
    buildWindow(locationX, locationY);
    buildWindow(locationX, locationY + 45);
    buildWindow(locationX, locationY + 90);

    glEnd();
    glPopMatrix();
}

void bigBuilding(int locationX, int locationY)
{
    glPushMatrix();
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
    glVertex2i(locationX, locationY);
    glVertex2i(locationX, locationY + 250);
    glVertex2i(locationX + 100, locationY + 250);
    glVertex2i(locationX + 100, locationY);
    //buldingWindow(locationX,locationX+100,locationY,locationY+250);
    buildWindow(locationX, locationY);
    buildWindow(locationX, locationY + 45);
    buildWindow(locationX, locationY + 90);
    buildWindow(locationX, locationY + 135);
    buildWindow(locationX, locationY + 180);
    glEnd();
    glPopMatrix();
}

void river(int locationX, int locationY)
{
    glColor3ub(0, 150, 190);
    glBegin(GL_QUADS);
    glVertex2i(locationX, locationY);
    glVertex2i(locationX, locationY + 300);
    glVertex2i(locationX + 1000, locationY + 300);
    glVertex2i(locationX + 1000, locationY);
    glEnd();
}
void ship1()
{
    glPushMatrix();
    glTranslatef(_ship1Moving, 0.0, 0.0);
    //glColor3ub(0, 0, 0);

    ///ship1
    glBegin(GL_QUADS);
    glColor3ub(1, 1, 1);
    glPointSize(5.0);

    glBegin(GL_QUADS); ///lower part
    glColor3ub(15, 35, 115);
    glVertex2i(60, 90);
    glVertex2i(580, 90);
    glVertex2i(580, 120);
    glVertex2i(60, 120);

    glBegin(GL_QUADS); ///second part
    glColor3ub(15, 35, 115);
    glVertex2i(60, 40);
    glVertex2i(580, 40);
    glVertex2i(580, 80);
    glVertex2i(60, 80);
    glEnd();

    glBegin(GL_TRIANGLES); ///front curve
    glColor3ub(15, 35, 115);

    glVertex2f(570, 120);
    glVertex2f(570, 40);
    glVertex2f(650, 120);

    glEnd();

    glBegin(GL_QUADS); ///1st floor
    glColor3ub(15, 35, 115);
    glVertex2i(90, 120);
    glVertex2i(500, 120);
    glVertex2i(500, 220);
    glVertex2i(90, 220);

    glBegin(GL_QUADS); ///window
    glColor3ub(232, 228, 125);
    glVertex2i(110, 130);
    glVertex2i(220, 130);
    glVertex2i(220, 200);
    glVertex2i(110, 200);

    glBegin(GL_QUADS); ///window
    glColor3ub(232, 228, 125);
    glVertex2i(230, 130);
    glVertex2i(330, 130);
    glVertex2i(330, 200);
    glVertex2i(230, 200);

    glBegin(GL_QUADS); ///window
    glColor3ub(232, 228, 125);
    glVertex2i(340, 130);
    glVertex2i(460, 130);
    glVertex2i(460, 200);
    glVertex2i(340, 200);

    glBegin(GL_QUADS); ///second floor
    glColor3ub(15, 35, 115);
    glVertex2i(180, 220);
    glVertex2i(450, 220);
    glVertex2i(450, 320);
    glVertex2i(180, 320);

    glBegin(GL_QUADS); ///window
    glColor3ub(232, 228, 125);
    glVertex2i(200, 230);
    glVertex2i(290, 230);
    glVertex2i(290, 310);
    glVertex2i(200, 310);

    glBegin(GL_QUADS); ///window
    glColor3ub(232, 228, 125);
    glVertex2i(300, 230);
    glVertex2i(420, 230);
    glVertex2i(420, 310);
    glVertex2i(300, 310);

    glBegin(GL_QUADS); ///3rd floor
    glColor3ub(15, 35, 115);
    glVertex2i(300, 320);
    glVertex2i(420, 320);
    glVertex2i(420, 360);
    glVertex2i(300, 360);

    glBegin(GL_QUADS); ///last floor
    glColor3ub(15, 35, 115);
    glVertex2i(380, 360);
    glVertex2i(400, 360);
    glVertex2i(400, 380);
    glVertex2i(380, 380);
    glEnd();

    //flag

    glBegin(GL_QUADS); // flag pole
    glVertex2i(560, 120);
    glVertex2i(560, 240);
    glVertex2i(565, 240);
    glVertex2i(565, 120);
    glEnd();

    glBegin(GL_QUADS); //falg
    glColor3ub(0, 240, 0);
    glVertex2i(560, 160);
    glVertex2i(560, 240);
    glVertex2i(505, 240);
    glVertex2i(505, 160);
    glEnd();

    glColor3ub(240, 0, 0);
    drawCircle(533, 200, 0, 20, 1000);
    //flag ends

    glPopMatrix(); //ei ta den nai ei karone porblem hoisilo

    //ship1 ends
}

/*void ship2() {
    glPushMatrix();
    glTranslatef(_ship1Moving, 0.0, 0.0);
    glColor3ub(0, 0, 0);;
}*/

void road(int locationX, int locationY)
{
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
    glVertex2i(locationX, locationY);
    glVertex2i(locationX, locationY + 270);
    glVertex2i(locationX + 1000, locationY + 270);
    glVertex2i(locationX + 1000, locationY);
    glEnd();
    glColor3ub(160, 100, 50);
    glBegin(GL_QUADS);
    glVertex2i(locationX, locationY + 270);
    glVertex2i(locationX, locationY + 290);
    glVertex2i(locationX + 1000, locationY + 290);
    glVertex2i(locationX + 1000, locationY + 270);

    glVertex2i(locationX, locationY);
    glVertex2i(locationX, locationY - 20);
    glVertex2i(locationX + 1000, locationY - 20);
    glVertex2i(locationX + 1000, locationY);
    glEnd();

    for (int i = 0; i <= 1000; i += 100)
    {
        glColor3ub(200, 200, 200);
        glBegin(GL_QUADS);
        glVertex2i(i, locationY + 140);
        glVertex2i(i, locationY + 160);
        glVertex2i(i + 100, locationY + 160);
        glVertex2i(i + 100, locationY + 140);

        glEnd();
        i = i + 20;
    }
    for (int i = 0; i <= 1000; i += 50)
    {
        glColor3ub(240, 240, 240);
        glBegin(GL_QUADS);
        glVertex2i(i, locationY + 270);
        glVertex2i(i, locationY + 290);
        glVertex2i(i + 20, locationY + 290);
        glVertex2i(i + 20, locationY + 270);

        glVertex2i(i, locationY);
        glVertex2i(i, locationY - 20);
        glVertex2i(i + 20, locationY - 20);
        glVertex2i(i + 20, locationY);

        glEnd();
        //i=i+20;
    }
}

// test cyber truck
void teslaCyberTruck()
{
    glPushMatrix();
    glTranslatef(_teslaCyberTruckMoving, 0.0, 0.0);
    glColor3ub(128, 128, 128);

    //base
    glBegin(GL_QUADS);
    glVertex2i(100, 370);
    glVertex2i(100, 400);
    glVertex2i(10, 410);
    glVertex2i(15, 370);
    glEnd();

    //base black bottom
    glBegin(GL_QUADS);
    glColor3ub(15, 15, 15);
    glVertex2i(100, 370);
    glVertex2i(100, 380);
    glVertex2i(10, 381);
    glVertex2i(15, 370);
    glEnd();

    //upper triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex2i(10, 410);
    glVertex2i(40, 440);
    glVertex2i(100, 400);
    glEnd();

    //font window
    glBegin(GL_TRIANGLES);
    glColor3ub(200, 200, 200);
    glVertex2i(45, 410);
    glVertex2i(45, 430);
    glVertex2i(85, 410);
    glEnd();

    //lines base and upper triangle
    glBegin(GL_LINES);
    glPointSize(1.0);
    glColor3ub(15, 15, 15);
    glVertex2i(10, 410);
    glVertex2i(100, 400);
    glPointSize(4.0);
    glEnd();

    //back tire
    glColor3ub(15, 15, 15);
    drawCircle(30, 370, 0, 10, 100);
    glColor3ub(240, 240, 240);
    drawCircle(30, 370, 0, 7, 100);

    //font tire
    glColor3ub(15, 15, 15);
    drawCircle(85, 370, 0, 10, 100);
    glColor3ub(240, 240, 240);
    drawCircle(85, 370, 0, 7, 100);

    glPopMatrix();
}

void bus(int busStartLocation)
{
    glPushMatrix();
    glTranslatef(_busMoving, 0.0f, 0.0f);

    //base
    glColor3ub(200, 10, 10);
    glBegin(GL_QUADS);
    glVertex2i(busStartLocation, 505);
    glVertex2i(busStartLocation, 570);
    glVertex2i(busStartLocation + 190, 570);
    glVertex2i(busStartLocation + 190, 505);
    glEnd();

    //windows

    for (int i = busStartLocation; i < (busStartLocation + 160); i = i + 20)
    {
        glColor3ub(200, 200, 200);
        glBegin(GL_QUADS);
        glVertex2i(i, 537);
        glVertex2i(i, 569);
        glVertex2i(i + 20, 569);
        glVertex2i(i + 20, 537);
        glEnd();

        i = i + 10;
    }

    //circle
    glColor3ub(20, 20, 20);
    drawCircle(busStartLocation + 30, 505, 0, 20, 100);
    drawCircle(busStartLocation + 160, 505, 0, 20, 100);

    glColor3ub(220, 220, 220);
    drawCircle(busStartLocation + 30, 505, 0, 17, 100);
    drawCircle(busStartLocation + 160, 505, 0, 17, 100);

    glPopMatrix();
}

void mountain(int mountainStartPointX, int red, int green, int blue)
{
    glPushMatrix();

    glBegin(GL_TRIANGLES);

    glColor3ub(red, green - 10, blue);
    glVertex2i(mountainStartPointX, 600);

    glColor3ub(red, green + 5, blue);
    glVertex2i(mountainStartPointX + 150, 900);

    glColor3ub(red, green - 10, blue);
    glVertex2i(mountainStartPointX + 300, 600);

    glEnd();

    glPopMatrix();
}

void cloud()
{
    ///Cloud

    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 40;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 50;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 40;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 50;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    //cloud 2
    glPushMatrix();
    glTranslatef(350, 100, 0);
    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 40;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 50;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 50;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 50;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 40;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(290, 760, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = 40;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
    //end of cloud
}

void sunOrMoon()
{
    glColor3ub(sunOrMoonColor[0], sunOrMoonColor[1], sunOrMoonColor[2]);
    drawCircle(800, 920, 0, 65, 1000);
}

void plane()
{
    glPushMatrix();
    glTranslatef(_planeMoving, 0.0f, 0.0f);
    glColor3ub(240, 240, 240);

    glBegin(GL_QUADS); //base //plane
    glVertex2i(30, 920);
    glVertex2i(220, 920);
    glVertex2i(220, 990);
    glVertex2i(30, 990);

    glVertex2i(130, 920); // wing bottom
    glVertex2i(120, 855);
    glVertex2i(170, 855);
    glVertex2i(180, 920);

    glVertex2i(130, 990); // wing top
    glVertex2i(120, 1045);
    glVertex2i(170, 1045);
    glVertex2i(180, 990);

    glVertex2i(40, 990); // wing top
    glVertex2i(35, 1025);
    glVertex2i(65, 1025);
    glVertex2i(70, 990);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(30, 920);
    glVertex2i(25, 955);
    glVertex2i(30, 990);
    glEnd();

    drawCircle(220, 955, 0, 35, 1000); //plane font dom

    //windows
    glBegin(GL_QUADS);
    glColor3ub(150, 150, 150);
    for (int i = 40; i < 220; i += 20)
    {
        glVertex2i(i, 950);
        glVertex2i(i + 20, 950);
        glVertex2i(i + 20, 970);
        glVertex2i(i, 970);

        i = i + 20;
    }
    glEnd();

    glPopMatrix();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    sunOrMoon();
    plane();

    int mountainColor1[] = {2, 210, 6};
    mountain(500, 30, 240, 70);
    mountain(200, 30, 240, 70);
    mountain(-100, 30, 240, 70);
    mountain(10, 2, 210, 6);
    mountain(370, 2, 210, 6);
    mountain(770, 2, 210, 6);
    cloud();

    glPopMatrix();

    glPushMatrix();
    separaratorTopBuildingLine(600);
    separaratorTopBuildingLine(300);
    smallBuilding(600, 600);
    smallBuilding(750, 600);
    bigBuilding(880, 600);
    smallBuilding(30, 600);

    //buldingWindow(600,600+100,600,600+150);
    bigBuilding(300, 600);
    smallBuilding(450, 600);

    bigBuilding(150, 600);

    river(0, 0);

    road(0, 320);
    glPopMatrix();

    ship1();
    teslaCyberTruck();

    bus(60);
    bus(400);

    if (isRaining)
    {
        rain();
    }

    glFlush();
}
void update(int value)
{
    _rainValueY += _rainUpdateValueY;

    if (_rainValueY > 1000)
    {
        _rainValueY = 300;
    }

    _ship1Moving += _ship1UpdateValue;
    if (_ship1Moving > 1000)
    {
        _ship1Moving -= 1700;
    }

    _teslaCyberTruckMoving += _teslaCyberTruckUpdateValue;
    if (_teslaCyberTruckMoving > 1000)
    {
        _teslaCyberTruckMoving -= 1700;
    }

    _planeMoving += _planeMovingUpdate;
    if (_planeMoving > 1000)
    {
        _planeMoving -= 1700;
    }

    _busMoving += _busMovingUpdate;

    if (_busMoving < -700)
    {
        _busMoving = +1700;
    }

    _run3 += 0.8f;
    if (_run3 > 1000)
    {
        _run3 -= 1700;
    }

    glutPostRedisplay(); //Tell GLUT that the display has changed
    glutTimerFunc(25, update, 0);
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
        buildingWindowColor[0] = 90;
        buildingWindowColor[1] = 90;
        buildingWindowColor[2] = 90;
        sunOrMoonColor[0] = 240;
        sunOrMoonColor[1] = 240;
        sunOrMoonColor[2] = 150;

        break;
    case 'n':
        buildingWindowColor[0] = 240;
        buildingWindowColor[1] = 200;
        buildingWindowColor[2] = 100;
        sunOrMoonColor[0] = 200;
        sunOrMoonColor[1] = 200;
        sunOrMoonColor[2] = 200;

        break;
    case 's':
        _teslaCyberTruckUpdateValue = 0.0;
        break;

    case 'p':
        _teslaCyberTruckUpdateValue = 3.7;
        break;
    case 'r':
        isRaining = !isRaining;
        break;

    default:
        break;
    }
}

int main(int argc, char **argv)
{
    cout << endl
         << "*** BUSY CITY  ********************" << endl
         << endl;

    cout << "Press N : For Night " << endl
         << endl;
    cout << "Press B : For Day" << endl
         << endl;
    cout << "Press S : For stop" << endl
         << endl;
    cout << "Press P : For start" << endl
         << endl;
    cout << "Press R : For controlling rain" << endl
         << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1800, 1200);
    glutCreateWindow("BUSY CITY"); // creating the window
    //glutFullScreen();       // making the window full screen
    //glutInitWindowPosition(0,0);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(25, update, 0);
    init();
    glutMainLoop();
    return 0;
}
