#ifndef DATA
#define DATA
#include "headers/JsonConvertable.h"
#include <string>
#include <iostream>
class Data : public JsonConvertable
{
  public:
	Data();
	virtual void fromJson(JSONEntity *e);
	virtual std::string toJson();

	std::string type;
	std::string id;
	std::string value;
	std::string location_id;
};
#endif