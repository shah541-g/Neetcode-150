#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allThreeSums;
        int left = 0, right = 0, sum = 0;
        for(int i=0; i<nums.size();i++){
          left = i+1, right = nums.size()-1;
          while(left<right){
            sum = nums[i] + nums[left] + nums[right];
            if(sum>0){
              right--;
              continue;
            }
            if(sum<0){
              left++;
              continue;
            }
            if(sum==0){
            
              allThreeSums.push_back({nums[i],nums[left],nums[right]});
              left++; 
              right--;
            }
          }
        }
        return allThreeSums;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},         // [[-1,-1,2],[-1,0,1]]
        {0, 1, 1},                     // []
        {0, 0, 0},                     // [[0,0,0]]
        {0, 0, 0, 0},                  // [[0,0,0]]
        {-2, 0, 1, 1, 2},              // [[-2,0,2],[-2,1,1]]
        {-4, -2, -2, 0, 1, 2, 2, 4},   // Multiple valid triplets
        {1, 2, -2, -1},                // []
        {-3, -2, -1, 0, 1, 2, 3},      // Several valid triplets
        {-1, -1, -1, 2, 2},            // [[-1,-1,2]]
        {}                             // []
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";

        vector<int> nums = testCases[i];
        vector<vector<int>> result = obj.threeSum(nums);

        if (result.empty()) {
            cout << "No triplets found.\n";
        } else {
            for (const auto& triplet : result) {
                cout << "[ ";
                for (int num : triplet) {
                    cout << num << " ";
                }
                cout << "]\n";
            }
        }

        cout << "-------------------------\n";
    }

    return 0;
}