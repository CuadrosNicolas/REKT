#ifndef JSONARRAY
#define JSONARRAY
#include "JSONEntity.h"
#include <vector>
#include <string>
class JSONArray : public JSONEntity
{
		public:
			JSONArray();
		virtual void assign(JSONEntity* entity);
		virtual JSONEntity& operator[](std::string s);
		virtual JSONEntity& operator[](unsigned int i);
		virtual std::vector<JSONEntity *> *getArray();
		virtual std::string getValue();
		virtual size_t getSize();

	  protected:
		std::vector<JSONEntity *> value;

};

#endif