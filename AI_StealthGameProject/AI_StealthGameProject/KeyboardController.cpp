#include "KeyboardController.h"
#include <Input.h>



KeyboardController::KeyboardController()
{
}

KeyboardController::KeyboardController(aie::Input * input)
{
	this->input = input;
}

void KeyboardController::update(GameObject * gameObject, float deltaTime)
{
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		gameObject->AddForce(Vector2(0, speed));

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		gameObject->AddForce(Vector2(0, -speed));

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		gameObject->AddForce(Vector2(-speed, 0));

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		gameObject->AddForce(Vector2(speed, 0));
}

KeyboardController::~KeyboardController()
{
}
