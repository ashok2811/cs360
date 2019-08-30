#include <GL/gl.h>
#include <GL/glut.h>

GLfloat angle = 0.0; //angle for cube1
GLfloat tangle = 0.0; //angle for cube2

void cube (void) {
glPushMatrix(); //set where to start the current object transformations
glTranslatef(1, 0, 0); //move cube1 to the right
glRotatef(angle, 1.0, 0.0, 0.0);
glRotatef(angle, 0.0, 1.0, 0.0);
glRotatef(angle, 0.0, 0.0, 1.0);
glColor3f(1.0, 0.0, 0.0); //change cube1 to red
glutWireCube(2);
glPopMatrix(); //end the current object transformations
}

void cube2 (void) {
glPushMatrix(); //set where to start the current object transformations
glTranslatef(-1, 0, 0); //move cube2 to the left
glRotatef(tangle, 1.0, 0.0, 0.0);
glRotatef(tangle, 0.0, 1.0, 0.0);
glRotatef(tangle, 0.0, 0.0, 1.0);
glColor3f(0.0, 1.0, 0.0); //change cube2 to green
glutWireCube(2);
glPopMatrix(); //end the current object transformations
}

void display (void) {
glClearColor (0.0,0.0,0.0,1.0);
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
cube();
cube2();
glutSwapBuffers();
angle = 1.0;
tangle = 2.0;
}

void reshape (int w, int h) {
glViewport (0, 0, (GLsizei)w, (GLsizei)h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv) {
glutInit (&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Ashok");
glutDisplayFunc (display);
glutIdleFunc (display);
glutReshapeFunc (reshape);
glutMainLoop ();
return 0;
}