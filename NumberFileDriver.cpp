/**
*	@file:NumberFileDriver.cpp
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose:Implements the methods detailed in NumberFileDriver.h.
*/
#include "NumberFileDriver.h"

void NumberFileDriver::run(int argc, char** argv) {

	NumberFileGenerator nfg = NumberFileGenerator();
	bool check = isValidOption(argv[2]);
	int size = atoi(argv[4]);

	if(check) {
		if((std::string)argv[2] == "-a") {
			nfg.ascending(argv[3], size);
		}
		
		else if((std::string)argv[2] == "-d") {
			nfg.descending(argv[3], size);
		}
		
		else if((std::string)argv[2] == "-s") {
			int size2 = atoi(argv[5]);
			nfg.singleValue(argv[3], size, size2);
		}	
		
		else if((std::string)argv[2] == "-r") {
			int size2 = atoi(argv[5]);
			int size3 = atoi(argv[6]);
			nfg.random(argv[3], size, size2, size3);
		}	
	}

	else {
		printHelpMenu();
	}

}

void NumberFileDriver::printHelpMenu() {
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}

bool NumberFileDriver::isValidOption(std::string option) {
	
	if(option == "-a" || option == "-d" || option == "-s" || option == "-r") {
		return(true);
	}

	else {
		return(false);
	}
}
