#include "JData.h"
Data::Data()
{
}
void Data::fromJson(JSONEntity *e)
{
	type = (*e)["type"].getValue();
	id = (*e)["id"].getValue();
	value = (*e)["value"].getValue();
	location_id = (*e)["location_id"].getValue();
}
std::string Data::toJson()
{
	std::string out = "{";
	out += "\"type\":";
	out += "\"" + type + "\",";

	out += "\"id\":";
	out += "\"" + id + "\",";

	out += "\"value\":";
	out += "\"" + value + "\",";

	out += "\"location_id\":";
	out += "\"" + location_id + "\"";

	out += "}";
	return out;
}