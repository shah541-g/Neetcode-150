#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> nodesReferences;
        while(head!=NULL){
            if(nodesReferences.count(head)){
                return true;
            } 
            nodesReferences.insert(head);
            head=head->next;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    // 3 -> 2 -> 0 -> -4
    //      ^         |
    //      |_________|
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    cout << boolalpha;
    cout << "Test Case 1: " << sol.hasCycle(node1) << endl;
    // Expected: true


    // Test Case 2
    // 1 -> 2 -> NULL
    ListNode* node5 = new ListNode(1);
    ListNode* node6 = new ListNode(2);

    node5->next = node6;

    cout << "Test Case 2: " << sol.hasCycle(node5) << endl;
    // Expected: false


    // Test Case 3
    // 1 -> 2 -> 3
    //      ^    |
    //      |____|
    ListNode* node7 = new ListNode(1);
    ListNode* node8 = new ListNode(2);
    ListNode* node9 = new ListNode(3);

    node7->next = node8;
    node8->next = node9;
    node9->next = node8;

    cout << "Test Case 3: " << sol.hasCycle(node7) << endl;
    // Expected: true


    // Test Case 4
    // Single node with cycle
    ListNode* node10 = new ListNode(1);
    node10->next = node10;

    cout << "Test Case 4: " << sol.hasCycle(node10) << endl;
    // Expected: true


    // Test Case 5
    // Single node without cycle
    ListNode* node11 = new ListNode(1);

    cout << "Test Case 5: " << sol.hasCycle(node11) << endl;
    // Expected: false


    // Test Case 6
    // Empty list
    ListNode* node12 = NULL;

    cout << "Test Case 6: " << sol.hasCycle(node12) << endl;
    // Expected: false


    // Test Case 7
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ListNode* node13 = new ListNode(1);
    ListNode* node14 = new ListNode(2);
    ListNode* node15 = new ListNode(3);
    ListNode* node16 = new ListNode(4);
    ListNode* node17 = new ListNode(5);

    node13->next = node14;
    node14->next = node15;
    node15->next = node16;
    node16->next = node17;

    cout << "Test Case 7: " << sol.hasCycle(node13) << endl;
    // Expected: false

    return 0;
}