#pragma once

class Entity {
protected:
	int xPos;
	int yPos;
	int width;
	int height;

	char** sprite;
	Entity();
public:
	int getPosX();
	int getPosY();
	int getWidth();
	int getHeight();
	char** getSprite();
	Entity(int xPos, int yPos, int width, int height);
	Entity(const Entity&);
	~Entity();
};