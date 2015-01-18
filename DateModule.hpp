
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef DATEMODULE_HPP
#define DATEMODULE_HPP

#include <list>
#include "IMonitorModule.hpp"

#include "TextItem.hpp"
#include "HorizontalBarItem.hpp"

class DateModule : public IMonitorModule {

public:

  DateModule();
  ~DateModule();

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

  DateModule(const DateModule&);
  DateModule& operator=(const DateModule& rhs);

  TextItem* _yearItem;
  TextItem* _monthItem;
  TextItem* _dayItem;

  TextItem* _hoursItem;
  TextItem* _minutesItem;
  TextItem* _secondsItem;

  HorizontalBarItem* _activeRamItemBar;

  int _lastRefresh;
  int _refreshRate;
  std::list<AModuleItem*> _items;
  std::string _title;

};

#endif
