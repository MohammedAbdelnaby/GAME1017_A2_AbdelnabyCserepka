#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
	m_CloudsScroll();

	for (int i = 0; i < 2; i++)
	{
		if (int(m_pPlayer->getTransform()->position.y + m_pPlayer->getHeight() - m_pPlayer->getRigidBody()->velocity.y) >= m_pGround->getTransform()->position.y)
		{
			m_pPlayer->getRigidBody()->velocity.y = 0.0f;
			m_pPlayer->getTransform()->position.y = m_pGround->getTransform()->position.y - m_pPlayer->getHeight() + m_pPlayer->getHeight() / 2;
			m_pPlayer->setisGorunded(true);
		}
		else
		{
			m_pPlayer->setisGorunded(false);
		}
	}
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	const SDL_Color gray = { 188, 164, 164, 255 };

	m_pBackground = new Background();
	m_pBackground->getTransform()->position = glm::vec2(400.0f, 250.0f);
	addChild(m_pBackground);

	m_pMoon = new Moon();
	m_pMoon->getTransform()->position = glm::vec2(400.0f, 230.0f);
	addChild(m_pMoon);

	m_pClouds1 = new Clouds();
	m_pClouds1->getTransform()->position = glm::vec2(400.0f, 230.0f);
	addChild(m_pClouds1);

	m_pClouds2 = new Clouds();
	m_pClouds2->getTransform()->position = glm::vec2(1200.0f, 230.0f);
	addChild(m_pClouds2);

	m_pGround = new Ground();
	m_pGround->getTransform()->position = glm::vec2(0.0f, 505.0f);
	addChild(m_pGround);

	m_pPlayer = new Player();
	m_pPlayer->getTransform()->position = glm::vec2(380.0, 50.0);
	addChild(m_pPlayer);

	m_pStartLabel = new Label("Assignment 3", "Consolas", 80, gray, glm::vec2(400.0f, 220.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("Mohammed Abdelnaby (101295593)", "Consolas", 40, gray, glm::vec2(400.0f, 300.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	m_pInstructionsLabel = new Label("Reuben Cserepka (101334740)", "Consolas", 40, gray, glm::vec2(400.0f, 340.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(400.0f, 400.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);
}

void StartScene::m_CloudsScroll()
{
	srand(unsigned(time(NULL)));

	m_pClouds1->getTransform()->position.x -= 1.25f;
	m_pClouds2->getTransform()->position.x -= 1.25f;

	if (m_pClouds1->getTransform()->position.x <= -m_pClouds1->getWidth() + 400)
	{
		randomNumber = 1 + (rand() % 4);
		std::cout << randomNumber << std::endl;
		m_pClouds1->setClouds(randomNumber);
		m_pClouds1->getTransform()->position.x = m_pClouds1->getWidth() + 400;
	}
	if (m_pClouds2->getTransform()->position.x <= -m_pClouds2->getWidth() + 400)
	{
		randomNumber = 1 + (rand() % 4);
		std::cout << randomNumber << std::endl;
		m_pClouds2->setClouds(randomNumber);
		m_pClouds2->getTransform()->position.x = m_pClouds2->getWidth() + 400;
	}
}

