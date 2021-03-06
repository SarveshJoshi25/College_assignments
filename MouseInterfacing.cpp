#include <iostream>
#include <GL/glut.h>
using namespace std;
double x1, y1;
int Xsize, YSize;
double radius = 45, XCenter, YCenter;
double xnew, ynew;

void myInit(){
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(2.0);

	gluOrtho2D(-320 , 320 , -240 , 240);
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


void myMouse(int button, int state, int x, int y){
	if(state== GLUT_DOWN){
		if(button==GLUT_LEFT_BUTTON){
			x1=x;
			y1=y;
			glBegin(GL_POINTS);
			XCenter = (x - 320) * -1; YCenter = y - 240;
			cout << XCenter << endl << YCenter;
			bresenhamCircleDrawing();
			//glVertex2f((x-320) * -1 , (y-240));
			glEnd();
			glFlush();
		}
		else if(button==GLUT_RIGHT_BUTTON){
			glClearColor(1.0f,0.0f,0.0f,0.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
		}
	}
	return;}



void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);

	glVertex2d(320, 0);
	glVertex2d(-320, 0);
	glVertex2d(0, 240);
	glVertex2d(0, -240);

	glEnd();

	glBegin(GL_POINTS);
	glEnd();
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("Sarvesh Joshi's Output");
	myInit();
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(myMouse);
	glutMainLoop();
}
