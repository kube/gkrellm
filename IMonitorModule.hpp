
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

class IMonitorModule {

public:

  virtual IMonitorModule() = 0;
  virtual IMonitorModule(const IMonitorModule& rhs) = 0;
  virtual ~IMonitorModule() = 0;
  virtual IMonitorModule& operator=(const IMonitorModule& rhs) = 0;


private:

  


};

#endif
