#pragma once

#include "State.h"

class Wander_State : public State
{
public:
	Wander_State();
	Wander_State(GameObject* target, float wanderDist, float wanderRadius, float wanderJitter);
	virtual void update(GameObject* gameObject, StateMachine* sm, float deltaTime);
	virtual void initiate(GameObject* gameObject);
	virtual void exit(GameObject* gameObject);
	~Wander_State();

private:
	float m_wanderDist;
	float m_wanderRadius;
	float m_wanderJitter;
	Vector2 randomVec;
	GameObject * m_target;
};