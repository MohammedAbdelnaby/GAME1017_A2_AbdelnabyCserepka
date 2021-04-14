#pragma once
#ifndef __MOON__
#define __MOON__
#include "DisplayObject.h"
#include "TextureManager.h"

class Moon final : public DisplayObject
{
public:
	Moon();
	~Moon();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

private:

};

#endif // !__MOON__
