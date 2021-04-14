#pragma once
#ifndef __MIDGROUND__
#define __MIDGROUND__
#include "DisplayObject.h"
#include "TextureManager.h"

class MidGround final : public DisplayObject
{
public:
	MidGround();
	~MidGround();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

private:

};

#endif // !__MIDGROUND__
