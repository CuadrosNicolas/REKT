#ifndef CONFIGFILE
#define CONFIGFILE
#include <map>
#include "Str.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
class configFile
{
	public:
		configFile(std::string path);
		std::string get(std::string section,std::string name);
		std::vector<int> getIntVector(std::string section, std::string name);
		std::vector<float> getFloatVector(std::string section, std::string name);
		sf::Color getColorVector(std::string section, std::string name);

	  private:
		std::map<std::string, std::map<std::string, std::string> > m_datas;
};
#endif