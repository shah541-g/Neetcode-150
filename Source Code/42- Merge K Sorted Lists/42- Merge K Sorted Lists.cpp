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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        while (lists.size()>1){
            vector<ListNode*> mergedLists;
            for (int i=0; i<lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1<lists.size() ? lists[i+1] : NULL;
                mergedLists.push_back(merge(l1,l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while(l1 && l2){
            if(l1->val<l2->val){
                tail->next = l1;
                l1 = l1->next;
            } else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if(l1){
            tail->next = l1;
        }

        if(l2){
            tail->next = l2;
        }

        return dummy->next;
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
    vector<ListNode*> lists1 = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };

    ListNode* result1 = solution.mergeKLists(lists1);

    cout << "Test Case 1: ";
    printList(result1);
    // Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6


    // Test Case 2 - Three simple lists
    vector<ListNode*> lists2 = {
        createList({1}),
        createList({2}),
        createList({3})
    };

    ListNode* result2 = solution.mergeKLists(lists2);

    cout << "Test Case 2: ";
    printList(result2);
    // Expected: 1 -> 2 -> 3


    // Test Case 3 - Already ordered lists
    vector<ListNode*> lists3 = {
        createList({1, 2, 3}),
        createList({4, 5, 6})
    };

    ListNode* result3 = solution.mergeKLists(lists3);

    cout << "Test Case 3: ";
    printList(result3);
    // Expected: 1 -> 2 -> 3 -> 4 -> 5 -> 6


    // Test Case 4 - Different number of elements
    vector<ListNode*> lists4 = {
        createList({1, 3, 5}),
        createList({2, 4}),
        createList({0, 6, 7, 8})
    };

    ListNode* result4 = solution.mergeKLists(lists4);

    cout << "Test Case 4: ";
    printList(result4);
    // Expected: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8


    // Test Case 5 - Empty vector
    vector<ListNode*> lists5;

    ListNode* result5 = solution.mergeKLists(lists5);

    cout << "Test Case 5: ";
    printList(result5);
    // Expected: empty


    // Test Case 6 - One list
    vector<ListNode*> lists6 = {
        createList({1, 2, 3, 4})
    };

    ListNode* result6 = solution.mergeKLists(lists6);

    cout << "Test Case 6: ";
    printList(result6);
    // Expected: 1 -> 2 -> 3 -> 4


    // Test Case 7 - Some empty lists
    vector<ListNode*> lists7 = {
        NULL,
        createList({1, 2}),
        NULL,
        createList({3, 4})
    };

    ListNode* result7 = solution.mergeKLists(lists7);

    cout << "Test Case 7: ";
    printList(result7);
    // Expected: 1 -> 2 -> 3 -> 4


    // Test Case 8 - Duplicate values
    vector<ListNode*> lists8 = {
        createList({1, 1, 1}),
        createList({1, 1}),
        createList({1})
    };

    ListNode* result8 = solution.mergeKLists(lists8);

    cout << "Test Case 8: ";
    printList(result8);
    // Expected: 1 -> 1 -> 1 -> 1 -> 1 -> 1


    return 0;
}