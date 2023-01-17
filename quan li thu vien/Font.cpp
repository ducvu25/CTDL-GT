#include"Font.h"
using namespace std;

void TextColor(int color) { // do mau chu
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y) { // di chuyen con chuot toi vi tri x, y
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void menu_1(int x, int y, int d){
    string ten[] = {"Menu", "Quan li", "Doc gia", "Dau sach", "Cac nut: mui ten len/xuong: di chuyen, enter: chon, esc: thoat"};
    TextColor(7);
    for(int i=0; i<4; i++){
        gotoXY(x + (i == 0)*5, y + 1 + 2*i);
        cout << ten[i];
        ve_o(x - 3, y + 2*i, 20);
    }
    gotoXY(x, y + 15);
    cout << ten[4];
    TextColor(11);
    gotoXY(x, y + 1 + 2*d);
    cout << ten[d];
}
void menu_2(int x, int y, int d){
    d--;
    TextColor(7);
    string ten[] = {"Them doc gia", "Xoa doc gia", "Chinh thong tin", "Danh sach theo ten", "Danh sach theo ma", "Black list"};
    ve_o(x - 3, y - 2, 45);
    gotoXY(x + 15, y - 1);
    cout << "Quan li";
    for(int i=0; i<3; i++){
        gotoXY(x, y + 1 + 2*i);
        cout << ten[i];
        gotoXY(x + 20, y + 1 + 2*i);
        cout << ten[i + 3];
        ve_o(x - 3, y + 2*i, 20);
        ve_o(x + 17, y + 2*i, 25);
    }
    gotoXY(x, y + 15);
    cout << "Cac nut: mui ten len/xuong: di chuyen, enter: chon, esc: thoat";
    TextColor(11);
    if(d > 2)
        gotoXY(x + 20, y + 1 + 2*(d - 3));
    else
        gotoXY(x, y + 1 + 2*d);
    cout << ten[d];
}
void menu_3(int x, int y, int d){
    d--;
    TextColor(7);
    string ten[] = {"Muon sach", "Tra sach", "Tra cuu"};
    ve_o(x - 3, y - 2, 20);
    gotoXY(x + 2, y - 1);
    cout << "Doc gia";
    for(int i=0; i<3; i++){
        gotoXY(x, y+ 1 + 2*i);
        cout << ten[i];
        ve_o(x - 3, y + 2*i, 20);
    }
    gotoXY(x, y + 15);
    cout << "Cac nut: mui ten len/xuong: di chuyen, enter: chon, esc: thoat";
    TextColor(11);
    gotoXY(x, y + 1 + 2*d);
    cout << ten[d];
}
void menu_4(int x, int y, int d){
    d--;
    TextColor(7);
    string ten[] = {"Nhap sach", "Danh sach theo the loai", "Tim kiem", "Top 10 sach muon nhieu"};
    ve_o(x - 3, y - 2, 30);
    gotoXY(x + 5, y - 1);
    cout << "Quan ly dau sach";
    for(int i=0; i<4; i++){
        gotoXY(x, y+1 + 2*i);
        cout << ten[i];
        ve_o(x - 3, y + 2*i, 30);
    }
    gotoXY(x, y + 15);
    cout << "Cac nut: mui ten len/xuong: di chuyen, enter: chon, esc: thoat";
    TextColor(11);
    gotoXY(x, y + 1 + 2*d);
    cout << ten[d];
}
void ve_o(int x, int y, int d){ // goc trai tren va do dai, chieu rong = 1
    gotoXY(x, y);       cout << "+";
    gotoXY(x, y+2);     cout << "+";
    gotoXY(x + d, y);   cout << "+";
    gotoXY(x + d, y + 2);cout << "+";
    gotoXY(x, y+1);     cout << "|";
    gotoXY(x + d, y+1); cout << "|";

    for(int i = 1; i< d; i++){
        gotoXY(x+i, y);
        cout << "-";
        gotoXY(x+i, y+2);
        cout << "-";
    }
}
