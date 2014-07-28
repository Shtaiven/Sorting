#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include "quicksort.cpp"
 
using namespace std;

int main()
{
	string infilename = " ";
	cout << "Enter input filename: ";
	getline(cin, infilename);

	string outfilename = " ";
	cout << "Enter output filename: ";
	getline(cin, outfilename);

	int sortpercent = 0;
	cout << "Enter sort percentage (20 or 40): ";
	cin >> sortpercent;

	// Open the file
    ifstream fin(infilename);

    // Error Handler
    if (fin.fail()) {
    	cerr << "Error opening file" << endl;
    	exit(1);
    }

	// Initialize the vector which will store the unsorted file
    vector<double> unsorted_vec;
    vector<double> vec;
    vector<double> partial_vec;
    vector<double> partial_vec2;
 	vec = unsorted_vec;
    // Input from file into vector
    copy(istream_iterator<double>(fin), istream_iterator<double>(), back_inserter(unsorted_vec));
    vec = unsorted_vec;
    // Sort vector copy
    quicksort::quickSortInsert(vec, 0, vec.size()-1);

 	// Partially sort the file
 	if ((sortpercent == 20) || (sortpercent == 40)) {
 		int i = 0;
 		int j = 0;
 		while (j < vec.size()) {
 			partial_vec.push_back(vec[j]);
 			i++;
 			j += 5;
 		}

		i = 0; j = 0;
		while ( i < partial_vec.size() ) {// while (j < vec.size()) do
			swap( *(find(unsorted_vec.begin(), unsorted_vec.end(), partial_vec[i])), unsorted_vec[j] );
			i++;
			j += 5;
		}
 	}

 	if (sortpercent == 40) {
 		int i = 0;
 		int j = 1;
 		while (j < vec.size()) {
 			partial_vec2.push_back(vec[j]);
 			i++;
 			j += 5;
 		}

 		i = 0; j = 1;
		while ( i < partial_vec2.size() ) {// while (j < vec.size()) do
			swap( *(find(unsorted_vec.begin(), unsorted_vec.end(), partial_vec2[i])), unsorted_vec[j] );
			i++;
			j += 5;
		}
 	}

    // Generate and write output file
    vec = unsorted_vec;
    ofstream fout(outfilename);
    ostream_iterator<double> output_iterator(fout, "\n");
    copy(vec.begin(), vec.end(), output_iterator);
}