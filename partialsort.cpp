#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
 
int main()
{
    std::vector<double> s;
 	s.push_back(5);
 	s.push_back(7);
 	s.push_back(4);
 	s.push_back(2);
 	s.push_back(8);
 	s.push_back(6);
 	s.push_back(1);
 	s.push_back(9);
 	s.push_back(0);
 	s.push_back(3);
 	
    std::partial_sort(s.begin(), s.begin() + 3, s.end());
    for (double a : s) {
        std::cout << a << " ";
    } 
}