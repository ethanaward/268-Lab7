/**
*	@file:NumberFileGenerator.h
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose:Writes to files lists of numbers in various orders: random, ascending, descending, and single values.
*/
#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H

#include <string>
#include <fstream>
#include <ctime>
#include <random>
#include <iostream>

class NumberFileGenerator {

public:
/**
*	@pre: fileName is a valid file name. amount is > 0.
*	@post: Creates a file with the amount of numbers in ascending order, with the amount of numbers as the first entry.
*	@return: None
*/
	static void ascending(std::string fileName, int amount);
/**
*	@pre: fileName is a valid file name. amount is > 0.
*	@post: Creates a file with the amount of numbers in descending order, with the amount of numbers as the first entry.
*	@return: None
*/
	static void descending(std::string fileName, int amount);
/**
*	@pre: fileName is a valid file name. amount is > 0.
*	@post: Creates a file with the amount of numbers in random order, with the given min and max values, and with the amount of numbers as the first entry.
*	@return: None
*/
	static void random(std::string fileName, int amount, int min, int max);
/**
*	@pre: fileName is a valid file name. amount is > 0.
*	@post: Creates a file with the taken in value amount number of times, with the amount of numbers as the first entry.
*	@return: None
*/
	static void singleValue(std::string fileName, int amount, int value);
};

#endif
