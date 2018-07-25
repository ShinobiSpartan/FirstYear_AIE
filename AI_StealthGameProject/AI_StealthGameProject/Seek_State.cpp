#include "Seek_State.h"
#include "StateMachine.h"


Seek_State::Seek_State()
{
	target = nullptr;
}

Seek_State::Seek_State(GameObject * target)
{
	this->target = target;
}

void Seek_State::update(GameObject * gameObject, StateMachine * sm, float deltaTime)
{
	Vector2 desiredVel = target->GetPosition() - gameObject->GetPosition();
	float mag = desiredVel.magnitude();
	desiredVel.normalise();
	desiredVel = desiredVel * 100;
	Vector2 force = desiredVel - gameObject->GetVelocity();
	gameObject->AddForce(force);
}

void Seek_State::initiate(GameObject * gameObject)
{
}

void Seek_State::exit(GameObject * gameObject)
{
}


Seek_State::~Seek_State()
{
	delete target;
}
