#include "Obstacle.h"

Obstacle::Obstacle(int x = 1) : m_RandomPiller(x)
{
	TextureManager::Instance()->load("../Assets/textures/PineapplePiller.png", "Pineapple");
	TextureManager::Instance()->load("../Assets/textures/watermelonPiller.png", "watermelon");
	TextureManager::Instance()->load("../Assets/textures/CoconutPiller.png", "Coconut");
	auto size = TextureManager::Instance()->getTextureSize("Pineapple");
	setWidth(size.x);
	setHeight(size.y);
	getTransform()->position = glm::vec2(400.f, 200.0f);
}

Obstacle::~Obstacle()
= default;

void Obstacle::draw()
{
	if (m_RandomPiller == 1)
	{
		TextureManager::Instance()->draw("Pineapple", getTransform()->position.x, getTransform()->position.y, 0, 255, false);
	}
	else if (m_RandomPiller == 2)
	{
		TextureManager::Instance()->draw("watermelon", getTransform()->position.x, getTransform()->position.y, 0, 255, false);
	}
	else if (m_RandomPiller == 3)
	{
		TextureManager::Instance()->draw("Coconut", getTransform()->position.x, getTransform()->position.y, 0, 255, false);
	}
}

void Obstacle::update()
{
}

void Obstacle::clean()
{
}

int Obstacle::getRandomPiller()
{
	return m_RandomPiller;
}

void Obstacle::setRandomPiller(int x)
{
	m_RandomPiller = x;
}
