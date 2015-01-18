
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <ncurses.h>
#include "TextItem.hpp"
#include "NCursesDisplay.hpp"

TextItem::TextItem(const std::string& name) :
  _name(name),
  _height(1)
{

}

TextItem::TextItem(const std::string& name, const std::string& value) :
  _name(name),
  _value(value),
  _height(1)
{

}

TextItem::~TextItem() {

}



void TextItem::draw(NCursesDisplay& display, int x, int y) const {
  display.drawText(x + 1, y + 1, (_name + " :").c_str(), 2);
  display.drawText(COLS / 2 - _value.length() / 2, y + 1, _value.c_str(), 1);
}



const std::string& TextItem::getName() const {
  return _name;
}

const std::string& TextItem::getValue() const {
  return _value;
}

int TextItem::getHeight() const {
  return _height;
}

void TextItem::setValue(const std::string& value) {
  _value = value;
}
