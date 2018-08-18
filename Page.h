#ifndef PAGE
#define PAGE
#include "Entity.h"
#include "JPage.h"
#include "headers/JSONParser.h"
#include "Rekt.h"
#include <vector>
#include <fstream>
class Page : public Entity
{
	public:
	  Page();
	  Page(sf::Texture *pageName,sf::Image im,std::string name);
	  void loadPage(std::string jsonFile);
	  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	  std::vector<Rekt*>& getRekt();
	  Rekt* addRekt();
	  void remove(std::string id);
	  void save();
	  void screenShot();

	protected :
	std::string m_name;
	std::string m_jsonFile;
	  int maxID;
	  sf::RectangleShape pageShape;
	  sf::Image innerImage;
	  JPage *pageDatas;
	  std::vector<Rekt *> rekts;
};




#endif