
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

class TextItem : public AModuleItem {

public:

  TextItem(const std::string& name);
  ~TextItem();

  std::string& getValue() const;


private:

  TextItem();
  TextItem(const TextItem& rhs);
  TextItem& operator=(const TextItem& rhs);

  const std::string _value;

};

#endif
