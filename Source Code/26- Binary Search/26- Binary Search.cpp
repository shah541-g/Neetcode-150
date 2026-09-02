#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target > nums[mid]) {
                left = mid + 1;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<pair<vector<int>, int>> testCases = {
        {{-1,0,3,5,9,12}, 9},        // 4
        {{-1,0,3,5,9,12}, 2},        // -1
        {{1}, 1},                    // 0
        {{1}, 0},                    // -1
        {{1,2,3,4,5}, 3},            // 2
        {{1,2,3,4,5}, 1},            // 0
        {{1,2,3,4,5}, 5},            // 4
        {{1,2,3,4,5}, 6},            // -1
        {{-10,-5,-2,0,3,7,11}, -10}, // 0
        {{-10,-5,-2,0,3,7,11}, 11},  // 6
        {{-10,-5,-2,0,3,7,11}, -3},   // -1
        {{2,4,6,8,10,12,14}, 8},      // 3
        {{2,4,6,8,10,12,14}, 7},      // -1
        {{0,5,10,15,20,25}, 0},       // 0
        {{0,5,10,15,20,25}, 25},      // 5
        {{3,7,9,12,15,20,25,30}, 15}, // 4
        {{3,7,9,12,15,20,25,30}, 1}   // -1
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> nums = testCases[i].first;
        int target = testCases[i].second;

        int result = obj.search(nums, target);

        cout << result << endl;
    }

    return 0;
}