#include "giaoDien.h"
#define setColorTable 7
#define setColorText 11
#define setColorMenu1 12
#define setColorMenu0 14
#define setX 30
#define setY 5
#define TbX 30
#define TbY 20
using namespace std;

void TextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y) { // x la ngang, y la doc
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void VeBang(int x, int y, char* tieuDe[100], int* tableSize, int m, int n) {
	m++;
    int len = 0;
    m += 1;
    TextColor(setColorText);
    for (int j = 1; j <= n; j++) {
        gotoXY(x + len + 3, y + 1);
        cout << tieuDe[j - 1];
        len += tableSize[j - 1];
    }
    TextColor(setColorTable);
    for (int i = 0; i < m; i++) {
        len = 0;
        if(i < m - 1){
        	gotoXY(x + len + 1, y + 2 * i + 1);
        	cout << char(179);
		}
        for (int j = 0; j < n; j++) {
            // ve bang
            if(i < m - 1){
			    if (j == n - 1)
			        gotoXY(x + len + tableSize[j], y + 2 * i + 1);
			    else
			        gotoXY(x + len + tableSize[j] + 1, y + 2 * i + 1);
			    cout << char(179);
			}
            gotoXY(x + len, y + 2 * i);
            for (int k = 0; k < tableSize[j]; k++) {
                len++;
                gotoXY(x + len, y + i * 2);
                cout << char(196); // -
                gotoXY(x + len, y + i * 2);
                if (i == 0) {// dòng đầu tiên
                    if (len == 1) // góc trái trên
                        cout << char(218);
                    else if (k == 0) // vị trí cắt
                        cout << char(194);
                    if (j == n - 1 && k == tableSize[j] - 1) // góc phải trên
                        cout << char(191);
                }
                else if (i == m - 1) { // dong cuoi cung
                    if (len == 1) // góc trái trên
                        cout << char(192);
                    else if (k == 0) // vị trí cắt
                        cout << char(193);
                    else if (j == n - 1 && k == tableSize[j] - 1) // góc phải trên
                        cout << char(217);
                }
                else {
                    if (len == 1) // góc trái trên
                        cout << char(195);
                    else if (k == 0) // vị trí cắt
                        cout << char(197);
                    else if (j == n - 1 && k == tableSize[j] - 1) // góc phải trên
                        cout << char(180);
                }
            }
        }
    }
}
void VeBang2(int x, int y, char** tieuDe, int* tableSize, int m, int n) {
    char** Tieude = new char* [n + 1];
    int* Tablesize = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        Tieude[i] = new char[100];
    }
    Tablesize[0] = 5;
    strcpy(Tieude[0], "STT");
    for (int i = 1; i < n + 1; i++) {
        strcpy(Tieude[i], tieuDe[i - 1]);
        Tablesize[i] = tableSize[i - 1];
    }

    VeBang(x, y, Tieude, Tablesize, m, n + 1);
}
int menu(int d) {
	int denta = 15;
	system("cls");
	TextColor(11);
	Vao(setX - 15 + denta, setY -5);
	ChuThich(TbX, TbY + 2);
    string *s = new string[7];
    int n = 0;
    int dodai;
    char** tieuDe = new char* [1];
    tieuDe[0] = new char[100];
    strcpy(tieuDe[0], " \0");
    switch(d){
        case 0: {
            int size[] = { 30 };
            VeBang(setX  + denta, setY, tieuDe, size, 4, 1);
            dodai = 15;
            s[0] = "Menu";
            s[1] = "Quan ly mon hoc";
            s[2] = "Quan ly lop tin chi";
            s[3] = "Quan ly danh sach sinh vien";
            s[4] = "Thoat";
            n = 5;
            break;
        }
        case 1: {
            int size[] = { 28 };
            VeBang(setX + denta, setY, tieuDe, size, 3, 1);
            dodai = 15;
            s[0] = "Quan ly mon hoc";
            s[1] = "Dieu chinh mon hoc";
            s[2] = "In danh sach mon hoc";
            s[3] = "Thoat";
            n = 4;
            break;
        }
        case 2: {
            int size[] = { 36 };
            VeBang(setX + denta, setY, tieuDe, size, 6, 1);
            dodai = 18;
            s[0] = "Quan ly lop tin chi";
            s[1] = "Dieu chinh lop tin chi";
            s[2] = "Dang ky lop";
            s[3] = "Huy lop";
            s[4] = "Nhap diem";
            s[5] = "Xuat thong tin";
            s[6] = "Thoat";
            n = 7;
            break;
        }
        case 3: {
            int size[] = { 36 };
            VeBang(setX + denta, setY, tieuDe, size, 5, 1);
            dodai = 18;
            s[0] = "Quan ly sinh vien";
            s[1] = "Dieu chinh thong tin";
            s[2] = "In danh sach lop";
            s[3] = "Thong tin diem trung binh";
            s[4] = "Thong tin diem tong ket";
            s[5] = "Thoat";
            n = 6;
            break;
        }
        case 4: {
            int size[] = { 30 };
            VeBang(setX  + denta, setY, tieuDe, size, 4, 1);
            dodai = 15;
            s[0] = "Sua doi thong tin";
            s[1] = "Them du lieu";
            s[2] = "Xoa du lieu";
            s[3] = "Sua du lieu";
            s[4] = "Thoat";
            n = 5;
            break;
        }
        case 5: {
            int size[] = { 36 };
            VeBang(setX  + denta, setY, tieuDe, size, 4, 1);
            dodai = 18;
            s[0] = "Thong ke";
            s[1] = "In thong tin bang diem";
            s[2] = "Thong ke diem trung binh";
            s[3] = "Bang diem tong ket";
            s[4] = "Thoat";
            n = 5;
            break;
        }
    }
    TextColor(setColorMenu0);
    for (int i = 0; i < n; i++) {
        gotoXY(setX + dodai - s[i].size() / 2  + denta, setY + 2 * i + 1);
        cout << s[i];
    }
    TextColor(setColorMenu1);
    gotoXY(setX + dodai - s[1].size() / 2  + denta, setY + 2 + 1);
    cout << s[1];

    int dk = 1;
    char c;
    while (1) {
        if (kbhit()) {
            c = getch();
            switch (c) {
                case 13: { // phim enter
                    system("cls");
                    if(dk == n - 1)
                        return 0;
                    return dk;
                }
                case 72: { // len
                    dk--;
                    if (dk == 0)
                        dk = n - 1;
                    break;
                }
                case 80: { // xuong
                    dk++;
                    if (dk == n)
                        dk = 1;
                    break;
                }
            }
            TextColor(setColorMenu0);
            for (int i = 0; i < n; i++) {
                gotoXY(setX + dodai - s[i].size() / 2  + denta, setY + 2 * i + 1);
                cout << s[i];
            }
            TextColor(setColorMenu1);
            gotoXY(setX + dodai - s[dk].size() / 2  + denta, setY + 2 * dk + 1);
            cout << s[dk];
        }
    }
}
void Loading(int x, int y, int time) {
    gotoXY(x, y + 2);
    cout << "Loading";
    for (int i = 0; i < 9; i++) {
        gotoXY(x + i % 3 + strlen("Loading"), y + 2);
        cout << ".   ";
        Sleep(time);
    }
}
void ChuThich(int x, int y) {
    TextColor(11);
    gotoXY(x + 8, y);
	cout << "Enter: chon - Mui ten len/xuong: di chuyen tro chuot";
}
void Vao(int x, int y){
    gotoXY(x, y + 0); cout << " ___                  _        ___  _       _          _           ";
    gotoXY(x, y + 1); cout << "| . | _ _  ___ ._ _  | | _ _  / __><_>._ _ | |_   _ _ <_> ___ ._ _ ";
    gotoXY(x, y + 2); cout << "| | || | |<_> || ' | | || | | \\__ \\| || ' || . | | | || |/ ._>| ' |";
    gotoXY(x, y + 3); cout << "`___\\`___|<___||_|_| |_|`_. | <___/|_||_|_||_|_| |__/ |_|\\___.|_|_|";
    gotoXY(x, y + 4); cout << "                        <___'                                      ";
}
