#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
      unordered_map<int,int> numIndexMapper;
      int complement = 0;
      int n = nums.size();
      for(int i=0; i<n; i++){
        complement = target - nums[i];
        if(numIndexMapper.find(complement)!=numIndexMapper.end()){
          return {numIndexMapper[complement],i};
        }
        numIndexMapper[nums[i]] = i;
      }
      return {};
    }
};

int main() {
    Solution obj;

    vector<pair<vector<int>, int>> testCases = {
        {{2, 7, 11, 15}, 9},      // [0,1]
        {{3, 2, 4}, 6},           // [1,2]
        {{3, 3}, 6},              // [0,1]
        {{1, 5, 3, 7}, 8},        // [0,3] or [1,2]
        {{10, 20, 30, 40}, 50},   // [0,3] or [1,2]
        {{-1, -2, -3, -4, -5}, -8}, // [2,4]
        {{0, 4, 3, 0}, 0}         // [0,3]
    };

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i].first;
        int target = testCases[i].second;

        cout << "Test Case " << i + 1 << ": ";

        vector<int> result = obj.twoSum(nums, target);

        if (result.empty()) {
            cout << "No solution found";
        } else {
            cout << "[" << result[0] << ", " << result[1] << "]";
        }

        cout << endl;
    }

    return 0;
}