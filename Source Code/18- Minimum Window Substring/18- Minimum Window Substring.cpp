#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    if (s.length() < t.length() || s.length() == 0 || t.length() == 0)
    {
      return "";
    }
    unordered_map<char, int> tMap, sMap;
    for (char c : t)
    {
      tMap[c]++;
    }
    int required = tMap.size();
    int created = 0;
    int l = 0, r = 0;
    int ans[] = {-1, 0, 0};
    while (r < s.size())
    {
      char c = s[r];
      sMap[c]++;
      if (tMap.count(c) && sMap[c] == tMap[c])
      {
        created++;
      }
      while (created == required && l <= r)
      {
        int length = r - l + 1;
        if (ans[0] == -1 || ans[0] > length)
        {
          ans[0] = length;
          ans[1] = l;
          ans[2] = r;
        }
        char lc = s[l];
        sMap[lc]--;
        if (tMap.count(lc) && tMap[lc] > sMap[lc])
        {
          created--;
        }
        l++;
      }
      r++;
    }
    if(ans[0]==-1){
      return "";
    }
    return s.substr(ans[1],ans[0]);
  }
};

int main()
{
  Solution obj;

  vector<pair<string, string>> testCases = {
      {"ADOBECODEBANC", "ABC"},       // "BANC"
      {"a", "a"},                     // "a"
      {"a", "aa"},                    // ""
      {"abc", "c"},                   // "c"
      {"abc", "ac"},                  // "abc"
      {"aa", "aa"},                   // "aa"
      {"aaflslflsldkalskaaa", "aaa"}, // "aaa"
      {"ab", "b"},                    // "b"
      {"ab", "a"},                    // "a"
      {"abc", "d"},                   // ""
      {"", "a"},                      // ""
      {"a", ""},                      // ""
      {"thisisateststring", "tist"},  // "tstr"
      {"cabwefgewcwaefgcf", "cae"}    // "cwae"
  };

  for (int i = 0; i < testCases.size(); i++)
  {
    cout << "Test Case " << i + 1 << ": ";

    string s = testCases[i].first;
    string t = testCases[i].second;

    string result = obj.minWindow(s, t);

    cout << "\"" << result << "\"" << endl;
  }

  return 0;
}