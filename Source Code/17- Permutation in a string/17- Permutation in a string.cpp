#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s1.length()>s2.length()) return false;
      int s1Map[26] = {0};
      int s2Map[26] = {0};
      int i;
      for(i=0; i<s1.length();i++){
        s1Map[s1[i]-'a']++;
        s2Map[s2[i]-'a']++;
      }
      for(int j=0;i<s2.length();i++,j++){
        s2Map[s2[i]-'a']++;
        s2Map[s2[j]-'a']--;

        if(match(s1Map,s2Map)){
          return true;
        }
      }
      return match(s1Map,s2Map);
    }
    bool match(int *s1, int *s2){
      for(int i=0; i<26; i++){
        if(s1[i]!=s2[i]){
          return false;
        }
      }
      return true;
    }
};

int main() {
    Solution obj;

    vector<pair<string, string>> testCases = {
        {"ab", "eidbaooo"},        // true
        {"ab", "eidboaoo"},        // false
        {"adc", "dcda"},           // true
        {"hello", "ooolleoooleh"}, // false
        {"a", "a"},                // true
        {"a", "b"},                // false
        {"", ""},                  // true
        {"abc", "bbbca"},          // true
        {"xyz", "afdgzyxksldfm"},  // true
        {"abc", "defghijkl"},      // false
        {"aa", "eidbaaaaoo"},      // true
        {"abcd", "abc"},           // false
        {"abc", "ccccbbbbaaaa"},   // false
        {"cab", "eidbacooo"},      // true
        {"xyz", ""}                // false
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        string s1 = testCases[i].first;
        string s2 = testCases[i].second;

        bool result = obj.checkInclusion(s1, s2);

        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}