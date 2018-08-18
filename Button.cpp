#include "Button.h"

Button::Button()
{
	m_animTime = 0.1;
}
Button::Button(std::string imageName) : ToggleButton(imageName)
{
	m_animTime = 0.1;
}
void Button::updateState()
{
	if(m_state == true && m_animClock.getElapsedTime().asSeconds() >= m_animTime)
	{
		m_animClock.restart();
		disable();
	}
}
void Button::toggle()
{
	if (m_lock==false && m_state==false && m_animClock.getElapsedTime().asSeconds() > m_animTime)
	{
		m_animClock.restart();
		throwEvent("PRESSED");
		enable();
	}
}