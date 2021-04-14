#include "MidGround.h"

MidGround::MidGround()
{
	TextureManager::Instance()->load("../Assets/textures/Small_Trees.png", "mg");
	auto size = TextureManager::Instance()->getTextureSize("mg");
	setWidth(size.x);
	setHeight(size.y);
	//getTransform()->position = glm::vec2(800.0f, 300.0f);
}

MidGround::~MidGround()
= default;

void MidGround::draw()
{
	TextureManager::Instance()->draw("mg", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
}

void MidGround::update()
{

}

void MidGround::clean()
{

}