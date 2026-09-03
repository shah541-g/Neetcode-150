#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int m = 0;
        while (l<=r){
            m = (l+r)/2;
            if(nums[m]==target){
                return m;
            }
            // Left Sorted Portion
            if(nums[m]>=nums[l]){
                if(target>nums[m] || target < nums[l])
                l = m + 1;
                else
                r = m - 1;
            }
            // Right Sorted Portion
            else{
                if(target<nums[m] || target > nums[r]){
                    r = m - 1;
                } else{
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.search(nums1, 0) << endl;
    // Expected: 4

    // Test Case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.search(nums2, 3) << endl;
    // Expected: -1

    // Test Case 3
    vector<int> nums3 = {1};
    cout << sol.search(nums3, 1) << endl;
    // Expected: 0

    // Test Case 4
    vector<int> nums4 = {1};
    cout << sol.search(nums4, 0) << endl;
    // Expected: -1

    // Test Case 5
    vector<int> nums5 = {5, 6, 7, 8, 1, 2, 3, 4};
    cout << sol.search(nums5, 3) << endl;
    // Expected: 6

    // Test Case 6
    vector<int> nums6 = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    cout << sol.search(nums6, 8) << endl;
    // Expected: 2

    // Test Case 7
    vector<int> nums7 = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    cout << sol.search(nums7, 10) << endl;
    // Expected: -1

    return 0;
  }