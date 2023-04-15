#include <iostream>
#include <conio.h>
#include <stdarg.h>

using namespace std;

int Sum(int n, ...){
    valist vl;
    vastart(vl, n);
    int sum = 0;
    for(int i=0; i<n; i++){
        int value = vaarg(vl, int);
        sum += value;
    }
    vaend(vl);
    return sum;
}

int main(){
    cout << Sum(5, 1, 2, 3, 4, 5) << endl;
    cout << Sum(3, 1, 2, 3);
}
