#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int x[10] = { 1, 2, 3 , 4, 5 ,6, 7 ,8, 9, 10};
  int y[10] = {0};

 copy_if(rbegin(x), rend(x), y+5, [](int a){ return a%2 == 0;});
  //   cout << n << endl;

  for (auto n : y)
    cout << n << endl;
}
