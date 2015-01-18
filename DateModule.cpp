
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <ncurses.h>
#include "DateModule.hpp"
#include "Monitor.hpp"
#include "NCursesDisplay.hpp"
#include "TextItem.hpp"

#include "Info.hpp"

#include <sstream>


static std::string unsignedIntToString(unsigned int a) {
  std::stringstream ss;
  ss << a;

  return ss.str();
}


DateModule::DateModule() :
  _refreshRate(100),
  _title("Date")
{
  time_t t = time(0);
  struct tm * now = localtime(&t);

  _yearItem = new TextItem("Year", unsignedIntToString(now->tm_year + 1900));
  _monthItem = new TextItem("Month", unsignedIntToString(now->tm_mon + 1));
  _dayItem = new TextItem("Day", unsignedIntToString(now->tm_mday));

  _hoursItem = new TextItem("Hours", unsignedIntToString(now->tm_hour));
  _minutesItem = new TextItem("Minutes", unsignedIntToString(now->tm_min));
  _secondsItem = new TextItem("Seconds", unsignedIntToString(now->tm_sec));

  addItem(_yearItem);
  addItem(_monthItem);
  addItem(_dayItem);

  addItem(_hoursItem);
  addItem(_minutesItem);
  addItem(_secondsItem);
}

DateModule::~DateModule() {

}


int DateModule::getHeight() const {
  int height = 3;
  std::list<AModuleItem*>::const_iterator i;

  for (i = _items.begin(); i != _items.end(); i++)
    height += (*i)->getHeight();

  return height;
}

const std::string& DateModule::getTitle() const {
  return _title;
}


int DateModule::getRefreshRate() const {
  return _refreshRate;
}

int DateModule::getLastRefresh() const {
  return _lastRefresh;
}

void DateModule::setLastRefresh(int value) {
  _lastRefresh = value;
}



void DateModule::refresh() {
  time_t t = time(0);
  struct tm * now = localtime(&t);

  _yearItem->setValue(unsignedIntToString(now->tm_year + 1900));
  _monthItem->setValue(unsignedIntToString(now->tm_mon + 1));
  _dayItem->setValue(unsignedIntToString(now->tm_mday));

  _hoursItem->setValue(unsignedIntToString(now->tm_hour));
  _minutesItem->setValue(unsignedIntToString(now->tm_min));
  _secondsItem->setValue(unsignedIntToString(now->tm_sec));
}

void DateModule::draw(NCursesDisplay& display, int x, int y) const {
  display.drawRectangle(x, y, COLS - 2, getHeight(), 2);
  display.drawText(COLS / 2 - _title.length() / 2, y + 1, _title.c_str(), 3);

  int offsetY = 1;
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    (*i)->draw(display, x, y + offsetY++);
}


AModuleItem* DateModule::getItem(const std::string& name) const {
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    if ((*i)->getName() == name)
      return *i;

  return NULL;
}

void DateModule::addItem(AModuleItem* item) {
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    if ((*i)->getName() == item->getName())
      return;

  _items.push_back(item);
}

void DateModule::removeItem(AModuleItem*item) {
  _items.remove(item);
}

const std::list<AModuleItem*>& DateModule::getItems() const {
  return _items;
}
