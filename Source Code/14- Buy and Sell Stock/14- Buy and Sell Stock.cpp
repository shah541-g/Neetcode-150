#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size()==0)
    {
      return 0;
    }
    
    int minPrice = prices[0];
    int maxProfit = 0;
    for(int price: prices){
      minPrice = min(price, minPrice);
      maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
  }
};

int main() {
  Solution obj;

  vector<vector<int>> testCases = {
    {7,1,5,3,6,4},          // 5
    {7,6,4,3,1},            // 0
    {1,2,3,4,5},            // 4
    {2,4,1},                // 2
    {3,2,6,5,0,3},          // 4
    {5},                    // 0
    {},                     // 0
    {2,1,2,1,0,1,2},        // 2
    {10,9,8,7,6},           // 0
    {1,10},                 // 9
    {2,1,4},                // 3
    {3,8,2,5,1,7,8},        // 7
    {6,1,3,2,4,7},          // 6
    {1,1,1,1},              // 0
    {9,1,5,2,7}             // 6
  };

  for (int i = 0; i < testCases.size(); i++) {
    cout << "Test Case " << i + 1 << ": ";

    vector<int> prices = testCases[i];

    int result = obj.maxProfit(prices);

    cout << result << endl;
  }

  return 0;
}