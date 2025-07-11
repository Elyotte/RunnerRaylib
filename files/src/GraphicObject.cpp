#include "GraphicObject.h"
#include <iostream>

GraphicObject::GraphicObject() {
	DrawTextureEx(texture, position, rotation, scale, LIGHTGRAY);
	std::cout << "graphic object instanciated" << std::endl;
}

void GraphicObject::Destroy() {
	UnloadTexture(texture);
}

void GraphicObject::Update() {
	DrawTextureEx(texture, position, rotation, scale, LIGHTGRAY);
}