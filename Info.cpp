
      /*#######.
     ########",#:
   #########',##".
  ##'##'## .##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include "Info.hpp"

Info::Info(void)
{
}

Info::Info(Info const & src)
{
  *this = src;
}

Info::~Info(void)
{
}

Info & Info::operator=(Info const & src)
{
  *this = src;
  return (*this);
}

unsigned int            Info::getInfoByFlag(int f1, int f2)
{
  int mib[2] = { f1, f2 };
    u_int namelen = sizeof(mib) / sizeof(mib[0]);
    unsigned int  v;
    size_t len = sizeof(v);

    sysctl(mib, namelen, &v, &len, NULL, 0);
    return v;
}

std::string            Info::getInfoByFlagString(int f1, int f2)
{
  int mib[2] = { f1, f2 };
    u_int namelen = sizeof(mib) / sizeof(mib[0]);
    char  v[1024];
    size_t len = sizeof(v);

    sysctl(mib, namelen, &v, &len, NULL, 0);
    return v;
}

unsigned int            Info::getInfoByName(std::string name)
{
  char * cstr = new char [name.length()+1];

    unsigned int       result;
    size_t  len = sizeof(result);

  std::strcpy (cstr, name.c_str());

    sysctlbyname(cstr, &result, &len, 0, 1024);
    return result;
}

std::string           Info::getInfoByNameString(std::string name)
{
  char result[1024];
    size_t len = sizeof(result);
    char * cstr = new char [name.length()+1];

  std::strcpy (cstr, name.c_str());
    sysctlbyname(cstr, &result, &len, 0, 1024);
    return result;
}

std::string       Info::getUserName(void)
{
  register struct passwd *pw;
  register uid_t uid;

  uid = getuid();
  pw = getpwuid(uid);
  if (pw)
    return (pw->pw_name);
  return (NULL);
}
