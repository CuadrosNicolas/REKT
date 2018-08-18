#ifndef JSONENTITY
#define JSONENTITY
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
enum JSONTYPE{ARRAY,VAR_NUMBER,VAR_STRING,VAR_BOOL,VAR_NULL,VAR_CONTAINER,OBJECT};
class JSONEntity
{
	public:
		JSONEntity();
		virtual void assign(JSONEntity* entity);
		virtual JSONEntity& operator[](std::string s);
		virtual JSONEntity& operator[](unsigned int i);
		virtual size_t getSize();
		virtual std::vector<JSONEntity*>* getArray();
		virtual std::map<std::string,JSONEntity *> *getMap();
		virtual std::string getValue();
		virtual void print(std::ostream &O);
		virtual JSONTYPE getType();
		virtual int toint();
		virtual float tofloat();
		virtual double todouble();
		virtual std::string tostring();
		virtual bool tobool();
	protected:
	  JSONTYPE m_type;
};
std::ostream& operator<<(std::ostream& flow,JSONEntity& e);
#endif