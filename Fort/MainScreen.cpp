#include "MainScreen.h"


std::vector<float> verts = {
	-0.694383f, -0.694383f, 1.000000f,	  //1
	-0.694383f, 0.694383f, 1.000000f,	  //2
	-1.000000f, -1.000000f, -1.000000f,  //3
	-1.000000f, 1.000000f, -1.000000f,	  //4
	0.694383f, -0.694383f, 1.000000f,	  //5
	0.694383f, 0.694383f, 1.000000f,	  //6
	1.000000f, -1.000000f, -1.000000f,	  //7
	1.000000f, 1.000000f, -1.000000f,	  //8
	-1.000000f, -1.000000f, 1.000000f,	  //9
	-1.000000f, 1.000000f, 1.000000f,	  //10
	1.000000f, 1.000000f, 1.000000f,	  //11
	1.000000f, -1.000000f, 1.000000f,	  //12
	-0.694383f, -0.694383f, 0.397366f,	  //13
	-0.694383f, 0.694383f, 0.397366f,	  //14
	0.694383f, -0.694383f, 0.397366f,	  //15
	0.694383f, 0.694383f, 0.397366f 	  //16
};

std::vector<float> vertexNormals = {
	-1.0000f, 0.0000f, 0.0000f,
	0.0000f, 0.0000f, -1.0000f,
	1.0000f, 0.0000f, 0.0000f,
	0.0000f, 1.0000f, 0.0000f,
	0.0000f, -1.0000f, 0.0000f,
	0.0000f, 0.0000f, 1.0000f
};

//Vertex Index,Normal Index
std::vector<std::vector<std::vector<int>>> faces = {
	{ { 9, 1 }, { 10, 1 }, { 4, 1 }, { 3, 1 } },
	{ { 3, 2 }, { 4, 2 }, { 8, 2 }, { 7, 2 } },
	{ { 7, 3 }, { 8, 3 }, { 11, 3 }, { 12, 3 } },
	{ { 1, 4 }, { 5, 4 }, { 15, 4 }, { 13, 4 } },
	{ { 3, 5 }, { 7, 5 }, { 12, 5 }, { 9, 5 } },
	{ { 8, 4 }, { 4, 4 }, { 10, 4 }, { 11, 4 } },
	{ { 1, 6 }, { 2, 6 }, { 10, 6 }, { 9, 6 } },
	{ { 6, 6 }, { 5, 6 }, { 12, 6 }, { 11, 6 } },
	{ { 5, 6 }, { 1, 6 }, { 9, 6 }, { 12, 6 } },
	{ { 2, 6 }, { 6, 6 }, { 11, 6 }, { 10, 6 } },
	{ { 15, 6 }, { 16, 6 }, { 14, 6 }, { 13, 6 } },
	{ { 2, 3 }, { 1, 3 }, { 13, 3 }, { 14, 3 } },
	{ { 6, 5 }, { 2, 5 }, { 14, 5 }, { 16, 5 } },
	{ { 5, 1 }, { 6, 1 }, { 16, 1 }, { 15, 1 } }
};

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