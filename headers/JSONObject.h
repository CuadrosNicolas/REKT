#ifndef JSONOBJECT
#define JSONOBJECT
#include "JSONEntity.h"
#include <map>
#include "JSONVariable.h"
class JSONObject : public JSONEntity
{
		public:
			JSONObject();
		virtual void assign(JSONEntity* entity);
		virtual JSONEntity& operator[](std::string s);
		virtual JSONEntity &operator[](unsigned int i);
		virtual std::map<std::string, JSONEntity *> *getMap();
		virtual std::string getValue();
		virtual size_t getSize();

	  protected:
		std::map<std::string, JSONEntity *> value;

};

#endif