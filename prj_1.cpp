#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt xcopy_if(InputIt first, InputIt last,
                 OutputIt d_first, UnaryPredicate pred)
{
    for (; first != last; ++first) {
        if (pred(*first)) {
            *d_first = *first;
            ++d_first;
        }
    }
    return d_first;
}

int main()
{
  // int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // int y[10] = {0};

  // vector<int> x = {1 , 2, 3, 4, 5, 6, 7, 8, 9};
  // vector<int> y(10);

  list<int> s = { 1 ,2 3, 4 ,5 ,6 7, 8, 9};
  list

  xcopy_if(x.begin(), x.end(), y.begin()+1, [](int a){ return a%2 == 0; });

  for (auto n : y)
    cout << n << endl;
}
