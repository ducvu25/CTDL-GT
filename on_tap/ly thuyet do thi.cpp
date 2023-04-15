#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int** InPut(int &n, char *s){
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
    cin.close();
    return a;
}
bool Huong(int **a, int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i != j && a[i][j] != a[j][i])
                return true;
    return false;
}
int soCanh(int **a, int n, bool huong){
	int canh = 0;
	if(huong == false)
		for(int i=0; i<n; i++)
	        for(int j=i; j<n; j++)
				canh += a[i][j];
	else
		for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
				canh += a[i][j];
    return canh;
}
int soDinhCoCanhBoi(int **a, int n, bool huong){
	int count = 0;
	if(huong == false){
		for(int i=0; i<n-1; i++)
			for(int j=i; j<n; j++)
				if(a[i][j] > 1)
					count++;
	}
	else{
		for(int i=0; i<n-1; i++)
			for(int j=0; j<n; j++)
				if(a[i][j] > 1 && i != j)
					count++;
	}
	return count;
}
int soCanhKhuyen(int **a, int n){
    int count = 0;
    for(int i=0; i<n; i++)
        count += a[i][i];
    return count;
}
void soDinhTreoCoLap(int **a, int n, int &treo, int &coLap, bool huong){
	treo = 0, coLap = 0;
	for(int i=0; i<n; i++){
		int bac = 0;
		if(huong == true){
			int vao = 0, ra = 0;
			for(int j = 0; j<n; j++){
				vao += a[j][i];
				ra += a[i][j];
			}
			bac = vao + ra;
		}else{
			for(int j = 0; j<n; j++)
				bac += a[i][j];
		}
		if(bac == 1)
			treo++;
		if(bac == 0)
			coLap++;	
	}
}
void yG(int **a, int n, bool huong){
	if(huong)
		cout << "(Bac vao - Bac ra) cua tung dinh:\n";
	else
		cout << "Bac cua tung dinh:\n";
	for(int i=0; i<n; i++)
		if(huong){
			int vao = 0, ra = 0;
			for(int j=0; j<n; j++){
				vao += a[j][i];
				ra += a[i][j];
			}
			cout << i << "(" << vao << "-" << ra << ") ";
		}else{
			int bac = 0;
			for(int j=0; j<n; j++)
				if(i == j)
					bac += a[i][j]*2;
				else
					bac += a[i][j];
			cout << i << "(" << bac << ") ";
		}
	cout << endl;
}
void yH(int **a, int n, bool huong){
	if(huong){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(a[i][j] > 1){
					cout << "Da do thi co huong";
					return;
				}
		cout << "Do thi co huong";
	}else{
		int daDoThi = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				if(a[i][j] > 1)
					daDoThi = 1;
				if(daDoThi == 1 && a[i][j] != 0){
					cout << "Gia do thi";
					return;
				}
			}
		if(daDoThi == 1)
			cout << "Da do thi";
		else
			cout << "Don do thi";
	}
}
int main(){
    int n;
    int **a = InPut(n, "./input.txt");
    if(n <= 2)
    	return 0;
    cout << n << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    bool huong = Huong(a, n);
    if(huong)
        cout << "Do thi co huong\n";
    else    
        cout << "Do thi vo huong\n";
	
	cout << "So dinh cua do thi la: " << n << endl;
	cout << "So canh cua do thi la: " << soCanh(a, n, huong) << endl;
    cout << "So cap dinh xuat hien canh boi: " << soDinhCoCanhBoi(a, n, huong) << endl;
    cout << "So canh khuyen: " << soCanhKhuyen(a, n) << endl;
    int treo, coLap;
    soDinhTreoCoLap(a, n, treo, coLap, huong);
    cout << "So dinh treo: " << treo << endl;
    cout << "So dinh co lap: " << coLap << endl;
    yG(a, n, huong);
    yH(a, n, huong);
	return 0;
}
