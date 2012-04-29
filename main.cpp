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
#include "3DCurve.h"

//======================================================
// GLOBAL VARIABLES & FUNCTIONS
//======================================================
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
	drawRightTrunk();
	drawLeftTrunk();
	drawLeftBranch();
	drawRightBranch();
}

//======================================================
// DRAW C
//======================================================
void drawC(void) {
	glPushMatrix();
	glRotatef(50.0, 0.0, 0.0, 1.0);
	
	draw3Dcurve  (1.0,          //depth  
				  1.5,          //inner radius
				  2.0,          //outer radius
				  0.0,          //start angle
				  260,  		//stop angle
				  5.0);  
				  
	glPopMatrix();
}

//======================================================
// DRAW R
//======================================================
void drawStem() {
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

void drawLeg() {
	glBegin(GL_QUADS);//Back
        glColor3f(0, 0, 0);
		glVertex3f(-2, 0, -1);
		glVertex3f(-1, 0, -1);
		glVertex3f(0, -2, -1);
		glVertex3f(-1, -2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//Front
        glColor3f(0, 0, 0);
		glVertex3f(-2, 0, 1);
		glVertex3f(-1, 0, 1);
		glVertex3f(0, -2, 1);
		glVertex3f(-1, -2, 1);
	glEnd();
	
	glBegin(GL_QUADS);//Back
        glColor3f(0, 0, 0);
		glVertex3f(-2, 0, -1);
		glVertex3f(-2, 0, 1);
		glVertex3f(-1, -2, 1);
		glVertex3f(-1, -2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//Front
        glColor3f(0, 0, 0);
		glVertex3f(-1, 0, -1);
		glVertex3f(-1, 0, 1);
		glVertex3f(0, -2, 1);
		glVertex3f(0, -2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//Bottom
        glColor3f(0, 0, 0);
		glVertex3f(-1, -2, 1);
		glVertex3f(-1, -2, -1);
		glVertex3f(0, -2, -1);
		glVertex3f(0, -2, 1);
	glEnd();
}

void drawTopLeg() {
	glBegin(GL_QUADS);//Top
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, 1);
		glVertex3f(-2, 2, -1);
		glVertex3f(-1, 2, -1);
		glVertex3f(-1, 2, 1);
	glEnd();
	
	glBegin(GL_QUADS);//Back
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, -1);
		glVertex3f(-2, 1.5, -1);
		glVertex3f(-1, 1.5, -1);
		glVertex3f(-1, 2, -1);
	glEnd();
	
	glBegin(GL_QUADS);//Bottom
        glColor3f(0, 0, 0);
		glVertex3f(-2, 1.5, -1);
		glVertex3f(-2, 1.5, 1);
		glVertex3f(-1, 1.5, 1);
		glVertex3f(-1, 1.5, -1);
	glEnd();
	
	glBegin(GL_QUADS);//Front
        glColor3f(0, 0, 0);
		glVertex3f(-2, 2, 1);
		glVertex3f(-2, 1.5, 1);
		glVertex3f(-1, 1.5, 1);
		glVertex3f(-1, 2, 1);
	glEnd();
}

void drawBottomLeg() {
	glBegin(GL_QUADS);//Bottom
        glColor3f(0, 0, 0);
		glVertex3f(-2, 0, -1);
		glVertex3f(-1, 0, -1);
		glVertex3f(-1, 0, 1);
		glVertex3f(-2, 0, 1);
	glEnd();
	
	glBegin(GL_QUADS);//Front
        glColor3f(0, 0, 0);
		glVertex3f(-2, 0, 1);
		glVertex3f(-2, 0.5, 1);
		glVertex3f(-1, 0.5, 1);
		glVertex3f(-1, 0, 1);
	glEnd();
	
	glBegin(GL_QUADS);//Top
        glColor3f(0, 0, 0);
		glVertex3f(-2, 0.5, 1);
		glVertex3f(-2, 0.5, -1);
		glVertex3f(-1, 0.5, -1);
		glVertex3f(-1, 0.5, 1);
	glEnd();
	
	glBegin(GL_QUADS);//Back
        glColor3f(0, 0, 0);
		glVertex3f(-2, 0.5, -1);
		glVertex3f(-2, 0, -1);
		glVertex3f(-1, 0, -1);;
		glVertex3f(-1, 0.5, -1);
	glEnd();
}

void drawCurve() {
	drawTopLeg();
	drawBottomLeg();
	
	glPushMatrix();
	glTranslatef(-1, 1, 0);
	glRotatef(270.0, 0.0, 0.0, 1.0);
	draw3Dcurve  (2.0,          //depth  
				  0.5,          //inner radius
				  1.0,          //outer radius
				  0.0,          //start angle
				  180,  		//stop angle
				  5.0);  
	glPopMatrix();
}

void drawR(void) {
	drawStem();
	drawLeg();
	drawCurve();
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
	
	glPushMatrix();
    glTranslatef(-5.5, 0, 0);
	drawM();
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(0, 0, 0);
	drawC();
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(5, 0, 0);
	drawR();
	glPopMatrix();

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

