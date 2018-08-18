#ifndef TEST
#define TEST

#include <SFML/Graphics.hpp>

class test : public sf::Drawable
{
	public:
		test();
	private:
	  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	  sf::Sprite m_sprite;
	  sf::Texture m_texture;

};

#endif