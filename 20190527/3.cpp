#include <iostream>
#include <algorithm>

using namespace std;
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main()
{
  int n, data;
  cin >> n;
  int i = 0;
  int a[100];
  while (cin >> data)
  {
    a[i] = data;
    i++;

    if (i == n)
    {
      break;
    }
  }

  std::sort(a, a + n);

  int alice, bob = 0;
  i = 0;
  for (const int *p = a + n; p != a; --p)
  {
    if (i % 2 == 0)
    {
      alice += *(p - 1);
    }
    else
    {
      bob += *(p - 1);
    }
    i++;
  }

  cout << alice - bob << endl;
  return 0;
}