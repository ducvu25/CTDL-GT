#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<vector>
using namespace std;


// I. Kiem tra
bool Check_nguyen_to(int n){
    if(n < 2)
        return false;
    for(int i=2; i<=sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}
bool Check_so_dep(int n){
    int m = 0;
    for(int i=2; i<=sqrt(n); i++)
        if(n%i == 0){
            if(n/i == i)
                m += i;
            else
                m += i + n/i;
        }
    return m + 1 == n;
}
bool Check_fbnc(int n){
    int a = 0,
        b = 1, c;
    do{
        c = a + b;
        a = b;
        b = c;
    }while(c < n);
    return c == n;
}
int UCLN(int a, int b){
    if(b == 0)  return a;
    return UCLN(b, a%b);
}
int BCNN(int a, int b){
    return a*b/UCLN(a, b);
}

// II. 
void Nhap_mang(float* a, int size){
    cout << "Nhap " << size << " phan tu:\n";
    for(int i=0; i<size; i++)
        cin >> a[i];
}

void Xuat_mang(float* array, int size){
    for(int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void Them_mang(float* array, int &size,float k, int x){
    if(x > size)
        x = size;
    if(x < 0)
        x = 0;
    for(int i = size; i>x; i--)
        array[i] = array[i-1];
    array[x] = k;
    size++;
}

void Xoa_mang(float* array, int &size, int x){
    if(x > size)
        x = size;
    if(x < 0)
        x = 0;
    size--;
    for(int i=x; i<size; i++)
        array[i] = array[i+1];
}

int Tim_kiem_mang(float* a, int size,float k){
    for(int i=0; i<size; i++)
        if(a[i] == k)
            return i + 1;
    return -1;
}

void Sort_mang(float* a, int size, bool tang_dan){
    for(int i=0; i<size-1; i++)
        for(int j=i+1; j<size; j++)
            if(a[i] > a[j] == tang_dan){
               float t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

// III.

float** Nhap_matrix(int m, int n){
    float** a = new float*[m];
    for(int i=0; i<m; i++)
        a[i] = new float[n];
    cout << "Nhap ma tran " << m << " x " << n << ":\n";
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    return a;
}

void Xuat_matrix(float** a, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

float** Cong_matrix(float** a, float** b, int m, int n){
    float** c = new float*[m];
    for(int i=0; i<m; i++)
        c[i] = new float[n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

float** Tru_matrix(float** a, float** b, int m, int n){
    float** c = new float*[m];
    for(int i=0; i<m; i++)
        c[i] = new float[n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            c[i][j] = a[i][j] - b[i][j];
    return c;
}

float** Nhan_matrix(float** a, float** b, int m, int n, int p){
    float** c = new float*[m];
    for(int i=0; i<m; i++)
        c[i] = new float(p);
    for(int i=0; i<m; i++)
        for(int j=0; j<p; j++){
            c[i][j] = 0;
            for(int k=0; k<n; k++)
                c[i][j] += a[i][k]*b[k][j];
        }
    return c;
}
void Tinh_toan(char c){
    int m1, n1;
    cout << "Nhap kich thuoc ma tran A: "; cin >> m1 >> n1; 
    float** matrix_1; matrix_1 = Nhap_matrix(m1, n1);

    int m2, n2;
    cout << "Nhap kich thuoc ma tran B: "; cin >> m2 >> n2; 
    float** matrix_2; matrix_2 = Nhap_matrix(m2, n2);
    cout << "A " << c << " B = \n";
    switch(c){
        case '+':{
            if(m1 != m2 || n1 != n2)
                cout << "Kich thuoc khong hop le!\n";
            else{
                Xuat_matrix(Cong_matrix(matrix_1, matrix_2, m1, n1), m1, n1);
            }
            break;
        }
        case '-':{
            if(m1 != m2 || n1 != n2)
                cout << "Kich thuoc khong hop le!\n";
            else{
                Xuat_matrix(Tru_matrix(matrix_1, matrix_2, m1, n1), m1, n1);
            }
            break;
        }
        case '*':{
            if(n1 != m2)
                cout << "Kich thuoc khong hop le!\n";
            else{
                Xuat_matrix(Nhan_matrix(matrix_1, matrix_2, m1, n1, n2), m1, n2);
            }
            break;
        }
    }
}

void Xoa_cot(float** &a, int m, int &n, int x){
    n--;
    if(n == 0)
        a = NULL;
    else{
        if(x > n)
            x = n;
        if(x < 0)
            x = 0;
        for(int i=0; i<m; i++)
            for(int j=x; j<n; j++)
                a[i][j] = a[i][j+1];
    }
}

void Xoa_hang(float** &a, int &m, int n, int y){
    m--;
    if(m == 0)
        a = NULL;
    else{
        if(y > m)
            y = m;
        if(y < 0)
            y = 0;
        for(int i=y; i<m; i++)
            for(int j=0; j<n; j++)
                a[i][j] = a[i+1][j];
    }
}

float** Chen_cot(float** a, int m, int &n,float k, int x){
    float** b = new float*[m];
    for(int i=0; i<m; i++)
        b[i] = new float[n + 1];
    if(x > n)
        x = n;
    if(x < 0)
        x = 0;
    n++;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(j<x)
                b[i][j] = a[i][j];
            else if(j == x)
                b[i][j] = k;
            else
                b[i][j] = a[i][j-1];
    return b;
}

float** Chen_hang(float** a, int &m, int n,float k, int y){
    float** b = new float*[m];
    for(int i=0; i<m + 1; i++)
        b[i] = new float[n];
    if(y > m)
        y = m;
    if(y < 0)
        y = 0;
    m++;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(i<y)
                b[i][j] = a[i][j];
            else if(i == y)
                b[i][j] = k;
            else
                b[i][j] = a[i-1][j];
    return b;
}

void Sort_cot(float** a, int m, int n, int x){
    if(x > n)
        x = n;
    if(x < 0)
        x = 0;
    for(int i=0; i<m-1; i++)
        for(int j=i+1; j<m; j++)
        if(a[i][x] > a[j][x]){
           float t = a[i][x];
            a[i][x] = a[j][x];
            a[j][x] = t;
        }
}

void Sort_hang(float** a, int m, int n, int y){
    if(y > m)
        y = m;
    if(y < 0)
        y = 0;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
        if(a[y][i] > a[y][j]){
           float t = a[y][i];
            a[y][i] = a[y][j];
            a[y][j] = t;
        }
}
int Tan_suat(string &s, string s1){
    int so_luong = 0;
    while(s.find(s1) != -1){
        so_luong++;
        s.erase(s.find(s1), s1.size());
    }
    return so_luong;
}
void Tan_suat(string s){
    s += " ";
    int i = 0;
    while(s.size() != 1){
        if(s[i] == ' '){
            cout << s.substr(0, i);
            cout << " " << Tan_suat(s, s.substr(0, i)) << endl;
            cout << s << endl;
            i = 0;
        }else
            i++;
    }
}

// IV.
void Chuan_hoa_ten(string &s){
    while(s[0] == 32)
		s.erase(0, 1);
	while(s[s.size() - 1] == 32)
		s.erase(s.size() - 1, 1);
    if(s[0] >= 'a' && s[0] <= 'z')
        s[0] -= 32;
    for(int i=0; i<s.size(); i++)
        if(s[i] == 32){
            if(s[i+1] == 32){
                s.erase(i, 1);
                i--;
            } else if(s[i+1] >= 'a' && s[i+1] <= 'z')
                s[i+1] -= 32;
        }else if(s[i+1] >= 'A' && s[i+1] <= 'Z')
            s[i+1] += 32;      
}
void Chuan_hoa_ngay(string &s){
	string s1, s2, s3;
	s1 = s.substr(0, s.find("/"));
	s.erase(0, s.find("/") + 1);
	s2 = s.substr(0, s.find("/"));
	s.erase(0, s.find("/") + 1);
	if(s1.size() == 1)
		s1 = "0" + s1;
	if(s2.size() == 1)
		s2 = "0" + s2; 
	s = s1 + "/" + s2 + "/" + s;
}
void Chuan_hoa_gio(string &s){
	string s1;
	if(s.size() == 1){
		s = "0" + s + ":00";
		return;
	}else if(s.size() == 2){
		s = s + ":00";
		return;
	}
	s1 = s.substr(0, s.find(":"));
	s.erase(0, s.find(":") + 1);
	if(s1.size() == 1)
		s1 = "0" + s1;
	if(s.size() == 1)
		s = s1 + ":0" + s;
	else
		s = s1 + ":" + s;
}
void Thay_the(string &s, string s1, string s2){
    while(s.find(s1) != -1){
        int index = s.find(s1);
        s = s.substr(0, index) + s2 + s.substr(index + s1.size());
    }
}
void Xoa_chuoi(string &s, string s1){
    while(s.find(s1) != -1){
        int index = s.find(s1);
        s = s.substr(0, index) + s.substr(index + s1.size());
    }
}
