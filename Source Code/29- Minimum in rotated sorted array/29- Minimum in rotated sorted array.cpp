#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int res = nums[l];
        int m = 0;
        while(l<=r){
            if(nums[l]<nums[r]){
                res = min(res,nums[l]);
                break;
            }
            m = (l+r)/2;
            res = min(res,nums[m]);
            if(nums[m]>=nums[l]){
                l = m+1;
            } else {
                r=m-1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << sol.findMin(nums1) << endl;
    // Expected: 1

    // Test Case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(nums2) << endl;
    // Expected: 0

    // Test Case 3
    vector<int> nums3 = {11, 13, 15, 17};
    cout << sol.findMin(nums3) << endl;
    // Expected: 11

    // Test Case 4
    vector<int> nums4 = {2, 1};
    cout << sol.findMin(nums4) << endl;
    // Expected: 1

    // Test Case 5
    vector<int> nums5 = {1};
    cout << sol.findMin(nums5) << endl;
    // Expected: 1

    // Test Case 6
    vector<int> nums6 = {5, 6, 7, 1, 2, 3, 4};
    cout << sol.findMin(nums6) << endl;
    // Expected: 1

    // Test Case 7
    vector<int> nums7 = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    cout << sol.findMin(nums7) << endl;
    // Expected: 1

    return 0;
}