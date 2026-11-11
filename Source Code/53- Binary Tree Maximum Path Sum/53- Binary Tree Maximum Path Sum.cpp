#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    int result = 0;
public:
    int dfs(TreeNode* root){
        if (!root){
            return 0;
        }
        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        leftMax = max(leftMax,0);
        rightMax = max(rightMax,0);
        result = max(result, root->val+leftMax+rightMax);
        return root->val+max(leftMax,rightMax);
    }
    int maxPathSum(TreeNode* root) {
        result = root->val;
        dfs(root);
        return result;
    }
};

// -1 represents a NULL node
TreeNode* createTree(vector<int> values) {
    if (values.empty() || values[0] == -1) {
        return nullptr;
    }

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
    Solution sol;

    // Test Case 1
    TreeNode* root1 = createTree({1, 2, 3});
    cout << "Test 1: " << sol.maxPathSum(root1)
         << " | Expected: 6" << endl;

    // Test Case 2
    TreeNode* root2 = createTree({-10, 9, 20, -1, -1, 15, 7});
    cout << "Test 2: " << sol.maxPathSum(root2)
         << " | Expected: 42" << endl;

    // Test Case 3: All negative values
    TreeNode* root3 = createTree({-3, -2, -5});
    cout << "Test 3: " << sol.maxPathSum(root3)
         << " | Expected: -2" << endl;

    // Test Case 4: Single node
    TreeNode* root4 = createTree({5});
    cout << "Test 4: " << sol.maxPathSum(root4)
         << " | Expected: 5" << endl;

    // Test Case 5: Path through a deeper subtree
    TreeNode* root5 = createTree({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1});
    cout << "Test 5: " << sol.maxPathSum(root5)
         << " | Expected: 48" << endl;

    // Test Case 6: Best path is entirely on one side
    TreeNode* root6 = createTree({1, -2, 10, -1, -1, 9, 20});
    cout << "Test 6: " << sol.maxPathSum(root6)
         << " | Expected: 39" << endl;

    // Test Case 7: Root is not part of the best path
    TreeNode* root7 = createTree({-10, 5, 6});
    cout << "Test 7: " << sol.maxPathSum(root7)
        << " | Expected: 6" << endl;

    return 0;
}