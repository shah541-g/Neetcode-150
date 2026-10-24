#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> q;
        q.push_back(root);

        while (q.size()){
            int qLen = q.size();
            vector<int> level;

            for(int i=0; i<qLen; i++){
                TreeNode* node = q.front();
                q.erase(q.begin());

                if (node){
                    level.push_back(node->val);
                    q.push_back(node->left);
                    q.push_back(node->right);
                }
            }

            if(level.size()!=0)
                res.push_back(level);
        }

        return res;
    }
};


// Create binary tree from level-order values.
// Use -1 for NULL.
TreeNode* createTree(vector<int> values) {
    if (values.empty() || values[0] == -1)
        return NULL;

    TreeNode* root = new TreeNode(values[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (values[i] != -1) {
            curr->left = new TreeNode(values[i]);
            q.push(curr->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) {
            curr->right = new TreeNode(values[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}


// Print vector<vector<int>>
void printResult(vector<vector<int>> result) {
    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << "[";

        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j < result[i].size() - 1)
                cout << ", ";
        }

        cout << "]";

        if (i < result.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}


int main() {

    Solution solution;


    // Test Case 1
    TreeNode* root1 = createTree({3, 9, 20, -1, -1, 15, 7});

    vector<vector<int>> result1 = solution.levelOrder(root1);

    cout << "Test Case 1: ";
    printResult(result1);
    // Expected: [[3], [9, 20], [15, 7]]


    // Test Case 2 - Single node
    TreeNode* root2 = createTree({1});

    vector<vector<int>> result2 = solution.levelOrder(root2);

    cout << "Test Case 2: ";
    printResult(result2);
    // Expected: [[1]]


    // Test Case 3 - Empty tree
    TreeNode* root3 = createTree({});

    vector<vector<int>> result3 = solution.levelOrder(root3);

    cout << "Test Case 3: ";
    printResult(result3);
    // Expected: []


    // Test Case 4 - Complete binary tree
    TreeNode* root4 = createTree({1, 2, 3, 4, 5, 6, 7});

    vector<vector<int>> result4 = solution.levelOrder(root4);

    cout << "Test Case 4: ";
    printResult(result4);
    // Expected: [[1], [2, 3], [4, 5, 6, 7]]


    // Test Case 5 - Left-skewed tree
    TreeNode* root5 = createTree({1, 2, -1, 3, -1, -1, -1, 4});

    vector<vector<int>> result5 = solution.levelOrder(root5);

    cout << "Test Case 5: ";
    printResult(result5);
    // Expected: [[1], [2], [3], [4]]


    // Test Case 6 - Right-skewed tree
    TreeNode* root6 = createTree({1, -1, 2, -1, -1, -1, 3});

    vector<vector<int>> result6 = solution.levelOrder(root6);

    cout << "Test Case 6: ";
    printResult(result6);
    // Expected: [[1], [2], [3]]


    // Test Case 7 - Uneven tree
    TreeNode* root7 = createTree({
        1, 2, 3,
        4, -1, -1, 5,
        6
    });

    vector<vector<int>> result7 = solution.levelOrder(root7);

    cout << "Test Case 7: ";
    printResult(result7);
    // Expected: [[1], [2, 3], [4, 5], [6]]


    // Test Case 8 - Duplicate values
    TreeNode* root8 = createTree({
        1, 1, 1,
        1, 1, 1, 1
    });

    vector<vector<int>> result8 = solution.levelOrder(root8);

    cout << "Test Case 8: ";
    printResult(result8);
    // Expected: [[1], [1, 1], [1, 1, 1, 1]]


    return 0;
}