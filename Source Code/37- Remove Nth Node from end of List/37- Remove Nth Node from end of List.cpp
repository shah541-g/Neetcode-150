#include <iostream>
#include <initializer_list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while(n>0 && right!=NULL){
            right = right->next;
            n--;
        }
        while(right!=NULL){
            left=left->next;
            right=right->next;
        }
        left->next=left->next->next;
        return dummy->next;
    }
};

// Helper function to create a linked list
ListNode* createList(initializer_list<int> values) {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int val : values) {
        ListNode* newNode = new ListNode(val);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val;

        if(head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    ListNode* head1 = createList({1, 2, 3, 4, 5});

    cout << "Test Case 1: ";
    head1 = sol.removeNthFromEnd(head1, 2);
    printList(head1);
    // Expected: 1 -> 2 -> 3 -> 5


    // Test Case 2
    ListNode* head2 = createList({1});

    cout << "Test Case 2: ";
    head2 = sol.removeNthFromEnd(head2, 1);
    printList(head2);
    // Expected: empty list


    // Test Case 3
    ListNode* head3 = createList({1, 2});

    cout << "Test Case 3: ";
    head3 = sol.removeNthFromEnd(head3, 1);
    printList(head3);
    // Expected: 1


    // Test Case 4
    ListNode* head4 = createList({1, 2});

    cout << "Test Case 4: ";
    head4 = sol.removeNthFromEnd(head4, 2);
    printList(head4);
    // Expected: 2


    // Test Case 5
    ListNode* head5 = createList({1, 2, 3, 4, 5});

    cout << "Test Case 5: ";
    head5 = sol.removeNthFromEnd(head5, 5);
    printList(head5);
    // Expected: 2 -> 3 -> 4 -> 5


    // Test Case 6
    ListNode* head6 = createList({10, 20, 30, 40, 50, 60});

    cout << "Test Case 6: ";
    head6 = sol.removeNthFromEnd(head6, 3);
    printList(head6);
    // Expected: 10 -> 20 -> 30 -> 50 -> 60


    // Test Case 7
    ListNode* head7 = createList({1, 2, 3});

    cout << "Test Case 7: ";
    head7 = sol.removeNthFromEnd(head7, 1);
    printList(head7);
    // Expected: 1 -> 2


    // Test Case 8
    ListNode* head8 = createList({1, 2, 3});

    cout << "Test Case 8: ";
    head8 = sol.removeNthFromEnd(head8, 2);
    printList(head8);
    // Expected: 1 -> 3

    return 0;
}