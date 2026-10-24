#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
    bool isValid(long long lb, TreeNode* root, long long ub){
        if (!root){
            return true;
        }
        if(root->val<=lb || root->val>=ub){
            return false;
        }
        return isValid(lb, root->left, root->val) && isValid(root->val, root->right, ub);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(LLONG_MIN,root,LLONG_MAX);
    }
};


// Create binary tree from level-order values.
// Use -1 for NULL.
// Note: This helper uses -1 as the null marker, so don't use it
// to test a node whose actual value is -1.
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

    // Test Case 1 - Valid BST
    TreeNode* root1 = createTree({2, 1, 3});
    cout << "Test Case 1: "
         << (solution.isValidBST(root1) ? "true" : "false") << endl;
    // Expected: true


    // Test Case 2 - Invalid: left child is greater than root
    TreeNode* root2 = createTree({5, 6, 7});
    cout << "Test Case 2: "
         << (solution.isValidBST(root2) ? "true" : "false") << endl;
    // Expected: false


    // Test Case 3 - Invalid: right child is smaller than root
    TreeNode* root3 = createTree({5, 3, 4});
    cout << "Test Case 3: "
         << (solution.isValidBST(root3) ? "true" : "false") << endl;
    // Expected: false


    // Test Case 4 - Invalid deeper node
    // 5's right subtree contains 3, which is less than 5.
    TreeNode* root4 = createTree({5, 1, 7, -1, -1, 3, 8});
    cout << "Test Case 4: "
         << (solution.isValidBST(root4) ? "true" : "false") << endl;
    // Expected: false


    // Test Case 5 - Duplicate values are invalid
    TreeNode* root5 = createTree({2, 2, 3});
    cout << "Test Case 5: "
         << (solution.isValidBST(root5) ? "true" : "false") << endl;
    // Expected: false


    // Test Case 6 - Single node
    TreeNode* root6 = createTree({10});
    cout << "Test Case 6: "
         << (solution.isValidBST(root6) ? "true" : "false") << endl;
    // Expected: true


    // Test Case 7 - Empty tree
    TreeNode* root7 = createTree({});
    cout << "Test Case 7: "
         << (solution.isValidBST(root7) ? "true" : "false") << endl;
    // Expected: true


    // Test Case 8 - Larger valid BST
    TreeNode* root8 = createTree({8, 4, 12, 2, 6, 10, 14});
    cout << "Test Case 8: "
         << (solution.isValidBST(root8) ? "true" : "false") << endl;
    // Expected: true


    // Test Case 9 - Invalid deeper node in left subtree
    // 6 is in the left subtree of 5, so the BST is invalid.
    TreeNode* root9 = createTree({5, 3, 8, 2, 6, 7, 9});
    cout << "Test Case 9: "
         << (solution.isValidBST(root9) ? "true" : "false") << endl;
    // Expected: false


    return 0;
}