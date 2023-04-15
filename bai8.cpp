#include <iostream>
#include <list>

using namespace std;
struct List;
struct Tree;

struct List{
    int value;
    List* next;
    Tree* root;
};
void Push(List* &head, int x){
    List* p = new List;
    p->value = x;
    p->next = NULL;
    p->root = NULL;
    if(head == NULL){
        head = p;
    }else{
        List* i = head;
        while(i->next != NULL)
            i = i->next;
        i->next = p;
    }
}
int len(List* head){
    int Len = 0;
    for(List* i = head; i != NULL; i=i->next)
        Len++;
    return Len;
}
struct Tree{
    int value;
    List* head;
};
void Push(Tree* &root, int cha, int con){
    if(root == NULL){
        root = new Tree;
        root->value = cha;
        root->head = NULL;
        Push(root->head, con);
    }else{
        if(root->value == cha){
            Push(root->head, con);
        }else{
            for(List* i = root->head; i != NULL; i = i->next)
                Push(i->root, cha, con);
        }
    }
}
void Xuat(Tree* root){
    if(root != NULL){
        cout << root->value << " ";
        for(List* i = root->head; i != NULL; i = i->next)
            Xuat(i->root);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    Tree* root = NULL;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        Push(root, x, y);
    }
    Xuat(root);
    return 0;
}