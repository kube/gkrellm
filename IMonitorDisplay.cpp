
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

class IMonitorDisplay {

public:

  virtual IMonitorDisplay() = 0;
  virtual IMonitorDisplay(const IMonitorDisplay& rhs) = 0;
  virtual ~IMonitorDisplay() = 0;
  virtual IMonitorDisplay& operator=(const IMonitorDisplay& rhs) = 0;


private:

  


};

#endif
