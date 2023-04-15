#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* a = new int[n];
    int* f = new int[n];
    map <int, int> m;
    cin >> a[0];
    f[0] = a[0];
    for(int i=1; i<n; i++){
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    for(int i=0; i<n; i++) 
        for(int j=i; j < n; j++){
            int kq;
            if(i == 0)
                kq = f[j];
            else{
                if(j == i)
                    kq = f[j] - f[i-1];
                else
                    kq = f[j] - f[i - 1];
            }
            cout << i << " " << j << " " << kq << endl;
            if(!m[kq])
                m[kq] = 1;
            else    
                m[kq]++;
        }
    int sum = 0;
    for(map <int, int> :: iterator i = m.begin(); i != m.end(); i++){
        //cout << i->first << " " << i->second << endl;
        if(i->second == 1)
            sum += i->first;
        //cout << sum << endl << endl;
    }
            
    cout << sum;
}