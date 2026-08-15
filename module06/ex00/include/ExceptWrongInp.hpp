#ifndef EXCEPTWRONGINP_HPP
#define EXCEPTWRONGINP_HPP

#include <stdexcept>

class ExceptWrongInp: public std::exception{
	public:
		ExceptWrongInp();
		ExceptWrongInp(const ExceptWrongInp &other);
		~ExceptWrongInp() throw();
		ExceptWrongInp &operator=(const ExceptWrongInp &other);
		const char *what() const throw();
	private:
};

#endif