
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef INFO_HPP
#define INFO_HPP

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/vmmeter.h>
#include <iostream>
#include <cstring>
#include <string>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <ctime>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
    
class Info {

public:
  Info(void);
  Info(Info const & src);
  ~Info(void);

  Info & operator=(Info const & src);

  unsigned int  getInfoByFlag(int f1, int f2);
  std::string   getInfoByFlagString(int f1, int f2);
  unsigned int  getInfoByName(std::string name);
  std::string   getInfoByNameString(std::string name);
  std::string   getUserName(void);


protected:


private:


};

#endif
