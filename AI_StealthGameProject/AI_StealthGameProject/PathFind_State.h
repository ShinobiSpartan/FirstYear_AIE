#pragma once
#include "State.h"
#include <list>

class Node;

class PathFind_State : public State
{
public:
	PathFind_State();
	PathFind_State(std::list<Node*> target);
	virtual void update(GameObject* gameObject, StateMachine* sm, float deltaTime);
	virtual void initiate(GameObject* gameObject);
	virtual void exit(GameObject* gameObject);

	~PathFind_State();

private:
	std::list<Node*>	target;
};

