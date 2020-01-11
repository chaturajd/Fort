#include "Menu.h"

//Model *lightHouse = new Model();
GLfloat green[] = { .0, 1.0, 0.0, 1.0 };
GLfloat red[] =	  { 1.0, .0, 0.0, 1.0 };
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };

Model *m_hospital;
Model *m_lampPost;

void Menu::initialize()
{
	//std::string hospital = "F:\\FortAssets\\exports\\Export_WatchTower.obj";
	std::string hospital = "Assets\\Export_WatchTower.obj";
	//std::string hospital = "F:\\FortAssets\\exports\\Export_DutchHospital.obj";
	std::string lampPost = "Assets\\Export_LampPost.obj";


	ModelLoader loader;
	
	m_hospital = loader.loadModel(hospital);
	//m_hospital->loadTexture("");					//TODO
	m_hospital->printDetails();						//
//	m_hospital->transform.setScale(.1f, .1f, .1f);	//Set Scale of the Model 
	m_hospital->listId = glGenLists(1);				//Genarates Displat List ID
	m_hospital->setDiffuse(.0f,0.8f,1.0f);
	m_hospital->genarateList();						//Compiles the Display List


	m_lampPost = loader.loadModel(lampPost);
	m_lampPost->transform.setScale(.3f);
	m_lampPost->transform.setPosition(m_lampPost->transform.getPosition().x, -.1f, .9f);
	m_lampPost->listId = glGenLists(1);
	m_lampPost->genarateList();
	//lightHouse->initialize(lightHouse_vertices, lightHouse_vertexNormals, lightHouse_faces);

}

void Menu::render()
{
	glShadeModel(GL_SMOOTH);

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glPushMatrix();
	//glTranslatef(2.5, 5.5, 0.0);
	//glutSolidSphere(.5,32,32);
	//glPopMatrix();

	m_hospital->draw();
	//m_lampPost->draw();
}

float sx=0, sy=0, sz=0;
float rx = 0, ry = 0, rz = 0;


void Menu::keyDown(unsigned char key)
{
	switch (key)
	{
	case 'z':
		sx += .1f;
		sy += .1f;
		sz += .1f;
		break;

	case 'x':
		sx -= .1f;
		sy -= .1f;
		sz -= .1f;
		break;
	case'a':
		rx += 0.4f;
		break;

	case's':
		ry += 0.4f;
		break;

	case'd':
		rz += 0.4f;
		break;

	}

	if (sx <=0)
	{
		sx = .1f;
		sy = .1f;
		sz = .1f;
	}

	m_hospital->transform.setScale(sx, sy, sz);
	m_hospital->transform.setRotation(rx, ry, rz);


}

	
	//	glMaterialfv(GL_FRONT, GL_AMBIENT,green);
	//	glMaterialfv(GL_FRONT, GL_DIFFUSE, green);
	//	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	//	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
