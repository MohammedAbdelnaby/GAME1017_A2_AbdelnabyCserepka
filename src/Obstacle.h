#pragma once
#ifndef __OBSTACLE__
#define __OBSTACLE__
#include "DisplayObject.h"
#include "TextureManager.h"
#include "Sprite.h"

class Obstacle final : public Sprite
{
public:
	Obstacle(int x);
	~Obstacle();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;
	int getRandomPiller();
	void setRandomPiller(int x);

private:
	int m_RandomPiller;
};
#endif // !__OBSTACLE__