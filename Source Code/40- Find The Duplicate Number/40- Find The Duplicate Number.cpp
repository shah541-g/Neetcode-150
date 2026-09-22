#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow!=fast){
            slow = nums[slow];
            fast=nums[nums[fast]];
        }
        int slow2 = 0;
        while(slow2!=slow){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Test Case 1: " << sol.findDuplicate(nums1) << endl;
    // Expected: 2


    // Test Case 2
    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Test Case 2: " << sol.findDuplicate(nums2) << endl;
    // Expected: 3


    // Test Case 3
    vector<int> nums3 = {1, 1};
    cout << "Test Case 3: " << sol.findDuplicate(nums3) << endl;
    // Expected: 1


    // Test Case 4
    vector<int> nums4 = {1, 1, 2};
    cout << "Test Case 4: " << sol.findDuplicate(nums4) << endl;
    // Expected: 1


    // Test Case 5
    vector<int> nums5 = {1, 4, 4, 2, 3};
    cout << "Test Case 5: " << sol.findDuplicate(nums5) << endl;
    // Expected: 4


    // Test Case 6
    vector<int> nums6 = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    cout << "Test Case 6: " << sol.findDuplicate(nums6) << endl;
    // Expected: 9


    // Test Case 7
    vector<int> nums7 = {1, 2, 3, 4, 4};
    cout << "Test Case 7: " << sol.findDuplicate(nums7) << endl;
    // Expected: 4


    // Test Case 8
    vector<int> nums8 = {2, 2, 2, 2, 2};
    cout << "Test Case 8: " << sol.findDuplicate(nums8) << endl;
    // Expected: 2


    // Test Case 9
    vector<int> nums9 = {1, 5, 3, 4, 2, 5};
    cout << "Test Case 9: " << sol.findDuplicate(nums9) << endl;
    // Expected: 5

    return 0;
}