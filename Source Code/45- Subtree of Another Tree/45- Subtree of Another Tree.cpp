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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        if(!p || !q || p->val!=q->val){
            return false;
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};


// Create a binary tree from level-order values.
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


    // Test Case 1 - Same trees
    TreeNode* p1 = createTree({1, 2, 3});
    TreeNode* q1 = createTree({1, 2, 3});

    cout << "Test Case 1: "
         << (solution.isSameTree(p1, q1) ? "true" : "false")
         << endl;
    // Expected: true


    // Test Case 2 - Different values
    TreeNode* p2 = createTree({1, 2, 3});
    TreeNode* q2 = createTree({1, 2, 4});

    cout << "Test Case 2: "
         << (solution.isSameTree(p2, q2) ? "true" : "false")
         << endl;
    // Expected: false


    // Test Case 3 - Different structures
    TreeNode* p3 = createTree({1, 2});
    TreeNode* q3 = createTree({1, -1, 2});

    cout << "Test Case 3: "
         << (solution.isSameTree(p3, q3) ? "true" : "false")
         << endl;
    // Expected: false


    // Test Case 4 - Both empty
    TreeNode* p4 = createTree({});
    TreeNode* q4 = createTree({});

    cout << "Test Case 4: "
         << (solution.isSameTree(p4, q4) ? "true" : "false")
         << endl;
    // Expected: true


    // Test Case 5 - One empty, one non-empty
    TreeNode* p5 = createTree({});
    TreeNode* q5 = createTree({1});

    cout << "Test Case 5: "
         << (solution.isSameTree(p5, q5) ? "true" : "false")
         << endl;
    // Expected: false


    // Test Case 6 - Single identical nodes
    TreeNode* p6 = createTree({1});
    TreeNode* q6 = createTree({1});

    cout << "Test Case 6: "
         << (solution.isSameTree(p6, q6) ? "true" : "false")
         << endl;
    // Expected: true


    // Test Case 7 - Single different nodes
    TreeNode* p7 = createTree({1});
    TreeNode* q7 = createTree({2});

    cout << "Test Case 7: "
         << (solution.isSameTree(p7, q7) ? "true" : "false")
         << endl;
    // Expected: false


    // Test Case 8 - Larger identical trees
    TreeNode* p8 = createTree({1, 2, 3, 4, 5, 6, 7});
    TreeNode* q8 = createTree({1, 2, 3, 4, 5, 6, 7});

    cout << "Test Case 8: "
         << (solution.isSameTree(p8, q8) ? "true" : "false")
         << endl;
    // Expected: true


    // Test Case 9 - Same values but different structure
    TreeNode* p9 = createTree({1, 2, 3, -1, 4});
    TreeNode* q9 = createTree({1, 2, 3, 4});

    cout << "Test Case 9: "
         << (solution.isSameTree(p9, q9) ? "true" : "false")
         << endl;
    // Expected: false


    return 0;
}