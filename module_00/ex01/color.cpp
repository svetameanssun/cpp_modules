#include "phonebook.hpp"


void Color::set_theme(std::string theme)
{
    reset = "\033[0m";
    bold = "\033[1m";

    if (theme == "meadow")
    {
        colorWarm = "\033[38;2;22;180;126m";
        colorCalm = "\033[38;2;91;216;187m";
        colorPale = "\033[38;2;156;232;214m";
        colorVibr = "\033[38;2;37;181;205m";
        errorRed = "\033[38;2;240;122;118m";
    }
    else if (theme == "bubble")
    {
        colorWarm = "\033[38;2;255;136;136m";
        colorCalm = "\033[38;2;255;179;207m";
        colorPale = "\033[38;2;162;224;255m";
        colorVibr = "\033[38;2;234;136;242m";
        errorRed = "\033[38;2;222;1;0m";
    }
    else if (theme == "sunset")
    {
        colorWarm = "\033[38;2;255;158;151m";
        colorCalm = "\033[38;2;255;198;184m";
        colorPale = "\033[38;2;255;232;215m";
        colorVibr = "\033[38;2;255;120;113m";
        errorRed = "\033[38;2;255;61;71m";
    }
    else if (theme == "default")
    {
        colorWarm = "\033[1;34m";
        colorCalm = "\033[1;35m";
        colorPale = "\033[1;36m";
        colorVibr = "\033[1;33m";
        errorRed = "\033[1;31m";
    }
    else
    {
        throw WrongArgException();
    }
    
}


std::string Color::getWarm()
{
    return (colorWarm);
}

std::string Color::getCalm(){
    return (colorCalm);
}

std::string Color::getPale(){
    return (colorPale);
}

std::string Color::getVibr(){
    return (colorVibr);
}

std::string Color::getRed(){
    return (errorRed);
}

std::string Color::getBold(){
    return (bold);
}

std::string Color::getReset(){
    return (reset);
}