#include <iostream>
#include <vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = board.size();
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
            char val = board[i][j];
            if(val=='.'){
              continue;
            }

            if(rows[i].count(val)){
              return false;
            }
            rows[i].insert(val);

            if(cols[j].count(val)){
              return false;
            }
            cols[j].insert(val);

            int boxNumber = (i/3) *3+(j/3);
            if(boxes[boxNumber].count(val)){
              return false;
            }
            boxes[boxNumber].insert(val);
          }
        }
        return true;
    }
};

int main() {
    Solution obj;

    vector<vector<vector<char>>> testCases = {
        // Test Case 1: Valid Sudoku
        {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        },

        // Test Case 2: Invalid (duplicate in first row)
        {
            {'5','3','.','.','7','.','.','3','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        },

        // Test Case 3: Invalid (duplicate in first column)
        {
            {'5','3','.','.','7','.','.','.','.'},
            {'5','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        },

        // Test Case 4: Invalid (duplicate in top-left 3x3 box)
        {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','5','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        }
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";

        bool result = obj.isValidSudoku(testCases[i]);

        cout << (result ? "Valid" : "Invalid") << endl;
    }

    return 0;
}