#pragma once
#ifndef __EXTRASCROLL__
#define __EXTRASCROLL__
#include "DisplayObject.h"
#include "TextureManager.h"

class ExtraScroll final : public DisplayObject
{
public:
	ExtraScroll();
	~ExtraScroll();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

private:

};

#endif // !__EXTRASCROLL__

