
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <ncurses.h>
#include "RamModule.hpp"
#include "Monitor.hpp"
#include "NCursesDisplay.hpp"
#include "TextItem.hpp"

#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

#include <sstream>

RamModule::RamModule() :
  _refreshRate(200),
  _title("RAM")
{
  _totalRamItem = new TextItem("totalRamItem");
  _wiredRamItem = new TextItem("wiredRamItem");
  _activeRamItem = new TextItem("activeRamItem");
  _inactiveRamItem = new TextItem("inactiveRamItem");
  _freeRamItem = new TextItem("freeRamItem");

  _activeRamItemBar = new HorizontalBarItem("_activeRamItemBar", 0.01f);


  addItem(_totalRamItem);
  addItem(_wiredRamItem);
  addItem(_activeRamItem);
  addItem(_inactiveRamItem);
  addItem(_freeRamItem);

  addItem(_activeRamItemBar);
}

RamModule::~RamModule() {

}


int RamModule::getHeight() const {
  int height = 3;
  std::list<AModuleItem*>::const_iterator i;

  for (i = _items.begin(); i != _items.end(); i++)
    height += (*i)->getHeight();

  return height;
}

const std::string& RamModule::getTitle() const {
  return _title;
}


int RamModule::getRefreshRate() const {
  return _refreshRate;
}

int RamModule::getLastRefresh() const {
  return _lastRefresh;
}

void RamModule::setLastRefresh(int value) {
  _lastRefresh = value;
}


static std::string unsignedIntToString(unsigned int a) {
  std::stringstream ss;
  ss << a;

  return ss.str();
}

void RamModule::refresh() {

  mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
  vm_statistics_data_t vmstat;

  host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count);

  _totalRamItem->setValue(unsignedIntToString(vmstat.wire_count + vmstat.active_count + vmstat.inactive_count + vmstat.free_count));
  _wiredRamItem->setValue(unsignedIntToString(vmstat.wire_count));
  _activeRamItem->setValue(unsignedIntToString(vmstat.active_count));
  _inactiveRamItem->setValue(unsignedIntToString(vmstat.inactive_count));
  _freeRamItem->setValue(unsignedIntToString(vmstat.free_count));

  float activeRamProportion = static_cast<float>(vmstat.active_count) / static_cast<float>(vmstat.wire_count + vmstat.active_count + vmstat.inactive_count + vmstat.free_count);

  _activeRamItemBar->setValue(activeRamProportion);
}

void RamModule::draw(NCursesDisplay& display, int x, int y) const {
  display.drawRectangle(x, y, COLS - 2, getHeight(), 2);
  display.drawText(COLS / 2 - _title.length() / 2, y + 1, _title.c_str(), 3);

  int offsetY = 1;
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    (*i)->draw(display, x, y + offsetY++);
}


AModuleItem* RamModule::getItem(const std::string& name) const {
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    if ((*i)->getName() == name)
      return *i;

  return NULL;
}

void RamModule::addItem(AModuleItem* item) {
  std::list<AModuleItem*>::const_iterator i;
  for (i = _items.begin(); i != _items.end(); i++)
    if ((*i)->getName() == item->getName())
      return;

  _items.push_back(item);
}

void RamModule::removeItem(AModuleItem*item) {
  _items.remove(item);
}

const std::list<AModuleItem*>& RamModule::getItems() const {
  return _items;
}
