/**
*	@file:Sorts.hpp
*	@author: Ethan Ward
*	@date:2014.04.10
*	@purpose: Implements the methods detailed in Sorts.h
*/
template <typename T>
void Sorts<T>::insertionSort(T arr[], int size) {

	T tempValue = T();
	int j;

	for(int i = 1; i < size; i++) {
		j = i-1;
		tempValue = arr[i];
		while(j >= 0 && arr[j] > tempValue) {
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = tempValue;
	}

	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size) {

	bool isSorted = false;
	T tempValue = T();
	
	while(!isSorted) {
		isSorted = true;

		for(int i = 0; i < size; i++) {
			if(arr[i] > arr[i+1]) {
				tempValue = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = tempValue;
				isSorted = false;
			}
		}
	}


	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::mergeSort(T arr[], int size) {

	if(size !=0 && size !=1) {
		int mid = size/2;
		mergeSort(arr, mid);
		mergeSort(arr + mid, size-mid);
		merge(arr, arr + mid, mid, size-mid);
	}

	else {
		return;
	}

	assert( isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size) {

	if(size <= 1) {
		return;
	}
	
	else {
		quickSortRec(arr,0,size-1,false);	
	}

	assert( isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::quickSortMedian(T arr[], int size) {

	if(size <= 1) {
		return;
	}
	
	else {
		quickSortRec(arr,0,size-1,true);		
	}

	assert( isSorted(arr, size) );
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size) {

	T minValue = T();
	T tempValue = T();	

	for(int i = 0; i < size; i++) {
		minValue = i;
		for(int j = i; j < size; j++) {
			if(arr[j] < arr[minValue]) {
				minValue = j;
			}
		}	
		tempValue = arr[i];
		arr[i] = arr[minValue];
		arr[minValue] = tempValue;
	}

	assert( Sorts<T>::isSorted(arr, size) );
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size) {

	if(size <=1) {
		return(true);
	}

	for(int i = 0; i < size-1; i++) {
		if(arr[i] > arr[i+1]) {
			return false;
		}
	}

	
	return(true);
}

template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[], int)> sort, T arr[], int size) {

	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;

	start = std::chrono::system_clock::now();
	sort(arr, size);
	end = std::chrono::system_clock::now();
	elapsed = (end - start);

	return(elapsed.count());
}

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2) {

	T* fullArr = new T[size1+size2];
	T* temp = a1;
	int fullSize = size1 + size2;
	int i = 0;
	int j = 0;
	int k = 0;

	while(size1 > 0 && size2 > 0) {
		if(a1[j] <= a2[k]) {
			fullArr[i] = a1[j];
			i++;
			j++;
			size1--;
		}

		else {
			fullArr[i] = a2[k];			
			k++;
			i++;	
			size2--;
		}
	}
	
	while(size1 > 0) {
		fullArr[i] = a1[j];
		j++;
		i++;
		size1--;
	}	

	while(size2 > 0) {
		fullArr[i] = a2[k];
		k++;
		i++;
		size2--;
	}	

	

	for(int l = 0; l < fullSize; l++) {
		a1[l] = fullArr[l];
	}

	delete [ ] fullArr;


}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median) {

	if(last-first <= 1) {
		return;
	}

	else {
		int piv = partition(arr, first, last, median);
		quickSortRec(arr, first, piv-1, median);
		quickSortRec(arr, piv+1, last, median);
	}

}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last) {

	int mid = (last-first)/2;
	T median = arr[mid];
	T tempValue = T();
	
	if(median <= arr[last] && median <= arr[first]) {
		if(arr[last] > arr[first]) {
			mid = first;
		}
		else {
			return;
		}
	}

	else if(median >= arr[last] && median >= arr[first]) {
		if(arr[first] > arr[last]) {
			mid = first;
		}
		else {
			return;
		}
	}

	tempValue = arr[mid];
	arr[mid] = arr[last];
	arr[last] = tempValue;

}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median) {

	int left = 0;
	int right = last - 1;
	T tempValue = T();

	if(median) {
		setMedianPivot(arr, first, last);
	}

	while(left < right) {
		while(arr[left] < arr[last]) {
			left++;	
		}	
		while(arr[right] > arr[last]) {
			right--;
		}
		
		if(left <= right) {
			tempValue = arr[left];
			arr[left] = arr[right];
			arr[right] = tempValue;	
		}
	
	}	
	if(arr[last] < arr[left]) {
		tempValue = arr[left];
		arr[left] = arr[last];
		arr[last] = tempValue;
	}
	
	return(left);

}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size) {

	T tempValue = T();
	int tempPlace = 0;
	std::uniform_int_distribution<int> distribution(0,size-1);
	std::default_random_engine generator(time(nullptr));


	for(int i = 0; i < size; i++) {
		tempPlace = distribution(generator);
		tempValue = arr[tempPlace];
		arr[tempPlace] = arr[i];
		arr[i] = tempValue;
	}
}
