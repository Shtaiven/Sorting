#include <vector>
using namespace std;

void shellSortPhase(vector<double> &a, int length, int gap) {
  int i;
  for (i = gap; i < length; ++i) {
    double value = a[i];
    int j;
    for (j = i - gap; j >= 0 && a[j] > value; j -= gap) {
      a[j + gap] = a[j];
    }
    a[j + gap] = value;
  }
}
 
void shellSort(vector<double> &a, size_t length) {
/*
  gaps[] should approximate a [[w:geometric progression|geometric progression]].
  The following sequence is the best known in terms of
  the average number of key comparisons made [http://www.research.att.com/~njas/sequences/A102549]
*/
  static const int gaps[] = {
    1, 4, 10, 23, 57, 132, 301, 701
  };
  int sizeIndex;
  for (sizeIndex = sizeof(gaps)/sizeof(gaps[0]) - 1;
      sizeIndex >= 0;
      --sizeIndex)
  shellSortPhase(a, length, gaps[sizeIndex]);
}