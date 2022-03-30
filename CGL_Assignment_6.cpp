// Implement DDA and Bresenham's Line Drawing Algorithm to draw 1. Simple Line 2. Dotted Line 3. Dashed Line 4. Solid Line using mouse interface. Divide the Screen in four cordants with center at (0,0). The Line should work for all the slopes, Positive as well as negative. 


#include<iostream>
#include<stdlib.h>
#include<vector>
#include <GL/glut.h>

int number_of_vertices = 4;
int originalVertices[4][3];
int resultant[4][3] = {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}};

using namespace std;

void drawPolygon(int vertices[4][3]){

	glBegin(GL_LINE_LOOP);
	
	for(int i = 0; i < 4; i++){
		glVertex2i(vertices[i][0], vertices[i][1]);
	}
	glEnd();
}




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
	glBegin(GL_LINE_LOOP);
	drawPolygon(originalVertices);
	glEnd();

	glBegin(GL_LINE_LOOP);
	drawPolygon(resultant);
	glEnd();
	glFlush();
	
}

void scailing(int vertices[4][3]){
	
	int scailingX, scailingY;
	
	cout << endl << "Please Enter Scailing Factors (X, Y)";
	cin >> scailingX >> scailingY;

	for(int i = 0; i < 4; i++){
		resultant[i][0] = vertices[i][0] * scailingX;
		resultant[i][1] = vertices[i][1] * scailingY;
	}	
	drawPolygon(resultant);
}

void menu(int item){
	if(item == 1)
		scailing(originalVertices);
//	else if(item == 2)
		//translation(originalVertices);
//	else if(item == 3)
		//reflection(originalVertices);
//	else
		//rotation(originalVertices);
}



int main(int argc, char **argv){
	// Accepting Vertices of Polygon.

	cout << "Please Enter 4 Vertices of your Polygon >" << endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			if(j == 2){
				originalVertices[i][j]  = 1;
				continue;
			}
			else if(j == 1)
				cout << "Please Enter y Co-ordinate of the Point #" << i+1 << " >" << endl;
			else
				cout << "Please Enter X Co-ordinate of the Point #" << i+1 << " >" << endl;
			cin >> originalVertices[i][j];		
		}
	}

	cout << "Co-ordinates saved successfully!" << endl;

	drawPolygon(originalVertices);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1280,840);
	glutCreateWindow("Sarvesh Joshi's Output");
	myInit();
	glutDisplayFunc(MyDisplay);
	glutCreateMenu (menu); //Create the first menu & add items
	glutAddMenuEntry ("1. Scailing", 1); //choices
	glutAddMenuEntry ("2. Translation", 2);
	glutAddMenuEntry ("3. Rotation", 3);
	glutAddMenuEntry ("4. Reflexation", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON); //on mouse right click show menu
	glutMainLoop();
	}
