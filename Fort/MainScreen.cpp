#include "MainScreen.h"

Model *cube;

void MainScreen::initialize()
{
std::string filePath = "F:\\untitled1.obj";
	ModelLoader loader;
	std::cout << "Initializing MainScreen" << std::endl;
	//cube->initialize(verts, vertexNormals, faces);
	cube = loader.loadModel(filePath);

}

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
void MainScreen::render()
{
//	std::cout << "Rendering MainScreen" << std::endl;
	/*glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glRotatef(angleX, 1.0f, 0.0f, 0.0f);
		glRotatef(angleY, .0f, 01.0f, 0.0f);
		glRotatef(angleZ, .0f, 0.0f, 01.0f);*/
		cube->render();
	//glPopMatrix();

}

void MainScreen::keyDown(unsigned char key)
{
	
	if (key == 'a') angleX += 01.1f;
	if (key == 's') angleY += 01.1f;
	if (key == 'd') angleZ += 01.1f;
}



//Using Indexed Vertex Buffer
//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//drawCube();
//cube->render();


//glMatrixMode(GL_MODELVIEW);
//glPushMatrix();
//glEnableClientState(GL_VERTEX_ARRAY);
////glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//glEnableClientState(GL_NORMAL_ARRAY);
//
//glVertexPointer(3, GL_FLOAT, 0, corners);

//glNormalPointer(GL_FLOAT,0,normals);
//
//glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indexes);
//
//glDisableClientState(GL_VERTEX_ARRAY);
//glDisableClientState(GL_NORMAL_ARRAY);

//glPopMatrix();