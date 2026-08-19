#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node{
  public:
  int val, min;
  Node* next;
  Node(int val, int min, Node *next){
    this->val = val;
    this->min = min;
    this-> next = next;
  }
};

class MinStack {
    Node* head;
public:
    MinStack() {
        head = NULL;
    }
    
    void push(int value) {
      if(head==NULL){
        head = new Node(value,value,NULL);
      }
      else{
        int min = head->min > value ? value : head->min;
        head = new Node(value,min,head);
      }
    }
    
    void pop() {
       Node* temp = head;
       head = head->next;
       delete temp;
    }
    
    int top() {
      return head->val;
    }
    
    int getMin() {
     return head->min; 
    }
};

int main() {
    MinStack obj;

    cout << "Test Case 1:\n";

    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    cout << "getMin(): " << obj.getMin() << endl;  // -3

    obj.pop();

    cout << "top(): " << obj.top() << endl;        // 0
    cout << "getMin(): " << obj.getMin() << endl;  // -2


    cout << "\nTest Case 2:\n";

    MinStack obj2;

    obj2.push(5);
    obj2.push(3);
    obj2.push(7);
    obj2.push(1);
    obj2.push(4);

    cout << "top(): " << obj2.top() << endl;        // 4
    cout << "getMin(): " << obj2.getMin() << endl;  // 1

    obj2.pop();

    cout << "top(): " << obj2.top() << endl;        // 1
    cout << "getMin(): " << obj2.getMin() << endl; // 1

    obj2.pop();

    cout << "top(): " << obj2.top() << endl;        // 7
    cout << "getMin(): " << obj2.getMin() << endl;  // 3


    cout << "\nTest Case 3:\n";

    MinStack obj3;

    obj3.push(2);
    obj3.push(2);
    obj3.push(1);
    obj3.push(1);

    cout << "getMin(): " << obj3.getMin() << endl;  // 1

    obj3.pop();

    cout << "getMin(): " << obj3.getMin() << endl;  // 1

    obj3.pop();

    cout << "getMin(): " << obj3.getMin() << endl;  // 2


    cout << "\nTest Case 4:\n";

    MinStack obj4;

    obj4.push(-10);
    obj4.push(-20);
    obj4.push(-5);
    obj4.push(-30);

    cout << "top(): " << obj4.top() << endl;        // -30
    cout << "getMin(): " << obj4.getMin() << endl;  // -30

    obj4.pop();

    cout << "top(): " << obj4.top() << endl;        // -5
    cout << "getMin(): " << obj4.getMin() << endl;  // -20

    return 0;
}