#pragma once
#include "GameObject.h"
class IBehaviour
{
public:
	virtual void update(GameObject* gameObject, float deltaTime) = 0;
};
