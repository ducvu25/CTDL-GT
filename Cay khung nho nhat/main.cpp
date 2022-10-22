#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int** Input(int &n){
    ifstream cin("./input.txt");
    cin >> n;
    int** a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    return a;
}
void Prim(int**a, int n, int x){
    vector<int> da_xet, chua_xet, canh;
    da_xet.push_back(x);
    for(int i=0; i<n; i++)
        if(i != x)
            chua_xet.push_back(i);
    while(da_xet.size() != n){
        int min = -1;
        int x = -1;
        int y = -1;
        for(int i=0; i<chua_xet.size(); i++)
            for(int j=0; j<da_xet.size(); j++)
            if(a[da_xet[j]][chua_xet[i]] != 0
            && (a[da_xet[j]][chua_xet[i]] < min || min == -1)){
                min = a[da_xet[j]][chua_xet[i]];
                x = j;
                y = i;
            }
        canh.push_back(da_xet[x]);
        canh.push_back(chua_xet[y]);
        da_xet.push_back(chua_xet[y]);
        chua_xet.erase(chua_xet.begin() + y, chua_xet.begin() + y + 1);
    }
    int sum = 0;
    cout << "Tap canh cua cay khung:\n";
    for(int i=0; i<canh.size(); i+=2){
        sum +=  a[canh[i]][canh[i+1]];
        cout << canh[i] << "-" << canh[i+1] << ": " << a[canh[i]][canh[i+1]] << endl;
    }
    cout << "Trong so cua cay khung: " << sum << endl;
}

void make_set(int *parent, int *sz, int n){
	for(int i = 0; i < n; i++){
		parent[i] = i;
		sz[i] = 1;
	}
}
int find(int *parent, int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent, parent[v]);
}
bool Union(int *parent, int *sz, int a, int b){
	a = find(parent, a);
	b = find(parent, b);
	if(a == b) return false; // khong the gop a, b vao voi nhau
	if(sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] + sz[b];
	return true;
}
struct edge{
    int u, v, w;
};
vector<edge> chuyenDoi(int**a, int n){
    vector<edge> kq;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[i][j] > 0){
                edge x;
                x.u = i;
                x.v = j;
                x.w = a[i][j];
                kq.push_back(x);
            }
    return kq;
}
bool so_sanh(edge x, edge y){
    return x.w > y.w;
}
void Kruska(int** a, int n){
    // tao cac canh tang dan
    int *parent = new int[n],
        *size = new int[n];
    make_set(parent, size, n);
    vector<edge> canh = chuyenDoi(a, n);
    vector<edge> T;
    int sum = 0;
    // sap xep
    for(int i=0; i<canh.size(); i++)
        for(int j=i+1; j<canh.size(); j++)
            if(so_sanh(canh[i], canh[j]))
                swap(canh[i], canh[j]);
    for(int t=0; t<canh.size(); t++)
        cout << char(canh[t].u + 'A') <<  char(canh[t].v + 'A') << ": " << canh[t].w << endl;
    // B3
    for(int i=0; i<canh.size(); i++){
        if(T.size() == n - 1)
            break;
        edge x = canh[i];
        if(Union(parent, size, x.u, x.v)){
            T.push_back(x);
            sum += x.w;
        }
    }
    cout << "Tap canh cua cay khung nho nhat:\n";
    for(int i=0; i<T.size(); i++){
        cout << T[i].u << " - " << T[i].v << ": " << T[i].w << endl;
    }
    cout << "Trong so cua cay khung nho nhat: " << sum << endl;
}
void Xuat(int** a, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main(){
    int n;
    int** a = Input(n);
    Xuat(a, n);
    Prim(a, n, 0);
    Kruska(a, n);
    return 0;
}