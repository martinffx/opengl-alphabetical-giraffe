////////////////////////////////////////////////////////////////
//
// mcr.cpp - Code for functions to draw the letters MCR
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
	
	draw3Dcurve  (2.0,          //depth  
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
