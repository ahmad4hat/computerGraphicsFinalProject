#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

float _run3 = 0.0;


int buildingWindowColor[]={240,200,100};
int sunOrMoonColor[]={200,200,200};

int cloudColor[]={255,255,255};

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
    glColor3ub(0,150,190);
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

void cloud(){
   ///Cloud

    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
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
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(290, 760, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
//end of cloud

}
void drawCircle( GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides )
{
    int numberOfVertices = numberOfSides + 2;

    GLfloat twicePi = 2.0f * M_PI;

    GLfloat circleVerticesX[numberOfVertices];
    GLfloat circleVerticesY[numberOfVertices];
    GLfloat circleVerticesZ[numberOfVertices];

    circleVerticesX[0] = x;
    circleVerticesY[0] = y;
    circleVerticesZ[0] = z;

    for ( int i = 1; i < numberOfVertices; i++ )
    {
        circleVerticesX[i] = x + ( radius * cos( i *  twicePi / numberOfSides ) );
        circleVerticesY[i] = y + ( radius * sin( i * twicePi / numberOfSides ) );
        circleVerticesZ[i] = z;
    }

    GLfloat allCircleVertices[( numberOfVertices ) * 3];

    for ( int i = 0; i < numberOfVertices; i++ )
    {
        allCircleVertices[i * 3] = circleVerticesX[i];
        allCircleVertices[( i * 3 ) + 1] = circleVerticesY[i];
        allCircleVertices[( i * 3 ) + 2] = circleVerticesZ[i];
    }

    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, allCircleVertices );
    glDrawArrays( GL_TRIANGLE_FAN, 0, numberOfVertices);
    glDisableClientState( GL_VERTEX_ARRAY );
}

void sunOrMoon(){
    glColor3ub(sunOrMoonColor[0],sunOrMoonColor[1],sunOrMoonColor[2]);
     drawCircle( 800, 920, 0, 65, 1000 );

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	sunOrMoon();
	glPopMatrix();

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

    cloud();


    glFlush();
}
void update(int value) {



     _run3 += 0.8f;
	if (_run3 > 1000)
    {
        _run3 -= 1700;
    }

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);
}

void myKeyboard(unsigned char key, int x, int y){
	switch (key)
	{
    case 'd':
        buildingWindowColor[0]=90;
        buildingWindowColor[1]=90;
        buildingWindowColor[2]=90;
         sunOrMoonColor[0]=240;
         sunOrMoonColor[1]=240;
         sunOrMoonColor[2]=150;

        break;
    case 'n':
        buildingWindowColor[0]=240;
        buildingWindowColor[1]=200;
        buildingWindowColor[2]=100;
         sunOrMoonColor[0]=200;
         sunOrMoonColor[1]=200;
         sunOrMoonColor[2]=200;

        break;

	default:
	break;
	}
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
	glutInitWindowSize(1800, 1200);
	glutCreateWindow("Natural View Of A Village");     // creating the window
	//glutFullScreen();       // making the window full screen
	//glutInitWindowPosition(0,0);
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(25, update, 0);
	init();
	glutMainLoop();
	return 0;
}

