#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        int sum = 0;
        while (left<right)
        { 
          sum = numbers[left]+numbers[right];
          if(sum>target){
            right--;
            continue;
          }
          if(sum<target){
            left++;
            continue;
          }
          if(sum==target){
            return {left+1,right+1};
          }
        }
        return {};
        
    }
};

int main() {
    Solution obj;

    vector<pair<vector<int>, int>> testCases = {
        {{2, 7, 11, 15}, 9},          // [1,2]
        {{2, 3, 4}, 6},               // [1,3]
        {{-1, 0}, -1},                // [1,2]
        {{1, 2, 3, 4, 4, 9}, 8},      // [4,5]
        {{1, 3, 4, 5, 7, 10}, 11},    // [3,6]
        {{5, 25, 75}, 100},           // [2,3]
        {{1, 2}, 3},                  // [1,2]
        {{-5, -3, 0, 2, 8}, 5}        // [2,5]
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> numbers = testCases[i].first;
        int target = testCases[i].second;

        vector<int> result = obj.twoSum(numbers, target);

        if (!result.empty()) {
            cout << "[" << result[0] << ", " << result[1] << "]";
        } else {
            cout << "No solution found";
        }

        cout << endl;
    }

    return 0;
}