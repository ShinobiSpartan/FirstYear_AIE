#include "StateMachine.h"



StateMachine::StateMachine()
{
	currentState = nullptr;
	prevState = nullptr;
}

void StateMachine::update(GameObject * gameObject, float deltaTime)
{
	// Calls the update function of the current state
	if (currentState != nullptr)
		currentState->update(gameObject, this, deltaTime);
}

void StateMachine::ChangeState(GameObject * gameObject, State * newState)
{
	// If the current state does not equal nullptr
	if (currentState != nullptr)
		// Destroy the objects in the current state with the exit function
		currentState->exit(gameObject);
	// If the new state does not equal nullptr
	if (newState != nullptr)
		// Create the objects of the new state with the initiate function
		newState->initiate(gameObject);

	// Store the current state into prevState
	prevState = currentState;
	// Store the new state into currentState
	currentState = newState;
}

State * StateMachine::GetCurrentState()
{
	return currentState;
}

State * StateMachine::GetPrevState()
{
	return prevState;
}

StateMachine::~StateMachine()
{
	delete currentState;
	delete prevState;
}
