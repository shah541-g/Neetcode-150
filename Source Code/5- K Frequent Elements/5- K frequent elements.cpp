#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> numsFreqMapper;
      for(int n: nums){
        numsFreqMapper[n]++;
      }
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
      for(auto& it: numsFreqMapper){
        minHeap.push({it.second,it.first});
        if(minHeap.size()>k){
          minHeap.pop();
        }
      }
      vector<int> ans;
      while (minHeap.size()!=0)
      {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
      }
      return ans;
    }
};

int main() {
    Solution obj;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 1, 1, 2, 2, 3}, 2},                     // [1,2]
        {{1}, 1},                                   // [1]
        {{4, 4, 4, 6, 6, 7}, 1},                    // [4]
        {{5, 5, 6, 6, 7, 7, 7, 8}, 2},              // [7,5] or [7,6]
        {{10, 20, 20, 30, 30, 30, 40, 40}, 3},      // [20,40,30] (order may vary)
        {{-1, -1, -2, -2, -2, -3}, 2},              // [-2,-1]
        {{9, 9, 9, 9}, 1},                          // [9]
        {{1, 2, 3, 4, 5}, 3}                        // Any 3 elements (all frequency = 1)
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> nums = testCases[i].first;
        int k = testCases[i].second;

        vector<int> result = obj.topKFrequent(nums, k);

        cout << "[ ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}