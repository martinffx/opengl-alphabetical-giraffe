////////////////////////////////////////////////////////////////
//
// Letters.cpp - function to draw a 3D curve and letters S, T and U.
// 
// Author: Shaakir Cosyn
// Student number : H00108756
// Campus : Cape Town South Africa
// Date:   29/04/2012
// Version:v001 - created
//
// Invocation: call draw3Dcurve()
//
// Arguments: 
// 	depth = depth centred round z=0
// 	r1 = inner radius
// 	r2 = outer radius
// 	theta_start = start angle in degrees measured from x-axis
// 	theta_stop = similar 
//                          
//
////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "3DCurve.h"

float colors[][3] = {{0.0,0.5,0.5},{1.0,0.0,0.0},
	{1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}, 
	{1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}};

float vertices[][3] = 
{
		{0,0,-0.5},{0.5,0,-0.5},
		{0.5,4.5,-0.5}, {0,4.5,-0.5}, {0,0,0.5}, 
		{0.5,0,0.5}, {0.5,4.5,0.5}, {0,4.5,0.5}
};

float verticesR[][3] = 
{
		{-0.5,-1.5,-0.5},{0,-1.5,-0.5},
		{0,1,-0.5}, {-0.5,1,-0.5}, {-0.5,-1.5,0.5}, 
		{0,-1.5,0.5}, {0,1,0.5}, {-0.5,1,0.5}
};

float verticesV1[][3] = 
{
		{-0.25,0,-0.5},{0.25,0,-0.5},
		{-1,4.5,-0.5}, {-1.5,4.5,-0.5}, {-0.25,0,0.5}, 
		{0.25,0,0.5}, {-1,4.5,0.5}, {-1.5,4.5,0.5}
};

float verticesV2[][3] = 
{
		{-0.25,0,-0.5},{0.25,0,-0.5},
		{1.5,4.5,-0.5}, {1,4.5,-0.5}, {-0.25,0,0.5}, 
		{0.25,0,0.5}, {1.5,4.5,0.5}, {1,4.5,0.5}
};

void polygon(int a, int b, int c , int d)
{
	// draw a polygon using colour of first vertex

 	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glVertex3fv(vertices[a]);
		glVertex3fv(vertices[b]);
		glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
	glEnd();
}

void cube(int size) {
	//Draw unit cube centred on the origin
	

	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(4,7,3,0);
	polygon(1,2,6,5);
	polygon(7,4,5,6);
	polygon(5,4,0,1);

}

void drawS()
{
	//curve on s
	glPushMatrix(); 
	glTranslatef(0.5, 3, 0);
	//glRotatef(270, 0, 0, 1);
	draw3Dcurve  (1.0,          //depth  
				1,          //inner radius
				1.5,          //outer radius
				0,          //start angle
				270,  //stop angle
				5.0);         //anular increments
	glPopMatrix();

	//glPushMatrix();
	//cube(1);
	//glPopMatrix();

	glPushMatrix();
	glPushMatrix(); 
	glTranslatef(0.5, 0.5, 0);
	glRotatef(180, 0, 0, 1);
	draw3Dcurve  (1.0,          //depth  
				1,          //inner radius
				1.5,          //outer radius
				0,          //start angle
				270,  //stop angle
				5.0);         //anular increments
	glPopMatrix();
	glPopMatrix();

}

void drawT()
{
	glPushMatrix();
	glTranslatef(-0.5, -1, 0);
	//glRotatef(180, 0, 0, 1);
	glScalef(1, 1.2, 1);
	cube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2,4, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(1, 1, 1);
	cube(1);
	glPopMatrix();
}

void drawU()
{
	//curve on u
	glPushMatrix(); 
	glTranslatef(1.5, 0.5, 0);
	glRotatef(180, 0, 0, 1);
	draw3Dcurve  (1.0,          //depth  
				1,          //inner radius
				1.5,          //outer radius
				0,          //start angle
				180,  //stop angle
				5.0);         //anular increments
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, -1, 0);
	//glRotatef(180, 0, 0, 1);
	glScalef(1, 1.23, 1);
	cube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	//glRotatef(180, 0, 0, 1);
	glScalef(1, 0.889, 1);
	cube(1);
	glPopMatrix();
}
