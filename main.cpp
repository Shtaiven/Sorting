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
#include <chrono>
#include <string>

using namespace std;

int main()
{
	string filename = " ";
	cout << "Enter filename: ";
	getline(cin, filename);

	// Open the file
    ifstream fin(filename);

    // Error Handler
    if (fin.fail()) {
    	cerr << "Error opening file" << endl;
    	exit(1);
    }

	// Initialize the vector which will store the unsorted file
    vector<double> vec; 
 
    // Input from file into vector
    copy(istream_iterator<double>(fin), istream_iterator<double>(), back_inserter(vec));

    // Initialize clock variables
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed_seconds;

	// Insertionsort
	vector<double> insertionsort_result = vec;

	start = chrono::system_clock::now(); // set beginning of system clock
	insertionSort(insertionsort_result,insertionsort_result.size()-1);
	end = chrono::system_clock::now(); // set end of system clock
	elapsed_seconds = end-start;
	cout << "Insertionsort time:                                      " << elapsed_seconds.count() << "s\n";

	// Shellsort
	vector<double> shellsort_result = vec;

	start = chrono::system_clock::now(); // set beginning of system clock
	shellSort(shellsort_result,shellsort_result.size()-1);
	end = chrono::system_clock::now(); // set end of system clock
	elapsed_seconds = end-start;
	cout << "Shellsort time:                                          " << elapsed_seconds.count() << "s\n";

	// Quicksort using rightmost key
	vector<double> quicksortR_result = vec; 

	start = chrono::system_clock::now(); // set beginning of system clock
	quicksort::quickSortRight<double>(quicksortR_result, 0, vec.size()-1);
	end = chrono::system_clock::now(); // set end of system clock
	elapsed_seconds = end-start;
	cout << "Quicksort (right pivot) time:                            " << elapsed_seconds.count() << "s\n";

	// Quicksort using median key of 3
	vector<double> quicksortM_result = vec; 

	start = chrono::system_clock::now(); // set beginning of system clock
	quicksort::quickSortMedian<double>(quicksortM_result, 0, vec.size()-1);
	end = chrono::system_clock::now(); // set end of system clock
	elapsed_seconds = end-start;
	cout << "Quicksort (median pivot) time:                           " << elapsed_seconds.count() << "s\n";

	// Quicksort using median key of 3 using Insertionsort for subfiles under size of 25
	vector<double> quicksortMI_result = vec; 

	start = chrono::system_clock::now(); // set beginning of system clock
	quicksort::quickSortInsert<double>(quicksortMI_result, 0, vec.size()-1);
	end = chrono::system_clock::now(); // set end of system clock
	elapsed_seconds = end-start;
	cout << "Quicksort (median pivot w/ Insertionsort) time:          " << elapsed_seconds.count() << "s\n";

	// Mergesort
	start = chrono::system_clock::now(); // set beginning of system clock
	vector<double> mergesort_result = mergesort(vec);
	end = chrono::system_clock::now(); // set end of system clock
	elapsed_seconds = end-start;
	cout << "Mergesort time:                                          " << elapsed_seconds.count() << "s\n";

	// Heapsort
	vector<double> heapsort_result = vec;

	start = chrono::system_clock::now(); // set beginning of system clock
	heapSort(heapsort_result.begin(), heapsort_result.end());
	end = chrono::system_clock::now(); // set end of system clock
	elapsed_seconds = end-start;
	cout << "Heapsort time:                                           " << elapsed_seconds.count() << "s\n";

	return 0;
}