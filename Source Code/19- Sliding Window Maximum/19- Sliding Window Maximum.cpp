#include <iostream>
#include <vector>
#include<deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        vector<int> result(nums.size()-k+1);
        deque<int> indicesQueue;

        while(r<nums.size()){
          if(indicesQueue.size()!=0 && l>indicesQueue.front()){
            indicesQueue.pop_front();
          }
          while (indicesQueue.size()!=0 && nums[indicesQueue.back()]<nums[r])
          {
            indicesQueue.pop_back();
          }
          indicesQueue.push_back(r);
          if(r>=k-1){
            result[r-k+1] = nums[indicesQueue.front()];
            l++;
          }     
          r++;     
        }
      return result;
    }
};

int main() {
    Solution obj;

    vector<pair<vector<int>, int>> testCases = {
        {{1,3,-1,-3,5,3,6,7}, 3},       // [3,3,5,5,6,7]
        {{1}, 1},                       // [1]
        {{1,-1}, 1},                    // [1,-1]
        {{1,-1}, 2},                    // [1]
        {{9,11}, 2},                    // [11]
        {{4,3,2,1}, 2},                 // [4,3,2]
        {{1,2,3,4,5}, 3},               // [3,4,5]
        {{5,4,3,2,1}, 3},               // [5,4,3]
        {{1,1,1,1}, 2},                 // [1,1,1]
        {{7,2,4}, 2},                   // [7,4]
        {{-1,-3,-5,-2,-1}, 2},          // [-1,-3,-2,-1]
        {{10,9,8,7,6,5}, 4},            // [10,9,8]
        {{1,3,1,2,0,5}, 3},             // [3,3,2,5]
        {{100}, 1},                     // [100]
        {{2,2,2,1,1,1}, 3}              // [2,2,2,1]
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> nums = testCases[i].first;
        int k = testCases[i].second;

        vector<int> result = obj.maxSlidingWindow(nums, k);

        cout << "[ ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}