#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdlib>

using namespace std;
GLsizei winWidth = 1000, winHeight = 600;
GLfloat r=0,g=0,b=0;
GLint t=0, h1=200, h2=200, h3=200, h4=200, h5=200;

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 600);
}

void drawQuads(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2i(0, h1);
		glVertex2i(0, (h1+200));
		glVertex2i(200, (h1+200));
		glVertex2i(200, h1);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2i(200, h2);
		glVertex2i(200, (h2+200));
		glVertex2i(400, (h2+200));
		glVertex2i(400, h2);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2i(400, h3);
		glVertex2i(400, (h3+200));
		glVertex2i(600, (h3+200));
		glVertex2i(600, h3);
	glEnd();	

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2i(600, h4);
		glVertex2i(600, (h4+200));
		glVertex2i(800, (h4+200));
		glVertex2i(800, h4);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2i(800, h5);
		glVertex2i(800, (h5+200));
		glVertex2i(1000, (h5+200));
		glVertex2i(1000, h5);
	glEnd();

	glFlush();
}

void wave(){
	
	if(t==0){
		h1 = 200;
		h2 = 200;
		h3 = 200;
		h4 = 200;
		h5 = 200;
		drawQuads();
		t++;
	}
	else if(t==1){
		h1 = 300;
		h2 = 200;
		h3 = 200;
		h4 = 200;
		h5 = 200;
		drawQuads();
		t++;
	}
	else if(t==2){
		h1 = 400;
		h2 = 300;
		h3 = 200;
		h4 = 200;
		h5 = 200;
		drawQuads();
		t++;
	}
	else if(t==3){
		h1 = 300;
		h2 = 400;
		h3 = 300;
		h4 = 200;
		h5 = 200;
		drawQuads();
		t++;
	}
	else if(t==4){
		h1 = 200;
		h2 = 300;
		h3 = 400;
		h4 = 300;
		h5 = 200;
		drawQuads();
		t++;
	}
	else if(t==5){
		h1 = 100;
		h2 = 200;
		h3 = 300;
		h4 = 400;
		h5 = 300;
		drawQuads();
		t++;
	}
	else if(t==6){
		h1 = 0;
		h2 = 100;
		h3 = 200;
		h4 = 300;
		h5 = 400;
		drawQuads();
		t++;
	}
	else if(t==7){
		h1 = 100;
		h2 = 0;
		h3 = 100;
		h4 = 200;
		h5 = 300;
		drawQuads();
		t++;
	}
	else if(t==8){
		h1 = 200;
		h2 = 100;
		h3 = 0;
		h4 = 100;
		h5 = 200;
		drawQuads();
		t++;
	}
	else if(t==9){
		h1 = 200;
		h2 = 200;
		h3 = 100;
		h4 = 0;
		h5 = 100;
		drawQuads();
		t++;
	}
	else if(t==10){
		h1 = 200;
		h2 = 200;
		h3 = 200;
		h4 = 100;
		h5 = 0;
		drawQuads();
		t++;
	}
	else if(t==11){
		h1 = 200;
		h2 = 200;
		h3 = 200;
		h4 = 200;
		h5 = 100;
		drawQuads();
		t++;
	}
	else if(t==12){
		h1 = 200;
		h2 = 200;
		h3 = 200;
		h4 = 200;
		h5 = 200;
		drawQuads();
		t++;
	}
	else{
		t = 0;
		//cout<<"Entrou no else"<<endl;
	}
	
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse){
	if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
		wave();
		//cout<<"t da funcao"<<t<<endl;
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
	glutDisplayFunc(drawQuads);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mousePtPlot);
	
	glutMainLoop();
	
	return 0;
}