#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using namespace std;

class Solution {
private:
   string getCode(string testString){
    int freqMap[26]={0};
    int n = testString.length();
    for(int i=0; i<n; i++){
      freqMap[testString[i] - 'a']++;
    }
    string code = "";
    for(int n: freqMap){
      code+=to_string(n);
      code+="#";
    }
    return code;
   }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
      unordered_map<string,vector<string>> anagramsGroups;
      for(string str:strs){
        string code = getCode(str);
        if(anagramsGroups.find(code)!=anagramsGroups.end()){
          anagramsGroups[code].push_back(str);
          continue;
        }
        anagramsGroups[code].push_back(str);
      }
      vector<vector<string>> ans;
      for(auto& codeAndCorrespondingAnagrams: anagramsGroups){
        ans.push_back(codeAndCorrespondingAnagrams.second);
      }
      return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<string>> testCases = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {""},
        {"a"},
        {"abc", "bca", "cab", "xyz", "zyx", "hello"},
        {"listen", "silent", "enlist", "google", "gooegl"},
        {"rat", "tar", "art", "car"},
        {"", "", ""},
        {"abcd", "dcba", "bcad", "efgh", "hgfe"}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";

        vector<vector<string>> result = obj.groupAnagrams(testCases[i]);

        for (const auto& group : result) {
            cout << "[ ";
            for (const auto& word : group) {
                cout << "\"" << word << "\" ";
            }
            cout << "]\n";
        }

        cout << "-------------------------\n";
    }

    return 0;
}