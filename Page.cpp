#include "Page.h"

Page::Page()
{
	maxID = 0;
}
Page::Page(sf::Texture *pageName, sf::Image im,std::string name)
{
	pageShape.setTexture(pageName);
	pageShape.setSize(sf::Vector2f(pageShape.getTexture()->getSize().x, pageShape.getTexture()->getSize().y));
	box.setSize(pageShape.getSize());
	maxID = 0;
	innerImage = im;
	m_name = name;
}
void Page::loadPage(std::string jsonFile)
{
	std::cout << "Trying to set page : "+jsonFile << std::endl;
	m_jsonFile = jsonFile;
	pageDatas = new JPage();
	pageDatas->fromJson(JSONParser(jsonFile).parse());
	for(size_t s = 0;s<pageDatas->datas.size();s++)
	{
		if(pageDatas->datas[s].id[0] >= '0' && pageDatas->datas[s].id[0] <= '9')
		{
			if(std::stoi(pageDatas->datas[s].id)>maxID)
			{
				maxID = std::stoi(pageDatas->datas[s].id);
			}
		}
		rekts.push_back(new Rekt(pageDatas->datas[s],pageDatas->locations[pageDatas->datas[s].location_id]));
	}
	Rekt::setMaxID(maxID);

}
void Page::save()
{
	pageDatas->datas.clear();
	pageDatas->locations.clear();
	for(size_t s=0;s<rekts.size();s++)
	{
		pageDatas->datas.push_back(rekts[s]->m_data);
		pageDatas->locations[rekts[s]->m_data.location_id] = rekts[s]->m_location;
	}
	std::fstream ofs;
	ofs.open(m_jsonFile,std::ofstream::out|std::ofstream::trunc);
	ofs << pageDatas->toJson();
	ofs.close();
}
void Page::screenShot()
{
	for (size_t s = 0; s < rekts.size(); s++)
	{
		sf::Vector2f base = rekts[s]->getPosition();
		for (int i = -3; i < rekts[s]->getSize().x+3;i++)
		{
			for (int j = -3; j < rekts[s]->getSize().y+3; j++)
			{
				if(i<0)
					i=0;
				if(j<0)
					j=0;
				sf::Vector2f actualPixel = base+sf::Vector2f(i,j);
				if (!(actualPixel.x >= base.x && actualPixel.x <= base.x + rekts[s]->getSize().x &&
				 actualPixel.y >= base.y && actualPixel.y <= base.y + rekts[s]->getSize().y))
				 {
					innerImage.setPixel(actualPixel.x, actualPixel.y, sf::Color::Red);
				 }
			}
		}
	}
	innerImage.saveToFile("./out/"+m_name+".bmp");
}
void Page::remove(std::string id)
{
	for(size_t s=0;s<rekts.size();s++)
	{
		if(rekts[s]->getLocationId()==id)
		{
			rekts.erase(rekts.begin()+s);
			break;
		}
	}
}
void Page::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (m_isDrawable)
	{
		target.draw(pageShape, states);
		for(size_t s =0;s<rekts.size();s++)
		{
			target.draw(*rekts[s],states);
		}
	}
}
Rekt* Page::addRekt()
{
	Rekt* temp = new Rekt();
	rekts.push_back(temp);
	return temp;
}
std::vector<Rekt*>& Page::getRekt()
{
	return rekts;
}