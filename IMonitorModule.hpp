
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <list>
#include "AModuleItem.hpp"

class NCursesDisplay;

class IMonitorModule {

public:

  IMonitorModule() {};

  virtual int getRefreshRate() const = 0;

  virtual void addItem(AModuleItem*) = 0;
  virtual void removeItem(AModuleItem*) = 0;
  virtual AModuleItem* getItem(const std::string& name) const = 0;
  virtual const std::list<AModuleItem*>& getItems() const = 0;
  virtual int getHeight() const = 0;
  virtual const std::string& getTitle() const = 0;


  virtual void refresh() = 0;

  virtual void draw(NCursesDisplay&, int x, int y) const = 0;

  virtual ~IMonitorModule() {};

  virtual int getLastRefresh() const = 0;
  virtual void setLastRefresh(int value) = 0;


private:

  IMonitorModule(const IMonitorModule&) {};
  IMonitorModule& operator=(const IMonitorModule& rhs);


};

#endif
