#include "Wander_State.h"
#include <glm\ext.hpp>
#include <random>
#include <time.h>
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

	randomVec = Vector2(rand() % (int)m_wanderJitter, rand() % (int)m_wanderJitter);
	m_target = target;
}

void Wander_State::update(GameObject * gameObject, StateMachine * sm, float deltaTime)
{
	glm::vec2 circle = glm::circularRand(m_wanderRadius);
	Vector2 newTarget = Vector2(randomVec.m_x + circle.x, randomVec.m_y + circle.y);
	newTarget.normalise();
	Vector2 normalisedTarget = newTarget;
	Vector2 targetOnSphere = normalisedTarget * m_wanderRadius;
	targetOnSphere.normalise();
	Vector2 force = targetOnSphere;
	force = force * 50.0f;

	gameObject->AddForce(force);

	Vector2 dist = m_target->GetPosition() - gameObject->GetPosition();
	float mag = dist.magnitude();
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
