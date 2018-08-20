#ifndef REKT
#define REKT
#include "Entity.h"
#include "JLocation.h"
#include "JData.h"
class Rekt : public Entity
{
  public:
		Rekt(Data d,Location l);
		Rekt();
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		Data toData();
		Location toLocation();
		void setPosition(sf::Vector2f position);
		void setSize(sf::Vector2f size);
		sf::Vector2f getSize()
		{
			return shape.getSize();
		}
		sf::Vector2f getPosition()
		{
			return shape.getPosition();
		}
		static void setMaxID(int i);
		static std::string getID();
		std::string getId();
		std::string getLocationId();

			Data m_data;
		Location m_location;

  protected:
		void boxToLocation();
		std::string ID;
		enum state{
			ADDED,
			BEING_ADDED
		};
		sf::RectangleShape shape;
		int  m_compensation;
		static int maxID;
};

#endif