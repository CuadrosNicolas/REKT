#ifndef MOUSE
#define MOUSE
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Rekt.h"
#include "Page.h"
#include "Ressources.h"
enum MouseState{NOT_PRESSED,PRESSED};
struct Mouse
{
	sf::Vector2f position;
	MouseState status;
};
class MouseManager
{
	friend class Page;
	public:
		static Mouse getState();
		static void setState(sf::Vector2f position, MouseState status);
		static void setLink(Rekt* r);
		static void unlink();
		static bool isLink();
		static void updatePage(Page* p);
		static void setAdd(EventHandler* e);
		static void setRemove(EventHandler* e);

	  private:
	  	enum mode{
			ADD,
			REMOVE,
		  };
		static sf::Vector2f previousPos;
		static mode actualMode;
		static Mouse M;
		static Rekt* linkRekt;
};
#endif