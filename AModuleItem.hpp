
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef AMODULEITEM_HPP
#define AMODULEITEM_HPP

#include <string>

class NCursesDisplay;

class AModuleItem {

public:

  AModuleItem() {};
  ~AModuleItem() {};

  virtual const std::string& getName() const = 0;
  virtual int getHeight() const = 0;
  virtual void setValue(const std::string& value) = 0;

  virtual void draw(NCursesDisplay& display, int x, int y) const = 0;

private:

  AModuleItem(const AModuleItem&) {};
  AModuleItem& operator=(const AModuleItem&);


};

#endif
