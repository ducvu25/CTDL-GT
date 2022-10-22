#include<iostream>
#include<fstream>
#include<stack>
#include <vector>
using namespace std;

int** Nhap(int &n){
    ifstream cin("./input.txt");
    cin >> n;
    int** a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = 0;
    int x, m, y;
    for(int i=0; i<n; i++){
        cin >> m >> x;
        for(int j=0; j<m; j++){
            cin >> y;
            a[x][y] = 1;
        }
    }
    return a;
}
int** AT(int**b, int n){
    int** a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j] = b[j][i];
    return a;
}
void Xuat(int** a, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}
void Xuat(stack<int> head){
    while(!head.empty()){
        cout << head.top() << " ";
        head.pop();
    }
    cout << endl;
}
void DFS(int u, int**a, int n, int* check){
    check[u] = 1;
    for(int i=0; i<n; i++)
        if(a[u][i] == 1 && check[i] == 0)
            DFS(i, a, n, check);
}
void DFS1(int u, int**a, int n, int* check, stack <int> &head){
    check[u] = 1;
    for(int i=0; i<n; i++)
        if(a[u][i] == 1 && check[i] == 0)
            DFS1(i, a, n, check, head);
    head.push(u);
}
void DFS2(int u, int**a, int n, int* check, vector<int> &LienThong){
    LienThong.push_back(u);
    check[u] = 1;
    for(int i=0; i<n; i++)
        if(a[u][i] == 1 && check[i] == 0)
            DFS2(i, a, n, check, LienThong);
}

void SCC(int** a, int n){
    stack <int> head;
    // B1:
    int* check = new int[n];
    for(int i=0; i<n; i++)
        check[i] = 0;
    for(int i=0; i<n; i++)
        if(check[i] == 0)
            DFS1(i, a, n, check, head);
    // Xuat(head);
    // cout << endl;
    // B2:
    int** g = AT(a, n);
    // B3:
    for(int i=0; i<n; i++)
        check[i] = 0;
    vector<vector <int> > kq;
    while (!head.empty()){
        int u = head.top();
        head.pop();
        if(check[u] == false){
            vector <int> LienThong;
            DFS2(u, g, n, check, LienThong);
            kq.push_back(LienThong);
        }
    }
    if(kq.size() == 1)
        cout << "Do thi lien thong manh";
    else{
        int count = 0;
        for(int i=0; i<kq.size(); i++)
            if(kq[i].size() == 1)
                count++;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                check[j] = 0;
                DFS(i, a, n, check);
            for(int j=0; j<n; j++)
                if(check[j] == 0){
                    cout << "Do thi khong lien thong";
                    goto OUT;
                }
        }
        if(count > kq.size()/2)
            cout << "Do thi lien thong yeu";
        else 
            cout << "Do thi lien thong tung phan";  
    }
    OUT:
    for(int i=0; i<kq.size(); i++){
        cout << "\nThanh phan lien thong manh " << i + 1 << ": ";
        for(int j=0; j<kq[i].size(); j++)
            cout << kq[i][j] << " ";
    }   
}

int main(){
    int n;
    int** a = Nhap(n);
    //Xuat(a, n);
    SCC(a, n);
    return 0;
}