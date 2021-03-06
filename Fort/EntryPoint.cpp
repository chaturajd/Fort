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
GLfloat light_diffuse[] = { .90, 0.90, 0.90, 1.0 };  /* White diffuse light. */
GLfloat light1_diffuse[] = { 0.0, 0.50, 1.0, 1.0 };  /* Red diffuse light. */

GLfloat light_position[] = { 2.0, 3.0, 0.0, 1.0 };  /* Infinite light location. */
GLfloat light1_position[] = { 3.0, 3.0, 3.0, 1.0 };  /* Infinite light location. */

GLfloat globalAmbient[] = { 0.90, 0.90, 0.90, 1.0 };
//CAMERA
bool cameraR = false; //Camera Rotation
Transform camera;

//Scenes
Scene *ms = new MainScreen();
Scene *menu = new Menu();


Scene *currentScene;

void initScenes()
{
	ms->initialize();
	menu->initialize();

	currentScene = menu;
	//currentScene = ms;

//	cube->initialize(verts, vertexNormals, faces);
}

void init()
{
	glClearColor(0.00, 0.15, 0.20, 1.0);
	
	glColor3f(1.0, 1.0, 1.0);


	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);

	//glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glRotatef(-30.0f, 1.0f, 0.0f, .0);
	glOrtho(-3, 3, -.5, 5.5, -3, 3);

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
		currentScene = ms;
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
