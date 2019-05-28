#include <iostream>
#include <utility>
#include <map>

using namespace std;
#define SWAP(type, a, b) \
  {                      \
    type work = a;       \
    a = b;               \
    b = work;            \
  }

void simple_sort(int *array, int *sub, size_t size)
{
  size_t i, j;

  for (i = 0; i < size - 1; ++i)
  {
    for (j = i + 1; j < size; ++j)
    {
      if (array[i] > array[j])
      {
        SWAP(int, array[i], array[j]);
        SWAP(int, sub[i], sub[j]);
      }
    }
  }
}

int main()
{

  int match[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  int n, m;
  cin >> n >> m;
  int a[10];
  int amatch[10];

  int i, tmp = 0;
  while (cin >> tmp)
  {
    a[i] = tmp;
    amatch[i] = match[a[i]];
    i++;
    if (i == m)
    {
      break;
    }
  }

  // for (i = 0; i < m; i++)
  // {
  //   cout << "a:" << a[i] << ", m:" << amatch[i] << endl;
  // }

  simple_sort(amatch, a, m);

  int small = amatch[0];

  for (int i = 1; i < 3; i++)
  {
    if (amatch[i] == small && a[0] < a[i])
    {
      int tmp = a[0];
      a[0] = a[i];
      a[i] = tmp;
    }
  }

  for (i = 0; i < m; i++)
  {
    cout << "a:" << a[i] << ", m:" << amatch[i] << endl;
  }

  int x = (n / small) - 1;
  int y = n - (x * small);
  int max = 0;

  for (int i = 0; i < m; i++)
  {
    if (amatch[i] < y && a[i] > max)
    {
      max = a[i];
    }
  }
  cout << max;
  for (int i = 0; i < x; i++)
  {
    cout << small;
  }
  cout << endl;

  return 0;
}