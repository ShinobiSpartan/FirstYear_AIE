#pragma once
#include "GameObject.h"

class StateMachine;

class State
{
public:
	virtual void update(GameObject* gameObject, StateMachine* sm, float deltaTime) = 0;
	virtual void initiate(GameObject* gameObject) = 0;
	virtual void exit(GameObject* gameObject) = 0;
};
