#ifndef DOCK
#define DOCK
#include "Entity.h"
#include "ToggleButton.h"
#include "Button.h"
#include "Mouse.h"
class Dock : public Entity
{
	public:
		Dock(sf::Vector2f windowSize);
		void setDimension(sf::Vector2f windowSize) ;
		sf::Vector2f getButtonPosition(int n);
		sf::Vector2f getButtonSize();
		virtual void setPosition(sf::Vector2f position);
		virtual void setSize(sf::Vector2f position);
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		bool updateDock(Mouse m);
		void updateState();
		static void setEraseEvent(EventHandler* sender);
		static void setWriteEvent(EventHandler *sender);
		static void setErase();
		static void setWrite();

		sf::Vector2f getAnimUPosition(float time);
		sf::Vector2f getAnimDPosition(float time);
		static void disableAll(EventHandler* sender);
		static bool isWrite();
	  private:
	  	int nb_button;
		  int mode;
	  	sf::RectangleShape back;

		sf::RectangleShape actualTool;

		sf::Text actualPageName;
		sf::Text actualPageIndex;


		ToggleButton write;
		ToggleButton erase;
		Button previous;
		Button next;
		HitBox makeAppearBox;
		sf::Clock animClock;
		float anim_time;
		bool m_isUp;
		sf::Vector2f wSize;

		static Dock* actualDock;
};


#endif