#ifndef LOCATION
#define LOCATION
#include "headers/JsonConvertable.h"
#include <string>
#include <iostream>
class Location : public JsonConvertable
{
	public:
		Location();
		virtual void fromJson(JSONEntity* e);
		virtual std::string toJson();

		std::string type;
		std::string id;
		float polygon[4][2];
};

#endif

