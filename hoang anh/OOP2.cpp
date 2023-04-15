#include<iostream>
#include<string>

using namespace std;
class SACH{
    private:
        string ma;
        string ten;
        int soTo;
    public:
        SACH* next;
        void Gan(string mas, string tens, int ns){
            ma = mas;
            ten = tens;
            soTo = ns;
        }
        void Nhap(){
            cin >> ma >> ten >> soTo;
        }
        string Ma(){
            return this-> ma;
        }
        string Ten(){
            return this->ten;
        }
        int Num(){
            return this->soTo;
        }
        void Xuat(){
            cout << ma << "-" << ten <<"-" << soTo << endl;
        }
};
class DSLK{
    private:
        SACH* head;
    public:
        void Init(){
            head = NULL;
        }
        void push(){
            SACH* p = new SACH;
            p->Nhap();
            p->next = NULL;
            if(head == NULL)
                head = p;
            else{
                SACH* i = head;
                while(i->next != NULL){
                    i = i->next;
                }
                i->next = p;
            }
        }
        void Delete(int k){
            if(k == 0)
                head = head->next;
            else{
                int index = 0;

                for(SACH* i =head; i->next != NULL; i = i->next){
                    if(index + 1 == k){
                        i->next = i->next->next;
                        return;
                    }
                    index++;
                }
            }
        }
        int TongTrang(){
            int sum = 0;
            for(SACH* i=head; i!= NULL; i = i->next)
                sum += i->Num();
            return sum;
        }
        void print(){
            for(SACH* i=head; i!= NULL; i = i->next)
                i->Xuat();
        }
};

int main(){
    int n, index;
    cin >> n >> index;
    DSLK head;
    head.Init();
    for(int i=0; i<n; i++){
        head.push();
    }
    cout << head.TongTrang() << endl;
    head.Delete(index);
    head.print();
    return 0;
}