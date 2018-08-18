#ifndef JSONVARIABLE
#define JSONVARIABLE
#include "JSONEntity.h"

class JSONVariable : public JSONEntity
{
		public:
		  JSONVariable(std::string s,JSONTYPE T);
		  JSONVariable();
		  virtual void assign(JSONEntity *entity);
		  virtual JSONEntity &operator[](std::string s);
		  virtual JSONEntity &operator[](unsigned int i);
			virtual size_t getSize();
			virtual std::string getValue();
		  std::string name;
		  JSONEntity *value;
};

#endif