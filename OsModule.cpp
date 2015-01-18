
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <ncurses.h>
#include "OsModule.hpp"
#include "Monitor.hpp"
#include "NCursesDisplay.hpp"
#include "TextItem.hpp"

#include "Info.hpp"

#include <sstream>

OsModule::OsModule() :
  _refreshRate(100000),
  _title("OS")
{
  Info os;

  _osTypeItem = new TextItem("OS Type", os.getInfoByNameString("kern.ostype"));
  _osReleaseItem = new TextItem("OS Release", os.getInfoByNameString("kern.osrelease"));
  _versionItem = new TextItem("Version", os.getInfoByNameString("kern.version"));

  addItem(_osTypeItem);
  addItem(_osReleaseItem);
  addItem(_versionItem);
}

OsModule::~OsModule() {

}


int OsModule::getHeight() const {
  int height = 3;
  std::list<AModuleItem*>::const_iterator i;

  for (i = _items.begin(); i != _items.end(); i++)
    height += (*i)->getHeight();

  return height;
}

const std::string& OsModule::getTitle() const {
  return _title;
}


int OsModule::getRefreshRate() const {
  return _refreshRate;
}

int OsModule::getLastRefresh() const {
  return _lastRefresh;
}

void OsModule::setLastRefresh(int value) {
  _lastRefresh = value;
}



void OsModule::refresh() {
  Info os;

  _osTypeItem->setValue(os.getInfoByNameString("kern.ostype"));
  _osReleaseItem->setValue(os.getInfoByNameString("kern.osrelease"));
  _versionItem->setValue(os.getInfoByNameString("kern.version"));
}

void OsModule::draw(NCursesDisplay& display, int x, int y) const {
  display.drawRectangle(x, y, COLS - 2, getHeight(), 2);
  display.drawText(COLS / 2 - _title.length() / 2, y + 1, _title.c_str(), 3);

  int offsetY = 1;
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    (*i)->draw(display, x, y + offsetY++);
}


AModuleItem* OsModule::getItem(const std::string& name) const {
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    if ((*i)->getName() == name)
      return *i;

  return NULL;
}

void OsModule::addItem(AModuleItem* item) {
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    if ((*i)->getName() == item->getName())
      return;

  _items.push_back(item);
}

void OsModule::removeItem(AModuleItem*item) {
  _items.remove(item);
}

const std::list<AModuleItem*>& OsModule::getItems() const {
  return _items;
}
