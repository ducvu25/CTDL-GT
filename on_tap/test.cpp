#include <iostream>
#include <math.h>

using namespace std;

int C1(int n){
    int kq = 1;
    for(int i=0; i<n; i++)
        kq *= 2;
    return kq;
}
int C2(int n){
   int kq = 1;
   int mu = 0;
    while(mu < n){
        kq *= 4;
        mu +=2;
    }
    if(mu > n)
        return kq/2;
    return kq;
}
int main(){
    int n;
    cin >> n;
    cout << C1(n) << endl;
    cout << C2(n) << endl;
    return 1;
}