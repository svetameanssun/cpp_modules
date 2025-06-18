#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> // Для std::cout
# include <string>

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        static int getFractionalBits();
        ~Fixed();
    private:
        int _value;
        static const int _fractionalBits;
};

#endif