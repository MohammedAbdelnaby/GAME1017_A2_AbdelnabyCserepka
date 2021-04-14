#include "Moon.h"

Moon::Moon()
{
	TextureManager::Instance()->load("../Assets/textures/Moon.png", "mn");
	auto size = TextureManager::Instance()->getTextureSize("mn");
	setWidth(size.x);
	setHeight(size.y);
	//getTransform()->position = glm::vec2(800.0f, 300.0f);
}

Moon::~Moon()
= default;

void Moon::draw()
{
	TextureManager::Instance()->draw("mn", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
}

void Moon::update()
{

}

void Moon::clean()
{

}