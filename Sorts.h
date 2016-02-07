/**
*	@file:Sorts.h
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose:To take in arguments and either create a file with numbers in it or sort a file and output how long it took.
*/
#ifndef SORTS_H
#define SORTS_H

#include <functional>
#include <cassert>
#include <chrono>
#include <ctime>
#include <random>

template <typename T>
class Sorts {

public:
/**
*	@pre: None
*	@post: Sorts the taken in array with Insertion Sort.
*	@return: None
*/
	static void insertionSort(T arr[], int size);
/**
*	@pre: None
*	@post:	Sorts the taken in array with Bubble Sort.
*	@return: None
*/
	static void bubbleSort(T arr[], int size);
/**
*	@pre: None
*	@post:	Sorts the taken in array with Merge sort, using the merge method.
*	@return: None
*/
	static void mergeSort(T arr[], int size);
/**
*	@pre: None
*	@post:	Passes the array and size to the quickSortRec method with the median flag set to false.
*	@return: None
*/
	static void quickSort(T arr[], int size);
/**
*	@pre: None
*	@post:	Passes the array and size to the quickSortRec method with the median flag set to true.
*	@return: None
*/
	static void quickSortMedian(T arr[], int size);
/**
*	@pre: None
*	@post:	Sorts the taken in array with the Selection Sort algorithm.
*	@return: None
*/
	static void selectionSort(T arr[], int size);
/**
*	@pre: None
*	@post:	None
*	@return: True if the taken in array is in ascending order, false otherwise.
*/
	static bool isSorted(T arr[], int size);
/**
*	@pre: arr is a valid array of T of size elements, < is overloaded for T, and sort is capable of sorting the array
*	@post:	None
*	@return: The time taken to sort the array in seconds
*/
	static double sortTimer(std::function<void(T[], int)> sort, T arr[], int size);
private:
/**
*	@pre: None
*	@post:	Used in merge sort. Takes in two sorted arrays and merges them into one sorted array.
*	@return: None
*/
	static void merge(T* a1, T* a2, int size1, int size2);
/**
*	@pre: None
*	@post:	Partitions the array with median set to true or false, then recursively calls itself on the left and right halves.
*	@return: None
*/
	static void quickSortRec(T arr[], int first, int last, bool median);
/**
*	@pre: None
*	@post:	Changes the last value of the array to the median of the first, middle, and last values.
*	@return: None
*/
	static void setMedianPivot(T arr[], int first, int last);
/**
*	@pre: None
*	@post:	Partitions the array with the last value set as the pivot if median is false, and the median value if median is true. All values to the left of pivot are less than in, and all values to the right are greater.
*	@return: None
*/
	static int partition(T arr[], int first, int last, bool median);
/**
*	@pre: None
*	@post:	Randomly shuffles the taken in array.
*	@return: None
*/
	static void shuffle(T arr[], int size);

};

#include "Sorts.hpp"

#endif
