#include <iostream>
#include <vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<pair<int,int>> mStack;
        for(int i=0; i<temperatures.size(); i++){
            int c = temperatures[i];
            while(mStack.size()!=0 && mStack.top().first<c){
                int jumps = i-mStack.top().second;
                result[mStack.top().second] = jumps;
                mStack.pop();
            }
            pair<int,int> tempDetails = {c,i};
            mStack.push(tempDetails); 
        }
        return result;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> testCases = {
        {73,74,75,71,69,72,76,73},  // [1,1,4,2,1,1,0,0]
        {30,40,50,60},              // [1,1,1,0]
        {30,60,90},                 // [1,1,0]
        {90,80,70,60},              // [0,0,0,0]
        {70},                       // [0]
        {},                         // []
        {70,70,70,70},              // [0,0,0,0]
        {30,31,30,32,33},            // [1,2,1,1,0]
        {50,40,45,35,60},            // [4,2,1,1,0]
        {100,99,98,97,101},           // [4,3,2,1,0]
        {20,25,21,22,30},             // [1,3,1,1,0]
        {80,79,78,81,77,82},          // [3,2,1,1,1,0]
        {55,60,58,65,62,70},          // [1,2,1,2,1,0]
        {10,20,30,25,40,35,50}        // [1,1,2,1,2,1,0]
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> temperatures = testCases[i];

        vector<int> result = obj.dailyTemperatures(temperatures);

        cout << "[ ";
        for (int value : result) {
            cout << value << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}