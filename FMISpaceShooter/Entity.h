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
	bool isInCollisionWith(const Entity&);
	int getPosX() const;
	int getPosY() const;
	int getWidth() const;
	int getHeight() const;
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