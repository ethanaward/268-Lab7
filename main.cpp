/**
*	@file:main.cpp
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose:To take in arguments and either create a file with numbers in it or sort a file and output how long it took.
*/

#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include <string>
#include "SortDriver.h"
#include "NumberFileDriver.h"

int main(int argc, char** argv) {


bool size = argc >= 5;
std::string mode = argv[1];
bool first = (mode == "-create" || mode == "-sort");





if(size && first) {

	if(mode == "-create") {
		NumberFileDriver::run(argc, argv);
	}

	else if(mode == "-sort") {
		
		SortDriver::run(argc,argv);
	}
}

else {
	NumberFileDriver::printHelpMenu();
	SortDriver::printHelpMenu();
}

};

#endif
