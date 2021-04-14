#pragma once
#ifndef __CLOUDS__
#define __CLOUDS__
#include "DisplayObject.h"
#include "TextureManager.h"

class Clouds final : public DisplayObject
{
public:
	Clouds();
	~Clouds();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

	int getClouds();
	void setClouds(int num);

private:
	int m_Clouds;
};

#endif // !__CLOUDS__
