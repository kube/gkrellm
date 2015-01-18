
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

class HorizontalBarItem : public AModuleItem {

public:

  HorizontalBarItem(const std::string& name);
  ~HorizontalBarItem();

  float getValue() const;


private:

  HorizontalBarItem();
  HorizontalBarItem(const HorizontalBarItem& rhs);
  HorizontalBarItem& operator=(const HorizontalBarItem& rhs);

  const std::string      _value;

};

#endif
