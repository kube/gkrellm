
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <ncurses.h>
#include "UserModule.hpp"
#include "Monitor.hpp"
#include "NCursesDisplay.hpp"
#include "TextItem.hpp"

#include "Info.hpp"

#include <sstream>

UserModule::UserModule() :
  _refreshRate(100000),
  _title("OS")
{
  Info user;

  _hostNameItem = new TextItem("Host Name", user.getInfoByNameString("kern.hostname"));
  _userNameItem = new TextItem("User Name", user.getUserName());

  addItem(_hostNameItem);
  addItem(_userNameItem);
}

UserModule::~UserModule() {

}


int UserModule::getHeight() const {
  int height = 3;
  std::list<AModuleItem*>::const_iterator i;

  for (i = _items.begin(); i != _items.end(); i++)
    height += (*i)->getHeight();

  return height;
}

const std::string& UserModule::getTitle() const {
  return _title;
}


int UserModule::getRefreshRate() const {
  return _refreshRate;
}

int UserModule::getLastRefresh() const {
  return _lastRefresh;
}

void UserModule::setLastRefresh(int value) {
  _lastRefresh = value;
}



void UserModule::refresh() {
  Info user;

  _hostNameItem->setValue(user.getInfoByNameString("kern.hostname"));
  _userNameItem->setValue(user.getUserName());
}

void UserModule::draw(NCursesDisplay& display, int x, int y) const {
  display.drawRectangle(x, y, COLS - 2, getHeight(), 2);
  display.drawText(COLS / 2 - _title.length() / 2, y + 1, _title.c_str(), 3);

  int offsetY = 1;
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    (*i)->draw(display, x, y + offsetY++);
}


AModuleItem* UserModule::getItem(const std::string& name) const {
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    if ((*i)->getName() == name)
      return *i;

  return NULL;
}

void UserModule::addItem(AModuleItem* item) {
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    if ((*i)->getName() == item->getName())
      return;

  _items.push_back(item);
}

void UserModule::removeItem(AModuleItem*item) {
  _items.remove(item);
}

const std::list<AModuleItem*>& UserModule::getItems() const {
  return _items;
}
