#pragma once
#include <vector>
#include <Renderer2D.h>
#include <Vector2.h>
#include <Matrix3.h>

class SceneObject
{
public:
	SceneObject();
	virtual ~SceneObject();

	SceneObject* getParent() const { return m_parent; }

	size_t childCount() const { return m_children.size(); }
	SceneObject* getChild(unsigned int index) const { return m_children[index]; }

	virtual void onUpdate(float deltaTime);
	virtual void onDraw(aie::Renderer2D* renderer);

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

	void addChild(SceneObject* child);
	void removeChild(SceneObject* child);

	Matrix3& getLocalTransform();
	Matrix3& getGlobalTransform();
	Vector2& getForces();

	void updateTransform();

	void setPosition(float x, float y);
	void setRotate(float radians);
	void setScale(float width, float height);

	void translate(float x, float y);
	void rotate(float radians);
	void scale(float width, float height);
	
	void addForce(float x, float y);
	void reduceForce();


protected:

	SceneObject * m_parent = nullptr;
	std::vector<SceneObject*> m_children;

	Matrix3 m_localTransform;
	Matrix3 m_globalTransform;

	Vector2 m_forces = { 0,0 };
};

