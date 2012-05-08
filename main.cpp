////////////////////////////////////////////////////////////////
//
// main.cpp - main program for animal made from initials
// 
// Author: Martin C. Richards
// Student number : H00112763
// Campus : Cape Town South Africa
// Date:   29/04/2012
//
////////////////////////////////////////////////////////////////     

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "3DCurve.h"
#include "mcr.h"
#include "stu.h"

//======================================================
// GLOBAL VARIABLES & FUNCTIONS
//======================================================
float pitch = 0.0f;
float yaw = 0.0f;
float neckAngle = 75.0;
float headAngle = -110.0;
float zoomFactor = 10.0;
float pitch0, yaw0;
bool MousePressed;
int mouseX0, mouseY0;
bool rotating=false;

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
    if (w <= h) glOrtho(-zoomFactor, zoomFactor, -zoomFactor * (GLfloat) h / (GLfloat) w, zoomFactor * (GLfloat) h / (GLfloat) w, -20.0, 20.0);
    else        glOrtho(-zoomFactor* (GLfloat) w / (GLfloat) h, zoomFactor * (GLfloat) w / (GLfloat) h, -zoomFactor, zoomFactor, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//======================================================
// KEYBOARD CALLBACK ROUTINE 
//======================================================
void keyboardCallBack(unsigned char key, int x, int y) {
	printf("Keyboard call back: key=%c, x=%d, y=%d\n", key, x, y);
	switch(key)
	{
	case 'b': case 'B':
		glPolygonMode(GL_BACK,GL_FILL);
	break;
	case 'f': case 'F':
		glPolygonMode(GL_FRONT,GL_FILL);
	break;
	case 'l': case 'L':
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	break;
	case 'r': 
		rotating= !rotating;
		rotateView(rotating);
	break;
	case 'R':
        resetView();
	break;
	case 'z': 
		if (zoomFactor > 1) zoomFactor = zoomFactor - 1;
	break;
	case 'Z':
        zoomFactor = zoomFactor + 1;
	break;
	default:
		printf("Press b - back fill; f - front fill; l - line; i - increment; or d - decrement; r - rotate; R - reset view\n");
	}

	glutPostRedisplay();
}

//======================================================
// DRAW  ANIMAL
//======================================================
void drawHorns(){
	glPushMatrix();
	glTranslatef(5,11.2,-.5);
	glRotatef(20, 0, 0, 1);
	glScalef(.2, 0.2, .2);
	drawU();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(5,11.2,.5);
	glRotatef(20, 0, 0, 1);
	glScalef(.2, 0.2, .2);
	drawU();
	glPopMatrix();
}

void drawHead() {
	glPushMatrix();
	glTranslatef(5.1,10.5,0);
	glRotatef(headAngle, 0, 0, 1);
	glScalef(.7, 0.7, 2);
	drawS();
	glPopMatrix();
	
	drawHorns();
}

void drawFoot() {
	//draw foot
	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	glScalef(.55, 0.55, 1);
	drawR();
	glPopMatrix();
}

void drawAnimalLeg() {
	//draw legs
	glPushMatrix();
	glRotatef(180, 1.0, 0.0, 0);
	glScalef(0.5, 0.5, 2);
	drawT();
	glPopMatrix();
	
	//draw feet
	glPushMatrix();
	glTranslatef(-.1, -3.8, 0);
	drawFoot();
	glPopMatrix();
}

void drawLineOfC() {
	glPushMatrix();
	glScalef(.5,.5,1);
	drawC();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1.3,0,0);
	glScalef(.5,.5,1);
	drawC();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(2.6,0,0);
	glScalef(.5,.5,1);
	drawC();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(3.9,0,0);
	glScalef(.5,.5,1);
	drawC();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(5.2,0,0);
	glScalef(.5,.5,1);
	drawC();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(6.5,0,0);
	glScalef(.5,.5,1);
	drawC();
	glPopMatrix();
}

void drawNeck() {
	glPushMatrix();
	glTranslatef(3.5, 2.7, 0);
	glRotatef(neckAngle, 0, 0, 1.0);
	drawLineOfC();
	glPopMatrix();
}

void drawLeftLeg(){
	glPushMatrix();//draw left leg
	glTranslatef(-2.5, -2.5, 0);
	drawAnimalLeg();
	glPopMatrix();
}

void drawRightLeg(){
	glPushMatrix();//draw right leg
	glTranslatef(2.5, -2.5, 0);
	drawAnimalLeg();
	glPopMatrix();
}

void drawBody(){
	drawM();//draw body
}

void drawGiraffe(){
	glPushMatrix();
	glTranslatef(-4, -3, 0);
	drawBody();
	drawRightLeg();
	drawLeftLeg();
	drawNeck();
	drawHead();
	glPopMatrix();
}

//======================================================
// DISPLAY CALL BACK ROUTINE 
//======================================================
void displayCallBack()	
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	executeViewControl (yaw, pitch);
	
	drawGiraffe();

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
    glutInitWindowSize(700, 700);
    glutCreateWindow("F29GR - Initials - MCR");

	// Add Display & Mouse CallBacks
	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(displayCallBack);
	glutIdleFunc(NULL); // Starts the Idle Function as having no routine attached to it. This is modified in rotateView()
	glutMouseFunc(mouseClickCallBack);
	glutMotionFunc(mouseMotionCallBack);
	glutKeyboardFunc(keyboardCallBack);


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

