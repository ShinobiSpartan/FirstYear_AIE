#include "GameObject.h"
#include <Renderer2D.h>
#include <Texture.h>
#include "IBehaviour.h"

GameObject::GameObject()
{
	// Sets all variables default values
	texture = nullptr;
	position = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
}

GameObject::GameObject(aie::Texture * texture, Vector2 position, Race objectRace)
{
	// Assigns variables to correct functions
	this->texture = texture;
	this->position = position;
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
	m_race = objectRace;
}

void GameObject::update(float deltaTime)
{
	// Physics settings for enemy ai's (aliens)
	if (m_race == Alien)
	{
		if (position.m_x < 0 || position.m_x > 1400 || position.m_y < 0 || position.m_y > 720)
			position = { 1300, 360 };

		AddForce(velocity * -0.15f);
		velocity = velocity + acceleration * deltaTime;
		position = position + velocity * deltaTime;
		acceleration = Vector2(0, 0);
		m_behaviours->update(this, deltaTime);
	}
	// Physics settings for player
	else if (m_race == Player)
	{
		if (position.m_x < 0 || position.m_x > 1400 || position.m_y < 0 || position.m_y > 720)
			position = { 100, 360 };

		AddForce(velocity * -50.0f);
		velocity = velocity + acceleration * deltaTime;
		position = position + velocity * deltaTime;
		acceleration = Vector2(0, 0);
		m_behaviours->update(this, deltaTime);
	}
	// Physics settings for smart AI
	else if (m_race == S_Alien)
	{
		AddForce(velocity * -3.0f);
		velocity = velocity + acceleration * deltaTime;
		position = position + velocity * deltaTime;
		acceleration = Vector2(0, 0);
		m_behaviours->update(this, deltaTime);
	}
}

void GameObject::draw(aie::Renderer2D * renderer)
{
	// Draws all of the sprites
	renderer->drawSprite(texture, position.m_x, position.m_y);
	
	// Adds a coloured detection radius around the dumb ai
	if (m_race == Alien)
	{
		renderer->setRenderColour(1, 0.898f, 0, 0.25f);
		renderer->drawCircle(position.m_x, position.m_y, 100.0f, 1.5f);
		renderer->setRenderColour(1, 1, 1, 1);
	}
}

void GameObject::AddForce(Vector2 force)
{
	acceleration = acceleration + force;
}

void GameObject::AddBehaviour(IBehaviour * behaviour)
{
	m_behaviours = behaviour;
}

Vector2 GameObject::GetVelocity()
{
	return velocity;
}

void GameObject::SetPosition(Vector2 pos)
{
	position = pos;
}

Vector2 GameObject::GetPosition()
{
	return position;
}

GameObject::~GameObject()
{
	delete texture;
}