#include "EventHandler.h"
using namespace std;

EventHandler::EventHandler()
{
}
EventHandler::~EventHandler()
{

}
void EventHandler::SetEventList(string eventList[], int eventListSize)
{

	for(int i = 0; i <eventListSize;i++)
	{
		eventVec temp;
		m_events[eventList[i]] = temp;
	}
}

void EventHandler::addEvent(std::string name, f_event event)
{
	if(m_events.find(name) != m_events.end())
	{
		m_events[name].push_back(event);
	}
}
void EventHandler::throwEvent(std::string name)
{
	if (m_events.find(name) != m_events.end())
	{
		eventVec temp = (m_events)[name];
		for(size_t i =0;i < temp.size();i++)
		{
			temp[i](this);
		}
	}
}