// do an Ptit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "giaoDien.h"
#include "xuLy.h"
using namespace std;
#define setColorTable 7
#define setColorText 11
#define setColorMenu1 12
#define setColorMenu0 14
#define setX 30
#define setY 5
#define TbX 30
#define TbY 20
int main(){
    char monHocInput[] = "./monHoc.txt";
    char sinhVienInput[] = "./sinhVien.txt";
    char tinChiInput[] = "./lop.txt";
    char dsHSInput[] = "./danhSachHS.txt";
    
    Tree* root;   Init(monHocInput, root);
    Node1* headSV; Init(sinhVienInput, headSV);
    Lop* A[10000];
    int n;   Init(tinChiInput, A, n);
    InitDS(dsHSInput, A, n);
    //return 0;
    int chucNang[3];
    do {
        chucNang[0] = menu(0); // menu chinh
        ChuThich(TbX, TbY + 2);
        switch (chucNang[0]) { 
            case 1: { // mon hoc
                do {
                    chucNang[1] = menu(1); // bat dau menu chuc nang 1
                    ChuThich(TbX, TbY + 2);
					switch (chucNang[1]) {
                        case 1: {
                            do {
                                system("cls");
                                ChuThich(TbX, TbY + 2);
                                chucNang[2] = menu(4); // bat dau menu chuc nang 2
                                switch (chucNang[2]) {
                                    case 1: {
                                        MonHoc x;
                                        if(Nhap(x)){
                                        	Push(root, x);
		                                    Loading(TbX, TbY, 300);
		                                    gotoXY(TbX, TbY + 1);
		                                    cout << "Them thanh cong!";
										}else{
											gotoXY(TbX, TbY + 1);
		                                    cout << "Them that bai!";
										}
                                        
                                        getch();
                                        break;
                                    }
                                    case 2: {
                                        TextColor(setColorText);
                                        char mamh[10];
                                        gotoXY(setX, setY);
                                        cout << "Nhap ma mon: ";
                                        cin >> mamh;
                                        if(Delete(root, mamh)){
                                        	Loading(TbX, TbY, 300);
                                        gotoXY(TbX, TbY + 1);
                                        cout << "Xoa thanh cong!";
										}else{
											gotoXY(TbX, TbY + 1);
                                        cout << "Ma khong co trong danh sach!";
										}
                                        getch();
                                        break;
                                    }
                                    case 3: {
                                    	bool trangthai = false;
                                        TextColor(setColorText);
                                        char mamh[10];
                                        gotoXY(setX, setY);
                                        cout << "Nhap ma mon: ";
                                        cin >> mamh;
                                        Update(root, mamh, trangthai);
                                        Loading(TbX, TbY, 300);
                                        gotoXY(TbX, TbY + 1);
                                        if(trangthai)
                                        	cout << "Cap nhat thanh cong!";
                                        else
                                        	cout << "Cap nhat that bai!";
                                        getch();
                                        break;
                                    }
                                }
                            } while (chucNang[2] != 0);
                            break;
                        }
                        case 2: {
                            system("cls");
                            TextColor(setColorText);
                            Loading(TbX, TbY, 300);
                            DSMonHoc(root);
                            getch();
                            break;
                        }
                    }
                    system("cls");
                } while (chucNang[1] != 0);
                break;
            }
            case 2: { // tin chi
                do {
                    chucNang[1] = menu(2);
                    ChuThich(TbX, TbY + 2);
                    switch (chucNang[1]) {
                        case 1: { // them du lieu
                            do {ChuThich(TbX, TbY + 2);
                                chucNang[2] = menu(4); // bat dau menu chuc nang 2
                                switch (chucNang[2]) {
                                    case 1: {
                                        Push(A, n);
                                        Loading(TbX, TbY, 300);
//                                        gotoXY(TbX, TbY + 1);
                                        //getch();
                                        break;
                                    }
                                    case 2: {
                                        Delete(A, n);
                                        //Loading(TbX, TbY, 300);
//                                        gotoXY(TbX, TbY + 1);
                                        //getch();
                                        break;
                                    }
                                    case 3: {
                                        Update(A, n);
                                        //Loading(TbX, TbY, 300);
//                                        gotoXY(TbX, TbY + 1);
                                        //getch();
                                        break;
                                    }
                                }
                            } while (chucNang[2] != 0);
                            break;
                        }
                        case 2: {
                            TextColor(setColorText);
                            gotoXY(setX, setY);
                            char masv[16];
                            cout << "Nhap ma sinh vien: ";
                            cin >> masv;
                            Node1* x = Search(headSV, masv, 0);
                            if (x != NULL)  {
                                if (strcmp(x->data.MASV, masv) == 0)
                                    Xuat(x->data);
                                else
                                    Xuat(x->next->data);
                                int soTin = soTinDaDangKy(root, A, n, masv);
	                            gotoXY(setX, setY + 6);
	                            cout << "So tin da dang ki: " << soTin;
                                if(soTin > 21){
                                	gotoXY(setX, setY + 7);
                                	cout << "So tin cua ban da vuot qua 21 tin!";
                                	getch();
                                	system("cls");
                                	break;
								}
								if(soTin < 14){
									gotoXY(setX, setY + 7);
                                	cout << "So tin ban dang ky dang o duoi muc toi thieu!";
								}
                                char nien[11];
                                int hk;
                                getch();
                                system("cls");
                                gotoXY(setX, setY + 2);
                                cout << "Nhap nien: "; cin >> nien;
                                gotoXY(setX, setY + 3);
                                cout << "Nhap hoc ki: "; cin >> hk;
                                Search(root, A, n, nien, hk, masv);
                            }
                            break;
                        }
                        case 3: {
                            HuyLop(A, n);
                            break;
                        }
                        case 4: {
                        	char ma[10], nien[11], hk[5], nhom[5], svmin[5], svmax[5];
							int j;
							while(1){
								system("cls");
								j = 0;
								TextColor(setColorText);
								gotoXY(setX, setY + j++);
								cout << "Nhap ma mon hoc: "; cin >> ma;
								gotoXY(setX, setY + j++);
								cout << "Nhap nien khoa: "; cin >> nien;
								gotoXY(setX, setY + j++);
								cout << "Nhap hoc ki: "; cin >> hk;
								gotoXY(setX, setY + j++);
								cout << "Nhap nhom: "; cin >> nhom;
								if(KiemTraMa(ma) && KiemTraint(hk) && KiemTraint(nhom)){
									break;
								}
								gotoXY(TbX, TbY);
								cout << "Nhap sai kieu du lieu!";
								gotoXY(TbX, TbY + 1);
								system("pause");
							}
                            system("cls");
                            NhapDiem(A, n, ma, nien, Float(hk), Float(nhom), headSV, 1);
                            system("cls");
                            break;
                        }
                        case 5: {
                            char ma[10], nien[11], hk[5], nhom[5], svmin[5], svmax[5];
							int j;
							while(1){
								system("cls");
								j = 0;
								TextColor(setColorText);
								gotoXY(setX, setY + j++);
								cout << "Nhap ma mon hoc: "; cin >> ma;
								gotoXY(setX, setY + j++);
								cout << "Nhap nien khoa: "; cin >> nien;
								gotoXY(setX, setY + j++);
								cout << "Nhap hoc ki: "; cin >> hk;
								gotoXY(setX, setY + j++);
								cout << "Nhap nhom: "; cin >> nhom;
								if(KiemTraMa(ma) && KiemTraint(hk) && KiemTraint(nhom)){
									break;
								}
								gotoXY(TbX, TbY);
								cout << "Nhap sai kieu du lieu!";
								gotoXY(TbX, TbY + 1);
								system("pause");
							}
                            system("cls");
                            gotoXY(setX, setY - 1);
                            cout << "Bang diem mon hoc: " << TenMH(root, ma) << endl;
                            gotoXY(setX, setY );
                            cout << "Nien khoa " << nien << " Hoc ky: " << hk << " Nhom: " << nhom << endl;
                            NhapDiem(A, n, ma, nien, Float(hk), Float(nhom), headSV, 0);
                            system("cls");
                            break;
                        }
                    }
                } while (chucNang[1] != 0);
                break;
            }
            case 3: { // sinh vien
                do {
                    chucNang[1] = menu(3);
                    ChuThich(TbX, TbY + 2);
                    switch (chucNang[1]) {
                        case 1: {
                            do {ChuThich(TbX, TbY + 2);
                                system("cls");
                                chucNang[2] = menu(4); // bat dau menu chuc nang 2
                                switch (chucNang[2]) {
                                    case 1: {
                                        SinhVien x;
                                        if(Nhap(x)){
                                        	Push(headSV, x, 1);
										}else{
											gotoXY(TbX, TbY);
											cout << "Them that bai!";
										}
                                        system("cls");
                                        getch();
                                        break;
                                    }
                                    case 2: {
                                        char masv[10];
                                        TextColor(setColorText);
                                        while(1){
                                        	system("cls");
                                        	gotoXY(setX, setY);
	                                        cout << "Nhap ma sv: ";
	                                        cin >> masv;
	                                        if(KiemTraMa(masv)){
	                                        	break;
											}
											gotoXY(TbX, TbY);
											cout << "Nhap sai kieu du lieu!";
											gotoXY(TbX, TbY + 1);
											system("pause");
										}
                                        if(Delete(headSV, masv)){
                                        	 system("cls");
		                                    Loading(TbX, TbY, 300);
		                                    gotoXY(TbX, TbY + 1);
		                                    cout << "Xoa thanh cong!";
										}else{
											gotoXY(TbX, TbY + 1);
		                                    cout << "Xoa that bai!";
										}
                                        getch();
                                        break;
                                    }
                                    case 3: {
                                        char masv[10];
                                        bool trangthai = false;
                                        TextColor(setColorText);
                                        gotoXY(setX, setY);
                                        cout << "Nhap ma sv: ";
                                        cin >> masv;
                                        Update(headSV, masv, trangthai);
                                        system("cls");
                                        Loading(TbX, TbY, 300);
                                        gotoXY(TbX, TbY + 1);
                                        if(trangthai)
                                        	cout << "Cap nhat thanh cong!";
                                        else
                                        	cout << "Cap nhat that bai!";
                                        getch();
                                        break;
                                    }
                                }
                            } while (chucNang[2] != 0);
                            break;
                        }
                        case 2: {
                            char malop[15] ;
                            TextColor(setColorText);
                            while(1){
                            	system("cls");
                            	gotoXY(setX, setY);
                            	cout << "Nhap ma lop: ";
                            	cin >> malop;
                                if(KiemTraMa(malop)){
                                	break;
								}
								gotoXY(TbX, TbY);
								cout << "Nhap sai kieu du lieu!";
								gotoXY(TbX, TbY + 1);
								system("pause");
							}
                            Loading(TbX, TbY, 300);
//                                        gotoXY(TbX, TbY + 1);
                            system("cls");
                            XuatDSSVTheoLop(headSV, malop);
                            break;
                        }
                        case 3: {
                            char ma[10];
                            TextColor(setColorText);
                            while(1){
                            	system("cls");
                            	gotoXY(setX, setY);
                            	cout << "Nhap ma lop: ";
                            	cin >> ma;
                                if(KiemTraMa(ma)){
                                	break;
								}
								gotoXY(TbX, TbY);
								cout << "Nhap sai kieu du lieu!";
								gotoXY(TbX, TbY + 1);
								system("pause");
							}
                            system("cls");
                            gotoXY(setX + 10, setY - 3);
                            cout << "Bang thong ke diem trung binh khoa hoc";
                            gotoXY(setX + 10, setY - 1);
                            cout << "Lop: " << ma;
                            DSdiemTB(A, n, ma, headSV);
                            break;
                        }
                        case 4: {
                            char ma[10];
                            TextColor(setColorText);
                            while(1){
                            	system("cls");
                            	gotoXY(setX, setY);
                            	cout << "Nhap ma lop: ";
                            	cin >> ma;
                                if(KiemTraMa(ma)){
                                	break;
								}
								gotoXY(TbX, TbY);
								cout << "Nhap sai kieu du lieu!";
								gotoXY(TbX, TbY + 1);
								system("pause");
							}
                            system("cls");
                            gotoXY(setX + 10, setY - 3);
                            cout << "Bang diem tong ket";
                            gotoXY(setX + 10, setY - 1);
                            cout << "Lop: " << ma;
                            DSdiemTK(A, n, ma, headSV, root);
                            break;
                        }
                    }
                } while (chucNang[1] != 0);
                break;
            }
            case 0: {
                SaveSinhVien(headSV);
                SaveMonHoc(root);
                SaveLop(A, n);
                SaveDSHS(A, n);
                cout << "bye";
                break;
            }
        }
    } while (chucNang[0] != 0);
}

