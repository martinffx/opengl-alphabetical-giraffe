//      main.cpp
//      
//      Copyright 2012 martin <martin@crunchbang>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
//      

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

//======================================================
// GLOBAL VARIABLES 
//======================================================
static double theta_stop1 = 260;
float pitch = 0.0f;
float yaw = 0.0f;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;

//======================================================
// DRAW M
//======================================================
void drawRightBranch() {
	glBegin(GL_POLYGON);//Front
        glColor3f(0, 0, 0);
		glVertex3f(2, 2, 1);
		glVertex3f(2, 1, 1);
		glVertex3f(0, -2, 1);
		glVertex3f(0, -1, 1);
	glEnd();
	
	glBegin(GL_POLYGON);//top
        glColor3f(0, 0, 0);
		glVertex3f(2, 2, -1);
		glVertex3f(2, 2, 1);
		glVertex3f(0, -1, 1);
		glVertex3f(0, -1, -1);
	glEnd();
	
	glBegin(GL_POLYGON);//back
        glColor3f(0, 0, 0);
		glVertex3f(2, 2, -1);
		glVertex3f(2, 1, -1);
		glVertex3f(0, -2, -1);
		glVertex3f(0, -1, -1);
	glEnd();
	
	glBegin(GL_POLYGON);//bottom
        glColor3f(0, 0, 0);
		glVertex3f(2, 1, -1);
		glVertex3f(2, 1, 1);
		glVertex3f(0, -2, 1);
		glVertex3f(0, -2, -1);
	glEnd();
	
	glDisable(GL_LINE_SMOOTH);
}

void drawLeftBranch(){
  glBegin(GL_POLYGON);//Front
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, 1);
		glVertex3f(-2, 1, 1);
		glVertex3f(0, -2, 1);
		glVertex3f(0, -1, 1);
	glEnd();
	
	glBegin(GL_POLYGON);//top
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, -1);
		glVertex3f(-2, 2, 1);
		glVertex3f(0, -1, 1);
		glVertex3f(0, -1, -1);
	glEnd();
	
	glBegin(GL_POLYGON);//back
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, -1);
		glVertex3f(-2, 1, -1);
		glVertex3f(0, -2, -1);
		glVertex3f(0, -1, -1);
	glEnd();
	
	glBegin(GL_POLYGON);//bottom
        glColor3f(0, 0, 0);
		glVertex3f(-2, 1, -1);
		glVertex3f(-2, 1, 1);
		glVertex3f(0, -2, 1);
		glVertex3f(0, -2, -1);
	glEnd();
	
	glDisable(GL_LINE_SMOOTH);
}

void drawLeftTrunk(){
	glBegin(GL_QUADS);//Front
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, 1);
		glVertex3f(-3, 2, 1);
		glVertex3f(-3, -2, 1);
		glVertex3f(-2, -2, 1);
	glEnd();
	
	glBegin(GL_QUADS);//top
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, 1);
		glVertex3f(-3, 2, 1);
		glVertex3f(-3, 2, -1);
		glVertex3f(-2, 2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//back
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, -1);
		glVertex3f(-3, 2, -1);
		glVertex3f(-3, -2, -1);
		glVertex3f(-2, -2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//bottom
        glColor3f(0, 0, 0);
		glVertex3f(-2, -2, 1);
		glVertex3f(-3, -2, 1);
		glVertex3f(-3, -2, -1);
		glVertex3f(-2, -2, -1);
	glEnd();
	//~ 
	glBegin(GL_QUADS);//left
        glColor3f(0, 0, 0);
		glVertex3f(-3, 2, -1);
		glVertex3f(-3, -2, -1);
		glVertex3f(-3, -2, 1);
		glVertex3f(-3, 2, 1);
	glEnd();
	
	glBegin(GL_QUADS);//right
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, -1);
		glVertex3f(-2, -2, -1);
		glVertex3f(-2, -2, 1);
		glVertex3f(-2, 2, 1);
	glEnd();
	
	glDisable(GL_LINE_SMOOTH);
}

void drawRightTrunk(){
	glBegin(GL_QUADS);//Front
        glColor3f(0, 0, 0);
		glVertex3f(2, 2, 1);
		glVertex3f(3, 2, 1);
		glVertex3f(3, -2, 1);
		glVertex3f(2, -2, 1);
	glEnd();
	
	glBegin(GL_QUADS);//top
        glColor3f(0, 0, 0);
		glVertex3f(2, 2, 1);
		glVertex3f(3, 2, 1);
		glVertex3f(3, 2, -1);
		glVertex3f(2, 2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//back
        glColor3f(0, 0, 0);
		glVertex3f(2, 2, -1);
		glVertex3f(3, 2, -1);
		glVertex3f(3, -2, -1);
		glVertex3f(2, -2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//bottom
        glColor3f(0, 0, 0);
		glVertex3f(2, -2, 1);
		glVertex3f(3, -2, 1);
		glVertex3f(3, -2, -1);
		glVertex3f(2, -2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//right
        glColor3f(0, 0, 0);
		glVertex3f(3, 2, -1);
		glVertex3f(3, -2, -1);
		glVertex3f(3, -2, 1);
		glVertex3f(3, 2, 1);
	glEnd();
	
	glBegin(GL_QUADS);//left
        glColor3f(0, 0, 0);
		glVertex3f(2, 2, -1);
		glVertex3f(2, -2, -1);
		glVertex3f(2, -2, 1);
		glVertex3f(2, 2, 1);
	glEnd();
	
	glDisable(GL_LINE_SMOOTH);
}

void drawM(void) {
	glPushMatrix();
    glTranslatef(-2, 0, 0);
     
	drawRightTrunk();
	drawLeftTrunk();
	drawLeftBranch();
	drawRightBranch();
	
	glPopMatrix();
}

//======================================================
// DRAW C
//======================================================
void draw3Dcurve(double depth, double r1, double r2, double theta_start, double theta_stop, double theta_inc) {
	// Function to draw 3D curve 
	// depth = depth centred round z=0
	// r1 = inner radius
	// r2 = outer radius
	// theta_start = start angle in degrees measured from x-axis
	// theta_stop = similar 

	double x, y, x1, x2, y1, y2, z, thet, z_front, z_back;
	int i=0;
	double radius=1.5, c=3.14159/180.0;
	z_front=depth/2; z_back=-depth/2;
	
	// draw rear face (away from viewer)
	glColor3f(0.0, 0.0, 0.0);
	z=z_back;
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc) {
		x=cos(c*thet)*r2; y=sin(c*thet)*r2; glVertex3d(x,y,z);
		x=cos(c*thet)*r1; y=sin(c*thet)*r1; glVertex3d(x,y,z);
	}
	glEnd();

	// draw front face (closer to viewer)
	glColor3f(0.0, 0.0, 0.0);
	z=z_front;
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc)	{
		x=cos(c*thet)*r1; y=sin(c*thet)*r1; glVertex3d(x,y,z);
		x=cos(c*thet)*r2; y=sin(c*thet)*r2; glVertex3d(x,y,z);
	}
	glEnd();

	// draw upper face
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc) {
		x=cos(c*thet)*r2; y=sin(c*thet)*r2;
		z=z_front; glVertex3d(x,y,z);
		z=z_back;  glVertex3d(x,y,z);
	}
	glEnd();

	// draw lower face
	glBegin(GL_QUAD_STRIP);
	for(thet=theta_start; thet<=theta_stop;thet+=theta_inc)	{
		x=cos(c*thet)*r1; y=sin(c*thet)*r1;
		z=z_back; glVertex3d(x,y,z);
		z=z_front; glVertex3d(x,y,z);
	}
	glEnd();

	// draw bottom end
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3d(r1,0.0,z_front);
		glVertex3d(r1,0.0,z_back);
		glVertex3d(r2,0.0,z_back);
		glVertex3d(r2,0.0,z_front);
	glEnd();

	// draw top end
	glBegin(GL_POLYGON);
		x1=cos(c*theta_stop)*r1; y1=sin(c*theta_stop)*r1;
		x2=cos(c*theta_stop)*r2; y2=sin(c*theta_stop)*r2;

		glVertex3d(x1,y1,z_front);
		glVertex3d(x2,y2,z_front);
		glVertex3d(x2,y2,z_back);
		glVertex3d(x1,y1,z_back);
	glEnd();
}

void drawC(void) {
	glPushMatrix();
	glRotatef(50.0, 0.0, 0.0, 1.0);
	
	draw3Dcurve  (1.0,          //depth  
				  1.5,          //inner radius
				  2.0,          //outer radius
				  0.0,        //start angle
				  theta_stop1,  		//stop angle
				  5.0);  
				  
	glPopMatrix();
}


//======================================================
// DRAW AXES and GRIDS
//======================================================
void drawAxesAndGridLines(bool x_y_display, bool y_z_display,  bool x_z_display)
{
	float offset;
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3f(-20, 0, 0);					
		glVertex3f(+20, 0, 0);					
		glVertex3f( 0 ,-20, 0);				    	
		glVertex3f(	0, +20, 0);
		glVertex3f( 0, 0,-20);				    	
		glVertex3f(	0, 0, +20);

	glEnd();
	
	glLineStipple(1, 0xAAAA); //line style = fine dots
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINES);
		
		if (x_y_display) {glColor3f(0.0,0.7,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-y plane
			glVertex3f(-10.0, offset, 0.0);					// Top Left
			glVertex3f(+10.0, offset, 0.0);					// Top Right
			glVertex3f( offset,-10, 0.0);					// Bottom Right
			glVertex3f(	offset,+10.0, 0.0);					// Bottom Left
		}}

		if (y_z_display) {glColor3f(0.7,0.0,0.7);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in y-z plane
			glVertex3f( 0, offset, -10);					
			glVertex3f(	0, offset, 10.0);
			glVertex3f( 0, -10, offset);					
			glVertex3f(	0, 10, offset);
		}}

		if (x_z_display) {glColor3f(0.7,0.7,0.0);
		for (offset=-10.0;offset<10.1;offset++){
			//draw lines in x-z plane
			glVertex3f( offset, 0, -10);					
			glVertex3f(	offset, 0, 10.0);
			glVertex3f( -10, 0, offset);					
			glVertex3f(	10, 0, offset);
		}}

	glEnd();
	glDisable(GL_LINE_STIPPLE);

}

//======================================================
// VIEW CONTROL ROUTINES
//======================================================

void idleCallBack (){
	yaw=yaw+.25;
    glutPostRedisplay();
}

void rotateView(bool r){
	rotating = r;
	if (r) glutIdleFunc(idleCallBack); else glutIdleFunc(NULL);
}

void resetView(){
	rotateView(false); //Stop view rotation
	yaw=pitch=0;
}

void executeViewControl (float y, float p){
	glRotatef(y, 0.0f, 1.0f, 0.0f); //yaw about y-axis
    glRotatef(p, 1.0f, 0.0f, 0.0f); //pitch about x-axis 
}

void mouseClickCallBack(int button, int state, int x, int y) {
	//Called on button press or release
    switch (state)
    {
		case GLUT_DOWN:
			MousePressed = true;
			rotateView(false);
			pitch0 = pitch; yaw0 = yaw;
			mouseX0 = x; mouseY0 = y;
			break;
		default:
		case GLUT_UP:
			MousePressed = false;
			//rotateView(true);
			break;
    }
} 

void mouseMotionCallBack(int x, int y) 
{
	// Called when the Mouse is moved with left button down
    pitch = pitch0 + (y - mouseY0);
    yaw = yaw0 + (x - mouseX0);
	glutPostRedisplay();
} 

void reshapeCallBack(int w, int h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	if (w == 0 || h == 0) return;
    if (w <= h) glOrtho(-3.0, 3.0, -3.0 * (GLfloat) h / (GLfloat) w, 3.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else        glOrtho(-3.0 * (GLfloat) w / (GLfloat) h, 3.0 * (GLfloat) w / (GLfloat) h, -3.0, 3.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


//======================================================
// DISPLAY CALL BACK ROUTINE 
//======================================================
void displayCallBack()	
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	executeViewControl (yaw, pitch);
	//drawAxesAndGridLines(true, true, true);

	//drawM();
	drawC();

	glutSwapBuffers();
}

//======================================================
// MAIN PROGRAM
//======================================================
int main(int argc, char** argv)
{
   // Allow cmd line arguments to be passed to the glut
	glutInit(&argc, argv);

	// Create and name window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Need both double buffering and z buffer
    glutInitWindowSize(500, 500);
    glutCreateWindow("F29GR - Initials - MCR");

	// Add Display & Mouse CallBacks
	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	glutMouseFunc(mouseClickCallBack);
        glutMotionFunc(mouseMotionCallBack);


	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */

	// Print Application Usage
	printf("Program Controls:\n");
	printf("Left Mouse Button & Drag - Changes the View.\n");
	printf("Key \"b\" - Back Fill.\n");
	printf("Key \"f\" - Front Fill.\n");
	printf("Key \"l\" - Wire Frame/Line Fill.\n");
	printf("Key \"i\" - Increment Sections of Curve.\n");
	printf("Key \"d\" - Decrement Sections of Curve.\n");
	printf("Key \"r\" - Automated Rotation.\n");
	printf("Key \"R\" - Reset the View.\n");

	glutMainLoop();

	return 0;
}

