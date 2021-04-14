#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ship.h"
#include "Button.h"
#include "Player.h"
#include "BackRound.h"
#include "Ground.h"
#include "Moon.h"
#include "Clouds.h"

class StartScene final : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	void m_CloudsScroll();
	
private:
	Label* m_pStartLabel{};
	Label* m_pInstructionsLabel{};
	Label* m_pInstructionsLabel2{};
	Background* m_pBackground;
	Ground* m_pGround;
	Moon* m_pMoon;
	Clouds* m_pClouds1;
	Clouds* m_pClouds2;
	Player* m_pPlayer;
	Ship* m_pShip{};
	Button* m_pStartButton;

	int randomNumber;
};

#endif /* defined (__START_SCENE__) */