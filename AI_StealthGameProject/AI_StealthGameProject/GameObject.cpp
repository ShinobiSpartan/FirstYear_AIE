#include "GameObject.h"
#include <Renderer2D.h>
#include <Texture.h>
#include "IBehaviour.h"

GameObject::GameObject()
{
	texture = nullptr;
	position = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
}

GameObject::GameObject(aie::Texture * texture, Vector2 position)
{
	this->texture = texture;
	this->position = position;
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);
}


GameObject::~GameObject()
{
	delete texture;
}

void GameObject::update(float deltaTime)
{
	AddForce(velocity * -0.15f);
	velocity = velocity + acceleration * deltaTime;
	position = position + velocity * deltaTime;
	acceleration = Vector2(0, 0);
	m_behaviours->update(this, deltaTime);
}

void GameObject::draw(aie::Renderer2D * renderer)
{
	renderer->drawSprite(texture, position.m_x, position.m_y);
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
