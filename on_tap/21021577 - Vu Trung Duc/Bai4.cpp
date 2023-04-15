#include <iostream>

using namespace std;

void Swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
void Sort(int* a, int n){
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[i] > a[j])
                Swap(a[i], a[j]);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    Sort(a, n);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";
}
