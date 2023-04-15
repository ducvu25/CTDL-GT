#include <iostream>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <MMsystem.h>

using namespace std;

// ------ setting ----
int soMin;
int sizeTable;
int setUpX = 30;
int setUpY = 2;
int setColorText = 11;
int setColorTable = 13;
int setColorBom = 4;
int setColorNumber[]  = {15, 14, 11, 10, 12, 6, 3, 8};
// ô mìn = -2, ô trống 0, ô số 1, 2, ..., ô đã mở -1 
void TextColor(int color);
void gotoXY(int x, int y);
void KhoiTao(int** a);
void VeBan();
void MoRong(int**a, int x, int y);
void GoiY(int **a);
void Play(int **a);
void End(int**a);
int Win(int **a);

int main(){
    gotoXY(setUpX + 10, 0);		cout << "Nhap so min: "; cin >> soMin;
    TextColor(11); gotoXY(setUpX + 5, 1); cout << "Trung Duc - K66 - UET";
    sizeTable = sqrt(soMin + 4 - (soMin % 4))*3;
    VeBan();
    int** a = new int*[sizeTable];
    for(int i=0; i<sizeTable; i++)
        a[i] = new int[sizeTable];
    KhoiTao(a);
    Play(a);
    return 0;
}
void TextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STDOUTPUTHANDLE), color);
}
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STDOUTPUTHANDLE), coord);
}
void KhoiTao(int** a){
	srand(time(0));
    int n = sizeTable + 2, count = 0;
    int** b = new int*[n];
    for(int i=0; i<n; i++)
        b[i] = new int[n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            b[i][j] = 0;
    while(count <= soMin){
        int xx = rand() %sizeTable;
        int yy = rand() %sizeTable;
        if(b[xx][yy] == 0 && xx > 0 && xx < n - 1 && yy > 0 && yy < n - 1){
            count++;
            b[xx][yy] = -2;
        }
    }
    for(int i=1; i<n-1; i++)
        for(int j=1; j<n-1; j++){
            if(b[i][j] == 0){
                count = 0;
                for(int t1=-1; t1<2; t1++)
                    for(int t2=-1; t2<2; t2++)
                        if(b[i+t1][j+t2] == -2)
                            count++;
                b[i][j] = count;
            }
            a[i-1][j-1] = b[i][j];
        }
}
void VeBan(){
    for(int i=0; i<=sizeTable*2; i++)
        for(int j=0; j<=sizeTable*2; j++){
        	TextColor(setColorTable);
            gotoXY(setUpX + i, setUpY + j);
            if(i % 2 == 0)
                if(j % 2 == 0)
                    cout << char (197); // +
                else    
                    cout << char (179); // |
            else{
                if(j % 2 == 0)
                    cout << char (196); // -
                else{
                	TextColor(15);
                	cout << char (178); // o
				}
            }
        }
}
void MoRong(int**a, int x, int y){
	for(int i=-1; i<2 && x + i >= 0 && x + i < sizeTable; i++)
		for(int j=-1; j<2 && y + j >= 0 && y + j < sizeTable; j++)
            if(a[x + i][y + j] == 0){
                gotoXY(setUpX + 2*(x + i) + 1, setUpY + 2*(y + j) + 1); 
                cout << " ";
                a[x + i][y + j] = -1;
                MoRong(a, x + i, y + j);
            }
}
void GoiY(int **a){
	int count = 0;
	while(count <= soMin/2){
		int i = rand() %sizeTable;
        int j = rand() %sizeTable;
        if(a[i][j] != -1 && a[i][j] != -2 && a[i][j] != 0){
        	count++;
            TextColor(setColorNumber[a[i][j] - 1]);
            gotoXY(setUpX + 2*(i) + 1, setUpY + 2*(j) + 1); cout << a[i][j];
            a[i][j] = -1;
		}
	}
}
void Play(int **a){
 //   PlaySound(TEXT("NgayTho.wav"), NULL, SNDASYNC);
    char c;
    GoiY(a);
    int i = sizeTable/2;
    int j = sizeTable/2;
	while(1){
		if(kbhit()){
            c = getch();
            switch (c){
                case 'w':{
                    j--;
                    if(j == -1)
                        j = sizeTable - 1;
                    break;
                }
                case 'a':{
                    i--;
                    if(i == -1)
                        i = sizeTable - 1;
                    break;
                }
                case 'd':{
                    i++;
                    if(i == sizeTable)
                        i = 0;
                    break;
                }
                case 'x':{
                    j++;
                    if(j == sizeTable)
                        j = 0;
                    break;
                }
                case 's':{
                	gotoXY(setUpX + 2*(i) + 1, setUpY + 2*(j) + 1);
                    switch (a[i][j]){
                        case -2:
                        	TextColor(setColorBom);
                        	cout << "*";
                        	End(a);
                            return;
                        case -1:
                            break;
                        case 0:
                            TextColor(15);
                            MoRong(a, i, j);
                            break;
                        default:
		                    TextColor(setColorNumber[a[i][j] - 1]);
		                    cout << a[i][j];
		                    a[i][j] = -1;
		                    break;
                    }
                    if(Win(a) == 1){
                    	TextColor(13);
                    	gotoXY(setUpX + sizeTable, setUpY + sizeTable);	cout << "YOU WIN!";
                    	return;
					}
                }
            }
            gotoXY(setUpX + 2*(i) + 1, setUpY + 2*(j) + 1);
        }
	}
}
void End(int** a){
	for(int i=0; i<sizeTable; i++)
		for(int j=0; j<sizeTable; j++)
			if(a[i][j] != -1){
				Sleep(50);
				switch (a[i][j]){
				case -2:
                    TextColor(setColorBom);
                    gotoXY(setUpX + 2*(i) + 1, setUpY + 2*(j) + 1); cout << "*";
                    break;
                case 0:
                    TextColor(15);
                    gotoXY(setUpX + 2*(i) + 1, setUpY + 2*(j) + 1); cout << " ";
                    MoRong(a, i, j);
                    a[i][j] = -1;
                    break;
                default:
                    TextColor(setColorNumber[a[i][j] - 1]);
                    gotoXY(setUpX + 2*(i) + 1, setUpY + 2*(j) + 1); cout << a[i][j];
                    a[i][j] = -1;
                    break;
            }
		}
	Sleep(1500);
	gotoXY(setUpX + sizeTable, setUpY + sizeTable);	cout << "GAME OVER!";
}
int Win(int **a){
	for(int i=0; i<sizeTable; i++)
		for(int j=0; j<sizeTable; j++)
			if(a[i][j] >= 0)
				return 0;
	return 1;
}
