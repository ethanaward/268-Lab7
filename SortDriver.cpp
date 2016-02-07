/**
*	@file:SortDriver.cpp
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose:Implements the methods described in SortDriver.h
*/
#include "SortDriver.h"

void SortDriver::run(int argc, char** argv) {

	Sorts<int> sort = Sorts<int>();
	bool check = areParametersValid(argv[2],argv[3]);
	double time;
	std::function<void(int[], int)> bSort = sort.bubbleSort;
	std::function<void(int[], int)> sSort = sort.selectionSort;
	std::function<void(int[], int)> iSort = sort.insertionSort;
	std::function<void(int[], int)> qSort = sort.quickSort;
	std::function<void(int[], int)> q3Sort = sort.quickSortMedian;
	std::function<void(int[], int)> mSort = sort.mergeSort;
	
	if(check) {
		if((std::string)argv[2] == "-bubble") {
			std::ifstream iFile(argv[3]);
			int size = getFileCount(iFile);
			int* array = createArray(iFile, size);
			time = sort.sortTimer(bSort, array, size);
			iFile.close();
			std::ofstream oFile(argv[4]);
			oFile << "Bubble Sort sorted " << size << 				" numbers in " << time << " seconds."; 
			oFile.close();
			delete [ ] array;
		}
		
		else if((std::string)argv[2] == "-selection") {
			std::ifstream iFile(argv[3]);
			int size = getFileCount(iFile);
			int* array = createArray(iFile, size);
			time = sort.sortTimer(sSort, array, size);
			iFile.close();
			std::ofstream oFile(argv[4]);
			oFile << "Selection Sort sorted " << size 				<<" numbers in " << time << " seconds."; 
			oFile.close();
			delete [ ] array;
		}
		
		else if((std::string)argv[2] == "-insertion") {
			std::ifstream iFile(argv[3]);
			int size = getFileCount(iFile);
			int* array = createArray(iFile, size);
			time = sort.sortTimer(iSort, array, size);
			iFile.close();
			std::ofstream oFile(argv[4]);
			oFile << "Insertion Sort sorted " << size 				<<" numbers in " << time << " seconds."; 
			oFile.close();
			delete [ ] array;
		}	
		
		else if((std::string)argv[2] == "-quick") {
			 std::ifstream iFile(argv[3]);
			int size = getFileCount(iFile);
			int* array = createArray(iFile, size);
			time = sort.sortTimer(qSort, array, size);
			iFile.close();
			std::ofstream oFile(argv[4]);
			oFile << "Quick Sort sorted " << size << 				" numbers in " << time << " seconds."; 
			oFile.close();
			delete [ ] array;
		}	

		else if((std::string)argv[2] == "-quick3") {
			std::ifstream iFile(argv[3]);
			int size = getFileCount(iFile);
			int* array = createArray(iFile, size);
			time = sort.sortTimer(q3Sort, array, size);
			iFile.close();
			std::ofstream oFile(argv[4]);
			oFile << "Quick Sort(with median) sorted 				" << size <<" numbers in " << time << 				" seconds."; 
			oFile.close();
			delete [ ] array;
		}

		else if((std::string)argv[2] == "-merge") {
			std::ifstream iFile(argv[3]);
			int size = getFileCount(iFile);
			int* array = createArray(iFile, size);
			time = sort.sortTimer(mSort, array, size);
			iFile.close();
			std::ofstream oFile(argv[4]);
			oFile << "Merge Sort sorted 				" << size <<" numbers in " << time << 				" seconds."; 
			oFile.close();
			delete [ ] array;
		}

		else if((std::string)argv[2] == "-all") {
			std::cout << "l";
			std::ifstream iFile(argv[3]);
			int size = getFileCount(iFile);
			int* array = createArray(iFile, size);
			iFile.close();

			int* sArray = new int[size];
			int* iArray = new int[size];;
			int* qArray = new int[size];;
			int* q3Array = new int[size];;
			int* mArray = new int[size];;
	
			copyArray(array,iArray,size);
			copyArray(array,qArray,size);
			copyArray(array,q3Array,size);
			copyArray(array,mArray,size);
			copyArray(array,sArray,size);
			
			time = sort.sortTimer(bSort, array, size);
			std::ofstream oFile(argv[4]);
			oFile << "Bubble Sort sorted 				" << size <<" numbers in " << time << 				" seconds."; 

			time = sort.sortTimer(sSort, sArray, size);
			oFile << "Selection Sort sorted " << size 				<<" numbers in " << time << " seconds."; 

			time = sort.sortTimer(iSort, iArray, size);
			oFile << "Insertion Sort sorted " << size 				<<" numbers in " << time << " seconds."; 
			

			time = sort.sortTimer(qSort, qArray, size);
			oFile << "Quick Sort sorted " << size 				<<" numbers in " << time << " seconds."; 
			
			time = sort.sortTimer(q3Sort, q3Array, size);
			oFile << "Quick Sort(with median) sorted " << size 				<<" numbers in " << time << " seconds."; 

			time = sort.sortTimer(mSort, mArray, size);
			oFile << "Merge Sort sorted " << size 				<<" numbers in " << time << " seconds."; 
			oFile.close();

			delete [ ] array;
			delete [ ] sArray;
			delete [ ] iArray;
			delete [ ] qArray;
			delete [ ] q3Array;
			delete [ ] mArray;
			
		}

		
	}

	else {
		printHelpMenu();
	}

}

void SortDriver::printHelpMenu() {
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";
}

bool SortDriver::isFileAccessible(std::string FileName) {
	
	std::ifstream iFile(FileName);
	
	if(iFile.good()) {
		iFile.close();
		return(true);
	}

	else {
		iFile.close();
		return(false);
	}
}

bool SortDriver::isSortValid(std::string sortParameter) {
	
	if(sortParameter == "-bubble" || sortParameter == "-selection" || sortParameter == "-insertion" || sortParameter == "-quick" || sortParameter == "-quick3" || sortParameter == "-merge" || sortParameter == "-all") {
		return(true);
	}

	else {
		return(false);
	}
}

bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName) {
	
	if(isFileAccessible(inputFileName) && isSortValid(sortName)) {		
		return(true);
	}

	else {
		return(false);
	}
}

int SortDriver::getFileCount(std::ifstream& inputFile) {
	
	int value;
	inputFile >> value;
	return(value);

}

int* SortDriver::createArray(std::ifstream& inputFile, int size) {

	int* nums = new int[size];

	for(int i = 0; i < size; i++) {
		inputFile >> nums[i];
	}

	return(nums);


}

void SortDriver::copyArray(int original[], int copy[], int size) {

	for(int i = 0; i < size; i++) {
		copy[i] = original[i];
	}

}
