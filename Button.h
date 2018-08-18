#ifndef BUTTON
#define BUTTON
#include "ToggleButton.h"

class Button : public ToggleButton
{
	public:
	Button();
	Button(std::string imageName);
	virtual void updateState();
	virtual void toggle();
};

#endif