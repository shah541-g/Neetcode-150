#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution { 
public: 
    int minEatingSpeed(vector<int>& piles, int h) { 
        int k = 0; 
 
        int l = 1, r = *max_element(piles.begin(),piles.end()); 
        int res = r; 
        while (l<=r){ 
            k = (l+r)/2; 
            double total = 0; 
            for(int p: piles){ 
                total+= ceil(p/double(k)); 
            } 
            if(total<=h){ 
                res = min(res,k); 
                r = k-1; 
            } else{ 
                l = k+1; 
            } 
        } 
 
        return res; 
    } 
};

int main() {
    Solution obj;

    vector<pair<vector<int>, int>> testCases = {
        {{3,6,7,11}, 8},                 // 4
        {{30,11,23,4,20}, 5},             // 30
        {{30,11,23,4,20}, 6},             // 23
        {{1}, 1},                         // 1
        {{1,2,3,4,5}, 5},                // 5
        {{1,2,3,4,5}, 15},               // 1
        {{5,5,5,5}, 4},                  // 5
        {{5,5,5,5}, 8},                  // 3
        {{10,10,10}, 3},                 // 10
        {{10,10,10}, 6},                 // 5
        {{9,7,5,3,1}, 5},                // 9
        {{9,7,5,3,1}, 10},               // 3
        {{1000000000}, 2},               // 500000000
        {{1000000000,1000000000}, 3},    // 1000000000
        {{2,2,2,2,2}, 10},               // 1
        {{4,8,15,16,23,42}, 10},         // 15
        {{1,1,1,1,1,1,1}, 7},            // 1
        {{312884470}, 312884469}         // 2
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<int> piles = testCases[i].first;
        int h = testCases[i].second;

        int result = obj.minEatingSpeed(piles, h);

        cout << result << endl;
    }

    return 0;
}