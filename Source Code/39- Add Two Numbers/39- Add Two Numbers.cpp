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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;

        while(l1!=NULL || l2!=NULL || carry){
            int val1 = l1!=NULL ? l1->val : 0;
            int val2 = l2!=NULL ? l2->val : 0;
            int val = val1 + val2 + carry;
            carry = val / 10;
            val = val%10;
            current->next = new ListNode(val);
            current = current->next;
            l1= l1!=NULL ? l1->next : NULL;
            l2= l2!=NULL ? l2->next : NULL;
        }
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
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    cout << "Test Case 1: ";
    ListNode* result1 = sol.addTwoNumbers(l1, l2);
    printList(result1);
    // Expected: 7 -> 0 -> 8
    // 342 + 465 = 807


    // Test Case 2
    ListNode* l3 = createList({0});
    ListNode* l4 = createList({0});

    cout << "Test Case 2: ";
    ListNode* result2 = sol.addTwoNumbers(l3, l4);
    printList(result2);
    // Expected: 0


    // Test Case 3
    ListNode* l5 = createList({9, 9, 9});
    ListNode* l6 = createList({1});

    cout << "Test Case 3: ";
    ListNode* result3 = sol.addTwoNumbers(l5, l6);
    printList(result3);
    // Expected: 0 -> 0 -> 0 -> 1
    // 999 + 1 = 1000


    // Test Case 4
    ListNode* l7 = createList({1});
    ListNode* l8 = createList({9, 9, 9});

    cout << "Test Case 4: ";
    ListNode* result4 = sol.addTwoNumbers(l7, l8);
    printList(result4);
    // Expected: 0 -> 0 -> 0 -> 1
    // 1 + 999 = 1000


    // Test Case 5
    ListNode* l9 = createList({9});
    ListNode* l10 = createList({9});

    cout << "Test Case 5: ";
    ListNode* result5 = sol.addTwoNumbers(l9, l10);
    printList(result5);
    // Expected: 8 -> 1
    // 9 + 9 = 18


    // Test Case 6
    ListNode* l11 = createList({2, 4, 9});
    ListNode* l12 = createList({5, 6, 4, 9});

    cout << "Test Case 6: ";
    ListNode* result6 = sol.addTwoNumbers(l11, l12);
    printList(result6);
    // Expected: 7 -> 0 -> 4 -> 9
    // 942 + 9465 = 10407
    // Actually represented as: 7 -> 0 -> 4 -> 0 -> 1


    // Test Case 7
    ListNode* l13 = createList({1, 8});
    ListNode* l14 = createList({0});

    cout << "Test Case 7: ";
    ListNode* result7 = sol.addTwoNumbers(l13, l14);
    printList(result7);
    // Expected: 1 -> 8


    // Test Case 8
    ListNode* l15 = createList({9, 9, 9, 9, 9});
    ListNode* l16 = createList({1});

    cout << "Test Case 8: ";
    ListNode* result8 = sol.addTwoNumbers(l15, l16);
    printList(result8);
    // Expected: 0 -> 0 -> 0 -> 0 -> 0 -> 1

    return 0;
}