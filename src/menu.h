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
#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "link.h"

class LinkApp;
class Esoteric;

typedef std::vector<Link*> linklist;

/**
Handles the menu structure

	@author Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
*/
class Menu {
private:
	Esoteric *app;
	int iSection, iLink;
	uint32_t iFirstDispSection, iFirstDispRow;
	std::vector<std::string> sections;
	std::vector<linklist> links;

	void readLinks();
	void freeLinks();

public:
	Menu(Esoteric *app);
	~Menu();

	linklist *sectionLinks(int i = -1);

	int selSectionIndex();
	int sectionNumItems();

	const std::string &selSection();
	void decSectionIndex();
	void incSectionIndex();
	void setSectionIndex(int i);
	uint32_t firstDispSection();
	uint32_t firstDispRow();

	bool addActionLink(uint32_t section, const std::string &title, fastdelegate::FastDelegate0<> action, const std::string &description = "", const std::string &icon = "");
	bool addLink(std::string path, std::string file, std::string section = "");
	bool addSection(const string &sectionName);
	void deleteSelectedLink();
	void deleteSelectedSection();

	void loadIcons();
	bool linkChangeSection(uint32_t linkIndex, uint32_t oldSectionIndex, uint32_t newSectionIndex);

	int selLinkIndex();
	Link *selLink();
	LinkApp *selLinkApp();
	void pageUp();
	void pageDown();
	void linkLeft();
	void linkRight();
	void linkUp();
	void linkDown();
	void setLinkIndex(int i);
	void letterPrevious();
	void letterNext();

	std::string sectionPath(int section = -1);

	const std::vector<std::string> &getSections() { return sections; }
	void renameSection(int index, const std::string &name);
	bool sectionExists(const std::string &name);
	int getSectionIndex(const std::string &name);
	const std::string getSectionIcon(int i);

	void orderLinks();
};

#endif
