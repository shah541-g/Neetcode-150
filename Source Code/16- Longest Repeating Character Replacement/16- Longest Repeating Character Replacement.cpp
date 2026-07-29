#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

       int left = 0, right = 0, maxFreq = 0, ans = 0;
       int freq[26] = {0};
       for(;right<s.size();right++){
        char c =  s[right];
        freq[c-'A']++;
        maxFreq = max(maxFreq,freq[c-'A']);
        while((right-left+1) - maxFreq > k){
          freq[s[left]-'A']--;
          left++;
        }
        ans = max(ans,right-left+1);
       }
       return ans;
    }
};

int main() {
    Solution obj;

    vector<pair<string, int>> testCases = {
        {"ABAB", 2},          // 4
        {"AABABBA", 1},       // 4
        {"AAAA", 2},          // 4
        {"ABCDE", 1},         // 2
        {"BAAAB", 2},         // 5
        {"ABBB", 2},          // 4
        {"A", 0},             // 1
        {"", 0},              // 0
        {"ABAA", 0},          // 2
        {"ABABBA", 2},        // 5
        {"AAABBC", 2},        // 5
        {"ABCABC", 3},        // 5
        {"BBBBBAA", 1},       // 6
        {"BAABA", 2},         // 5
        {"ABCDA", 1}          // 2
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        string s = testCases[i].first;
        int k = testCases[i].second;

        int result = obj.characterReplacement(s, k);

        cout << result << endl;
    }

    return 0;
}