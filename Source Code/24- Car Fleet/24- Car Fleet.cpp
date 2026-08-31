#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> speedAndPositionPairs;
        int length = position.size();
        for(int i=0; i<length; i++){
            speedAndPositionPairs.push_back({position[i],speed[i]});
        }
        sort(speedAndPositionPairs.rbegin(), speedAndPositionPairs.rend());
        stack<double> timeStack;
        for(auto car: speedAndPositionPairs){
            double arrivalTime = (target-car.first)/double(car.second);
            if (timeStack.empty() || arrivalTime>timeStack.top()){
                timeStack.push(arrivalTime);
            }
        }
        return timeStack.size();
    }
};

int main() {
    Solution obj;

    struct TestCase {
        int target;
        vector<int> position;
        vector<int> speed;
    };

    vector<TestCase> testCases = {
        {12, {10, 8, 0, 5, 3}, {2, 4, 1, 1, 3}},     // 3
        {10, {3}, {3}},                               // 1
        {100, {0, 2, 4}, {4, 2, 1}},                  // 1
        {12, {10, 8, 0, 5, 3}, {2, 4, 1, 1, 3}},     // 3
        {10, {6, 8}, {3, 2}},                         // 2
        {10, {0, 4}, {2, 4}},                         // 2
        {10, {0, 5}, {1, 1}},                         // 2
        {20, {6, 8, 10, 12}, {3, 2, 1, 4}},          // 2
        {15, {10, 8, 0, 5, 3}, {2, 4, 1, 1, 3}},     // 3
        {10, {1, 2, 3}, {1, 1, 1}},                  // 3
        {10, {1, 2, 3}, {3, 2, 1}},                  // 1
        {20, {0, 5, 10, 15}, {2, 4, 2, 1}},          // 2
        {100, {10, 20, 30, 40}, {5, 4, 3, 2}},       // 1
        {10, {2, 5, 7}, {3, 2, 1}},                  // 1
        {12, {5, 6, 8, 10}, {1, 2, 1, 1}}            // 3
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        int target = testCases[i].target;
        vector<int> position = testCases[i].position;
        vector<int> speed = testCases[i].speed;

        int result = obj.carFleet(target, position, speed);

        cout << result << endl;
    }

    return 0;
}