/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:33:40 by stitovsk          #+#    #+#             */
/*   Updated: 2025/10/22 19:33:41 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>  // time

/*#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/

int main()
{
	try{
		Array<int> intArray(5);
		for (size_t i = 0; i < intArray.size(); ++i) 
		{
			intArray[i] = i *10;
		}
		std::cout << "Integer Array:" << std::endl;
		for (size_t i = 0; i < intArray.size(); ++i) 
		{
			std::cout << intArray[i] << std::endl;
		}

		Array<std::string> strArray(3);
		strArray[0] =  "Hello";
		strArray[1] = "World";
		strArray[2] =  "C++";
		int a = 1;
		std::cout << "getting: " << strArray[a] << std::endl;
		std::cout << "\nString Array:" << std::endl;
		for (size_t i = 0; i < strArray.size(); ++i) 
		{
			std::cout << strArray[i] << std::endl;
		}

		std::cout << "\nAccessing out of bounds index:" << std::endl;
		std::cout << intArray[10] << std::endl; // This should throw an exception
	}
	catch (const std::out_of_range& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}