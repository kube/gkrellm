
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef NCURSESDISPLAY_HPP
#define NCURSESDISPLAY_HPP

#include "IMonitorDisplay.hpp"

class NCursesDisplay : public IMonitorDisplay {

public:

  NCursesDisplay();
  ~NCursesDisplay();

  void refresh();

  void draw();
  void draw(IMonitorModule&);
  void draw(TextItem&);
  void draw(HorizontalBarItem&);


private:

  void _getKey();
  NCursesDisplay(const NCursesDisplay& rhs);
  NCursesDisplay& operator=(const NCursesDisplay& rhs);

};

#endif
