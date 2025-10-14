#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(){

	Data *myData = new Data;
	myData->myFullName = "Svetlana";
	myData->myAge = 32;
	uintptr_t raw = Serializer::serialize(myData);
	Data *ptr = Serializer::deserialize(raw);
	std::cout << ptr->myFullName << ", "<<ptr->myAge << std::endl;
	delete myData;
}