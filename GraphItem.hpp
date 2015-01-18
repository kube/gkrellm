
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef GRAPHITEM_HPP
#define GRAPHITEM_HPP

class GraphItem {

public:


  ~GraphItem();
  GraphItem& operator=(const GraphItem& rhs);


private:
  GraphItem(const GraphItem& rhs);
  GraphItem();
  


};

#endif