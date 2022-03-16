// Implement DDA and Bresenham's Line Drawing Algorithm to draw 1. Simple Line 2. Dotted Line 3. Dashed Line 4. Solid Line using mouse interface. Divide the Screen in four cordants with center at (0,0). The Line should work for all the slopes, Positive as well as negative. 


#include<iostream>
#include<GL/glut.h>
using namespace std;

void myInit(){
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(2.0);
	gluOrtho2D(0 , 640 , 0 , 480);

}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POINTS);
}

bool dda_line_drawing(double X1, double Y1, double X2, double Y2){
	
	double dx = X2 - X1;
	double dy = Y2 - Y1;
	double m = abs(dy/dx);
	
	cout << dx << " " << dy << " " << m << endl;
	
	double x_inc, y_inc;

	if(dx > dy && X1 < X2){
		x_inc = 1;
		y_inc = m;
	}
	else if(dx > dy && X1 > X2){
		x_inc = -1;
		y_inc = -m;
	}

	else if(dx < dy && Y1 < Y2){
		x_inc = 1/m;
		y_inc = 1;
	}

	else if(dx < dy && Y1 > Y2){
		x_inc = -1/m;
		y_inc = -1;
	}
	else{
		cout << "issue" << endl;
	}

	cout << x_inc << " " << y_inc ;
	
	double x_old = X1;
	double y_old = Y1;

	double x_new = X1;
	double y_new = Y1;

	while(x_new != X2 && y_new != Y2){
		x_new = x_old + x_inc;
		y_new = y_old + y_inc;
	
		cout << x_new << " " << y_new << endl;

		x_old = x_new;
		y_old = y_new;

//		glVertex2d(x_new,y_new);
	}

//	cout << endl << "The line is displayed on the output window." << endl;
}


int main(int argc, char **argv){
	
	double X1, X2, Y1, Y2;

	cout << endl << "Please Enter Co-ordinates for First Point (x1, y1) > ";
	cin >> X1 >> Y1;
	cout << endl << "Please Enter Co-ordinates for Second Point (x2, y2) > ";
	cin >> X2 >> Y2;

	cout << endl << "Generating a line between given points." << endl;

	dda_line_drawing(X1, Y1, X2, Y2);			
	
	//glutInit(&argc,argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowPosition(0,0);
	//glutInitWindowSize(1280,880);
	//glutCreateWindow("Sarvesh Joshi's Output");
	//myInit();
	//glutDisplayFunc(MyDisplay);
	//glutMainLoop();
	
	
	

//	glEnd();
//	glFlush();

}
