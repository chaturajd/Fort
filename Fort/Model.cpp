#include "Model.h"

void Model::initialize(std::vector<float> vertices, std::vector<float> normals, std::vector<std::vector<std::vector<int>>> faces)
{
	Model::vertices = vertices;
	Model::normals = normals;
	Model::faces = faces;

	genarateList();
}

void Model::printDetails()
{
	std::cout << "List ID: " << listId << std::endl;
	std::cout << "Vertices Count: " << vertices.size()<<std::endl;
	std::cout << "faces Count: " << faces.size() << std::endl;
	std::cout << "Normals Count: " << normals.size() << std::endl;

}

void Model::genarateList()
{
	glNewList(listId, GL_COMPILE);
		draw(GL_QUADS);
	glEndList();
}

void Model::render()
{
	for (auto& face : faces)
	{
		glBegin(GL_QUADS);
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
			float vnX = vertices[vn1];
			float vnY = vertices[vn2];
			float vnZ = vertices[vn3];

			glVertex3f(vX, vY, vZ);
			glNormal3f(vnX, vnY, vnZ);
		}
		glEnd();
	}
}

void Model::draw(GLenum drawMethod)
{
	//glBegin(GL_QUADS);
	//for (auto& face : faces)
	//{
	//	for (auto& vertex : face)
	//	{
	//		//Vertex
	//		int v1 = (vertex[0] - 1) * 3;
	//		int v2 = (vertex[0] - 1) * 3 + 1;
	//		int v3 = (vertex[0] - 1) * 3 + 2;
	//		float vX = vertices[v1];
	//		float vY = vertices[v2];
	//		float vZ = vertices[v3];

	//		//Normal
	//		int vn1 = (vertex[1] - 1) * 3;
	//		int vn2 = (vertex[1] - 1) * 3 + 1;
	//		int vn3 = (vertex[1] - 1) * 3 + 2;
	//		float vnX = vertices[vn1];
	//		float vnY = vertices[vn2];
	//		float vnZ = vertices[vn3];

	//		glVertex3f(vX, vY, vZ);
	//		glNormal3f(vnX, vnY, vnZ);
	//	}
	//}
	//glEnd();
}



