#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size() || !inorder.size()) return NULL;

        int num = preorder[0];
        TreeNode* root = new TreeNode(num);
        auto it = find(inorder.begin(), inorder.end(), num);
        int mid = distance(inorder.begin(), it);

        vector<int> leftPreorder(mid), leftInorder(mid), rightInorder(inorder.size() - mid - 1), rightPreorder(preorder.size() - mid - 1);

        copy(preorder.begin() + 1, preorder.begin() + mid + 1, leftPreorder.begin());
        copy(inorder.begin(), inorder.begin() + mid, leftInorder.begin());

        root->left = buildTree(leftPreorder, leftInorder);

        copy(preorder.begin() + mid + 1, preorder.end(), rightPreorder.begin());
        copy(inorder.begin() + mid + 1, inorder.end(), rightInorder.begin());

        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};

// Print preorder traversal
void printPreorder(TreeNode* root) {
    if (!root) return;

    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};

    TreeNode* root1 = sol.buildTree(preorder1, inorder1);

    cout << "Test 1:" << endl;
    cout << "Preorder: ";
    printPreorder(root1);
    cout << "\nExpected: 3 9 20 15 7" << endl;

    cout << "Inorder: ";
    printInorder(root1);
    cout << "\nExpected: 9 3 15 20 7" << endl;


    // Test Case 2: Single node
    vector<int> preorder2 = {1};
    vector<int> inorder2 = {1};

    TreeNode* root2 = sol.buildTree(preorder2, inorder2);

    cout << "\nTest 2:" << endl;
    cout << "Preorder: ";
    printPreorder(root2);
    cout << "\nExpected: 1" << endl;

    cout << "Inorder: ";
    printInorder(root2);
    cout << "\nExpected: 1" << endl;


    // Test Case 3: Left-skewed tree
    vector<int> preorder3 = {1, 2, 3, 4};
    vector<int> inorder3 = {4, 3, 2, 1};

    TreeNode* root3 = sol.buildTree(preorder3, inorder3);

    cout << "\nTest 3:" << endl;
    cout << "Preorder: ";
    printPreorder(root3);
    cout << "\nExpected: 1 2 3 4" << endl;

    cout << "Inorder: ";
    printInorder(root3);
    cout << "\nExpected: 4 3 2 1" << endl;


    // Test Case 4: Right-skewed tree
    vector<int> preorder4 = {1, 2, 3, 4};
    vector<int> inorder4 = {1, 2, 3, 4};

    TreeNode* root4 = sol.buildTree(preorder4, inorder4);

    cout << "\nTest 4:" << endl;
    cout << "Preorder: ";
    printPreorder(root4);
    cout << "\nExpected: 1 2 3 4" << endl;

    cout << "Inorder: ";
    printInorder(root4);
    cout << "\nExpected: 1 2 3 4" << endl;


    // Test Case 5: Balanced tree
    vector<int> preorder5 = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder5 = {4, 2, 5, 1, 6, 3, 7};

    TreeNode* root5 = sol.buildTree(preorder5, inorder5);

    cout << "\nTest 5:" << endl;
    cout << "Preorder: ";
    printPreorder(root5);
    cout << "\nExpected: 1 2 4 5 3 6 7" << endl;

    cout << "Inorder: ";
    printInorder(root5);
    cout << "\nExpected: 4 2 5 1 6 3 7" << endl;


    // Test Case 6: Empty tree
    vector<int> preorder6 = {};
    vector<int> inorder6 = {};

    TreeNode* root6 = sol.buildTree(preorder6, inorder6);

    cout << "\nTest 6:" << endl;
    cout << "Preorder: ";
    printPreorder(root6);
    cout << "\nExpected: (empty)" << endl;

    cout << "Inorder: ";
    printInorder(root6);
    cout << "\nExpected: (empty)" << endl;

    return 0;
}