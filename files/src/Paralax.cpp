#include "Paralax.h"
#include <iostream>

Paralax::Paralax()
{
}

void Paralax::Move()	
{
	position += Vector2{ paralaxDirection * paralaxSpeed, 0.0f };
	if (position.x < -GetScreenWidth())
	{
		position = Vector2{ 0.0f,0.0f };
	}
}

void Paralax::Update() {
	GraphicObject::Update();
	Vector2 offset = Vector2(GetScreenWidth(), 0.0f);
	
	DrawTextureEx(texture, (position + offset), rotation, scale, LIGHTGRAY);
	Move();
}
