#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void draw(){

	glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	glTranslatef(0.0f, 0.5, 0.0f);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.1, 15, 15);

	glLoadIdentity();
	glTranslatef(0.5, 0.0f, 0.0f);
	glColor3f(1.0, 0.0, 1.0);
	glutSolidSphere(0.1, 15, 15);

	glFlush();

}

int main(int argc, char** argv){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	//glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Teste de Translacao");
	
	init();
	glutDisplayFunc(draw);

	glutMainLoop();
	
	return 0;
}