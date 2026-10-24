#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while (true){
            ListNode* kthNode = getKthNode(groupPrev,k);
            if (!kthNode){
                break;
            }
            ListNode* groupNext = kthNode->next;

            ListNode* prev = kthNode->next;
            ListNode* curr = groupPrev->next;

            while(curr!=groupNext){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kthNode;
            groupPrev = temp;
        }
        return dummy->next;
    }

    ListNode* getKthNode(ListNode* curr, int k ){
        while (curr && k>=1){
            curr = curr->next;
            k-=1;
        }
        return curr;
    }
};


// Create linked list
ListNode* createList(vector<int> values) {
    if (values.empty())
        return NULL;

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;

    for (int i = 1; i < values.size(); i++) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }

    return head;
}


// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}


int main() {

    Solution solution;


    // Test Case 1
    ListNode* head1 = createList({1, 2, 3, 4, 5});

    ListNode* result1 = solution.reverseKGroup(head1, 2);

    cout << "Test Case 1: ";
    printList(result1);
    // Expected: 2 -> 1 -> 4 -> 3 -> 5


    // Test Case 2
    ListNode* head2 = createList({1, 2, 3, 4, 5});

    ListNode* result2 = solution.reverseKGroup(head2, 3);

    cout << "Test Case 2: ";
    printList(result2);
    // Expected: 3 -> 2 -> 1 -> 4 -> 5


    // Test Case 3 - k = 1
    ListNode* head3 = createList({1, 2, 3, 4, 5});

    ListNode* result3 = solution.reverseKGroup(head3, 1);

    cout << "Test Case 3: ";
    printList(result3);
    // Expected: 1 -> 2 -> 3 -> 4 -> 5


    // Test Case 4 - k equals list size
    ListNode* head4 = createList({1, 2, 3, 4});

    ListNode* result4 = solution.reverseKGroup(head4, 4);

    cout << "Test Case 4: ";
    printList(result4);
    // Expected: 4 -> 3 -> 2 -> 1


    // Test Case 5 - k greater than list size
    ListNode* head5 = createList({1, 2, 3});

    ListNode* result5 = solution.reverseKGroup(head5, 5);

    cout << "Test Case 5: ";
    printList(result5);
    // Expected: 1 -> 2 -> 3


    // Test Case 6 - Single node
    ListNode* head6 = createList({1});

    ListNode* result6 = solution.reverseKGroup(head6, 2);

    cout << "Test Case 6: ";
    printList(result6);
    // Expected: 1


    // Test Case 7 - Empty list
    ListNode* head7 = createList({});

    ListNode* result7 = solution.reverseKGroup(head7, 2);

    cout << "Test Case 7: ";
    printList(result7);
    // Expected: empty


    // Test Case 8 - Multiple complete groups
    ListNode* head8 = createList({1, 2, 3, 4, 5, 6, 7, 8});

    ListNode* result8 = solution.reverseKGroup(head8, 4);

    cout << "Test Case 8: ";
    printList(result8);
    // Expected: 4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5


    // Test Case 9 - Duplicate values
    ListNode* head9 = createList({1, 1, 2, 2, 3, 3});

    ListNode* result9 = solution.reverseKGroup(head9, 2);

    cout << "Test Case 9: ";
    printList(result9);
    // Expected: 1 -> 1 -> 2 -> 2 -> 3 -> 3


    return 0;
}