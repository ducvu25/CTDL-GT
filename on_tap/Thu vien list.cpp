#include <iostream>
#include <list>

using namespace std;

int main(){
    list <int> l;
    l.pushback(1);
    l.pushback(2);
    l.pushback(3);
    l.pushback(4);
    l.pushfront(0);
    for(list <int> :: iterator it = l.begin(); it != l.end(); it++)
        cout << *it << " ";
    return 0;
}