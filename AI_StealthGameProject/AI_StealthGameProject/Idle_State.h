#pragma once

#include "State.h"

class Idle_State : public State
{
public:
	Idle_State();

	///
	// Nothing is changed in this state
	///

	virtual void update(GameObject* gameObject, StateMachine* sm, float deltaTime);
	virtual void initiate(GameObject* gameObject);
	virtual void exit(GameObject* gameObject);

	~Idle_State();
};

