/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:33:28 by stitovsk          #+#    #+#             */
/*   Updated: 2025/10/22 19:33:29 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

class Awesome {
 public:
  Awesome(void) : _n(42) { return; }
  int get(void) const { return this->_n; }

 private:
  int _n;
};

std::ostream& operator<<(std::ostream& o, Awesome const& rhs) {
  o << rhs.get();
  return o;
}

template <typename T>
void print(T& x) {
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = {0, 1, 2, 3, 4};
  Awesome tab2[5];

  const int len = 5;

  iter(tab, len, print<const int>);
  iter(tab2, len, print<Awesome>);

  return 0;
}
