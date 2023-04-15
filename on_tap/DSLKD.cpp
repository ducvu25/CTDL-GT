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
Node* PushFirst(Node* head, int x){ // Thêm vào đầu
    Node* p = newNode(x);
    p->next = head;
    return p;
}
void PushLast(Node* &head, int x){ // thêm vào cuối
    Node* p = newNode(x);
    if(head == NULL){
        head = p;
        return;
    }
    Node* i = head;
    while(i->next != NULL)
        i = i->next;
    i->next = p;
}
void PushNextX(Node* &head, int x, int y){ // chèn vào sau vị trí x
    Node* p = newNode(y);
    Node* i = head;
    while(i->next != NULL){
        if(x == 0){
            p->next = i->next;
            i->next = p;
            return;
        }
        x--;
        i = i->next;
    }
}
void PushX(Node* &head, int x, int y){ // chèn vào vị trí x
    Node* p = newNode(y);
    Node* i = head;
    while(i->next != NULL){
        if(x == 0){
            if(i == head){
                p->next = head;
                head = p;
            }else{
                p->next = i->next;
                i->next = p;
            }
            return;
        }
        x--;
        i = i->next;
    }
}
void PushX2(Node* &head, int x, int y){
    Node* q = NULL;
    Node* p = newNode(y);
    Node* i = head;
    while(i != NULL){
        if( x == 0){
            if(q == NULL){
                head = p;
            }else{
                p->next = q->next;
                q->next = p;
            }
            return;
        }
        q = i;
        i = i->next;
    }
}
void deleteNextX(Node* &head, int x){
    Node* i = head;
    while(i->next != NULL){
        if(x == 0){
            Node* p = i->next;
            i->next = i->next->next;
            delete p;
            return;
        }
        x--;
        i = i->next;
    }
}
void deleteX(Node* &head, int x){
    Node* i = head;
    while(i != NULL){
        if(x == 0){
            if(i == head){
                Node* p = head;
                head = head->next;
                delete p;
            }else{
                Node* p = i->next;
                i->next = i->next->next;
                delete p;
            }      
            return;
        }
        x--;
        i = i->next;
    }
}
int value(Node* head, int x){
    Node* i = head;
    while(i->next != NULL){
        if(x == 0){
            return i->data;
        }
        x--;
        i = i->next;
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
    head = PushFirst(head, 5);
    Print(head);
    PushLast(head, 6);
    PushLast(head, 7);
    Print(head);
    PushNextX(head, 1, 1);
    Print(head);
    PushX(head, 0, 0);
    PushX(head, 1, 2);
    Print(head);
    deleteNextX(head, 0);
    Print(head);
    deleteNextX(head, 2);
    Print(head);
    deleteX(head, 3);
    Print(head);
    cout << "gia tri tai vi tri 2 la: " << value(head, 1) << endl;
    return 0;
}