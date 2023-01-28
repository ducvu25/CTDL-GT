#include<iostream>
#include"ducvu25.h"

using namespace std;
int Menu(int muc){
    vector<string> tieu_de;
    switch(muc){
        case -1:
            return -1;
        case 0:{
            system("cls");
            tieu_de.push_back("Kiem tra");
            tieu_de.push_back("Mang 1 chieu");
            tieu_de.push_back("Mang 2 chieu");
            tieu_de.push_back("Chuoi");
            break;
        }
        case 1:{
            tieu_de.push_back("So nguyen to");
            tieu_de.push_back("So dep");
            tieu_de.push_back("So fibonaci");
            tieu_de.push_back("UCLN, BCNN");
            break;
        }
        case 2:{
            tieu_de.push_back("Nhap mang");
            tieu_de.push_back("Xuat mang");
            tieu_de.push_back("Them gia tri k vao vi tri x");
            tieu_de.push_back("Xoa phan tu o vi tri x");
            tieu_de.push_back("Tim kiem vi tri gia tri k dau tien");
            tieu_de.push_back("Sap xep tang dan mang");
            tieu_de.push_back("Sap xep giam dan mang");
            break;
        }
        case 3:{
            tieu_de.push_back("Khoi tao");
            tieu_de.push_back("Xuat");
            tieu_de.push_back("Cong 2 ma tran");
            tieu_de.push_back("Tru 2 ma tran");
            tieu_de.push_back("Nhan 2 ma tran");
            tieu_de.push_back("Dinh thuc");
            tieu_de.push_back("Xoa cot x");
            tieu_de.push_back("Xoa hang y");
            tieu_de.push_back("Chen cot co gia tri k vao cot x");
            tieu_de.push_back("Chen hang co gia tri k vao hang y");
            tieu_de.push_back("Sap xep tren cot");
            tieu_de.push_back("Sap xep tren hang");
            break;
        }
        case 4:{
            tieu_de.push_back("Chuan hoa ten");
            tieu_de.push_back("Chuan hoa ngay");
            tieu_de.push_back("Chuan hoa gio");
            tieu_de.push_back("Thay the chuoi s1 thanh s2 trong chuoi s");
            tieu_de.push_back("Xoa chuoi s1 trong chuoi s");
            tieu_de.push_back("Tinh toan voi cac so lon");
            tieu_de.push_back("Thuc hien bieu thuc");
            break;
        }
    }
    tieu_de.push_back("Thoat");
    cout << "\n\n\t\tMenu " << muc << endl;
    for(int i=0; i<tieu_de.size(); i++){
        cout << "\t" << i << ". " << tieu_de[i] << endl;
    }
    int chuc_nang;
    do{
        cout << "Chuc nang: ";
        cin >> chuc_nang;
    }while(chuc_nang < 0 || chuc_nang > tieu_de.size());
    cout << "\n\t\tgithub: ducvu25\n\n";
    if(chuc_nang == tieu_de.size() - 1)
        return -1;
    return chuc_nang;
}
int main(){
    int chuc_nang_1, chuc_nang_2;
    do{
        chuc_nang_1 = Menu(0);
            switch(chuc_nang_1){
                case 0:{
                    do{
                        chuc_nang_2 = Menu(1);
                                            switch(chuc_nang_2){
                        case 0:{
                            cout << "\nKiem tra so nguyen to\n";
                            int number;
                            cout << "Nhap so can kiem tra: ";
                            cin >> number;
                            if(Check_nguyen_to(number) == true)
                                cout << number << " la so nguyen to\n";
                            else
                                cout << number << " khong la so nguyen to\n";
                            break;
                        }
                        case 1:{
                            cout << "\nKiem tra so dep\n";
                            int number;
                            cout << "Nhap so can kiem tra: ";
                            cin >> number;
                            if(Check_so_dep(number) == true)
                                cout << number << " la so dep\n";
                            else
                                cout << number << " khong la so dep\n";
                            break;
                        }
                        case 2:{
                            cout << "\nKiem tra so fibonaci\n";
                            int number;
                            cout << "Nhap so can kiem tra: ";
                            cin >> number;
                            if(Check_fbnc(number) == true)
                                cout << number << " la fbnc\n";
                            else
                                cout << number << " khong la so fbnc\n";
                            break;
                        }
                        case 3:{
                            cout << "\nTim UCLN, BCNN\n";
                            int number1, number2;
                            cout << "Nhap 2 so: "; cin >> number1 >> number2;
                            cout << "UCLN(" << number1 << "; " << number2 << "): " << UCLN(number1, number2) << endl;
                            cout << "BCNN(" << number1 << "; " << number2 << "): " << BCNN(number1, number2) << endl;
                            break;
                        }
                    }
                    }while(chuc_nang_2 != -1);
                    break;
                }
                case 1:{
                    float array[100];
                    int size = 0;
                    do{
                        chuc_nang_2 = Menu(chuc_nang_1 + 1);
                        switch(chuc_nang_2){
                        case 0:{
                            cout << "\nNhap mang\n";
                            cout << "Nhap so luong phan tu: "; cin >> size;
                            Nhap_mang(array, size);
                            break;
                        }
                        case 1:{
                            cout << "\nMang hien tai:\n";
                            Xuat_mang(array, size);
                            break;
                        }
                        case 2:{
                            float k;
                            cout << "Nhap gia tri muon them: "; cin >> k;
                            int x;
                            cout << "Nhap vi tri muon them: "; cin >> x;
                            Them_mang(array, size, k, x - 1);
                            break;
                        }
                        case 3:{
                            int x;
                            cout << "Nhap vi tri muon xoa: "; cin >> x;
                            Xoa_mang(array, size, x - 1);
                            break;
                        }
                        case 4:{
                            float k;
                            cout << "Nhap gia tri can tim: "; cin >> k;
                            int index = Tim_kiem_mang(array, size, k);
                            if(index == -1)
                                cout << "Gia tri " << k << " khong co trong mang\n";
                            else
                                cout << "Vi tri xuat hien dau tien: " << index << endl;
                            break;
                        }
                        case 5:{
                            cout << "Sap xep tang dan";
                            Sort_mang(array, size, true);
                            break;
                        }
                        case 6:{
                            cout << "Sap xep giam dan";
                            Sort_mang(array, size, false);
                            break;
                        }
                        }
                    }while(chuc_nang_2 != -1);
                    break;
                }
                case 2:{
                    float** matrix;
                    int m =0, n = 0;
                    do{
                        chuc_nang_2 = Menu(chuc_nang_1 + 1);
                        switch(chuc_nang_2){
                        case 0:{
                            cout << "\nNhap matrix\n";
                            cout << "Nhap kich thuoc: "; cin >> m >> n;
                            matrix = Nhap_matrix(m, n);
                            break;
                        }
                        case 1:{
                            cout << "\nMa tran hien tai:\n";
                            Xuat_matrix(matrix, m, n);
                            break;
                        }
                        case 2:{
                            Tinh_toan('+');
                            break;
                        }
                        case 3:{
                            Tinh_toan('-');
                            break;
                        }
                        case 4:{
                            Tinh_toan('*');
                            break;
                        }
                        case 5:{
                            cout << "Dinh thuc\n";
                            cout << "Lien he fanpage - Support - C/Cpp de nhan mien phi\n";
                            break;
                        }
                        case 6:{
                            cout << "Xoa cot\n";
                            int x; cout << "Nhap cot muon xoa: "; cin >> x;
                            Xoa_cot(matrix, m, n, x);
                            break;
                        }
                        case 7:{
                            cout << "Xoa hang\n";
                            int y; cout << "Nhap hang muon xoa: "; cin >> y;
                            Xoa_hang(matrix, m, n, y);
                            break;
                        }
                        case 8:{
                            cout << "Chen cot\n";
                            float k; cout << "Nhap gia tri muon chen: "; cin >> k;
                            int x; cout << "Nhap cot muon chen: "; cin >> x;
                            matrix = Chen_cot(matrix, m, n, k, x);
                            break;
                        }
                        case 9:{
                            cout << "Chen hang\n";
                            float k; cout << "Nhap gia tri muon chen: "; cin >> k;
                            int y; cout << "Nhap hang muon chen: "; cin >> y;
                            matrix = Chen_hang(matrix, m, n, k, y);
                            break;
                        }
                        case 10:{
                            cout << "Sap xep cot\n";
                            int x; cout << "Nhap cot muon sap xep: "; cin >> x;
                            Sort_cot(matrix, m, n, x);
                            break;
                        }
                        case 11:{
                            cout << "Sap xep hang\n";
                            int y; cout << "Nhap hang muon sap xep: "; cin >> y;
                            Sort_hang(matrix, m, n, y);
                            break;
                        }
                        }
                    }while(chuc_nang_2 != -1);
                    break;
                }
                case 3:{
                    do{
                        chuc_nang_2 = Menu(4);
                        switch(chuc_nang_2){
                        case 0:{
                            cout << "\nChuan hoa ten\n";
                            string s; cout << "Nhap chuoi s: "; cin.ignore(); getline(cin ,s);
                            Chuan_hoa_ten(s);
                            cout << "Ten hoan chinh: " << s << endl;
                            break;
                        }
                        case 1:{
                            cout << "\nChuan hoa ngay\n";
                            string s; cout << "Nhap chuoi s: "; cin.ignore(); getline(cin ,s);
                            Chuan_hoa_ngay(s);
                            cout << "Ngay hoan chinh: " << s << endl;
                            break;
                        }
                        case 2:{
                            cout << "\nChuan hoa gio\n";
                            string s; cout << "Nhap chuoi s: "; cin.ignore(); getline(cin ,s);
                            Chuan_hoa_gio(s);
                            cout << "Gio hoan chinh: " << s << endl;
                            break;
                        }
                        case 3:{
                            string s, s1, s2;
                            cout << "Nhap chuoi s: "; cin.ignore(); getline(cin ,s);
                            cout << "Chuoi can thay the: "; getline(cin, s1);
                            cout << "Chuoi thay the: "; getline(cin, s2);
                            Thay_the(s, s1, s2);
                            cout << "Chuoi dat duoc: " << s << endl;
                            break;
                        }
                        case 4:{
                            string s, s1, s2;
                            cout << "Nhap chuoi s: "; cin.ignore(); getline(cin ,s);
                            cout << "Chuoi can xoa: "; getline(cin, s1);
                            Xoa_chuoi(s, s1);
                            cout << "Chuoi dat duoc: " << s << endl;
                            break;
                        }
                        case 5:
                        case 6:{
                            cout << "Tinh toan so lon\n";
                            cout << "Lien he fanpage - Support - C/Cpp de nhan mien phi\n";
                            break;
                        }
                    }
                    }while(chuc_nang_2 != -1);
                    break;
                }
            }
        system("\npause");
    }while(chuc_nang_1 != -1);
    return 0;
}