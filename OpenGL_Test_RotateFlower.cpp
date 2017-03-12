#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdlib>

using namespace std;
GLsizei winWidth = 500, winHeight = 500;
GLfloat r=0,g=0,b=0;

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500);
}

void drawFlower(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2i(240,0);
		glVertex2i(240, 200);
		glVertex2i(260, 200);
		glVertex2i(260, 0);
	glEnd();	

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(100, 150);
		glVertex2i(100, 250);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(400, 150);
		glVertex2i(400, 250);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(200, 50);
		glVertex2i(300, 50);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(200, 350);
		glVertex2i(300, 350);
	glEnd();

	glFlush();
}

void changeColors(){
	r = (rand()%255);
	g = (rand()%255);
	b = (rand()%255);
	r = r/255;
	g = g/255;
	b = b/255;
}

void plotPoint(GLint x, GLint y){
	
	changeColors();
	cout<<"r: "<<r<<endl;
	cout<<"g: "<<g<<endl;
	cout<<"b: "<<b<<endl;
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(100, 150);
		glVertex2i(100, 250);
	glEnd();

	changeColors();
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(400, 150);
		glVertex2i(400, 250);
	glEnd();

	changeColors();
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(200, 50);
		glVertex2i(300, 50);
	glEnd();

	changeColors();
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(200, 350);
		glVertex2i(300, 350);
	glEnd();
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){
	if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
		int x1 = xMouse;
		int y1 = winHeight - yMouse;
		plotPoint(x1, y1);
		cout<<"x1 da funcao"<<x1<<endl;
		cout<<"y1 da funcao"<<y1<<endl;
	}
	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight), -1.0, 1.0);
	winWidth = newWidth;
	winHeight = newHeight;
}

int main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	//glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Troca de Cores");
	
	init();
	glutDisplayFunc(drawFlower);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mousePtPlot);
	
	glutMainLoop();
	
	return 0;
}