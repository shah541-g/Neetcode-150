#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    int dfs(TreeNode* root, int maxVal){
        if (!root){
            return 0;
        }
        int res = root->val>=maxVal ? 1 : 0;
        maxVal = max(root->val, maxVal);
        return res + dfs(root->left,maxVal) + dfs(root->right,maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
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


int main() {
    Solution solution;

    // Test Case 1
    TreeNode* root1 = createTree({3, 1, 4, 3, -1, 1, 5});

    cout << "Test Case 1: " << solution.goodNodes(root1) << endl;
    // Expected: 4


    // Test Case 2
    TreeNode* root2 = createTree({3, 3, -1, 4, 2});

    cout << "Test Case 2: " << solution.goodNodes(root2) << endl;
    // Expected: 3


    // Test Case 3 - Single node
    TreeNode* root3 = createTree({1});

    cout << "Test Case 3: " << solution.goodNodes(root3) << endl;
    // Expected: 1


    // Test Case 4 - Increasing values
    TreeNode* root4 = createTree({1, 2, 3, 4, 5});

    cout << "Test Case 4: " << solution.goodNodes(root4) << endl;
    // Expected: 5


    // Test Case 5 - All values equal
    TreeNode* root5 = createTree({5, 5, 5, 5, 5});

    cout << "Test Case 5: " << solution.goodNodes(root5) << endl;
    // Expected: 5


    // Test Case 6 - Descending values
    TreeNode* root6 = createTree({5, 4, 3, 2, 1});

    cout << "Test Case 6: " << solution.goodNodes(root6) << endl;
    // Expected: 1


    // Test Case 7 - Root with two children
    TreeNode* root8 = createTree({3, 1, 5});

    cout << "Test Case 7: " << solution.goodNodes(root8) << endl;
    // Expected: 2


    return 0;
}