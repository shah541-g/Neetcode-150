#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> numbersStack;
      int a = 0, b = 0;
      for(int i=0; i<tokens.size();i++){
        string c = tokens[i];
        a = 0, b = 0;
        if (c=="+"){
          a = numbersStack.top();
          numbersStack.pop();
          b = numbersStack.top();
          numbersStack.pop();
          numbersStack.push((a+b));

        } else if(c=="-"){
          a = numbersStack.top();
          numbersStack.pop();
          b = numbersStack.top();
          numbersStack.pop();
          numbersStack.push((b-a));
        } else if(c=="*"){
          a = numbersStack.top();
          numbersStack.pop();
          b = numbersStack.top();
          numbersStack.pop();
          numbersStack.push((a*b));
        } else if(c=="/"){
          a = numbersStack.top();
          numbersStack.pop();
          b = numbersStack.top();
          numbersStack.pop();
          numbersStack.push((b/a));
        } else{
          numbersStack.push(stoi(c));
        }
      }
      return numbersStack.top();
    }
};

int main() {
    Solution obj;

    vector<vector<string>> testCases = {
        {"2", "1", "+", "3", "*"},                    // 9
        {"4", "13", "5", "/", "+"},                  // 6
        {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, // 22
        {"2", "3", "/"},                              // 0
        {"5", "1", "2", "+", "4", "*", "+", "3", "-"}, // 14
        {"4", "2", "-"},                              // 2
        {"3", "4", "+"},                              // 7
        {"10", "2", "/"},                             // 5
        {"-2", "3", "*"},                             // -6
        {"-10", "2", "/"},                            // -5
        {"2", "3", "4", "*", "+"},                    // 14
        {"7", "2", "3", "*", "-"},                    // 1
        {"15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-"} // 5
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<string> tokens = testCases[i];

        int result = obj.evalRPN(tokens);

        cout << result << endl;
    }

    return 0;
}