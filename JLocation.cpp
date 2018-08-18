#include "JLocation.h"
Location::Location()
{

}
void Location::fromJson(JSONEntity* e)
{
	type = (*e)["type"].getValue();
	id = (*e)["id"].getValue();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			polygon[i][j] = (*e)["polygon"][i][j].tofloat();
		}
	}
}
std::string Location::toJson()
{
	std::string out = "{";
	out += "\"type\":";
	out += "\"" + type + "\",";
	out += "\"id\":";
	out += "\"" + id + "\",";
	out += "\"polygon\":";
	out += "[";
	for (int i = 0; i < 4; i++)
	{
		out += "[";
		out += std::to_string(polygon[i][0])+",";
		out += std::to_string(polygon[i][1]);
		out += "],";
	}
	out[out.length()-1] = ']';
	out += "}";
	return out;
}