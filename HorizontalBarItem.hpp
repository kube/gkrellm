
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef HORIZONTALBARITEM_HPP
#define HORIZONTALBARITEM_HPP

#include "AModuleItem.hpp"

class HorizontalBarItem : public AModuleItem {

public:

  HorizontalBarItem(const std::string& name);
  HorizontalBarItem(const std::string& name, const std::string& value);
  ~HorizontalBarItem();

  const std::string& getName() const;
  int getHeight() const;
  float getValue() const;
  void setValue(float);

  void draw(NCursesDisplay& display, int x, int y) const;


private:

  HorizontalBarItem();
  HorizontalBarItem(const HorizontalBarItem& rhs);
  HorizontalBarItem& operator=(const HorizontalBarItem& rhs);

  const std::string _name;
  float             _value;
  int               _height;

};

#endif
