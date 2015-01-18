
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include "TextItem.hpp"
#include "HorizontalBarItem.hpp"

class IMonitorDisplay {

public:

  IMonitorDisplay() {};
  virtual ~IMonitorDisplay() {};

  virtual void refresh() = 0;
  virtual void draw() = 0;


private:

  IMonitorDisplay(const IMonitorDisplay& rhs);
  IMonitorDisplay& operator=(const IMonitorDisplay& rhs);

};

#endif
