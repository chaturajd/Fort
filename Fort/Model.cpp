#include "Model.h"

//Initializes an object using custom arrays of data
void Model::initialize(std::vector<float> vertices, std::vector<float> normals, std::vector<std::vector<std::vector<int>>> faces)
{
	Model::vertices = vertices;
	Model::normals = normals;
	Model::faces = faces;

	//loadTexture("F:\\Untitled.png");
	genarateList();
}

//Prints object's data counts
void Model::printDetails()
{
	std::cout << "List ID: " << listId << std::endl;
	std::cout << "Vertices Count: " << vertices.size()<<std::endl;
	std::cout << "faces Count: " << faces.size() << std::endl;
	std::cout << "Normals Count: " << normals.size() << std::endl;
}

//Compiles a display list for rendering
void Model::genarateList()
{
	glNewList(listId, GL_COMPILE);
	glPushMatrix();
	glScalef(transform.getScale().x, transform.getScale().y, transform.getScale().z);
	glRotated(transform.getRotation().x, 1.0f, 0.0f, 0.0f);
	glRotated(transform.getRotation().y, 0.0f, 1.0f, 0.0f);
	glRotated(transform.getRotation().z, 0.0f, 0.0f, 1.0f);
	glTranslatef(transform.getPosition().x, transform.getPosition().y, transform.getPosition().z);

	for (auto& face : faces)
	{
		glBegin(GL_POLYGON);
		for (auto& vertex : face)
		{
			//Vertex
			int v1 = (vertex[0] - 1) * 3;
			int v2 = (vertex[0] - 1) * 3 + 1;
			int v3 = (vertex[0] - 1) * 3 + 2;
			float vX = vertices[v1];
			float vY = vertices[v2];
			float vZ = vertices[v3];

			//Normal
			int vn1 = (vertex[2] - 1) * 3;
			int vn2 = (vertex[2] - 1) * 3 + 1;
			int vn3 = (vertex[2] - 1) * 3 + 2;
			float vnX = normals[vn1];
			float vnY = normals[vn2];
			float vnZ = normals[vn3];

			//int vt1 = (vertex[1] - 1) * 2;
			//int vt2 = (vertex[1] - 1) * 2 + 1;
			//float vtX = texture[vn1];
			//float vtY = texture[vn2];

			glNormal3f(vnX, vnY, vnZ);
			//glTexCoord2f(vtX,vtY);
			glVertex3f(vX, vY, vZ);
		}
		glEnd();
	}
	glPopMatrix();
	glEndList();
}

//Renders using genarated display list
void Model::draw()
{
	glCallList(listId);
}

//Renders the object in imediate mode
void Model::render()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(transform.getScale().x, transform.getScale().y, transform.getScale().z);
	glRotated(transform.getRotation().x, 1.0f, 0.0f, 0.0f);
	glRotated(transform.getRotation().y, 0.0f, 1.0f, 0.0f);
	glRotated(transform.getRotation().z, 0.0f, 0.0f, 1.0f);
	glTranslatef(transform.getPosition().x, transform.getPosition().y, transform.getPosition().z);

	for (auto& face : faces)
	{
	glBegin(GL_POLYGON);
		for (auto& vertex : face)
		{
			//Vertex
			int v1 = (vertex[0] - 1) * 3;
			int v2 = (vertex[0] - 1) * 3 + 1;
			int v3 = (vertex[0] - 1) * 3 + 2;
			float vX = vertices[v1];
			float vY = vertices[v2];
			float vZ = vertices[v3];

			//Normal
			int vn1 = (vertex[2] - 1) * 3;
			int vn2 = (vertex[2] - 1) * 3 + 1;
			int vn3 = (vertex[2] - 1) * 3 + 2;
			float vnX = normals[vn1];
			float vnY = normals[vn2];
			float vnZ = normals[vn3];

			//int vt1 = (vertex[1] - 1) * 2;
			//int vt2 = (vertex[1] - 1) * 2 + 1;
			//float vtX = texture[vn1];
			//float vtY = texture[vn2];

			glNormal3f(vnX, vnY, vnZ);
			//glTexCoord2f(vtX,vtY);
			glVertex3f(vX, vY, vZ);
		}
	glEnd();
	}
	glPopMatrix();
}

//TODO
//Load Textures. 
void Model::loadTexture(const char* path)
{

	//int width, height;
	//unsigned char* image = SOIL_load_image("F:\\Untitled.png", &width, &height, 0, SOIL_LOAD_RGB);
	//glTexImage2D(GL_TEXTURE_2D, 0, 0, width, height,
	//	0,GL_RGB, GL_UNSIGNED_BYTE, image);
	////	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	//SOIL_free_image_data(image);
	//
	//
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	/*int width, height;
	unsigned char* image = SOIL_load_image(path,&width,&height,0,SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
	SOIL_free_image_data(image);*/

	//glTexParameteri(GL_TEXTURE_2D, );


}
