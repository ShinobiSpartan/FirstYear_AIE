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
	// Calculate the distance between the agent and the position slightly ahead of the target
	Vector2 anticipDist = target->GetPosition() + target->GetVelocity() - gameObject->GetPosition();
	
	// Get the magnitude of the distance
	float mag = anticipDist.magnitude();
	
	// Normalise the value and add speed
	anticipDist.normalise();
	anticipDist = anticipDist * 100;

	// Calculate the force needed to reach the target from the previous value and the current velocity of the game object
	Vector2 force = anticipDist - gameObject->GetVelocity();
	
	// Apply the force to the game object
	gameObject->AddForce(force);

	// ------------------------------------------------------------------------------- //

	// Calculate the distance between the agent and the target
	Vector2 dist = target->GetPosition() - gameObject->GetPosition();
	// Get the magnitude of the distance
	float magFromTarget = dist.magnitude();
	// If the magnitude is too low, set the target's position to the 'spawn'
	if (magFromTarget < 15.0f)
		target->SetPosition(Vector2 (100, 360));
	// If the magnitude is too high, set the agent's state to wander
	if (magFromTarget > 100.0f)
		sm->ChangeState(gameObject, new Wander_State(target, 0.0f, 15.0f, 10.0f));
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
