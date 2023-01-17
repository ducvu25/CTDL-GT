#include"Back.h"
using namespace std;
int tieu_de = 14;
int loi = 12;
int toa_do_x = 30, toa_do_y = 2;
int toa_do_tb_x = 30, toa_do_tb_y = 15;
int tru_ngay(string day1, string day2){
	int ngay2 = chuyen_doi(day2.substr(3, 2))*30 + chuyen_doi(day2.substr(0, 2));
	int ngay1 = chuyen_doi(day1.substr(3, 2))*30 + chuyen_doi(day1.substr(0, 2));
	return ngay2 - ngay1;
}
bool check(string s, bool ten, bool so,  bool ma, bool ngay){
    if(ten){
        for(int i=0; i<s.size(); i++)
            if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
            || (s[i] >= '0' && s[i] <= '9') || s[i] == 32))
                return false;
        return true;
    }
    if(so){
        for(int i=0; i<s.size(); i++)
            if(!(s[i] >= '0' && s[i] <= '9'))
                return false;
        return true;
    }
    if(ma){
        for(int i=0; i<s.size(); i++)
            if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
            || (s[i] >= '0' && s[i] <= '9')))
                return false;
        return true;
    }
    if(ngay){
        if(s.size() != 10)
            return false;
        for(int i=0; i<10; i++)
            if(!((s[i] >= 48 && s[i] <= 57) || s[i] == '/'))
                return false;
        if(s.substr(0, 2) > "31" || s[2] != '/' || s.substr(3, 2) > "12" || s[5] != '/' || s.substr(6) < "1")
            return false;
        return true;
    }
}
string chuyen_doi(int n){
    string s;
    while(n != 0){
        s.insert(s.begin(), n%10 + 48);
        n /= 10;
    }
    return s;
}
int chuyen_doi(string s){
	int kq = 0;
	for(int i=0; i<s.size(); i++)
		kq = kq*10 + s[i] - 48;
	return kq;
}
string chuan_hoa(string s){
	string k = s;
	while(k[0] == 32)
		k.erase(0, 1);
	k.push_back(32);
	if(k[0] >= 'A' && k[0] <= 'Z')
		k[0] += 32;
	for(int i=0; i<k.size() - 1; i++){
		if(k[i] == 32){
			if(k[i+1] == 32){
				k.erase(i, 1);
				i--;
			}else if(k[i+1] >= 'A' && k[i+1] <= 'Z')
				k[i+1] += 32;		
		}
	}
	while(k[k.size() - 1] == 32)
		k.erase(k.size() - 1, 1);
	return k;
}
LDMS* tim_kiem(LDMS* head, string ma){
    for(LDMS* i=head; i != NULL; i=i->next)
        if(i->data.Ma == ma)
            return i;
    return NULL;
}
void them(LDMS* &head, string key, int n, int set_x, int set_y){
	if(head == NULL){
		LDMS* p =new LDMS;
		p->data.Ma = key + chuyen_doi(n);
		p->data.TrangThai = "0";
		p->data.ViTri = "";
		gotoXY(set_x, set_y);
		cout << left << setw(15) << p->data.Ma << setw(20) << p->data.TrangThai;
		ve_o(set_x - 3, set_y - 1, 15); ve_o(set_x - 3 + 15, set_y - 1, 20); ve_o(set_x - 3 + 35, set_y - 1, 15);
		p->next = NULL;
		head = p;
	}else
		them(head->next, key, n, set_x, set_y);
}
int xuat(LDMS* head, int x, int y){
	int j = 0;
	gotoXY(x, y += 2);
	TextColor(tieu_de);
	cout << left << setw(15) << "Ma" << setw(20) << "Trang thai" << setw(20) << "Vi tri";
	TextColor(7);
	ve_o(x - 3, y - 1, 15);ve_o(x - 3 + 15, y - 1, 20); ve_o(x - 3 + 35, y - 1, 20);
    for(LDMS*i = head; i!= NULL; i=i->next){
    	j++;
    	gotoXY(x, y += 2);
    	cout << left << setw(15) << i->data.Ma << setw(20) << i->data.TrangThai << setw(20) << i->data.ViTri;
    	ve_o(x - 3, y - 1, 15);ve_o(x - 3 + 15, y - 1, 20); ve_o(x - 3 + 35, y - 1, 20);
	}
	return j;
}
// dau sach
bool nhap(DauSach& x, int set_x, int set_y){
	TextColor(7);
	ve_o(toa_do_x - 3, toa_do_y + 2*1, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*2, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*3, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*4, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*5, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*6, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*7, 40);
	int dong = 1;
	TextColor(tieu_de);
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "ISBN: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "Ten sach: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "So trang: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "Tac gia: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "Nha xuat ban: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "The loai: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "Nhap so luong cuon: ";
    dong = 1;
    TextColor(7);
    gotoXY(toa_do_x + 7, toa_do_y + 1 +  2*dong); dong++;
    fflush(stdin);
    string s;
    getline(cin, x.ISBN);
    if(check(x.ISBN, 0, 0, 1, 0) == false){
    	gotoXY(toa_do_x + 7, toa_do_y + 1 +  2*10);
    	TextColor(loi);
    	cout << "ISBN khong hop le!";
    	return false;
	}
    gotoXY(toa_do_x + 10, toa_do_y + 1 +  2*dong); dong++;
    getline(cin, x.TenSach);
    if(check(x.TenSach, 1, 0, 0, 0) == false){
    	gotoXY(toa_do_x + 7, toa_do_y + 1 +  2*10);
    	TextColor(loi);
    	cout << "Ten sach khong hop le!";
    	return false;
	}
	gotoXY(toa_do_x + 10, toa_do_y + 1 +  2*dong); dong++;
    getline(cin, s);
    if(check(s, 0, 1, 0, 0) == false){
    	gotoXY(toa_do_x + 7, toa_do_y + 1 +  2*10);
    	TextColor(loi);
    	cout << "So trang khong hop le!";
    	return false;
	}
	x.SoTrang = chuyen_doi(s);
	gotoXY(toa_do_x + 10, toa_do_y + 1 +  2*dong); dong++;
    getline(cin, x.TacGia);
    if(check(x.TacGia, 1, 0, 0, 0) == false){
    	gotoXY(toa_do_x + 7, toa_do_y + 1 +  2*10);
    	TextColor(loi);
    	cout << "Ten tac gia khong hop le!";
    	return false;
	}
	gotoXY(toa_do_x + 14, toa_do_y + 1 +  2*dong); dong++;
    getline(cin, x.NXB);
    if(check(x.NXB, 1, 0, 0, 0) == false){
    	gotoXY(toa_do_x + 7, toa_do_y + 1 +  2*10);
    	TextColor(loi);
    	cout << "Nha xuat ban khong hop le!";
    	return false;
	}
	gotoXY(toa_do_x + 10, toa_do_y + 1 +  2*dong); dong++;
    getline(cin, x.TheLoai);
    if(check(x.TheLoai, 1, 0, 0, 0) == false){
    	gotoXY(toa_do_x + 7, toa_do_y + 1 +  2*10);
    	TextColor(loi);
    	cout << "The loai khong hop le!";
    	return false;
	}
	x.head = NULL; // chua co ban sao chep
	gotoXY(toa_do_x + 20, toa_do_y + 1 +  2*dong); dong++;
    int num; cin >> num;
    gotoXY(toa_do_x + 50, toa_do_y + 5);
    TextColor(tieu_de);
    cout << left << setw(15) << "Ma sach" << setw(20) << "Trang thai" << setw(20) << "Vi tri";
    TextColor(7);
	ve_o(toa_do_x - 3 + 50, toa_do_y + 5 - 1, 15); ve_o(toa_do_x - 3 + 15 + 50, toa_do_y + 5 - 1, 20); ve_o(toa_do_x - 3 + 35 + 50, toa_do_y + 5 - 1, 15);
    for(int i=0; i<num; i++){
    	them(x.head, x.ISBN, i, toa_do_x + 50, toa_do_y + 7 + 2*i);
	}
	int j = 0;
	for(LDMS* i = x.head; i!= NULL; i=i->next){
		gotoXY(toa_do_x + 85, toa_do_y + 7 + 2*j);
		fflush(stdin);
		getline(cin, i->data.ViTri);
		j++;
	}
	TextColor(7);
    return true;
}
void doc_file(DauSach* A[200], int &n){
	n = 0;
	ifstream cin("./DauSach.txt");
	DauSach x;
	while(1){
		if(!(cin >> x.ISBN)){
			return;
		}
		cin.ignore();
		getline(cin, x.TenSach);
		cin >> x.SoTrang;
		cin.ignore();
		getline(cin, x.TacGia);
		getline(cin, x.NXB);
		getline(cin, x.TheLoai);
		int m; cin >> m;
		x.head = NULL;
		LDMS* p;
		for(int i=0; i<m; i++){
			DMS y;
			cin >> y.Ma >> y.TrangThai >> y.ViTri;
			if(i == 0){
				p = new LDMS;
				p->data = y;
				p->next = NULL;
				x.head = p;
			}else{
				LDMS* q = new LDMS;
				q->data = y;
				q->next = NULL;
				p->next = q;
				p = q;
			}
		}
		A[n] = new DauSach;
		*A[n++] = x;
	}
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(A[i]->TenSach > A[j]->TenSach){
				DauSach t = *A[i];
				*A[i] = *A[j];
				*A[j] = t;
			}
}
bool cap_nhat(DauSach &a){
    DauSach x = a;
    string s;
    fflush(stdin);
    cout << "Ten sach: ";
    getline(cin, x.TenSach);
    if(check(x.TenSach, 0, 0, 1, 0) == false){
    	cout << "Ten sach khong hop le!";
    	return false;
	}
	cout << "So trang: ";
    getline(cin, s);
    if(check(s, 0, 0, 1, 0) == false){
    	cout << "So trang khong hop le!";
    	return false;
	}
	x.SoTrang = chuyen_doi(s);
	cout << "Tac gia: ";
    getline(cin, x.TacGia);
    if(check(x.TacGia, 0, 0, 1, 0) == false){
    	cout << "Ten tac gia khong hop le!";
    	return false;
	}
	cout << "Nha xuat ban: ";
    getline(cin, x.NXB);
    if(check(x.NXB, 0, 0, 1, 0) == false){
    	cout << "Nha xuat ban khong hop le!";
    	return false;
	}
	cout << "The loai: ";
    getline(cin, x.TheLoai);
    if(check(x.TheLoai, 0, 0, 1, 0) == false){
    	cout << "The loai khong hop le!";
    	return false;
	}
    a = x;
    return true;
}
int tim_kiem_ma(DauSach* A[200], int n, string ma){
    for(int i=0; i<n; i++)
        if(A[i]->ISBN == ma)
            return i;
    return -1;
}
int tim_kiem_ten(DauSach* A[200], int n, string ten, int x, int y){
    int d = y;
    char c;
    for(int i=0; i<n; i++){
    	if(chuan_hoa(A[i]->TenSach).find(ten) != -1){
    		system("cls");
    		y = d;
    		gotoXY(x + 30, y+=2);
    		TextColor(tieu_de);
		    cout << "Danh sach dau sach: " << ten;
		    TextColor(7);
		    ve_o(x - 3, y - 1, 105);
		    gotoXY(x, y+=2);
		    TextColor(tieu_de);
		    cout << left << setw(15) << "ISBN" << setw(30) << "Ten sach" 
		    << setw(20) << "Tac gia" << setw(20) << "Nha xuat ban" << setw(20) << "The loai";
		    TextColor(7);
            ve_o(x - 3, y - 1, 15); ve_o(x - 3 + 15, y - 1, 30); ve_o(x - 3 + 45, y - 1, 20);
			ve_o(x - 3 + 65, y - 1, 20); ve_o(x - 3 + 85, y - 1, 20);
			gotoXY(x, y+=2);
            cout << left << setw(15) << A[i]->ISBN << setw(30) << A[i]->TenSach 
            << setw(20) << A[i]->TacGia << setw(20) << A[i]->NXB << setw(20) << A[i]->TheLoai;
            ve_o(x - 3, y - 1, 15); ve_o(x - 3 + 15, y - 1, 30); ve_o(x - 3 + 45, y - 1, 20);
			ve_o(x - 3 + 65, y - 1, 20); ve_o(x - 3 + 85, y - 1, 20);
			y += 1;
			gotoXY(x + 15, y+=2);
			TextColor(tieu_de);
		    cout << left << setw(15) << "Ma sach" << setw(20) << "Trang thai" << setw(20) << "Vi tri" ;
		    TextColor(7);
            ve_o(x - 3 + 15, y - 1, 15); ve_o(x - 3 + 15 + 15, y - 1, 20); ve_o(x - 3 + 35 + 15, y - 1, 20);
			for(LDMS* j=A[i]->head; j != NULL; j = j->next){
            	gotoXY(x + 15, y+=2);
            	cout << left << setw(15) << j->data.Ma << setw(20) << j->data.TrangThai << setw(20) << j->data.ViTri;
            	ve_o(x - 3 + 15, y - 1, 15); ve_o(x - 3 + 15 + 15, y - 1, 20); ve_o(x - 3 + 35 + 15, y - 1, 20);
			}
			gotoXY(x, y + 6);
			TextColor(7);
			cout << "sang phai: chuyen tiep, sang trai: quay lai, esc: thoat";
            getch();
            c = getch();
            switch(c){
				case 75:{
					i = -1;
					break;
				}
				case 27:{
					return 1;
				}
			}
        }
	}
    return d;
}
int danh_sach_theo_the_loai(DauSach* A[200], int n, string the_loai, int x, int y){
    int d = 0;
    gotoXY(x + 30, y+=2);
    TextColor(tieu_de);
    cout << "Danh sach dau sach the loai: " << the_loai;
    TextColor(7);
    ve_o(x - 3, y - 1, 105);
    gotoXY(x, y+=2);
    TextColor(tieu_de);
    cout << left << setw(15) << "ISBN" << setw(30) << "Ten sach" 
    << setw(20) << "Tac gia" << setw(20) << "Nha xuat ban" << setw(20) << "The loai";
    TextColor(7);
    ve_o(x - 3, y - 1, 15); ve_o(x - 3 + 15, y - 1, 30); ve_o(x - 3 + 45, y - 1, 20);
	ve_o(x - 3 + 65, y - 1, 20); ve_o(x - 3 + 85, y - 1, 20);
    for(int i=0; i<n; i++)
        if(chuan_hoa(A[i]->TheLoai).find(the_loai) != -1){
        	gotoXY(x, y+=2);
            cout << left << setw(15) << A[i]->ISBN << setw(30) << A[i]->TenSach 
            << setw(20) << A[i]->TacGia << setw(20) << A[i]->NXB << setw(20) << A[i]->TheLoai;
            ve_o(x - 3, y - 1, 15); ve_o(x - 3 + 15, y - 1, 30); ve_o(x - 3 + 45, y - 1, 20);
			ve_o(x - 3 + 65, y - 1, 20); ve_o(x - 3 + 85, y - 1, 20);
            d++;
        }
    return d;
}
bool cap_nhat(DauSach* A[200], int n){
    string s;
    cout << "Nhap ma: ";
    fflush(stdin);
    getline(cin, s);
    if(check(s, 0, 0, 1, 0) == false)
        return false;
    int index = tim_kiem_ma(A, n, s);
    if(index == - 1)
        return false;
    return cap_nhat(*A[index]);
}
void them(DauSach* A[200], int &n, DauSach x){
    A[n] = new DauSach;
    for(int i=0; i<n; i++)
        if(A[i]->TenSach > x.TenSach){
            for(int j=n; j>i; j--)
                *A[j] = *A[j-1];
            *A[i] = x;
            return;
        }
    *A[n] = x;
    n++;
}
// muon tra
bool nhap(MuonTra &x){
    fflush(stdin);
    getline(cin, x.Ma);
    if(check(x.Ma, 0, 0, 1, 0) == false)
        return false;
    getline(cin, x.NgayMuon);
    if(check(x.NgayMuon, 0, 0, 0, 1) == false)
        return false;
    x.NgayTra = " ";
    getline(cin, x.TrangThai);
    if(x.TrangThai != "0" && x.TrangThai != "1" && x.TrangThai != "2" )
        return false;
    return true;
}
bool tra(MuonTra& x){
    string s;
    fflush(stdin);
    getline(cin, s);
    if(check(s, 0, 0, 0, 1) == false)
        return false;
    x.NgayTra = s;
    x.TrangThai = 1;
}
void them(LMuonTra*& head, MuonTra x){
	if(head == NULL){
		head = new LMuonTra;
		head->data = x;
		head->next = NULL;
	}else
		them(head->next, x);
}
int xuat(LMuonTra* head, int set_x, int set_y, string ngay, int d){
	int dem = 0;
	int j = -1;
	gotoXY(set_x, set_y + 4 + j*2);
	TextColor(tieu_de);
	cout << left << setw(15) << "Ma" << setw(20) << "Ngay muon" << setw(20) << "Ngay tra" << setw(15) << "Trang thai";
	TextColor(7);
	ve_o(set_x - 3, set_y + 4 + j*2 - 1, 15); ve_o(set_x - 3 + 15, set_y + 4 + j*2 - 1, 20);
	ve_o(set_x - 3 + 35, set_y + 4 + j*2 - 1, 20); ve_o(set_x - 3 + 55, set_y + 4 + j*2 - 1, 20);
	for(LMuonTra* i = head; i != NULL; i = i->next){
		j++;
		if(j == d)
			TextColor(11);
		gotoXY(set_x, set_y + 4 + j*2);
		cout << left << setw(15) << i->data.Ma << setw(20) << i->data.NgayMuon << setw(20) << i->data.NgayTra << setw(15) << i->data.TrangThai;
		TextColor(7);
		ve_o(set_x - 3, set_y + 4 + j*2 - 1, 15); ve_o(set_x - 3 + 15, set_y + 4 + j*2 - 1, 20);
		ve_o(set_x - 3 + 35, set_y + 4 + j*2 - 1, 20); ve_o(set_x - 3 + 55, set_y + 4 + j*2 - 1, 20);
		if(i->data.TrangThai == "0" && tru_ngay(i->data.NgayMuon, ngay) > 7)
			dem += 5;
		if(i->data.TrangThai == "2")
			dem++;
	}
	if(d == -1)
		return dem;
	else
		return j;
}

// doc gia
bool nhap(DocGia &x){
	system("cls");
	TextColor(7);
	ve_o(toa_do_x - 3, toa_do_y, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*1, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*2, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*3, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*4, 40);
	int dong = 0;
	TextColor(tieu_de);
	gotoXY(toa_do_x + 5, toa_do_y + 1 +  2*dong); dong++;	cout << "Nhap thong tin";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "Ho: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "Ten: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "Phai: ";
    gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;	cout << "Trang thai: ";
    dong = 1;
    TextColor(7);
    gotoXY(toa_do_x + 4, toa_do_y + 1 +  2*dong); dong++;
	fflush(stdin);	getline(cin, x.Ho);
	if(check(x.Ho, 1, 0, 0, 0) == false){
		gotoXY(toa_do_x + 7, toa_do_y +  2*6);
		TextColor(loi);
		cout << "Ho khong hop le!";
		return false;
	}
	gotoXY(toa_do_x + 5, toa_do_y + 1 +  2*dong); dong++;
	getline(cin, x.Ten);
	if(check(x.Ten, 1, 0, 0, 0) == false){
		gotoXY(toa_do_x + 7, toa_do_y +  2*6);
		TextColor(loi);
		cout << "Ten khong hop le!";
		return false;
	}
	gotoXY(toa_do_x + 6, toa_do_y + 1 +  2*dong); dong++;
	getline(cin, x.Phai);
	if(x.Phai != "Nam" && x.Phai != "Nu"){
		gotoXY(toa_do_x + 7, toa_do_y +  2*6);TextColor(loi);
		cout << "Phai khong hop le!";
		return false;
	}
	gotoXY(toa_do_x + 12, toa_do_y + 1 +  2*dong); dong++;
	getline(cin, x.TrangThai);
	if(x.TrangThai != "0" && x.TrangThai != "1"){
		gotoXY(toa_do_x + 7, toa_do_y +  2*6);
		TextColor(loi);
		cout << "Trang thai khong hop le!";
		return false;
	}
	x.head = NULL;
	return true;
}
bool cap_nhat(DocGia &a){
	DocGia x = a;
	if(nhap(x) == false){
		return false;
	}
	a = x;
	return true;
}
void xuat(DocGia x){
	system("cls");
	int dong = 0;
	TextColor(7); // doi mau chu
	ve_o(toa_do_x - 3, toa_do_y, 40); // ve 1 o 
	ve_o(toa_do_x - 3, toa_do_y + 2*1, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*2, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*3, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*4, 40);
	ve_o(toa_do_x - 3, toa_do_y + 2*5, 40);
	TextColor(tieu_de);
	gotoXY(toa_do_x + 8, toa_do_y + 1 +  2*dong); dong++;cout << left << setw(15) << "Thong tin ban doc"; // ham setw(n) tuc la tao 1 o n khoang de in du lieu
	gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;cout << left << setw(15) << "Ma: " << x.MaThe;
	gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;cout << left << setw(15) << "Ho: " << x.Ho;
	gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;cout << left << setw(15) << "Ten: " << x.Ten;
	gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;cout << left << setw(15) << "Phai: " << x.Phai;
	gotoXY(toa_do_x, toa_do_y + 1 +  2*dong); dong++;cout << left << setw(15) << "Tinh trang: " << x.TrangThai;
	getch(); // bam phim de tiep tuc
	TextColor(7);
}
Tree* tim_kiem(Tree* root, int ma){
	if(root != NULL){
		if(root->data.MaThe == ma)
			return root;
		if(root->data.MaThe > ma)
			return tim_kiem(root->left, ma);
		if(root->data.MaThe < ma)
			return tim_kiem(root->right, ma);
	}
	return NULL;
}
void them(Tree*& root, DocGia x){
	if(root != NULL){
		if(root->data.MaThe > x.MaThe)
			them(root->left, x);
		if(root->data.MaThe < x.MaThe)
			them(root->right, x);
	}else{
		root = new Tree;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}
}
void doc_file(Tree*& root){
	root = NULL;
	ifstream cin("./DocGia.txt");
	DocGia x;
	while(1){
		if(!(cin >> x.MaThe))
			break;
		cin.ignore();
		getline(cin, x.Ho);
		getline(cin, x.Ten);
		cin >> x.Phai >> x.TrangThai;
		x.head = NULL;
		them(root, x);
	}
	cin.close();
}
void doc_file_muon_tra(Tree* root){
	ifstream cin("./MuonTra.txt");
	while(1){
		int ma;
		if(!(cin >> ma))
			return;
		Tree* p = tim_kiem(root, ma);
		int m;
		cin >> m;
		//cout << m << endl;
		for(int i=0; i <m; i++){
			MuonTra muon_tra;
			cin >> muon_tra.Ma >> muon_tra.NgayMuon >> muon_tra.TrangThai;
			//cout << muon_tra.Ma >> muon_tra.NgayMuon >> muon_tra.TrangThai;
			if(muon_tra.TrangThai != "1")
				muon_tra.NgayTra = "";
			else
				cin >> muon_tra.NgayTra;
			them(p->data.head, muon_tra);
		}
	}
	cin.close();
}
void phai_cung(Tree*& root, Tree*& la){
	if(la->right == NULL){
		root->data = la->data;
		la = la->left;
	}else
		phai_cung(root, la->right);
}
bool xoa(Tree* &root, int ma){
	if(root == NULL)
		return false;
	if(root->data.MaThe > ma)
		return xoa(root->left, ma);
	if(root->data.MaThe < ma)
		return xoa(root->right, ma);
	if(root->left == NULL)
		root = root->right;
	else if(root->right == NULL)
		root = root->left;
	else{
		phai_cung(root, root->left);
	}
	return false;
}
void danh_sach_theo_ma(Tree* root, int x, int &y){ // LNR
	if(root !=NULL){
		danh_sach_theo_ma(root->left, x, y);
		gotoXY(x, y+=2);
		cout << left << setw(15) << root->data.MaThe << setw(20) << root->data.Ho << setw(20) << root->data.Ten
		<< setw(15) << root->data.Phai << setw(15) << root->data.TrangThai;
		ve_o(x - 3, y - 1, 15); ve_o(x - 3 + 15, y - 1, 20); ve_o(x - 3 + 35, y - 1, 20); ve_o(x - 3 + 55, y - 1, 15); ve_o(x - 3 + 70, y - 1, 15);
		danh_sach_theo_ma(root->right, x, y);
	}
}
void danh_sach_theo_ten1(Tree* root, DocGia *a, int &n){
	if(root !=NULL){
		a[n] = root->data;
		n++;
		danh_sach_theo_ten1(root->left, a, n);
		danh_sach_theo_ten1(root->right, a, n);
	}
}
void danh_sach_theo_ten(Tree* root, int x, int y){
	int n = 0;
	DocGia a[1000];
	danh_sach_theo_ten1(root, a, n);
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(a[i].Ten > a[j].Ten || (a[i].Ten == a[j].Ten && a[i].Ho > a[i].Ho)){
				DocGia t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	for(int i=0; i<n; i++){
		gotoXY(x, y + 1 + 2*i);
		cout << left << setw(15) << a[i].MaThe << setw(20) << a[i].Ho << setw(20) << a[i].Ten
		<< setw(15) << a[i].Phai << setw(15) << a[i].TrangThai;
		ve_o(x - 3, y + 2*i, 15); ve_o(x - 3 + 15, y + 2*i, 20); ve_o(x - 3 + 35, y + 2*i, 20); ve_o(x - 3 + 55, y + 2*i, 15); ve_o(x - 3 + 70, y + 2*i, 15);
	}
}
void danh_sach_yeu_thich(Tree* root, DauSach* A[200], int n, int x, int y){
	string ma = "";
	queue <Tree*> BFS;
	BFS.push(root);
	while(!(BFS.empty())){
		Tree* p = BFS.front();
		//cout << p->data.MaThe << endl;
		for(LMuonTra* ii =p->data.head; ii != NULL; ii=ii->next)
			ma += " " + ii->data.Ma;
		if(p->left != NULL)
			BFS.push(p->left);
		if(p->right != NULL)
			BFS.push(p->right);
		BFS.pop();
	}
	int so_luong[200];
	for(int i=0; i<n; i++){
		so_luong[i] = 0;
		while(1){
			int index = ma.find(A[i]->ISBN);
			if(index != -1){
				so_luong[i]++;
				ma.erase(index, A[i]->ISBN.size());
			}else
				break;
		}
	}
	system("cls");
	int d = y;
	gotoXY(x + 30, y+=2);
	TextColor(tieu_de);
    cout << "Top 10 dau sach duoc yeu thich";
    TextColor(7);
    ve_o(x - 3, y - 1, 105);
    gotoXY(x, y+=2);
    TextColor(tieu_de);
    cout << left << setw(15) << "ISBN" << setw(30) << "Ten sach" 
    << setw(20) << "Tac gia" << setw(20) << "Nha xuat ban" << setw(20) << "The loai";
    TextColor(7);
    ve_o(x - 3, y - 1, 15); ve_o(x - 3 + 15, y - 1, 30); ve_o(x - 3 + 45, y - 1, 20);
	ve_o(x - 3 + 65, y - 1, 20); ve_o(x - 3 + 85, y - 1, 20);
	for(int j=0; j<10 && j < n; j++){
		int max = -1;
		for(int i=0; i<n; i++){
			if(max == -1 || so_luong[i] > so_luong[max])
				max = i;
		}
		if(max == -1)
			break;
		so_luong[max] = -1;
		gotoXY(x, y+=2);
        cout << left << setw(15) << A[max]->ISBN << setw(30) << A[max]->TenSach 
        << setw(20) << A[max]->TacGia << setw(20) << A[max]->NXB << setw(20) << A[max]->TheLoai;
        ve_o(x - 3, y - 1, 15); ve_o(x - 3 + 15, y - 1, 30); ve_o(x - 3 + 45, y - 1, 20);
		ve_o(x - 3 + 65, y - 1, 20); ve_o(x - 3 + 85, y - 1, 20);
	}
}
void danh_sach_qua_han(Tree* root, string day, int x, int y){
	y+= 2;
	gotoXY(x + 30, y);
	TextColor(tieu_de);
    cout << "Danh sach muon qua han";
	x -= 10;
	TextColor(7);
    ve_o(x- 3, y - 1, 100);
    gotoXY(x, y+=2);
    TextColor(tieu_de);
    cout << left << setw(15) << "Ma the" << setw(20) << "Ho" << setw(20) << "Ten"
	<< setw(15) << "Phai" << setw(15) << "Trang thai" << "Ngay qua han";
	TextColor(7);
    ve_o(x- 3, y- 1, 15); ve_o(x- 3 + 15, y- 1, 20); ve_o(x- 3 + 35, y- 1, 20);
	ve_o(x- 3 + 55, y- 1, 15); ve_o(x- 3 + 70, y- 1, 15); ve_o(x- 3 + 85, y- 1, 15);
	queue <Tree*> BFS;
	BFS.push(root);
	DocGia a[200];
	int n = 0;
	while(!(BFS.empty())){
		Tree* p = BFS.front();
		//cout << p->data.MaThe << endl;
		a[n] = p->data;
		n++;
		if(p->left != NULL)
			BFS.push(p->left);
		if(p->right != NULL)
			BFS.push(p->right);
		BFS.pop();
	}
	int day_muon[200];
	for(int i=0; i<n; i++){
		day_muon[i] = -1;
		for(LMuonTra* ii=a[i].head; ii!= NULL; ii=ii->next){
			if(ii->data.TrangThai == "0")
				day_muon[i] = tru_ngay(ii->data.NgayMuon, day);
		}
	}
	for(int i=0; i<n; i++){
		int max = -1;
		for(int j=0; j<n; j++){
//			cout << day_muon[j] << endl;
//			getch();
			if(max == -1 || day_muon[j] > day_muon[max ] )
				max = j;
		}
		if(max == -1 || day_muon[max] < 1)
			break;
		gotoXY(x, y+=2);
		cout << left << setw(15) << a[max].MaThe << setw(20) << a[max].Ho << setw(20) << a[max].Ten
		<< setw(15) <<a[max].Phai << setw(15) << a[max].TrangThai << day_muon[max];
		ve_o(x - 3, y - 1, 15); ve_o(x - 3 + 15, y - 1, 20); ve_o(x - 3 + 35, y - 1, 20); 
		ve_o(x - 3 + 55, y - 1, 15); ve_o(x - 3 + 70, y - 1, 15); ve_o(x - 3 + 85, y - 1, 15);
		day_muon[max] = -1;	
	}
}
