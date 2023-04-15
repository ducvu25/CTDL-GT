#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[i] + a[j] == k){
                cout << "YES";
                return 0;
            }
    cout << "NO";
    return 0;
}