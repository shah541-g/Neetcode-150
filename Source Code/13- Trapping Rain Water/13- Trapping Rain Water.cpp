#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    if (height.empty())
      return 0;
    int l = 0, r = height.size() - 1;
    int area = 0;
    int lMax = height[l], rMax = height[r];
    while (l < r)
    {
      if (height[l] < height[r])
      {
        lMax = max(lMax , height[l]);
        area += lMax - height[l];
        l++;
      }
      else
      {
        rMax = max(rMax , height[r]);
        area += rMax - height[r];
        r--;
      }
    }
    return area;
  }
};

int main()
{
  Solution obj;

  vector<vector<int>> testCases = {
      {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, // 6
      {4, 2, 0, 3, 2, 5},                   // 9
      {},                                   // 0
      {1},                                  // 0
      {1, 2, 3, 4, 5},                      // 0
      {5, 4, 3, 2, 1},                      // 0
      {3, 0, 2, 0, 4},                      // 7
      {2, 0, 2},                            // 2
      {5, 2, 1, 2, 1, 5},                   // 14
      {4, 2, 3},                            // 1
      {0, 0, 0, 0},                         // 0
      {5, 0, 5},                            // 5
      {2, 1, 0, 1, 3},                      // 4
      {3, 1, 2, 1, 2, 1, 5},                // 8
      {2, 0, 1, 0, 3}                       // 5
  };

  for (int i = 0; i < testCases.size(); i++)
  {
    cout << "Test Case " << i + 1 << ": ";

    vector<int> height = testCases[i];

    int result = obj.trap(height);

    cout << result << endl;
  }

  return 0;
}