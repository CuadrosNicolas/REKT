#include "Str.h"
using namespace std;

Str::Str()
{

}
Str::Str(const std::string &s) : string(s)
{

}
Str::Str(const char *s) : std::string(s)
{

}
Str &Str::replace(char previous, char newC)
{
	size_t pos;
	do
	{
		pos = this->find(previous);
		if (pos != string::npos)
		{
			(*this)[pos] = newC;
		}
	} while (pos != string::npos);
	return (*this);
}
Str &Str::remove(char c)
{
	size_t pos;
	do
	{
		pos = this->find(c);
		if (pos != string::npos)
		{
			this->erase(pos, 1);
		}
	} while (pos != string::npos);
	return (*this);
}
std::vector<Str> Str::split(char delimiter)
{
	std::vector<Str> out;
	Str token;
	size_t pos;
	string save = *this;
	while ((pos = save.find(delimiter)) != std::string::npos)
	{
		token = save.substr(0, pos);
		out.push_back(token);
		save.erase(0, pos + 1);
	}
	out.push_back(save);
	return out;
}