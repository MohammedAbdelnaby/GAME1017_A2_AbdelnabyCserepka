#pragma once
#ifndef __FOREGROUND__
#define __FOREGROUND__
#include "DisplayObject.h"
#include "TextureManager.h"

class Foreground final : public DisplayObject
{
public:
	Foreground();
	~Foreground();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;

	int getForeground();
	void setForeground(int num);

private:
	int m_foreground;
};

#endif // !__FOREGROUND__