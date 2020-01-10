#pragma once

#include <vector>
#include <iostream>
#include "GL\glut.h"
#include "Transform.h"
#include "SOIL\SOIL.h"

class Model
{
public:
	Model(){}
	~Model(){}

	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> texture;
	std::vector<std::vector<std::vector<int>>> faces;
	Transform transform;
	
	int listId;
	
	void initialize(std::vector<float> vertices, std::vector<float> normals, std::vector<std::vector<std::vector<int>>> faces);
	void render();
	void loadTexture(const char* path);
	void genarateList();
	void printDetails();
	void draw(GLenum drawMethod);


private:
};
