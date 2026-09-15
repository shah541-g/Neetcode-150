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
    void reorderList(ListNode* head) {
        ListNode* sP = head, *fP = head, *mid = NULL;
        while(fP!=NULL){
            if(fP->next==NULL){
                mid = sP->next;
                sP->next = NULL;
                break;
            }
            if(fP->next->next==NULL){
                mid = sP->next;
                sP->next = NULL;
                break;
            }
            sP = sP->next;
            fP = fP->next->next;
        }
        ListNode* prev = NULL;
        while(mid!=NULL){
            ListNode* next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        ListNode *second = prev, *first = head;
        while(second!=NULL && first!=NULL){
            ListNode* fNext = first->next;
            ListNode* sNext = second->next;
            first->next = second;
            second->next = fNext;
            second = sNext;
            first = fNext;
        }

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
    ListNode* head1 = createList({1, 2, 3, 4});

    cout << "Test Case 1: ";
    sol.reorderList(head1);
    printList(head1);
    // Expected: 1 -> 4 -> 2 -> 3


    // Test Case 2
    ListNode* head2 = createList({1, 2, 3, 4, 5});

    cout << "Test Case 2: ";
    sol.reorderList(head2);
    printList(head2);
    // Expected: 1 -> 5 -> 2 -> 4 -> 3


    // Test Case 3
    ListNode* head3 = createList({1, 2});

    cout << "Test Case 3: ";
    sol.reorderList(head3);
    printList(head3);
    // Expected: 1 -> 2


    // Test Case 4
    ListNode* head4 = createList({1});

    cout << "Test Case 4: ";
    sol.reorderList(head4);
    printList(head4);
    // Expected: 1


    // Test Case 5
    ListNode* head5 = createList({1, 2, 3, 4, 5, 6});

    cout << "Test Case 5: ";
    sol.reorderList(head5);
    printList(head5);
    // Expected: 1 -> 6 -> 2 -> 5 -> 3 -> 4


    // Test Case 6
    ListNode* head6 = createList({10, 20, 30, 40, 50, 60, 70});

    cout << "Test Case 6: ";
    sol.reorderList(head6);
    printList(head6);
    // Expected: 10 -> 70 -> 20 -> 60 -> 30 -> 50 -> 40


    // Test Case 7
    ListNode* head7 = createList({1, 2, 3, 4, 5, 6, 7, 8});

    cout << "Test Case 7: ";
    sol.reorderList(head7);
    printList(head7);
    // Expected: 1 -> 8 -> 2 -> 7 -> 3 -> 6 -> 4 -> 5


    // Test Case 8
    ListNode* head8 = createList({});

    cout << "Test Case 8: ";
    sol.reorderList(head8);
    printList(head8);
    // Expected: empty list

    return 0;
}