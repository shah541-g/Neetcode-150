#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedian(vector<int>& A, vector<int>& B, int total) {
        
        int half = total / 2;

        int l = 0;
        int r = A.size();

        while (l<=r) {

            int i = (l + r) / 2;
            int j = half - i;

            double Aleft = (i > 0) ? A[i - 1] : -INFINITY;
            double Aright = (i < A.size()) ? A[i] : INFINITY;

            double Bleft = (j > 0) ? B[j - 1] : -INFINITY;
            double Bright = (j < B.size()) ? B[j] : INFINITY;

            if (Aleft <= Bright && Bleft <= Aright) {

                if (total % 2) {
                    return min(Aright, Bright);
                }
                else {
                    return (max(Aleft, Bleft) + 
                            min(Aright, Bright)) / 2.0;
                }
            }

            else if (Aleft > Bright) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int total = nums1.size() + nums2.size();

        if (nums1.size() > nums2.size()) {
            return findMedian(nums2, nums1, total);
        }

        return findMedian(nums1, nums2, total);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    // Expected: 2

    // Test Case 2
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};

    cout << sol.findMedianSortedArrays(nums3, nums4) << endl;
    // Expected: 2.5

    // Test Case 3
    vector<int> nums5 = {1};
    vector<int> nums6 = {2};

    cout << sol.findMedianSortedArrays(nums5, nums6) << endl;
    // Expected: 1.5

    // Test Case 4
    vector<int> nums7 = {1, 2, 3};
    vector<int> nums8 = {4, 5, 6};

    cout << sol.findMedianSortedArrays(nums7, nums8) << endl;
    // Expected: 3.5

    // Test Case 5
    vector<int> nums9 = {1, 3, 5, 7};
    vector<int> nums10 = {2, 4, 6, 8, 10};

    cout << sol.findMedianSortedArrays(nums9, nums10) << endl;
    // Expected: 5.5

    // Test Case 6
    vector<int> nums11 = {1, 2, 3, 4, 5};
    vector<int> nums12 = {6, 7, 8, 9, 10};

    cout << sol.findMedianSortedArrays(nums11, nums12) << endl;
    // Expected: 5.5

    // Test Case 7
    vector<int> nums13 = {100};
    vector<int> nums14 = {1, 2, 3, 4, 5};

    cout << sol.findMedianSortedArrays(nums13, nums14) << endl;
    // Expected: 3

    // Test Case 8
    vector<int> nums15 = {};
    vector<int> nums16 = {1, 2, 3, 4};

    cout << sol.findMedianSortedArrays(nums15, nums16) << endl;
    // Expected: 2.5

    // Test Case 9
    vector<int> nums17 = {1, 2, 2};
    vector<int> nums18 = {2, 3, 4};

    cout << sol.findMedianSortedArrays(nums17, nums18) << endl;
    // Expected: 2

    return 0;
}