#ifndef RESSOURCES
#define RESSOURCES
#include <SFML/Graphics.hpp>
#include <map>
#include "configFile.h"
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "Page.h"
class Ressources
{
	public:
		static void loadRessources();
		static sf::Texture* getTexture(std::string name);
		static sf::Texture *getPage(std::string name);
		static sf::Color button_pressed;
		static sf::Color button;
		static sf::Color background;
		static sf::Color rectangle;

		static std::string textures_path;
		static std::string icons_path;
		static std::string datas;

		static sf::Font font;
		static std::vector<float> dock_dimensions;

		static std::vector<std::string> listDir(std::string folder);
		static std::vector<std::string> listDir(const char *folder);
		static Page *updateActualPage();
		static void incIndex(EventHandler* sender);
		static void decIndex(EventHandler* sender);
		static Page *actualPage;
		static unsigned int actualPageIndex;
		static std::string actualPageName;

	  private:
		Ressources();
		static std::map<std::string, sf::Texture*> m_textures;
		static std::vector<std::string> m_DatasNames;
		static std::vector<std::string> m_Texfiles;
};

#endif