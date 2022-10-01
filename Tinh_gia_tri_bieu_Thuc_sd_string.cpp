#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

float ChuyenSangSo(string s) {
    int d = 1;
    if (s[0] == '-') {
        d = -1;
        s.erase(0, 1);
    }
    float kq = 0;
    int mu = 1;
    int start = int(s.find("."));
    if (start == -1)
        start = int(s.size());
    for (int i = start - 1; i >= 0; i--) {
        kq += (s[i] - 48) * mu;
        mu *= 10;
    }
    mu = 10;
    if (s.find(".") != -1)
        for (int i = start + 1; i < s.size(); i++) {
            kq += (float)(s[i] - 48) / mu;
            mu *= 10;
        }
    return kq*d;
}
string ChuyenSangXauI(int x) {
    if (x == 0)
        return "0";
    string s;
    if (x < 0) {
        s.push_back('-');
        x *= -1;
    }
    int n = int(log(x) / log(10));
    for (int i = 0; i <= n; i++) {
        s.push_back(char(x / pow(10, n - i) + 48));
        x -= (s[i] - 48) * (int)pow(10, n - i);
    }
    return s;
}
string ChuyenSangXauF(float x) {
    string s;
    if (x < 0) {
        s.push_back('-');
        x *= -1;
    }
    int t = int(x * 10000);
    s = s + ChuyenSangXauI(t / 10000);
    t %= 10000;
    s = s + "." + ChuyenSangXauI(t);
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0'){
        	s.erase(i, 1);
		}else
            break;
    }
    return s;
}

string Tinh1(string s) {
    vector <string> PhepTinh;
    s += " ";
    while (s.find(" ") != -1) {
        PhepTinh.push_back(s.substr(0, s.find(" ")));
        s.erase(0, s.find(" ") + 1);
    }
    while (PhepTinh.size() != 1) {
        for (int i = 0; i < PhepTinh.size(); i++) {
            float kq, x, y;
            if (PhepTinh[i] == "*" || PhepTinh[i] == "/") {
                x = ChuyenSangSo(PhepTinh[i - 1]);
                y = ChuyenSangSo(PhepTinh[i + 1]);
                if (PhepTinh[i] == "*")
                    kq = x * y;
                else
                    kq = x / y;
                PhepTinh[i - 1] = ChuyenSangXauF(kq);
                PhepTinh.erase(PhepTinh.begin() + i);
                PhepTinh.erase(PhepTinh.begin() + i);
                i--;
            }
        }
        for (int i = 0; i < PhepTinh.size(); i++) {
            float kq, x, y;
            if (PhepTinh[i] == "+" || PhepTinh[i] == "-") {
                x = ChuyenSangSo(PhepTinh[i - 1]);
                y = ChuyenSangSo(PhepTinh[i + 1]);
                if (PhepTinh[i] == "+")
                    kq = x + y;
                else
                    kq = x - y;
                PhepTinh[i - 1] = ChuyenSangXauF(kq);
                PhepTinh.erase(PhepTinh.begin() + i);
                PhepTinh.erase(PhepTinh.begin() + i);
                i--;
            }
        }
    }
    return PhepTinh[0];
}
string ThucHienTinh(string s) {
    while (s.find("(") != -1 || s.find(")") != -1) {
        int x = 0, y;
        y = int(s.find(")"));
        for (int i = y; i >= 0; i--)
            if (s[i] == '(') {
               x = i;
               break;
            }
        string s1 = s.substr(x + 1, y - x - 1);
        s.erase(x, y - x + 1);
        s.insert(x, Tinh1(s1));
        cout << s << endl;
    }
    return Tinh1(s);
}
int main()
{
    cout << "Nhap phep tinh: ";
    string s;
    //string s = "5 - 8 * 2 + 9 / 2 - 6";
     s = "12 + (5 * 6 + (12 - 1))";
    //s = "1 + 2 * ((3 - 4) / 5)";
    //getline(cin, s);
    cout << ThucHienTinh(s);
}

