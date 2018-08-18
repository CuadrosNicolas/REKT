#ifndef TOGGLEBUTTON
#define TOGGLEBUTTON
#include "Entity.h"
#include "Ressources.h"
#include "Mouse.h"
class ToggleButton : public Entity
{
	public:
	  ToggleButton();
	  ToggleButton(std::string imageName);
	  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	  bool updateFunction(Mouse m);
	  virtual void updateState();

	  virtual void toggle();
	  void enable();
	  void disable();
	  void lock();
	  void unlock();

	  virtual void setPosition(sf::Vector2f position)
	  {
		  m_background.setPosition(position);
		  m_icon.setPosition(position);
		  box.setPosition(position);
	  }
	  virtual void setSize(sf::Vector2f size)
	  {
		  m_background.setSize(size);
		  m_icon.setSize(size);
		  box.setSize(size);
	  }

	protected:
		bool m_state;
		bool m_lock;
		float m_animTime;
		sf::Clock m_animClock;
		sf::RectangleShape m_icon;
		sf::RectangleShape m_background;
};

#endif