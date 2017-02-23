#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

static int year=0, day=0;

void init(){

	glClearColor(0.0, 0.0, 0.0, 0.0);

}

void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
		glRotatef((GLfloat) year, 1.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
		glutWireSphere(1.0, 20, 16);
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
		glTranslatef(2.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat) year, 0.0, -1.0, 0.0);
		glTranslatef(-2.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, -1.0, 0.0);
		glutWireSphere(0.4, 10, 8);
	glPopMatrix();
	

	glutSwapBuffers();

}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'd':
			day = (day+10)%360;
			glutPostRedisplay();
			break;
		case 'D':
			day = (day-10)%360;
			glutPostRedisplay();
			break;
		case 'y':
			year = (year+5)%360;
			glutPostRedisplay();
			break;
		case 'Y':
			year = (year-5)%360;
			glutPostRedisplay();
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	//glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Rotacao");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	
	return 0;
}