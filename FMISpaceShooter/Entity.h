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
	void moveUp(int);
	void moveDown(int);
	void moveLeft(int);
	void moveRight(int);
	char** getSprite();
	char getChar(int y, int x);
	Entity(int xPos, int yPos, int width, int height);
	Entity(const Entity&);
	~Entity();
};