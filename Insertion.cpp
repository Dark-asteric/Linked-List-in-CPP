/**
*	author: shafi
*	created: 25.01.2024 20.56.00
**/
// https://www.youtube.com/watch?v=Kz_6lUoDO_Y - part 1
// https://www.youtube.com/watch?v=OjGR1GpEukY - part 2

#include "bits/stdc++.h"
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
void insertionAtHead(Node* &head,int val){
    Node* new_node = new Node(val);
    new_node -> next = head;
    head = new_node;
}

void insertionAtTail(Node* &head,int val){
    Node* new_node = new Node(val);
    Node* tmp = head;
    while(tmp -> next != 0){
        tmp = tmp->next;
    }
    tmp -> next = new_node;
}

void insertionAtPos(Node* &head, int val, int pos){
    if(pos == 0){
        Node* new_node = new Node(val);
        new_node -> next = head;
        head = new_node;
    }
    else{
        Node* new_node = new Node(val);
        Node* tmp = head;
        int cnt = 0;
        while(cnt != pos-1){
            tmp = tmp -> next;
            cnt++;
        }
        new_node -> next = tmp->next;
        tmp -> next = new_node;
    }
}

void deletionAtHead(Node* &head){
    if(head == 0){
        return;
    }
    Node* tmp = head;
    head = head -> next;
    delete tmp;
}

void deletionAtTail(Node* &head){
    Node* tmp = head;
    while(tmp -> next ->next != 0){
        tmp = tmp->next;
    }
    delete tmp->next;
    tmp -> next = NULL;
}

void deleteAtPos(Node* &head, int pos){
    if(pos == 0){
        deletionAtHead(head);
        return;
    }
    Node* tmp = head;
    int cur = 0;
    while(cur != pos-1){
        tmp = tmp -> next;
        cur++;
    }
    Node* temp = tmp -> next;
    tmp -> next = tmp -> next -> next;
    delete temp;
}
void updateAtPos(Node* &head,int val, int pos){
    Node* tmp = head;
    int cur = 0;
    while(cur != pos){
        tmp = tmp -> next;
        cur++;
    }
    tmp -> val = val;
}

void display(Node* head){
    Node* tmp = head;
    while(tmp != 0){
        cout<<tmp->val<<"->";
        tmp = tmp -> next;
    }
    cout<<"NULL\n";
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    Node* head = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertionAtHead(head,x);
    }
    display(head);
    int nn;
    cin>>nn;
    for(int i=0;i<nn;i++){
        int x;
        cin>>x;
        insertionAtTail(head,x);
    }
    display(head);
    insertionAtPos(head,4,1);
    display(head);
    updateAtPos(head,0,5);
    display(head);
    deleteAtPos(head,3);
    display(head);
    // delete at head : 
    /**
     deletionAtHead(head);
    display(head);
    // delete at tail :
    deletionAtTail(head);
    display(head);
    ***/
    return 0;
}