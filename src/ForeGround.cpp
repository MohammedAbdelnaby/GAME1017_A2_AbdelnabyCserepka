#include "ForeGround.h"

Foreground::Foreground()
{
	TextureManager::Instance()->load("../Assets/textures/Foreground_1.png", "fg1");
	TextureManager::Instance()->load("../Assets/textures/Foreground_2.png", "fg2");
	TextureManager::Instance()->load("../Assets/textures/Foreground_3.png", "fg3");
	TextureManager::Instance()->load("../Assets/textures/Foreground_4.png", "fg4");
	auto size = TextureManager::Instance()->getTextureSize("fg1");
	setWidth(size.x);
	setHeight(size.y);
}

Foreground::~Foreground()
= default;

void Foreground::draw()
{
	if (getForeground() == 1)
	{
		TextureManager::Instance()->draw("fg1", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
	}
	else if (getForeground() == 2)
	{
		TextureManager::Instance()->draw("fg2", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
	}
	else if (getForeground() == 3)
	{
		TextureManager::Instance()->draw("fg3", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
	}
	else
	{
		TextureManager::Instance()->draw("fg4", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
	}
}

void Foreground::update()
{
	
}

void Foreground::clean()
{

}

int Foreground::getForeground()
{
	return m_foreground;
}

void Foreground::setForeground(int num)
{
	m_foreground = num;
}
