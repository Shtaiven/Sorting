/*
Program 2: Sorting and Time Complexity
By Steven Eisinger

Sources:
http://en.wikibooks.org/wiki/Algorithm_Implementation
GitHub user luigi1015 for quicksort.cpp

*/
#include "quicksort.cpp"
#include "mergesort.cpp"
#include "shellsort.cpp"
#include "insertionsort.cpp"
#include "heapsort.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    ifstream fin("10000 unsorted"); // make this variable so you can input any file name
    vector<double> vec;
 
    // Input from file into vector
    copy(istream_iterator<double>(fin), istream_iterator<double>(), back_inserter(vec));

	// Quicksort
	vector<double> quicksort_result = vec;
	QuickSort::quickSort<double>(quicksort_result, 0, vec.size()-1);

	// Mergesort
	vector<double> mergesort_result = mergesort(vec);

	// Heapsort
	vector<double> heapsort_result = vec;
	heapSort(heapsort_result.begin(), heapsort_result.end());

	// Insertionsort
	vector<double> insertionsort_result = vec;
	insertionSort(insertionsort_result,insertionsort_result.size()-1);

	// Shellsort
	vector<double> shellsort_result = vec;
	shellSort(shellsort_result,shellsort_result.size()-1);

	return 0;
}