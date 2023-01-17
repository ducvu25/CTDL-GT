#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int* meger(int *A, int *B, int sizeA, int sizeB){
    int sizeC = sizeA + sizeB;
    int* C = new int[sizeC];
    int nA = 0, nB = 0;

    for(int i=0; i<sizeC; i++){
        if((nA < sizeA && nB < sizeB && A[nA] <= B[nB])
        || nB == sizeB){
            C[i] = A[nA];
            nA++;
        }else{
            C[i] = B[nB];
            nB++;
        }
    }
    return C;
}
void meger_sort(int *A, int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        //cout << mid - left + 1 << " " << right - mid << endl;
        meger_sort(A, left, mid);
        meger_sort(A, mid + 1, right);
        int *Meger = meger(A + left, A + mid + 1, mid - left + 1, right - mid);
        for(int i=0; i<right - left + 1; i++)
            A[left + i] = Meger[i];
    }
}
void Giai_doan_2(string tb1, string tb2, string ta1, string ta2, int m){
    ifstream file_doc_1(tb1.c_str());
    ifstream file_doc_2(tb2.c_str());
    ofstream file_ra_1(ta1.c_str());
    ofstream file_ra_2(ta2.c_str());
    bool file_tb1 = true;
    int Tb1[m], Tb2[m], n_tb1 = 0, n_tb2 = 0;
    bool check = false;
    while(true){
        int x;
        while(true){
            if(!(file_doc_1 >> x))
                break;
            Tb1[n_tb1] = x;
            n_tb1++;
            if(n_tb1 == m)
                break;
        }
        while(true){
            if(!(file_doc_2 >> x))
                break;
            Tb2[n_tb2] = x;
            n_tb2++;
            if(n_tb2 == m)
                break;
        }
        if(n_tb2 == 0){
            system("pause");
            file_doc_1.close();
            file_doc_2.close();
            file_ra_1.close();
            file_ra_2.close();
            if(check == false){ // sap xep xong
                cout << "file duoc sap xep: " << tb1; // tra ve ten file ket qua
                return;
            }else if(n_tb1 == 0){ // doc het file
                Giai_doan_2(ta1, ta2, tb1, tb2, 2*m); // goi de quy lai nhung doi file vao ra
                return;
            }
        }
        check = true;
        int* an_pha = meger(Tb1, Tb2, n_tb1, n_tb2); // tron
        // for(int i=0; i<n_tb1 + n_tb2; i++)
        //         cout << an_pha[i] << " ";
        // cout << endl;
        if(file_tb1){
            for(int i=0; i<n_tb1 + n_tb2; i++)
                file_ra_1 << an_pha[i] << " ";
        }else{
            for(int i=0; i<n_tb1 + n_tb2; i++)
                file_ra_2 << an_pha[i] << " ";
        }
        file_tb1 = !file_tb1;
        n_tb1 = 0;
        n_tb2 = 0;
    }
}
void sort(){
    int m;
    cout << "Nhap M: "; cin >> m;
    string s[] = {"tb1.txt", "tb2.txt", "ta1.txt", "ta2.txt"};

    ifstream file_dau_vao("input.txt");
    ofstream ghi_file_tb1(s[0].c_str());
    ofstream ghi_file_tb2(s[1].c_str());
    int a[m]; // bang tam
    int n = 0; // so luong phan tu cua bang tam
    bool tb1 = true;
    while(true){
        int x;
        if(!(file_dau_vao >> x)) // neu doc het file thi thoat
            break;
        if(n < m){ // kiem tra so luong phan tu da du chua
            a[n] = x;
            n++;
        }else{ // khi du so luon phan tu tien hanh sap xep
            // for(int i=0; i<n; i++)
            //     cout << a[i] << " ";
            // cout << endl;
            meger_sort(a, 0, n - 1);
            if(tb1){ // doc vao file tb1
                for(int i=0; i<n; i++)
                    ghi_file_tb1 << a[i] << " ";
            }else{ // doc vao file tb2
                for(int i=0; i<n; i++)
                    ghi_file_tb2 << a[i] << " ";
            }
            tb1 = !tb1; // doi file ghi
            n = 1; // cap nhat lai so luong phan tu
            a[0] = x;
        }
    }
    meger_sort(a, 0, n - 1);
    if(tb1){
        for(int i=0; i<n; i++)
            ghi_file_tb1 << a[i] << " ";
    }else{
        for(int i=0; i<n; i++)
            ghi_file_tb2 << a[i] << " ";
    }
    ghi_file_tb1.close();
    ghi_file_tb2.close();
    //system("pause");
    Giai_doan_2(s[0], s[1], s[2], s[3], m);
}
int main(){
    sort();
    return 0;
}