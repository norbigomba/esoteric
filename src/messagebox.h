/***************************************************************************
 *   Copyright (C) 2006 by Massimiliano Torromeo   *
 *   massimiliano.torromeo@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef MESSAGEBOX_H_
#define MESSAGEBOX_H_

#define MB_BTN_B 0
#define MB_BTN_X 1
#define MB_BTN_START 2
#define MB_BTN_SELECT 3

#include <string>
#include "esoteric.h"

using std::string;
using std::vector;

class MessageBox {
private:
	string text, icon;
	int autohide, bgalpha;
	Esoteric *app;
	vector<string> buttons;
	vector<string> buttonLabels;
	vector<SDL_Rect> buttonPositions;
	string formatText(int box_w_padding, int buttonWidth);

public:
	MessageBox(Esoteric *app, const string &text, const string &icon="");
	void setButton(int action, const string &btn);
	int exec();
	void setAutoHide(int delay);
	void setBgAlpha(int bgalpha);
	void fadeOut(int delay = 250);
};

#endif /*MESSAGEBOX_H_*/
