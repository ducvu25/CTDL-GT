#include<iostream>
#include<string>

using namespace std;
class SACH{
    private:
        string ma;
        string ten;
        int soTo;
    public:
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
class ArrayList{
    private:
        SACH* a;
        int n;
    public:
        void Nhap(int size){
            n = size;
            a = new SACH[n];
            for(int i=0; i<n; i++)
                a[i].Nhap();
        }
        int find(string maSach){
            for(int i=0; i<n; i++)
                if(a[i].Ma() == maSach)
                    return i;
            return -1;
        }
        void sort(){
            for(int i=0; i<n-1; i++)
                for(int j=i+1; j<n; j++)
                    if(a[i].Num() > a[j].Num()){
                        string ma = a[i].Ma();
                        string ten = a[i].Ten();
                        int num = a[i].Num();
                        a[i].Gan(a[j].Ma(), a[j].Ten(), a[j].Num());
                        a[j].Gan(ma, ten, num);
                    }
        }
        void print(){
            for(int i=0; i<n; i++)
                a[i].Xuat();
        }
};

int main(){
    int n; cin >> n;
    ArrayList A;
    A.Nhap(n);
    A.sort();
    A.print();
    return 0;
}