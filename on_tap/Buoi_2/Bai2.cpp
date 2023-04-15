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
void PushX(Node* &head, int x, int y){ // chèn vào vị trí x
    Node* p = newNode(y);
    if(x == 0){
        p->next = head;
        head = p;
        return;
    }
    int j = 1;
    Node *i = head;
    for( ; i->next != NULL; i=i->next, j++){
        if(j == x){
            p->next = i->next;
            i->next = p;
            return;
        }
    }
    i->next = p;
}

void deleteX(Node* &head, int x){
    if(x == 0){
        Node* p = head;
        head = head->next;
        delete p;
        return;
    }
    int j = 1;
    Node *i = head;
    for( ; i->next != NULL; i=i->next, j++){
        if(j == x){
            Node * p = i->next;
            i->next = i->next->next;
            delete p;
            return;
        }
    }
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
        if(s == "insert"){
            int x, y;
            cin >> x >> y;
            PushX(head, x, y);
        }else {
            int x;
            cin >> x;
            deleteX(head, x);
        }
    }
    Print(head);
    return 0;
}
/*
7
insert 0 1
insert 1 3
insert 1 4
insert 1 6
insert 2 2
delete 1
delete 3

*/
