#include <iostream>
using namespace std;

int h[100000];
int costs[100000];

int pl(int x)
{
  return x > 0 ? x : -x;
}

int min(int x, int y)
{
  return x > y ? y : x;
}

int cost(int x)
{
  if (x == 0)
    return 0;
  if (x == 1)
    return pl(h[1] - h[0]);

  if (costs[x] > 0)
  {
    return costs[x];
  }
  int m = min(
      cost(x - 1) + pl(h[x] - h[x - 1]),
      cost(x - 2) + pl(h[x] - h[x - 2]));
  costs[x] = m;
  return m;
}

int main()
{
  int n, tmp, i = 0;

  cin >> n;
  while (cin >> tmp)
  {
    h[i] = tmp;
    i++;
    if (i == n)
    {
      break;
    }
  }
  cout << cost(n - 1);

  return 0;
}