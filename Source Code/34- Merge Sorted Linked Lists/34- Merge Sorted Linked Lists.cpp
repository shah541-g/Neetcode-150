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
    void insertIntoList(ListNode*& head, ListNode*& tail, int val){
        if(head==NULL){
            head = new ListNode(val);
            tail = head;
            return;
        }
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                insertIntoList(head, tail, list1->val);
                list1 = list1->next;
            } else{
                insertIntoList(head, tail, list2->val);
                list2 = list2->next;
            }
        }
        while(list1!=NULL){
            insertIntoList(head, tail, list1->val);
            list1 = list1->next;
        }
        while(list2!=NULL){
            insertIntoList(head, tail, list2->val);
            list2 = list2->next;
        }
        return head;
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
    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});

    cout << "Test Case 1: ";
    ListNode* result1 = sol.mergeTwoLists(list1, list2);
    printList(result1);
    // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4


    // Test Case 2
    ListNode* list3 = createList({});
    ListNode* list4 = createList({0});

    cout << "Test Case 2: ";
    ListNode* result2 = sol.mergeTwoLists(list3, list4);
    printList(result2);
    // Expected: 0


    // Test Case 3
    ListNode* list5 = createList({1, 2, 3});
    ListNode* list6 = createList({4, 5, 6});

    cout << "Test Case 3: ";
    ListNode* result3 = sol.mergeTwoLists(list5, list6);
    printList(result3);
    // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6


    // Test Case 4
    ListNode* list7 = createList({1, 3, 5});
    ListNode* list8 = createList({2, 4, 6});

    cout << "Test Case 4: ";
    ListNode* result4 = sol.mergeTwoLists(list7, list8);
    printList(result4);
    // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6


    // Test Case 5
    ListNode* list9 = createList({1});
    ListNode* list10 = createList({2});

    cout << "Test Case 5: ";
    ListNode* result5 = sol.mergeTwoLists(list9, list10);
    printList(result5);
    // Expected: 1 -> 2


    // Test Case 6
    ListNode* list11 = createList({1, 1, 2});
    ListNode* list12 = createList({1, 2, 2});

    cout << "Test Case 6: ";
    ListNode* result6 = sol.mergeTwoLists(list11, list12);
    printList(result6);
    // Expected: 1 -> 1 -> 1 -> 2 -> 2 -> 2

    return 0;
}