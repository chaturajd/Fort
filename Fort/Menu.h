#include <iostream>
#include "Scene.h"


class Menu : public Scene
{
public:
	Menu(){}
	~Menu(){}

	void initialize();
	void render();
	void keyDown(unsigned char key);


private:

};
