#pragma once
#ifndef __BACKGROUND__
#define __BACKGROUND__
#include "DisplayObject.h"
#include "TextureManager.h"

class Background final : public DisplayObject
{
public:
	Background();
	~Background();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

private:

};

#endif // !__BACKGROUND__