#include <iostream>
#include <string>
using namespace std;

void daoNguoc(string &a){
    for(int i=0; i<a.size()/2; i++){
        char t = a[i];
        a[i] = a[a.size() - 1 - i];
        a[a.size() - 1 - i] = t;
    }
}
int main(){
    string a;
    getline(cin, a);
    daoNguoc(a);
    cout << a;
}
