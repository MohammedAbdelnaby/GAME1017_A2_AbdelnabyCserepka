#include "ExtraScroll.h"

ExtraScroll::ExtraScroll()
{
	TextureManager::Instance()->load("../Assets/textures/Close_Trees.png", "cg");
	auto size = TextureManager::Instance()->getTextureSize("cg");
	setWidth(size.x);
	setHeight(size.y);
	//getTransform()->position = glm::vec2(800.0f, 300.0f);
}

ExtraScroll::~ExtraScroll()
= default;

void ExtraScroll::draw()
{
	TextureManager::Instance()->draw("cg", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
}

void ExtraScroll::update()
{

}

void ExtraScroll::clean()
{

}