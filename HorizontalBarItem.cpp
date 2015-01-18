
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <ncurses.h>
#include "HorizontalBarItem.hpp"
#include "NCursesDisplay.hpp"

HorizontalBarItem::HorizontalBarItem(const std::string& name) :
  _name(name),
  _height(1)
{

}

HorizontalBarItem::HorizontalBarItem(const std::string& name, const float value) :
  _name(name),
  _value(value),
  _height(1)
{

}

HorizontalBarItem::~HorizontalBarItem() {

}



void HorizontalBarItem::draw(NCursesDisplay& display, int x, int y) const {
  int width = static_cast<int>((COLS - 4) * _value);

  display.drawText(x + 1, y + 2, std::string(width, '|').c_str(), 3);
}



const std::string& HorizontalBarItem::getName() const {
  return _name;
}

float HorizontalBarItem::getValue() const {
  return _value;
}

int HorizontalBarItem::getHeight() const {
  return _height;
}

void HorizontalBarItem::setValue(float value) {

  _value = value > 0 ? value : 0;
  _value = _value < 1 ? value : 1;
}
