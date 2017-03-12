#include <GL/freeglut.h>
#include <GL/gl.h>

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINES);
		glVertex2i(0,0);
		glVertex2i(200, 150);
	glEnd();

	glFlush();
}

int main (int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutCreateWindow("OpenGL Test");
	glutInitWindowSize(500, 500);

	init();
	glutDisplayFunc(lineSegment);

	glutMainLoop();
}