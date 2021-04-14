#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	if(EventManager::Instance().isIMGUIActive())
	{
		GUI_Function();
	}

	drawDisplayList();
	SDL_SetRenderDrawColor(Renderer::Instance()->getRenderer(), 255, 255, 255, 255);
}

void PlayScene::update()
{
	if (m_pPauseScene->getIsPaused())
	{
		m_pPauseScene->update();
		return;
	}
	TimerCounter();
	m_ObstacleScrolling();
	m_objectScrolling();
	updateDisplayList();
	m_CollisionUpdate();
	m_BackgroundScroll();
	m_ForegroundScroll();
	m_MidGroundScroll();
	m_ExtraScroll();

	for (int i = 0; i < 2; i++)
	{
		if (int(m_pPlayer->getTransform()->position.y + m_pPlayer->getHeight() - m_pPlayer->getRigidBody()->velocity.y) >= m_pGround[i]->getTransform()->position.y)
		{
			m_pPlayer->getRigidBody()->velocity.y = 0.0f;
			m_pPlayer->getTransform()->position.y = m_pGround[i]->getTransform()->position.y - m_pPlayer->getHeight() + m_pPlayer->getHeight()/2;
			m_pPlayer->setisGorunded(true);
		}
		else
		{
			m_pPlayer->setisGorunded(false);
		}
	}
	cooldown--;
}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();


	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		if (cooldown <= 0)
		{
			if (m_pPauseScene->getIsPaused())
			{
				std::cout << " NOT Paused" << std::endl;
				m_pPauseScene->setIsPaused(false);
			}
			else
			{
				std::cout << "Paused" << std::endl;
				m_pPauseScene->setIsPaused(true);
			}
			cooldown = 40;
		}
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
	{
		m_pPlayer->move();
		m_pPlayer->setCurrentDirection(glm::vec2(-1.0f, m_pPlayer->getCurrentDirection().y));
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
	{
		m_pPlayer->move();
		m_pPlayer->setCurrentDirection(glm::vec2(1.0f, m_pPlayer->getCurrentDirection().y));
		m_pPlayer->setAnimationState(PLAYER_RUN_RIGHT);
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_S) && m_pPlayer->getisGrounded())
	{
		m_pPlayer->setAnimationState(PLAYER_SLIDE_RIGHT);
	}
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_SPACE) && m_pPlayer->getisGrounded())
	{ 
		m_pPlayer->PlayerJump();
	}
}

void PlayScene::start()
{
	// Set GUI Title
	m_guiTitle = "Play Scene";

	m_pBackground1 = new Background();
	m_pBackground1->getTransform()->position = glm::vec2(400.0f, 250.0f);
	addChild(m_pBackground1);

	m_pBackground2 = new Background();
	m_pBackground2->getTransform()->position = glm::vec2(1200.0f, 250.0f);
	addChild(m_pBackground2);

	m_pMoon = new Moon();
	m_pMoon->getTransform()->position = glm::vec2(400.0f, 230.0f);
	addChild(m_pMoon);

	m_pForeground1 = new Foreground();
	m_pForeground1->getTransform()->position = glm::vec2(400.0f, 290.0f);
	addChild(m_pForeground1);

	m_pForeground2 = new Foreground();
	m_pForeground2->getTransform()->position = glm::vec2(1200.0f, 290.0f);
	addChild(m_pForeground2);

	m_pMidGround1 = new MidGround();
	m_pMidGround1->getTransform()->position = glm::vec2(400.0f, 415.0f);
	addChild(m_pMidGround1);

	m_pMidGround2 = new MidGround();
	m_pMidGround2->getTransform()->position = glm::vec2(1200.0f, 415.0f);
	addChild(m_pMidGround2);

	m_pExtraScroll1 = new ExtraScroll();
	m_pExtraScroll1->getTransform()->position = glm::vec2(400.0f, 415.0f);
	addChild(m_pExtraScroll1);

	m_pExtraScroll2 = new ExtraScroll();
	m_pExtraScroll2->getTransform()->position = glm::vec2(1200.0f, 415.0f);
	addChild(m_pExtraScroll2);

	m_pGround[0] = new Ground();
	m_pGround[0]->getTransform()->position = glm::vec2(0.0f, 505.0f);
	addChild(m_pGround[0]);

	m_pGround[1] = new Ground();
	m_pGround[1]->getTransform()->position = glm::vec2(800.0f, 505.0f);
	addChild(m_pGround[1]);

	m_pPlayer = new Player();
	m_pPlayer->getTransform()->position = glm::vec2(300.0, 100.0);
	addChild(m_pPlayer);

	m_pPauseScene = new PauseScene();
	addChild(m_pPauseScene);

	const SDL_Color colour = { 0,0,0,255 };
	m_pTimer = new Label("", "Consolas", 20, colour, glm::vec2(700.0f, 20.0f));
	addChild(m_pTimer);
}

void PlayScene::m_objectScrolling()
{
	m_pGround[0]->getTransform()->position.x -= 5;
	m_pGround[1]->getTransform()->position.x -= 5;
	if (m_pGround[0]->getTransform()->position.x <= -m_pGround[0]->getWidth())
	{
		m_pGround[0]->getTransform()->position.x = 0;
		m_pGround[1]->getTransform()->position.x = 800;
	}
}

void PlayScene::m_ObstacleScrolling()
{
	srand((unsigned)time(NULL));
	if (m_pObstacle == nullptr)
	{
		m_pObstacle = new Obstacle(1 + rand() % 3);
		if (m_pObstacle->getRandomPiller() == 1)
		{
			m_pObstacle->getTransform()->position = glm::vec2(950.0f, 0.0f);
		}
		if (m_pObstacle->getRandomPiller() == 2)
		{
			m_pObstacle->getTransform()->position = glm::vec2(950.0f, 475.0f);
		}
		if (m_pObstacle->getRandomPiller() == 3)
		{
			m_pObstacle->getTransform()->position = glm::vec2(950.0f, 110.0f);
		}
		addChild(m_pObstacle);
	}
	if (m_pObstacle != nullptr)
	{
		m_pObstacle->getTransform()->position.x -= 5;
	}

	if (m_pObstacle != nullptr)
	{
		if (m_pObstacle->getTransform()->position.x <= -m_pObstacle->getWidth())
		{
			removeChild(m_pObstacle);
			m_pObstacle = nullptr;
			delete m_pObstacle;
		}
	}
}

void PlayScene::m_CollisionUpdate()
{
	if (m_pObstacle != nullptr)
	{
		if (CollisionManager::AABBCheck(m_pPlayer, m_pObstacle))
		{
			TheGame::Instance()->changeSceneState(END_SCENE);
		}
	}
}

void PlayScene::m_BackgroundScroll()
{
	m_pBackground1->getTransform()->position.x -= 0.25f;
	m_pBackground2->getTransform()->position.x -= 0.25f;

	if (m_pBackground1->getTransform()->position.x <= -m_pBackground1->getWidth() + 400)
		m_pBackground1->getTransform()->position.x = m_pBackground1->getWidth() + 400;

	if (m_pBackground2->getTransform()->position.x <= -m_pBackground2->getWidth() + 400)
		m_pBackground2->getTransform()->position.x = m_pBackground2->getWidth() + 400;
}

void PlayScene::m_ForegroundScroll()
{
	srand(unsigned(time(NULL)));

	m_pForeground1->getTransform()->position.x -= 1.25f;
	m_pForeground2->getTransform()->position.x -= 1.25f;

	if (m_pForeground1->getTransform()->position.x <= -m_pForeground1->getWidth() + 400)
	{
		randomNumber = 1 + (rand() % 3);
		std::cout << randomNumber << std::endl;
		m_pForeground1->setForeground(randomNumber);
		m_pForeground1->getTransform()->position.x = m_pForeground1->getWidth() + 400;
	}
	if (m_pForeground2->getTransform()->position.x <= -m_pForeground2->getWidth() + 400)
	{
		randomNumber = 1 + (rand() % 3);
		std::cout << randomNumber << std::endl;
		m_pForeground2->setForeground(randomNumber);
		m_pForeground2->getTransform()->position.x = m_pForeground2->getWidth() + 400;
	}
}

void PlayScene::m_MidGroundScroll()
{
	m_pMidGround1->getTransform()->position.x -= 1.75f;
	m_pMidGround2->getTransform()->position.x -= 1.75f;

	if (m_pMidGround1->getTransform()->position.x <= -m_pMidGround1->getWidth() + 400)
		m_pMidGround1->getTransform()->position.x = m_pMidGround1->getWidth() + 400;

	if (m_pMidGround2->getTransform()->position.x <= -m_pMidGround2->getWidth() + 400)
		m_pMidGround2->getTransform()->position.x = m_pMidGround2->getWidth() + 400;
}

void PlayScene::m_ExtraScroll()
{
	m_pExtraScroll1->getTransform()->position.x -= 2.0f;
	m_pExtraScroll2->getTransform()->position.x -= 2.0f;

	if (m_pExtraScroll1->getTransform()->position.x <= -m_pExtraScroll1->getWidth() + 400)
		m_pExtraScroll1->getTransform()->position.x = m_pExtraScroll1->getWidth() + 400;

	if (m_pExtraScroll2->getTransform()->position.x <= -m_pExtraScroll2->getWidth() + 400)
		m_pExtraScroll2->getTransform()->position.x = m_pExtraScroll2->getWidth() + 400;
}

void PlayScene::TimerCounter()
{
	if (TheGame::Instance()->getFrames() % 60 == 0)
	{
		m_TimerCounter++;
		m_pTimer->setText("Time: " + std::to_string(m_TimerCounter));
	}
}

void PlayScene::GUI_Function() const
{
	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();
	
	ImGui::Begin("Your Window Title Goes Here", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar);

	if(ImGui::Button("My Button"))
	{
		std::cout << "My Button Pressed" << std::endl;
	}

	ImGui::Separator();

	static float float3[3] = { 0.0f, 1.0f, 1.5f };
	if(ImGui::SliderFloat3("My Slider", float3, 0.0f, 2.0f))
	{
		std::cout << float3[0] << std::endl;
		std::cout << float3[1] << std::endl;
		std::cout << float3[2] << std::endl;
		std::cout << "---------------------------\n";
	}
	
	ImGui::End();

	// Don't Remove this
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	ImGui::StyleColorsDark();
}
