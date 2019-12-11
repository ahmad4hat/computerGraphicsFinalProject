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


//void buldingWindow(int locationX,int locationY){
//    glColor3ub(buildingWindowColor[0],buildingWindowColor[1],buildingWindowColor[2]);
////    int xct=xEnd-locationX;
////    int yct=yEnd-locationY;
//
//
//    glBegin(GL_QUADS);
//
//         glVertex2i((locationX+20),locationY+20);
//        glVertex2i(locationX+20,locationY+50);
//        glVertex2i(locationX+80,locationY+50);
//        glVertex2i(locationX+80,locationY+20);
//
//        /*glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*10));
//        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*25));
//        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*25));
//        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*10));
//
//        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*35));
//        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*50));
//        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*50));
//        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*35));
//
//        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*60));
//        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*75));
//        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*75));
//        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*60));
//
//        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*85));
//        glVertex2i(locationX+((xct/100)*20),locationY+((yct/100)*95));
//        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*95));
//        glVertex2i(locationX+((xct/100)*80),locationY+((yct/100)*85));*/
//
//    glEnd();
//
//}

void buildWindow(int xw,int yw){
    glPushMatrix();
    glColor3ub(buildingWindowColor[0],buildingWindowColor[1],buildingWindowColor[2]);
        glBegin(GL_QUADS);
        glVertex2i((xw+20),yw+20);
        glVertex2i(xw+20,yw+50);
        glVertex2i(xw+80,yw+50);
        glVertex2i(xw+80,yw+20);
        glEnd();
        glPopMatrix();
}

void smallBuilding(int locationX,int locationY){
    glPushMatrix();
    glColor3ub(200,0,0);
    glBegin(GL_QUADS);
    glVertex2i(locationX,locationY);
    glVertex2i(locationX,locationY+150);
    glVertex2i(locationX+100,locationY+150);
    glVertex2i(locationX+100,locationY);
    //buildWindow(locationX,locationY);
    buildWindow(locationX,locationY);
    buildWindow(locationX,locationY+45);
    buildWindow(locationX,locationY+90);

    glEnd();
    glPopMatrix();

}

void bigBuilding(int locationX,int locationY){
    glPushMatrix();
    glColor3ub(200,0,0);
    glBegin(GL_QUADS);
    glVertex2i(locationX,locationY);
    glVertex2i(locationX,locationY+250);
    glVertex2i(locationX+100,locationY+250);
    glVertex2i(locationX+100,locationY);
    //buldingWindow(locationX,locationX+100,locationY,locationY+250);
    buildWindow(locationX,locationY);
    buildWindow(locationX,locationY+45);
    buildWindow(locationX,locationY+90);
    buildWindow(locationX,locationY+135);
    buildWindow(locationX,locationY+180);
    glEnd();
    glPopMatrix();

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
    glColor3ub(250,250,250);
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

    for(int i=0;i<=1000;i+=100){
         glColor3ub(200,200,200);
         glBegin(GL_QUADS);
         glVertex2i(i,locationY+140);
         glVertex2i(i,locationY+160);
         glVertex2i(i+100,locationY+160);
         glVertex2i(i+100,locationY+140);

         glEnd();
         i=i+20;
    }
    for(int i=0;i<=1000;i+=100){
         glColor3ub(5,5,5);
         glBegin(GL_QUADS);
         glVertex2i(i,locationY+270);
         glVertex2i(i,locationY+290);
         glVertex2i(i+100,locationY+290);
         glVertex2i(i+100,locationY+270);

         glVertex2i(i,locationY);
        glVertex2i(i,locationY-20);
        glVertex2i(i+100,locationY-20);
        glVertex2i(i+100,locationY);

         glEnd();
         i=i+89;
    }
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
    separaratorTopBuildingLine(600);
    separaratorTopBuildingLine(300);
    smallBuilding(600,600);
    smallBuilding(750,600);
     bigBuilding(880,600);
     smallBuilding(30,600);


    //buldingWindow(600,600+100,600,600+150);
    bigBuilding(300,600);
    smallBuilding(450,600);


    bigBuilding(150,600);


    river(0,300);

    road(0,20);
    glPopMatrix();


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

