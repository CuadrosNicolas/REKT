#include "Entity.h"

Entity::Entity()
{
	m_isDrawable = true;
}
void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(m_isDrawable)
	{
		target.draw(*this, states);
	}
}

void Entity::setDrawable()
{
	m_isDrawable = true;
}
void Entity::setNotDrawable()
{
	m_isDrawable = false;
}

Entity::~Entity()
{

}
void Entity::setPosition(sf::Vector2f position)
{

}
void Entity::setSize(sf::Vector2f position)
{

}
HitBox* Entity::getBox()
{
	return &box;
}