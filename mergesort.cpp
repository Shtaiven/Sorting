#include <vector>

using namespace std;

vector<double> merge(const vector<double>& left, const vector<double>& right);

vector<double> mergesort(vector<double>& vec)
{
    // Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1)
    {
        return vec;
    }
 
    // Determine the location of the middle element in the vector
    vector<double>::iterator middle = vec.begin() + (vec.size() / 2);
 
    vector<double> left(vec.begin(), middle);
    vector<double> right(middle, vec.end());
 
    // Perform a merge sort on the two smaller vectors
    left = mergesort(left);
    right = mergesort(right);
 
    return merge(left, right);
}

vector<double> merge(const vector<double>& left, const vector<double>& right)
{
    // Fill the resultant vector with sorted results from both vectors
    vector<double> result;
    unsigned left_it = 0, right_it = 0;
 
    while(left_it < left.size() && right_it < right.size())
    {
        // If the left value is smaller than the right it goes next
        // into the resultant vector
        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }
 
    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }
 
    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }
 
    return result;
}
