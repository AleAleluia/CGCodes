#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdlib>

using namespace std;
GLsizei winWidth = 500, winHeight = 500;
GLfloat p1[3], p2[3], p3[4], p4[3], a[3];

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 500);

	p1[0] = 1.0;
	p1[1] = 0.0;
	p1[2] = 0.0;

	p2[0] = 0.0;
	p2[1] = 1.0;
	p2[2] = 0.0;

	p3[0] = 0.0;
	p3[1] = 0.0;
	p3[2] = 1.0;

	p4[0] = 0.0;
	p4[1] = 0.0;
	p4[2] = 0.0;
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

	glColor3f(p1[0], p1[1], p1[2]);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(100, 150);
		glVertex2i(100, 250);
	glEnd();

	glColor3f(p2[0], p2[1], p2[2]);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(200, 350);
		glVertex2i(300, 350);
	glEnd();

	glColor3f(p3[0], p3[1], p3[2]);	
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(400, 150);
		glVertex2i(400, 250);
	glEnd();
	

	glColor3f(p4[0], p4[1], p4[2]);
	glBegin(GL_TRIANGLES);
		glVertex2i(250,200);
		glVertex2i(200, 50);
		glVertex2i(300, 50);
	glEnd();
	
	glFlush();
}

void rotateFlower(){
	
	a[0] = p1[0];
	a[1] = p1[1];
	a[2] = p1[2];

	p1[0] = p2[0];
	p1[1] = p2[1];
	p1[2] = p2[2];

	p2[0] = p3[0];
	p2[1] = p3[1];
	p2[2] = p3[2];

	p3[0] = p4[0];
	p3[1] = p4[1];
	p3[2] = p4[2];

	p4[0] = a[0];
	p4[1] = a[1];
	p4[2] = a[2];	
}

void rotateFlowerTwo(){
	
	a[0] = p1[0];
	a[1] = p1[1];
	a[2] = p1[2];

	p1[0] = p4[0];
	p1[1] = p4[1];
	p1[2] = p4[2];

	p4[0] = p3[0];
	p4[1] = p3[1];
	p4[2] = p3[2];

	p3[0] = p2[0];
	p3[1] = p2[1];
	p3[2] = p2[2];

	p2[0] = a[0];
	p2[1] = a[1];
	p2[2] = a[2];	
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){
	if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
		rotateFlower();
		drawFlower();
	}
	if(button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN){
		rotateFlowerTwo();
		drawFlower();
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