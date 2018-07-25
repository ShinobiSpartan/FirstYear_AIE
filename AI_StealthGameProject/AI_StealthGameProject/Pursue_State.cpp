#include "Pursue_State.h"
#include "StateMachine.h"
#include "Wander_State.h"


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

	Vector2 dist = target->GetPosition() - gameObject->GetPosition();
	float magFromTarget = dist.magnitude();
	if (magFromTarget > 250.0f)
		sm->ChangeState(gameObject, new Wander_State(target, 0.0f, 5.0f, 2.0f));
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
