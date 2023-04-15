#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};
void Init(Node* &head){
    head = NULL;
}
void Push(Node *&head, int x){
    Node *p = new Node;
    p->value = x;
    p->next = head;
    head = p;
}
int Count(Node* head){
    int count = 0;
    for(Node* i = head; i->next != NULL; i=i->next)
        for(Node* j=i->next; j!= NULL; j=j->next)
            if(i->value == j->value)
                count++;
    return count;
}

int main(){
    int n;
    cin >> n;
    Node* head;
    Init(head);
    for(int i=0; i<n; i++){
        int x; cin >> x;
        Push(head, x);
    }
    cout << Count(head);
}
