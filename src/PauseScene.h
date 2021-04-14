#pragma once
#ifndef __PAUSESCENE__
#define __PAUSESCENE__
#include "DisplayObject.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Button.h"

class PauseScene final : public Sprite
{
public:
	PauseScene();
	~PauseScene();

	// Life Cycle Functions
	void draw() override;
	void update() override;
	void clean() override;
	void setIsPaused(bool x);
	bool getIsPaused();
private:
	bool m_isPaused;
	Button* m_pResume;
};
#endif // !__PAUSESCENE__