#include "xuLy.h";
#include <queue>
using namespace std;
#pragma warning(disable : 4996)
#define setColorTable 7
#define setColorText 11
#define setColorMenu1 12
#define setColorMenu0 14
#define setX 30
#define setY 5
#define TbX 30
#define TbY 20
bool KiemTrafloat(char* s){
	for(int i=0; i<strlen(s); i++)
		if(!(s[i] == '.' || (s[i] >= 48 && s[i] <= 57)))
			return false;
	return true;
}
bool KiemTraint(char* s){
	for(int i=0; i<strlen(s); i++)
		if(!(s[i] >= 48 && s[i] <= 57))
			return false;
	return true;
}
bool KiemTraTen(char *s){
	for(int i=0; i<strlen(s); i++)
		if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == 32))
			return false;
	return true;
}
bool KiemTraMa(char *s){
	for(int i=0; i<strlen(s); i++)
		if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 48 && s[i] <= 57)))
			return false;
	return true;
}
float Float(char* s){
    float a = 0;
    int d = 1;
    for(int i=0; i<strlen(s); i++){
        if(s[i] == '.'){
            d = 10;
            continue;
        }
        if(d == 1)
            a = a*10 + s[i] - 48;
        else{
            a += 1.0*(s[i] - 48)/d;
            d *= 10;
        }
    }
    return a;
}
// mon hoc
void Nhap(MonHoc& x) {
	char lt[10];
	char th[10];
	while(1){
		system("cls");
		TextColor(setColorText);
		gotoXY(setX, setY);
		cout << "Nhap ma mon hoc: ";
		cin >> x.MAMH;
		gotoXY(setX, setY + 1);
		cout << "Nhap ten mon hoc: ";
		cin.ignore(); cin.getline(x.TENMH, 49);
		gotoXY(setX, setY + 2);
		cout << "Nhap so tin ly thuyet - thuc hanh: ";
		cin >> lt >> th ;
		if(KiemTraMa(x.MAMH) && KiemTraTen(x.TENMH) && KiemTraint(lt) && KiemTraint(th)){
			x.STCLT = Float(lt);
			x.STCTH = Float(th);
			return;
		}
		gotoXY(TbX, TbY);
		cout << "Nhap sai kieu du lieu!";
		gotoXY(TbX, TbY + 1);
		system("pause");
	}
}
void Update(MonHoc& x) {
	char lt[10];
	char th[10];
	while(1){
		system("cls");
		int j = 0;
		TextColor(setColorText);
		gotoXY(setX, setY + j++);
		cout << "Nhap ten mon hoc moi: ";
		cin.ignore(); cin.getline(x.TENMH, 49);
		gotoXY(setX, setY + j++);
		cout << "Nhap so tin ly thuyet - thuc hanh: ";
		cin >> lt >> th ;
		if(KiemTraMa(x.MAMH) && KiemTraTen(x.TENMH) && KiemTraint(lt) && KiemTraint(th)){
			x.STCLT = Float(lt);
			x.STCTH = Float(th);
			return;
		}
		gotoXY(TbX, TbY);
		cout << "Nhap sai kieu du lieu!";
		gotoXY(TbX, TbY + 1);
		system("pause");
	}
}
Tree* newTree(MonHoc x) {
	Tree* p = new Tree;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void Push(Tree*& root, MonHoc x) {
	if (root == NULL) {
		root = newTree(x);
	}
	else {
		if(strcmp(root->data.MAMH, x.MAMH) == 0){
			gotoXY(TbX, TbY);
		cout << "Ma mon hoc da co trong danh sach!";
		gotoXY(TbX, TbY + 1);
		system("pause");
		}
		if (strcmp(root->data.MAMH, x.MAMH) == 1)
			Push(root->left, x);
		else if (strcmp(root->data.MAMH, x.MAMH) == -1)
			Push(root->right, x);
	}
}
void Init(char* s, Tree*& root) {
	root = NULL;
	ifstream cin(s);
	if (!cin) {
		cout << "Loi file";
		return;
	}
	while (1) {
		MonHoc x;
		if (!(cin >> x.MAMH))
			return;
		cin.ignore(); cin.getline(x.TENMH, 49);
		cin >> x.STCLT >> x.STCTH;
		Push(root, x);
	}
}
void Delete(Tree*& root, char* mamh) {
	if (root == NULL)
		return;
	if (strcmp(root->data.MAMH, mamh) > 0)
		Delete(root->left, mamh);
	else if (strcmp(root->data.MAMH, mamh) < 0)
		Delete(root->right, mamh);
	else {
		Tree* p = root;
		if (p->left == NULL) {
			root = p->right;
		}
		else if (p->right == NULL) {
			root = p->left;
		}
		else {
			p = root->right;
			if (p->left == NULL) {
				root->data = p->data;
				root->right = p->right;
			}
			else {
				while (p->left->left != NULL) {
					p = p->left;
				}
				p->left = p->left->right;
			}
		}
	}
}
Tree* Search(Tree* root, char*mamh){
	if (root != NULL) {
		if (strcmp(root->data.MAMH, mamh) > 0)
			return Search(root->left, mamh);
		else if (strcmp(root->data.MAMH, mamh) < 0)
			return Search(root->right, mamh);
		else {
			return root;
		}
	}else
		return NULL;
}
void Update(Tree* root, char* mamh, bool &trangthai) {
	if (root != NULL) {
		if (strcmp(root->data.MAMH, mamh) > 0)
			Update(root->left, mamh, trangthai);
		else if (strcmp(root->data.MAMH, mamh) < 0)
			Update(root->right, mamh, trangthai);
		else {
			Update(root->data);
			trangthai = true;
		}
	}
}
char* TenMH(Tree* root, char* ma) {
	if (root != NULL) {
		if (strcmp(root->data.MAMH, ma) == 0)
			return root->data.TENMH;
		if (strcmp(root->data.MAMH, ma) > 0)
			return TenMH(root->left, ma);
		return TenMH(root->right, ma);
	}
}
void TenMH(Tree* root, MonHoc* x, int& n) {
	if (root != NULL) {
		x[n] = root->data;
		n++;
		TenMH(root->left, x, n);
		TenMH(root->right, x, n);
	}
}
void DSMonHoc(Tree* root) {
	int n = 0;
	MonHoc x[100];
	TenMH(root, x, n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(x[i].TENMH, x[j].TENMH) > 0) {
				MonHoc t = x[i];
				x[i] = x[j];
				x[j] = t;
			}
	system("cls");
	int j = 0;
	TextColor(setColorText);
	gotoXY(setX + 20, setY - 3);
	cout << "DANH SACH MON HOC";
	int size[] = { 10, 15, 30, 20, 20 };
	char** TieuDe;
	TieuDe = new char*[5];
	for (int i = 0; i < 5; i++)
		TieuDe[i] = new char[20];
	strcpy(TieuDe[0], "STT");
	strcpy(TieuDe[1], "MAMH");
	strcpy(TieuDe[2], "TEN MH");
	strcpy(TieuDe[3], "LY THUYET");
	strcpy(TieuDe[4], "THUC HANH");
	for (int i = 0; i < n; i++) {
		gotoXY(setX - 6, setY + 2 * i + 3);
		cout << left << setw(size[0]) << i + 1 << setw(size[1]) << x[i].MAMH << setw(size[2]) << x[i].TENMH
			<< setw(size[3]) << x[i].STCLT << setw(size[4]) << x[i].STCTH;
	}
	VeBang(setX - 10, setY, TieuDe, size, n + 1, 5);
}
void Xuat(Tree* root) {
	if (root != NULL) {
		Xuat(root->left);
		cout << root->data.MAMH << " " << root->data.TENMH << "\n";
		Xuat(root->right);
	}
}
MonHoc* Ten(Tree* root, char* mamh) {
	int n = 0;
	MonHoc *x = new MonHoc[100];
	TenMH(root, x, n);
	for (int i = 0; i < n; i++)
		if ((x->MAMH, mamh) == 0)
			return x;
	return NULL;
}

// sinh vien
void Nhap(SinhVien& x) {
	while(1){
		system("cls");
		int j = 0;
		TextColor(setColorText);
		gotoXY(setX, setY + j++);
		cout << "Nhap ma sinh vien: ";
		cin >> x.MASV;
		gotoXY(setX, setY + j++);
		cout << "Nhap ho: "; cin.ignore();
		cin.getline(x.HO, 10);
		gotoXY(setX, setY + j++);
		cout << "Nhap ten: ";
		cin.getline(x.TEN, 20);
		gotoXY(setX, setY + j++);
		cout << "Nhap gioi tinh: ";
		cin >> x.PHAI;
		gotoXY(setX, setY + j++);
		cout << "Nhap sdt: ";
		cin >> x.SDT;
		gotoXY(setX, setY + j++);
		cout << "Nhap ma lop: ";
		cin >> x.MALOP;
		if(KiemTraMa(x.MASV) && KiemTraTen(x.HO) && KiemTraTen(x.TEN) 
			&& (strcmp(x.PHAI, "Nam") == 0 || strcmp(x.PHAI, "Nu") == 0) && KiemTraint(x.SDT) 
			&& strlen(x.SDT) == 10 && KiemTraMa(x.MALOP)){
			return;
		}
		gotoXY(TbX, TbY);
		cout << "Nhap sai kieu du lieu!";
		gotoXY(TbX, TbY + 1);
		system("pause");
	}
}
void Xuat(SinhVien x) {
	system("cls");
	int j = 0;
	TextColor(setColorText);
	gotoXY(setX, setY + j++);
	cout << "Thong tin sinh vien:";
	gotoXY(setX, setY + j++);
	cout << "Ma sinh vien: " << x.MASV;
	gotoXY(setX, setY + j++);
	cout << "Ho ten: " << x.HO << " " << x.TEN;
	gotoXY(setX, setY + j++);
	cout << "Gioi tinh: " << x.PHAI;
	gotoXY(setX, setY + j++);
	cout << "So dien thoai: " << x.SDT;
	gotoXY(setX, setY + j++);
	cout << "Ma lop: " << x.MALOP;
}
void Update(SinhVien& x) {
	while(1){
		system("cls");
		int j = 0;
		TextColor(setColorText);
		gotoXY(setX, setY + j++);
		cin.ignore();
		cout << "Nhap ho: "; cin.getline(x.HO, 10);
		gotoXY(setX, setY + j++);
		cout << "Nhap ten: "; cin.getline(x.TEN, 20);
		gotoXY(setX, setY + j++);
		cout << "Nhap gioi tinh: "; cin >> x.PHAI;
		gotoXY(setX, setY + j++);
		cout << "Nhap SDT: "; cin >> x.SDT;
		gotoXY(setX, setY + j++);
		cout << "Nhap ma lop: "; cin >> x.MALOP;
		if(KiemTraTen(x.HO) && KiemTraTen(x.TEN) 
		&& (strcmp(x.PHAI, "Nam") == 0 || strcmp(x.PHAI, "Nu") == 0)
		&& KiemTraint(x.SDT) && KiemTraMa(x.MALOP)){
			return;
		}
		gotoXY(TbX, TbY);
		cout << "Nhap sai kieu du lieu!";
		gotoXY(TbX, TbY + 1);
		system("pause");
	}
}
Node1* newNode(SinhVien x) {
	Node1* p = new Node1;
	p->data = x;
	p->next = NULL;
	return p;
}
void Push(Node1*& head, SinhVien x, int d) {
	for(Node1*i = head; i != NULL; i=i->next)
		if(strcmp(i->data.MASV, x.MASV) == 0){
			Loading(TbX, TbY, 300);
			gotoXY(TbX, TbY);
			cout << "Ma sinh vien da co trong danh sach!";
			gotoXY(TbX, TbY + 1);
			system("pause");
			return;
		}
	Node1* p = newNode(x);
	if (head == NULL) {
		head = p;
	}
	else {
		Node1* i = head;
		while (i->next != NULL)
			i = i->next;
		i->next = p;
	}
	if(d == 0)
	return;
	Loading(TbX, TbY, 300);
    gotoXY(TbX, TbY + 1);
    cout << "Them thanh cong!";
    gotoXY(TbX, TbY + 1);
	system("pause");
}
void Init(char* s, Node1*& head) {
	head = NULL;
	ifstream cin(s);
	if (!cin) {
		cout << "Loi file";
		return;
	}
	while (1) {
		SinhVien x;
		if (!(cin >> x.MASV))
			return;
		cin >> x.HO;
		cin.ignore();
		cin.getline(x.TEN, 20);
		cin >> x.PHAI >> x.SDT >> x.MALOP;
		Push(head, x, 0);
	}
}
Node1* Search(Node1* head, char* masv, int d) {
	if (strcmp(head->data.MASV, masv) == 0) {
		if (d == 1)
			Xuat(head->data);
		return head;
	}
	for (Node1* i = head; i->next != NULL; i = i->next) {
		if (strcmp(i->next->data.MASV, masv) == 0) {
			if (d == 1)
				Xuat(head->next->data);
			return i;
		}
	}
	gotoXY(TbX, TbY);
	cout << "Ma sinh vien khong co trong danh sach!";
	gotoXY(TbX, TbY + 1);
	system("pause");
	system("cls");
	return NULL;
}
void Delete(Node1*& head, char* masv) {
	Node1* p = Search(head, masv, 0);
	if (p == NULL){
		return;
	}
	if (p == head && strcmp(p->data.MASV, masv) == 0)
		head = head->next;
	else {
		Node1* q = p->next;
		p->next = p->next->next;
		delete q;
	}
}
void Update(Node1*& head, char* masv, bool &trangthai) {
	Node1* p = Search(head, masv, 0);
	if (p == NULL){
		return;
	}
	if (p == head && strcmp(p->data.MASV, masv) == 0){
		Update(head->data);
		trangthai = true;
	}
	else {
		Update(p->next->data);
	}
}
void XuatDSSVTheoLop(Node1* head, char* maLop) {
	Node1* tam = NULL;
	for (Node1* i = head; i != NULL; i = i->next)
		if (strcmp(i->data.MALOP, maLop) == 0)
			Push(tam, i->data, 0);
	for (Node1* i = head; i->next->next != NULL; i = i->next)
		for (Node1* j = i->next; j->next != NULL; j = j->next)
			if (strcmp(i->data.TEN, j->data.TEN) > 0
				|| (strcmp(i->data.TEN, j->data.TEN) == 0
					&& strcmp(i->data.HO, j->data.HO) > 0)) {
				SinhVien t = i->data;
				i->data = j->data;
				j->data = t;
			}
	int size[] = { 10, 15, 20, 20, 10, 15, 15 };
	Loading(setX, setY, 300);
	system("cls");
	gotoXY(setX + 7, setY - 3);
	cout << "DANH SACH SINH VIEN";
	char** TieuDe;
	TieuDe = new char* [7];
	for (int i = 0; i < 7; i++)
		TieuDe[i] = new char[20];
	strcpy(TieuDe[0], "STT");
	strcpy(TieuDe[1], "MASV");
	strcpy(TieuDe[2], "Ho");
	strcpy(TieuDe[3], "Ten");
	strcpy(TieuDe[4], "Phai");
	strcpy(TieuDe[5], "SDT");
	strcpy(TieuDe[6], "Ma lop");
	int x = 0;
	for (Node1* i = tam; i != NULL; i = i->next) {
		gotoXY(setX - 14, setY + 2 * x + 3);
		cout << left << setw(size[0]) << x++ + 1 << setw(size[1]) << i->data.MASV << setw(size[2]) << i->data.HO 
			<< setw(size[3]) << i->data.TEN << setw(size[4]) << i->data.PHAI 
			<< setw(size[5]) << i->data.SDT << setw(size[6]) << i->data.MALOP;
	}
	VeBang(setX - 17, setY, TieuDe, size, x + 1, 7);
	getch();
	system("cls");
}
// Node2
Node2* newNode(DSDK x) {
	Node2* p = new Node2;
	p->data = x;
	p->next = NULL;
	return p;
}
void Push(Node2*& head, DSDK x) {
	Node2* p = newNode(x);
	if (head == NULL)
		head = p;
	else {
		Node2* i = head;
		while (i->next != NULL)
			i = i->next;
		i->next = p;
	}
}
void Push(Node2*& head, char* s, int diem, int huy) {
	DSDK x;
	strcpy(x.MASV, s);
	x.HDK = huy > 0;
	x.diem = diem;
	Push(head, x);
}
void InitDS(char* s, Lop* A[10000], int n) {
	ifstream cin(s);
	char ma[100]; ma[1] = '\0';
	char nien[100]; nien[1] = '\0';
	int ki, nhom;
	char c[100]; c[1] = '\0';
	while (1) {
		if (!(cin >> ma))
			return;
		cin >> nien >> ki >> nhom;
		for (int i = 0; i < n; i++)
			if (strcmp(A[i]->MAMH, ma) == 0 && strcmp(A[i]->NIENKHOA, nien) == 0 && A[i]->HK == ki && A[i]->NHOM == nhom) {
				cin >> c;
				Node2* head = NULL;
				do {
					cin >> c;
					if (strcmp(c, "*") != 0) {
						int diem, huy;
						cin >> diem >> huy;
						Push(head, c, diem, huy);
					}
					else
						break;
				} while (1);
				A[i]->head = head;
				break;
			}
	}
}
int SoLuong(Node2* head) {
	int n = 0;
	Node2* i = head;
	while (i != NULL) {
		if (i->data.HDK == false)
			n++;
		i = i->next;
	}
	return n;
}
int SoLuong(Lop* A[10000], int n, char* ma, char* nien, int hk) {
	int count = 0;
	for (int i = 0; i < n; i++)
		if (strcmp(A[i]->MAMH, ma) == 0 && strcmp(A[i]->NIENKHOA, nien) == 0 && A[i]->HK == hk)
			count += SoLuong(A[i]->head);
	return count;
}
void NhapDiem(Node2* head, int n) {
	Node2* i = head;
	int j = 0;
	for (; j != n; i = i->next, j++);
	cin >> i->data.diem;
}

void Nhap(Lop& x) {
	char hk[5];
	char nhom[5];
	char svmin[5];
	char svmax[5];
	while(1){
		system("cls");
		int j = 0;
		TextColor(setColorText);
		gotoXY(setX, setY + j++);
		cout << "Nhap ma mon hoc: "; cin >> x.MAMH;
		gotoXY(setX, setY + j++);
		cout << "Nhap nien khoa: ";
		cin.ignore(); cin.getline(x.NIENKHOA, 10);
		gotoXY(setX, setY + j++);
		cout << "Nhap hoc ki: "; cin >> hk;
		gotoXY(setX, setY + j++);
		cout << "Nhap nhom: "; cin >> nhom;
		gotoXY(setX, setY + j++);
		cout << "Nhap so sinh vien toi thieu: "; cin >> svmin;
		gotoXY(setX, setY + j++);
		cout << "Nhap so sinh vien toi da: "; cin >> svmax;
		if(KiemTraMa(x.MAMH) && KiemTraint(hk) && KiemTraint(nhom) 
		&& KiemTraint(svmin) && KiemTraint(svmax)){
			x.HUYLOP = false;
			x.head = NULL;
			x.NHOM = Float(nhom);
			x.SVMIN = Float(svmin);
			x.SVMAX = Float(svmax);
			x.HK = Float(hk);
			return;
		}
		gotoXY(TbX, TbY);
		cout << "Nhap sai kieu du lieu!";
		gotoXY(TbX, TbY + 1);
		system("pause");
	}
}
void Init(char* s, Lop* A[10000], int &n) {
	n = 0;
	char c[11];
	ifstream cin(s);
	while (1) {
		if (!(cin >> c))
			return;
		A[n] = new Lop;
		A[n]->MALOPTC = n;
		strcpy(A[n]->MAMH, c);
		cin >> A[n]->NIENKHOA >> A[n]->HK >> A[n]->NHOM
			>> A[n]->SVMIN >> A[n]->SVMAX;
		A[n]->HUYLOP = false;
		A[n]->head = NULL;
		n++;
	}
}
void Push(Lop* A[10000], int& n) {
	Lop x;
	if (n > 0)
		x.MALOPTC = A[n - 1]->MALOPTC + 1;
	else
		x.MALOPTC = 0;
	Nhap(x);
	A[n] = new Lop;
	*(A[n]) = x;
	n++;
}
void Delete(Lop* A[10000], int& n) {
	char mamh[16];
	char nien[11];
	char hk[5];
	char nhom[5];
	int j;
	while(1){
		system("cls");
		j = 0;
		TextColor(setColorText);
		gotoXY(setX, setY + j++);
		cout << "Nhap ma mon hoc: "; cin >> mamh;
		gotoXY(setX, setY + j++);
		cout << "Nhap nien: "; cin >> nien;
		gotoXY(setX, setY + j++);
		cout << "Nhap hoc ki: "; cin >> hk;
		gotoXY(setX, setY + j++);
		cout << "Nhap nhom: "; cin >> nhom;
		if(KiemTraMa(mamh) && KiemTraint(hk) && KiemTraint(nhom)){
			break;
		}
		gotoXY(TbX, TbY);
		cout << "Nhap sai kieu du lieu!";
		gotoXY(TbX, TbY + 1);
		system("pause");
	}
	for (int i = 0; i < n; i++)
		if (strcmp(A[i]->MAMH, mamh) == 0 && strcmp(A[i]->NIENKHOA, nien) == 0 && A[i]->HK == Float(hk) && A[i]->NHOM == Float(nhom)) {
			n--;
			for (; i < n; i++) {
				*A[i] = *A[i + 1];
				A[i]->MALOPTC = A[i - 1]->MALOPTC + 1;
			}
			Loading(TbX, TbY, 300);
			gotoXY(TbX, TbY + 1);
			cout << "Da xoa thanh cong!";
			getch();
			return;
		}
	gotoXY(TbX, TbY + 1);
	cout << "Khong co du lieu can xoa";
	getch();
}
void Update(Lop* A[10000], int n) {
	char mamh[16];
	char nien[11];
	char hk[5];
	char nhom[5];
	int j;
	while(1){
		system("cls");
		j = 0;
		TextColor(setColorText);
		gotoXY(setX, setY + j++);
		cout << "Nhap ma mon hoc: "; cin >> mamh;
		gotoXY(setX, setY + j++);
		cout << "Nhap nien: "; cin >> nien;
		gotoXY(setX, setY + j++);
		cout << "Nhap hoc ki: "; cin >> hk;
		gotoXY(setX, setY + j++);
		cout << "Nhap nhom: "; cin >> nhom;
		if(KiemTraMa(mamh) && KiemTraint(hk) && KiemTraint(nhom)){
			break;
		}
		gotoXY(TbX, TbY);
		cout << "Nhap sai kieu du lieu!";
		gotoXY(TbX, TbY + 1);
		system("pause");
	}
	for (int i = 0; i < n; i++)
		if (strcmp(A[i]->MAMH, mamh) == 0 && strcmp(A[i]->NIENKHOA, nien) == 0 && A[i]->HK == Float(hk) && A[i]->NHOM == Float(nhom)) {
			Lop x = *(A[i]);
			char hk[5];
			char nhom[5];
			char svmin[5];
			char svmax[5];
			while(1){
				system("cls");
				j = 0;
				TextColor(setColorText);
				gotoXY(setX, setY + j++);
				cout << "Nhap ma mon hoc: "; cin >> x.MAMH;
				gotoXY(setX, setY + j++);
				cout << "Nhap nien khoa: ";
				cin.ignore(); cin.getline(x.NIENKHOA, 10);
				gotoXY(setX, setY + j++);
				cout << "Nhap hoc ki: "; cin >> hk;
				gotoXY(setX, setY + j++);
				cout << "Nhap nhom: "; cin >> nhom;
				gotoXY(setX, setY + j++);
				cout << "Nhap so sinh vien toi thieu: "; cin >> svmin;
				gotoXY(setX, setY + j++);
				cout << "Nhap so sinh vien toi da: "; cin >> svmax;
				if(KiemTraMa(x.MAMH) && KiemTraint(hk) && KiemTraint(nhom) 
				&& KiemTraint(svmin) && KiemTraint(svmax)){
					x.NHOM = Float(nhom);
					x.SVMIN = Float(svmin);
					x.SVMAX = Float(svmax);
					x.HK = Float(hk);
					break;
				}
				gotoXY(TbX, TbY);
				cout << "Nhap sai kieu du lieu!";
				gotoXY(TbX, TbY + 1);
				system("pause");
			}
			*(A[i]) = x;
			delete& x;
			Loading(setX, setY + j++ + 1, 300);
			gotoXY(TbX, TbY);
			cout << "Cap nhat thanh cong!";
			getch();
			return;
		}
	Loading(setX, setY + j++ + 1, 300);
	gotoXY(TbX, TbY);
	cout << "Ma mon khong co trong danh sach!";
	getch();
}
void Search(Tree* root, Lop* A[10000], int n, char* nien, int hk, char* masv) {
	int size[] = { 15, 30, 10, 10, 10};
	char c;
	Loading(TbX, TbY, 300);
	system("cls");
	gotoXY(setX + 7, setY - 3);
	cout << "DANH SACH LOP";
	char** TieuDe;
	TieuDe = new char* [5];
	for (int i = 0; i < 5; i++)
		TieuDe[i] = new char[20];
	strcpy(TieuDe[0], "MAMH");
	strcpy(TieuDe[1], "TENMH");
	strcpy(TieuDe[2], "NHOM");
	strcpy(TieuDe[3], "SL");
	strcpy(TieuDe[4], "TRONG");
	int j = 0, num = 0;
	Lop *B = new Lop[n];
	char Ten[100][50];
	for(int i=0; i<n; i++)
		if (A[i]->HK == hk && strcmp(A[i]->NIENKHOA, nien) == 0) {
			B[num++] = *A[i];
		}
	for(int i=0; i<num; i++)
		for(int t=i+1; t<num; t++)
			if(strcmp(TenMH(root, B[i].MAMH), TenMH(root, B[j].MAMH)) > 0){
				Lop tam = B[i];
				B[i] = B[t];
				B[t] = tam;
			}
	int sl[100];
	for(int i=0; i<num; i++){
		gotoXY(setX - 14, setY + 3 + 2 * j++);
		sl[i] = SoLuong(A, n, B[i].MAMH, B[i].NIENKHOA, B[i].HK);
		cout << left << setw(size[0]) << B[i].MAMH << setw(size[1]) << TenMH(root, B[i].MAMH)
			<< setw(size[2]) << B[i].NHOM << setw(size[3]) << sl[i]
			<< setw(size[4]) << B[i].SVMAX - sl[i];
	}
	VeBang(setX - 17, setY, TieuDe, size, num+1, 5);
	gotoXY(setX + 7, setY + 2*num+5);
	cout << "Bam s de dang ki";
	int vitri = 0;
	gotoXY(setX - 5, setY + 2 * vitri + 3);
	cout << "<";
	while (1) {
		if (kbhit()) {
			c = getch();
			gotoXY(setX - 5, setY + 2 * vitri + 3);
			cout << " ";
			switch (c) {
			case 72: { // len
				vitri--;
				if (vitri == -1)
					vitri = num-1;
				break;
			}
			case 80: { // xuong
				vitri++;
				if (vitri == num)
					vitri = 0;
				break;
			}
			case 's': {
				if(sl[vitri] < 1){
					gotoXY(TbX, TbY);
					cout << "Lop da du!";
				}else{
					int Diem = -1;
					int huy = 0;
					for(int i=0; i<n; i++)
						if(B[vitri].MALOPTC == A[i]->MALOPTC){
							Push(A[i]->head, masv, Diem, huy);
							gotoXY(TbX, TbY);
							cout << "Dang ki thanh cong!";
							break;
						}
				}
				getch();
				system("cls");
				return;
			}
			case 27: { // thoat
				system("cls");
				return;
			}
			}
			gotoXY(setX - 5, setY + 2 * vitri + 3);
			cout << "<";
		}
				}
	getch();
	system("cls");
}
int soTinDaDangKy(Tree* root, Lop* A[10000], int n, char* masv){
	int soTin = 0;
	MonHoc x[100];
	for(int i=0; i<n; i++){
		for(Node2* j=A[i]->head; j !=NULL; j=j->next)
			if(strcmp(j->data.MASV, masv) == 0){
				Tree* p = Search(root, A[i]->MAMH);
				soTin+=p->data.STCLT + p->data.STCTH;
				break;
			}			
	}
	return soTin;
}
void HuyLop(Lop* A[10000], int n) {
	char c;
	do {
		system("cls");
		int j = 0;
		TextColor(setColorText);
		gotoXY(setX, setY + j++);
		cout << "Ban co muon huy cac lop khong du sinh vien khong(y/n)?";
		cin >> c;
		if (c == 'n' || c == 'N')
			return;
		if (c == 'y' || c == 'Y')
			break;
		else {
			gotoXY(TbX, TbY);
			cout << "Thao tac sai!";
		}
	} while (1);
	for (int i = 0; i < n; i++)
		if (SoLuong(A[i]->head) < A[i]->SVMIN)
			A[i]->HUYLOP = true;
}
void NhapDiem(Lop* A[10000], int n, char* ma, char* nien, int hk, int nhom, Node1* head, int d) {
	int size[] = { 10, 15, 20, 20, 10 };
	Loading(TbX, TbY, 300);
	system("cls");
	gotoXY(setX + 7, setY - 3);
	cout << "DANH SACH SINH VIEN";
	char** TieuDe;
	TieuDe = new char* [5];
	for (int i = 0; i < 5; i++)
		TieuDe[i] = new char[20];
	strcpy(TieuDe[0], "STT");
	strcpy(TieuDe[1], "MASV");
	strcpy(TieuDe[2], "Ho");
	strcpy(TieuDe[3], "Ten");
	strcpy(TieuDe[4], "Diem");
	int j = 1;
	for (int i = 0; i < n; i++)
		if (strcmp(A[i]->MAMH, ma) == 0 && A[i]->HK == hk && strcmp(A[i]->NIENKHOA, nien) == 0 && A[i]->NHOM == nhom) {
			Node2* head2 = A[i]->head;
			while (head2 != NULL) {
				Node1* tim = Search(head, head2->data.MASV, 0);
				if (strcmp(tim->data.MASV, head2->data.MASV)) {
					gotoXY(setX - 10, setY + 2 * j + 1);
					cout << setw(size[0]) << left << j++ << setw(size[1]) << head2->data.MASV << setw(size[2]) << tim->data.HO
						<< setw(size[3]) << tim->data.TEN;
				}
				if (head2->data.diem != -1)
					cout << setw(size[4]) << left << head2->data.diem ;
				else
					cout << setw(size[4]) << left << " ";
				head2 = head2->next;
			}
			VeBang(setX - 13, setY, TieuDe, size, j, 5);
			if (d == 1) { // sua diem
				gotoXY(setX + 7, TbY + 5);
				cout << "Bam s de nhap diem";
				char c;
				int vitri = 0;
				gotoXY(setX + 54, setY + 2 * vitri + 3);
				cout << ">";
				while (1) {
					if (kbhit()) {
						c = getch();
						gotoXY(setX + 54, setY + 2 * vitri + 3);
						cout << " ";
						switch (c) {
						case 72: { // len
							vitri--;
							if (vitri == -1)
								vitri = j - 1;
							break;
						}
						case 80: { // xuong
							vitri++;
							if (vitri == j - 1)
								vitri = 0;
							break;
						}
						case 's': {
							int dodai = 0;
							gotoXY(setX + 55, setY + 2 * vitri + 3);
							cout << "    ";
							float diem;
							gotoXY(setX + 55, setY + 2 * vitri + 3);
							cin >> diem;
							if(diem < 0 || diem > 10){
								int dodai = 0;
								gotoXY(setX + 55, setY + 2 * vitri + 3);
								cout << "    ";
								break;
							}
							int sua = 0;
							for (head2 = A[i]->head; sua != vitri; head2 = head2->next, sua++);
							head2->data.diem = diem;
							break;
						}
						case 27: { // thoat
							system("cls");
							return;
						}
						}
						gotoXY(setX + 54, setY + 2 * vitri + 3);
						cout << ">";
					}
				}
			}
			return;
		}
	gotoXY(setX + 7, setY - 1);
	cout << "DANH SACH TRONG";
}

float DiemTB(char* maSV, Lop* A[10000], int n) {
	float sum = 0;
	int sl = 0;
	for (int i = 0; i < n; i++) {
		for(Node2* head = A[i]->head; head != NULL; head = head->next)
			if (strcmp(head->data.MASV, maSV) == 0 && head->data.diem != -1) {
				sum += head->data.diem;
				sl++;
			}
	}
	if(sl == 0)
		return 0;
	return sum / sl;
}
void DSdiemTB(Lop* A[10000], int n, char* maLop, Node1* head) {
	int size[] = { 10, 15, 20, 20, 10 };
	int j = 1;
	Loading(TbX, TbY, 300);
	system("cls");
	gotoXY(setX + 7, setY - 3);
	cout << "DANH SACH DIEM TB";
	char** TieuDe;
	TieuDe = new char* [5];
	for (int i = 0; i < 5; i++)
		TieuDe[i] = new char[20];
	strcpy(TieuDe[0], "STT");
	strcpy(TieuDe[1], "MASV");
	strcpy(TieuDe[2], "Ho");
	strcpy(TieuDe[3], "Ten");
	strcpy(TieuDe[4], "Diem");
	Node1* Tam = NULL;
	for (Node1* i = head; i != NULL; i = i->next, j) 
		if (strcmp(i->data.MALOP, maLop) == 0)
			Push(Tam, i->data, 0);
	for(Node1*i = Tam; i->next != NULL; i = i->next)
		for(Node1* ii=i->next; ii!= NULL; ii = ii->next)
			if(strcmp(i->data.TEN, ii->data.TEN) > 0 
			|| (strcmp(i->data.TEN, ii->data.TEN) == 0 && strcmp(i->data.HO, ii->data.HO) > 0)){
				SinhVien tam = i->data;
				i->data = ii->data;
				ii->data = tam;
			}
	for(Node1*i = Tam; i->next != NULL; i = i->next){
		gotoXY(setX - 14, setY + 2 * j + 1);
		cout << left << setw(size[0]) << j++ << setw(size[1]) << i->data.MASV
			<< setw(size[2]) << i->data.HO << setw(size[3]) << i->data.TEN
			<< setw(size[4]) << fixed << setprecision(2) << DiemTB(i->data.MASV, A, n);
	}
	VeBang(setX - 17, setY, TieuDe, size, j, 5);
	getch();
	system("cls");
}
void DSdiemTK(Lop* A[10000], int n, char* maLop, Node1* head, Tree* root) {
	int slMon = 0, stt = 1;
	MonHoc x[100];
	TenMH(root, x, slMon);
	char** TieuDe;
	TieuDe = new char* [slMon + 3];
	for (int i = 0; i < slMon + 3; i++) {
		TieuDe[i] = new char[50];
		TieuDe[i][1] = '\0';
	}
	int* size = new int[slMon + 3];
	for (int i = 0; i < slMon + 3; i++)
		size[i] = 10;
	size[1] = 15;
	size[2] = 30;
	strcpy(TieuDe[0], "STT");
	strcpy(TieuDe[1], "MASV");
	strcpy(TieuDe[2], "Ho va Ten");
	for (int i = 3; i < slMon + 3; i++)
		strcpy(TieuDe[i], x[i-3].MAMH);
	char hoTen[40];
	for (Node1* i = head; i != NULL; i = i->next) {
		if (strcmp(i->data.MALOP, maLop) == 0) // tim duoc sinh vien trong lop
		{
			hoTen[1] = '\0';
			strcpy(hoTen, i->data.HO);
			strcat(hoTen, " ");
			strcat(hoTen, i->data.TEN);
			gotoXY(setX - 20, setY + 2 * stt + 1);
			cout << setw(size[0]) << left << stt++ << setw(size[1]) << i->data.MASV << setw(30) << hoTen;
			for (int j = 0; j < slMon; j++) {
				float diemMax = -1; // khong hoc
				for (int lop = 0; lop < n; lop++)
					if (strcmp(A[lop]->MAMH, x[j].MAMH) == 0)
						for (Node2* head = A[lop]->head; head != NULL; head = head->next)
							if (strcmp(head->data.MASV, i->data.MASV) == 0 && diemMax < head->data.diem)
								diemMax = head->data.diem;
				// tim duoc diem max
				if (diemMax == -1)
					cout << setw(10) << "";
				else
					cout << setw(10) << left << fixed << setprecision(2) << diemMax;
			}
		}
	}
	VeBang(setX - 23, setY, TieuDe, size, stt, slMon + 3);
	getch();
	system("cls");
}
void SaveSinhVien(Node1* head) {
	ofstream cout("./sinhVienNew.txt");
	for (Node1* i = head; i != NULL; i = i->next) {
		cout << i->data.MASV << endl;
		cout << i->data.HO << endl;
		cout << i->data.TEN << endl;
		cout << i->data.PHAI << endl;
		cout << i->data.SDT << endl;
		cout << i->data.MALOP << endl;
	}
	cout.close();
}
void SaveMonHoc(Tree* root) {
	ofstream cout("./monHocNew.txt");
	queue <Tree*> x;
	x.push(root);
	while (x.empty()) {
		cout << x.front()->data.MAMH << endl;
		cout << x.front()->data.TENMH << endl;
		cout << x.front()->data.STCLT << endl;
		cout << x.front()->data.STCTH << endl;
		if (root->left != NULL)
			x.push(root->left);
		if (root->right != NULL)
			x.push(root->right);
	}
	cout.close();
}
void SaveLop(Lop* A[10000], int n) {
	ofstream cout("./lopNew.txt");
	for (int i = 0; i < n; i++) {
		cout << A[i]->MAMH << endl;
		cout << A[i]->NIENKHOA << endl;
		cout << A[i]->HK << endl;
		cout << A[i]->NHOM << endl;
		cout << A[i]->SVMIN << endl;
		cout << A[i]->SVMAX << endl;
	}
	cout.close();
}
void SaveDSHS(Lop* A[10000], int n) {
	ofstream cout("./danhSachHSNew.txt");
	for (int i = 0; i < n; i++) {
		cout << A[i]->MAMH << endl;
		cout << A[i]->NIENKHOA << endl;
		cout << A[i]->HK << endl;
		cout << A[i]->NHOM << endl;
		cout << "*" << endl;
		for (Node2* head = A[i]->head; head != NULL; head = head->next) {
			cout << head->data.MASV << " " << head->data.diem << " " << head->data.HDK << endl;
		}
		cout << "*";
	}
	cout.close();
}
