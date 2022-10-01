#include <iostream>
#include <string>
#include <math.h>
using namespace  std;

int StringInt(string s){
    int d = 1;
    if(s[0] == '-'){
        s.erase(0, 1);
        d = -1;
    }
    int kq = 0;
    for(int i=0; i<s.size(); i++)
        kq = kq*10 + (s[i] - 48);
    return kq*d;
}
float StringFloat(string s){
    int index = s.find(".");
    if(index == -1)
        return StringInt(s);
    if(index == s.size() - 1){
        s.erase(s.size() - 1, 1);
        return StringInt(s);
    }
    int d = 1;
    if(s[0] == '-'){
        s.erase(0, 1);
        d = -1;
    }
    float kq = StringInt(s.substr(0, index - 1));
    cout << kq << endl;
    kq += 1.0*StringInt(s.substr(index))/pow(10, s.size() - index);
    return kq*d;
}
string IntString(int n){
    int d = 1;
    if(n < 0){
        d = -1;
        n *= -1;
    }
    string kq;
    while(n != 0){
        char x = n % 10 + 48;
        kq.insert(kq.begin(), x);
        n /= 10;
    }
    if(d == -1)
        kq = "-" + kq;
    return kq;
}
string FloatString(float x){
    int d = 1;
    if(x < 0){
        d = -1;
        x *= -1;
    }
    string kq = IntString(int(x));
    x -= int(x);
    x *= 10000;
    if(d == 1)
        return kq + "." + IntString(int(x));
    else    
        return "-" + kq + "." + IntString(int(x));
}
struct Node{
    string value;
    Node* next;
};
void Push(Node* &Stack, string s){
    Node* p = new Node;
    p->value = s;
    p->next = Stack;
    Stack = p;
}
void Pop(Node* &Stack){
    Node* p = Stack;
    Stack = Stack->next;
    delete p;
}
void Xuat(Node* Stack){
    for(Node* i = Stack; i != NULL; i = i->next)
        cout << i->value << " ";
    cout << endl;
}
void TinhToan(Node* &Stack){
    float x2 = StringFloat(Stack->value);   Pop(Stack);
    string c = Stack->value;    Pop(Stack);
    float x1 = StringFloat(Stack->value);   Pop(Stack);
    cout << "\n" << x1 << " " << c << " " << x2 << " " << endl;
    if(c == "+")
        Push(Stack, FloatString(x1 + x2));
    if(c == "-")
        Push(Stack, FloatString(x1 - x2));
    if(c == "/")
        Push(Stack, FloatString(x1 / x2));
    if(c == "*")
        Push(Stack, FloatString(x1 * x2));
}
string KQ(string s){
    Node* Stack = NULL;
    int dau = 0;
    s += " ";
    for(int i=0; i<s.size(); i++){
        if((s[i] == ' ' && s[i-1] != ')') || s[i] == ')'){
            Xuat(Stack);
            if(i != dau)
                Push(Stack, s.substr(dau, i - dau));
            dau = i + 1;
            if(s[i] == ')')
                TinhToan(Stack);
            Xuat(Stack);
            cout << endl;
        }else if(s[i] == '(')
            dau = i + 1;
    }
    while(Stack->next != NULL)
        TinhToan(Stack);
    return Stack->value;
}
int main(){
    // 12 + (5 * 6 + (12 - 1))
    //cout << KQ("11. * 6 + 5 + 12");
    cout << KQ("12 + (5 + 6 - (12 - 1))");
    //cout << StringFloat("11.");
    // Node* Stack = NULL;
    // Push(Stack, "12");
    // Push(Stack, "+");
    // Push(Stack, "5");
    // Push(Stack, "+");
    // Push(Stack, "6");
    // Push(Stack, "*");
    // Push(Stack, "11.");
    // while(Stack->next != NULL){
    //     TinhToan(Stack);
    //     Xuat(Stack);
    // }

    return 0;
}

