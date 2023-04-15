#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *pHead;
    Node *pPrev;
};

Node* newNode(int x){ // tạo node
    Node* p = new Node;
    p->data = x;
    p->pHead = NULL;
    p->pPrev = NULL;
    return p;
}
void PushX(Node* &head, int x){ // chèn vào vị trí x
    Node* p = newNode(x);
    if(head == NULL){
    	head = p;
    	return;
	}
    p->pPrev = head;
    head->pHead = p;
    head = p;
}

int Count(Node* head){
    int count = 0;
    for(Node* i=head->pPrev; i->pPrev != NULL; i=i->pPrev)
        if(i->pPrev->data + i->data + i->pHead->data == 0)
            count++;
    return count;
}
void Print(Node* head){
    Node* i = head;
    while(i != NULL){
        cout << i->data << " ";
        i = i->pPrev;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
    	int x;  cin >> x;
        PushX(head, x);
    }
    cout << Count(head);
    return 0;
}
/*
6
5 -3 -2 2 9 -11


*/
