#include "test.h"

test::test() : m_sprite()  , m_texture()
{
	m_texture.loadFromFile("Ressources/textures/PNG/dock.png");
	m_sprite.setTexture(m_texture);
}

void test::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_sprite,states);
}