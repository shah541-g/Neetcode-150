#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* prev = NULL, *crr = head, *next = crr->next;
        while(crr!=NULL){
            next = crr->next;
            crr->next = prev;
            prev = crr;
            crr = next;
        }
        return prev;
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
    ListNode* result1 = sol.reverseList(head1);
    printList(result1);
    // Expected: 5 -> 4 -> 3 -> 2 -> 1


    // Test Case 2
    ListNode* head2 = createList({1, 2});

    cout << "Test Case 2: ";
    ListNode* result2 = sol.reverseList(head2);
    printList(result2);
    // Expected: 2 -> 1


    // Test Case 3
    ListNode* head3 = createList({1});

    cout << "Test Case 3: ";
    ListNode* result3 = sol.reverseList(head3);
    printList(result3);
    // Expected: 1


    // Test Case 4
    ListNode* head4 = createList({});

    cout << "Test Case 4: ";
    ListNode* result4 = sol.reverseList(head4);
    printList(result4);
    // Expected: empty list


    // Test Case 5
    ListNode* head5 = createList({10, 20, 30, 40});

    cout << "Test Case 5: ";
    ListNode* result5 = sol.reverseList(head5);
    printList(result5);
    // Expected: 40 -> 30 -> 20 -> 10


    // Test Case 6
    ListNode* head6 = createList({5, 4, 3, 2, 1});

    cout << "Test Case 6: ";
    ListNode* result6 = sol.reverseList(head6);
    printList(result6);
    // Expected: 1 -> 2 -> 3 -> 4 -> 5

    return 0;
}