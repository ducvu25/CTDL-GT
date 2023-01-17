#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
#include"Font.h"
#include"Back.h"
int set_x = 30;
int set_y = 2;
int set_thong_bao_x = 30;
int set_thong_bao_y = 15;
using namespace std;

int main(){
    system("cls");
    Tree* root; doc_file(root); doc_file_muon_tra(root);
    DauSach* A[200]; int n; doc_file(A, n);
    int chuc_nang1, chuc_nang2;
    char c1, c2;
    MENU1:
    chuc_nang1=1, chuc_nang2=1;
    menu_1(set_x, set_y, 1);
    while(1){
        if(kbhit()){ // neu co phim duoc bam
            c1 = getch(); // gan phim do = c1
            switch (c1){
            case 'H':{ // di len - lay ma = phim di len
                if(chuc_nang1 == 1){
                    chuc_nang1 = 3;
                    break;
                }
                chuc_nang1--;
                break;
            }
            case 'P':{ // di xuong
                if(chuc_nang1 == 3){
                    chuc_nang1 = 1;
                    break;
                }
                chuc_nang1++;
                break;
            }
            case 13:{ // phim enter
                system("cls");
                switch (chuc_nang1){ 
                case 1:{ 
                    menu_2(set_x, set_y, chuc_nang2);
                    while(1){
                        if(kbhit()){
                            c2 = getch();
                            switch (c2){
                            case 'H':{ // di len
                                if(chuc_nang2 == 1){
                                    chuc_nang2 = 6;
                                    break;
                                }
                                chuc_nang2--;
                                break;
                            }
                            case 'P':{
                                if(chuc_nang2 == 6){
                                    chuc_nang2 = 1;
                                    break;
                                }
                                chuc_nang2++;
                                break;
                            }
                            case 13:{
                                system("cls");
                                switch (chuc_nang2){
                                case 1:{
                                    gotoXY(set_x, set_y);
                                    cout << "Them";
                                    DocGia doc_gia;
                                    if(!nhap(doc_gia)){ // neu nhap sai
                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
                                    	cout << "Them that bai!";
									}else{
										int ma;
										do{
											ma = rand() % 1000;
										}while(tim_kiem(root, ma) != NULL);
										doc_gia.MaThe = ma;
										them(root, doc_gia);
										xuat(doc_gia);
										gotoXY(set_thong_bao_x, set_thong_bao_y);
										cout << "Them thanh cong!";
									}
                                    break;
                                }
                                case 2:{
                                    gotoXY(set_x, set_y);
                                    cout << "Xoa";
                                    string mas;
                                    fflush(stdin); // xoa bo nho thua khi nhap
                                    gotoXY(set_x, set_y + 1);
                                    cout << "Nhap ma: ";
                                    getline(cin, mas); // nhap ma - nhap string
                                    if(check(mas, 0, 1, 0, 0) == false){
                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
                                    	cout << "Ma khong hop le!";
									}else{
										int ma = chuyen_doi(mas);
										Tree* p = tim_kiem(root, ma);
	                                    if(p == NULL){
	                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
	                                    	cout << "Ma khong co trong danh sach";
										}else{
											
											cout << "Thong tin:\n";
											xuat(p->data);
											cout << "Ban co muon xoa khong(y/n)?";
											char chon;
											cin >> chon;
											if(chon == 'y'){
												xoa(root, ma);
												gotoXY(set_thong_bao_x, set_thong_bao_y);
												cout << "Xoa thanh cong!";
											}else{
												gotoXY(set_thong_bao_x, set_thong_bao_y);
												cout << "Xoa that bai!";
											}
										}
									}
                                    break;
                                }
                                case 3:{
                                    gotoXY(set_x, set_y);
                                    cout << "Chinh thong tin\n";
                                    string mas;
                                    fflush(stdin);
                                    gotoXY(set_x, set_y + 1);
                                    cout << "Nhap ma: ";
                                    getline(cin, mas);
                                    if(check(mas, 0, 1, 0, 0) == false){
                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
                                    	cout << "Ma khong hop le!";
									}else{
										int ma = chuyen_doi(mas);
										Tree* p = tim_kiem(root, ma);
	                                    if(p == NULL){
	                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
	                                    	cout << "Ma khong co trong danh sach";
										}else{	
											cout << "Thong tin:\n";
											xuat(p->data);
											DocGia doc_gia;
											doc_gia = p->data;
											if(cap_nhat(doc_gia) == false){
												gotoXY(set_thong_bao_x, set_thong_bao_y);
												cout << "Cap nhat that bai!";
											}else{
												cout << "Ban co muon cap nhat khong(y/n)?";
												char chon;
												cin >> chon;
												if(chon == 'y'){
													p->data = doc_gia;
													gotoXY(set_thong_bao_x, set_thong_bao_y);
													cout << "Cap nhat thanh cong!";
												}else{
													gotoXY(set_thong_bao_x, set_thong_bao_y);
													cout << "Cap nhat that bai!";
												}
											}
										}
									}
                                    break;
                                }
                                case 4:{
                                    gotoXY(set_x+ 30, set_y);
								    cout << "Danh sach";
									set_x -= 10;
								    ve_o(set_x- 3, set_y - 1, 85);
								    gotoXY(set_x, set_y+=2);
								    cout << left << setw(15) << "Ma the" << setw(20) << "Ho" << setw(20) << "Ten"
									<< setw(15) << "Phai" << setw(15) << "Trang thai";
								    ve_o(set_x- 3, set_y- 1, 15); ve_o(set_x- 3 + 15, set_y- 1, 20); ve_o(set_x- 3 + 35, set_y- 1, 20);
									ve_o(set_x- 3 + 55, set_y- 1, 15); ve_o(set_x- 3 + 70, set_y- 1, 15);
									set_y -= 2;
									set_x += 10;
                                    danh_sach_theo_ten(root, set_x - 10, set_y + 3);
                                    break;
                                }
                                case 5:{
                                    gotoXY(set_x + 20, set_y);
                                    cout << "Danh sach";
									set_x -= 10;
								    ve_o(set_x- 3, set_y - 1, 85);
								    gotoXY(set_x, set_y+=2);
								    cout << left << setw(15) << "Ma the" << setw(20) << "Ho" << setw(20) << "Ten"
									<< setw(15) << "Phai" << setw(15) << "Trang thai";
								    ve_o(set_x- 3, set_y- 1, 15); ve_o(set_x- 3 + 15, set_y- 1, 20); ve_o(set_x- 3 + 35, set_y- 1, 20);
									ve_o(set_x- 3 + 55, set_y- 1, 15); ve_o(set_x- 3 + 70, set_y- 1, 15);
									set_y -= 2;
									set_x += 10;
                                    int yToaDo = set_y + 2;
                                    danh_sach_theo_ma(root, set_x - 10, yToaDo);
                                    break;
                                }
                                case 6:{
                                	gotoXY(set_x, set_y);
                                	cout << "Nhap ngay: "; string ngay; cin >> ngay;
                                    danh_sach_qua_han(root, ngay, set_x, set_y);
                                    break;
                                }
                                }
                                getch();
                                system("cls");
                                break;
                            }
                            case 27:{
                                system("cls");
                                goto MENU1;
                            }
                            }
                            menu_2(set_x, set_y, chuc_nang2);
                        }
                    }
                    break;
                }
                case 2:{
                    menu_3(set_x, set_y, chuc_nang2);
                    while(1){
                        if(kbhit()){
                            c2 = getch();
                            switch (c2){
                            case 'H':{ // di len
                                if(chuc_nang2 == 1){
                                    chuc_nang2 = 3;
                                    break;
                                }
                                chuc_nang2--;
                                break;
                            }
                            case 'P':{
                                if(chuc_nang2 == 3){
                                    chuc_nang2 = 1;
                                    break;
                                }
                                chuc_nang2++;
                                break;
                            }
                            case 13:{
                                system("cls");
                                switch (chuc_nang2){
                                case 1:{
                                    gotoXY(set_x, set_y);
                                    cout << "Nhap ngay: "; string ngay; cin >> ngay;
                                    if(check(ngay, 0, 0, 0, 1) == false){
                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
                                    	cout << "Ngay khong hop le!";
                                    	break;
									}
									gotoXY(set_x, set_y + 1);
                                    cout << "Nhap ma the: ";
                                    int ma; cin >> ma;
                                    Tree* p = tim_kiem(root, ma);
                                    if(p == NULL){
                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
                                    	cout << "Ma the khong co trong danh sach!";
									}else{
										
										int dem = xuat(p->data.head, set_x - 5, set_y, ngay, -1);
										if(dem > 3){
											gotoXY(set_thong_bao_x, set_thong_bao_y);
											cout << "Ban khong duoc phep muon sach!";
										}else{
											getch();
											system("cls");
											gotoXY(set_x, set_y);
											cout << "Nhap ma dau sach: "; string ma_dau_sach; cin >> ma_dau_sach;
											int index = tim_kiem_ma(A, n, ma_dau_sach);
											if(index == -1){
												gotoXY(set_thong_bao_x, set_thong_bao_y);
												cout << "Khong co ma dau sach phu hop!";
											}else{
												int j = xuat(A[index]->head, set_x + 5, set_y);
												gotoXY(set_x, set_y + j*2 + 5);
												cout << "Nhap ma sach: "; string ma_sach; cin >> ma_sach;
												LDMS* pp = tim_kiem(A[index]->head, ma_sach);
												if(pp == NULL || pp->data.TrangThai != "0"){
													gotoXY(set_x, set_y + j*2 + 7);
													cout << "Muon that bai!";
												}else{
													gotoXY(set_x, set_y + j*2 + 7);
													cout << "Muon thanh cong!";
													MuonTra muon_tra;
													muon_tra.Ma = ma_sach;
													muon_tra.NgayMuon = ngay;
													muon_tra.NgayTra = "";
													muon_tra.TrangThai = "0";
													them(p->data.head, muon_tra);
													pp->data.TrangThai = "1";
												}
											}
										}
									}
                                    break;
                                }
                                case 2:{
                                	gotoXY(set_x, set_y);
                                    cout << "Nhap ngay: "; string ngay; cin >> ngay;
                                    if(check(ngay, 0, 0, 0, 1) == false){
                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
                                    	cout << "Ngay khong hop le!";
                                    	break;
									}
                                    gotoXY(set_x, set_y + 1);
                                    cout << "Nhap ma the: "; int ma; cin >> ma;
                                    Tree* p = tim_kiem(root, ma);
                                    if(p == NULL){
                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
                                    	cout << "Ma the khong co trong danh sach!";
									}else{
										int so_luong = xuat(p->data.head, set_x - 5, set_y, ngay, 1) + 1;
										char dieu_khien;
										int chuc_nang_3 = 1;
										while(1){
											if(kbhit()){
												dieu_khien = getch();
												switch(dieu_khien){
													case 'H':{
														chuc_nang_3--;
														if(chuc_nang_3 == 0)
															chuc_nang_3 = so_luong;
														break;
													}
													case 'P':{
														chuc_nang_3++;
														if(chuc_nang_3 == so_luong + 1)
															chuc_nang_3 = 1;
														break;
													}
													case 13:{
														int j = 1;
														for(LMuonTra* i = p->data.head; i != NULL; i = i->next){
															if(j == chuc_nang_3){
																if(i->data.TrangThai != "0")
																	goto THOAT;
																//cout << "HI";
																i->data.NgayTra = ngay;
																i->data.TrangThai = "1";
																for(int ii=0; ii<n; ii++){
																	for(LDMS* pp = A[ii]->head; pp != NULL; pp = pp->next){
																		if(pp->data.Ma == i->data.Ma){
																			pp->data.TrangThai = "0";
																			gotoXY(set_thong_bao_x, set_thong_bao_y + 5);
																			cout << "Tra thanh cong!";
																			goto THOAT;
																		}
																	}
																}
															}
															j++;
														}
														break;
													}
												}
												xuat(p->data.head, set_x - 5, set_y, ngay, chuc_nang_3 - 1);
											}
										}
									}
									THOAT:
                                    break;
                                }
                                case 3:{
                                    gotoXY(set_x, set_y);
                                    gotoXY(set_x, set_y);
                                    cout << "Nhap ma the: "; int ma; cin >> ma;
                                    Tree* p = tim_kiem(root, ma);
                                    if(p == NULL){
                                    	gotoXY(set_thong_bao_x, set_thong_bao_y);
                                    	cout << "Ma the khong co trong danh sach!";
									}else{
										xuat(p->data.head, set_x - 5, set_y, "12/10/2023", -1);
									}
                                    break;
                                }
                                }
                                getch();
                                system("cls");
                                break;
                            }
                            case 27:{
                                system("cls");
                                goto MENU1;
                            }
                            }
                            menu_3(set_x, set_y, chuc_nang2);
                        }
                    }
                    break;
                }
                case 3:{
                    menu_4(set_x, set_y, chuc_nang2);
                    while(1){
                        if(kbhit()){
                            c2 = getch();
                            switch (c2){
                            case 'H':{ // di len
                                if(chuc_nang2 == 1){
                                    chuc_nang2 = 4;
                                    break;
                                }
                                chuc_nang2--;
                                break;
                            }
                            case 'P':{
                                if(chuc_nang2 == 4){
                                    chuc_nang2 = 1;
                                    break;
                                }
                                chuc_nang2++;
                                break;
                            }
                            case 13:{
                                system("cls");
                                switch (chuc_nang2){
                                case 1:{
                                    DauSach dau_sach;
                                    if(nhap(dau_sach, set_x, set_y)){
                                    	them(A, n, dau_sach);
									}
                                    break;
                                }
                                case 2:{
                                    gotoXY(set_x, set_y);
                                    cout << "Ten the loai tim kiem: ";
                                    string the_loai; fflush(stdin); getline(cin, the_loai);
                                    if(check(the_loai, 1, 0, 0, 0)){
                                    	danh_sach_theo_the_loai(A, n, chuan_hoa(the_loai), set_x, set_y);
									}
                                    break;
                                }
                                case 3:{
                                    gotoXY(set_x, set_y);
                                    cout << "Ten tim kiem: ";
                                    string ten; fflush(stdin); getline(cin, ten);
                                    if(check(ten, 1, 0, 0, 0)){
                                    	tim_kiem_ten(A, n, chuan_hoa(ten), set_x, set_y);
									}
                                    break;
                                }
                                case 4:{
                                    danh_sach_yeu_thich(root, A, n, set_x, set_y);
                                   
                                    break;
                                }
                                }
                                getch();
                                system("cls");
                                break;
                            }
                            case 27:{
                                system("cls");
                                goto MENU1;
                            }
                            }
                            menu_4(set_x, set_y, chuc_nang2);
                        }
                    }
                    break;
                }
                }
                break;
            }
            case 27:{
                return 0;
            }
            }
            menu_1(set_x, set_y, chuc_nang1);
        }
    }
    return 0;
}
