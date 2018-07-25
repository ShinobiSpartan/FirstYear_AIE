#pragma once

#include "State.h"

class Seek_State : public State
{
public:
	Seek_State();
	Seek_State(GameObject* target);
	virtual void update(GameObject* gameObject, StateMachine* sm, float deltaTime);
	virtual void initiate(GameObject* gameObject);
	virtual void exit(GameObject* gameObject);
	~Seek_State();

private:
	GameObject * target;
};

