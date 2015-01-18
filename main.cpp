
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

int main(int argc, char **argv) {

  Monitor& monitor = *(Monitor::getInstance());

  if (argc > 1 && (std::string(argv[1]) == "--graphic" || std::string(argv[1]) == "-g"))
    std::cout << "Launch in Graphic mode" << std::endl;
  else
    monitor.setDisplay(new NCursesDisplay());

  monitor.run();

  return 0;
}
