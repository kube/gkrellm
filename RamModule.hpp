
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef RAMMODULE_HPP
#define RAMMODULE_HPP

#include <list>
#include "IMonitorModule.hpp"

#include "TextItem.hpp"
#include "HorizontalBarItem.hpp"

class RamModule : public IMonitorModule {

public:

  RamModule();
  ~RamModule();

  int getRefreshRate() const;

  int getHeight() const;
  const std::string& getTitle() const;

  void refresh();
  void draw(NCursesDisplay&, int x, int y) const;

  void addItem(AModuleItem*);
  void removeItem(AModuleItem*);
  AModuleItem* getItem(const std::string&) const;
  const std::list<AModuleItem*>& getItems() const;

  int getLastRefresh() const;
  void setLastRefresh(int value);


private:

  RamModule(const RamModule&);
  RamModule& operator=(const RamModule& rhs);

  TextItem* _totalRamItem;
  TextItem* _wiredRamItem;
  TextItem* _activeRamItem;
  TextItem* _inactiveRamItem;
  TextItem* _freeRamItem;

  HorizontalBarItem* _wiredRamItemBar;

  int _lastRefresh;
  int _refreshRate;
  std::list<AModuleItem*> _items;
  std::string _title;

};

#endif
