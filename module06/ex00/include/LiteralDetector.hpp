#ifndef LITERALDETECTOR_HPP
#define LITERALDETECTOR_HPP

class LiteralDetector{
  public:
    enum Type {CHAR, INT, FLOAT, DOUBLE, UNKNOWN};
    static bool isChar(std::string str);
    static bool isInt(std::string str);
    static bool isFloat(std::string str);
    static bool isDouble(std::string str);
  private:
    LiteralDetector(){};
    ~LiteralDetector(){};    
};

#endif
