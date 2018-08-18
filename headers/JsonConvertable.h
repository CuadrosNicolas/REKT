#ifndef JSONCONVERTABLE
#define JSONCONVERTABLE
#include "JSONEntity.h"
#include <iostream>
class JsonConvertable
{
	public:
		JsonConvertable();
		virtual std::string toJson();
		virtual void fromJson(JSONEntity* e);
};
#endif