
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
#include "UserModule.hpp"
#include "DateModule.hpp"

int main() {

  Monitor& monitor = *(Monitor::getInstance());
  monitor.setDisplay(new NCursesDisplay());


  Monitor::getInstance()->addModule(new RamModule());
  Monitor::getInstance()->addModule(new UserModule());
  Monitor::getInstance()->addModule(new DateModule());
  Monitor::getInstance()->addModule(new OsModule());


  monitor.run();
  return 0;
}
