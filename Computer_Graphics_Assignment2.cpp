// Implement DDA and Bresenham's Line Drawing Algorithm to draw 1. Simple Line 2. Dotted Line 3. Dashed Line 4. Solid Line using mouse interface. Divide the Screen in four cordants with center at (0,0). The Line should work for all the slopes, Positive as well as negative. 


#include<iostream>
#include<GL/glut.h>
double X1, X2, Y1, Y2;
int choice;
using namespace std;

bool dda_line_drawing(double X1, double Y1, double X2, double Y2);
bool dda_line_drawing_dotted(double X1, double Y1, double X2, double Y2);
bool dda_line_drawing_dashed(double X1, double Y1, double X2, double Y2);

void myInit(){
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(16.0);
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
	glBegin(GL_LINES);

	switch(choice){
		case 1:
			dda_line_drawing(X1, Y1, X2, Y2);		
			break;
		case 2:
			dda_line_drawing_dotted(X1, Y1, X2, Y2);		
			break;
		case 3:
			dda_line_drawing_dashed(X1, Y1, X2, Y2);
			break;
		default:
			cout << "error" << endl;
		
	}

	glEnd();
	glFlush();	
}

bool dda_line_drawing(double X1, double Y1, double X2, double Y2){
	double dx = abs(X2 - X1);
	double dy = (Y2 - Y1);
	double m = abs(dy/dx);
	
	
	double x_inc, y_inc;

	if(dx >= dy && X1 < X2){
		x_inc = 1;
		y_inc = m;
	}
	else if(dx >= dy && X1 > X2){
		x_inc = -1;
		y_inc = -m;
	}

	else if(dx < dy && Y1 < Y2){
		x_inc = 1/m;
		y_inc = 1;
	}

	else{
		x_inc = -1/m;
		y_inc = -1;
	}

	double x_new = X1;
	double y_new = Y1;

	glVertex2d(x_new,y_new);

	while(x_new != X2 && y_new != Y2){
		x_new += x_inc;
		y_new += y_inc;
	
		glVertex2d(x_new,y_new);
	}

	cout << endl << "The line is displayed on the output window." << endl;

	return true;
}

bool dda_line_drawing_dotted(double X1, double Y1, double X2, double Y2){
	double dx = abs(X2 - X1);
	double dy = (Y2 - Y1);
	double m = abs(dy/dx);
	
	
	double x_inc, y_inc;

	if(dx >= dy && X1 < X2){
		x_inc = 1;
		y_inc = m;
	}
	else if(dx >= dy && X1 > X2){
		x_inc = -1;
		y_inc = -m;
	}

	else if(dx < dy && Y1 < Y2){
		x_inc = 1/m;
		y_inc = 1;
	}

	else{
		x_inc = -1/m;
		y_inc = -1;
	}

	double x_new = X1;
	double y_new = Y1;

	glVertex2d(x_new,y_new);
	bool should_display = false;

	while(x_new != X2 && y_new != Y2){
		x_new += x_inc;
		y_new += y_inc;
		
		if(should_display)
			glVertex2d(x_new,y_new);
		should_display = !(should_display);
	}

	cout << endl << "The line is displayed on the output window." << endl;

	return true;
}

bool dda_line_drawing_dashed(double X1, double Y1, double X2, double Y2){
	double dx = abs(X2 - X1);
	double dy = (Y2 - Y1);
	double m = abs(dy/dx);
	
	
	double x_inc, y_inc;

	if(dx >= dy && X1 < X2){
		x_inc = 1;
		y_inc = m;
	}
	else if(dx >= dy && X1 > X2){
		x_inc = -1;
		y_inc = -m;
	}

	else if(dx < dy && Y1 < Y2){
		x_inc = 1/m;
		y_inc = 1;
	}

	else{
		x_inc = -1/m;
		y_inc = -1;
	}

	double x_new = X1;
	double y_new = Y1;

	glVertex2d(x_new,y_new);
	int some = 0;

	while(x_new != X2 && y_new != Y2){
		x_new += x_inc;
		y_new += y_inc;
		
		if(some % 5 != 0)
			glVertex2d(x_new,y_new);
		some++;
	}

	cout << endl << "The line is displayed on the output window." << endl;

	return true;
}



int main(int argc, char **argv){
	
	

	cout << endl << "Please Enter Co-ordinates for First Point (x1, y1) > ";
	cin >> X1 >> Y1;
	cout << endl << "Please Enter Co-ordinates for Second Point (x2, y2) > ";
	cin >> X2 >> Y2;

	cout << endl << "Please Enter 1 to Display the Line in Normal Way \nPlease Enter 2 to Display Line in Dotted Way \nPlease Enter 3 to Display Line in Dashed way \n>" << endl;


	cin >> choice;
	
	cout << endl << "Generating a line between given points." << endl;

	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(480,480);
	glutCreateWindow("Sarvesh Joshi's Output");
	myInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
}
