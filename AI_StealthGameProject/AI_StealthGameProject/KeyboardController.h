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
	~KeyboardController();
	
	virtual void update(GameObject* gameObject, float deltaTime);

private:
	aie::Input* input;
};

