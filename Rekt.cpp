#include "Rekt.h"
int Rekt::maxID;
Rekt::Rekt()
{
	ID = getID();
	m_compensation = 3;

	shape.setOutlineColor(sf::Color::Red);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(m_compensation);
	m_isDrawable = true;
	m_data.id =ID;
	m_data.type = "annotation";
	m_data.value = "None";
	m_data.location_id = "L_"+ID;

	m_location.type = "annotation";
	m_location.id = m_data.location_id;

}
void Rekt::boxToLocation()
{
	m_location.polygon[0][0] = box.getPosition().x;
	m_location.polygon[0][1] = box.getPosition().y;

	m_location.polygon[1][0] = box.getPosition().x + box.getSize().x;
	m_location.polygon[1][1] = box.getPosition().y;

	m_location.polygon[2][0] = box.getPosition().x + box.getSize().x;
	m_location.polygon[2][1] = box.getPosition().y + box.getSize().y;

	m_location.polygon[3][0] = box.getPosition().x;
	m_location.polygon[3][1] = box.getPosition().y + box.getSize().y;
}
Rekt::Rekt(Data d, Location l)
{
	m_compensation = 3;
	m_isDrawable = true;
	shape.setOutlineColor(sf::Color::Red);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(m_compensation);
	sf::Vector2f pos = sf::Vector2f(l.polygon[0][0], l.polygon[0][1]);
	sf::Vector2f size = sf::Vector2f(l.polygon[1][0] - l.polygon[0][0], l.polygon[3][1] -l.polygon[0][1]);
	shape.setPosition(pos);
	shape.setSize(size);
	pos = sf::Vector2f(l.polygon[0][0] - m_compensation, l.polygon[0][1] - m_compensation);
	size = sf::Vector2f(l.polygon[1][0] - l.polygon[0][0] + m_compensation * 2, l.polygon[3][1] - l.polygon[0][1] + m_compensation*2);
	box.setSize(size);
	box.setPosition(pos);
	ID = d.id;
	m_data = d;
	m_location = l;
}
std::string Rekt::getId()
{
	return ID;
}
void Rekt::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (m_isDrawable)
	{
		target.draw(shape, states);
	}
}

void Rekt::setMaxID(int i )
{
	maxID = i;
}

std::string Rekt::getID()
 {
	 return std::to_string(maxID++);
 }

 	void Rekt::setPosition(sf::Vector2f position)
	 {
		 shape.setPosition(position);
		 box.setPosition(position);
		 boxToLocation();
		 box.setPosition(sf::Vector2f(position.x - m_compensation, position.y - m_compensation));
	 }
	void Rekt::setSize(sf::Vector2f size)
	{
		shape.setSize(size);
		box.setSize(size);
		boxToLocation();
		box.setSize(sf::Vector2f(size.x + m_compensation*2, size.y + m_compensation * 2));
	}
