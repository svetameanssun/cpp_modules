#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <map>
#include <iostream>

class Harl {
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    std::map<std::string, void (Harl::*)(void)> levelFunctions;

  public:
    Harl();
    void complain(std::string level);
};

#endif