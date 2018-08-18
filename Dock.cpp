#include "Dock.h"
Dock *Dock::actualDock;


Dock::Dock(sf::Vector2f windowSize) : write("pencil"), erase("eraser"), previous("left-arrow"), next("right-arrow")
{
	actualDock = this;
	nb_button = 4;
	setDimension(windowSize);
	back.setTexture((Ressources::getTexture("dock")));
	setPosition(sf::Vector2f(0,0));
	write.setSize(getButtonSize());
	erase.setSize(getButtonSize());
	previous.setSize(getButtonSize());
	next.setSize(getButtonSize());
	setWrite();
	actualTool.setTexture(Ressources::getTexture("pencil"));
	actualTool.setSize(getButtonSize());
	actualTool.setPosition(10,getButtonPosition(0).y);

	setDimension(windowSize);
	anim_time = 0.1;
	m_isUp = true;
	wSize = windowSize;
	makeAppearBox.setPosition(sf::Vector2f(0,0));
	makeAppearBox.setSize(sf::Vector2f(windowSize.x,back.getSize().y+back.getSize().y*0.1));
	erase.addEvent("PRESSED",disableAll);
	write.addEvent("PRESSED",disableAll);
	erase.addEvent("PRESSED",setEraseEvent);
	write.addEvent("PRESSED",setWriteEvent);
	previous.addEvent("PRESSED",Ressources::decIndex);
	next.addEvent("PRESSED", Ressources::incIndex);

	disableAll(&write);
	write.enable();
	actualPageName.setFont(Ressources::font);
	actualPageName.setPosition(actualTool.getSize().x+15,actualTool.getPosition().y);
	actualPageName.setScale(sf::Vector2f(0.3,0.3));
	actualPageName.setColor(sf::Color::Black);

	actualPageIndex.setFont(Ressources::font);
	actualPageIndex.setPosition(actualTool.getSize().x + 15, actualTool.getPosition().y+10);
	actualPageIndex.setScale(sf::Vector2f(0.3, 0.3));
	actualPageIndex.setColor(sf::Color::Black);
}
sf::Vector2f Dock::getButtonPosition(int n)
{
	sf::Vector2f out;
	out.x = n * (back.getSize().x / nb_button) + (back.getSize().x / nb_button / 3) + back.getPosition().x;
	out.y = (back.getSize().y/10) + back.getPosition().y;
	return out;
}
sf::Vector2f Dock::getButtonSize()
{
	sf::Vector2f out;
	out.x = (back.getSize().x / nb_button / 3);
	out.y = 8*(back.getSize().y / 10);
	return out;
}
bool Dock::updateDock(Mouse m)
{
	bool isPressed = false;
	if(makeAppearBox.pointCollision(m.position)==true and m_isUp == false)
	{
		animClock.restart();
		m_isUp=true;
	}
	else if (m_isUp == true and makeAppearBox.pointCollision(m.position) == false)
	{
		animClock.restart();
		m_isUp=false;
	}
	isPressed = isPressed || write.updateFunction(m);
	isPressed = isPressed || erase.updateFunction(m);
	isPressed = isPressed || previous.updateFunction(m);
	isPressed = isPressed || next.updateFunction(m);
	return isPressed;
}
void Dock::updateState()
{
	actualPageName.setString(Ressources::actualPageName);
	actualPageIndex.setString(std::to_string(Ressources::actualPageIndex));
	previous.updateState();
	next.updateState();
	if (m_isUp == true)
		setPosition(getAnimUPosition(animClock.getElapsedTime().asSeconds()));
	else
		setPosition(getAnimDPosition(animClock.getElapsedTime().asSeconds()));
}
void Dock::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (m_isDrawable)
	{
		target.draw(back, states);
		target.draw(write, states);
		target.draw(erase, states);
		target.draw(previous, states);
		target.draw(next, states);
		target.draw(actualTool, states);
		target.draw(actualPageName,states);
		target.draw(actualPageIndex, states);
	}
}
void Dock::setDimension(sf::Vector2f windowSize)
{
	back.setPosition(Ressources::dock_dimensions[0] * windowSize.x,
					 0);
	back.setSize(sf::Vector2f(
		Ressources::dock_dimensions[1] * windowSize.x,
		Ressources::dock_dimensions[2] * windowSize.y));
}
sf::Vector2f Dock::getAnimUPosition(float time)
{
	if(time>=anim_time)
	{
		return sf::Vector2f(Ressources::dock_dimensions[0] * wSize.x, -1);
	}
	else
	{
		return sf::Vector2f(Ressources::dock_dimensions[0] * wSize.x, (back.getSize().y*-1) + (back.getSize().y / anim_time) * time -1);
	}
}
sf::Vector2f Dock::getAnimDPosition(float time)
{
	if (time >= anim_time)
	{
		return sf::Vector2f(Ressources::dock_dimensions[0] * wSize.x, back.getSize().y * -1);
	}
	else
	{
		return sf::Vector2f(Ressources::dock_dimensions[0] * wSize.x,  - (back.getSize().y / anim_time * time) - 1);
	}
}
void Dock::setPosition(sf::Vector2f position)
{

	back.setPosition(position);
	write.setPosition(getButtonPosition(0));
	erase.setPosition(getButtonPosition(1));
	previous.setPosition(getButtonPosition(2));
	next.setPosition(getButtonPosition(3));
}
void Dock::setSize(sf::Vector2f position)
{
}

void Dock::disableAll(EventHandler *sender)
{
	actualDock->write.disable();
	actualDock->erase.disable();

	((ToggleButton*)sender)->toggle();
}
void Dock::setEraseEvent(EventHandler *sender)
{
	setErase();
}
void Dock::setWriteEvent(EventHandler *sender)
{
	setWrite();
}
void Dock::setErase()
{
	actualDock->actualTool.setTexture(Ressources::getTexture("eraser"));
	MouseManager::setRemove(actualDock);
}
void Dock::setWrite()
{
	actualDock->actualTool.setTexture(Ressources::getTexture("pencil"));
	MouseManager::setAdd(actualDock);
}
