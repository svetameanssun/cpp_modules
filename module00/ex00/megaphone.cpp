/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:46:18 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/18 12:09:08 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype> // isalpha, islower, toupper
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return (1);
  }

  char c;
  for (int i = 1; i < argc; ++i) {
    for (int j = 0; argv[i][j]; ++j) {
      c = argv[i][j];
      if (std::isalpha(c) && std::islower(c)) {
        c = std::toupper(c);
      }
      std::cout << c;
    }
    if (argv[i + 1]) {
      std::cout << " ";
    }
  }
  std::cout << "\n";
  return (0);
}
