#ifndef HITBOX
#define HITBOX
#include <SFML/Graphics.hpp>
#include <iostream>
class HitBox
{
	public:
		HitBox();
		HitBox(sf::Vector2f position,sf::Vector2f size);
		void setPosition(sf::Vector2f position);
		void setSize(sf::Vector2f size);
		sf::Vector2f getPosition();
		sf::Vector2f getSize();
		void setCenter(sf::Vector2f center);
		bool pointCollision(sf::Vector2f point);
	private:
		sf::Vector2f m_center;
		sf::Vector2f m_position;
		sf::Vector2f m_fixPosition;
		sf::Vector2f m_size;
};

#endif