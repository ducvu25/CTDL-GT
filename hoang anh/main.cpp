#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include<iomanip>
using namespace std;
int mau_chu = 11;
int mau_thong_bao = 4;
// giao dien
void TextColor(int color); // đổ màu
void gotoXY(int x, int y);// tọa độ
void Ox(int x1, int x2, int y);// vẽ trục ngang
void Oy(int y1, int y2, int x, int d);// vẽ trục đứng
void Table(int x, int y, int* a, int b, int m, int n, int size, int color);// vẽ bảng

int menu_1(int x, int y);
int menu_2(int x, int y, int chuc_nang1, int d);

// xu ly
string in_thuong(string s);
void chuan_hoa_ngay(string &s);
bool so_sanh_ngay(string d1, string d2);
string int_sang_string(int x);
int string_sang_int(string s);
bool kiem_tra_ma(string &s);
bool kiem_tra_ten(string &s);
bool kiem_tra_so(string &s);
bool kiem_tra_ngay(string &s);
bool kiem_tra_email(string &s);
string nhap_ten(int x, int y, int tb_x, int tb_y, int len);
string nhap_ngay(int x, int y, int tb_x, int tb_y, int len);
string nhap_ma(int x, int y, int tb_x, int tb_y, int len);
string nhap_sdt(int x, int y, int tb_x, int tb_y, int len);
string nhap_email(int x, int y, int tb_x, int tb_y, int len);
//
struct SinhVien{
    string MaSV; // 10
    string HoTen; // 30
    string NgaySinh; // 10
    string GioiTinh; // nam/nu
    string MaLop; // 10 
    string DiaChi; // 30
    string SDT; // 10
    string Email; // 35
};
bool doc_file(SinhVien *A, int &n);
void xuat_file(SinhVien *A, int &n);
void Nhap(SinhVien *A, int &n, int x, int y, int tbX, int tbY);
void Xuat(SinhVien a, int x, int y);
void Sua(SinhVien &a, int x, int y, int tbX, int tbY);
int TimKiem(SinhVien *A, int n, string s, int x, int y, int tbX, int tbY);
void Sua(SinhVien *A, int n, string s, int x, int y, int tbX, int tbY);
void Xoa(SinhVien *A, int &n, string s, int x, int y, int tbX, int tbY);
void DSTheoLop(SinhVien *A, int &n, string s, int x, int y);

// giang vien
struct GiangVien{
    string MaGV; // 10
    string TenGV; // 30
    string NgaySinh; // 10
    string GioiTinh; // 
    string Khoa; // 30
    string SDT; // 10
    string Email; // 30
};
bool doc_file(GiangVien *A, int &n);
void xuat_file(GiangVien *A, int &n);
void Nhap(GiangVien *A, int &n, int x, int y, int tbX, int tbY);
void Xuat(GiangVien a, int x, int y);
void Sua(GiangVien &a, int x, int y, int tbX, int tbY);
int TimKiem(GiangVien *A, int n, string s, int x, int y, int tbX, int tbY);
void Sua(GiangVien *A, int n, string s, int x, int y, int tbX, int tbY);
void DSTheoKhoa(GiangVien *A, int &n, string s, int x, int y);
void DSTheoTen(GiangVien *A, int &n, string s, int x, int y);
// tin chi
struct TinChi{
    string MaTC; //10
    string TenTC;// 30
    int LT; // [0, 2]
    int TH; // [0, 2]
    int SVMax; // [10, 15];
    int SVMin; // [5, 8]
    bool TrangThai; // huy / mo
    string MaGV1; // 10
    string MaGV2; // 10
};
bool doc_file(TinChi *A, int &n);
void xuat_file(TinChi *A, int &n);
void Nhap(TinChi *A, int &n, int x, int y, int tbX, int tbY);
void Xuat(TinChi a, int x, int y);
void Xuat(TinChi a, int x, int y, int color);
void Sua(TinChi &a, int x, int y, int tbX, int tbY);
int TimKiem(TinChi *A, int n, string s, int x, int y, int tbX, int tbY);
void Sua(TinChi *A, int n, string s, int x, int y, int tbX, int tbY);
void HuyTin(TinChi *A, int n, int x, int y, int tbX, int tbY);
void DSTheoTen(TinChi *A, int &n, string ten, int x, int y);
void DSTinChi(TinChi *A, int n, int x, int y, int chuc_nang);

// chuc nang khac
void DanhSachDangKy(string maGV, TinChi* TC, int nTC, int x, int y, int tbX, int tbY);
void DangKyTin(string maGV, TinChi* TC, int nTC, int x, int y, int tbX, int tbY);
// ds dang ky
struct DangKy{
    string MaSV;
    string MaTC; // 10
    float GK;
    float CK;
};
bool doc_file(DangKy* A, int &n);
void xuat_file(DangKy* A, int &n);
void Xuat(DangKy a, int x, int y);
void Them(string ma1, string ma2, DangKy* A, int &n);
void DangKyMon(string maSV, TinChi *TC, int nTC, DangKy* DK, int &nDK, int x, int y, int tbX, int tbY);
bool Check(DangKy* A, int &n, string s);
void DSDangKy(DangKy* A, int &n, string s, int x, int y);
void HuyTin(DangKy* A, int &n, string s, int x, int y, int tbX, int tbY);
int SoLuongSV(DangKy* A, int &n, string s);
void HuyTin(TinChi* TC, int nTC, DangKy *DK, int nDK, int x, int y);
void DSLop(string s, DangKy* DK, int nDK, int x, int y);
void NhapDiem1(string s, DangKy* DK, int nDK, int x, int y);
void NhapDiem(string maGV, TinChi* TC, int nTC, DangKy* DK, int nDK, int x, int y, int tbX, int tbY);
int main(){
    system("cls");
    int x = 5, y = 2, tbX = 20, tbY = 15;
    GiangVien *GV = new GiangVien[100]; int nGV;
    if(!doc_file(GV, nGV)){
        cout << "Loi file giang vien!";
        return 0;
    }
    TinChi *TC = new TinChi[100]; int nTC; 
    if(!doc_file(TC, nTC)){
        cout << "Loi file tin chi!";
        return 0;
    }
    DangKy *DK = new DangKy[100]; int nDK;
    if(!doc_file(DK, nDK)){
        cout << "Loi file danh sach dang ky!";
        return 0;
    }
    SinhVien *SV = new SinhVien[100]; int nSV;   
    if(!doc_file(SV, nSV)){
        cout << "Loi file sinh vien!";
        return 0;
    }
    while(1){
    	int chuc_nang1 = menu_1(x, y);
    	switch(chuc_nang1){
    		case 0:{
    			int chuc_nang2;
                do{
                    system("cls");
                    chuc_nang2 = menu_2(x + 20, y, chuc_nang1, 1);
                    system("cls");
                    switch(chuc_nang2){
                        case 0:{
                            Nhap(SV, nSV, x, y, tbX, tbY);
                            break;
                        }
                        case 1:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma sinh vien: ";
                            ma = nhap_ma(x + strlen("Nhap ma sinh vien: "), y, tbX, tbY, 10);
                            Sua(SV, nSV, ma, x, y + 2, tbX, tbY);
                            break;
                        }
                        case 2:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma sinh vien: ";
                            ma = nhap_ma(x + strlen("Nhap ma sinh vien: "), y, tbX, tbY, 10);
                            int index = TimKiem(SV, nSV, ma, x, y, tbX, tbY);
                            if(index != -1){
                            if(Check(DK, nDK, ma)){
                                gotoXY(tbX, tbY);
                                TextColor(4);
                                cout << "Sinh vien dang dang ky nen khong the xoa!";
                            }else
                                Xoa(SV, nSV, ma, x, y + 2, tbX, tbY);       
                            }
                            getch();
                            break;
                        }
                        case 3:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma sinh vien: ";
                            ma = nhap_ma(x + strlen("Nhap ma sinh vien: "), y, tbX, tbY, 10);
                            int index = TimKiem(SV, nSV, ma, x, y, tbX, tbY);
                            if(index != -1)
                                DangKyMon(ma, TC, nTC, DK, nDK, x, y, tbX, tbY);
                            break;
                        }
                        case 4:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma sinh vien: ";
                            ma = nhap_ma(x + strlen("Nhap ma sinh vien: "), y, tbX, tbY, 10);
                            DSDangKy(DK, nDK, ma, x, y);
                            break;
                        }
                        case 5:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma sinh vien: ";
                            ma = nhap_ma(x + strlen("Nhap ma sinh vien: "), y, tbX, tbY, 10);
                            HuyTin(DK, nDK, ma, x, y, tbX, tbY);
                            break;
                        }
                        case 6:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma lop: ";
                            ma = nhap_ma(x + strlen("Nhap ma lop: "), y, tbX, tbY, 10);
                            DSTheoLop(SV, nSV, ma, x, y);
                            break;
                        }

                    }
                }while(chuc_nang2 != -1);
				break;
			}
			case 1:{
				int chuc_nang2;
                do{
                    system("cls");
                    chuc_nang2 = menu_2(x + 20, y, chuc_nang1, 1);
                    system("cls");

                    switch(chuc_nang2){
                        case 0:{
                            Nhap(TC, nTC, x, y, tbX, tbY);
                            break;
                        }
                        case 1:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma tin chi: ";
                            ma = nhap_ma(x + strlen("Nhap ma tin chi: "), y, tbX, tbY, 10);
                            Sua(TC, nTC, ma, x, y + 2, tbX, tbY);
                            break;
                        }
                        case 2:{
                            HuyTin(TC, nTC, DK, nDK, x, y);
                            break;
                        }
                        case 3:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma tin chi: ";
                            ma = nhap_ma(x + strlen("Nhap ma tin chi: "), y, tbX, tbY, 10);
                            int index = TimKiem(TC, nTC, ma, x, y, tbX, tbY);
                            if(index != -1){
                                DSLop(ma, DK, nDK, x, y);
                            }
                            break;
                        }
                        case 4:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ten tin chi: ";
                            ma = nhap_ten(x + strlen("Nhap ten tin chi: "), y, tbX, tbY, 30);
                            DSTheoTen(TC, nTC, ma, x, y);
                            break;
                        }
                    }
                }while(chuc_nang2 != -1);
				break;
			}
			case 2:{
				int chuc_nang2;
                do{
                    system("cls");
                    chuc_nang2 = menu_2(x + 20, y, chuc_nang1, 1);
                    system("cls");
                    switch(chuc_nang2){
                        case 0:{
                            Nhap(GV, nGV, x, y, tbX, tbY);
                            break;
                        }
                        case 1:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma giang vien: ";
                            ma = nhap_ma(x + strlen("Nhap ma giang vien: "), y, tbX, tbY, 10);
                            Sua(GV, nGV, ma, x, y + 2, tbX, tbY);
                            break;
                        }
                        case 2:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma giang vien: ";
                            ma = nhap_ma(x + strlen("Nhap ma giang vien: "), y, tbX, tbY, 10);
                            TimKiem(GV, nGV, ma, x, y, tbX, tbY);
                            break;
                        }
                        case 3:{
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma giang vien: ";
                            string maGV = nhap_ma(x + strlen("Nhap ma giang vien: "), y, tbX, tbY, 10);
                            int index = TimKiem(GV, nGV, maGV, x, y, tbX, tbY);
                            if(index != -1){
                                DangKyTin(maGV, TC, nTC, x, y, tbX, tbY);
                            } 
                            break;
                        }
                        case 4:{
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma giang vien: ";
                            string maGV = nhap_ma(x + strlen("Nhap ma giang vien: "), y, tbX, tbY, 10);
                            int index = TimKiem(GV, nGV, maGV, x, y, tbX, tbY);
                            if(index != -1){
                                DanhSachDangKy(maGV, TC, nTC, x, y, tbX, tbY);
                            } 
                            break;
                        }
                        case 5:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ten: ";
                            ma = nhap_ten(x + strlen("Nhap ten: "), y, tbX, tbY, 28);
                            DSTheoTen(GV, nGV, ma, x, y);
                            break;
                        }
                        case 6:{
                            string ma;
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap khoa: ";
                            ma = nhap_ten(x + strlen("Nhap khoa: "), y, tbX, tbY, 28);
                            DSTheoKhoa(GV, nGV, ma, x, y);
                            break;
                        }
                        case 7:{
                            gotoXY(x, y); TextColor(mau_chu); cout << "Nhap ma giang vien: ";
                            string maGV = nhap_ma(x + strlen("Nhap ma giang vien: "), y, tbX, tbY, 10);
                            int index = TimKiem(GV, nGV, maGV, x, y, tbX, tbY);
                            if(index != -1){
                                NhapDiem(maGV, TC, nTC, DK, nDK, x, y, tbX, tbY);
                            } 
                            break;
                        }
                    }
                }while(chuc_nang2 != -1);
				break;
			}
			case -1:{
				xuat_file(GV, nGV);
				xuat_file(TC, nTC);
				xuat_file(DK, nDK);
				xuat_file(SV, nSV);
				return 0;
			}
		}
	}
    return 0;
}
void TextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y) { // x la ngang, y la doc
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Ox(int x1, int x2, int y) {
    for (int j = x1; j <= x2; j+=2) {
        gotoXY(j, y);
        cout << "-";
    }     
}
void Oy(int y1, int y2, int x, int d) {
    for (int j = y1; j <= y2; j++) {
        gotoXY(x, j);
        if ((j - y1) % d == 0)
            cout << "+";
        else
        cout << "|";
    }
}
void Table(int x, int y, int* a, int b, int m, int n, int size, int color) {
    TextColor(color);
    // dong
    for (int i = 0; i <= m; i++)
        Ox(x, x + size, y + b * i);
    // cot
    Oy(y, y + m * b, x, b);
    Oy(y, y + m * b, x + size, b);
    int d = 0;
    for (int i = 0; i < n; i++){
        Oy(y, y + m * b, x + d + a[i], b);
        d += a[i];
    }
}
void XoaVung(int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++)
        for (int j = x1; j <= x2; j++) {
            gotoXY(j, i);
            cout << " ";
        }
}
int menu_1(int x, int y){
	int size[] = {18};
	Table(x-2, y-1, size, 4, 1, 1, 18, 11);
    char c;
    string tieu_de[] = {"Sinh vien", "Tin chi", "Giang vien"};
    int chuc_nang = 0;
    TextColor(7);
    for(int i=0; i<3; i++){
        gotoXY(x, y+i);
        cout << tieu_de[i];
    }
    TextColor(12);
    gotoXY(x, y);
    cout << tieu_de[0];
    while(1){
        if(kbhit()){
            c = getch();
            menu_2(x+20, y, chuc_nang, 0);
            switch(c){
                case 72:{// len
                    if(chuc_nang == 0){
                        chuc_nang = 2;
                        break;
                    }
                    chuc_nang--;
                    break;
                }
                case 80:{// xuong
                    if(chuc_nang == 2){
                        chuc_nang = 0;
                        break;
                    }
                    chuc_nang++;
                    break;
                }
                case 13:{// enter
                    return chuc_nang;
                    break;
                }
                case 27:{// len
                    return -1;
                }
            }
            TextColor(7);
            for(int i=0; i<3; i++){
                gotoXY(x, y+i);
                cout << tieu_de[i];
            }
            TextColor(12);
            gotoXY(x, y + chuc_nang);
            cout << tieu_de[chuc_nang];
            menu_2(x+20, y, chuc_nang, 7);
        }
    }
}
int menu_2(int x, int y, int chuc_nang1, int d){
    int size[] = {35};
	Table(x-2, y-1, size, 10, 1, 1, 35, 11);
    char c;
    vector<string> tieu_de;
    switch(chuc_nang1){
        case 0:{
            tieu_de.push_back("Them thong tin sinh vien");
            tieu_de.push_back("Cap nhat thong tin sinh vien");
            tieu_de.push_back("Xoa sinh vien");
            tieu_de.push_back("Dang ki tin");
            tieu_de.push_back("Kiem tra danh sach tin");
            tieu_de.push_back("Huy tin");
            tieu_de.push_back("Danh sach sinh vien theo ma lop");
            break;
        }
        case 1:{
            tieu_de.push_back("Mo tin");
            tieu_de.push_back("Sua tin");
            tieu_de.push_back("Huy tin");
            tieu_de.push_back("Xem thong tin");
            tieu_de.push_back("Danh sach tin theo ten");
            break;
        }
        case 2:{
            tieu_de.push_back("Them thong tin giang vien");
            tieu_de.push_back("Cap nhat thong tin giang vien");
            tieu_de.push_back("Tim kiem theo ma");
            tieu_de.push_back("Dang ki tin");
            tieu_de.push_back("Kiem tra danh sach tin");
            tieu_de.push_back("Tim kiem giang vien theo ten");
            tieu_de.push_back("Tim kiem giang vien theo khoa");
            tieu_de.push_back("Nhap diem");
            break;
        }
    }
    if(d != 1){
        TextColor(d);
        for(int i=0; i<tieu_de.size(); i++){
            gotoXY(x, y+i);
            cout << tieu_de[i];
        }
        return -1;
    }
    TextColor(7);
    for(int i=0; i<tieu_de.size(); i++){
        gotoXY(x, y+i);
        cout << tieu_de[i];
    }
    TextColor(12);
    int chuc_nang2 = 0;
    gotoXY(x, y + chuc_nang2);
    cout << tieu_de[chuc_nang2];
    while(1){
        if(kbhit()){
            c = getch();
            switch(c){
                case 72:{// len
                    if(chuc_nang2 == 0){
                        chuc_nang2 = tieu_de.size() - 1;
                        break;
                    }
                    chuc_nang2--;
                    break;
                }
                case 80:{// xuong
                    if(chuc_nang2 == tieu_de.size() - 1){
                        chuc_nang2 = 0;
                        break;
                    }
                    chuc_nang2++;
                    break;
                }
                case 13:{// enter
                    return chuc_nang2;
                    break;
                }
                case 27:{// len
                    return -1;
                }
            }
            TextColor(7);
            for(int i=0; i< tieu_de.size(); i++){
                gotoXY(x, y+i);
                cout << tieu_de[i];
            }
            TextColor(12);
            gotoXY(x, y + chuc_nang2);
            cout << tieu_de[chuc_nang2];
        }
    }
}

// xu lys
string in_thuong(string s){
    string a = s;
    for(int i=0; i<a.size(); i++)
        if(a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
    return a;
}
void chuan_hoa_ngay(string &s){
    string s1, s2, s3;
	s1 = s.substr(0, s.find("/"));
	s.erase(0, s.find("/") + 1);
	s2 = s.substr(0, s.find("/"));
	s.erase(0, s.find("/") + 1);
	if(s1.size() == 1)
		s1 = "0" + s1;
	if(s2.size() == 1)
		s2 = "0" + s2; 
	s = s1 + "/" + s2 + "/" + s;
}
bool so_sanh_ngay(string d1, string d2){
	if(d1 == d2)
		return 0;
	string s1 = d1.substr(6) + d1.substr(3, 2) + d1.substr(0, 2);
	string s2 = d2.substr(6) + d2.substr(3, 2) + d2.substr(0, 2);
	return s1 > s2;
}
string int_sang_string(int x) {
	string kq = "";
	string s = "0";
	while (x != 0) {
		s[0] = x % 10 + 48;
		kq = s + kq;
		x /= 10;
	}
	return kq;
}
int string_sang_int(string s) {
	int kq = 0;
	for (int i = 0; i < s.size(); i++)
		kq = kq * 10 + s[i] - 48;
	return kq;
}
bool kiem_tra_ma(string &s){
    for(int i=0; i<s.size(); i++)
        if(!((s[i] >= 'a' && s[i] <= 'z')
        || (s[i] >= 'A' && s[i] <= 'Z')
        || (s[i] >= '0' && s[i] <= '9') || s[i] == 32))
            return false;
    return true;
}
bool kiem_tra_ten(string &s){
    //in_thuong(s);
    for(int i=0; i<s.size(); i++)
        if(!((s[i] >= 'a' && s[i] <= 'z')
        || (s[i] >= 'A' && s[i] <= 'Z')
        || (s[i] >= '0' && s[i] <= '9') 
        || s[i] == 32 || s[i] == '-' || s[i] == ','))
            return false;
    return true;
}
bool kiem_tra_so(string &s){
    for(int i=0; i<s.size(); i++)
        if(!(s[i] >= '0' && s[i] <= '9'))
            return false;
    return true;
}
bool kiem_tra_ngay(string &s){
    chuan_hoa_ngay(s);
    if(s.size() != 10)
        return false;
    for(int i=0; i<10; i++)
        if(s[i] != '/' && !(s[i] >= '0' && s[i] <= '9'))
            return false;
    return true;
}
bool kiem_tra_email(string &a){
    string s = a;
    if(s.find("@") == -1)
        return false;
    s.erase(0, s.find("@") + 1);
    if(s.find("@") != -1 || s.find(".") == -1)
        return false;
    return true;
}
string nhap_ten(int x, int y, int tb_x, int tb_y, int len){
    len++;
    string s;
    fflush(stdin);
    while(1){
        for(int i=0; i<len - 2; i++){
            gotoXY(x + i, y);
            cout << " ";
        }
        TextColor(7);
        gotoXY(x, y);
        getline(cin, s);
        if(s.find("esc") != -1)
            return s;
        //in_thuong(s);
        if(kiem_tra_ten(s) && s.size() <= len)
            return s;
        TextColor(4);
        gotoXY(tb_x, tb_y);
        cout << "Loi dinh dang hop le!";
        gotoXY(tb_x, tb_y + 1);
        cout << "Bam phim bat ki de tiep tuc!";
        getch();
        gotoXY(tb_x, tb_y);
        cout << "                                ";
        gotoXY(tb_x, tb_y + 1);
        cout << "                                ";
    }
}
string nhap_ngay(int x, int y, int tb_x, int tb_y, int len){
    string s;
    fflush(stdin);
    while(1){
        for(int i=0; i<len; i++){
            gotoXY(x + i, y);
            cout << " ";
        }
        TextColor(7);
        gotoXY(x, y);
        getline(cin, s);
        if(s.find("esc") != -1)
            return s;
        chuan_hoa_ngay(s);
        if(kiem_tra_ngay(s) && s.size() <= len)
            return s;
        TextColor(4);
        gotoXY(tb_x, tb_y);
        cout << "Loi dinh dang hop le!";
        gotoXY(tb_x, tb_y + 1);
        cout << "Bam phim bat ki de tiep tuc!";
        getch();
        gotoXY(tb_x, tb_y);
        cout << "                                ";
        gotoXY(tb_x, tb_y + 1);
        cout << "                                ";
    }
}
string nhap_ma(int x, int y, int tb_x, int tb_y, int len){
    string s;
    fflush(stdin);
    while(1){
        for(int i=0; i<len; i++){
            gotoXY(x + i, y);
            cout << " ";
        }
        TextColor(7);
        gotoXY(x, y);
        getline(cin, s);
        if(s.find("esc") != -1)
            return s;
        if(kiem_tra_ma(s) && s.size() <= len)
            return s;
        TextColor(4);
        gotoXY(tb_x, tb_y);
        cout << "Loi dinh dang hop le!";
        gotoXY(tb_x, tb_y + 1);
        cout << "Bam phim bat ki de tiep tuc!";
        getch();
        gotoXY(tb_x, tb_y);
        cout << "                                ";
        gotoXY(tb_x, tb_y + 1);
        cout << "                                ";
    }
}
string nhap_sdt(int x, int y, int tb_x, int tb_y, int len){
    string s;
    fflush(stdin);
    while(1){
        for(int i=0; i<len; i++){
            gotoXY(x + i, y);
            cout << "  ";
        }
        TextColor(7);
        gotoXY(x, y);
        getline(cin, s);
        if(s.find("esc") != -1)
            return s;
        if(kiem_tra_so(s) || s.size() <= len)
            return s;
        TextColor(4);
        gotoXY(tb_x, tb_y);
        cout << "Loi dinh dang hop le!";
        gotoXY(tb_x, tb_y + 1);
        cout << "Bam phim bat ki de tiep tuc!";
        getch();
        gotoXY(tb_x, tb_y);
        cout << "                                ";
        gotoXY(tb_x, tb_y + 1);
        cout << "                                ";
    }
}
string nhap_email(int x, int y, int tb_x, int tb_y, int len){
    string s;
    fflush(stdin);
    len++;
    while(1){
        for(int i=0; i<len - 2; i++){
            gotoXY(x + i, y);
            cout << " ";
        }
        TextColor(7);
        gotoXY(x, y);
        getline(cin, s);
        if(s.find("esc") != -1)
            return s;
        if(kiem_tra_email(s) && s.size() <= len)
            return s;
        TextColor(4);
        gotoXY(tb_x, tb_y);
        cout << "Loi dinh dang hop le!";
        gotoXY(tb_x, tb_y + 1);
        cout << "Bam phim bat ki de tiep tuc!";
        getch();
        gotoXY(tb_x, tb_y);
        cout << "                                ";
        gotoXY(tb_x, tb_y + 1);
        cout << "                                ";
    }
}

void Nhap(SinhVien *A, int &n, int x, int y, int tbX, int tbY){
    int size[8] = {170};
    fflush(stdin);
    TextColor(mau_chu);
    gotoXY(x + 60, y); cout << "Thong tin sinh vien";
    Table(x - 2, y - 1, size, 2, 1, 1, 170, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s %-14s %-29s%-15s %-34s", "Ma sinh vien", "Ho ten", "Ngay sinh", "Gioi tinh", "Ma lop", "Dia chi", "So dien thoai", "Email");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 30, size[6] = 15, size[7] = 35;
    Table(x - 2, y + 1, size, 2, 1, 8, 170, 7);
    int i = 0;
    char c;
    while(1){
        SinhVien a;
        TextColor(7);
        Table(x - 2, y + 3 + 2*i, size, 2, 1, 7, 170, 7);
        a.MaSV = nhap_ma(x, y + 4 + 2*i, tbX, tbY, 10);
        if(a.MaSV == "esc")
            break;
        a.HoTen = nhap_ten(x + 15, y + 4 + 2*i, tbX, tbY, 28);
        if(a.HoTen == "esc")
            break;
        a.NgaySinh = nhap_ngay(x + 45, y + 4 + 2*i, tbX, tbY, 10);
        if(a.NgaySinh== "esc")
            break;
        a.GioiTinh = nhap_ten(x + 60, y + 4 + 2*i, tbX, tbY, 10);
        if(a.GioiTinh == "esc")
            break;
        a.MaLop = nhap_ma(x + 75, y + 4 + 2*i, tbX, tbY, 10);
        if(a.MaLop == "esc")
            break;
        a.DiaChi = nhap_ten(x + 90, y + 4 + 2*i, tbX, tbY, 28);
        if(a.DiaChi == "esc")
            break;
        a.SDT = nhap_sdt(x + 120, y + 4 + 2*i, tbX, tbY, 10);
        if(a.SDT == "esc")
            break;
        a.Email = nhap_email(x + 135, y + 4 + 2*i, tbX, tbY, 28);
        if(a.Email == "esc")
            break;
        TextColor(mau_chu);
        gotoXY(tbX, tbY);   cout << "Bam ESC de thoat!";
        c = getch();
        if(c == 27)
            break;
        i++;
        A[n] = a;
        n++;
    }
}
void Xuat(SinhVien a, int x, int y){
    int size[8] = {170};
    int i = 1;
    TextColor(7);
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 30, size[6] = 15, size[7] = 35;
    gotoXY(x, y);
    cout << left << setw(15) << a.MaSV << setw(size[1]) << a.HoTen << setw(size[2]) << a.NgaySinh << setw(size[3])
     << a.GioiTinh << setw(size[4]) << a.MaLop << setw(size[5]) << a.DiaChi << setw(size[6]) << a.SDT << setw(size[7]) << a.Email;
    Table(x - 2, y - 1, size, 2, 1, 8, 170, 7);
}
bool doc_file(SinhVien *A, int &n){
    n = 0;
    ifstream cin("./DSSinhVien.txt");
    if(!(cin))
        return false;
    while(1){
        SinhVien a;
        if(!(cin >> a.MaSV))
            return true;
        cin.ignore();
        getline(cin, a.HoTen);
        getline(cin, a.NgaySinh );
        getline(cin, a.GioiTinh );
        getline(cin, a.MaLop );
        getline(cin, a.DiaChi );
        getline(cin, a.SDT );
        getline(cin, a.Email );
        A[n++] = a;
    }
}
void xuat_file(SinhVien *A, int &n){
	ofstream cout("./DSSinhVienNew.txt");
    for(int i=0; i<n; i++){
    	cout << A[i].MaSV<< endl; 
    	cout << A[i].HoTen<< endl; 
    	cout << A[i].NgaySinh<< endl; 
    	cout << A[i].GioiTinh<< endl; 
    	cout << A[i].MaLop<< endl; 
    	cout << A[i].DiaChi<< endl; 
    	cout << A[i].SDT<< endl; 
    	cout << A[i].Email<< endl; 
	}
}
void Sua(SinhVien &sinh_vien, int x, int y, int tbX, int tbY){
    SinhVien a = sinh_vien;
    // a.HoTen = nhap_ten(x + 15, y + 4, tbX, tbY, 28);
    // a.NgaySinh = nhap_ngay(x + 45, y + 4, tbX, tbY, 10);
    // a.GioiTinh = nhap_ten(x + 60, y + 4, tbX, tbY, 10);
    // a.MaLop = nhap_ma(x + 75, y + 4, tbX, tbY, 10);
    // a.DiaChi = nhap_ten(x + 90, y + 4, tbX, tbY, 28);
    // a.SDT = nhap_sdt(x + 120, y + 4, tbX, tbY, 10);
    // a.Email = nhap_email(x + 135, y + 4, tbX, tbY, 28);
    a.HoTen = nhap_ten(x + 15, y + 4 , tbX, tbY, 28);
        if(a.HoTen == "esc")
            goto out;
        a.NgaySinh = nhap_ngay(x + 45, y + 4 , tbX, tbY, 10);
        if(a.NgaySinh== "esc")
            goto out;
        a.GioiTinh = nhap_ten(x + 60, y + 4 , tbX, tbY, 10);
        if(a.GioiTinh == "esc")
            goto out;
        a.MaLop = nhap_ma(x + 75, y + 4 , tbX, tbY, 10);
        if(a.MaLop == "esc")
            goto out;
        a.DiaChi = nhap_ten(x + 90, y + 4 , tbX, tbY, 28);
        if(a.DiaChi == "esc")
            goto out;
        a.SDT = nhap_sdt(x + 120, y + 4 , tbX, tbY, 10);
        if(a.SDT == "esc")
            goto out;
        a.Email = nhap_email(x + 135, y + 4 , tbX, tbY, 28);
        if(a.Email == "esc")
            goto out;
    
    gotoXY(tbX, tbY);   cout << "Ban co chac muon cap nhat khong(y/n)? ";
    char c; cin >> c;
    if(c == 'y' || c == 'Y'){
        sinh_vien = a;
        gotoXY(tbX, tbY + 1);   cout << "Cap nhat thanh cong!";
    }else{
        out:
        gotoXY(tbX, tbY + 1);   cout << "Cap nhat that bai!";
    }
}
int TimKiem(SinhVien *A, int n, string s, int x, int y, int tbX, int tbY){
    for(int i=0; i<n; i++)
        if(A[i].MaSV == s){
            SinhVien a = A[i];
            int size[8] = {170};
            TextColor(mau_chu);
            gotoXY(x + 60, y); cout << "Thong tin sinh vien";
            Table(x - 2, y - 1, size, 2, 1, 1, 170, 7);
            TextColor(mau_chu);
            gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s %-14s %-29s%-15s %-34s", "Ma sinh vien", "Ho ten", "Ngay sinh", "Gioi tinh", "Ma lop", "Dia chi", "So dien thoai", "Email");
            size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 30, size[6] = 15, size[7] = 35;
            Table(x - 2, y + 1, size, 2, 1, 8, 170, 7);
            Xuat(a, x, y + 4);
            getch();
            return i;
        }
    TextColor(4);
    gotoXY(tbX, tbY);
    cout << "Ma sinh vien khong co trong danh sach!";
    getch();
    return -1;
}
void Sua(SinhVien *A, int n, string s, int x, int y, int tbX, int tbY){
    int index = TimKiem(A, n, s, x, y, tbX, tbY);
    if(index != -1)
        Sua(A[index], x, y, tbX, tbY);
}
void Xoa(SinhVien *A, int &n, string s, int x, int y, int tbX, int tbY){
    int index = TimKiem(A, n, s, x, y, tbX, tbY);
    if(index != -1){
        gotoXY(tbX, tbY);   cout << "Ban co chac muon xoa khong(y/n)? ";
        char c; cin >> c;
        if(c == 'y' || c == 'Y'){
            n--;
            for(int i=index; i<n; i++)
                A[i] = A[i-1];
            gotoXY(tbX, tbY + 1);   cout << "Xoa thanh cong!";
        }else{
            gotoXY(tbX, tbY + 1);   cout << "Xoa that bai!";
        }
    }
}
void DSTheoLop(SinhVien *A, int &n, string s, int x, int y){
    system("cls");
    int size[8] = {170};
    TextColor(mau_chu);
    gotoXY(x + 60, y); cout << "Danh sach sinh vien lop: " << s;
    Table(x - 2, y - 1, size, 2, 1, 1, 170, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s %-14s %-29s%-15s %-34s", "Ma sinh vien", "Ho ten", "Ngay sinh", "Gioi tinh", "Ma lop", "Dia chi", "So dien thoai", "Email");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 30, size[6] = 15, size[7] = 35;
    Table(x - 2, y + 1, size, 2, 1, 8, 170, 7);
    int dong = 0;
    for(int i=0; i<n; i++){
        if(A[i].MaLop == s)
            Xuat(A[i], x, y + 4 + 2*dong++);
    }
    getch();
}

// gv
bool doc_file(GiangVien *A, int &n){
    n = 0;
    ifstream cin("./DSGiangVien.txt");
    if(!(cin))
        return false;
    while(1){
        GiangVien a;
        if(!(cin >> a.MaGV))
            return true;
        cin.ignore();
        getline(cin, a.TenGV);
        getline(cin, a.NgaySinh );
        getline(cin, a.GioiTinh );
        getline(cin, a.Khoa );
        getline(cin, a.SDT );
        getline(cin, a.Email );
        A[n++] = a;
    }
}
void xuat_file(GiangVien *A, int &n){
    ofstream cin("./DSGiangVienNew.txt");
    for(int i=0; i<n; i++){
    	cout << A[i].MaGV<< endl;
    	cout << A[i].TenGV<< endl; 
		cout << A[i].NgaySinh<< endl; 
		cout << A[i].GioiTinh<< endl; 
		cout << A[i].Khoa<< endl; 
		cout << A[i].SDT<< endl; 
		cout << A[i].Email<< endl;   	
	}
}
void Nhap(GiangVien *A, int &n, int x, int y, int tbX, int tbY){
    int size[7] = {155};
    fflush(stdin);
    TextColor(mau_chu);
    gotoXY(x + 50, y); cout << "Thong tin giang vien";
    Table(x - 2, y - 1, size, 2, 1, 1, 155, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s %-29s%-15s %-34s", "Ma giang vien", "Ho ten", "Ngay sinh", "Gioi tinh", "Khoa", "So dien thoai", "Email");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 30, size[5] = 15, size[6] = 35;
    Table(x - 2, y + 1, size, 2, 1, 7, 155, 7);
    int i = 0;
    char c;
    while(1){
        GiangVien a;
        TextColor(7);
        Table(x - 2, y + 3 + 2*i, size, 2, 1, 7, 155, 7);
        a.MaGV = nhap_ma(x, y + 4 + 2*i, tbX, tbY, 10);
        a.TenGV = nhap_ten(x + 15, y + 4 + 2*i, tbX, tbY, 28);
        a.NgaySinh = nhap_ngay(x + 45, y + 4 + 2*i, tbX, tbY, 10);
        a.GioiTinh = nhap_ten(x + 60, y + 4 + 2*i, tbX, tbY, 10);
        a.Khoa = nhap_ten(x + 75, y + 4 + 2*i, tbX, tbY, 28);
        a.SDT = nhap_sdt(x + 105, y + 4 + 2*i, tbX, tbY, 10);
        a.Email = nhap_email(x + 115, y + 4 + 2*i, tbX, tbY, 28);
        TextColor(mau_chu);
        gotoXY(tbX, tbY);   cout << "Bam ESC de thoat!";
        c = getch();
        if(c == 27)
            break;
        i++;
        A[n] = a;
        n++;
    }
}
void Xuat(GiangVien a, int x, int y){
    int size[7] = {155};
    int i = 1;
    TextColor(7);
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 30, size[5] = 15, size[6] = 35;
    gotoXY(x, y);
    cout << left << setw(15) << a.MaGV << setw(size[1]) << a.TenGV << setw(size[2]) << a.NgaySinh << setw(size[3])
     << a.GioiTinh << setw(size[4]) << a.Khoa << setw(size[5]) << a.SDT << setw(size[6]) << a.Email;
    Table(x - 2, y - 1, size, 2, 1, 7, 155, 7);
}
void Sua(GiangVien &giang_vien, int x, int y, int tbX, int tbY){
    GiangVien a = giang_vien;
    int i = 0;
    a.TenGV = nhap_ten(x + 15, y + 4 + 2*i, tbX, tbY, 28);
    a.NgaySinh = nhap_ngay(x + 45, y + 4 + 2*i, tbX, tbY, 10);
    a.GioiTinh = nhap_ten(x + 60, y + 4 + 2*i, tbX, tbY, 10);
    a.Khoa = nhap_ten(x + 75, y + 4 + 2*i, tbX, tbY, 28);
    a.SDT = nhap_sdt(x + 105, y + 4 + 2*i, tbX, tbY, 10);
    a.Email = nhap_email(x + 115, y + 4 + 2*i, tbX, tbY, 28);
    gotoXY(tbX, tbY);   cout << "Ban co chac muon cap nhat khong(y/n)? ";
    char c; cin >> c;
    if(c == 'y' || c == 'Y'){
        giang_vien = a;
        gotoXY(tbX, tbY + 1);   cout << "Cap nhat thanh cong!";
    }else{
         gotoXY(tbX, tbY + 1);   cout << "Cap nhat that bai!";
    }
}
int TimKiem(GiangVien *A, int n, string s, int x, int y, int tbX, int tbY){
    for(int i=0; i<n; i++)
        if(A[i].MaGV == s){
            GiangVien a = A[i];
            int size[7] = {155};
            TextColor(mau_chu);
            gotoXY(x + 50, y); cout << "Thong tin giang vien";
            Table(x - 2, y - 1, size, 2, 1, 1, 155, 7);
            TextColor(mau_chu);
            gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s %-29s%-15s %-34s", "Ma giang vien", "Ho ten", "Ngay sinh", "Gioi tinh", "Khoa", "So dien thoai", "Email");
            size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 30, size[5] = 15, size[6] = 35;
            Table(x - 2, y + 1, size, 2, 1, 7, 155, 7);
            Xuat(a, x, y + 4);
            getch();
            return i;
    }
    TextColor(4);
    gotoXY(tbX, tbY);
    cout << "Ma giang vien khong co trong danh sach!";
    getch();
    return -1;
}
void Sua(GiangVien *A, int n, string s, int x, int y, int tbX, int tbY){
    int index = TimKiem(A, n, s, x, y, tbX, tbY);
    if(index != -1)
        Sua(A[index], x, y, tbX, tbY);
}
void DSTheoKhoa(GiangVien *A, int &n, string s, int x, int y){
    system("cls");
    int size[7] = {155};
    TextColor(mau_chu);
    gotoXY(x + 50, y); cout << "Danh sach giang vien khoa: " << s;
    Table(x - 2, y - 1, size, 2, 1, 1, 155, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s %-29s%-15s %-34s", "Ma giang vien", "Ho ten", "Ngay sinh", "Gioi tinh", "Khoa", "So dien thoai", "Email");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 30, size[5] = 15, size[6] = 35;
    Table(x - 2, y + 1, size, 2, 1, 7, 155, 7);
    int dong = 0;
    for(int i=0; i<n; i++){
        if(in_thuong(A[i].Khoa).find(in_thuong(s)) != -1)
            Xuat(A[i], x, y + 4 + 2*dong++);
    }
    getch();
}
void DSTheoTen(GiangVien *A, int &n, string s, int x, int y){
    system("cls");
    int size[7] = {155};
    TextColor(mau_chu);
    gotoXY(x + 50, y); cout << "Danh sach giang vien ten: " << s;
    Table(x - 2, y - 1, size, 2, 1, 1, 155, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s %-29s%-15s %-34s", "Ma giang vien", "Ho ten", "Ngay sinh", "Gioi tinh", "Khoa", "So dien thoai", "Email");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 30, size[5] = 15, size[6] = 35;
    Table(x - 2, y + 1, size, 2, 1, 7, 155, 7);
    int dong = 0;
    for(int i=0; i<n; i++){
        if(in_thuong(A[i].TenGV).find(in_thuong(s)) != -1)
            Xuat(A[i], x, y + 4 + 2*dong++);
    }
    getch();
}


// tin
bool doc_file(TinChi *A, int &n){
    n = 0;
    ifstream cin("./DSTinChi.txt");
    if(!(cin))
        return false;
    while(1){
        TinChi a;
        if(!(getline(cin, a.MaTC)))
            return true;
        getline(cin, a.TenTC);
        cin >> a.LT >> a.TH >> a.SVMax >> a.SVMin >> a.TrangThai >> a.MaGV1 >> a.MaGV2;
        cin.ignore();
        A[n++] = a;
    }
}
void xuat_file(TinChi *A, int &n){
    ofstream cout("./DSTinChiNew.txt");
   for(int i=0; i<n; i++){
   	cout << A[i].MaTC<< endl;
   	cout << A[i].TenTC<< endl;
   	cout << A[i].LT<< endl;
   	cout << A[i].TH<< endl;
   	cout << A[i].SVMax<< endl;
   	cout << A[i].SVMin<< endl;
   	cout << A[i].TrangThai<< endl;
   	cout << A[i].MaGV1<< endl;
   	cout << A[i].MaGV2<< endl;
   }
}
void Nhap(TinChi *A, int &n, int x, int y, int tbX, int tbY){
    int size[9] = {150};
    fflush(stdin);
    TextColor(mau_chu);
    gotoXY(x + 45, y); cout << "Thong tin tin chi";
    Table(x - 2, y - 1, size, 2, 1, 1, 120, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s%-15s%-15s %-14s %-14s %-14s", "Ma tin chi", "Ten", "So tin LT", "So tin TH", "So luong max", "So luong min", "Trang thai", "GV day", "GV on tap");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 15, size[6] = 15;
    Table(x - 2, y + 1, size, 2, 1, 7, 120, 7);
    int i = 0;
    char c;
    while(1){
        TinChi a;
        TextColor(7);
        Table(x - 2, y + 3 + 2*i, size, 2, 1, 7, 120, 7);
        a.MaTC = nhap_ma(x, y + 4 + 2*i, tbX, tbY, 10);
        a.TenTC = nhap_ten(x + 15, y + 4 + 2*i, tbX, tbY, 28);
        do{
            a.LT = string_sang_int(nhap_sdt(x + 45, y + 4 + 2*i, tbX, tbY, 10));
            if(a.LT < 0 || a.LT > 2){
                TextColor(4);
                gotoXY(tbX, tbY);
                cout << "So tin LT thuoc [0, 2]!";
                getch();
                TextColor(0);
                gotoXY(tbX, tbY);
                cout << "So tin TH thuoc [0, 2]!";
            }else   
                break;
        }while(1);
        do{
            a.TH = string_sang_int(nhap_sdt(x + 60, y + 4 + 2*i, tbX, tbY, 10));
            if(a.TH < 0 || a.TH > 2){
                TextColor(4);
                gotoXY(tbX, tbY);
                cout << "So tin TH thuoc [0, 2]!";
                getch();
                TextColor(0);
                gotoXY(tbX, tbY);
                cout << "So tin TH thuoc [0, 2]!";
            }else   
                break;
        }while(1);
        do{
            a.SVMax = string_sang_int(nhap_sdt(x + 75, y + 4 + 2*i, tbX, tbY, 10));
            if(a.SVMax < 10 || a.SVMax > 15){
                TextColor(4);
                gotoXY(tbX, tbY);
                cout << "Toi da co [10, 15]!";
                getch();
                TextColor(0);
                gotoXY(tbX, tbY);
                cout << "Toi da co [10, 15]!";
            }else   
                break;
        }while(1);
        do{
            a.SVMin = string_sang_int(nhap_sdt(x + 90, y + 4 + 2*i, tbX, tbY, 10));
            if(a.SVMin < 5 || a.SVMin > 8){
                TextColor(4);
                gotoXY(tbX, tbY);
                cout << "Toi thieu phai co [5, 8]!";
                getch();
                TextColor(0);
                gotoXY(tbX, tbY);
                cout << "Toi thieu phai co [5, 8]!";
            }else   
                break;
        }while(1);
        do{
            a.TrangThai = string_sang_int(nhap_sdt(x + 105, y + 4 + 2*i, tbX, tbY, 10));
            if(a.TrangThai < 0 || a.TrangThai > 1){
                TextColor(4);
                gotoXY(tbX, tbY);
                cout << "Trang thai thuoc [0,1]!";
                getch();
                TextColor(0);
                gotoXY(tbX, tbY);
                cout << "Trang thai thuoc [0,1]!";
            }else   
                break;
        }while(1);
        TextColor(mau_chu);
        gotoXY(tbX, tbY);   cout << "Bam ESC de thoat!";
        c = getch();
        if(c == 27)
            break;
        i++;
        a.MaGV1 = "NULL";
        a.MaGV2 = "NULL";
        A[n] = a;
        n++;
    }
}
void Xuat(TinChi a, int x, int y){
    int size[9] = {150};
    TextColor(7);
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 15, size[6] = 15, size[7] = 15, size[8] = 15;
    gotoXY(x, y);
    cout << left << setw(15) << a.MaTC << setw(size[1]) << a.TenTC << setw(size[2]) << a.LT << setw(size[3])
    << a.TH << setw(size[4]) << a.SVMax << setw(size[5]) << a.SVMin << setw(size[6]) << a.TrangThai 
    << setw(size[6]) << a.MaGV1 << setw(size[6]) << a.MaGV2;
    Table(x - 2, y - 1, size, 2, 1, 9, 150, 7);
}
void Xuat(TinChi a, int x, int y, int color){
    int size[9] = {150};
    TextColor(color);
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 15, size[6] = 15, size[7] = 15, size[8] = 15;
    gotoXY(x, y);
    cout << left << setw(15) << a.MaTC << setw(size[1]) << a.TenTC << setw(size[2]) << a.LT << setw(size[3])
    << a.TH << setw(size[4]) << a.SVMax << setw(size[5]) << a.SVMin << setw(size[6]) << a.TrangThai 
    << setw(size[6]) << a.MaGV1 << setw(size[6]) << a.MaGV2;
    Table(x - 2, y - 1, size, 2, 1, 9, 150, 7);
}
void Sua(TinChi &tin_chi, int x, int y, int tbX, int tbY){
    TinChi a = tin_chi;
    a.TenTC = nhap_ten(x + 15, y + 4, tbX, tbY, 28);
    int i = 0;
    do{
        a.LT = string_sang_int(nhap_sdt(x + 45, y + 4 + 2*i, tbX, tbY, 10));
        if(a.LT < 0 || a.LT > 2){
            TextColor(4);
            gotoXY(tbX, tbY);
            cout << "So tin LT thuoc [0, 2]!";
            getch();
            TextColor(0);
            gotoXY(tbX, tbY);
            cout << "So tin TH thuoc [0, 2]!";
        }else   
            break;
    }while(1);
    do{
        a.TH = string_sang_int(nhap_sdt(x + 60, y + 4 + 2*i, tbX, tbY, 10));
        if(a.TH < 0 || a.TH > 2){
            TextColor(4);
            gotoXY(tbX, tbY);
            cout << "So tin TH thuoc [0, 2]!";
            getch();
            TextColor(0);
            gotoXY(tbX, tbY);
            cout << "So tin TH thuoc [0, 2]!";
        }else   
            break;
    }while(1);
    do{
        a.SVMax = string_sang_int(nhap_sdt(x + 75, y + 4 + 2*i, tbX, tbY, 10));
        if(a.SVMax < 10 || a.SVMax > 15){
            TextColor(4);
            gotoXY(tbX, tbY);
            cout << "Toi da co [10, 15]!";
            getch();
            TextColor(0);
            gotoXY(tbX, tbY);
            cout << "Toi da co [10, 15]!";
        }else   
            break;
    }while(1);
    do{
        a.SVMin = string_sang_int(nhap_sdt(x + 90, y + 4 + 2*i, tbX, tbY, 10));
        if(a.SVMin < 5 || a.SVMin > 8){
            TextColor(4);
            gotoXY(tbX, tbY);
            cout << "Toi thieu phai co [5, 8]!";
            getch();
            TextColor(0);
            gotoXY(tbX, tbY);
            cout << "Toi thieu phai co [5, 8]!";
        }else   
            break;
    }while(1);
    do{
        a.TrangThai = string_sang_int(nhap_sdt(x + 105, y + 4 + 2*i, tbX, tbY, 10));
        if(a.TrangThai < 0 || a.TrangThai > 1){
            TextColor(4);
            gotoXY(tbX, tbY);
            cout << "Trang thai thuoc [0,1]!";
            getch();
            TextColor(0);
            gotoXY(tbX, tbY);
            cout << "Trang thai thuoc [0,1]!";
        }else   
            break;
    }while(1);
    gotoXY(tbX, tbY);   cout << "Ban co chac muon cap nhat khong(y/n)? ";
    char c; cin >> c;
    if(c == 'y' || c == 'Y'){
        tin_chi = a;
        gotoXY(tbX, tbY + 1);   cout << "Cap nhat thanh cong!";
    }else{
         gotoXY(tbX, tbY + 1);   cout << "Cap nhat that bai!";
    }
}
int TimKiem(TinChi *A, int n, string s, int x, int y, int tbX, int tbY){
        for(int i=0; i<n; i++)
        if(A[i].MaTC == s){
            TinChi a = A[i];
            int size[9] = {150};
            TextColor(mau_chu);
            gotoXY(x + 55, y); cout << "Thong tin tin chi";
            Table(x - 2, y - 1, size, 2, 1, 1, 150, 7);
            TextColor(mau_chu);
            gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s%-15s%-15s %-14s %-14s %-14s", "Ma tin chi", "Ten", "So tin LT", "So tin TH", "So luong max", "So luong min", "Trang thai", "GV day", "GV on tap");
            size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 15, size[6] = 15, size[7] = 15, size[8] = 15 ;
            Table(x - 2, y + 1, size, 2, 1, 9, 150, 7);
            Xuat(a, x, y + 4);
            getch();
            return i;
        }
    TextColor(4);
    gotoXY(tbX, tbY);
    cout << "Tin chi khong co trong danh sach!";
    getch();
    return -1;
}
void Sua(TinChi *A, int n, string s, int x, int y, int tbX, int tbY){
    int index = TimKiem(A, n, s, x, y, tbX, tbY);
    if(index != -1)
        Sua(A[index], x, y, tbX, tbY);

}
void DSTheoTen(TinChi *A, int &n, string ten, int x, int y){
    system("cls");
    int size[9] = {150};
    TextColor(mau_chu);
    gotoXY(x + 45, y); cout << "Thong tin tin chi";
    Table(x - 2, y - 1, size, 2, 1, 1, 150, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s%-15s%-15s %-14s %-14s %-14s", "Ma tin chi", "Ten", "So tin LT", "So tin TH", "So luong max", "So luong min", "Trang thai", "GV day", "GV on tap");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 15, size[6] = 15, size[7] = 15, size[8] = 15 ;
    Table(x - 2, y + 1, size, 2, 1, 9, 150, 7);
    int dong = 0;
    string ten2 = ten;
    if(ten[0] >= 'a' && ten[0] <= 'z')
        ten2[0] -= 32;
    for(int i=0; i<n; i++){
        if(A[i].TenTC.find(ten) != -1 || A[i].TenTC.find(ten2) != -1)
            Xuat(A[i], x, y + 4 + 2*dong++);
    }
    getch();
}
void DSTinChi(TinChi *A, int n, int x, int y, int chuc_nang){
    system("cls");
    int size[9] = {150};
    TextColor(mau_chu);
    gotoXY(x + 45, y); cout << "Thong tin tin chi";
    Table(x - 2, y - 1, size, 2, 1, 1, 150, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s%-15s%-15s %-14s %-14s %-14s", "Ma tin chi", "Ten", "So tin LT", "So tin TH", "So luong max", "So luong min", "Trang thai", "GV day", "GV on tap");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 15, size[6] = 15, size[7] = 15, size[8] = 15 ;
    Table(x - 2, y + 1, size, 2, 1, 9, 150, 7);
    int dong = 0;
    for(int i=0; i<n; i++){
        if(i == chuc_nang)
            TextColor(mau_chu);
        else
            TextColor(7);
        Xuat(A[i], x, y + 4 + 2*dong++);
    }
    getch();
}

// chuc nang khac
void DanhSachDangKy(string maGV, TinChi* TC, int nTC, int x, int y, int tbX, int tbY){
    system("cls");
    int size[9] = {150};
    TextColor(mau_chu);
    gotoXY(x + 45, y); cout << "Thong tin tin chi";
    Table(x - 2, y - 1, size, 2, 1, 1, 150, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s%-15s%-15s %-14s %-14s %-14s", "Ma tin chi", "Ten", "So tin LT", "So tin TH", "So luong max", "So luong min", "Trang thai", "GV day", "GV on tap");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 15, size[6] = 15, size[7] = 15, size[8] = 15 ;
    Table(x - 2, y + 1, size, 2, 1, 9, 150, 7);
    int dong = 0;
    int soTin = 0;
    for(int i=0; i<nTC; i++){
        if(TC[i].MaGV1 == maGV){
            Xuat(TC[i], x, y + 4 + 2*dong++);
            soTin += TC[i].LT;
        }
        
        if(TC[i].MaGV2 == maGV){
            if(TC[i].MaGV1 != maGV)
                Xuat(TC[i], x, y + 4 + 2*dong++);
            soTin += TC[i].TH;
        }
    }
    TextColor(mau_chu);
    gotoXY(x, y + 4 + 2*dong); cout << "So tin da dang ky: " << soTin;
    size[0] = 30;
    Table(x - 2, y + 3 + 2*dong, size, 2, 1, 1, 30, 7); 
    getch();
}
void DangKyTin(string maGV, TinChi* TC, int nTC, int x, int y, int tbX, int tbY){
    DanhSachDangKy(maGV, TC, nTC, x, y, tbX, tbY);
    int size[9] = {150};
    int chuc_nang = 0;
    DSTinChi(TC, nTC, x, y, chuc_nang);
    while(1){
        if(kbhit()){
            char c = getch();
            Xuat(TC[chuc_nang], x, y + 4 + 2*chuc_nang, 7);
            switch (c){
                case 72:{
                    chuc_nang--;
                    if(chuc_nang < 0)
                        chuc_nang = nTC-1;
                    break;
                }
                case 80:{
                    chuc_nang++;
                    if(chuc_nang >= nTC)
                        chuc_nang = 0;
                    break;
                }
                case 13:{
                    string chon;
                    gotoXY(x, y + 2*nTC + 4); cout << "Dang ky o vi tri(day/on): "; cin >> chon;
                    if(chon == "day"){
                        if(TC[chuc_nang].MaGV1 != "NULL"){
                            gotoXY(tbX, tbY); TextColor(4); cout << "Vi tri day da co giang vien dang ky!";
                            break;
                        }else{
                            TC[chuc_nang].MaGV1 = maGV;
                            gotoXY(tbX, tbY); TextColor(mau_chu); cout << "Dang ky thanh cong!";
                            break;
                        }
                    }else{
                        if(TC[chuc_nang].MaGV2 != "NULL"){
                            gotoXY(tbX, tbY); TextColor(4); cout << "Vi tri on tap da co giang vien dang ky!";
                            break;
                        }else{
                            TC[chuc_nang].MaGV2 = maGV;
                            gotoXY(tbX, tbY); TextColor(mau_chu); cout << "Dang ky thanh cong!";
                            break;
                        }
                    }
                    return;
                }
                case 27:{
                    return;
                }
            }
            Xuat(TC[chuc_nang], x, y + 4 + 2*chuc_nang, mau_chu);
        }
    }
}
bool doc_file(DangKy* A, int &n){
    ifstream cin("./DSDangKy.txt");
    n = 0;
    if(!cin)
        return false;
    while(1){
        DangKy a;
        if(!(cin >> a.MaSV))
            return true;
        cin.ignore(); 
        getline(cin, a.MaTC);
        cin >> a.GK >> a.CK;
        A[n++] = a;
    }
    return true;
}
void xuat_file(DangKy* A, int &n){
    ofstream cout("./DSDangKyNew.txt");
   for(int i=0; i<n; i++){
   	cout << A[i].MaSV << endl;
   	cout << A[i].MaTC << endl;
   	cout << A[i].GK << endl;
   	cout << A[i].CK << endl;
   }
}
void Xuat(DangKy a, int x, int y){
    int size[4];
    TextColor(7);
    size[0] = 15, size[1] = 15, size[2] = 15, size[3] = 15;
    gotoXY(x, y);
    cout << left << setw(15) << a.MaSV << setw(15) << a.MaTC; 
    if(a.GK == -1)
        cout << setw(15) << "NULL";
    else    
        cout << fixed << setprecision(2) << setw(size[1]) << a.GK;
    
    if(a.CK == -1)
        cout << "NULL";
    else
        cout << setw(size[2])<< fixed << setprecision(2) << a.CK ;
    Table(x - 2, y - 1, size, 2, 1, 4, 60, 7);
}
void Xuat(DangKy a, int x, int y, int color){
    int size[4];
    TextColor(color);
    size[0] = 15, size[1] = 15, size[2] = 15, size[3] = 15;
    gotoXY(x, y);
    cout << left << setw(15) << a.MaSV << setw(15) << a.MaTC; 
    if(a.GK == -1)
        cout << setw(15) << "NULL";
    else    
        cout << fixed << setprecision(2) << setw(size[1]) << a.GK;
    
    if(a.CK == -1)
        cout << "NULL";
    else
        cout << setw(size[2])<< fixed << setprecision(2) << a.CK ;
    Table(x - 2, y - 1, size, 2, 1, 4, 60, 7);
}
bool Check(DangKy* A, int &n, string s){
    for(int i=0; i<n; i++){
        if(A[i].MaSV == s)
            return true;
    }
    return false;
}
void Them(string ma1, string ma2, DangKy* A, int &n){
    DangKy a;
    a.MaSV = ma1;
    a.MaTC = ma2;
    a.CK = -1;
    a.GK = -1;
    A[n++] = a;
}
void DangKyMon(string maSV, TinChi *TC, int nTC, DangKy* DK, int &nDK, int x, int y, int tbX, int tbY){
    int size[9] = {150};
    int chuc_nang = 0;
    DSTinChi(TC, nTC, x, y, chuc_nang);
    while(1){
        if(kbhit()){
            char c = getch();
            Xuat(TC[chuc_nang], x, y + 4 + 2*chuc_nang, 7);
            switch (c){
                case 72:{
                    chuc_nang--;
                    if(chuc_nang < 0)
                        chuc_nang = nTC-1;
                    break;
                }
                case 80:{
                    chuc_nang++;
                    if(chuc_nang >= nTC)
                        chuc_nang = 0;
                    break;
                }
                case 13:{
                    string chon;
                    gotoXY(x, y + 2*nTC + 4); cout << "Ban chac muon dang ky(y/n)? "; cin >> chon;
                    if(chon == "y"){
                        if(TC[chuc_nang].SVMax >= SoLuongSV(DK, nDK, TC[chuc_nang].MaTC)){
                            gotoXY(x, y + 2*nTC + 5); TextColor(4); cout << "Tin chi da du so luong!";
                        }else{
                            gotoXY(x, y + 2*nTC + 5); TextColor(mau_chu); cout << "Dang ky thanh cong!";
                            Them(maSV, TC[chuc_nang].MaTC, DK, nDK);
                        }
                    }
                    return;
                }
                case 27:{
                    return;
                }
            }
            Xuat(TC[chuc_nang], x, y + 4 + 2*chuc_nang, mau_chu);
        }
    }
}
void DSDangKy(DangKy* A, int &n, string s, int x, int y){
    system("cls");
    int size[4] = {60};
    TextColor(mau_chu);
    gotoXY(x + 5, y); cout << "Danh sach dang ki cua: " << s;
    Table(x - 2, y - 1, size, 2, 1, 1, 60, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-15s %-15s %-14s", "Ma sinh vien", "Ma mon", "Diem GK", "Diem CK");
    size[0] = 15, size[1] = 15, size[2] = 15, size[3] = 15;// size[4] = 30, size[5] = 15, size[6] = 35;
    Table(x - 2, y + 1, size, 2, 1, 4, 60, 7);
    int dong = 0;
    for(int i=0; i<n; i++){
        if(A[i].MaSV == s)
            Xuat(A[i], x, y + 4 + 2*dong++);
    }
    getch();
}
void HuyTin(DangKy* A, int &n, string s, int x, int y, int tbX, int tbY){
    DSDangKy(A, n, s, x, y);
    gotoXY(tbX, tbY);   cout << "Nhap ma tin chi muon huy: ";
    fflush(stdin); string ss; getline(cin, ss);
    gotoXY(tbX, tbY + 1); cout << "Ban chac muon huy khong(y/n)? "; char c; cin >> c;
    if(c == 'y'){
        for(int i=0; i<n; i++)
            if(A[i].MaSV == s && A[i].MaTC == ss){
                n--;
                for(; i<n; i++)
                    A[i] = A[i+1];
            }
    } 
}
int SoLuongSV(DangKy* A, int &n, string s){
    int count = 0;
    for(int i=0; i<n; i++)
        if(A[i].MaTC == s)
            count++;
    return count;
}
void HuyTin(TinChi* TC, int nTC, DangKy *DK, int nDK, int x, int y){
    system("cls");
    int size[9] = {150};
    TextColor(mau_chu);
    gotoXY(x + 45, y); cout << "Thong tin tin chi chua du so luong";
    Table(x - 2, y - 1, size, 2, 1, 1, 150, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-29s %-14s %-14s%-15s%-15s %-14s %-14s %-14s", "Ma tin chi", "Ten", "So tin LT", "So tin TH", "So luong max", "So luong min", "Trang thai", "GV day", "GV on tap");
    size[0] = 15, size[1] = 30, size[2] = 15, size[3] = 15, size[4] = 15, size[5] = 15, size[6] = 15, size[7] = 15, size[8] = 15 ;
    Table(x - 2, y + 1, size, 2, 1, 9, 150, 7);
    int dong = 0;
    for(int i=0; i<nTC; i++){
        if(TC[i].SVMin > SoLuongSV(DK, nDK, TC[i].MaTC))
            Xuat(TC[i], x, y + 4 + 2*dong++);
    }
    gotoXY(x, y + 4 + 2*dong);
    cout << "Ban muon huy nhung tin khong chua dat so luong(y/n)?  ";
    char c; cin >> c;
    if(c == 'y')
        for(int i=0; i<nTC; i++){
        if(TC[i].SVMin > SoLuongSV(DK, nDK, TC[i].MaTC))
            TC[i].TrangThai = "0";
        }
    getch();
}
void DSLop(string s, DangKy* DK, int nDK, int x, int y){
    system("cls");
    int size[4] = {60};
    TextColor(mau_chu);
    gotoXY(x, y); cout << "Danh sach mon: " << s;
    Table(x - 2, y - 1, size, 2, 1, 1, 60, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-15s %-15s %-14s", "Ma sinh vien", "Ma tin chi", "Diem GK", "Diem CK");
    size[0] = 15, size[1] = 15, size[2] = 15, size[3] = 15; // size[4] = 30, size[5] = 15, size[6] = 35;
    Table(x - 2, y + 1, size, 2, 1, 4, 60, 7);
    int dong = 0;
    for(int i=0; i<nDK; i++){
        if(DK[i].MaTC == s)
            Xuat(DK[i], x, y + 4 + 2*dong++);
    }
    getch();
}
void NhapDiem1(string s, DangKy* DK, int nDK, int x, int y){
    DangKy Tam[100]; int nTam = 0;
    for(int i=0; i<nDK; i++){
        if(DK[i].MaTC == s)
            Tam[nTam++] = DK[i];
    }
    int dong = 0, cot = 0;
    system("cls");
    int size[4] = {60};
    TextColor(mau_chu);
    gotoXY(x, y); cout << "Danh sach mon: " << s;
    Table(x - 2, y - 1, size, 2, 1, 1, 60, 7);
    TextColor(mau_chu);
    gotoXY(x, y + 2); printf("%-15s %-15s %-15s %-14s", "Ma sinh vien", "Ma tin chi", "Diem GK", "Diem CK");
    size[0] = 15, size[1] = 15, size[2] = 15, size[3] = 15; // size[4] = 30, size[5] = 15, size[6] = 35;
    Table(x - 2, y + 1, size, 2, 1, 4, 60, 7);
    if(nTam == 0){
        gotoXY(x, y + 4 + 6);
        cout << "Danh sach lop trong!";
        getch();
        return;
    }
    for(int i=0; i<nTam; i++)
        Xuat(Tam[i], x, y + 4 + 2*dong++);
    dong = 0;
    while(1){
        if(kbhit()){
            char c = getch();
            Xuat(Tam[dong], x, y + 4 + 2*dong);
            switch(c){
                case 72: { // di len
                dong--;
                if (dong == -1)
                    dong = nTam - 1;
                break;
            }
            case 80: { // di xuong
                dong++;
                if (dong == nTam )
                    dong = 0;
                break;
            }
            case 27:
                for(int i=0; i<nTam; i++)
                    for(int j=0; j<nDK; j++)
                        if(Tam[i].MaSV == DK[j].MaSV && Tam[i].MaTC == DK[j].MaTC){
                            DK[j] = Tam[i];
                            break;
                        }
                return;
            case 13: {
                gotoXY(x + 30, y + 4 + 2*dong); cout << "      ";
                gotoXY(x + 45, y + 4 + 2*dong); cout << "      ";
                gotoXY(x + 30, y + 4 + 2*dong); cin >> Tam[dong].GK;
                gotoXY(x + 45, y + 4 + 2*dong); cin >> Tam[dong].CK;
            }
            }
            Xuat(Tam[dong], x, y + 4 + 2*dong, mau_chu);
        }
    }
}
void NhapDiem(string maGV, TinChi* TC, int nTC, DangKy* DK, int nDK, int x, int y, int tbX, int tbY){
    DanhSachDangKy(maGV, TC, nTC, x, y, tbX, tbY);
    fflush(stdin);
    gotoXY(tbX, tbY);
    string s;
    cout << "Nhap ma mon: "; getline(cin, s);
    NhapDiem1(s, DK, nDK, x, y);
}
