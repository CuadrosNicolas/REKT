#ifndef EVENTHANDLER
#define EVENTHANDLER
#include <map>
#include <string>
#include <vector>
#include <iostream>

class EventHandler
{

public:
	EventHandler();
	~EventHandler();
	void SetEventList(std::string eventList[], int eventListSize);
	void addEvent(std::string name, void (*event)(EventHandler *sender));
	void throwEvent(std::string name);

private:
	std::map<std::string, std::vector< void (*)(EventHandler *sender) > > m_events;
};


typedef void (*f_event)(EventHandler *sender);
typedef std::vector<f_event> eventVec;
typedef std::map<std::string, eventVec> eventMap;

#endif