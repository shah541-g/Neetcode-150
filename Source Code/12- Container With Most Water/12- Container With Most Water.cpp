#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int left = 0;
      int right = height.size()-1;
      int area = 0, maxArea = 0,  cHeight = 0, width = 0;

      while (left<right)
      {
        cHeight = height[left] < height[right] ? height[left] : height[right];
        width = right - left;
        area = width * cHeight;
        maxArea = maxArea > area ? maxArea : area;
        if(height[left]>=height[right]){
          right--;
        } else{
          left++;
        }
      }
      return maxArea;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> testCases = {
        {1,8,6,2,5,4,8,3,7},      // 49
        {1,1},                    // 1
        {4,3,2,1,4},              // 16
        {1,2,1},                  // 2
        {2,3,10,5,7,8,9},         // 36
        {1,2,4,3},                // 4
        {5,5,5,5,5},              // 20
        {6},                      // 0
        {1,3,2,5,25,24,5},        // 24
        {2,1,2}                   // 4
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> height = testCases[i];

        int result = obj.maxArea(height);

        cout << result << endl;
    }

    return 0;
}