#include <iostream>
#include <string>
using namespace std;

int KQ(string a){
	int min = a[0];
	int max = a[0];
	for(int i=1; i<a.size(); i++){
		max = max > a[i] ? max : a[i];
		min = min < a[i] ? min : a[i];
	}
	return max + min - 48*2;
}
int main(){
	string number;
	cin >> number;
	cout << KQ(number);
}
