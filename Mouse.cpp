#include "Mouse.h"

Mouse MouseManager::M;
MouseManager::mode MouseManager::actualMode=ADD;
sf::Vector2f MouseManager::previousPos;
Rekt *MouseManager::linkRekt=NULL;

Mouse MouseManager::getState()
{
	return M;
}
void MouseManager::setState(sf::Vector2f position, MouseState status)
{
	M.position = position;
	M.status = status;
}
void MouseManager::setAdd(EventHandler* e)
{
	actualMode = ADD;
	unlink();
}
void MouseManager::setRemove(EventHandler* e)
{
	actualMode = REMOVE;
	unlink();
}

void MouseManager::setLink(Rekt* r)
{
	linkRekt = r;
}
void MouseManager::unlink()
{
	linkRekt = NULL;
}
bool MouseManager::isLink()
{
	return !(linkRekt==NULL);
}
void MouseManager::updatePage(Page* p)
{
		switch(actualMode)
		{
			case ADD:
				if(!isLink())
				{

					if(p->getBox()->pointCollision(M.position) and M.status == PRESSED)
					{
						linkRekt = p->addRekt();
						linkRekt->setPosition(M.position);
						previousPos = M.position;
					}
				}
				else
				{
					linkRekt->setSize(sf::Vector2f(M.position.x-previousPos.x,M.position.y-previousPos.y));
					if(M.status==NOT_PRESSED)
					{
						actualMode = ADD;
						unlink();
					}
				}
			break;
			case REMOVE:
				for(size_t s=0;s<p->getRekt().size();s++)
				{
					if(p->getRekt()[s]->getBox()->pointCollision(M.position) and M.status == PRESSED)
					{
						p->remove(p->getRekt()[s]->getLocationId());
					}
				}
			break;

		}

	
}