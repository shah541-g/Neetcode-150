// Link: https://leetcode.com/problems/valid-palindrome/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
    }
};

int main() {
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
        ".,!@#",                          // true
        "Able was I, ere I saw Elba"      // true
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        bool result = obj.isPalindrome(testCases[i]);

        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}