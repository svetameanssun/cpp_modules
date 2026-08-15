/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:38:58 by stitovsk          #+#    #+#             */
/*   Updated: 2026/03/31 17:39:13 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:

    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other) {
        std::stack<T>::operator=(other);
        return *this;
    }
    //I want to create a shortcut name called iterator for a very long type.
    //alias
    typedef typename std::stack<T>::container_type::iterator iteraty;

    iteraty begin() { return this->c.begin(); }
    iteraty end() { return this->c.end(); }

    typedef typename std::stack<T>::container_type::const_iterator consty_iteraty;
    consty_iteraty begin() const { return this->c.begin(); }
	consty_iteraty end() const { return this->c.end(); }

};

#endif

