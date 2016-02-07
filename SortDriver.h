/**
*	@file:NumberFileGenerator.h
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose:Takes in arguments and if they are valid, opens a file with a list of numbers in it, turns it into an array, sorts it in the appropriate way, and prints the timing data to an output file.
*/
#ifndef SORTDRIVER_H
#define SORTDRIVER_H

#include <string>
#include <fstream>
#include <iostream>
#include "Sorts.h"

class SortDriver {

public:
/**
*	@pre: argv is a valid 2-D array.
*	@post: If the arguments are valid, sorts the array in the input file and outputs the timing information to the output file.
*	@return: None
*/
	static void run(int argc, char** argv);
/**
*	@pre: None
*	@post: Prints the help menu to help with valid arguments.
*	@return: None
*/
	static void printHelpMenu();
private:
/**
*	@pre: The file was created by a NumberFileGenerator
*	@post: None
*	@return: True if the file exist, false otherwise.
*/
	static bool isFileAccessible(std::string fileName);
/**
*	@pre: None
*	@post: None
*	@return: True if the sort parameter is valid, false otherwise.
*/
	static bool isSortValid(std::string sortParameter);
/**
*	@pre: None
*	@post: None
*	@return: True if the file exists and the parameter is valid, false otherwise.
*/
	static bool areParametersValid(std::string sortName, std::string inputFileName);
/**
*	@pre: The file was created by a NumberFileGenerator
*	@post: The first line of the file is read in.
*	@return: The amount of numbers in the file.
*/
	static int getFileCount(std::ifstream& inputFile);
/**
*	@pre: The file was created by a NumberFileGenerator, with the read in size being correct.
*	@post: The rest of the file is read in. Does not close the file.
*	@return: A pointer to a new array with all of the numbers from the input file.
*/
	static int* createArray(std::ifstream& inputFile, int size);
/**
*	@pre: Original and copy are both valid arrays of the same size.
*	@post: All values from the original array are copied into copy.
*	@return: None
*/
	static void copyArray(int original[], int copy[], int size);
};

#endif
