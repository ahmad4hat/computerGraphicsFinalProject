#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>

using namespace std;


int buildingWindowColor[]={240,200,100};

void init(){

	glClearColor(0.0,0.5,0.8,1.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);

}

void separaratorTopBuildingLine(int y){
    glColor3ub(255,255,255);
    glBegin(GL_LINES);
    glVertex2i(0,y);
    glVertex2i(1000,y);
    glEnd();
}


void buldingWindow(int locationX,int xEnd,int locationY,int yEnd){
    glColor3ub(buildingWindowColor[0],buildingWindowColor[1],buildingWindowColor[2]);
    int xct=xEnd-locationX;
    int yct=yEnd-locationY;

    cout<<xct<<yct;

    glBegin(GL_QUADS);

        /*glVertex2i((locationX+20),locationY+20);
        glVertex2i(locationX+20,locationY+50);
        glVertex2i(locationX+80,locationY+50);
        glVertex2i(locationX+80,locationY+20);*/

        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*10));
        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*25));
        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*25));
        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*10));

        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*35));
        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*50));
        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*50));
        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*35));

        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*60));
        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*75));
        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*75));
        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*60));

        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*85));
        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*95));
        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*95));
        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*85));

    glEnd();

}

void smallBuilding(int locationX,int locationY){
    glColor3ub(200,0,0);
    glBegin(GL_QUADS);
    glVertex2i(locationX,locationY);
    glVertex2i(locationX,locationY+150);
    glVertex2i(locationX+100,locationY+150);
    glVertex2i(locationX+100,locationY);
    buldingWindow(locationX,locationX+100,locationY,locationY+150);
    glEnd();

}

void bigBuilding(int locationX,int locationY){
    glColor3ub(200,0,0);
    glBegin(GL_QUADS);
    glVertex2i(locationX,locationY);
    glVertex2i(locationX,locationY+250);
    glVertex2i(locationX+100,locationY+250);
    glVertex2i(locationX+100,locationY);
    buldingWindow(locationX,locationX+100,locationY,locationY+250);
    glEnd();

}

void river(int locationX ,int locationY){
    glColor3ub(0,119,190);
    glBegin(GL_QUADS);
    glVertex2i(locationX,locationY);
    glVertex2i(locationX,locationY+300);
    glVertex2i(locationX+1000,locationY+300);
    glVertex2i(locationX+1000,locationY);
    glEnd();

}
void road(int locationX ,int locationY){
    glColor3ub(20,20,20);
    glBegin(GL_QUADS);
    glVertex2i(locationX,locationY);
    glVertex2i(locationX,locationY+270);
    glVertex2i(locationX+1000,locationY+270);
    glVertex2i(locationX+1000,locationY);
    glEnd();
    glColor3ub(200,20,20);
    glBegin(GL_QUADS);
    glVertex2i(locationX,locationY+270);
    glVertex2i(locationX,locationY+290);
    glVertex2i(locationX+1000,locationY+290);
    glVertex2i(locationX+1000,locationY+270);

    glVertex2i(locationX,locationY);
    glVertex2i(locationX,locationY-20);
    glVertex2i(locationX+1000,locationY-20);
    glVertex2i(locationX+1000,locationY);
    glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    separaratorTopBuildingLine(600);
    separaratorTopBuildingLine(300);
    smallBuilding(600,600);
    bigBuilding(300,600);
    bigBuilding(100,600);

    river(0,300);

    road(0,20);

    glFlush();

}


int main(int argc,char **argv)
{
    cout << endl << "*********** Natural View Of A Village ********************" << endl << endl;

    cout << "Press D : To Forward the Train" << endl << endl;
    cout << "Press A : To Backward the Train" << endl << endl;
    cout << "Press S : To Stop the Train" << endl << endl;

    cout << "Press R : For Rain " << endl << endl;
    cout << "Press E : For Stop Rain" << endl << endl;

    cout << "Press N : For Night " << endl << endl;
    cout << "Press B : For Day" << endl << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 1200);
	glutCreateWindow("Natural View Of A Village");     // creating the window
	//glutFullScreen();       // making the window full screen
	//glutInitWindowPosition(0,0);
	glutDisplayFunc(display);
	//glutKeyboardFunc(myKeyboard);
	//glutTimerFunc(25, update, 0);
	init();
	glutMainLoop();
	return 0;
}

