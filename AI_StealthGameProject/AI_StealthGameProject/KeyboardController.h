#pragma once
#include "IBehaviour.h"

namespace aie
{
	class Input;
}

class KeyboardController : public IBehaviour
{
public:
	KeyboardController();
	KeyboardController(aie::Input* input);
	
	virtual void update(GameObject* gameObject, float deltaTime);
	
	~KeyboardController();

private:
	aie::Input* input;
};

