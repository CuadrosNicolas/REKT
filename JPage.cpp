#include "JPage.h"
JPage::JPage()
{
}
void JPage::fromJson(JSONEntity *e)
{
	for (size_t i = 0; i < (*e)["data"].getSize(); i++)
	{
		datas.push_back(Data());
		datas[datas.size() - 1].fromJson(&((*e)["data"][i]));
	}
	for (size_t i = 0; i < (*e)["location"].getSize(); i++)
	{
		locations[(*e)["location"][i]["id"].getValue()] = Location();
		locations[(*e)["location"][i]["id"].getValue()].fromJson(&((*e)["location"][i]));
	}
	date = (*e)["meta"]["date"].getValue();
	type= (*e)["meta"]["type"].getValue();
	id = (*e)["meta"]["id"].getValue();
	piff_version = (*e)["meta"]["piff_version"].getValue();
	url = (*e)["meta"]["url"].getValue();
}
std::string JPage::toJson()
{
	std::string out = "{";
	std::string outLoc = "\"location\": [";
	out += "\"data\": [";

	for(size_t i=0;i<datas.size();i++)
	{
		out += datas[i].toJson();
		outLoc += locations[datas[i].location_id].toJson();
		out += ",";
		outLoc += ",";
	}
	out[out.length()-1] = ']';
	outLoc[outLoc.length() - 1] = ']';
	out += "," + outLoc + ",";
	out += "\"meta\":{";
	out += "\"date\":\"" + date + "\",";
	out += "\"type\":\"" + type + "\",";
	out += "\"id\":\"" + id + "\",";
	out += "\"piff_version\":\"" + piff_version + "\",";
	out += "\"url\":\"" + url + "\"";
	out += "}}";
	return out;
}