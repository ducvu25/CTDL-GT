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
    if(head == NULL){
    	head = p;
    	return;
	}
    Node *i = head;
    while(i->next != NULL)
    	i=i->next;
    i->next = p;
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
        if(s == "enqueue"){
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
enqueue 1
enqueue 2
enqueue 3
enqueue 4
dequeue
dequeue
enqueue 5


*/
