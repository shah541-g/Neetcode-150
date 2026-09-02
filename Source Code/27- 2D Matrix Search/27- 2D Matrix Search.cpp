#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int COL = matrix[0].size()-1;
        int top = 0, bot = matrix.size()-1;
        int ROW = 0;
        while(top<=bot){
            ROW = top+(bot-top)/2;
            if(target<matrix[ROW][0]){
                bot = ROW - 1;
            } else if (target>matrix[ROW][COL]){
                top = ROW + 1;
            } else{
                break;
            }
        }
        if(top>bot) return false;
        int l = 0, r = COL;
        int m = 0;
        while(l<=r){
            m = l+(r-l)/2;
            if(target>matrix[ROW][m]){
                l = m + 1;
            } else if(target<matrix[ROW][m]){
                r = m - 1;
            } else{
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    vector<pair<vector<vector<int>>, int>> testCases = {
        {
            {
                {1,3,5,7},
                {10,11,16,20},
                {23,30,34,60}
            },
            3
        }, // true

        {
            {
                {1,3,5,7},
                {10,11,16,20},
                {23,30,34,60}
            },
            13
        }, // false

        {
            {
                {1}
            },
            1
        }, // true

        {
            {
                {1}
            },
            2
        }, // false

        {
            {
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12}
            },
            10
        }, // true

        {
            {
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12}
            },
            13
        }, // false

        {
            {
                {1,4,7,11},
                {12,15,18,20},
                {23,26,30,34}
            },
            34
        }, // true

        {
            {
                {1,4,7,11},
                {12,15,18,20},
                {23,26,30,34}
            },
            2
        }, // false

        {
            {
                {-10,-5,0,5},
                {10,15,20,25},
                {30,35,40,45}
            },
            -5
        }, // true

        {
            {
                {-10,-5,0,5},
                {10,15,20,25},
                {30,35,40,45}
            },
            35
        }, // true

        {
            {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            },
            1
        }, // true

        {
            {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            },
            9
        }, // true

        {
            {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            },
            0
        }, // false

        {
            {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            },
            10
        } // false
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        vector<vector<int>> matrix = testCases[i].first;
        int target = testCases[i].second;

        bool result = obj.searchMatrix(matrix, target);

        cout << (result ? "true" : "false") << endl;
    }

    return 0;
}