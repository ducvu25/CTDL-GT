#include <iostream>
using namespace std;

int** Init(int m, int n){
    int** a = new int*[m];
    for(int i=0; i<m; i++)
        a[i] = new int[n];
    for(int i=0; i<n; i++)  
        for(int j=0; j<m; j++)
            a[j][i] = 0;
    return a;
}
int Count(int**a, int x, int y, int m, int n){
    int count = 0;
    for(int i=0; i<m; i++)
        if(a[i][y] == 0){
            count++;
            a[i][y] = 1;
        }
    for(int i=0; i<n; i++)
        if(a[x][i] == 0){
            count++;
            a[x][i] = 1;
        }
    return count;
}
int main(){
    int n, k;
    cin >> n >> k;
    int** a = Init(n, n);
    int soluong = n*n;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        soluong -= Count(a, x - 1, y - 1, n, n);
        cout << soluong << " ";
    }
    return 0;
}