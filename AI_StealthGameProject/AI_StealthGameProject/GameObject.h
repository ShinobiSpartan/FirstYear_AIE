#pragma once

#include <Vector2.h>
#include <vector>

namespace aie
{
	class Renderer2D;
	class Texture;
}

enum Race
{
	Player,
	Alien,
	S_Alien
};

class IBehaviour;

class GameObject
{
public:
	GameObject();
	GameObject(aie::Texture* texture, Vector2 position, Race objectRace);

	// Update function for this object
	void update(float deltaTime);
	// Draw function for the object
	void draw(aie::Renderer2D* renderer);

	// Add forces
	void AddForce(Vector2 force);
	
	// Add behaviours
	void AddBehaviour(IBehaviour* behaviour);
	
	// Get Velocity of object
	Vector2 GetVelocity();
	
	// Sets the position of the object as a Vector2
	void SetPosition(Vector2 pos);
	// Gets the position of the current object
	Vector2 GetPosition();

	~GameObject();

	
	Vector2			position;

protected:
	aie::Texture*	texture;
	IBehaviour*		m_behaviours;
	Vector2			acceleration;
	Vector2			velocity;
	Race			m_race;
};
