#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* newNode(int x){ // tạo node
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}
void Push(Node* &head, int y){ // chèn vào vị trí x
    Node* p = newNode(y);
    p->next = head;
    head = p;
}
void deleteX(Node* &head){
    Node* p = head;
    head = head->next;
    delete p;
}
void Print(Node* head){
    Node* i = head;
    while(i != NULL){
        cout << i->data << " ";
        i = i->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s; 
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            Push(head, x);
        }else {
            deleteX(head);
        }
    }
    Print(head);
    return 0;
}
/*
7
push 1
push 2
push 3
push 4
pop
pop
push 5

5 2 1

*/
