#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<vector>
using namespace std;

void tao_test(int n){
    ofstream cout("./input.txt");
    for(int i=0; i<n; i++){
        int dau = rand() %5;
        int gia_tri = rand() %(n/2);
        if(dau == 2)
            cout << -gia_tri << " ";
        else
            cout << gia_tri << " ";
    }
}
int Index(int *a, int left, int right){
    int value = a[right];
    int count = 0;
    for(int i=left; i<right; i++)
        if(a[i] <= value)
            count++;

    int index = left + count;
    swap(a[index], a[right]);

    int i = left, j = right;
    while(i < index && j > index){
        while(a[i] <= value)
            i++;
        while(a[j] > value)
            j--;
        if(i < index && j > index)
            swap(a[i++], a[j--]);
    }
    return index;
}
void QSort(int* a, int left, int right){
    if(left < right){
        int index = Index(a, left, right);
        QSort(a, left, index - 1);
        QSort(a, index + 1, right);
    }
}
int* tron(int*a, int *b, int n, int m){
    int x =0, y = 0; // chỉ số của mảng a, b
    int* kq = new int[m + n]; // bảng kq
    for(int i=0; i<m+n; i++){ // thực hiện trộng
        if(y >= m || (x < n && a[x] < b[y])) // nếu mảng b đã hết phần tử hoặc giá trị của a[x] < b[y] và mảng a chưa hết phần tử 
            kq[i] = a[x++]; // thực hiện gán và tăng chỉ số mảng a
        else // trường hợp còn lại gán bảng b và tăng chỉ số mảng b
            kq[i] = b[y++]; 
    }
    return kq;
}
bool Buoc2(char* tb1, char* tb2, char* ta1, char* ta2, int m){
    ifstream cin1(tb1);
    ifstream cin2(tb2);
    int file = 1;
    int *TB1 = new int[m]; int size1 = 0;
    int *TB2 = new int[m]; int size2 = 0;
    int x;
    ofstream cout3(ta1);
    ofstream cout4(ta2);
    int lan = 0;
    while(1){// vòng lặp vô hạn
        while(cin1 >> x){ // đọc ở file tb1 m phần tử hoặc đến hết
            TB1[size1++] = x;
            if(size1 == m)
                break;
        }
        while(cin2 >> x){ // đọc ở file tb2 m phần tử hoặc đến hết
            TB2[size2++] = x;
            if(size2 == m)
                break;
        }
        if(lan == 0 && size2 == 0){ // nếu ngay từ đầu file tb2 đã hết phần tử thì trả về false - không cần thực hiện nữa
            cin1.close();
            cin2.close();
            cout3.close();
            cout4.close();
            return false;
        }
        lan++;
        if(size1 == 0 && size2 == 0) // nếu đã đọc hết 2 file thì dừng
            break;
        int* TB12 = tron(TB1, TB2, size1, size2); // thực hiện trộn 2 bảng vừa nhận được
        int size = size1+size2;
        if(file == 1){ // nếu biến file bằng 1 tiến hành lưu vào file ta1
            for(int i=0; i<size; i++)
                cout3 << TB12[i] << " ";
            file = 0;
        }else{ // nếu biến file bằng 0 tiến hành lưu vào file ta2
            for(int i=0; i<size; i++)
                cout4 << TB12[i] << " ";
            file = 1;
        } // cap nhat lai size
        size1 = 0;
        size2 = 0;
    }
    cin1.close();
    cin2.close();
    cout3.close();
    cout4.close();
    return true;
}
void Sort(int m){
    char tb1[] = "tb1.txt";
    char tb2[] = "tb2.txt";
    char ta1[] = "ta1.txt";
    char ta2[] = "ta2.txt";

    ifstream cin("input.txt");
    ofstream cout1(tb1);
    ofstream cout2(tb2);

    int* a = new int[m];
    int n = 0;
    int x, file = 1;
    while(cin >> x){ // doc hết file input
        if(n < m){ // đọc m phần tử vào mảng a
            a[n++] = x;
        }
        if(n == m){ // khi đủ m phần tử
            QSort(a, 0, n - 1); // sắp xếp rồi in lần lượt vào các file tb1 tb2
            if(file == 1){ 
                for(int i=0; i<n; i++)
                    cout1 << a[i] << " ";
                file = 0;
            }else{
                for(int i=0; i<n; i++)
                    cout2 << a[i] << " ";
                file = 1;
            }
            n = 0;
        }
    }
    // xét TH đọc hết file nhưng không đủ m phần tử
    QSort(a, 0, n - 1);
    if(file == 1){
        for(int i=0; i<n; i++)
            cout1 << a[i] << " ";
    }else{
        for(int i=0; i<n; i++)
            cout2 << a[i] << " ";
    }
    cout1.close();
    cout2.close();
    int lap = 1;
    system("pause");
    // 3 6 12 24
    // thực hiện trộn ở B2
    while(1){
        if(Buoc2(tb1, tb2, ta1, ta2, lap*m)){
            system("pause");
            lap *= 2;
            if(Buoc2(ta1, ta2, tb1, tb2, lap*m)){
                lap *= 2;
            }else{
                cout << ta1;
                break;
            }
        }else{
            cout << tb1;
            break;
        }
    }
}
int main(){
    int m;
    cout << "Nhap m: "; cin >> m;
    Sort(m);
    return 0;
}