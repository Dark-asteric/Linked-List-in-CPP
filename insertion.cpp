// Online C++ compiler to run C++ program online
// https://www.youtube.com/watch?v=Kz_6lUoDO_Y
#include <iostream>
using namespace std;

class Node{
  public:
  int val;
  Node* next;
  Node(int data){
      val = data;
      next = NULL;
  }
};

void insertAtHead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node ->next = head;
    head = new_node;
    
}

void insertAtTail(Node* &head, int val){
    Node* tmp = head;
    while(tmp->next != 0){
        tmp = tmp->next;
    }
    Node* new_node = new Node(val);
    tmp->next = new_node;
}

void insertAtPosition(Node* &head,int val, int pos){
    if(pos == 0){
        insertAtHead(head,val);
        return;
    }
    Node* tmp = head;
    int cur = 0;
    while(cur != pos-1){
        tmp = tmp->next;
        cur++;
    }
    Node* new_node = new Node(val);
    new_node -> next = tmp->next;
    tmp->next = new_node;
}
void display(Node* head){
    Node* tmp = head;
    while(tmp != 0){
        cout<<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<"NULL\n";
}
int main() {
    // Write C++ code here
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,4);
    insertAtTail(head,0);
    display(head);
    insertAtPosition(head,3,1);
    display(head);
    return 0;
}
