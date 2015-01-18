
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


#include "RamModule.hpp"

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
      _scrollY++;
      break;

    case KEY_DOWN:
      _scrollY--;
      break;

    case 'r':
      Monitor::getInstance()->addModule(new RamModule());
      break;

    case ' ':
      Monitor::getInstance()->pause();
      break;
  }
}


void NCursesDisplay::draw() {
  erase();

  std::list<IMonitorModule*>& modules = Monitor::getInstance()->getModules();

  int posY = _scrollY;

  std::list<IMonitorModule*>::iterator module;

  for (module = modules.begin(); module != modules.end(); module++) {
    int height = (*module)->getHeight();
    (*module)->draw(*this, 1, posY);
    posY += height + 1;
  }

  refresh();
}

void NCursesDisplay::drawRectangle(int x, int y, int width, int height, int color) {
  int y1 = y;

  attron(COLOR_PAIR(color));

  mvhline(y, x, ACS_HLINE, width);
  mvhline(y + height, x, ACS_HLINE, width + 1);
  
  if (y < 0)
    y1 = 0;

  mvvline(y1, x, ACS_VLINE, height + y - y1);
  mvvline(y1, x + width, ACS_VLINE, height + y - y1);
  
  mvaddch(y, x, ACS_ULCORNER);
  mvaddch(y, x + width, ACS_URCORNER);
  mvaddch(y + height, x, ACS_LLCORNER);
  mvaddch(y + height, x + width, ACS_LRCORNER);

  attroff(COLOR_PAIR(color));
}

void NCursesDisplay::drawText(int x, int y, const char* text, int color) {
  move(y, x);
  attron(COLOR_PAIR(color));
  printw(text);
  attroff(COLOR_PAIR(color));
}

void NCursesDisplay::refresh() {
  _getKey();
}

