/**
*	@file:NumberFileGenerator.cpp
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose:Implements the methods detailed in NumberFileGenerator.h.
*/
#include "NumberFileGenerator.h"

void NumberFileGenerator::ascending(std::string fileName, int amount) {

	std::ofstream oFile(fileName);
	
	oFile << amount << "\n";
	for(int i = 0; i < amount; i++) {
		oFile << i << "\n";
	}

	oFile.close();

	std::cout << amount << " numbers stored in " << fileName;
	
}

void NumberFileGenerator::descending(std::string fileName, int amount) {

	std::ofstream oFile(fileName);

	oFile << amount << "\n";
	for(int i = amount; i > 0; i--) {
		oFile << i << "\n";
	}
	
	oFile.close();

	std::cout << amount << " numbers stored in " << fileName;

}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max) {


	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min, max);
	int* tempArray = new int[amount];

	for(int i = 0; i < amount; i++) {
		tempArray[i] = distribution(generator);
	}

	std::ofstream oFile(fileName);

	oFile << amount << "\n";
	for(int i = 0; i < amount; i++) {
		oFile << tempArray[i] << "\n";
	}
	
	oFile.close();	

	std::cout << amount << " numbers stored in " << fileName;

}

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value) {

	std::ofstream oFile(fileName);
	
	oFile << amount << "\n";
	for(int i = 0; i < amount; i++) {
		oFile << value << "\n";
	}
	oFile.close();

	std::cout << amount << " numbers stored in " << fileName;

}
