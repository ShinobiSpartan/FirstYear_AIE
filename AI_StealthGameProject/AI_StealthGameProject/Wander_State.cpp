#include "Wander_State.h"
#include <glm\ext.hpp>
#include "StateMachine.h"
#include "Pursue_State.h"

Wander_State::Wander_State()
{
}

Wander_State::Wander_State(GameObject * target, float wanderDist, float wanderRadius, float wanderJitter)
{
	m_wanderDist = wanderDist;
	m_wanderRadius = wanderRadius;
	m_wanderJitter = wanderJitter;

	m_target = target;
	
	// Creates a random vector from exisiting variables
	randomVec = Vector2(rand() % (int)m_wanderJitter, rand() % (int)m_wanderJitter);
}

void Wander_State::update(GameObject * gameObject, StateMachine * sm, float deltaTime)
{
	// Generates a circle around the game object
	glm::vec2 circle = glm::circularRand(m_wanderRadius);

	// Calculate a random position by using the randomVec
	Vector2 newTarget = Vector2(randomVec.m_x + circle.x, randomVec.m_y + circle.y);

	// Normalise the new target value
	newTarget.normalise();
	Vector2 normalisedTarget = newTarget;

	// Calculate a position on the circle
	Vector2 targetOnCircle = normalisedTarget * m_wanderRadius;

	// Normalise the new position
	targetOnCircle.normalise();

	// Create a force towards the target
	Vector2 force = targetOnCircle;
	force = force * 50.0f;

	// Add the force to the game object
	gameObject->AddForce(force);

	// ------------------------------------------------------------------------------- //

	// Calculate the distance between the agent and target
	Vector2 dist = m_target->GetPosition() - gameObject->GetPosition();
	// Get the magnitude of the distance
	float mag = dist.magnitude();
	// If the magnitude gets below a certain point, change the agent's state to pursue the target
	if (mag < 100.0f)
		sm->ChangeState(gameObject, new Pursue_State(m_target));

}

void Wander_State::initiate(GameObject * gameObject)
{
}

void Wander_State::exit(GameObject * gameObject)
{
}


Wander_State::~Wander_State()
{
}
