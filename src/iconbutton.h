#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include <string>
#include "button.h"

using std::string;

class Esoteric;
class Surface;

class IconButton : public Button {
protected:
	Esoteric *app;
	string icon, label;
	int labelPosition, labelMargin;
	uint16_t labelHAlign, labelVAlign;
	void recalcSize();
	SDL_Rect iconRect, labelRect;

	Surface *iconSurface;

	void updateSurfaces();

public:
	static const int DISP_RIGHT = 0;
	static const int DISP_LEFT = 1;
	static const int DISP_TOP = 2;
	static const int DISP_BOTTOM = 3;

	IconButton(Esoteric *app, const string &icon, const string &label="");
	virtual ~IconButton() {};

	virtual void paint();
	virtual bool paintHover();

	virtual void setPosition(int x, int y);

	const string &getLabel();
	void setLabel(const string &label);
	void setLabelPosition(int pos, int margin);

	const string &getIcon();
	void setIcon(const string &icon);

	void setAction(ButtonAction action);
};

#endif
