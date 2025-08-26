#ifndef EXCEPTWRONGINP_HPP
#define EXCEPTWRONGINP_HPP

#include <stdexcept>

class ExceptWrongInp: public std::exception{
	public:
		const char *what() const throw();
};

#endif