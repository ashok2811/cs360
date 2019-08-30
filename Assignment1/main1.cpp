#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace  std;

GLfloat Tx,Ty,Tz;
GLfloat Rx,Ry,Rz;
GLfloat Sx,Sy,Sz;

GLfloat px = 0.0;
GLfloat py = 0.0;
GLfloat pz = 0.0;


void drawBox{
	public:

		GLfloat xt=0.0;
		GLfloat yt=0.0;
		GLfloat zt=14.0;
		GLfloat dx = 1.0;
		GLfloat dy = 1.0;
		GLfloat dz = 1.0;


		float ver[8][3] = 
		{
			{xt,yt,zt},
			{xt,yt+dy,zt},
			{xt+dx,yt+dy,zt},
			{xt+dx,yt,zt},
			{xt,yt,zt-dz},
			{xt,yt+dy,zt-dz},
			{xt+dx,yt+dy,zt-dz},
			{xt+dx,yt,zt-dz},
		};

		GLfloat color[8][3] = 
		{
			{0.0,0.0,0.0},
			{1.0,0.0,0.0},
			{1.0,1.0,0.0},
			{0.0,1.0,0.0},
			{0.0,0.0,1.0},
			{1.0,0.0,1.0},
			{1.0,1.0,1.0},
			{0.0,1.0,1.0},
		};


		void quad(int a,int b,int c,int d)
		{
			glBegin(GL_QUADS);
			glColor3fv(color[a]);
			glVertex3fv(ver[a]);

			glColor3fv(color[b]);
			glVertex3fv(ver[b]);

			glColor3fv(color[c]);
			glVertex3fv(ver[c]);

			glColor3fv(color[d]);
			glVertex3fv(ver[d]);
			glEnd();
		}

		void colorcube()
		{	
		
			quad(0,3,2,1);
			quad(2,3,7,6);
			quad(0,4,7,3);
			quad(1,2,6,5);
			quad(4,5,6,7);
			quad(0,1,5,4);
			
			
		}


		drawBox(){
			colorcube();
		}
};





void renderScene(void){
	glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 100 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
	glColor3f(0.412, 0.412, 0.412); 

	// changing in transformation matrix.
	glTranslatef(Tx, Ty, Tz);
	
	glRotatef(Rx, 1.0f, 0.0f, 0.0f);
	glRotatef(Ry, 0.0f, 1.0f, 0.0f);
	glRotatef(Rz, 0.0f, 0.0f, 1.0f);

	glScalef(Sx, Sy, Sz);	
   
	glBegin(GL_QUADS);
    glColor3f( 0.137, 0.121, 0.258); 
    glVertex3f(-20.0f, 0.0f, -15.0f);
    glColor3f( 0.137, 0.121, 0.258);
    glVertex3f(20.0f, 0.0f, -15.0f);
    glColor3f(  0.886, 0.070, 0.372 ); 
    glVertex3f(20.0f, 0.0f, 15.0f);
    glColor3f(  0.886, 0.070, 0.372 );
    glVertex3f(-20.0f, 0.0f, 15.0f);

	glEnd();

	
	drawBox b1 ;
	b1.xt = b1.xt + px;
	b1.yt = b1.yt + py;
	drawBox b2;
	glFlush();
	glutSwapBuffers();
}

void changeSize(int x, int y){
    if (y == 0 || x == 0) return;

    GLfloat aspect = (GLfloat)(x/y);

    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0, 1, 0);
    gluPerspective(45.0f,aspect,0.1f, 10000.0f);
    glViewport(0,0,x,y);
    glMatrixMode(GL_MODELVIEW);
}

void specialKeys( int key, int x, int y ) 
{
	
    if (key == GLUT_KEY_RIGHT)
        px += 0.5;
    else if (key == GLUT_KEY_LEFT)
      	 px -= 0.5;
    else if (key == GLUT_KEY_UP)
        pz += 0.5;
    else if (key == GLUT_KEY_DOWN)
        pz -= 0.5;
    glutPostRedisplay();
}

void animate(void){
	
	renderScene();
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Assignment1");
	
	Tx = 0.0; Ty = -14.0; Tz = -40.0;
	Rx = 0.0; Ry = 0.0; Rz = 0.0;
	Sx = 1.0f; Sy = 1.0; Sz = 1.0;
	//Assign  the function used in events
	
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	 glutSpecialFunc( specialKeys );
    glEnable( GL_DEPTH_TEST );

	//glutIdleFunc(animate);					//for animation uncomment

	//Let start glut loop
	glutMainLoop();

	return 0;
}
