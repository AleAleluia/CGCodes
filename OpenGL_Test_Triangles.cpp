#include <GL/freeglut.h>
#include <GL/gl.h>

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

int main (int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutCreateWindow("OpenGL Test");
	glutInitWindowSize(500, 500);

	init();
	glutDisplayFunc(drawFlower);

	glutMainLoop();
}