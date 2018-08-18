#include "configFile.h"
using namespace std;
configFile::configFile(std::string path)
{
	ifstream file(path);
	string line;
	bool isVar = false;
	string section;
	if(file.is_open())
	{
		while(getline(file,line))
		{
			Str l(line);
			if(l.find("[")!= string::npos and l.find('=') == string::npos)
				isVar = false;
			else
				isVar = true;
			l = l.remove('[').remove(']').remove(' ').remove('\t').remove('\n').split('#')[0];
			if(l.size()>0)
			{
				if(isVar)
				{
					std::vector<Str> temp = l.split('=');
					m_datas[section][temp[0]] = temp[1];
				}
				else
				{
					section = l;
					m_datas[section] = std::map<string, string>();
				}
			}

		}
	}
}
std::string configFile::get(std::string section, std::string name)
{
	return m_datas[section][name];
}
std::vector<int> configFile::getIntVector(std::string section, std::string name)
{
	Str temp(this->get(section,name));
	temp.remove('[').remove(']');
	std::vector<Str> outStr = temp.split(',');
	std::vector<int> out;
	for(size_t i = 0;i<outStr.size();i++)
	{
		out.push_back(std::stoi(outStr[i]));
	}

	return out;

}

std::vector<float> configFile::getFloatVector(std::string section, std::string name)
{
	Str temp(this->get(section, name));
	temp.remove('[').remove(']');
	std::vector<Str> outStr = temp.split(',');
	std::vector<float> out;
	for (unsigned int i = 0; i < outStr.size(); i++)
	{
		out.push_back(std::stof(outStr[i]));
	}
	return out;
}

sf::Color configFile::getColorVector(std::string section, std::string name)
{
	std::vector<int> vecColor = this->getIntVector(section,name);
	return sf::Color(vecColor[0],vecColor[1],vecColor[2],vecColor[3]);
}