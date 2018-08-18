#ifndef STR
#define STR
#include <string>
#include <vector>
class Str : public std::string
{
	public:
		Str();
		Str(const std::string& s);
		Str(const char*s);
		Str & replace(char previous, char newC);
		Str & remove(char c);
		std::vector<Str> split(char delimiter);
};
#endif