#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include "giaoDien.h"
#include <string.h>
bool KiemTrafloat(char* s);
bool KiemTraint(char* s);
bool KiemTraTen(char *s);
bool KiemTraMa(char *s);
float Float(char *s);
struct MonHoc {
	char MAMH[10];
	char TENMH[50];
	int STCLT;
	int STCTH;
};
bool Nhap(MonHoc& x);
bool Update(MonHoc& x);
struct Tree {
	MonHoc data;
	Tree* left;
	Tree* right;
};
Tree* newTree(MonHoc x);
void Push(Tree*& root, MonHoc x);
void Init(char* s, Tree*& root);
bool Delete(Tree*& root, char* mamh);
Tree* Search(Tree* root, char*mamh);
void Update(Tree* root, char* mamh, bool &trangthai);
char* TenMH(Tree* root, char* ma);
void TenMH(Tree* root, char DSten[][50], int& n);
void DSMonHoc(Tree* root);
void Xuat(Tree* root);
MonHoc* Ten(Tree* root, char* mamh);


// quản lý sinh viên
struct SinhVien {
	char MASV[16];
	char HO[11];
	char TEN[21];
	char PHAI[6];
	char SDT[11];
	char MALOP[16];
};
bool Nhap(SinhVien& x);
void Xuat(SinhVien x);
bool Update(SinhVien& x);
struct Node1 {
	SinhVien data;
	Node1* next;
};
Node1* newNode(SinhVien x);
void Push(Node1*& head, SinhVien x, int d);
void Init(char* s, Node1*& head);
Node1* Search(Node1* head, char* masv, int d);
bool Delete(Node1*& head, char* masv);
void Update(Node1*& head, char* masv, bool &trangthai);
void XuatDSSVTheoLop(Node1* head, char* maLop);
// danh sach dang ky
struct DSDK {
	char MASV[11];
	float diem;
	bool HDK;
};
struct Node2 {
	DSDK data;
	Node2* next;
};

// lớp tín chỉ
struct Lop {
	int MALOPTC; // tu dong tang
	char MAMH[11];
	char NIENKHOA[11];
	int HK;
	int NHOM;
	int SVMIN;
	int SVMAX;
	bool HUYLOP;
	Node2* head;
};
void Nhap(Lop& x);
void Init(char* s, Lop* A[10000], int &n);
void Push(Lop* A[10000], int& n);
void Delete(Lop* A[10000], int& n);
void Update(Lop* A[10000], int n);
void HuyLop(Lop* A[10000], int n);
void Search(Tree* root, Lop* A[10000], int n, char* nien, int hk, char* masv);
int soTinDaDangKy(Tree* root, Lop* A[10000], int n, char* masv);

Node2* newNode(DSDK x);
void Push(Node2*& head, DSDK x);
void Push(Node2*& head, char* s, int diem, int huy);
void InitDS(char* s, Lop* A[10000], int n);
int SoLuong(Node2* head);
int SoLuong(Lop* A[10000], int n, char* ma, char* nien, int hk);
void NhapDiem(Node2* head, char* masv);
void NhapDiem(Lop* A[10000], int n, char* ma, char* nien, int hk, int nhom, Node1* head, int d);

float DiemTB(char* maSV, Lop* A[10000], int n);
void DSdiemTB(Lop* A[10000], int n, char* maLop, Node1* head);
void DSdiemTK(Lop* A[10000], int n, char* maLop, Node1* head, Tree* root);

// luu du lieu
void SaveSinhVien(Node1* head);
void SaveMonHoc(Tree* root);
void SaveLop(Lop* A[10000], int n);
void SaveDSHS(Lop* A[10000], int n);
