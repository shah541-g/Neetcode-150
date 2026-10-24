#include <iostream>
#include <vector>
using namespace std;

// Definition for binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (cur){
            if(p->val<cur->val && q->val<cur->val) cur = cur->left;
            else if(p->val>cur->val && q->val>cur->val) cur = cur->right;
            else return cur;
        }
        return nullptr;
    }
};


// Insert into BST
TreeNode* insert(TreeNode* root, int value) {
    if (!root)
        return new TreeNode(value);

    if (value < root->val)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


// Create BST from vector
TreeNode* createBST(vector<int> values) {
    TreeNode* root = NULL;

    for (int value : values) {
        root = insert(root, value);
    }

    return root;
}


// Find node with given value
TreeNode* findNode(TreeNode* root, int value) {
    while (root) {
        if (root->val == value)
            return root;

        if (value < root->val)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}


int main() {

    Solution solution;


    // Test Case 1
    TreeNode* root1 = createBST({6, 2, 8, 0, 4, 7, 9, 3, 5});

    TreeNode* p1 = findNode(root1, 2);
    TreeNode* q1 = findNode(root1, 8);

    TreeNode* result1 = solution.lowestCommonAncestor(root1, p1, q1);

    cout << "Test Case 1: " << result1->val << endl;
    // Expected: 6


    // Test Case 2
    TreeNode* root2 = createBST({6, 2, 8, 0, 4, 7, 9, 3, 5});

    TreeNode* p2 = findNode(root2, 2);
    TreeNode* q2 = findNode(root2, 4);

    TreeNode* result2 = solution.lowestCommonAncestor(root2, p2, q2);

    cout << "Test Case 2: " << result2->val << endl;
    // Expected: 2


    // Test Case 3
    TreeNode* root3 = createBST({6, 2, 8, 0, 4, 7, 9, 3, 5});

    TreeNode* p3 = findNode(root3, 3);
    TreeNode* q3 = findNode(root3, 5);

    TreeNode* result3 = solution.lowestCommonAncestor(root3, p3, q3);

    cout << "Test Case 3: " << result3->val << endl;
    // Expected: 4


    // Test Case 4 - One node is ancestor of the other
    TreeNode* root4 = createBST({6, 2, 8, 0, 4, 7, 9, 3, 5});

    TreeNode* p4 = findNode(root4, 2);
    TreeNode* q4 = findNode(root4, 5);

    TreeNode* result4 = solution.lowestCommonAncestor(root4, p4, q4);

    cout << "Test Case 4: " << result4->val << endl;
    // Expected: 2


    // Test Case 5 - Both nodes on right side
    TreeNode* root5 = createBST({6, 2, 8, 0, 4, 7, 9});

    TreeNode* p5 = findNode(root5, 7);
    TreeNode* q5 = findNode(root5, 9);

    TreeNode* result5 = solution.lowestCommonAncestor(root5, p5, q5);

    cout << "Test Case 5: " << result5->val << endl;
    // Expected: 8


    // Test Case 6 - Both nodes on left side
    TreeNode* root6 = createBST({6, 2, 8, 0, 4, 7, 9});

    TreeNode* p6 = findNode(root6, 0);
    TreeNode* q6 = findNode(root6, 4);

    TreeNode* result6 = solution.lowestCommonAncestor(root6, p6, q6);

    cout << "Test Case 6: " << result6->val << endl;
    // Expected: 2


    // Test Case 7 - One node is root
    TreeNode* root7 = createBST({6, 2, 8, 0, 4, 7, 9});

    TreeNode* p7 = findNode(root7, 6);
    TreeNode* q7 = findNode(root7, 9);

    TreeNode* result7 = solution.lowestCommonAncestor(root7, p7, q7);

    cout << "Test Case 7: " << result7->val << endl;
    // Expected: 6


    // Test Case 8 - Same node
    TreeNode* root8 = createBST({5, 3, 7, 2, 4, 6, 8});

    TreeNode* p8 = findNode(root8, 4);
    TreeNode* q8 = findNode(root8, 4);

    TreeNode* result8 = solution.lowestCommonAncestor(root8, p8, q8);

    cout << "Test Case 8: " << result8->val << endl;
    // Expected: 4


    return 0;
}