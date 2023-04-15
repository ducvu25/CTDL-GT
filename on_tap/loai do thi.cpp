#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int** InPut(int &n, char* s){
    ifstream cin;
	cin.open(s);
    cin >> n;
    int **a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n];
    if(n <= 2)
    	return a;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    return a;
}
// do thi day du => tat ca phai noi voi nhau
// do thi chinh quy => cung bac
int Bac(int **a, int n, int x){
	int bac = 0;
	for(int i=0; i<n; i++)
		bac += a[x][i];
	return bac;
}
int KiemTra(int **a, int n, int &chinhQuy){
	chinhQuy = Bac(a, n, 0);
	int kq = 1;
	for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        	if(a[i][j] == 0 && i != j){
        		kq = 0;
        		goto End;
			}
	End:
	for(int i=1; i<n; i++)
		if(chinhQuy != Bac(a, n, i)){
			chinhQuy = -1;
			break;
		}
    return kq;
}
int main(){
	int n;
    int **a = InPut(n, "./input.txt");
    if(n <= 2)
    	return 0;
    int chinhQuy;
	int kq = KiemTra(a, n, chinhQuy);
    if(kq == 1)
    	cout << "Day la do thi day du K" << n << endl;
    else
    	cout << "Day khong phai do thi day du\n";
    if(chinhQuy != -1)
    	cout << "Day la do thi " << chinhQuy << "-chinh quy\n";
    else
    	cout << "Day khong phai do thi chinh quy\n";
    
    if(kq == 0 && chinhQuy == 2)
    	cout << "Day la do thi vong C" << n;
    else
    	cout << "Day khong phai do thi vong";   
}

