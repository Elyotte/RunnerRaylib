#pragma once
#include "raylib.h"
class GraphicObject
{
public:
	Texture texture;
	Vector2 position = Vector2{ 0.0f,0.0f };
	float scale = 1.0f;
	float rotation = 0.0f;
public:
	GraphicObject();
public:
	void Destroy();
	virtual void Update();
};

