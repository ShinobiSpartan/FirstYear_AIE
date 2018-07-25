#pragma once

#include "IBehaviour.h"
#include "State.h"

class StateMachine : public IBehaviour
{
public:
	StateMachine();
	~StateMachine();

	virtual void update(GameObject* gameObject, float deltaTime);
	
	void ChangeState(GameObject* gameObject, State* newState);
	State* GetCurrentState();
	State* GetPrevState();
private:
	State * currentState;
	State * prevState;
};

