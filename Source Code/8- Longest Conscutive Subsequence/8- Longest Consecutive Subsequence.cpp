// Link: https://leetcode.com/problems/longest-consecutive-sequence/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {

    unordered_set<int> numsSet;
    for (int n : nums)
    {
      if (!numsSet.count(n))
      {
        numsSet.insert(n);
      }
    }
    int consecutiveSequenceLength = 0;
    int maxLength = 0;
    for (int n : nums)
    {
      consecutiveSequenceLength = 0;
      if (numsSet.count(n - 1))
      {
        continue;
      }
      consecutiveSequenceLength += 1;
      while (numsSet.count(n + 1))
      {
        consecutiveSequenceLength += 1;
        n+=1;
      }
      maxLength = maxLength > consecutiveSequenceLength ? maxLength : consecutiveSequenceLength;
    }
    return maxLength;
  }
};

int main()
{
  Solution obj;

  vector<vector<int>> testCases = {
      {100, 4, 200, 1, 3, 2},              // 4
      {0, 3, 7, 2, 5, 8, 4, 6, 0, 1},      // 9
      {},                                  // 0
      {1},                                 // 1
      {1, 2, 0, 1},                        // 3
      {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6}, // 7
      {10, 30, 20},                        // 1
      {-2, -3, -1, 5, 6, 7},               // 3
      {1, 3, 5, 2, 4},                     // 5
      {5, 5, 5, 5}                         // 1
  };

  for (int i = 0; i < testCases.size(); i++)
  {
    cout << "Test Case " << i + 1 << ": ";

    vector<int> nums = testCases[i];

    int result = obj.longestConsecutive(nums);

    cout << result << endl;
  }

  return 0;
}