
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include "Monitor.hpp"
#include "NCursesDisplay.hpp"

#include "RamModule.hpp"
#include "OsModule.hpp"

int main() {

  Monitor& monitor = *(Monitor::getInstance());
  monitor.setDisplay(new NCursesDisplay());


  Monitor::getInstance()->addModule(new OsModule());
  Monitor::getInstance()->addModule(new RamModule());


  monitor.run();
  return 0;
}
