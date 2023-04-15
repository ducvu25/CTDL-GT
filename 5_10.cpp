#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        string hoTen;
        int namSinh;
        float diem[9];
    public:
        void Nhap(){
            cout << "Nhap ho ten: "; 
            fflush(stdin);
            getline(cin, hoTen);
            cout << "Nhap nam sinh: ";
            cin >> namSinh;
            cout << "Nhap diem cac mon:\n";
            for(int i=0; i<9; i++){
                cout << "Nhap diem mon " << i << ": ";
                cin >> diem[i];
            }
        }
        int loai(){
           // n = 0;
            float tongDiem = 0;
            for(int i=0; i<9; i++)
                if(diem[i] < 5){
                    // a[n] = i;
                    // n++;
                    return 0;
                }
                else    
                    tongDiem += diem[i];
            // if(n != 0)
            //     return 0;
            if(tongDiem/9 > 7)
                return 2; // luan van
            return 1; // tot nghiep
        }     
};
class Lop{
    private:
        int n;
        Person *a;
    public:
        void Nhap(int n){
            n  =n;
            a = new Person[n];
            for(int i=0; i<n; i++){
                a[i].Nhap();
            }
        }
        void YC(){
            int lv = 0, tn = 0, tl = 0;
            for(int i=0; i<n; i++)
                switch (a[i].loai()){
                case 0:
                    tl++;
                    break;
                case 1:
                    tn++;
                    break;
                default:
                    lv++;
                }
            cout << "so sv tot nghiep: " << tn << endl;
            cout << "so sv luan van: " << lv << endl;
            cout << "so sv thi lai: " << tl << endl;
        }
};
int main(){
    Lop a;
    int n;
    cout << "Nhap so luong: "; cin >> n;
    a.Nhap(n);
    a.YC();
    return 0;
}