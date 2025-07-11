#pragma once
#include "raylib.h"
#include "GraphicObject.h"

class Paralax : public GraphicObject
{
public:
	float paralaxSpeed = 0.2f;
	int paralaxDirection = -1;
	Vector2 startPos = Vector2{ 0.0f, 0.0f };

public:
	Paralax();

public:
	void Move();
	void Update() override;
};