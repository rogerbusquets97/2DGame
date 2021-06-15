#pragma once
#include <string>

struct RenderableComponent
{
	std::string fileName;

	RenderableComponent(const std::string& i_fileName) : fileName(i_fileName)
	{
	}

	RenderableComponent()
	{}
};

struct TransformComponent
{
	float x;
	float y;

	float angle;

	TransformComponent(float i_x, float i_y, float i_angle) : x(i_x), y(i_y), angle(i_angle)
	{
	}

	TransformComponent() : x(0.0f), y(0.0f), angle(0.0f)
	{
	}
};