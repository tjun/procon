#include <iostream>
using namespace std;

int main()
{
  int n, a;
  cin >> n;
  cin >> a;

  int x = n % 500;
  if (x <= a)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}