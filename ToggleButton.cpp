#include "ToggleButton.h"

ToggleButton::ToggleButton()
{
	ToggleButton("pencil");
}
ToggleButton::ToggleButton(std::string imageName)
{
	m_icon.setTexture(Ressources::getTexture(imageName));
	m_background = sf::RectangleShape();
	m_background.setTexture(Ressources::getTexture("button_background"));
	m_background.setSize(sf::Vector2f(m_icon.getTexture()->getSize().x, m_icon.getTexture()->getSize().y));
	box.setSize(sf::Vector2f(m_icon.getTexture()->getSize().x, m_icon.getTexture()->getSize().y));
	m_state = true;
	m_lock = false;
	std::string eventList[] = {"PRESSED", "ENABLE", "DISABLE"};
	SetEventList(eventList, 3);
	m_animTime = 0.3;
	disable();
}

void ToggleButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (m_isDrawable)
	{
		target.draw(m_background, states);
		target.draw(m_icon, states);
	}
}

bool ToggleButton::updateFunction(Mouse m)
{
	if (box.pointCollision(m.position) == true && m.status == MouseState::PRESSED)
	{
		toggle();
		return true;
	}
}
void ToggleButton::updateState()
{

}
void ToggleButton::toggle()
{
	if(!m_lock && m_animClock.getElapsedTime().asSeconds()>m_animTime)
	{
		m_animClock.restart();
		throwEvent("PRESSED");
		if(m_state==false)
		{
			enable();
		}
		else
		{
			disable();
		}
	}
}
void ToggleButton::enable()
{
	throwEvent("ENABLE");
	m_background.setTexture(Ressources::getTexture("button_pressed_background"));
	//m_background.setFillColor(Ressources::button_pressed);
	m_state = true;
}
void ToggleButton::disable()
{
	throwEvent("DISABLE");
	m_background.setTexture(Ressources::getTexture("button_background"));
	//m_background.setFillColor(Ressources::button);
	m_state = false;
}
void ToggleButton::lock()
{
	m_lock = true;
}
void ToggleButton::unlock()
{
	m_lock = false;
}