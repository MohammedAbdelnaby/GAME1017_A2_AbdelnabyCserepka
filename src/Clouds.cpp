#include "Clouds.h"

Clouds::Clouds()
{
	TextureManager::Instance()->load("../Assets/textures/Clouds_1.png", "c1");
	TextureManager::Instance()->load("../Assets/textures/Clouds_2.png", "c2");
	TextureManager::Instance()->load("../Assets/textures/Clouds_3.png", "c3");
	TextureManager::Instance()->load("../Assets/textures/Clouds_4.png", "c4");
	auto size = TextureManager::Instance()->getTextureSize("c1");
	setWidth(size.x);
	setHeight(size.y);
}

Clouds::~Clouds()
= default;

void Clouds::draw()
{
	if (getClouds() == 1)
	{
		TextureManager::Instance()->draw("c1", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
	}
	else if (getClouds() == 2)
	{
		TextureManager::Instance()->draw("c2", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
	}
	else if (getClouds() == 3)
	{
		TextureManager::Instance()->draw("c3", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
	}
	else
	{
		TextureManager::Instance()->draw("c4", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
	}
}

void Clouds::update()
{

}

void Clouds::clean()
{

}

int Clouds::getClouds()
{
	return m_Clouds;
}

void Clouds::setClouds(int num)
{
	m_Clouds = num;
}