
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef OSMODULE_HPP
#define OSMODULE_HPP

#include <list>
#include "IMonitorModule.hpp"

#include "TextItem.hpp"
#include "HorizontalBarItem.hpp"

class OsModule : public IMonitorModule {

public:

  OsModule();
  ~OsModule();

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

  OsModule(const OsModule&);
  OsModule& operator=(const OsModule& rhs);

  TextItem* _osTypeItem;
  TextItem* _osReleaseItem;
  TextItem* _versionItem;

  int _lastRefresh;
  int _refreshRate;
  std::list<AModuleItem*> _items;
  std::string _title;

};

#endif
