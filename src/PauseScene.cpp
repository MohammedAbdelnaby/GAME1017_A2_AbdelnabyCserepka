#include "PauseScene.h"

PauseScene::PauseScene()
{
	TextureManager::Instance()->load("../Assets/textures/PauseSceneBackground.png", "PauseMenu");
	auto size = TextureManager::Instance()->getTextureSize("PauseMenu");
	setWidth(size.x);
	setHeight(size.y);
	getTransform()->position = glm::vec2(400.0f, 300.0f);
	m_pResume = new Button("../Assets/textures/resumeButton.png", "resumeButton", RESUME_BUTTON);
	m_pResume->getTransform()->position = glm::vec2(400.0f, 300.0f);
	m_pResume->addEventListener(CLICK, [&]()-> void
		{
			setIsPaused(false);
		});
}

PauseScene::~PauseScene() = default;

void PauseScene::draw()
{
	if (m_isPaused)
	{
		TextureManager::Instance()->draw("PauseMenu", getTransform()->position.x, getTransform()->position.y, 0, 255, true);
		m_pResume->draw();
	}
}

void PauseScene::update()
{
	if (m_isPaused)
	{
		m_pResume->update();
	}
}

void PauseScene::clean()
{
}

void PauseScene::setIsPaused(bool x)
{
	m_isPaused = x;
}

bool PauseScene::getIsPaused()
{
	return m_isPaused;
}
