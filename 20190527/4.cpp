#include <iostream>
using namespace std;

int main()
{
  int data[3][3];

  int i, tmp = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> data[i][j];
    }
  }

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (data[i][j] + data[i + 1][j + 1] != data[i][j + 1] + data[i + 1][j])
      {
        // cout << "i:" << i << ",j:" << j << endl;
        cout << "No" << endl;
        return 0;
      }
    }
  }

  if (data[0][2] + data[2][0] != data[0][0] + data[2][2])
  {
    // cout << "i:" << 0 << ",j:" << 2 << endl;
    cout << "No" << endl;
    return 0;
  }

  // if (data[0][1] + data[2][1] != data[1][0] + data[1][2])
  // {
  //   cout << "No" << endl;
  //   return 0;
  // }

  cout << "Yes" << endl;
  return 0;
}