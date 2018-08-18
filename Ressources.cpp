#include "Ressources.h"

using namespace std;

std::map<std::string, sf::Texture *> Ressources::m_textures;
Page *Ressources::actualPage;
std::vector<std::string> Ressources::m_Texfiles;
std::vector<std::string> Ressources::m_DatasNames;

sf::Color Ressources::button_pressed;
sf::Color Ressources::button;
sf::Color Ressources::background;
sf::Color Ressources::rectangle;

std::string Ressources::textures_path;
std::string Ressources::icons_path;
std::string Ressources::datas;

sf::Font Ressources::font;
std::vector<float> Ressources::dock_dimensions;
unsigned int Ressources::actualPageIndex;
std::string Ressources::actualPageName;

void Ressources::loadRessources()
{
	configFile F("Ressources/ressources.ini");
	button_pressed = F.getColorVector("color","button_pressed");
	button = F.getColorVector("color", "button");
	background = F.getColorVector("color", "background");
	rectangle = F.getColorVector("color", "rectangle");

	textures_path = F.get("images","textures_path");
	icons_path = F.get("images","icons_path");
	datas = F.get("images","datas");

	font.loadFromFile(F.get("display","font_path"));
	dock_dimensions = F.getFloatVector("display","dock_dimensions");

	std::vector<string> temp;
	temp = listDir(textures_path);
	for (size_t i = 0; i < temp.size(); i++)
		m_Texfiles.push_back(temp[i]);
	temp = listDir(icons_path);
	for (size_t i = 0; i < temp.size(); i++)
		m_Texfiles.push_back(temp[i]);
	for (size_t i = 0; i < m_Texfiles.size(); i++)
	{
		if(m_Texfiles[i].find(".png") != string::npos)
		{
			Str s(m_Texfiles[i]);
			std::vector<Str> vec = s.split('/');
			s = Str(vec[vec.size() - 1]).split('.')[0];
			sf::Texture *tex = new sf::Texture();
			tex->loadFromFile(m_Texfiles[i]);
			tex->setSmooth(true);
			m_textures[s] = tex;
		}
	}

	temp = listDir(datas);
	for (size_t i = 0; i < temp.size(); i++)
	{
		if(temp[i].find(".jpg") != string::npos)
		{
			Str s(temp[i]);
			std::vector<Str> vec = s.split('/');
			s = Str(vec[vec.size() - 1]).split('.')[0];
			m_DatasNames.push_back(s);
		}
	}
	actualPageIndex = 0;
	updateActualPage();
}

sf::Texture *Ressources::getTexture(std::string name)
{
	return m_textures[name];
}
sf::Texture *Ressources::getPage(std::string name)
{
	if(actualPage != NULL)
		delete actualPage;
	sf::Texture*temp = new sf::Texture;
	temp->loadFromFile(Ressources::datas + name + ".jpg");
	return temp;
	;
}

Page *Ressources::updateActualPage()
{
	actualPageName = m_DatasNames[actualPageIndex] ;
	if(actualPage!=NULL)
		actualPage->save();
	sf::Image temp_im;
	temp_im.loadFromFile(Ressources::datas + actualPageName + ".jpg");
	actualPage = new Page(getPage(actualPageName), temp_im, actualPageName);
	actualPage->loadPage(datas + m_DatasNames[actualPageIndex] + ".piff");
	return actualPage;
}
void Ressources::incIndex(EventHandler* event)
{
	actualPageIndex++;
	if(actualPageIndex>=m_DatasNames.size())
		actualPageIndex=0;
	updateActualPage();
}

void Ressources::decIndex(EventHandler *event)
{
	actualPageIndex--;
	if (actualPageIndex <0)
		actualPageIndex = m_DatasNames.size()-1;
	updateActualPage();
}

std::vector<std::string> Ressources::listDir(const char* folder)
{
	vector<string> out;
	struct dirent *entry;
	DIR *dir = opendir(folder);
	if(dir == NULL)
	{
		return out;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if(entry->d_type == DT_REG)
		{
			out.push_back(folder+string(entry->d_name));
		}
	}

	closedir(dir);

	return out;
}
std::vector<std::string> Ressources::listDir(std::string folder)
{
	return listDir((folder.c_str()));
}