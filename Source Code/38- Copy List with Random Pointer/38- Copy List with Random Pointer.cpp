#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* current = head;
        Node* copy = NULL;
        unordered_map<Node*,Node*> oldToCopMap;

        while(current!=NULL){
            oldToCopMap[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        while(current!=NULL){
            Node* copy = oldToCopMap[current];
            copy->next = oldToCopMap[current->next];
            copy->random = oldToCopMap[current->random];
            current = current->next;
        }
        return oldToCopMap[head];
    }
};

// Helper function to create a random linked list
Node* createList(vector<int> values, vector<int> randomIndexes) {
    if(values.empty())
        return NULL;

    vector<Node*> nodes;

    for(int val : values) {
        nodes.push_back(new Node(val));
    }

    for(int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    for(int i = 0; i < nodes.size(); i++) {
        if(randomIndexes[i] != -1)
            nodes[i]->random = nodes[randomIndexes[i]];
    }

    return nodes[0];
}

// Helper function to print the list
void printList(Node* head) {
    Node* current = head;

    while(current != NULL) {
        cout << "[" << current->val << ", ";

        if(current->random != NULL)
            cout << current->random->val;
        else
            cout << "NULL";

        cout << "]";

        if(current->next != NULL)
            cout << " -> ";

        current = current->next;
    }

    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    // [7,NULL] -> [13,7] -> [11,1] -> [10,11] -> [1,7]
    Node* head1 = createList(
        {7, 13, 11, 10, 1},
        {-1, 0, 3, 2, 0}
    );

    cout << "Test Case 1: ";
    Node* result1 = sol.copyRandomList(head1);
    printList(result1);
    // Expected: [7,NULL] -> [13,7] -> [11,10] -> [10,11] -> [1,7]


    // Test Case 2
    // [1,NULL] -> [2,1]
    Node* head2 = createList(
        {1, 2},
        {-1, 0}
    );

    cout << "Test Case 2: ";
    Node* result2 = sol.copyRandomList(head2);
    printList(result2);
    // Expected: [1,NULL] -> [2,1]


    // Test Case 3
    // Single node with random pointing to itself
    Node* head3 = createList(
        {1},
        {0}
    );

    cout << "Test Case 3: ";
    Node* result3 = sol.copyRandomList(head3);
    printList(result3);
    // Expected: [1,1]


    // Test Case 4
    // Single node with no random pointer
    Node* head4 = createList(
        {1},
        {-1}
    );

    cout << "Test Case 4: ";
    Node* result4 = sol.copyRandomList(head4);
    printList(result4);
    // Expected: [1,NULL]


    // Test Case 5
    // All random pointers point to themselves
    Node* head5 = createList(
        {1, 2, 3, 4},
        {0, 1, 2, 3}
    );

    cout << "Test Case 5: ";
    Node* result5 = sol.copyRandomList(head5);
    printList(result5);
    // Expected: [1,1] -> [2,2] -> [3,3] -> [4,4]


    // Test Case 6
    // Random pointers form a cycle
    Node* head6 = createList(
        {10, 20, 30},
        {2, 0, 1}
    );

    cout << "Test Case 6: ";
    Node* result6 = sol.copyRandomList(head6);
    printList(result6);
    // Expected: [10,30] -> [20,10] -> [30,20]


    // Test Case 7
    // Empty list
    Node* head7 = NULL;

    cout << "Test Case 7: ";
    Node* result7 = sol.copyRandomList(head7);
    printList(result7);
    // Expected: empty list

    return 0;
}