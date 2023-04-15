#include <iostream>
#include <iomanip>
using namespace std;

class Point{
private:
    float x;
    float y;
public:
    void Gan(float a, float b){
        this->x = a;
        this->y = b;
    }
    float X(){
        return this->x;
    }
    float Y(){
        return this->y;
    }
};
class Line{
private:
    float a;
    float b;
public:
    void XacDinh(Point x, Point y){
        this->a = (x.Y() - y.Y())/(x.X() - y.X());
        this->b = x.Y() - this->a*x.X();
    }
    float A(){
        return this->a;
    }
    float B(){
        return this->b;
    }
    void Xuat(){
    	cout << "y = " << this->a << "x + " << this->b << endl;
	}
    void giaoDiem(Line d2){
        if(this->A() == d2.A() && this->B() != d2.B())
            cout << "Khong co diem chung\n";
        else if(this->A() == d2.A() && this->B() == d2.B())
            cout << "Trung nhau\n";
        else {
            float x, y;
            x = (d2.B() - this->B())/(this->A() - d2.A());
            y = this->A()*x + this->B();
            cout << fixed << setprecision(2) << "(" << x << "," << y << ")";
        }
    }
};
int main(){
    Point X[4];
    for(int i=0; i<4; i++){
        float x, y;
        cin >> x >> y;
        X[i].Gan(x, y);
    }
    Line d1, d2;
    d1.XacDinh(X[0], X[1]);
    d1.Xuat();
    d2.XacDinh(X[2], X[3]);
    d2.Xuat();
    d1.giaoDiem(d2);
}
