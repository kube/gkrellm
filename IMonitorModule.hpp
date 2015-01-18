
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

class IMonitorModule {

public:

  IMonitorModule() {};
  ~IMonitorModule() {};

  virtual const std::list<AModuleItem*>& getItems() const = 0;


private:

  IMonitorModule(const IMonitorModule& rhs);
  IMonitorModule& operator=(const IMonitorModule& rhs);

};

#endif
