#pragma once

#include "IBehaviour.h"
#include "State.h"

class StateMachine : public IBehaviour
{
public:
	StateMachine();

	virtual void update(GameObject* gameObject, float deltaTime);
	
	// Allows system to change between multiple states
	void ChangeState(GameObject* gameObject, State* newState);
	// Gets the current state the object is in
	State* GetCurrentState();
	// Gets the state before the current state
	State* GetPrevState();

	~StateMachine();

private:
	State * currentState;
	State * prevState;
};

