#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "PlayerAnimationState.h"
#include "Sprite.h"

class Player final : public Sprite
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	void UpdateGravity();
	virtual void clean() override;
	void move();
	// setters
	void setAnimationState(PlayerAnimationState new_state);
	void setCurrentDirection(glm::vec2 newDirection);
	glm::vec2 getCurrentDirection();
	void setisGorunded(bool grounded);
	bool getisGrounded();
	void PlayerJump();
	float getAngel();
	void setAngle(float x);
private:
	void m_buildAnimations();

	PlayerAnimationState m_currentAnimationState;

	float m_currentAngle;
	glm::vec2 m_currentDirection;
	float m_drag;
	bool m_isMoving;
	bool m_direction;
	float m_maxSpeed;
	bool isGrounded = true;
	float force = -100.0f;
	float gravity = 12.0f;
};

#endif /* defined (__PLAYER__) */