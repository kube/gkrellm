
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include "NCursesDisplay.hpp"
#include "Monitor.hpp"
#include <unistd.h>
#include <ncurses.h>

static void initColors() {
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
}

NCursesDisplay::NCursesDisplay() {
  initscr();
  ESCDELAY = 10;
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(0);
  noecho();
  initColors();
}

NCursesDisplay::~NCursesDisplay() {
  echo();
  endwin();
}

void  NCursesDisplay::_getKey() {
  int key = getch();

  switch (key) {

    case 27:
      Monitor::getInstance()->stop();
      break;

    case KEY_RIGHT:
      break;

    case KEY_LEFT:
      break;

    case KEY_UP:
      break;

    case KEY_DOWN:
      break;

    case ' ':
      Monitor::getInstance()->pause();
      break;
  }
}


void NCursesDisplay::draw() {
  erase();
  refresh();
}

void NCursesDisplay::refresh() {
  _getKey();
}


void NCursesDisplay::draw(IMonitorModule&) {

}

void NCursesDisplay::draw(TextItem&) {

}

void NCursesDisplay::draw(HorizontalBarItem&) {

}
