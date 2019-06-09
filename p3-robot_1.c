/* List: p3-robot.c
* Robot arm with two links and two joints.
* Examination of world-local coordinates, modeling transfomation and
* operation of matrix stack.
*/
#include <stdlib.h>
#include <GL/glut.h>

static int  r_shoulder = 0, r_elbow = 65, r_elbow2 = 15, body = 0, head = 0,
l_shoulder = 0, l_elbow = 115, l_elbow2 = 160, body2 = 0, body3 = 0, r_knee = 0, r_knee2 = 0,
r_knee3 = 0, r_foot = 0, l_knee = 0, l_knee2 = 0, l_knee3 = 0, l_foot = 0,
r_hand = 0, r_hand2 = 0, l_hand = 0, l_hand2 = 0, r_eye = 0, l_eye = 0,
r_horn = 105, r_horn2 = 10, l_horn = 45, l_horn2 = -10, maru = 0, motite = 75, bi_mu = 0,
shield = 0;

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

	//“·‘Ì
	glPushMatrix();
	glRotated((double)body, 0.0, 0.0, 0.0);
	glTranslated(0.0, 0.0, 0.0);
	glPushMatrix();
	glScaled(1.0, 1.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	//“ª
	glPushMatrix();
	glRotated((double)head, 0.0, 0.0, 0.0);
	glTranslated(0.0, 1.0, 0.0);
	glPushMatrix();
	glScaled(1.0, 1.0, 1.0);
	glutWireCube(0.5);
	glPopMatrix();

	//‰EŒ¨
	glPushMatrix();
	glRotated((double)r_shoulder, 1.0, 0.0, 0.0);
	glTranslated(-0.7, 0.5, 0.0);
	glPushMatrix();
	glScaled(0.6, 0.3, 1.0);
	glutWireCube(1.0);
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
	gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 's':
		r_shoulder = (r_shoulder + 5) % 360;
		l_shoulder = (l_shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		r_shoulder = (r_shoulder - 5) % 360;
		l_shoulder = (l_shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		r_elbow = (r_elbow + 5) % 360;
		l_elbow = (l_elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		r_elbow2 = (r_elbow2 - 5) % 360;
		l_elbow2 = (l_elbow2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'h':
		r_hand = (r_hand + 5) % 360;
		l_hand = (l_hand + 5) % 360;
		glutPostRedisplay();
		break;
	case 'H':
		r_hand2 = (r_hand2 - 5) % 360;
		l_hand2 = (l_hand2 - 5) % 360;
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	myInit(argv[0]);
//	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
