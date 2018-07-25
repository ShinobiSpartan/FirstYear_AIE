#pragma once

#include "State.h"


class Pursue_State : public State
{
public:
	Pursue_State();
	Pursue_State(GameObject* target);
	virtual void update(GameObject* gameObject, StateMachine* sm, float deltaTime);
	virtual void initiate(GameObject* gameObject);
	virtual void exit(GameObject* gameObject);
	~Pursue_State();

private:
	GameObject * target;
};

