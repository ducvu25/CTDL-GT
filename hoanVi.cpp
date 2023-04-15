#include <iostream>

using namespace std;
void hoanVi(int* check, int k, int n, int *a){
    for(int i=1; i<=n; i++){
        if(check[i] == 0){
            a[k] = i;
            check[i] = 1;
            if(k == n - 1){
                for(int i=0; i<n; i++)
                    cout << a[i];
                cout << endl;
            }else
                hoanVi(check, k+1, n, a);
            check[i] = 0;
        }
    }
}
void hoanVi2(int* check, int k, int n, int *a){
    for(int i=0; i<n; i++){
        if(check[i] == 0){
            a[k] = i;
            check[i] = 1;
            if(k == n - 1){
                for(int i=0; i<n; i++)
                    cout << a[i];
                cout << endl;
            }else
                hoanVi2(check, k+1, n, a);
            check[i] = 0;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int check[100] = {0};
    int a[100];
    hoanVi(check, 0, n, a);
    return 0;
}