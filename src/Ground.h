#pragma once
#ifndef __GROUND__
#define __GROUND__
#include "DisplayObject.h"
#include "TextureManager.h"

class Ground final : public DisplayObject
{
public:
	Ground();
	~Ground();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

private:

};

#endif // !__GROUND__