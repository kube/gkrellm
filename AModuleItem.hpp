
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

class AModuleItem {

public:

  AModuleItem();
  AModuleItem(const AModuleItem& rhs);
  ~AModuleItem();
  AModuleItem& operator=(const AModuleItem& rhs);

  const std::string& getName() const;


protected:

  const std::string _name;

};

#endif
