#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_set<char> visitedChars;
    int left = 0, right = 0, ans = 0;
    while (right < s.size())
    {
      char currentChar = s[right];
      while (visitedChars.count(currentChar))
      {
        /* code */
        visitedChars.erase(s[left]);
        left++;
      }
      visitedChars.insert(currentChar);
      ans = max(ans, right - left + 1);
      right++;
    }
    return ans;
  }
};

int main()
{
  Solution obj;

  vector<string> testCases = {
      "abcabcbb",  // 3
      "bbbbb",     // 1
      "pwwkew",    // 3
      "",          // 0
      " ",         // 1
      "au",        // 2
      "dvdf",      // 3
      "abba",      // 2
      "tmmzuxt",   // 5
      "anviaj",    // 5
      "abcdef",    // 6
      "aab",       // 2
      "abcadeaf",  // 5
      "aaabbbccc", // 2
      "abccdefgh"  // 6
  };

  for (int i = 0; i < testCases.size(); i++)
  {
    cout << "Test Case " << i + 1 << ": ";

    int result = obj.lengthOfLongestSubstring(testCases[i]);

    cout << result << endl;
  }

  return 0;
}