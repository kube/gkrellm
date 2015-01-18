
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include "Monitor.hpp"
#include <unistd.h>
#include <ncurses.h>

Monitor::Monitor() {

}

Monitor::~Monitor() {

}


void Monitor::pause() {
  _paused = !_paused;
}

void Monitor::stop() {
  _running = false;
}

void Monitor::run() {
  _running = true;
  _paused = false;

  static int elapsedMicroSeconds = 0;
  _elapsedTime = 0;

  while (_running) {
    this->refresh();
    this->draw();

    usleep(MONITOR_REFRESH_RATE);
    elapsedMicroSeconds += MONITOR_REFRESH_RATE;

    if (elapsedMicroSeconds >= 1000) {
      _elapsedTime += elapsedMicroSeconds / 1000;
      elapsedMicroSeconds %= 1000;
    }
  }

  delete _currentDisplay;
}



void Monitor::refresh() {
  _currentDisplay->refresh();
}

void Monitor::draw() {
  _currentDisplay->draw();
}



void Monitor::addModule(IMonitorModule* module) {
  _modules.push_back(module);
}

void Monitor::removeModule(IMonitorModule* module) {
  _modules.remove(module);
}

const std::list<IMonitorModule*>& Monitor::getModules() const {
  return _modules;
}




void Monitor::setDisplay(IMonitorDisplay* display) {
  _currentDisplay = display;
}

Monitor* Monitor::getInstance() {
  static Monitor instance;

  return &instance;
}
