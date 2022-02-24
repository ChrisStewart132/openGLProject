/*  =================================================================
*  COSC363: Computer Graphics (2021);  University of Canterbury.
*
*  FILE NAME: Teapot.cpp
*  A very basic OpenGL program to display a teapot
*  =================================================================*/


#include <GL/freeglut.h>


//==================================================================
// This is the main display module containing OpenGL function calls  for
// rendering a scene.  This function is registered as a display callback
// using 'glutDisplayFunc()'   in main().

void display(void)
{
	float lpos[4] = { 0., 10., 10., 1.0 };  //light's position

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 2, 11, 0, 0, 0, 0, 1, 0);		//Camera position and orientation

	glLightfv(GL_LIGHT0, GL_POSITION, lpos);		//Set light's position

	glColor3f(0.0, 1.0, 1.0);					//The color of the model
	glRotatef(10, 1, 0, 0);						//A small rotation about the x-axis
	glutSolidTeapot(1.0);						//The ever popular teapot!

	glFlush();

}

//==================================================================
//  Initialize function:
//  Used for initializing OpenGL state (lighting, color material, depth test etc.)

void initialize(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   //Background color

	glEnable(GL_LIGHTING);					//Enable OpenGL states
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);			//The projection matrix of the camera
	glLoadIdentity();
	glFrustum(-2.0, 2.0, -2.0, 2.0, 10.0, 1000.0);   //Camera frustum definition
}


//==================================================================
//  The Main function: 
//  Initializes glut window and registers callbacks

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);	//Buffers used for display  
	glutInitWindowSize(600, 600);					//Display window size in pixels
	glutInitWindowPosition(0, 0);					//Window's position w.r.t top-left corner of screen
	glutCreateWindow("Teapot");						//Title of the window
	initialize();									//A user defined function for initialising OpenGL parameters
	glutDisplayFunc(display);						//Register 'display()'  as a callback function
	glutMainLoop();									//Enter an infinite loop, waiting for events.
	//Do not place any code here!
	return 0;
}

