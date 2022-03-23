// Implement DDA and Bresenham's Line Drawing Algorithm to draw 1. Simple Line 2. Dotted Line 3. Dashed Line 4. Solid Line using mouse interface. Divide the Screen in four cordants with center at (0,0). The Line should work for all the slopes, Positive as well as negative. 


#include<iostream>
#include<GL/glut.h>
double radius, XCenter, YCenter;

using namespace std;

bool bresenhamCircleDrawing();
bool symmetry(double x, double y);

void myInit(){
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	gluOrtho2D(320 , -320 , 240 , -240);
}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2d(320, 0);
	glVertex2d(-320, 0);
	glVertex2d(0, 240);
	glVertex2d(0, -240);
	glEnd();

		
	glBegin(GL_POINTS);
	bresenhamCircleDrawing();
	glEnd();
	glFlush();
	
}


bool symmetry(double x, double y, double xc, double yc){
	glVertex2d(x + xc, y + yc);
	glVertex2d(-x + xc, y + yc);
	glVertex2d(x + xc, -y + yc);
	glVertex2d(-x + xc, -y + yc);
	glVertex2d(y + yc, x + xc);
	glVertex2d(-y + yc, x + xc);
	glVertex2d(y + yc, -x + xc);
	glVertex2d(-y + yc, -x + xc);
}



bool bresenhamCircleDrawing(){
	double x = 0, y = radius;
	double sum = 3 - 2 * radius;
	
	while(x < y){
		if(sum <= 0){
			sum += 4 * x + 6;
			x++; 	
		}
		else{
			sum += 4 * x - 4 * y  + 10;
			x++; y--;
		}
		symmetry(x, y, XCenter, YCenter);
	}
}

int main(int argc, char **argv){
	cout << "Please enter radius of the Required Circle > ";
	cin >> radius;
	cout << endl << "Please Enter Center Point (XC, YC) of circle > ";
	cin >> XCenter >> YCenter;
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1280,840);
	glutCreateWindow("Sarvesh Joshi's Output");
	myInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	
}
