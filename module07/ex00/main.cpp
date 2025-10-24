/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:41:37 by stitovsk          #+#    #+#             */
/*   Updated: 2025/10/22 19:47:36 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
      
int main(void) {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, bzzzzzz ) = " << ::max(a, b) << std::endl;
  //wrong input
  //----------------------
  //std::string c = "abcde";
  //double d = 14.0;
  //----------------------
  std::string c = "abcde";
  std::string d = "14.0";
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  std::string e = "Hola";
  std::string f = "adios";
  ::swap(e, f);
  std::cout << "e = " << c << ", f = " << d << std::endl;
  std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
  std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;

  return 0;
}
