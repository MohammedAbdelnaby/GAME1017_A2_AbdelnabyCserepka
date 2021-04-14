#include "BackRound.h"

Background::Background()
{
	TextureManager::Instance()->load("../Assets/textures/Background.png", "bg");
	auto size = TextureManager::Instance()->getTextureSize("bg");
	setWidth(size.x);
	setHeight(size.y);
	//getTransform()->position = glm::vec2(800.0f, 300.0f);
}

Background::~Background()
= default;

void Background::draw()
{
	TextureManager::Instance()->draw("bg", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
}

void Background::update()
{

}

void Background::clean()
{

}