#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include"Font.h"
#include <queue>
using namespace std;
// check Ten, so, Ma, ngay
int tru_ngay(string day1, string day2);
bool check(string s, bool ten, bool so,  bool ma, bool ngay);
string chuyen_doi(int n);
int chuyen_doi(string s);
string chuan_hoa(string s);
// struct danh muc sach
struct DMS{
    string Ma;
    string TrangThai;
    string ViTri;
};
struct LDMS{
    DMS data;
    LDMS* next;
};
void them(LDMS* &head, string key, int n, int set_x, int set_y);
LDMS* tim_kiem(LDMS* head, string ma);
int xuat(LDMS* head, int x, int y);
//Dau sach
struct DauSach{
    string ISBN;
    string TenSach;
    int SoTrang;
    string TacGia;
    string NXB;
    string TheLoai;
    LDMS* head = NULL;
};
bool nhap(DauSach& x, int set_x, int set_y);
void doc_file(DauSach* A[200], int &n);
bool cap_nhat(DauSach &a);
int tim_kiem_ma(DauSach* A[200], int n, string ma);
int tim_kiem_ten(DauSach* A[200], int n, string ten, int x, int y);
int danh_sach_theo_the_loai(DauSach* A[200], int n, string the_loai, int x, int y);
bool cap_nhat(DauSach* A[200], int n);
void them(DauSach* A[200], int &n, DauSach x);

//struct muon tra
struct MuonTra{
    string Ma;
    string NgayMuon;
    string NgayTra;
    string TrangThai;
};
bool nhap(MuonTra &x);
bool tra(MuonTra& x);
struct LMuonTra{
    MuonTra data;
    LMuonTra* next;
};
int xuat(LMuonTra* head, int set_x, int set_y, string ngay, int d);
void them(LMuonTra*& head, MuonTra x);
// doc gia
struct DocGia{
	int MaThe;
	string Ho;
	string Ten;
	string Phai;
	string TrangThai;
	LMuonTra* head;
};
bool nhap(DocGia &x);
bool cap_nhat(DocGia &a);
void xuat(DocGia x);
struct Tree{
	DocGia data;
	Tree *left;
	Tree *right;
};
Tree* tim_kiem(Tree* root, int ma);
void them(Tree*& root, DocGia x);
void doc_file_muon_tra(Tree* root);
void doc_file(Tree*& root);
void phai_cung(Tree*& root, Tree*& la);
bool xoa(Tree* &root, int ma);
void danh_sach_theo_ma(Tree* root, int x, int &y);
void danh_sach_theo_ten(Tree* root, int x, int y);
void danh_sach_yeu_thich(Tree* root, DauSach* A[200], int n, int x, int y);
void danh_sach_qua_han(Tree* root, string day, int x, int y);
