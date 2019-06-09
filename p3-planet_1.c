/* List: p3-planet.c
* The planet turns around the sun.
* Examination of world-local coordinates, modeling transfomation and
* operation of matrix stack.
*/
#include <stdlib.h>
#include <GL/glut.h>

static double year = 0.0, day = 0.0;
unsigned char	mouseFlag = GL_FALSE;		// flag for moving or not
int xStart, yStart;				// start position when drug begins
double xAngle = 0.0, yAngle = 0.0;	// angles of the teapot


void myInit(char *progname)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(progname);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 1.0);

	glutWireSphere(1.0, 20, 16);   /* sun */

	glPushMatrix();
		glRotated((double)year/0.241, 0.0, 1.0, 0.0);
		glTranslated(2.0, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet 1*/
	glPopMatrix();

	glPushMatrix();
		glRotated((double)year/0.615, 0.0, 1.0, 0.0);
		glTranslated(3.0, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet 2*/
	glPopMatrix();

	glPushMatrix();
		glRotated((double)year, 0.0, 1.0, 0.0);
		glTranslated(4.0, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet 3*/
	glPopMatrix();

	glPushMatrix();
		glRotated((double)year/1.881, 0.0, 1.0, 0.0);
		glTranslated(5.0, 0.0, 0.0);
		glRotated((double)day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);    /* planet 4*/
	glPopMatrix();
	
	glutSwapBuffers();
}

void myReshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (double)width / (double)height, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 3.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void myIdle(void)
{
	year = year + 0.1;
	glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'd':
		day = (day + 10.0);
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10.0);
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5.0);
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5.0);
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void myMouseMotion(int x, int y)
{
	int		xdis, ydis;
	double	a = 0.5;

	if (mouseFlag == GL_FALSE) return;
	xdis = x - xStart;
	ydis = y - yStart;
	/* To match mouse's movement and its rotation axis */
	xAngle += (double)ydis * a;
	yAngle += (double)xdis * a;

	xStart = x;
	yStart = y;
	glutPostRedisplay();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xStart = x;
		yStart = y;
		mouseFlag = GL_TRUE;
	}
	else {
		mouseFlag = GL_FALSE;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	myInit(argv[0]);
	glutKeyboardFunc(myKeyboard);
	glutMouseFunc(myMouseFunc);
	glutMotionFunc(myMouseMotion);
	glutIdleFunc(myIdle);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
