
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef TEXTITEM_HPP
#define TEXTITEM_HPP

#include "AModuleItem.hpp"

class TextItem : public AModuleItem {

public:

  TextItem(const std::string& name);
  TextItem(const std::string& name, const std::string& value);
  ~TextItem();

  const std::string& getName() const;
  const std::string& getValue() const;
  int getHeight() const;
  void setValue(const std::string& value);

  void draw(NCursesDisplay& display, int x, int y) const;


private:

  TextItem();
  TextItem(const TextItem& rhs);
  TextItem& operator=(const TextItem& rhs);

  const std::string _name;
  std::string       _value;
  int               _height;

};

#endif
