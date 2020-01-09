/*****************************************************************************
******************************************************************************
CS 308 | Computer Graphics | Group Project

KEYBOARD :
	a,s,d	=> Cube's Rotation
	o,p		=> Change Scene

*****************************************************************************
******************************************************************************/

#include <iostream>
#include <vector>
#include "GL\glut.h"
#include "Transform.h"
#include "Model.h"
#include "MainScreen.h"
#include "Menu.h"


//LIGHTS
GLfloat light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };  /* Red diffuse light. */
GLfloat light1_diffuse[] = { 0.0, 0.50, 1.0, 1.0 };  /* Red diffuse light. */

GLfloat light_position[] = { 3.0, 3.0, 3.0, 1.0 };  /* Infinite light location. */
GLfloat light1_position[] = { -3.0, 3.0, -3.0, 1.0 };  /* Infinite light location. */

//CAMERA
bool cameraR = false; //Camera Rotation
Transform camera;

//Scenes
//Scene *ms = new MainScreen();
Scene *menu = new Menu();


Scene *currentScene;

void initScenes()
{
	//ms->initialize();
	menu->initialize();

	currentScene = menu;
	//currentScene = ms;

//	cube->initialize(verts, vertexNormals, faces);
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light1_position);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	//glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glOrtho(-3, 3, -3, 3, -3, 3);

	initScenes();

}

void updateCamera(Transform t)
{
	glMatrixMode(GL_PROJECTION);
	glRotatef(t.getRotation().x, 1.0f, .0f, .0f);
	glRotatef(t.getRotation().y, .0f, 1.0f, .0f);
	glRotatef(t.getRotation().z, .0f, .0f, 1.0f);
}

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		currentScene->render();
		updateCamera(camera);

	glutSwapBuffers();
}

void onKeyDown(unsigned char key, int x, int y)
{
	if (key == 'c') cameraR = true;

	if (key == 'p')
	{
		//currentScene = ms;
	}
	if (key == 'o')
	{
		currentScene = menu;
	}

	currentScene->keyDown(key);

}

void onKeyUp(unsigned char key, int x, int y)
{

	if (key == 'c')	cameraR = false;
}

void Update(int value)
{
	if (cameraR) camera.setRotation(camera.getRotation().x, camera.getRotation().y + .01f, camera.getRotation().z);
	else camera.setRotation(camera.getRotation().x, 0, camera.getRotation().z);

	glutPostRedisplay();
	glutTimerFunc(30, Update, 0);
}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	//Create A window
	glutCreateWindow("");
	init();

	//glutIdleFunc(renderScene);
	glutDisplayFunc(renderScene);

	glutKeyboardFunc(onKeyDown);
	glutKeyboardUpFunc(onKeyUp);

	glutTimerFunc(1, Update, 0);
	glutMainLoop();
}
