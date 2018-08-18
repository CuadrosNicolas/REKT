#include "HitBox.h"

HitBox::HitBox()
{
	m_center = sf::Vector2f(0,0);
}
HitBox::HitBox(sf::Vector2f position, sf::Vector2f size)
{
	m_position = position;
	m_fixPosition = position;
	m_size = size;
	m_center = sf::Vector2f(0, 0);
}

bool HitBox::pointCollision(sf::Vector2f point)
{
	sf::Vector2f centered = m_position-(sf::Vector2f(m_size.x*m_center.x,m_size.y*m_center.y));
	if (point.x >= centered.x && point.x <= centered.x + m_size.x &&
		point.y >= centered.y && point.y <= centered.y + m_size.y)
		return true;
	else
		return false;
}

void HitBox::setPosition(sf::Vector2f position)
{
	m_position = position;
	m_fixPosition = position;
}
void HitBox::setSize(sf::Vector2f size)
{
	if(size.x <0)
	{
		m_position.x = m_fixPosition.x+size.x;
		size.x*=-1;
	}
	if(size.y<0)
	{
		m_position.y = m_fixPosition.y+size.y;
		size.y*=-1;
	}
	m_size = size;
}
sf::Vector2f HitBox::getPosition()
{
	return m_position;
}
sf::Vector2f HitBox::getSize()
{
	return m_size;
}
void HitBox::setCenter(sf::Vector2f center)
{
	m_center = center;
}