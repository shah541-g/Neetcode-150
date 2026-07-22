#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1, post = 1;
        vector<int> ans(nums.size(),1);

        for(int i=0; i<nums.size();i++){
          ans[i]=pre;
          pre*=nums[i];
        }
        for(int j=nums.size()-1; j>=0; j--){
          ans[j]*=post;
          post*=nums[j];
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> testCases = {
        {1, 2, 3, 4},          // [24,12,8,6]
        {-1, 1, 0, -3, 3},     // [0,0,9,0,0]
        {2, 3},                // [3,2]
        {5},                   // [1]
        {0, 0},                // [0,0]
        {0, 1, 2, 3},          // [6,0,0,0]
        {1, 1, 1, 1},          // [1,1,1,1]
        {-1, -2, -3, -4}       // [-24,-12,-8,-6]
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> nums = testCases[i];
        vector<int> result = obj.productExceptSelf(nums);

        cout << "[ ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}