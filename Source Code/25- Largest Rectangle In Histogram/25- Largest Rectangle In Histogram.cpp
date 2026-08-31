#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> mStack;
        int length = heights.size();
        int maxArea = 0;
        for(int i=0; i<length; i++){
            int h = heights[i];
            int start = i;
            while (mStack.size()>0 && mStack.top().second>h){
                int index = mStack.top().first;
                int height = mStack.top().second;
                mStack.pop();
                maxArea = max(maxArea, height * (i-index));
                start = index;
            }
            mStack.push({start,h});
        }
        while(mStack.size()>0){
            int index = mStack.top().first;
            int h = mStack.top().second;
            mStack.pop();
            maxArea = max(maxArea,h*(length-index));
        }
        return maxArea;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> testCases = {
        {2,1,5,6,2,3},       // 10
        {2,4},               // 4
        {2,2,2,2},           // 8
        {1},                 // 1
        {},                  // 0
        {5,4,3,2,1},         // 9
        {1,2,3,4,5},         // 9
        {6,2,5,4,5,1,6},     // 12
        {0,1,0,1,0},         // 1
        {3,3,3},             // 9
        {1,1,2,2},           // 4
        {4,2,0,3,2,5},       // 6
        {2,1,2},             // 3
        {1,3,2,1,2},         // 5
        {5,5,1,5,5},         // 10
        {10,9,8,7,6},        // 30
        {1,2,1},             // 3
        {4,4,4,1,4,4},       // 12
        {2,1,2,3,1}          // 5
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> heights = testCases[i];

        int result = obj.largestRectangleArea(heights);

        cout << result << endl;
    }

    return 0;
}