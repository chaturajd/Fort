#pragma once

#include <vector>
#include <iostream>
#include "GL\glut.h"

class Model
{
public:
	Model(){}
	~Model(){}

	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<std::vector<std::vector<int>>> faces;

	int listId;
	
	void initialize(std::vector<float> vertices, std::vector<float> normals, std::vector<std::vector<std::vector<int>>> faces);
	void render();
	void genarateList();
	void printDetails();
	void draw(GLenum drawMethod);

private:

};
