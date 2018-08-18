#ifndef JSONPARSER
#define JSONPARSER
#include "JSONEntity.h"
#include "JSONArray.h"
#include "JSONObject.h"
#include "JSONVariable.h"
#include <stack>
#include <fstream>
#include <iostream>
class JSONParser
{
	public:
		JSONParser(std::string file);
		JSONEntity *parse();

	  protected:
		enum state
		{
			A,
			B,
			C,
			D,
			E,
			F,
			G
		};
		std::string m_file;
		std::string buffer;
		char c;
		std::stack<JSONEntity*> stack;
		state s;
		void createObject();
		void createArray();
		void createVar();
		void assignVar();
		void assignNumber();
		void assignBool();
		void assignNull();
		void assign();
		void cleanBuffer();
};

#endif