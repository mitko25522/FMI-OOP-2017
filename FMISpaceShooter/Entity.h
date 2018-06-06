#pragma once

class Entity {
	int xPos;
	int yPos;
	int width;
	int height;

	char** sprite;
	Entity();
public:
	Entity(int, int, int, int);
	Entity(const Entity&);
	~Entity();
};