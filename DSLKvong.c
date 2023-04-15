#include <stdio.h>
#include <math.h>

int KT(int n){
    if(n < 2)
        return 0;
    int i;
    for(i=2; i<=sqrt(n); i++)
        if(n % i == 0)
            return 0;
    return 1;
}
struct Node{
    int value;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
void Nhap(){
    int n, i;
    printf("Nhap so luong phan tu: ");  scanf("%d", &n);
    for(i = 0; i<n; i++){
        int x; scanf("%d", &x);
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    	p->value = x;
    	p->next = NULL;
    	if(head == NULL){
    		head = p;
    		tail = p;
		}else{
			tail->next = p;
			tail = p;
		}	
    }
    tail->next = head;
}
void Xuat(){
    struct Node* i = head;
    if(i != NULL){
        do{
            printf("%d ", i->value);
            i = i->next;
        }while(i != head);
        printf("\n");
    }
}
void Y2(){
    struct Node* i = head;
    int index = 1;
    int d = 0;
    printf("\nVi tri cac so nguyen to: ");
    if(i != NULL){
        do{
            if(KT(i->value) == 1){
                printf("%d ", index);
                d = 1;
            }
            i = i->next;
            index++;
        }while(i != head);
        if(d == 0)
            printf("Khong co!");
        printf("\n");
    }
}
void Y3(){
    struct Node* i = head;
    int index = 1;
    int d = 0;
    if(i != NULL){
        do{
            i = i->next;
            index++;
        }while(index != 4);
        if(i->next->value == 0){
            d = 1;
            if(head == head->next)
                head = NULL;
            else{
                i->next = i->next->next;
            }
        }
    }
    if(d == 0)
        printf("\nKhong phai\n");
    else    
        printf("\nDa xoa!\n");
}
void Y4(){
    struct Node* i = head;
    if(i != NULL){
        do{
            if(i->next->value < 0){
                struct Node* p = i->next;
                i->next = p->next;
            } else 
                i = i->next;
        }while(i->next != head);
        if(head->value < 0){
            if(head->next == head)
                head = NULL;
            else    
                head = head->next;
                i->next = head;
        }
    }
}
void Y5(){
    struct Node* i, *j;
    for(i =head; i->next != head; i = i->next){
        for(j = i->next; j != head; j = j->next)
            if(i->value > j->value){
                int t = i->value;
                i->value = j->value;
                j->value = t;
            } 
    }
}
int main(){
    int chucNang;
    do{
         printf("\n\t\tMenu");
        printf("\n\t1. Tao danh sach");
        printf("\n\t2. Kiem tra danh sach so nguyen to");
        printf("\n\t3. Kiem tra vi tri so 5 trong danh sach phai so 0");
        printf("\n\t4. Xoa tat ca so am");
        printf("\n\t5. Sap xep theo thu tu tang dan");
        printf("\n\t6. Xuat danh sach");
        printf("\n\t0. Thoat");
        printf("\n\tChuc nang: ");
        scanf("%d", &chucNang);
        switch (chucNang)
        {
        case 1:
            Nhap();
            break;
        case 2:
            Y2();
            break;
        case 3:
            Y3();
            break;
        case 4:
            Y4();
            break;
        case 5:
            Y5();
            break;
        case 6:
            Xuat();
            break;
        case 0:
           return 0;
        default:
            printf("Thao tac khong hop le!\n");
            break;
        }
    }while(1);
}


