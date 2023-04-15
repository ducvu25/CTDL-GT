#include <iostream>

using namespace std;

int main(){
    int t, n;
    long p, k;
    cin >> t;
    for(int test=0; test < t; test++){
        cin >> n >> k >> p;
        long *a = new long[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        int count = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if((a[i]*a[i] + a[j]*a[j] + a[i]*a[j]) % p == k)
                    count++;
        cout << count << endl;
    }
    return 0;  
} 
/*
2
4 1 2
3 2 1 0
8 0 3
9 2 1 8 4 5 9 10
*/

