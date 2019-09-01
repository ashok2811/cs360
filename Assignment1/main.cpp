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
		glEnd();}	
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

		drawBox(float x = 1, float y = 1, float z = 1 ){
				dx=x; dy = y; dz = z;}

		void move(float x, float y , float z){
			px = px +x; py = py +y; pz = pz + z;}

		void rotate(float x, float y , float z){
			rx = rx +x; ry = ry +y; rz = rz + z;}

		void scale(float x, float y , float z){
			sx = sx +x; sy = sy +y; sz = sz + z;}

		void color(float r, float g, float b){
			rr =r; gg =g, bb=b;}


		void display(){
				glPushMatrix(); //set where to start the current object transformations
				glTranslatef(px, py, pz); //move cube1 to the right
				glRotatef(rx, 1.0f, 0.0f, 0.0f);
				glRotatef(ry, 0.0f, 1.0f, 0.0f);
				glRotatef(rz, 0.0f, 0.0f, 1.0f);
				glScalef(sx, sy, sz);
				colorcube(); 	
				glPopMatrix(); }

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

		barrel(){

			
		}

		

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
				drawBox b1;
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

class bullet{
	public:

		GLfloat px = 0.0;
		GLfloat py = 0.0;
		GLfloat pz = 0.0;

		GLfloat xt , yt , zt;
		GLfloat dx = 0.1;
		GLfloat dy = 0.2;
		GLfloat dz =0.1;
		GLfloat bx =0.0;
		GLfloat by =0.0;
		GLfloat bz =0.0;
		bullet (float x , float y , float z){
			xt =x ; yt = y ; zt =z;

		}

		void moveBullet(float x, float y , float z){

			bx =x; by = y; bz = z;

		}

			
		void display(){

				glPushMatrix(); //set where to start the current object transformations
				glTranslatef(bx, by, bz); //move cube1 to the right
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

		void quad(int a,int b,int c,int d)
		{	
			
			glBegin(GL_QUADS);
			glColor3f(1,1,0);
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

class tank{

	public:
		
		GLfloat px = 0.0;
		GLfloat py = 0.0;
		GLfloat pz = 0.0;
		GLfloat rx = 0.0;
		GLfloat ry = 0.0;
		GLfloat rz = 0.0;		
		GLfloat pitch = 0.0;
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

		void move(float s){

			px = px + s*sin(ry*3.14159/180);
			pz = pz + s*cos(ry*3.14159/180);

			}


		void color(float r, float g, float b){
			rr =r; gg =g, bb=b;
		}

		int isDead(float x, float z){

			if(((x>=px-2)&&(x <= px + 2) ) &&  ((z>=pz-2)&&(z <= pz + 2) )  ){
				return 1;
			}

			else{return 0;}

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
				
				b1.move(0.0 , -1.5 , 0.0);
				b1.scale(2.0, 1.0 , 2.0);
				b1.display();
				
				b2.display();
				
				b3.rotate(pitch);
				b3.display();
										

			glPopMatrix();			
		}	
};

float timeOfFlight(float u, float ang){

		return (2*u*sin(ang*3.14159/180)/(9.8));
}

float distance(float u, float ang){

	return (u*u*sin(2*ang*3.14159/180)/(9.8));
}

float currH(float u, float ang, float t){
		float s = u*sin(ang*3.14159/180)*t - 0.5*9.8*t*t ;
		return(s);
}


class scoreB{

	public:
		int s=5;
		GLfloat rr = 0;
		GLfloat gg =1;
		GLfloat bb =0;
		GLfloat x = 0;
		GLfloat z = 0;

		scoreB(float xx, float zz ){			
			x =xx; z = zz; 
		}
		void display(){

			drawBox b1(1);
			b1.color(rr, gg, bb );
			b1.move(x,-1,z);
			
			drawBox b2(2);
			b2.color(rr, gg, bb );
			b2.move(x,0.5,z);
			
			drawBox b3(1);
			b3.color(rr, gg, bb );
			b3.move(x,2.0,z);
			
			drawBox b4(2);
			b4.color(rr, gg, bb );
			b4.move(x,3.5,z);
			
			drawBox b5(1);
			b5.color(rr, gg, bb );
			b5.move(x,5.0,z);
			
			if(s==5){
				b1.display();
				b2.display();
				b3.display();
				b4.display();
				b5.display();
			}

			else if(s==4){
				b1.display();
				b2.display();
				b3.display();
				b4.display();
			}

			else if(s==3){
				b1.display();
				b2.display();
				b3.display();
			}

			else if(s==2){
				b1.display();
				b2.display();
			}
			else if(s==1){
				b1.display();
			}
						

		}

		int decHealth(){
			s = s-1;
			if(s<0){s=0;}
			return s;
		}


};

class power{

	public:
		int s=22;
		GLfloat rr = 1;
		GLfloat gg =0;
		GLfloat bb =0;
		GLfloat x = 0;
		GLfloat z = 0;


		power(float xx, float zz){
			x = xx ;	z = zz; 
		}

		void display(){
			
			

			drawBox b1(1);
			b1.color(rr, gg, bb );
			b1.move(x,-1,z);
			
			drawBox b2(2);
			b2.color(rr, gg, bb );
			b2.move(x,0.5,z);
			
			drawBox b3(1);
			b3.color(rr, gg, bb );
			b3.move(x,2.0,z);
			
			drawBox b4(2);
			b4.color(rr, gg, bb );
			b4.move(x,3.5,z);
			
			drawBox b5(1);
			b5.color(rr, gg, bb );
			b5.move(x,5.0,z);
			
			
			if(s==26){
				b1.display();
				b2.display();
				b3.display();
				b4.display();
				b5.display();
			}

			else if(s==24){
				b1.display();
				b2.display();
				b3.display();
				b4.display();
			}

			else if(s==22){
				b1.display();
				b2.display();
				b3.display();
			}

			else if(s==20){
				b1.display();
				b2.display();
			}
			else if(s==18){
				b1.display();
			}

		}


		int incPower(){
			s = s+2;
			if(s>26){s=26;}
			return s;
		}

		int decPower(){
			s = s-2;
			if(s<=18){s=18;}
			return s;
		}


};



tank t1(0, 25 , 0);
tank t2(0, -25, 180);
ground g1;
scoreB s1(20,25);
scoreB s2(-20 ,-25);
bullet b4(0, 0, 0);

power p1(-20,25);
power p2(20,-25);

class fire{
	public: 

	float t =0.0;
	float v ;
	int tank ;
	float Angle ,Ox, Oyy, Oz;
			
	fire (int x){

		if(x == 1){
		Angle = t1.pitch;
		Ox = t1.px;
		Oz = t1.pz;
		Oyy = t1.ry;
		v = p1.s;
		tank = 1;

		}
		else if (x == 2)
		{

		Angle = t2.pitch;
		Ox = t2.px;
		Oz = t2.pz;
		Oyy = t2.ry;
		v = p2.s;
		tank =2;
			
		}

	}

	
	void display(){	

				float vx , vz , vy;		
		
				if(currH(v, Angle , t) < -1.5){
				t=0;
				if(tank == 1){Angle = t1.pitch;
				Ox = t1.px;	Oz = t1.pz;	Oyy = t1.ry; v = p1.s;}
				else if(tank ==2){Angle = t2.pitch;
				Ox = t2.px;	Oz = t2.pz;	Oyy = t2.ry; v = p2.s;}										
				}
				
				else {	
				t=t+0.004;
				vx = Ox -(v*cos(Angle*3.14159/180)*t)*sin(Oyy*3.14159/180) ;
				vz =  Oz -(v*cos(Angle*3.14159/180)*t)*cos(Oyy*3.14159/180);

				b4.moveBullet( vx , currH(v, Angle , t), vz);

				if(tank == 1){					
						if(t2.isDead(0.0,-v*cos(Angle*3.14159/180)*t)){
						s2.decHealth();}
					}
				else if(tank == 2){					
						if(t1.isDead(0.0,-v*cos(Angle*3.14159/180)*t)){
						s1.decHealth();}
					}
				
			}

			

	}
	};


fire f1(1);
fire f2(2);
int ff = -1;


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
	b4.display();
	
	p1.display();
	
	p2.display();

	if(ff==1){f1.display();}
	else if (ff ==-1)
	{
		f2.display();
	}
	
	
	
			
	



	 
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




void keyboard(unsigned char key, int x, int y)
{
	
	if(key=='w'){t2.move(-1);}		
	else if(key=='a'){t2.rotate(0.0, 5.0, 0.0);}
	else if(key=='d'){t2.rotate(0.0, -5.0, 0.0);}
	else if(key=='s'){t2.move(1);}
	else if(key=='q'){t2.pitch = t2.pitch + 5;}
	else if(key=='z'){t2.pitch = t2.pitch - 5;}
	else if(key=='l'){t1.pitch = t1.pitch - 5;}
	else if(key=='o'){t1.pitch = t1.pitch + 5;}
	else if(key=='.'){p1.incPower();}
	else if(key==','){p1.decPower();}
	else if(key=='x'){p2.incPower();}
	else if(key=='c'){p2.decPower();}
	
}


void specialKeys( int key, int x, int y ) 
{
	
    if (key == GLUT_KEY_RIGHT){	t1.rotate(0.0, -5.0, 0.0);}
    else if (key == GLUT_KEY_LEFT){t1.rotate(0.0, 5.0, 0.0);}
    else if (key == GLUT_KEY_UP){t1.move(-1);}
	else if (key == GLUT_KEY_DOWN){t1.move(1);}
    glutPostRedisplay();
}




void animate(void){

		Ry += ff*0.06;
		
		

		if(Ry<=0){
			ff = 1;
				
		}
		if(Ry >=180 ){
			ff = -1;
		

		}


	renderScene();
}



int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Assignment1");
	
	Tx = 0.0; Ty = -20.0; Tz = -66.0;
	Rx = 0.0; Ry = 90.0; Rz = -0.0;
	Sx = 1.0f; Sy = 1.0; Sz = 1.0;
	//Assign  the function used in events

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutSpecialFunc( specialKeys );
    glEnable( GL_DEPTH_TEST );
	glutKeyboardFunc(keyboard);
	glutIdleFunc(animate);					//for animation uncomment
	
	glutMainLoop();

	return 0;
}
