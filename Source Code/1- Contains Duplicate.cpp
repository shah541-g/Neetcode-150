// Link: https://leetcode.com/problems/contains-duplicate/
#include <iostream>
#include <vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet;
        numsSet.reserve(nums.size());

        for(int n:nums){
          if(numsSet.count(n)){
            return true;
          }
          numsSet.insert(n);
        }
        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> testCases = {
        {1, 2, 3, 1},           // true
        {1, 2, 3, 4},           // false
        {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, // true
        {},                     // false
        {5},                    // false
        {2, 2},                 // true
        {-1, -2, -3, -1},       // true
        {10, 20, 30, 40, 50}    // false
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        bool result = obj.containsDuplicate(testCases[i]);

        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}