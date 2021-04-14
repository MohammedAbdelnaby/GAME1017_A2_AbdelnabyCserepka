#include "Ground.h"

Ground::Ground()
{
	TextureManager::Instance()->load("../Assets/textures/Piso.png", "ground");
	auto size = TextureManager::Instance()->getTextureSize("ground");
	setWidth(size.x);
	setHeight(size.y);
	getTransform()->position = glm::vec2(400.f, 300.0f);
}

Ground::~Ground()
= default;

void Ground::draw()
{
	TextureManager::Instance()->draw("ground", getTransform()->position.x, getTransform()->position.y, 0, 255, false);
}

void Ground::update()
{
}

void Ground::clean()
{
}
