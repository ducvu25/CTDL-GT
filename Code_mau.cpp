#include <iostream>

using namespace std;

int LinearExhaustive(int* a, int n, int x){
    for(int i=0; i<n; i++)
        if(a[i] == x)
            return i;
    return -1;
}
int LinearSentinel(int* a, int n, int x){
    a[n] = x;
    int i = 0;
    while(1){
        if(a[i] == x){
            if(i < n)
                return i;
            else    
                return -1;
        }
        i++;
    }
}
int BinarySearch(int* a, int n, int x){
    int left = 0, right = n - 1, mid;
    while(left <= right){
        mid = (left + right)/2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] < x)
            left = mid + 1;
        else    
            right = mid - 1;
    }
    return -1;
}
int main(){
    int n;  cin >> n;
    int a[100];
    for(int i=0; i<n; i++)
        cin >> a[i];
    int x;  cin >> x;
    // thuật toán vét cạn: O(n)
    cout << "Vi tri cua " << x << " trong mang la: " << LinearExhaustive(a, n, x) << endl;
    // Thuật toán lính canh: O(n) nhưng nhanh hơn cách 1
    cout << "Vi tri cua " << x << " trong mang la: " << LinearSentinel(a, n, x) << endl;
    // Thuật toán tìm kiếm nhị phân: log2(n)
    cout << "Vi tri cua " << x << " trong mang la: " << BinarySearch(a, n, x) << endl;
}
/*
test
5
1 2 3 4 5
3
10 
1 2 3 4 5 5 6 7 8 9
-5
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
9
*/