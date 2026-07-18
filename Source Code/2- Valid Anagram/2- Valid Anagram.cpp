// Link: https://leetcode.com/problems/valid-anagram/description/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      
      if(s.length()!=t.length()){
        return false;
      }
      
      int alphabetsFreq[26] =  {0};
      int length = s.length();
      for(int i=0; i<length; i++){
        alphabetsFreq[s[i]-'a']++;
        alphabetsFreq[t[i]-'a']--;
      }
      for(int n: alphabetsFreq){
        if(n!=0)
        return false;
      }
      return true;
    }
};

int main() {
    Solution obj;

    vector<pair<string, string>> testCases = {
        {"anagram", "nagaram"},   // true
        {"rat", "car"},           // false
        {"listen", "silent"},     // true
        {"hello", "world"},       // false
        {"", ""},                 // true
        {"a", "a"},               // true
        {"a", "b"},               // false
        {"abc", "cba"},           // true
        {"abcd", "abc"},          // false
        {"night", "thing"}        // true
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        bool result = obj.isAnagram(testCases[i].first, testCases[i].second);

        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}