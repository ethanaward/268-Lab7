/**
*	@file:NumberFileDriver.h
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose:To take in arguments and if the arguments are valid, create a file with the specified number of values in the specified order. If the arguments are not valid, prints the help menu.
*/
#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H

#include <string>
#include <iostream>
#include "NumberFileGenerator.h"

class NumberFileDriver {

public:
/**
*	@pre: argv is a valid 2-D array.
*	@post: If the arguments are valid, creates a file with numbers according to the arguments. If not valid, prints the help menu.
*	@return: None
*/
	static void run(int argc, char** argv);
/**
*	@pre: None
*	@post: Prints the help menu for help on valid command line arguments.
*	@return: None
*/
	static void printHelpMenu();
private:
/**
*	@pre: None
*	@post: None
*	@return: True if the passed in option is valid, false if not.
*/
	static bool isValidOption(std::string option);
};

#endif
