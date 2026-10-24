#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        int n = 0;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            n+=1;
            if(n==k){
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
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
    TreeNode* root1 = createTree({3, 1, 4, -1, 2});
    cout << "Test 1: " << sol.kthSmallest(root1, 1)
         << " | Expected: 1" << endl;

    // Test Case 2
    TreeNode* root2 = createTree({3, 1, 4, -1, 2});
    cout << "Test 2: " << sol.kthSmallest(root2, 2)
         << " | Expected: 2" << endl;

    // Test Case 3
    TreeNode* root3 = createTree({5, 3, 6, 2, 4, -1, -1, 1});
    cout << "Test 3: " << sol.kthSmallest(root3, 3)
         << " | Expected: 3" << endl;

    // Test Case 4: Smallest element
    TreeNode* root4 = createTree({8, 4, 10, 2, 6, 9, 12});
    cout << "Test 4: " << sol.kthSmallest(root4, 1)
         << " | Expected: 2" << endl;

    // Test Case 5: Largest element
    TreeNode* root5 = createTree({8, 4, 10, 2, 6, 9, 12});
    cout << "Test 5: " << sol.kthSmallest(root5, 7)
         << " | Expected: 12" << endl;

    // Test Case 6: Single-node tree
    TreeNode* root6 = createTree({7});
    cout << "Test 6: " << sol.kthSmallest(root6, 1)
         << " | Expected: 7" << endl;

    // Test Case 7: Left-skewed BST
    TreeNode* root7 = createTree({5, 3, -1, 2, -1, 1});
    cout << "Test 7: " << sol.kthSmallest(root7, 2)
         << " | Expected: 2" << endl;

    return 0;
}