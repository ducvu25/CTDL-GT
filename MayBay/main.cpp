#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<queue>
#include<ctime>
using namespace std;
int xtrai = 20, ytren = 10;
int xThongBao = 40, yThongBao = 25;
int xTieuDe = 30, yTieuDe = 0;
int xHoatDong = 20, yHoatDong = yTieuDe + 10;
struct MayBay {
	char SoHieu[15];
	char Loai[40];
	int SoDay;
	int SoHang;
};
struct Khach {
	char cccd[13];
	char Ho[20];
	char Ten[20];
	char Phai[10];
};
struct Tree{
	Khach data;
	Tree *left;
	Tree *right;
};
struct Ve {
	char Ma[20];
	char cccd[13];
	Ve() {
		Ma[0] = '\0';
		cccd[0] = '\0';
	}
};
struct LVe{
	Ve data;
	LVe* next;
};
struct ChuyenBay {
	char Ma[15];
	char Ngay[11];
	char Gio[6];
	char Dich[40];
	int TrangThai;
	char SoHieu[15];
	LVe* head;
};
struct LChuyenBay{
	ChuyenBay data;
	LChuyenBay* next;
};
// giao dien
void TextColor(int color);
void gotoXY(int x, int y);
void Ox(int x1, int x2, int y);
void Oy(int y1, int y2, int x, int d) ;
void KhungChu(int x, int y, int* a, int b, int m, int n, int size, int color);
void XoaVung(int x1, int y1, int x2, int y2);
// menu
int Menu1(int x, int y, int d, int color);
int Menu2(int x, int y, int d, int loai, int color);
// xu li
void ChuanHoaChuoi(string &s);
void ChuanHoaNgay(string &s);
int SoSanhNgay(string d1, string d2);
void ChuanHoaGio(string &s);
int StringSangIn(string s);
char* StringSangChar(string s) ;
string InSangString(int x);
bool KiemTra(string &s, int loai, int len);
bool KiemTra(char* a, int loai, int len);
bool KiemTraNgay(int day, int month, int year);


// MÃ¡y bay
bool Nhap(MayBay& x) ;
void Xuat(MayBay x) ;
bool CapNhat(MayBay& a) ;
void DSSoHieu(MayBay* a[300], int n, int x, int y);
void NhapFile(MayBay* a[300], int& n) ;
void XuatFile(MayBay* a[300], int& n);
int TimKiem(MayBay* a[300], int n, char* SoHieu);
bool Xoa(MayBay* a[300], int& n, LChuyenBay* head);
bool Them(MayBay* a[300], int& n) ;
bool CapNhat(MayBay* a[300], int n, LChuyenBay* head) ;
void Xuat(MayBay* a[300], int n);

// khach

bool Nhap(Khach& x) ;
bool Nhap(Khach& x, string ma);
bool CapNhat(Khach& x);
void Xuat(Khach x) ;

Tree* TimKiem(Tree* root, char* cccd);
bool Them(Tree* &root, Khach x);
bool CapNhat(Tree* root, char* cccd);
void NhapFile(Tree*& root);
void XuatFile(Tree* root);
void TanCungTrai(Tree*& root, Tree* &nhanh);
bool Xoa(Tree* &root, char* cccd);
// ve

void Xuat(Ve x) ;

void Them(LVe*& head, Ve x);
LVe* TimKiem(LVe* head, char* ma);

bool Nhap(ChuyenBay& x, string ngay, string gio) ;
void Xuat(ChuyenBay x);
void KhoiTaoVe(LVe*& head, MayBay* a[300], int x) ;

void Them(LChuyenBay*& head, ChuyenBay x);
void XuatMaCB(LChuyenBay* head, int x, int y);
LChuyenBay* TimKiem(LChuyenBay* head, char* ma);
void NhapFile(LChuyenBay* &head, MayBay* a[300], int n) ;
void XuatFile(LChuyenBay* head) ;
bool Them(LChuyenBay*& head, MayBay* a[300], int n, string ngay, string gio) ;
void NhapDSVeFile(LChuyenBay* head);
void XuatDSVeFile(LChuyenBay* head);
void XuatDSVe(ChuyenBay a, int x, int y);
bool CapNhat(LChuyenBay* head, string ngay, string gio) ;
bool HuyChuyen(LChuyenBay*& head);
void DanhSachKhach(ChuyenBay x, Tree* root, int xhd, int yhd);
int main(){
	getch();
	time_t baygio = time(0); 
    tm *ltm = localtime(&baygio); 
	string ngay = InSangString(ltm->tm_mday) + "/" + InSangString(1 + ltm->tm_mon) + "/2022";
	ChuanHoaNgay(ngay);
	string gio = InSangString(1 + ltm->tm_hour) + ":" + InSangString(1 + ltm->tm_min);
	ChuanHoaGio(gio);
	int n; MayBay* a[300];	NhapFile(a, n);
	cout << 0;
	Tree* root; NhapFile(root);
	cout << 1;
	LChuyenBay* headChuyenBay; NhapFile(headChuyenBay, a, n);
	cout << 2;
	NhapDSVeFile(headChuyenBay);
	cout << 3;
	system("cls");
    while(1){
    	int k1 = Menu1(xTieuDe, yTieuDe+1, -1, 7);
    	switch(k1){
    		case 0:{
    			int k2;
    			do{
    				k2 = Menu2(xTieuDe + 20, yTieuDe + 1, 1, 0, 7);
					fflush(stdin);
    				switch(k2){
    					case 0: { DSSoHieu(a, n, xHoatDong + 70, yHoatDong);
                            if (Them(a, n)) {
                                gotoXY(xThongBao, yThongBao);
                                TextColor(11);
                                cout << "Them thanh cong!";
                            }
                            else {
                                gotoXY(xThongBao, yThongBao);
                                TextColor(4);
                                cout << "Them that bai!";
                            }     
                            gotoXY(xThongBao, yThongBao + 3+ 1); 
                            TextColor(7);
                            system("pause");
                            system("cls");
                            //XoaVung(0, 2, 40, 20);
                            break;
                        }
                        case 1: {DSSoHieu(a, n, xHoatDong + 70, yHoatDong);
                            if(Xoa(a, n, headChuyenBay)){
                                gotoXY(xThongBao, yThongBao);
                                TextColor(11);
                                cout << "Xoa thanh cong!";
                            }
                            else {
                                gotoXY(xThongBao, yThongBao);
                                TextColor(4);
                                cout << "Xoa that bai!";
                            }     
                            gotoXY(xThongBao, yThongBao + 3+ 1); 
                            TextColor(7);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 2: {DSSoHieu(a, n, xHoatDong + 70, yHoatDong);
                        	if(CapNhat(a, n, headChuyenBay)){
                                gotoXY(xThongBao, yThongBao+ 3);
                                TextColor(11);
                                cout << "Cap nhat thanh cong!";
                            }
                            else {
                                gotoXY(xThongBao, yThongBao+ 3);
                                TextColor(4);
                                cout << "Cap nhat that bai!";
                            }     
                            gotoXY(xThongBao, yThongBao + 3+ 1+ 3); 
                            TextColor(7);
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 3: {DSSoHieu(a, n, xHoatDong + 70, yHoatDong);
                        	char ma[15];
                        	gotoXY(xHoatDong, yHoatDong - 3);
                        	TextColor(11);
                        	cout << "Nhap so hieu may bay: ";TextColor(7); cin >> ma;
                        	int p = TimKiem(a, n, ma);
                            if (p != -1) {
                                Xuat(*a[p]);
                            }
                            else {
                                gotoXY(xThongBao, yThongBao+ 3);
                                TextColor(4);
                                cout << "May bay khong co trong danh sach!";
                            }     
                            gotoXY(xThongBao, yThongBao + 3+ 1+ 3); 
                            TextColor(7);
                            system("pause");
                            system("cls");
                            //XoaVung(0, 2, 40, 20);
                            break;
                        }
					}
					Menu1(xTieuDe, yTieuDe+1, 0, 7);
				}while(k2 != -1);
				break;
			}
			case 1:{
				int k2;
    			do{
    				k2 = Menu2(xTieuDe + 20, yTieuDe + 1, 1, 1, 7);
					fflush(stdin);
    				switch(k2){
    					case 0: {
    						ChuyenBay chuyenBayx; DSSoHieu(a, n, xHoatDong + 70, yHoatDong);
    						if(!Them(headChuyenBay, a, n, ngay, gio)){
                                gotoXY(xThongBao, yThongBao+ 3); 
                                TextColor(4);
                            	cout << "Nhap that bai!";
							}
                            gotoXY(xThongBao, yThongBao + 3+ 1 + 3); 
                            TextColor(7);
							system("pause");
							system("cls");
                            break;
                        }
                        case 1: {
                            XuatMaCB(headChuyenBay, xHoatDong + 70, yHoatDong);
							// gotoXY
                            if(CapNhat(headChuyenBay, ngay, gio)){
                                gotoXY(xThongBao, yThongBao+ 3); 
                                TextColor(11);
    							cout << "Cap nhat thanh cong!";
							}else{
                                gotoXY(xThongBao, yThongBao+ 3); 
                                TextColor(4);
                            	cout << "Cap nhat that bai!";
							}
                            gotoXY(xThongBao, yThongBao + 3+ 1); 
                            TextColor(7);
							system("pause");
							system("cls");
                            break;
                        }
                        case 2: {
                            XuatMaCB(headChuyenBay, xHoatDong + 70, yHoatDong);
                            if(HuyChuyen(headChuyenBay)){
                                gotoXY(xThongBao, yThongBao+ 3); 
                                TextColor(11);
    							cout << "Huy chuyen thanh cong!";
							}else{
                                gotoXY(xThongBao, yThongBao+ 3); 
                                TextColor(4);
                            	cout << "Huy chuyent that bai!";
							}
                            gotoXY(xThongBao, yThongBao + 3+ 1); 
                            TextColor(7);
							system("pause");
							system("cls");
                            break;
                        }
                	}
                	Menu1(xTieuDe, yTieuDe+1, 1, 7);
				}while(k2 != -1);
				break;
			}
			case 2:{
				int k2;
    			do{
    				k2 = Menu2(xTieuDe + 20, yTieuDe + 1, 1, 2, 7);
					fflush(stdin);
    				switch(k2){
    					case 0: { 
    						string cccd1;
    						string maChuyenBay1;
                            gotoXY(xHoatDong, yHoatDong + 2);
    						cout << "Nhap so cccd: ";TextColor(7); fflush(stdin); getline(cin, cccd1);
    						if(cccd1.size() == 12 && KiemTra(cccd1, 0, 12)){
    							char *cccd = StringSangChar(cccd1);
    							DatVe:
    							Tree* pKhach = TimKiem(root, cccd);
    							if(pKhach != NULL){
									XuatMaCB(headChuyenBay, xHoatDong + 70, yHoatDong);
    								Xuat(pKhach->data);
                                    gotoXY(xHoatDong, yHoatDong + 14);
									fflush(stdin);
    								cout << "Nhap ma chuyen bay: ";
    								TextColor(7);
    								getline(cin, maChuyenBay1);
    								if(KiemTra(maChuyenBay1, 1, 15) == false){
                                        gotoXY(xThongBao, yThongBao+ 3); 
                                        TextColor(4);
    									cout << "Ma chuyen khong hop le!";
									}else{
										LChuyenBay* p = TimKiem(headChuyenBay,(char*) maChuyenBay1.c_str());
										if(p == NULL){
                                            gotoXY(xThongBao, yThongBao+ 3); 
                                            TextColor(4);
											cout << "Ma chuyen co trong danh sach!";
										}else{
											int damua = 0;
											for(LVe* iVe=p->data.head; iVe != NULL; iVe=iVe->next)
												if(strcmp(iVe->data.cccd, cccd) == 0){
                                                    gotoXY(xHoatDong, yHoatDong + 16);
													cout << "Ve ban da mua la: " << iVe->data.Ma << " ";
													damua = 1;
													break;
												}
											if(damua == 0){
                                                if(SoSanhNgay(p->data.Ngay, ngay) < 1){
                                                    gotoXY(xThongBao, yThongBao+ 3); 
                                                    TextColor(4);
													cout << "Chuyen bay da cat canh!";
													getch();
                                                	system("cls");
                                                    break;
                                                }
												if(p->data.TrangThai == 0){
                                                    gotoXY(xThongBao, yThongBao+ 3); 
                                                    TextColor(4);
													cout << "Chuyen bay da bi huy!";
													getch();
                                                	system("cls");
                                                    break;
                                                }
                                                getch();
                                                system("cls");
												XuatDSVe(p->data, xHoatDong, yHoatDong - 4);
												string maVe1;
                                                gotoXY(xHoatDong, yHoatDong + 17);
												cout << "Nhap ma ve muon dang ki: ";
                                                fflush(stdin);
												getline(cin, maVe1);
												if(KiemTra(maVe1, 1, 15) == false){
                                                    gotoXY(xThongBao, yThongBao+ 3); 
                                                    TextColor(4);
													cout << "Ma ve khong hop le!";
												}else{
													if(p->data.TrangThai != 1){
														switch(p->data.TrangThai){
															gotoXY(xThongBao, yThongBao+ 3); 
															TextColor(4);
															case 0:{
																cout << "Chuyen bay da bi huy";
																break;
															}
															case 2:{
																cout << "Chuyen bay da het ve";
																break;
															}
															case 3:{
																cout << "Chuyen bay da hoan tat";
																break;
															}
														}
													}else{
														int datVeThanhCong = 0;
														for(LVe* iVe=p->data.head; iVe != NULL; iVe=iVe->next)
															if(strcmp(iVe->data.Ma, (char*)maVe1.c_str()) == 0 && strlen(iVe->data.cccd) != 12){
																strcpy(iVe->data.cccd, cccd);
																gotoXY(xThongBao, yThongBao+ 3); TextColor(11);
																cout << "Dat ve thanh cong!";
																datVeThanhCong = 1;
																for(iVe=p->data.head; iVe != NULL; iVe=iVe->next){
																	if(strlen(iVe->data.cccd) != 12)
																		goto OUT1;
																}
																p->data.TrangThai = 2;
															}
															OUT1:
														if(datVeThanhCong == 0){
															gotoXY(xThongBao, yThongBao+ 3); 
															TextColor(4);
															cout << "Dat ve that bai!";
														}
													}
												}
											}
										}
									}
								}else{
                                    gotoXY(xThongBao, yThongBao+ 3); 
                                    TextColor(4);
									cout << "Ban chua dang ki thong tin! Vui long nhap thong tin de dang ki!";
									getch();
									gotoXY(xThongBao, yThongBao+ 3); 
									cout << "                                                               ";
									Khach khachx;
									if(Nhap(khachx, cccd1)){
										Them(root, khachx);
										strcpy(cccd, khachx.cccd);
										goto DatVe;
									}else{
                                        gotoXY(xThongBao, yThongBao+ 3); 
                                        TextColor(4);
										cout << "Nhap thong tin that bai!";
									}
								}
							}else{
                                gotoXY(xThongBao, yThongBao+ 3);
								TextColor(4); 
								cout << "cccd khong hop le!";
							}
                            gotoXY(xThongBao, yThongBao + 3+ 1); 
                            TextColor(7);
                            system("pause");
                            system("cls");
                            //XoaVung(0, 2, 40, 20);
                            break;
                        }
                        case 1: {
                        	char cccd[15], maChuyenBay[15];
                        	fflush(stdin);
                            gotoXY(xHoatDong, yHoatDong - 3);   cout << "Nhap cccd: "; TextColor(7);cin.getline(cccd, 15);
                            if(KiemTra(cccd, 0, 15) == false || strlen(cccd) != 12 ){
                                gotoXY(xThongBao, yThongBao+ 3); 
                                TextColor(4);
                                cout << "Can cuoc nhap khong chinh xac!";
                                getch();
                                system("cls");
                                break;
                            }
							XuatMaCB(headChuyenBay, xHoatDong + 70, yHoatDong);
                        	gotoXY(xHoatDong, yHoatDong - 2); cout << "Nhap ma chuyen bay: ";TextColor(7); cin.getline(maChuyenBay, 15);
                            if(KiemTra(maChuyenBay, 1, 15) == false){
                                gotoXY(xThongBao, yThongBao+ 3); 
                                TextColor(4);
                                cout << "Thong tin nhap khong chinh xac!";
                            }else {
                                LChuyenBay* p = TimKiem(headChuyenBay, maChuyenBay);
								if(p == NULL){
                                    gotoXY(xThongBao, yThongBao+ 3); 
                                    TextColor(4);
									cout << "Ma chuyen khong hop le!";
								}else{
									if(p->data.TrangThai != 1){
										switch(p->data.TrangThai){
											gotoXY(xThongBao, yThongBao+ 3); 
											TextColor(4);
											case 0:{
												cout << "Chuyen bay da bi huy";
												break;
											}
											case 2:{
												cout << "Chuyen bay da het ve";
												break;
											}
											case 3:{
												cout << "Chuyen bay da hoan tat";
												break;
											}
										}
									}else{
										for(LVe* iVe=p->data.head; iVe != NULL; iVe=iVe->next)
										if(strcmp(iVe->data.cccd, cccd) == 0){
											char xacNhan;
                                            gotoXY(xHoatDong, yHoatDong - 1);
											cout << "Ve ban da mua la: " << iVe->data.Ma;
                                            gotoXY(xThongBao, yThongBao+ 3); 
											cout << "Bam s de xac nhan huy ve!";
											cin >> xacNhan;
											if(xacNhan == 's'){
												iVe->data.cccd[0] = '\0'; 
                                                gotoXY(xThongBao, yThongBao + 3+ 3); 
                                                TextColor(11);
												cout << "Huy thanh cong!";
											}
											goto OUT2;
										}
                                    gotoXY(xThongBao, yThongBao + 3+ 3); 
                                    TextColor(4);
									cout << "Ban chua dang ki ve!";
									}
								}
                            }     
                            OUT2:
                            gotoXY(xThongBao, yThongBao + 3+ 1); 
                            TextColor(7);
                            system("pause");
                            system("cls");
                            break;
                        }
					}
					Menu1(xTieuDe, yTieuDe+1, 2, 7);
				}while(k2 != -1);
				break;
			}
			case 3:{
				int k2;
    			do{
    				k2 = Menu2(xTieuDe + 20, yTieuDe + 1, 1, 3, 7);
    				switch(k2){
    					case 0: {
                            XuatMaCB(headChuyenBay, xHoatDong + 70, yHoatDong);
                            int stt = 0;
                            char maChuyenBay[15];
                            gotoXY(xHoatDong, yHoatDong - 2);
                            cout << "Nhap ma chuyen bay: ";TextColor(7); fflush(stdin); cin.getline(maChuyenBay, 15);
                            if(KiemTra(maChuyenBay, 1, 15) == false){
                                gotoXY(xThongBao, yHoatDong+4 + 2*stt++ + 2); 
                                TextColor(4);
                            	cout << "Ma chuyen bay khong hop le!";
							}else{
								LChuyenBay* p = TimKiem(headChuyenBay, maChuyenBay);
								if(p == NULL){
                                    gotoXY(xThongBao, yHoatDong+4 + 2*stt++ + 2); 
                                    TextColor(4);
									cout << "Ma chuyen khong co trong danh sach!";
								}else{
									system("cls");
                                    Xuat(p->data);
									getch();
									system("cls");
									DanhSachKhach(p->data, root, xHoatDong, yHoatDong);
								}
							}
                            gotoXY(xThongBao, yHoatDong+4 + 2*stt++ + 1); 
                            TextColor(7);
                            system("pause");
                            system("cls");
                            //XoaVung(0, 2, 40, 20);
                            break;
                        }
                        case 1: {
                            int stt = 0;
                        	char ngay1[100];
                        	char dichDen[30];
                        	fflush(stdin);
                            gotoXY(xHoatDong, yHoatDong - 2); cout << "Nhap ngay: "; cin.getline(ngay1, 100);
                        	if(KiemTra(ngay1, 2, 16) == false){
                                gotoXY(xThongBao, yThongBao); 
                        		cout << "Ngay khong hop le!";
							}else{
                                gotoXY(xHoatDong, yHoatDong - 1); cout << "Nhap dich den: "; cin.getline(dichDen, 30);
                                if(KiemTra(dichDen, 1, 30) == false){
                                    gotoXY(xThongBao, yThongBao); 
                        		    cout << "Ngay khong hop le!";
                                }else{
                                    int size1[1] = {60};
                                    int size[3] = {15, 25, 20};
                                    KhungChu(xHoatDong-3, yHoatDong, size1, 2, 1, 1, 60, 7);
                                    gotoXY(xHoatDong + 5, yHoatDong+1);
                                    cout << "Chuyen bay den: " << dichDen << " - " << ngay1 << " ";
                                    gotoXY(xHoatDong, yHoatDong+3);
                                    cout << left << setw(15) << "Ma chuyen" << setw(25) << "Gio khoi hanh" << setw(20) << "So ve trong";
                                    KhungChu(xHoatDong-3, yHoatDong+2, size, 2, 1, 3, 60, 7);
                                    for(LChuyenBay* iChuyenBay = headChuyenBay; iChuyenBay != NULL; iChuyenBay=iChuyenBay->next){
                                        if(strcmp(iChuyenBay->data.Ngay, ngay1) == 0 && strcmp(iChuyenBay->data.Dich, dichDen) == 0){
                                            gotoXY(xHoatDong, yHoatDong+5 + 2*stt);
                                            cout << left << setw(15) << iChuyenBay->data.Ma << setw(25) << iChuyenBay->data.Gio;
                                            int soVe = 0;
                                            for(LVe* iVe = iChuyenBay->data.head; iVe != NULL; iVe = iVe->next){
                                                if(strlen(iVe->data.cccd) != 12)
                                                    soVe++;
                                            }
                                            cout << setw(20) << soVe;
                                            KhungChu(xHoatDong-3, yHoatDong+4 + 2*stt++, size, 2, 1, 3, 60, 7);
                                        }
							    	}
                                }
							}
                            gotoXY(xThongBao, yHoatDong+6 + 2*stt++); 
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 2: {
                        	int soLan[300];
                        	MayBay B[300];
                        	for(int SoLan = 0; SoLan <n; SoLan++){
                        		soLan[SoLan] = 0;
							}
							for(int i=0; i<n; i++){
								for(LChuyenBay* iChuyenBay = headChuyenBay; iChuyenBay != NULL; iChuyenBay=iChuyenBay->next){
									if(strcmp(iChuyenBay->data.SoHieu, a[i]->SoHieu) == 0 && iChuyenBay->data.TrangThai != 0)
										soLan[i]++;
								}
								B[i] = *a[i];
							}
							for(int i=0; i<n; i++)
								for(int j=i+1; j<n; j++)
									if(soLan[i] < soLan[j]){
										MayBay tam1 = B[i];
										B[i] = B[j];
										B[j] = tam1;
										int tam2 = soLan[j];
										soLan[j] = soLan[i];
										soLan[i] = tam2;	
									}
                            int size1[1] = {30};
                            int size[3] = {15, 15};
                            TextColor(7);
                            KhungChu(xHoatDong-3, yHoatDong, size1, 2, 1, 1, 30, 7);
                            gotoXY(xHoatDong + 5, yHoatDong+1);
                            cout << "Thong ke may bay";
                            gotoXY(xHoatDong, yHoatDong+3);
                            cout << left << setw(15) << "So hieu" << setw(25) << "So lan bay";
							TextColor(7);                           
							for(int i=0; i<n; i++){
                                gotoXY(xHoatDong, yHoatDong+5 + 2*i);
                                cout << setw(18) << B[i].SoHieu << soLan[i];
                            }
                            KhungChu(xHoatDong-3, yHoatDong+2, size, 2, n+1, 2, 30, 7); 
                            gotoXY(xThongBao, yHoatDong + 6 + 2*n + 2); 
                            system("pause");
                            system("cls");
                            break;
                        }
					}
				Menu1(xTieuDe, yTieuDe+1, 3, 7);
				}while(k2 != -1);
				break;
			}
			case 4:{
				XuatFile(headChuyenBay);
				XuatFile(root);
				XuatFile(a, n);
				XuatDSVeFile(headChuyenBay);
				return 0;
			}
		}
	}
    return 0;
}

// giao dien

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
void KhungChu(int x, int y, int* a, int b, int m, int n, int size, int color) {
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

// menu
int Menu2(int x, int y, int d, int loai, int color) {
    vector<string> tieu_de;
    if (loai == 0) { // may bay
        tieu_de.push_back("Them may bay");
        tieu_de.push_back("Xoa may bay");
        tieu_de.push_back("Chinh thong tin may bay");
        tieu_de.push_back("Xuat thong tin may bay");
    }
    else if (loai == 1) { // chuyen bay
        tieu_de.push_back("Lap chuyen bay");
        tieu_de.push_back("Hieu chinh ngay gio");
        tieu_de.push_back("Huy chuyen");
    }
    else if (loai == 2) { // Khach
        tieu_de.push_back("Dat ve");
        tieu_de.push_back("Huy ve");
    }
    else if (loai == 3) { // thong ke
        tieu_de.push_back("Danh sach Khach");
        tieu_de.push_back("Danh sach chuyen bay theo ngay");
        tieu_de.push_back("Thong ke chuyen bay");
    }
	TextColor(color);
    for (int i = 0; i < tieu_de.size(); i++) {
        gotoXY(x, y + i);
        cout << tieu_de[i];
    }
    if (d == 0)
        return -1;
    char c;
    d = 0;
    TextColor(11);
    gotoXY(x, y + d);
    cout << tieu_de[d];
    while (1) {
        if (kbhit()) {
            c = getch();
            switch (c) {
            case 72: { // di len
                d--;
                if (d == -1)
                    d = tieu_de.size() - 1;
                break;
            }
            case 80: { // di xuong
                d++;
                if (d == tieu_de.size())
                    d = 0;
                break;
            }
            case 77: {
            	return d;
            }
            case 27:
            case 75: {
                return -1;
            }
            }
            TextColor(11);
            gotoXY(x, y + d);
            cout << tieu_de[d];
            TextColor(color);
            for (int i = 0; i < tieu_de.size(); i++)
                if (i != d) {
                    gotoXY(x, y + i);
                    cout << tieu_de[i];
                }
        }
    }
}
int Menu1(int x, int y, int d,  int color) {
	system("cls");
	TextColor(7);
	Ox(30, 100, 34);
	Ox(30, 100, 36);
	TextColor(14);
	gotoXY(40, 35);
	cout << "<: quay ve, >: chon, ^: len, v: xuong, -1: thoat";
    int size[] = {20, 40};
    TextColor(7);
    KhungChu(x-3, y-1, size, 6, 1, 2, 60, 7);
    TextColor(color);
    string tieu_de[] = { "May bay", "Chuyen bay", "Khach", "Khac", "Luu" };
    for (int i = 0; i < 5; i++) {
        gotoXY(x, y + i);
        cout << tieu_de[i];
    }
    if(d != -1){
    	TextColor(11);
	    gotoXY(x, y + d);
	    cout << tieu_de[d];
    	return 0;
	}
    char c;
    d = 0;
    TextColor(11);
	    gotoXY(x, y + d);
	    cout << tieu_de[d];
    while (1) {
        if (kbhit()) {
            c = getch();
            Menu2(x + 20, y, 0, d, 0);
            switch (c) {
            case 72: { // di len
                d--;
                if (d == -1)
                    d = 4;
                break;
            }
            case 80: { // di xuong
                d++;
                if (d == 5)
                    d = 0;
                break;
            }
            case 77: { // di sang phai
            	return d;
            }
            }
            TextColor(11);
            gotoXY(x, y + d);
            cout << tieu_de[d];
            TextColor(color);
            for (int i = 0; i < 5; i++)
                if (i != d) {
                    gotoXY(x, y + i);
                    cout << tieu_de[i];
                }
            Menu2(x + 20, y, 0, d, 7);
        }
    }
}
void ChuanHoaChuoi(string &s){
	while(s[0] == 32)
		s.erase(0, 1);
	while(s.find("  ") != -1)
		s.erase(s.find("  "), 1);
	while(s[s.size() - 1] == 32)
		s.erase(s.size() - 1, 1);
}
void ChuanHoaNgay(string &s){
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
void ChuanHoaGio(string &s){
	string s1;
	if(s.size() == 1){
		s = "0" + s + ":00";
		return;
	}else if(s.size() == 2){
		s = s + ":00";
		return;
	}
	s1 = s.substr(0, s.find(":"));
	s.erase(0, s.find(":") + 1);
	if(s1.size() == 1)
		s1 = "0" + s1;
	if(s.size() == 1)
		s = s1 + ":0" + s;
	else
		s = s1 + ":" + s;
}
int SoSanhNgay(string d1, string d2){
	if(d1 == d2)
		return 0;
	int s1 = 365*StringSangIn(d1.substr(6)) + 31*StringSangIn(d1.substr(3, 2)) + StringSangIn(d1.substr(0, 2));
	int s2 = 365*StringSangIn(d2.substr(6)) + 31*StringSangIn(d2.substr(3, 2)) + StringSangIn(d2.substr(0, 2));
	return s1 - s2;
}
int StringSangIn(string s) {
	int kq = 0;
	for (int i = 0; i < s.size(); i++)
		kq = kq * 10 + s[i] - 48;
	return kq;
}
char* StringSangChar(string s) {
	char* kq = new char[s.size() + 1];
	for (int i = 0; i < s.size(); i++)
		kq[i] = int(s[i]);
	return kq;
}
string InSangString(int x) {
	string kq = "";
	string s = "0";
	while (x != 0) {
		s[0] = x % 10 + 48;
		kq = s + kq;
		x /= 10;
	}
	return kq;
}
bool KiemTraNgay(int day, int month, int year){
	if (month < 1 || month > 12 || day < 1) {
                return false;
            }
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day > 31)
			{
				return false;
			}
			break;
		case 2:
			{
				if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
					if(day > 29)
					{
					return false;
					}
				}
				else
				{
					if(day > 28)
					{
					return false;
					}
				}
				break;
			}
		default:
			{
				if(day > 30)
				{
				return false;
				}
				break;
			}
	}
	return true;
}
bool KiemTra(string &s, int loai, int len) { // 0: Sá»‘, 1: chuá»—i, 2: ngÃ y, 3: gio
	if(s == "")
		return false;
	if (loai == 0)
		for (int i = 0; i < s.size(); i++)
			if (s[i] < '0' || s[i] > '9')
				return false;

	if (loai == 1)
		if (s.size() > len)
			return false;
		else{
			for (int i = 0; i < s.size(); i++)
				if (!((s[i] >= 'a' && s[i] <= 'z')
					|| (s[i] >= 'A' && s[i] <= 'Z')
					|| (s[i] >= '0' && s[i] <= '9') || s[i] == 32))
					return false;
		}

	if (loai == 2) {
		ChuanHoaNgay(s);
		if(s.size() != 10)
			return false;
		string tam = s;
		for (int i = 0; i < s.size(); i++)
			if (!(s[i] >= '0' && s[i] <= '9' || s[i] == '/'))
				return false;
		string ngay = s.substr(0, s.find("/"));
		s.erase(0, s.find("/") + 1);
		string thang = s.substr(0, s.find("/"));
		s.erase(0, s.find("/") + 1);
		if(KiemTraNgay(StringSangIn(ngay), StringSangIn(thang), StringSangIn(s)) == false)
			return false;
		s = tam;
	}
	if (loai == 3) {
		ChuanHoaGio(s);
		string tam = s;
		if (s.size() != 5)
			return false;
		for (int i = 0; i < s.size(); i++)
			if (!(s[i] >= '0' && s[i] <= '9' || s[i] == ':'))
				return false;
		string gio = s.substr(0, s.find(":"));
		if (gio > "23")
			return false;
		s.erase(0, s.find(":") + 1);
		if (s > "59")
			return false;
		s = tam;
	}
	if(loai == 4){
		ChuanHoaChuoi(s);
		if(s[0] >= 'a' && s[0] <= 'z')
			s[0] -= 32;
		for(int i=1; i<s.size(); i++)
			if(s[i] >= 'a' && s[i] <= 'z' && s[i-1] == 32)
				s[i] -= 32;
			else if(s[i] >= 'A' && s[i] <= 'Z' && s[i-1] != 32)
				s[i] += 32;
			else if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == 32))
				return false;
	}
	return true;
}
bool KiemTra(char* a, int loai, int len) { // 0: Sá»‘, 1: chuá»—i, 2: ngÃ y, 3: gio
	string s = "";
	for(int i=0; i<strlen(a); i++)
		s.push_back(a[i]);
	if(s == "")
		return false;
	if (loai == 0)
		for (int i = 0; i < s.size(); i++)
			if (s[i] < '0' || s[i] > '9')
				return false;

	if (loai == 1)
		if (s.size() > len)
			return false;
		else{
			for (int i = 0; i < s.size(); i++)
				if (!((s[i] >= 'a' && s[i] <= 'z')
					|| (s[i] >= 'A' && s[i] <= 'Z')
					|| (s[i] >= '0' && s[i] <= '9') || s[i] == 32))
					return false;
		}

	if (loai == 2) {
		ChuanHoaNgay(s);
		if(s.size() != 10)
			return false;
		string tam = s;
		for (int i = 0; i < s.size(); i++)
			if (!(s[i] >= '0' && s[i] <= '9' || s[i] == '/'))
				return false;
		string ngay = s.substr(0, s.find("/"));
		s.erase(0, s.find("/") + 1);
		string thang = s.substr(0, s.find("/"));
		s.erase(0, s.find("/") + 1);
		if(KiemTraNgay(StringSangIn(ngay), StringSangIn(thang), StringSangIn(s)) == false)
			return false;
		s = tam;
	}
	if (loai == 3) {
		ChuanHoaGio(s);
		if (s.size() != 5)
			return false;
		for (int i = 0; i < s.size(); i++)
			if (!(s[i] >= '0' && s[i] <= '9' || s[i] == ':'))
				return false;
		string gio = s.substr(0, s.find(":"));
		if (gio > "23")
			return false;
		s.erase(0, s.find(":") + 1);
		if (s > "59")
			return false;
	}
	if(loai == 4){
		ChuanHoaChuoi(s);
		if(s[0] >= 'a' && s[0] <= 'z')
			s[0] -= 32;
		for(int i=1; i<s.size(); i++)
			if(s[i] >= 'a' && s[i] <= 'z' && s[i-1] == 32)
				s[i] -= 32;
			else if(s[i] >= 'A' && s[i] <= 'Z' && s[i-1] != 32)
				s[i] += 32;
			else if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == 32))
				return false;
	}
	for(int i=0; i<s.size(); i++)
		a[i] = s[i];
	return true;
}
bool Nhap(MayBay& x) {
	string s;
    int size[2] = {60};
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 60, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
	cout << "Nhap thong tin may bay";
    size[0] = 20, size[1] = 40;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 4, 2, 60, 7);
	TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << "Nhap so hieu: ";
    gotoXY(xHoatDong, yHoatDong + 4);  cout << "Nhap loai: ";
    gotoXY(xHoatDong, yHoatDong + 6);  cout << "Nhap so day: ";
    gotoXY(xHoatDong, yHoatDong + 8);  cout << "Nhap so hang: ";
    fflush(stdin);
    while(1){
    	gotoXY(xHoatDong + 25, yHoatDong + 2); cout << "                ";
	    TextColor(7);
	    gotoXY(xHoatDong + 25, yHoatDong + 2);
	    getline(cin, s);
        if(s.find("-1") != -1)
        return false;
		if (KiemTra(s, 1, 15) == false) {
	        gotoXY(xThongBao, yThongBao);
			TextColor(4);   
			cout << "Ma so hieu khong hop le!";
			getch();
			gotoXY(xThongBao, yThongBao);
			cout << "                        ";
		}else{
			strcpy(x.SoHieu, (char*)s.c_str());
			break;
		}
	}
	while(1){
		gotoXY(xHoatDong + 25, yHoatDong + 4); cout << "          ";
		gotoXY(xHoatDong + 25, yHoatDong + 4);
	    getline(cin, s);
        if(s.find("-1") != -1)
        return false;
		if (KiemTra(s, 1, 40) == false) {
	        gotoXY(xThongBao, yThongBao); 
			TextColor(4);  
			cout << "Loai khong hop le!";
			getch();
			gotoXY(xThongBao, yThongBao); 
			TextColor(7);  
			cout << "                  ";
		}else
			break;
	}
	strcpy(x.Loai, (char*)s.c_str());
	while(1){
		gotoXY(xHoatDong + 25, yHoatDong + 6); cout << "        ";
		gotoXY(xHoatDong + 25, yHoatDong + 6);
	    getline(cin, s);
        if(s.find("-1") != -1)
        return false;
		if (KiemTra(s, 0, 0) == false) {
			SAI1:
	        gotoXY(xThongBao, yThongBao); 
			TextColor(4);  
			cout << "So day khong hop le!";
			getch();
			gotoXY(xThongBao, yThongBao); 
			TextColor(7);  
			cout << "                     ";
		}else
			break;
	}
	x.SoDay = StringSangIn(s);
	if(x.SoDay > 5)
		goto SAI1;
	Lap1:
    gotoXY(xHoatDong + 25, yHoatDong + 8);
    getline(cin, s);
        if(s.find("-1") != -1)
        return false;
	if (KiemTra(s, 0, 0) == false) {
		SAI2:
        gotoXY(xThongBao, yThongBao);  
		TextColor(4); 
		cout << "So hang khong hop le!";
		getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
		goto Lap1;
	}
	x.SoHang = StringSangIn(s);
	if(x.SoHang > 30)
		goto SAI2;
	return true;
}
void Xuat(MayBay x) {
    int size[2] = {60};
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 60, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
	cout << "Thong tin may bay:";
    size[0] = 20, size[1] = 40;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 4, 2, 60, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << left << setw(25) << "So hieu: " << x.SoHieu;
    gotoXY(xHoatDong, yHoatDong + 4);  cout << left << setw(25) <<"Loai: " << x.Loai;
    gotoXY(xHoatDong, yHoatDong + 6);  cout << left << setw(25) <<"So day: " << x.SoDay;
    gotoXY(xHoatDong, yHoatDong + 8);  cout << left << setw(25) <<"So hang: " << x.SoHang;
}
bool CapNhat(MayBay& a) {
    int size[2] = {60};
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 60, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
	cout << "Cap nhat thong tin may bay";
    size[0] = 20, size[1] = 40;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 3, 2, 60, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << "Loai: ";
    gotoXY(xHoatDong, yHoatDong + 4);  cout << "So day: ";
    gotoXY(xHoatDong, yHoatDong + 6);  cout << "So hang: ";

	MayBay x;
    strcpy(x.SoHieu, a.SoHieu);
	string s;TextColor(7);
	Lap1:
    gotoXY(xHoatDong + 25, yHoatDong + 2);  fflush(stdin); getline(cin, s);
        if(s.find("-1") != -1)
        return false;
	if (KiemTra(s, 1, 40) == false) {
        gotoXY(xThongBao, yThongBao);   
        TextColor(4);
		cout << "Loai khong hop le!";
		getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 2);
        cout << "              ";
        goto Lap1;
	}
	strcpy(x.Loai, (char*)s.c_str());
	Lap2:
	gotoXY(xHoatDong + 25, yHoatDong + 4); 
    getline(cin, s);
        if(s.find("-1") != -1)
        return false;
	if (KiemTra(s, 0, 0) == false) {
        Sai1:
        gotoXY(xThongBao, yThongBao);   
        TextColor(4);
		cout << "So day khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 4);
        cout << "           ";
        goto Lap2;
	}
	x.SoDay = StringSangIn(s);
    if(x.SoDay > 5)
        goto Sai1;
	Lap3:
	gotoXY(xHoatDong + 25, yHoatDong + 6); 
    getline(cin, s);
        if(s.find("-1") != -1)
        return false;
	if (KiemTra(s, 0, 0) == false) {
        Sai2:
        gotoXY(xThongBao, yThongBao);   
        TextColor(4);
		cout << "So hang khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 6);
        cout << "      ";
        goto Lap3;
	}
	x.SoHang = StringSangIn(s);
    if(x.SoHang > 30)
        goto Sai2;
	a = x;
	return true;
}
void NhapFile(MayBay* a[300], int& n) {
	ifstream cin("./inputMayBay.txt");
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = new MayBay;
		cin >> a[i]->SoHieu;
		cin.ignore();
		cin.getline(a[i]->Loai, 50);
		cin >> a[i]->SoDay >> a[i]->SoHang;
	}
}
void XuatFile(MayBay* a[300], int& n) {
	ofstream cout("./inputMayBay.txt");
	cout << n;
	for (int i = 0; i < n; i++) {
		cout << a[i]->SoHieu << endl;
		cout << a[i]->Loai << endl;
		cout << a[i]->SoDay << endl;
		cout << a[i]->SoHang << endl;
	}
}
void DSSoHieu(MayBay* a[300], int n, int x, int y){
	int size[2] = {24};
    TextColor(7);
    KhungChu(x - 3, y-1, size, 2, 1, 1, 24, 7);
    gotoXY(x + 7, y);
    TextColor(11);
    cout << "So hieu";
	size[0] = 12, size[1] = 12;
    TextColor(7);
    for(int i=0; i<n; i++){
    	gotoXY(x + 2 + 12*(i%2), y + 2 + 2*(i/2));
    	cout << a[i]->SoHieu;
    	KhungChu(x-3, y + 1 + 2*(i/2), size, 2, 1, 1, 24, 7);
	}
}
int TimKiem(MayBay* a[300], int n, char* SoHieu) {
	for (int i = 0; i < n; i++)
		if (strcmp(a[i]->SoHieu, SoHieu) == 0)
			return i;
	return -1;
}
bool Xoa(MayBay* a[300], int& n, LChuyenBay* head) {
    int size[2] = {60};
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 60, 7);
    gotoXY(xHoatDong + 15, yHoatDong);
    TextColor(11);
    cout << "Xoa may bay";
    size[0] = 20, size[1] = 40;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 1, 2, 60, 7);
    gotoXY(xHoatDong, yHoatDong + 2); TextColor(11); cout << "So hieu: ";
	string s;TextColor(7);
	Lap1:
	gotoXY(xHoatDong + 25, yHoatDong + 2);  fflush(stdin); getline(cin, s);
    if(s.find("-1") != -1)
        return false;
	if (KiemTra(s, 1, 15) == false) {
        gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "Ma so hieu khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                         ";
        gotoXY(xHoatDong + 25, yHoatDong + 2);
        cout << "      ";
        goto Lap1;
	}
	int index = TimKiem(a, n, (char*)s.c_str());
	if (index == -1) {
        gotoXY(xThongBao, yThongBao);   
        TextColor(4);
		cout << "Khong co so hieu phu hop!";
		return false;
	}
	for(LChuyenBay* i=head; i!= NULL; i=i->next){
		if(strcmp(i->data.SoHieu, a[index]->SoHieu) == 0){
			gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "May bay dang co chuyen bay hoat dong!";
		return false;
		}
			
	}
	Lap2:
	gotoXY(xThongBao, yThongBao);   
    TextColor(11);
	cout << "Ban co chac muon huy chuyen(y/n)?"; TextColor(7);cin >> s;
	if(!(s == "n" || s == "N" || s == "y" || s == "Y")){
		gotoXY(xThongBao, yThongBao);   
		TextColor(11);
		cout << "Lua chon khong hop le!                ";
		goto Lap2;
	}
	if ((s == "n" || s == "N"))
		return false;
	for (int i = index; i < n - 1; i++)
		*a[i] = *a[i + 1];
	n--;
	delete a[n];
	return true;
}
bool Them(MayBay* a[300], int& n) {
	MayBay x;
	if (Nhap(x) == false)
		return false;
	int index = TimKiem(a, n, x.SoHieu);
	if (index != -1) { // da co trong danh sach
        gotoXY(xThongBao, yThongBao);
		TextColor(4);  
		cout << "So hieu da co trong danh sach!";
		return false;
	}
	a[n] = new MayBay;
	*a[n] = x;
	n++;
	return true;
}
bool CapNhat(MayBay* a[300], int n, LChuyenBay* head) {
	string s;
    gotoXY(xHoatDong, yHoatDong - 2);  
    TextColor(11);
    Lap:
	cout << "Nhap so hieu: ";TextColor(7); cin >> s;
	if (KiemTra(s, 1, 15) == false) {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Ma so hieu khong hop le!";
		getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                         ";
        gotoXY(xHoatDong + 14, yHoatDong - 2);
        cout << "               ";
        goto Lap;
	}
	int index = TimKiem(a, n, (char*)s.c_str());
	if (index == -1) {
        gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "Khong co so hieu phu hop!";
		return false;
	}
	for(LChuyenBay* i=head; i!= NULL; i=i->next){
		if(strcmp(i->data.SoHieu, a[index]->SoHieu) == 0){
			gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "May bay dang co chuyen bay hoat dong!";
		return false;
		}
			
	}
	return CapNhat(*a[index]);
}
void Xuat(MayBay* a[300], int n){
	for(int i=0; i<n; i++){
		Xuat(*a[i]);
	}
}

// khach

bool Nhap(Khach& x) {
	system("cls");
    int size[2] = {50};
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 50, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
    cout << "Nhap thong tin khach";
    size[0] = 15, size[1] = 35;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 4, 2, 50, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << "Nhap cccd: ";
    gotoXY(xHoatDong, yHoatDong + 4);  cout << "Nhap ho: ";
    gotoXY(xHoatDong, yHoatDong + 6);  cout << "Nhap ten: ";
    gotoXY(xHoatDong, yHoatDong + 8);  cout << "Nhap phai: ";
	string s;
	Lap1:
	gotoXY(xHoatDong + 23, yHoatDong + 2); TextColor(7);  cin >> s;
     if(s.find(-1) != -1)
        return false;
	if (s.size() != 12 || KiemTra(s, 0, 12) == false) {
        gotoXY(xThongBao, yThongBao);   
        TextColor(4);
		cout << "cccd khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 2);
        cout << "               ";
        goto Lap1;
	}
	strcpy(x.cccd, (char*)s.c_str());
	Lap2:
	gotoXY(xHoatDong + 20, yHoatDong + 4); cin.ignore(); getline(cin, s);
     if(s.find(-1) != -1)
        return false;
	if (KiemTra(s, 4, 20) == false) {
        gotoXY(xThongBao, yThongBao);  
		TextColor(4); 
		cout << "Ho khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 4);
        cout << "             ";
        goto Lap2;
	}
	strcpy(x.Ho, (char*)s.c_str());
	Lap3:
	gotoXY(xHoatDong + 20, yHoatDong + 6); getline(cin, s);
     if(s.find(-1) != -1)
        return false;
	if (KiemTra(s, 4, 20) == false) {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Ten khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 8);
        cout << "            ";
        goto Lap3;
	}
	strcpy(x.Ten, (char*)s.c_str());
	Lap4:
	gotoXY(xHoatDong + 20, yHoatDong + 8); cin >> s;
     if(s.find(-1) != -1)
        return false;
	if (s != "Nam" && s != "Nu") {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Phai khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 8);
        cout << "             ";
        goto Lap4;
	}
	strcpy(x.Phai, (char*)s.c_str());
	return true;
}
bool Nhap(Khach& x, string ma) {
	system("cls");
    int size[2] = {50};
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 50, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
    cout << "Nhap thong tin khach";
    size[0] = 15, size[1] = 35;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 4, 2, 50, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << "Nhap cccd:  "; TextColor(7); cout << "| " << ma;
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 4);  cout << "Nhap ho: ";
    gotoXY(xHoatDong, yHoatDong + 6);  cout << "Nhap ten: ";
    gotoXY(xHoatDong, yHoatDong + 8);  cout << "Nhap phai: ";
	string s;
	strcpy(x.cccd, (char*)ma.c_str());
	TextColor(7);
	Lap2:
	gotoXY(xHoatDong + 20, yHoatDong + 4); fflush(stdin); getline(cin, s);
     if(s.find(-1) != -1)
        return false;
	if (KiemTra(s, 4, 20) == false) {
        gotoXY(xThongBao, yThongBao);  
		TextColor(4); 
		cout << "Ho khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 4);
        cout << "             ";
        goto Lap2;
	}
	strcpy(x.Ho, (char*)s.c_str());
	Lap3:
	gotoXY(xHoatDong + 20, yHoatDong + 6); getline(cin, s);
     if(s.find(-1) != -1)
        return false;
	if (KiemTra(s, 4, 20) == false) {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Ten khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 8);
        cout << "            ";
        goto Lap3;
	}
	strcpy(x.Ten, (char*)s.c_str());
	Lap4:
	gotoXY(xHoatDong + 20, yHoatDong + 8); cin >> s;
	if (s != "Nam" && s != "Nu") {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Phai khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 8);
        cout << "             ";
        goto Lap4;
	}
	strcpy(x.Phai, (char*)s.c_str());
	return true;
}
bool CapNhat(Khach& a){
    int size[2] = {50};
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 50, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
    cout << "Cap nhat thong tin khach";
    size[0] = 15, size[1] = 35;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 3, 2, 50, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  	cout << "Ho: ";
    gotoXY(xHoatDong, yHoatDong + 4);  	cout << "Ten: ";
    gotoXY(xHoatDong, yHoatDong + 6); 	cout << "Phai: ";
	Khach x = a;
	string s;TextColor(7);
	Lap1:
    gotoXY(xHoatDong + 20, yHoatDong + 2); fflush(stdin); getline(cin, s);
    if(s.find(-1) != -1)
        return false;
	if (KiemTra(s, 4, 20) == false) {
        gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "Ho khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 2);
        cout << "             ";
        goto Lap1;
	}
	strcpy(x.Ho, (char*)s.c_str());
	Lap2:
    gotoXY(xHoatDong + 20, yHoatDong + 4); getline(cin, s);
     if(s.find(-1) != -1)
        return false;
	if (KiemTra(s, 4, 20) == false) {
        gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "Ten khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 4);
        cout << "             ";
        goto Lap2;
	}
	strcpy(x.Ten, (char*)s.c_str());
	Lap3:
    gotoXY(xHoatDong + 20, yHoatDong + 6); cin >> s;
	if (KiemTra(s, 1, 10) == false) {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Phai khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 6);
        cout << "             ";
        goto Lap3;
	}
	strcpy(x.Phai, (char*)s.c_str());
	a = x;
	return true;
}
void Xuat(Khach x) {
    int size[2] = {50};
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 50, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
	cout << "Thong tin khach                ";
    size[0] = 15, size[1] = 35;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 4, 2, 50, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << left << setw(25) << "cccd: " << x.cccd;
    gotoXY(xHoatDong, yHoatDong + 4);  cout << left << setw(25) << "Ho: " << x.Ho;
    gotoXY(xHoatDong, yHoatDong + 6);  cout << left << setw(25) << "Ten: " << x.Ten;
    gotoXY(xHoatDong, yHoatDong + 8);  cout << left << setw(25) << "Phai: " << x.Phai;
}
Tree* TimKiem(Tree* root, char* cccd){
	if(root == NULL)
		return NULL;
	if(strcmp(root->data.cccd, cccd) > 0)
		return TimKiem(root->left, cccd);
	if(strcmp(root->data.cccd, cccd) < 0)
		return TimKiem(root->right, cccd);
	return root;
}
bool Them(Tree* &root, Khach x){
	if(root == NULL){
		root = new Tree;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
		return true;
	}else{
		if(strcmp(root->data.cccd, x.cccd) > 0)
			return Them(root->left, x);
		if(strcmp(root->data.cccd, x.cccd) < 0)
			return Them(root->right, x);
		return false;
	}
}
void NhapFile(Tree*& root){
	root = NULL;
	ifstream cin("./khach.txt");
	while(1){
		Khach x;
		if(!(cin >> x.cccd))
			return;
		cin.ignore();
		cin.getline(x.Ho, 20);
		cin.getline(x.Ten, 20);
		cin >> x.Phai;
		Them(root, x);
	}
	cin.close();
}
void XuatFile(Tree* root){
	ofstream cout("./khach.txt");
	queue<Tree*> a;
	a.push(root);
	while(!a.empty()){
		Tree* x = a.front();
		cout << x->data.cccd << endl;
		cout << x->data.Ho << endl;
		cout << x->data.Ten << endl;
		cout << x->data.Phai << endl;
		if(x->left != NULL)
			a.push(x->left);
		if(x->right != NULL)
			a.push(x->right);
		a.pop();
	}
	cout.close();
}
bool CapNhat(Tree* root, char* cccd){
	Tree* p = TimKiem(root, cccd);
	if(p == NULL){
        gotoXY(xThongBao, yThongBao); 
        TextColor(4);
		cout << "Khong co!";
		return false;
	}
	return CapNhat(p->data);
}
void TanCungTrai(Tree*& root, Tree* &nhanh){
	if(nhanh->left == NULL){
		root->data = nhanh->data;
		nhanh = nhanh->right;
	}else
		TanCungTrai(root, nhanh->left);
}
bool Xoa(Tree* &root, char* cccd){
	if(root != NULL){
		if(strcmp(root->data.cccd, cccd) == 0){
			if(root->left == NULL){
				root = root->right;
			}else if(root->right == NULL){
				root = root->left;
			}else{
				TanCungTrai(root, root->right);
			}
			return true;
		}else if(strcmp(root->data.cccd, cccd) > 0){
			return Xoa(root->left, cccd);
		}else 
			return Xoa(root->right, cccd);	
	}
	return false;
}
// ve
void Xuat(Ve x) {
	cout << x.Ma << " " << x.cccd;
}
void Them(LVe*& head, Ve x){
	if(head == NULL){
		head = new LVe;
		head->data = x;
		head->next = NULL;
	}else
		Them(head->next, x);
}
void Xuat(LVe* head){
	for(LVe*i = head; i != NULL; i=i->next)
		Xuat(i->data);
}
LVe* TimKiem(LVe* head, char* ma){
	for(LVe* i =head; i!= NULL; i = i->next)
		if(strcmp(i->data.Ma, ma) == 0)
			return i;
	return NULL;
}
bool Nhap(ChuyenBay& x, string ngay, string gio) {
    int size[2] = {45, 30};
	size[0] = 70;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 70, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
    cout << "Nhap thong tin chuyen bay";
    size[0] = 30, size[1] = 40;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 5, 2, 70, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << "Ma: ";
    gotoXY(xHoatDong, yHoatDong + 4);  cout << "Ngay khoi hanh(dd/mm/yyyy):";
    gotoXY(xHoatDong, yHoatDong + 6);  cout << "Gio bay(hh:mm): ";
    gotoXY(xHoatDong, yHoatDong + 8);  cout << "Dich den: ";
    gotoXY(xHoatDong, yHoatDong + 10);  cout << "So hieu: ";
	string s;
    int dong = 1;TextColor(7);
    Lap1:
	gotoXY(xHoatDong + 30, yHoatDong + 2*dong++); fflush(stdin);  getline(cin, s);
	if(s.find("-1") != -1)
		return false;
	if (KiemTra(s, 1, 15) == false) {
        gotoXY(xThongBao, yThongBao); 
        TextColor(4);
		cout << "Ma khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 30, yHoatDong + 2*(--dong));
        cout << "              ";
        goto Lap1;
	}
	strcpy(x.Ma, (char*)s.c_str());
	Lap2:
	gotoXY(xHoatDong + 30, yHoatDong + 2*dong++); getline(cin, s);
	if(s.find("-1") != -1)
		return false;
	if (KiemTra(s, 2, 11) == false || SoSanhNgay(s, ngay) < 1 || SoSanhNgay(s, ngay) > 365) {
        gotoXY(xThongBao, yThongBao); 
        TextColor(4);
		cout << "Ngay khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 30, yHoatDong + 2*(--dong));
        cout << "             ";
        goto Lap2;
	}
	strcpy(x.Ngay, (char*)s.c_str());
	LapGio:
	gotoXY(xHoatDong + 30, yHoatDong + 2*dong++); getline(cin, s);
	if(s.find("-1") != -1)
		return false;
	if(KiemTra(s, 3, 1) == false || (x.Ngay == ngay && s < gio)){
		gotoXY(xThongBao, yThongBao); 
        TextColor(4);
		cout << "Gio khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 30, yHoatDong + 2*(--dong));
        cout << "             ";
        goto LapGio;
	}
	strcpy(x.Gio, (char*) s.c_str());
	Lap3:
	gotoXY(xHoatDong + 30, yHoatDong + 2*dong++); getline(cin, s);
	if(s.find("-1") != -1)
		return false;
	if (KiemTra(s, 1, 40) == false) {
        gotoXY(xThongBao, yThongBao); 
        TextColor(4);
		cout << "Dich den khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                       ";
        gotoXY(xHoatDong + 30, yHoatDong + 2*(--dong));
        cout << "             ";
        goto Lap3;
	}
	strcpy(x.Dich, (char*)s.c_str());
	x.TrangThai = 1;
	Lap5:
	gotoXY(xHoatDong + 30, yHoatDong + 2*dong++); getline(cin, s);
	if(s.find("-1") != -1)
		return false;
	if (KiemTra(s, 1, 16) == false) {
        gotoXY(xThongBao, yThongBao); 
        TextColor(4);
		cout << "So hieu khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 30, yHoatDong + 2*(--dong));
        cout << "           ";
        goto Lap5;
	}
	strcpy(x.SoHieu, (char*)s.c_str());
	return true;
}
void Xuat(ChuyenBay x) {
    int size[2] = {60};
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 60, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
	cout << "Thong tin chuyen bay";
    size[0] = 20, size[1] = 40;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 6, 2, 60, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << left << setw(25) <<  "Ma: " << x.Ma;
    gotoXY(xHoatDong, yHoatDong + 4);  cout << left << setw(25) <<  "Ngay khoi hanh: " << x.Ngay;
    gotoXY(xHoatDong, yHoatDong + 6);  cout << left << setw(25) <<  "Gio bat dau: " << x.Gio;
    gotoXY(xHoatDong, yHoatDong + 8);  cout << left << setw(25) << "Dich den: " << x.Dich;
    gotoXY(xHoatDong, yHoatDong + 10); cout << left << setw(25) << "Trang thai: ";
	
	switch (x.TrangThai) {
		case 0: {
			cout << "Huy chuyen";
			break;
		}
		case 1: {
			cout << "Con ve";
			break;
		}
		case 2: {
			cout << "Het ve";
			break;
		}
		case 3: {
			cout << "Hoan tat";
		}
	}
    gotoXY(xHoatDong, yHoatDong + 12); cout << left << setw(25) <<"So hieu: " << x.SoHieu;
	XuatDSVe(x, xHoatDong + 60, yHoatDong + 4);
}

void KhoiTaoVe(LVe*& head, MayBay* a[300], int x) {
	head = NULL;
	for (int i = 0; i < a[x]->SoDay; i++)
		for (int j = 1; j <= a[x]->SoHang; j++) {
			Ve t;
			t.Ma[0] = i + 'A';
			t.Ma[1] = '\0';
			strcat(t.Ma, (char*)InSangString(j).c_str());
			t.Ma[strlen(t.Ma)] = '\0';
			strcpy(t.cccd, " ");
			Them(head, t);	
		}
}
void Them(LChuyenBay*& head, ChuyenBay x){
	if(head == NULL){
		head = new LChuyenBay;
		head->data = x;
		head->next = NULL;
	}else{
		if(strcmp(head->data.Ma, x.Ma) == 0){
			gotoXY(xThongBao, yThongBao);
			TextColor(4);
			cout << "Ma da co trong danh sach!";
		}else
			Them(head->next, x);
	}
}
void XuatMaCB(LChuyenBay* head, int x, int y){
	int size[2] = {24};
    TextColor(7);
    KhungChu(x - 3, y-1, size, 2, 1, 1, 24, 7);
    gotoXY(x + 6, y);
    TextColor(11);
    cout << "Ma chuyen";
    TextColor(7);
	size[0] = 12, size[1] = 12;
	int j = 0;
    for(LChuyenBay* i = head; i!= NULL; i=i->next){
    	gotoXY(x + 2 + 12*(j%2), y + 2 + 2*(j/2));
    	cout << i->data.Ma;
    	KhungChu(x-3, y + 1 + 2*(j/2), size, 2, 2, 2, 24, 7);
		j++;
	}
}
void NhapFile(LChuyenBay* &head, MayBay* a[300], int n) {
	ifstream cin("./chuyenBay.txt");
	int m;
	cin >> m;
	head = NULL;
	for (int i = 0; i < m; i++) {
		ChuyenBay x;
		cin >> x.Ma >> x.Ngay >> x.Gio;
		cin.ignore();
		cin.getline(x.Dich, 40);
		cin >> x.TrangThai >> x.SoHieu;
		int index = TimKiem(a, n, x.SoHieu);
		KhoiTaoVe(x.head, a, index);
		Them(head, x);
	}
	cin.close();
}
void XuatFile(LChuyenBay* head){
	int m = 0;
	for(LChuyenBay*i = head; i != NULL; i=i->next)
		m++;
	ofstream cout("./ChuyenBay.txt");
	cout << m << endl;
	for(LChuyenBay*i = head; i != NULL; i=i->next){
		cout << i->data.Ma << endl;
		cout << i->data.Ngay<< endl;
		cout << i->data.Gio<< endl;
		cout << i->data.Dich<< endl;
		cout << i->data.TrangThai<< endl;
		cout << i->data.SoHieu<< endl;
	}
	cout.close();
}
bool Them(LChuyenBay*& head, MayBay* a[300], int n, string ngay, string gio) {
	ChuyenBay x;
	if (Nhap(x, ngay, gio) == false)
		return false;
	if(TimKiem(head, x.Ma) != NULL){
		gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "Ma chuyen bay da co trong danh sach!";
		return false;
	}
	int index = TimKiem(a, n, x.SoHieu);
	if (index == -1) {
        gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "So hieu khong co trong danh sach!";
		return false;
	}
	KhoiTaoVe(x.head, a, index);
	Them(head, x);
	gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "Nhap thanh cong!";
	return true;
}
LChuyenBay* TimKiem(LChuyenBay* head, char* ma){
	for(LChuyenBay* i =head; i!= NULL; i = i->next)
		if(strcmp(i->data.Ma, ma) == 0)
			return i;
	return NULL;	
}
//
void NhapDSVeFile(LChuyenBay* head) {
	ifstream cin("./DSVe.txt");
	char machuyen[16];
	while(1){
		if(!(cin >> machuyen))
			return;
		LChuyenBay* p1 = TimKiem(head, machuyen);
		char mave[20], cccd[13];
		cin >> mave;
		while(strcmp(mave, "#") != 0){
			cin >> cccd;
			LVe *p2 = TimKiem(p1->data.head, mave);
			strcpy(p2->data.cccd, cccd);
			cin >> mave;
		}
	}
	cin.close();
}
void XuatDSVeFile(LChuyenBay* head){
	ofstream cout("./DSVe.txt");
	for(LChuyenBay* i =head; i!= NULL; i=i->next){
				int dem = 0;
		for(LVe* j =i->data.head; j!= NULL; j=j->next)
			if(strlen(j->data.cccd) == 12)
				dem++;
		if(dem == 0)
			continue;
		cout << i->data.Ma << endl;
		for(LVe* j =i->data.head; j!= NULL; j=j->next)
			if(strlen(j->data.cccd) == 12)
			cout << j->data.Ma << " " << j->data.cccd << endl;
		cout << "#\n";
	}
	cout.close();
}
void XuatDSVe(ChuyenBay a, int x, int y){
	int size[1] = {10};
	TextColor(7);
	KhungChu(x - 3, y - 5, size, 2, 1, 1, 10, 7);
	TextColor(11);
	gotoXY(x, y - 4); cout << "Ma";
	int dong = 0, cot = 0;
	for(LVe* i = a.head; i != NULL; i = i->next){
		KhungChu(x - 3 + cot, y - 3 + 2*dong, size, 2, 1, 1, 10, 7);
		if(strlen(i->data.cccd) == 12){
			TextColor(14);
		}else
			TextColor(7);
		gotoXY(x + cot, y - 2 + 2*dong); cout << i->data.Ma;
		dong++;
		if(i->next != NULL && i->data.Ma[0] != i->next->data.Ma[0]){
		//if(dong == 10){
			cot += 10;
			dong = 0;
			KhungChu(x - 3 + cot, y - 5, size, 2, 1, 1, 10, 7);
			TextColor(11);
			gotoXY(x + cot, y - 4); cout << "Ma";
			TextColor(7);
		}
	}
}
bool CapNhat(LChuyenBay* head, string ngay, string gio) {
	gotoXY(xThongBao, yThongBao);
	TextColor(4); 
	switch(head->data.TrangThai){
		case 0:{
			cout << "Chuyen bay da co bi huy khong hieu chinh duoc!";
			return false;
		}
		case 3:{
			cout << "Chuyen bay da hoan tat khong hieu chinh duoc!";
			return false;
		}
	}
	for(LVe* i = head->data.head; i != NULL; i=i->next)
		if(strlen(i->data.cccd) == 12){
			gotoXY(xThongBao, yThongBao);
			TextColor(4);   
			cout << "Chuyen bay da co khach dat ve khong hieu chinh duoc!";
			return false;
		}
    int size[2] = {30, 30};
	size[0] = 60;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong-1, size, 2, 1, 1, 60, 7);
    gotoXY(xHoatDong + 10, yHoatDong);
    TextColor(11);
    cout << "Cap nhat";
    size[0] = 20, size[1] = 40;
    TextColor(7);
    KhungChu(xHoatDong-3, yHoatDong+1, size, 2, 3, 2, 60, 7);
    TextColor(11);
    gotoXY(xHoatDong, yHoatDong + 2);  cout << "Ma chuyen bay: ";
    gotoXY(xHoatDong, yHoatDong + 4);  cout << "Ngay khoi hanh: ";
    gotoXY(xHoatDong, yHoatDong + 6);  cout << "Gio bay: ";
	string s;TextColor(7);
	Lap1:
	gotoXY(xHoatDong + 25, yHoatDong + 2); fflush(stdin);
    getline(cin, s);
        if(s.find("-1") != -1)
        return false;
	if (KiemTra(s, 1, 15) == false) {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Ma khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 2);
        cout << "              ";
        goto Lap1;
	}
	
	LChuyenBay* index = TimKiem(head, (char*)s.c_str());
	if (index == NULL) {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Ma khong co trong danh sach!";
		return false;
	}
	ChuyenBay x = index->data;
	int dong = 2;
	Lap2:
	gotoXY(xHoatDong + 25, yHoatDong + 2*dong++); getline(cin, s);
        if(s.find("-1") != -1)
        return false;
	if (KiemTra(s, 2, 11) == false || SoSanhNgay(s, ngay) < 1 || SoSanhNgay(s, ngay) > 365) {
        gotoXY(xThongBao, yThongBao); 
        TextColor(4);
		cout << "Ngay khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 2*(--dong));
        cout << "                ";
        goto Lap2;
	}
	strcpy(x.Ngay, (char*)s.c_str());
	LapGio:
	gotoXY(xHoatDong + 25, yHoatDong + 2*dong++); getline(cin, s);
        if(s.find("-1") != -1)
        return false;
	if(KiemTra(x.Gio, 3, 1) == false || (x.Ngay == ngay && x.Gio < gio)){
		gotoXY(xThongBao, yThongBao); 
        TextColor(4);
		cout << "Gio khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + 25, yHoatDong + 2*(--dong));
        cout << "                ";
        goto LapGio;
	}
	LapY:
	gotoXY(xThongBao, yThongBao);   
    TextColor(11);
	cout << "Ban co chac muon huy chuyen(y/n)?"; TextColor(7);cin >> s;
	if(!(s == "n" || s == "N" || s == "y" || s == "Y")){
		gotoXY(xThongBao, yThongBao);   
		TextColor(11);
		cout << "Lua chon khong hop le!                ";
		goto LapY;
	}
	if ((s == "n" || s == "N"))
		return false;

	index->data= x;;
	return true;
}
bool HuyChuyen(LChuyenBay*& head) {
	string s;
	ChuyenBay x;
    gotoXY(xHoatDong, yHoatDong);  
    TextColor(11);
	cout << "Huy chuyen bay";
	Lap1:
    gotoXY(xHoatDong, yHoatDong + 2);  
	cout << "Nhap ma chuyen bay: "; TextColor(7);fflush(stdin);
    getline(cin, s);
        if(s.find("-1") != -1)
        return false;
	if (KiemTra(s, 1, 15) == false) {
        gotoXY(xThongBao, yThongBao);
		TextColor(4);   
		cout << "Ma khong hop le!";
		        getch();
		gotoXY(xThongBao, yThongBao);  
		TextColor(7); 
		cout << "                      ";
        gotoXY(xHoatDong + strlen("Nhap ma chuyen bay: "), yHoatDong + 2);
        cout << "      ";
        goto Lap1;
	}
	LChuyenBay* index = TimKiem(head, (char*)s.c_str());
	if (index == NULL) {
        gotoXY(xThongBao, yThongBao); 
		TextColor(4);  
		cout << "Ma khong phu hop!";
		return false;
	}
	Lap2:
	gotoXY(xThongBao, yThongBao);   
    TextColor(11);
	cout << "Ban co chac muon huy chuyen(y/n)?"; TextColor(7);cin >> s;
	if(!(s == "n" || s == "N" || s == "y" || s == "Y")){
		gotoXY(xThongBao, yThongBao);   
		TextColor(11);
		cout << "Lua chon khong hop le!                ";
		goto Lap2;
	}
	if ((s == "n" || s == "N"))
		return false;
	index->data.TrangThai = 0;
	return true;
}
void DanhSachKhach(ChuyenBay x, Tree* root, int xhd, int yhd){
	int j = 1;
	int size[] = {15, 15, 15, 30, 15};
	TextColor(11);
	gotoXY(xhd, yhd);
	cout << setw(15) << left << "STT" << setw(15) << "Ma ve" << setw(15) << "CCCD"
	<< setw(30) << "Ho Ten" << setw(15) << "Phai";
	KhungChu(xhd - 2, yhd -1, size, 2, 1, 5, 90, 7);
	for(LVe* i = x.head; i != NULL; i=i->next){
		if(strlen(i->data.cccd) == 12){
			Tree* p = TimKiem(root, i->data.cccd);
			char hoTen[60];
			strcpy(hoTen, p->data.Ho);
			strcat(hoTen, " ");
			strcat(hoTen, p->data.Ten);
			gotoXY(xhd, yhd + 2*j);
			cout << setw(15) << left << j << setw(15) << i->data.Ma << setw(15) << i->data.cccd
			<< setw(30) << hoTen << setw(15) << p->data.Phai;
			KhungChu(xhd - 2, yhd -1 + 2*j, size, 2, 1, 5, 90, 7);
			j++;
		}
	}
}


