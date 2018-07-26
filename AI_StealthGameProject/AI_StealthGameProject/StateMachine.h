#pragma once

#include "IBehaviour.h"
#include "State.h"

class StateMachine : public IBehaviour
{
public:
	StateMachine();

	virtual void update(GameObject* gameObject, float deltaTime);
	
	void ChangeState(GameObject* gameObject, State* newState);
	State* GetCurrentState();
	State* GetPrevState();

	~StateMachine();

private:
	State * currentState;
	State * prevState;
};

