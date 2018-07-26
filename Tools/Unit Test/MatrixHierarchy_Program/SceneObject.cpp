#include "SceneObject.h"
#include <assert.h>


SceneObject::SceneObject()
{
}


SceneObject::~SceneObject()
{
	// detatch from parent
	if (m_parent != nullptr)
		m_parent->removeChild(this);

	// remove all children
	for (auto child : m_children)
		child->m_parent = nullptr;
}

void SceneObject::onUpdate(float deltaTime)
{
	if (m_localTransform.m_wAxis.m_x < 0)
		m_localTransform.m_wAxis.m_x = 1280;
	else if (m_localTransform.m_wAxis.m_x > 1280)
		m_localTransform.m_wAxis.m_x = 0;

	if (m_localTransform.m_wAxis.m_y < 0)
		m_localTransform.m_wAxis.m_y = 720;
	else if (m_localTransform.m_wAxis.m_y > 720)
		m_localTransform.m_wAxis.m_y = 0;
}

void SceneObject::onDraw(aie::Renderer2D * renderer)
{
}

void SceneObject::update(float deltaTime)
{
	// run onUpdate behaviour
	onUpdate(deltaTime);

	// update children
	for (auto child : m_children)
		child->update(deltaTime);
}

void SceneObject::draw(aie::Renderer2D * renderer)
{
	// run onDraw behaviour
	onDraw(renderer);

	// draw children
	for (auto child : m_children)
		child->draw(renderer);
}

void SceneObject::addChild(SceneObject * child)
{
	// make sure it doesn't have a parent already
	assert(child->m_parent == nullptr);
	// assign "this" as parent
	child->m_parent = this;
	// add nw child to collection
	m_children.push_back(child);
}

void SceneObject::removeChild(SceneObject * child)
{
	// find the child in the collection
	auto iter = std::find(m_children.begin(), m_children.end(), child);

	// if found, remove it
	if (iter != m_children.end())
	{
		m_children.erase(iter);
		// also unassign the parent
		child->m_parent = nullptr;
	}
}

Matrix3 & SceneObject::getLocalTransform()
{
	return m_localTransform;
}

 Matrix3 & SceneObject::getGlobalTransform()
{
	return m_globalTransform;
}

 Vector2 & SceneObject::getForces()
 {
	 return m_forces;
 }

void SceneObject::updateTransform()
{
	if (m_parent != nullptr)
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	else
		m_globalTransform = m_localTransform;

	for (auto child : m_children)
		child->updateTransform();
}

void SceneObject::setPosition(float x, float y)
{
	m_localTransform[2] = { x, y, 0 };
	updateTransform();
}

void SceneObject::setRotate(float radians)
{
	m_localTransform.rotateZ(radians);
	updateTransform();
}

void SceneObject::setScale(float width, float height)
{
	m_localTransform.setScaled(width, height, 0);
	updateTransform();
}

void SceneObject::translate(float x, float y)
{
	m_localTransform.translate(x, y, 0);
	updateTransform();
}

void SceneObject::rotate(float radians)
{
	m_localTransform.rotateZ(radians);
	updateTransform();
}

void SceneObject::scale(float width, float height)
{
	m_localTransform.scale(width, height, 0);
	updateTransform();
}

void SceneObject::addForce(float x, float y)
{
	m_forces.m_x += x;
	m_forces.m_y += y;
}

void SceneObject::reduceForce()
{
	m_forces.m_x *= 0.95f;
	m_forces.m_y *= 0.95f;
}
