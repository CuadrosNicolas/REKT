#ifndef ENTITY
#define ENTITY
#include "HitBox.h"
#include "EventHandler.h"
#include <SFML/Graphics.hpp>


class Entity : public  sf::Drawable, public EventHandler
{
	public:
		Entity();
		virtual ~Entity();
		void setTexture(sf::Texture* tex);
		void setDrawable();
		void setNotDrawable();
		virtual void setPosition(sf::Vector2f position);
		virtual void setSize(sf::Vector2f position);
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		virtual HitBox* getBox();
	  protected:
		bool m_isDrawable;
		EventHandler handler;
		HitBox box;

};

#endif