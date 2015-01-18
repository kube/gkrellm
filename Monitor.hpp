
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef MONITOR_HPP
#define MONITOR_HPP

#define MONITOR_REFRESH_RATE 200

#include <list>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Monitor {

public:

  void run();
  void stop();
  void pause();

  void draw();
  void refresh();

  static Monitor* getInstance();

  void setDisplay(IMonitorDisplay*);
  void addModule(IMonitorModule*);
  void removeModule(IMonitorModule*);
  const std::list<IMonitorModule*>& getModules() const;

private:

  Monitor();
  ~Monitor();
  Monitor(const Monitor& rhs);
  Monitor& operator=(const Monitor& rhs);

  void _getKey();

  bool  _running;
  bool  _paused;
  int   _elapsedTime;

  IMonitorDisplay* _currentDisplay;
  std::list<IMonitorModule*> _modules;

};

#endif