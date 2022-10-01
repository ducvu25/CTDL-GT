/*
Cho bảng băm có kích thước M = 11, Hàm băm f(Key) = Key mod M.
Dùng phương pháp địa chỉ mở. Cho kết quả sau khi thêm vào bảng băm với các khóa
10, 22, 31, 4, 15, 28, 17, 88, 59 với 3 phương pháp xử lý đụng độ:
    + Dò tuyến tính - Linear probing
    + Dò bậc 2 - Quadratic probing
    + Băm kép với h2(Key) = (Key mod 19) + 1 // Double hashing
*/
#include <iostream>
using namespace std;

int SIZE = 11;

int HashTable(int Key){
    return Key % SIZE;
}
int HashTable_2(int Key){
    return (Key % 19) + 1;
}
int LinearProbing(int Key, int i){ // do tuyen tinh
    return (HashTable(Key) + i) % SIZE;
}
int QuadraticProbing(int Key, int i){
    return (HashTable(Key) + i*i) % SIZE;
}
int DoubleHashing(int Key, int i){
    return (HashTable(Key) + i*HashTable_2(Key)) % SIZE;
}
int main(){
    int a[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    for(int j=0; j<9; j++){
        int Key = a[j];
        cout << Key << endl;
        for(int i=0; i<SIZE; i++)
            cout << LinearProbing(Key, i) << " " << QuadraticProbing(Key, i) << " " << DoubleHashing(Key, i) << endl; 
        cout << endl;
    }
}