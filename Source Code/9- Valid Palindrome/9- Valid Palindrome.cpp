// Link: https://leetcode.com/problems/valid-palindrome/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {

    for (auto &x : s)
    {
      x = tolower(x);
    }
    int left = 0, right = s.length() - 1;
    while (left < right)
    {

      while (!isalnum(s[left]))
      {
        left++;
      }
      while (!isalnum(s[right]))
      {
        right--;
      }
      if (s[left] != s[right])
      {
        return false;
      }
      left++, right--;
    }
    return true;
  }
};

int main()
{
  Solution obj;

  vector<string> testCases = {
      "A man, a plan, a canal: Panama", // true
      "race a car",                     // false
      " ",                              // true
      "",                               // true
      "0P",                             // false
      "Madam",                          // true
      "No 'x' in Nixon",                // true
      "Was it a car or a cat I saw?",   // true
      "hello",                          // false
      "12321",                          // true
      "1231",                           // false
      ".,!@#",                          // flase
      "Able was I, ere I saw Elba"      // true
  };

  for (int i = 0; i < testCases.size(); i++)
  {
    cout << "Test Case " << i + 1 << ": ";

    bool result = obj.isPalindrome(testCases[i]);

    cout << (result ? "true" : "false") << endl;
  }

  return 0;
}