#include <iostream>
#include <map>

int main() {
  // Creating a map with character keys and integer values
  std::map<std::string, int> charMap;

  // Inserting elements into the map
  charMap["2012-01-11"] = 1;
  charMap["2012-01-13"] = 2;
  charMap["2012-01-15"] = 3;
  charMap["2012-01-17"] = 5;

  // Displaying the original map
  std::cout << "Map contents:" << std::endl;
  std::map <std::string, int>::iterator start = charMap.begin();
  for (;start !=charMap.end(); start++){
    std::cout << start->first << " : " << start->second << std::endl;
  }

  // Finding the lower bound for key 'd'
  std::map<std::string, int>::iterator it = charMap.lower_bound("2012-01-14");

  if (it == charMap.end() || it->first != "2012-01-14") {
    // Проверяем, не является ли найденный элемент самым первым в контейнере
    if (it != charMap.begin()) {
        --it; // Делаем шаг назад к "2012-01-13"
    } else {
        // Если it == begin(), значит записей до этой даты в базе нет
        it = charMap.end(); 
    }
  }

  if (it != charMap.end()) {
    std::cout << "Lower bound for '2012-01-14': " << it->first << " : " << it->second << std::endl;
  } else {
    std::cout << "'d' not found in the map." << std::endl;
  }

  return 0;
}
