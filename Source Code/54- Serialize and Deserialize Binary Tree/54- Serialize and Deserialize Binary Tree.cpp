#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    vector<string> treeSequence;
    vector<string> nodesSequence;
    int i;

    void dfs(TreeNode * root){
        if (!root){
            treeSequence.push_back("N");
            return;
        }
        treeSequence.push_back(to_string(root->val));
        dfs(root->left);
        dfs(root->right);
    }

    TreeNode* dfs(){
        if(nodesSequence[i]=="N"){
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(nodesSequence[i++]));
        root->left = dfs();
        root->right = dfs();
        return root;
    }

    vector<string> split(string str, char delimiter){
        vector<string> tokens;
        string token;
        stringstream ss(str);
        while(getline(ss,token,delimiter)){
            tokens.push_back(token);
        }
        return tokens;
    }

    string vTos(vector<string> s){
        string str = "";
        for(int i=0; i<s.size(); i++){
            str += s[i];
            if(i!=s.size()-1){
                str += ",";
            }
        }
        return str;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs(root);
        string s = vTos(treeSequence);
        treeSequence.clear();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        nodesSequence = split(data, ',');
        i = 0;
        TreeNode* root = dfs();
        nodesSequence.clear();
        return root;
    }
};

// Print test results
void testCodec(TreeNode* root, int testNumber, string expected) {
    Codec ser, deser;

    string serialized = ser.serialize(root);

    TreeNode* reconstructed = deser.deserialize(serialized);

    string reserialized = ser.serialize(reconstructed);

    cout << "\nTest Case " << testNumber << ":" << endl;

    cout << "Serialized: " << serialized << endl;
    cout << "Expected:   " << expected << endl;

    cout << "Reserialized: " << reserialized << endl;

    cout << "Result: "
         << (serialized == reserialized ? "PASS" : "FAIL")
         << endl;
}

int main() {

    // Test Case 1: Normal binary tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);

    testCodec(root1, 1, "1,2,N,N,3,4,N,N,5,N,N");

    // Test Case 2: Single node
    TreeNode* root2 = new TreeNode(10);

    testCodec(root2, 2, "10,N,N");

    // Test Case 3: Left-skewed tree
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->left->left = new TreeNode(3);
    root3->left->left->left = new TreeNode(4);

    testCodec(root3, 3, "1,2,3,4,N,N,N,N,N");

    // Test Case 4: Right-skewed tree
    TreeNode* root4 = new TreeNode(1);
    root4->right = new TreeNode(2);
    root4->right->right = new TreeNode(3);
    root4->right->right->right = new TreeNode(4);

    testCodec(root4, 4, "1,N,2,N,3,N,4,N,N");

    // Test Case 5: Balanced binary tree
    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(5);
    root5->right->left = new TreeNode(6);
    root5->right->right = new TreeNode(7);

    testCodec(root5, 5, "1,2,4,N,N,5,N,N,3,6,N,N,7,N,N");

    // Test Case 6: Negative values
    TreeNode* root6 = new TreeNode(-1);
    root6->left = new TreeNode(-2);
    root6->right = new TreeNode(-3);

    testCodec(root6, 6, "-1,-2,N,N,-3,N,N");

    // Test Case 7: Empty tree
    TreeNode* root7 = NULL;

    testCodec(root7, 7, "N");

    // Test Case 8: Mixed structure
    TreeNode* root8 = new TreeNode(10);
    root8->left = new TreeNode(5);
    root8->right = new TreeNode(15);
    root8->left->right = new TreeNode(7);
    root8->right->left = new TreeNode(12);
    root8->right->left->right = new TreeNode(13);

    testCodec(root8, 8, "10,5,N,7,N,N,15,12,N,13,N,N,N");

    return 0;
}