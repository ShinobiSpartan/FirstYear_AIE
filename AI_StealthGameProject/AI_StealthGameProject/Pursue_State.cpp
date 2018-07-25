#include "Pursue_State.h"
#include "StateMachine.h"


Pursue_State::Pursue_State()
{
	target = nullptr;
}

Pursue_State::Pursue_State(GameObject * target)
{
	this->target = target;
}

void Pursue_State::update(GameObject * gameObject, StateMachine * sm, float deltaTime)
{
	Vector2 desiredVel = target->GetPosition() + target->GetVelocity() - gameObject->GetPosition();
	float mag = desiredVel.magnitude();
	desiredVel.normalise();
	desiredVel = desiredVel * 100;
	Vector2 force = desiredVel - gameObject->GetVelocity();
	gameObject->AddForce(force);
}

void Pursue_State::initiate(GameObject * gameObject)
{
}

void Pursue_State::exit(GameObject * gameObject)
{
}


Pursue_State::~Pursue_State()
{
	delete target;
}
