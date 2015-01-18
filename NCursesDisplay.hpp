
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

  void refresh();
  void draw();

  void drawRectangle(int x, int y, int width, int height, int color);
  void drawText(int x, int y, const char* text, int color);

  ~NCursesDisplay();


private:

  void _getKey();
  NCursesDisplay(const NCursesDisplay& rhs);
  NCursesDisplay& operator=(const NCursesDisplay& rhs);

  int _scrollY;

};

#endif
