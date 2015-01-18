
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef USERMODULE_HPP
#define USERMODULE_HPP

#include <list>
#include "IMonitorModule.hpp"

#include "TextItem.hpp"
#include "HorizontalBarItem.hpp"

class UserModule : public IMonitorModule {

public:

  UserModule();
  ~UserModule();

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

  UserModule(const UserModule&);
  UserModule& operator=(const UserModule& rhs);

  TextItem* _hostNameItem;
  TextItem* _userNameItem;

  int _lastRefresh;
  int _refreshRate;
  std::list<AModuleItem*> _items;
  std::string _title;

};

#endif
