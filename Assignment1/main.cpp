#include <GL/glut.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace  std;

GLfloat Tx,Ty,Tz;
GLfloat Rx,Ry,Rz;
GLfloat Sx,Sy,Sz;

GLfloat qx = 0.0;
GLfloat qy = 0.0;
GLfloat qz = 0.0;

class ground{

	public:


	void draw(){		

		glBegin(GL_QUADS);
		glColor3f( 0.137, 0.121, 0.258); 
		glVertex3f(-40.0f, -2.0f, -30.0f);
		glColor3f( 0.137, 0.121, 0.258);
		glVertex3f(40.0f, -2.0f, -30.0f);
		glColor3f(  0.886, 0.070, 0.372 ); 
		glVertex3f(40.0f, -2.0f, 30.0f);
		glColor3f(  0.886, 0.070, 0.372 );
		glVertex3f(-40.0f, -2.0f, 30.0f);

		glEnd();
	}	

};

class drawBox{


	public:


		GLfloat px = 0.0;
		GLfloat py = 0.0;
		GLfloat pz = 0.0;
		GLfloat rx = 0.0;
		GLfloat ry = 0.0;
		GLfloat rz = 0.0;
		GLfloat sx = 1.0;
		GLfloat sy = 1.0;
		GLfloat sz = 1.0;
		GLfloat rr = 1.0;
		GLfloat gg = 1.0;
		GLfloat bb = 1.0;



		GLfloat xt =0.0;
		GLfloat yt =0.0;
		GLfloat zt = 0.0;
		GLfloat dx = 1.0;
		GLfloat dy = 1.0;
		GLfloat dz =1.0;

		drawBox(int x){

		}

		void move(float x, float y , float z){

			px = px +x; py = py +y; pz = pz + z;

		}

		void rotate(float x, float y , float z){

			rx = rx +x; ry = ry +y; rz = rz + z;

		}

		void scale(float x, float y , float z){

			sx = sx +x; sy = sy +y; sz = sz + z;

		}

		void color(float r, float g, float b){
			rr =r; gg =g, bb=b;
		}


		void display(){

				glPushMatrix(); //set where to start the current object transformations
				glTranslatef(px, py, pz); //move cube1 to the right
				glRotatef(rx, 1.0f, 0.0f, 0.0f);
				glRotatef(ry, 0.0f, 1.0f, 0.0f);
				glRotatef(rz, 0.0f, 0.0f, 1.0f);

				glScalef(sx, sy, sz);
				colorcube(); 	
				glPopMatrix(); //end the current object transformations

		
		}


		float ver[8][3] = 
		{
			{xt-dx/2,yt-dy/2,zt+dz/2},
			{xt-dx/2,yt+dy/2,zt+dz/2},
			{xt+dx/2,yt+dy/2,zt+dz/2},
			{xt+dx/2,yt-dy/2,zt+dz/2},
			{xt-dx/2,yt-dy/2,zt-dz/2},
			{xt-dx/2,yt+dy/2,zt-dz/2},
			{xt+dx/2,yt+dy/2,zt-dz/2},
			{xt+dx/2,yt-dy/2,zt-dz/2},
		};




		void quad(int a,int b,int c,int d)
		{	

			
			glBegin(GL_QUADS);
			glColor3f(rr,gg,bb);
			glVertex3fv(ver[a]);

			glVertex3fv(ver[b]);

			glVertex3fv(ver[c]);

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

};




class barrel{
	public:

		GLfloat px = 0.0;
		GLfloat py = 0.0;
		GLfloat pz = 0.0;
		GLfloat rx = 0.0;
		GLfloat ry = 0.0;
		GLfloat rz = 0.0;
		GLfloat sx = 1.0;
		GLfloat sy = 1.0;
		GLfloat sz = 1.0;


		GLfloat xt =0.0;
		GLfloat yt =0;
		GLfloat zt = 0;
		GLfloat dx = 0.1;
		GLfloat dy = 0.2;
		GLfloat dz =2.0;

		

		void move(float x, float y , float z){

			px = px +x; py = py +y; pz = pz + z;

		}

		void rotate(float x){
				rx = rx + x;
			if (rx >= 90)
			{
				rx=90;
			}
			if (rx <= 0)
			{
				rx = 0;
			}						
			 	
		}

	
		void display(){

				glPushMatrix(); //set where to start the current object transformations
				glTranslatef(px, py, pz); //move cube1 to the right

				glRotatef(rx, 1.0f, 0.0f, 0.0f);
				glRotatef(ry, 0.0f, 1.0f, 0.0f);
				glRotatef(rz, 0.0f, 0.0f, 1.0f);

				glScalef(sx, sy, sz);
				colorcube(); 	
				glPopMatrix(); //end the current object transformations

		
		}


		float ver[8][3] = 
		{
			{xt-dx/2,yt-dy/2,zt},
			{xt-dx/2,yt+dy/2,zt},
			{xt+dx/2,yt+dy/2,zt},
			{xt+dx/2,yt-dy/2,zt},
			{xt-dx/2,yt-dy/2,zt-dz},
			{xt-dx/2,yt+dy/2,zt-dz},
			{xt+dx/2,yt+dy/2,zt-dz},
			{xt+dx/2,yt-dy/2,zt-dz},
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
			glColor3f(1, 1, 1);
			glVertex3fv(ver[a]);

			glColor3f(1, 1, 1);
			glVertex3fv(ver[b]);

			glColor3f(1, 1, 1);
			glVertex3fv(ver[c]);

			glColor3f(1, 1, 1);
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



};







class tank{


	public:


		
		GLfloat px = 0.0;
		GLfloat py = 0.0;
		GLfloat pz = 0.0;
		GLfloat rx = 0.0;
		GLfloat ry = 0.0;
		GLfloat rz = 0.0;
		GLfloat sx = 1.0;
		GLfloat sy = 1.0;
		GLfloat sz = 1.0;
		GLfloat pitch = 0.0;
		GLfloat yaw =0.0;
		GLfloat rr = 1.0;
		GLfloat gg = 1.0;
		GLfloat bb = 1.0;


		tank(float x, float z, float a){

			px = x ;	pz = z; ry = a;	

			

		}


		void translate(float x, float y , float z){

			px = px +x; py = py +y; pz = pz + z;

		}

		void rotate(float x, float y , float z){

			rx = rx +x; ry = ry +y; rz = rz + z;

		}

		void scale(float x, float y , float z){

			sx = sx +x; sy = sy +y; sz = sz + z;

		}

		void move(float s){

			px = px + s*sin(ry*3.14159/180);
			pz = pz + s*cos(ry*3.14159/180);

			}

		void color(float r, float g, float b){
			rr =r; gg =g, bb=b;
		}

		void display(){

			barrel b3;
			drawBox b1(1);
			b1.color(rr, gg, bb );			
			drawBox b2(1);
			b2.color(1-gg, 1-bb, 1-rr );
		
		glPushMatrix(); //set where to start the current object transformations
				
				glTranslatef(px, py, pz); //move cube1 to the right

				glRotatef(rx, 1.0f, 0.0f, 0.0f);
				glRotatef(ry, 0.0f, 1.0f, 0.0f);
				glRotatef(rz, 0.0f, 0.0f, 1.0f);

				glScalef(sx, sy, sz);	
				

				
				b1.move(0.0 , -1.5 , 0.0);
				b1.scale(2.0, 1.0 , 2.0);
				b1.display();
				
				b2.display();
				
				b3.rotate(pitch);
				b3.display();		
				

			glPopMatrix();			
		}	
};


class score{

	public:

		int s=3;
		GLfloat rr = 0.77;
		GLfloat gg =0.38;
		GLfloat bb =0.06;
		GLfloat x = 0;
		GLfloat z = 0;

		score(float xx, float zz ){			
			x =xx; z = zz; 
		}


		void display(){

			drawBox b1(1);
			b1.color(rr, gg, bb );
			b1.move(x,-1,z);
			b1.display();
			drawBox b2(2);
			b2.color(rr, gg, bb );
			b2.move(x,0,z);
			b2.display();
			drawBox b3(1);
			b3.color(rr, gg, bb );
			b3.move(x,1,z);
			b3.display();
			drawBox b4(2);
			b4.color(rr, gg, bb );
			b4.move(x,2,z);
			b4.display();
			drawBox b5(1);
			b5.color(rr, gg, bb );
			b5.move(x,3,z);
			b5.display();			

			if(s==4){
				b5.color(0.0 , 1.0 , 0.0 );
			}

			else if(s==3){
				b4.color(0.0 , 1.0 , 0.0 );
			}

			else if(s==2){
				b3.color(0.0 , 1.0 , 0.0 );
			}

			else if(s==1){
				b2.color(0.0 , 1.0 , 0.0 );
			}
			else if(s==0){
				b1.color(0.0 , 1.0 , 0.0 );
			}
						

		}


};








tank t1(0, 25 , 0);
tank t2(0, -25, 180);
ground g1;
score s1(20,25);
score s2(-20 ,-25);

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

	
	// changing in transformation matrix.
	glTranslatef(Tx, Ty, Tz);
	
	glRotatef(Rx, 1.0f, 0.0f, 0.0f);
	glRotatef(Ry, 0.0f, 1.0f, 0.0f);
	glRotatef(Rz, 0.0f, 0.0f, 1.0f);

	glScalef(Sx, Sy, Sz);	
   
	
	g1.draw();
	t1.color(0.11,0.60,0.42);
	t1.display();
	t2.color(0.10,0.00,0.62);
	t2.display();
	s1.display();
	s2.display();

	 
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
	
    if (key == GLUT_KEY_RIGHT){
		t1.pitch = t1.pitch + 5.0;
	}
    else if (key == GLUT_KEY_LEFT){
      	t1.pitch = t1.pitch - 5.0;
}
    else if (key == GLUT_KEY_UP){
			t1.rotate(0.0, 5.0, 0.0);	}
	else if (key == GLUT_KEY_DOWN){
   			t1.rotate(0.0, -5.0, 0.0);
	}
    glutPostRedisplay();
}

void animate(void){

	Ry += 0.03;
	
	renderScene();
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Assignment1");
	
	Tx = 0.0; Ty = -20.0; Tz = -66.0;
	Rx = 0.0; Ry = 15.0; Rz = -0.0;
	Sx = 1.0f; Sy = 1.0; Sz = 1.0;
	//Assign  the function used in events


	
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	 glutSpecialFunc( specialKeys );
    glEnable( GL_DEPTH_TEST );

	glutIdleFunc(animate);					//for animation uncomment
	
	glutMainLoop();

	return 0;
}
