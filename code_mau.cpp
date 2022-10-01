#include <iostream>
#include <fstream>
#include <queue>
#include <math.h>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int x);
void Push(Node* &head, int x);
Node* Input(char* s);
Node* Init(int k);
void Print_Pre_order(Node* head); // duyệt trước
void Print_In_order(Node* head); // duyệt giữa
void Print_Post_order(Node* head); // duyệt sau
void Print_Bread_first(Node* head); // duyệt theo chiều rộng
int main(){
    Node* head = Input("./input.txt");
   // Node* head = Init(5);
    Print_Pre_order(head);
    cout << endl;
    Print_In_order(head);
    cout << endl;
    Print_Post_order(head);
    cout << endl;
    Print_Bread_first(head);
    return 0;
}
Node* newNode(int x){
    Node* p = new Node;
    p->value = x;
    p->left = NULL;
    p->right = NULL;
}
void Push(Node* &head, int x){
    if(head == NULL)
        head = newNode(x);
    else if(head->value > x)
        Push(head->left, x);
    else
        Push(head->right, x);
}
Node* Input(char* s){
    ifstream cin(s);
    int x;
    Node* head = NULL;
    while(cin >> x){
        Push(head, x);
    }
    return head;
}
Node* Init(int k){
    Node* root = NULL;
    int n = pow(2, k) - 1;
    for(int i=0; i<n; i++)
        Push(root, i);
    return root;
}
void Print_Pre_order(Node* head){ // N - L - R
    if(head != NULL){
        cout << head->value << " ";
        Print_Pre_order(head->left);
        Print_Pre_order(head->right);
    }
}
void Print_In_order(Node* head){ // LNR
    if(head != NULL){
        Print_In_order(head->left);
        cout << head->value << " ";
        Print_In_order(head->right);
    }
}
void Print_Post_order(Node* head){ // LRN
    if(head != NULL){
        Print_Post_order(head->left);
        Print_Post_order(head->right);
        cout << head->value << " ";
    }
}
void Print_Bread_first(Node* head){
    queue <Node*> root;
    root.push(head);
    while(!root.empty()){
    	Node* p = root.front() ;
        cout << p->value << " ";
        if(p->left != NULL)
        	root.push(p->left);
        if(p->right != NULL)
            root.push(p->right);
        root.pop();
    }
}
