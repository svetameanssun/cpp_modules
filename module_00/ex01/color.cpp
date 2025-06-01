#include "phonebook.hpp"


void Color::setTheme(std::string theme)
{
    reset = "\033[0m";
    bold = "\033[1m";

    if (theme == "meadow")
    {
        colorWarm = "\033[38;2;128;192;40m"; // (128,192,40)
        colorCalm = "\033[38;2;118;0;161m"; // (118,0,161)
        colorPale = "\033[38;2;141;255;0m"; // (141,255,0) 	
        colorVibr = "\033[38;2;0;255;255m"; //  (0,255,255)
        errorRed = "\033[38;2;238;0;140m"; // (238,0,140)
    }
    else if (theme == "bubble")
    {
        colorWarm = "\033[38;2;1;205;254m"; // (1,205,254)
        colorCalm = "\033[38;2;185;103;255m"; // (185,103,255)
        colorPale = "\033[38;2;255;251;150m"; // (255,251,150)
        colorVibr = "\033[38;2;5;255;161m"; // (5,255,161)
        errorRed = "\033[38;2;255;113;206m";  // (255,113,206)
    }
    else if (theme == "sunset")
    {
        colorWarm = "\033[38;2;167;197;27m"; // (167,197,27)
        colorCalm = "\033[38;2;81;155;229m"; // (254,132,2) (81,155,229)
        colorPale = "\033[38;2;254;130;153m"; // (254,130,153)
        colorVibr = "\033[38;2;254;234;17m"; // (254,234,17)
        errorRed = "\033[38;2;254;2;123m"; // 	(254,2,123)
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


std::string Color::getWarm() const
{
    return (colorWarm);
}

std::string Color::getCalm() const{
    return (colorCalm);
}

std::string Color::getPale() const{ 
    return (colorPale);
}

std::string Color::getVibr() const{
    return (colorVibr);
}

std::string Color::getRed() const{
    return (errorRed);
}

std::string Color::getBold() const{
    return (bold);
}

std::string Color::getReset() const{
    return (reset);
}