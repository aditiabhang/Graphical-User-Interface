/*

 Name:  Aditi Abhang
 NetID: aaa333

*/

#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void GLobj::resizeGL( int w, int h )
{
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void GLobj::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(4.0);
    glBegin(GL_POINTS); 
    glColor3f(0,1,0.5);
    glVertex2f(-0.9, 0.6); 
    glEnd(); 
    
    glLineWidth(4.0);
    glBegin(GL_LINES); 
    glColor3f(1,0,0);
    glVertex2f(-0.8, 0.6);
    glColor3f(0,1,0); 
    glVertex2f(-0.2, 0.6);
    glColor3f(0,0,1); 
    glEnd();

    //Drawing a triangle
    glPushMatrix();         // save the current version of matrix
    glTranslatef(0.1f,0.6f,0.0f);
    glScalef(0.3f,0.3f,0.3f);
    glColor3f(1,1,0);
    ngon(3);
    glPopMatrix();          // load the previously saved matrix

    // Drawing a square
    glPushMatrix();         // save the current version of matrix
    glTranslatef(0.6f,0.6f,0.0f);
    glScalef(0.3f,0.3f,0.3f);
    glColor3f(1,0,0);
    ngon(4);
    glPopMatrix();          // load the previously saved matrix
    
    // Drawing a pentagon
    glPushMatrix();         // save the current version of matrix
    glTranslatef(0.1f,0.2f,0.0f);
    glScalef(0.3f,0.3f,0.3f);
    glColor3f(1,1,0.5);
    ngon(5);
    glPopMatrix();          // load the previously saved matrix

    // Drawing a hexagon
    glPushMatrix();         // save the current version of matrix
    glTranslatef(0.6f,0.2f,0.0f);
    glScalef(0.3f,0.3f,0.3f);
    glColor3f(1,0.5,0.5);
    ngon(6);
    glPopMatrix();          // load the previously saved matrix

    // Drawing a hectagon
    glPushMatrix();         // save the current version of matrix
    glTranslatef(0.1f,-0.2f,0.0f);
    glScalef(0.3f,0.3f,0.3f);
    glColor3f(1,0,2);
    ngon(7);
    glPopMatrix();          // load the previously saved matrix

    // Drawing a hexagon
    glPushMatrix();         // save the current version of matrix
    glTranslatef(0.6f,-0.2f,0.0f);
    glScalef(0.3f,0.3f,0.3f);
    glColor3f(0,0.5,1.5);
    ngon(9);
    glPopMatrix();          // load the previously saved matrix

    // Drawing a circle
    glPushMatrix();         // save the current version of matrix
    glTranslatef(-0.5f,0.2f,0.0f);
    glScalef(0.3f,0.3f,0.3f);
    glColor3f(0,0,3);
    ngon(100);
    glEnd();
    glPopMatrix();          // load the previously saved matrix

    // Drawing a cube
    glPushMatrix();         // save the current version of matrix
    glTranslatef(-0.5f,-0.3f,0.0f);
    glRotatef(90,1,0,1);
    glScalef(0.3f,0.3f,0.3f);

    glBegin(GL_QUADS);
    // Top 
    glColor3f(0.0f,1.0f,0.0f);   
    glVertex3f(0.5f, 0.5f, -0.4f);  
    glVertex3f(-0.5f, 0.5f, -0.4f);  
    glVertex3f(-0.5f, 0.5f, 0.4f);  
    glVertex3f(0.5f, 0.5f, 0.4f);  
    glEnd();
    
    glBegin(GL_POLYGON);
    // Bottom
    //DarkPurple = color red 0.53 green 0.12 blue 0.47
    glColor3f(1.0,0.5,0.0);
    glVertex3f(0.5f, -0.5f, 0.4f);  
    glVertex3f(-0.5f, -0.5f, 0.4f);  
    glVertex3f(-0.5f, -0.5f, -0.4f);  
    glVertex3f(0.5f, -0.5f, -0.4f);  
    glEnd();

    glBegin(GL_POLYGON);
    // Front
    glColor3f(0.0,0.0,2.0);      
    glVertex3f(0.5f, 0.5f, 0.4f); 
    glVertex3f(-0.5f, 0.5f, 0.4f);  
    glVertex3f(-0.5f, -0.5f, 0.4f);  
    glVertex3f(0.5f, -0.5f, 0.4f);  
    glEnd();

    glBegin(GL_POLYGON);
    // Back
    glColor3f(1.0,0.0,0.5);
    glVertex3f(0.5f, -0.5f, -0.4f); 
    glVertex3f(-0.5f, -0.5f, -0.4f);    
    glVertex3f(-0.5f, 0.5f, -0.4f); 
    glVertex3f(0.5f, 0.5f, -0.4f);  
    glEnd();

    glBegin(GL_POLYGON);
    // Left
    glColor3f(0.1,0.1,0.0);
    glVertex3f(-0.5f, 0.5f, 0.4f);
    glVertex3f(-0.5f, 0.5f, -0.4f); 
    glVertex3f(-0.5f, -0.5f, -0.4f); 
    glVertex3f(-0.5f, -0.5f, 0.4f); 
    glEnd();

    glBegin(GL_POLYGON);
    // Right
    glColor3f(1.0,0.0,0.1);
    glVertex3f(0.5f, 0.5f, -0.4f);  
    glVertex3f(0.5f, 0.5f, 0.4f);  
    glVertex3f(0.5f, -0.5f, 0.4f);  
    glVertex3f(0.5f, -0.5f, -0.4f);  
    glEnd();
}    


void GLobj::ngon(int n)
{
    float degree, vertx, verty, rotate, degToRad;
    rotate = 360.0/n;               //Vertex rotation increment
    degree = rotate/2 + 180;        //Current degree of vertex (starts rotated to make object upright)
    degToRad = 180/3.14159;         //Conversion factor from degrees to radians

    glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++, degree += rotate) 
    {
        vertx = 0.5 * sin(degree/degToRad);         //next vertex's x coordinate 
        verty = 0.5 * sin((90 - degree)/degToRad);  //next vertex's y coordinate 
        glVertex3f(vertx, verty, 0); 
    }
    glEnd();
}
