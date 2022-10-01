/*
    + B1: Khai báo cấu trúc dữ liệu
    + B2: Khởi tạo
    + B3: Tạo node
    + B4: Thêm node vào cấu trúc    
    + B5: Input/OutPut
    + B6: Xử lý: thêm/xóa/tìm kiếm/sửa
    + B7: Giải phóng
*/
//VD: stack số nguyên

#include <iostream>
using namespace std;

/*======================= B1: Khai báo cấu trúc dữ liệu ======================*/
struct Node{
    int data;
    Node *next;
};
/*==================================================*/

/*======================= B2: Khởi tạo ======================*/
void Init(Node *&t){
    t = NULL;
}
/*==================================================*/

/*======================= B3: Tạo node ======================*/
Node *newNode(int x){
    Node *p = new Node;
    if(p != NULL){
        p->data = x;
        p->next = NULL;
    }
    return p;
}
/*==================================================*/

/*======================= B4: Thêm node ======================*/
/*  1: Kiểm tra stack có còn rỗng không?
    2: Push: Thêm 1 node
    3: Pop: Xóa node
    4: t: Xem node
*/
bool Empty(Node *t){
    if(t == NULL)
        return true;
    return false;
}
bool Push(Node *&t, int x){ // thành công trả về true >< trả về flase
    Node *p = newNode(x);
    if(p == NULL)
        return false;
    p->next = t;
    t = p;
    return true;
}
bool Pop(Node *&t){
    Node *p = t;
    t = t->next;
    delete p;
    return true;
}
int Top(Node *t){
    return t->data;
}
/*==================================================*/

/*======================= B5: Nhập/Xuất ======================*/
void Scan(Node *&t){
    Init(t);
    int n;
    cout << "Nhap so luong: "; cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        Push(t, x);
    }
}
void Print(Node *&t){
    while(!Empty(t)){
        cout << Top(t) << " ";
        Pop(t);
    }
    cout << endl;
}
/*==================================================*/

int main(){
    Node* t;
    Scan(t);
    Print(t);
    return 0;
}
