#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      unordered_map<char,char> parenthesesPairs;
      parenthesesPairs.insert({'}','{'});
      parenthesesPairs.insert({')','('});
      parenthesesPairs.insert({']','['});

      stack<char> parenthesesStack;
      
      for(char c: s){
        if(parenthesesPairs.find(c)!=parenthesesPairs.end()){
          if(parenthesesStack.empty()){
            return false;
          }
          char topElement = parenthesesStack.top();
          if(parenthesesPairs[c]!=topElement){
            return false;
          }
          parenthesesStack.pop();
        } else{
          parenthesesStack.push(c);
        }
      }
      return parenthesesStack.empty();
    }
};

int main() {
    Solution obj;

    vector<string> testCases = {
        "()",           // true
        "()[]{}",       // true
        "(]",            // false
        "([])",          // true
        "([)]",          // false
        "{[]}",          // true
        "",              // true
        "(",             // false
        ")",             // false
        "(((",           // false
        ")))",           // false
        "[",             // false
        "]",             // false
        "{",             // false
        "{}",            // true
        "({[]})",        // true
        "({[}])",        // false
        "((()))",        // true
        "([{}])",        // true
        "[(])",          // false
        "(([]){})",      // true
        "(){[()()]}",    // true
        "([[[[]]]])",    // true
        "(()",           // false
        "())"            // false
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        bool result = obj.isValid(testCases[i]);

        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}