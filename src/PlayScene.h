#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "time.h"

#include "Scene.h"
#include "Plane.h"
#include "Player.h"
#include "Button.h"
#include "Label.h"
#include "BackRound.h"
#include "Ground.h"
#include "Obstacle.h"
#include <time.h>
#include "CollisionManager.h"
#include "ForeGround.h"
#include "Moon.h"
#include "PauseScene.h"
#include "MidGround.h"
#include "ExtraScroll.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	void m_objectScrolling();
	void m_ObstacleScrolling();
	void m_CollisionUpdate();
	void m_BackgroundScroll();
	void m_ForegroundScroll();
	void m_MidGroundScroll();
	void m_ExtraScroll();
	void TimerCounter();
private:
	// IMGUI Function
	void GUI_Function() const;
	std::string m_guiTitle;
	
	Obstacle* m_pObstacle;
	glm::vec2 m_mousePosition;
	Background* m_pBackground1;
	Background* m_pBackground2;
	Foreground* m_pForeground1;
	Foreground* m_pForeground2;
	MidGround* m_pMidGround1;
	MidGround* m_pMidGround2;
	ExtraScroll* m_pExtraScroll1;
	ExtraScroll* m_pExtraScroll2;
	Moon* m_pMoon;
	Ground* m_pGround[2];
	Player* m_pPlayer;
	int randomNumber;
	int cooldown = 40;
	PauseScene* m_pPauseScene;
	int m_TimerCounter;
	Label* m_pTimer;
};

#endif /* defined (__PLAY_SCENE__) */